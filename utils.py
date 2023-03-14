import numpy as np
from numpy import dot
from numpy.linalg import norm
#import matplotlib.pyplot as plt
from sklearn.metrics import auc, roc_curve
from graphnnSiamese import graphnn
import json
import pandas as pd

def get_f_name(DATA, SF, CM, OP, VS):
    F_NAME = []
    for sf in SF:
        for cm in CM:
            for op in OP:
                for vs in VS:
                    F_NAME.append(DATA+sf+cm+vs+op+".json")
    return F_NAME


def get_f_dict(F_NAME):
    name_num = 0
    name_dict = {}
    for f_name in F_NAME:
        with open(f_name) as inf:
            for line in inf:
                g_info = json.loads(line.strip())
                if (g_info['f_name'] not in name_dict):
                    name_dict[g_info['f_name']] = name_num
                    name_num += 1
    return name_dict

class graph(object):
    def __init__(self, node_num = 0, label = None, name = None):
        self.node_num = node_num
        self.label = label
        self.name = name
        self.features = []
        self.succs = []
        self.preds = []
        if (node_num > 0):
            for i in range(node_num):
                self.features.append([])
                self.succs.append([])
                self.preds.append([])
                
    def add_node(self, feature = []):
        self.node_num += 1
        self.features.append(feature)
        self.succs.append([])
        self.preds.append([])
        
    def add_edge(self, u, v):
        self.succs[u].append(v)
        self.preds[v].append(u)

    def toString(self):
        ret = '{} {}\n'.format(self.node_num, self.label)
        for u in range(self.node_num):
            for fea in self.features[u]:
                ret += '{} '.format(fea)
            ret += str(len(self.succs[u]))
            for succ in self.succs[u]:
                ret += ' {}'.format(succ)
            ret += '\n'
        return ret

        
def read_graph(F_NAME, FUNC_NAME_DICT, FEATURE_DIM):
    graphs = []
    classes = []
    if FUNC_NAME_DICT != None:
        for f in range(len(FUNC_NAME_DICT)):
            classes.append([])

    for f_name in F_NAME:
        with open(f_name) as inf:
            for line in inf:
                g_info = json.loads(line.strip())
                label = FUNC_NAME_DICT[g_info['f_name']]
                classes[label].append(len(graphs))
                cur_graph = graph(g_info['n_num'], label, g_info['src'])
                for u in range(g_info['n_num']):
                    cur_graph.features[u] = np.array(g_info['features'][u])
                    for v in g_info['succs'][u]:
                        cur_graph.add_edge(u, v)
                graphs.append(cur_graph)

    return graphs, classes


def partition_data(Gs, classes, partitions, perm):
    C = len(classes)
    st = 0.0
    ret = []
    for part in partitions:
        cur_g = []
        cur_c = []
        ed = st + part * C
        for cls in range(int(st), int(ed)):
            prev_class = classes[perm[cls]]
            cur_c.append([])
            for i in range(len(prev_class)):
                cur_g.append(Gs[prev_class[i]])
                cur_g[-1].label = len(cur_c)-1
                cur_c[-1].append(len(cur_g)-1)

        ret.append(cur_g)
        ret.append(cur_c)
        st = ed

    return ret


def generate_epoch_pair(Gs, classes, M, output_id = False, load_id = None):
    epoch_data = []
    id_data = []   # [ ([(G0,G1),(G0,G1), ...], [(G0,H0),(G0,H0), ...]), ... ]

    if load_id is None:
        st = 0
        while st < len(Gs):
            if output_id:
                X1, X2, m1, m2, y, pos_id, neg_id = get_pair(Gs, classes,
                        M, st=st, output_id=True)
                id_data.append( (pos_id, neg_id) )
            else:
                X1, X2, m1, m2, y = get_pair(Gs, classes, M, st=st)
            epoch_data.append( (X1,X2,m1,m2,y) )
            st += M
    else:   ## Load from previous id data
        id_data = load_id
        for id_pair in id_data:
            X1, X2, m1, m2, y = get_pair(Gs, classes, M, load_id=id_pair)
            epoch_data.append( (X1, X2, m1, m2, y) )

    if output_id:
        return epoch_data, id_data
    else:
        return epoch_data


def get_pair(Gs, classes, M, st = -1, output_id = False, load_id = None):
    if load_id is None:
        C = len(classes)

        if (st + M > len(Gs)):
            M = len(Gs) - st
        ed = st + M

        pos_ids = [] # [(G_0, G_1)]
        neg_ids = [] # [(G_0, H_0)]

        for g_id in range(st, ed):
            g0 = Gs[g_id]
            cls = g0.label
            tot_g = len(classes[cls])
            if (len(classes[cls]) >= 2):
                g1_id = classes[cls][np.random.randint(tot_g)]
                while g_id == g1_id:
                    g1_id = classes[cls][np.random.randint(tot_g)]
                pos_ids.append( (g_id, g1_id) )

            cls2 = np.random.randint(C)
            while (len(classes[cls2]) == 0) or (cls2 == cls):
                cls2 = np.random.randint(C)

            tot_g2 = len(classes[cls2])
            h_id = classes[cls2][np.random.randint(tot_g2)]
            neg_ids.append( (g_id, h_id) )
    else:
        pos_ids = load_id[0]
        neg_ids = load_id[1]
        
    M_pos = len(pos_ids)
    M_neg = len(neg_ids)
    M = M_pos + M_neg

    maxN1 = 0
    maxN2 = 0
    for pair in pos_ids:
        maxN1 = max(maxN1, Gs[pair[0]].node_num)
        maxN2 = max(maxN2, Gs[pair[1]].node_num)
    for pair in neg_ids:
        maxN1 = max(maxN1, Gs[pair[0]].node_num)
        maxN2 = max(maxN2, Gs[pair[1]].node_num)

    feature_dim = len(Gs[0].features[0])
    X1_input = np.zeros((M, maxN1, feature_dim))
    X2_input = np.zeros((M, maxN2, feature_dim))
    node1_mask = np.zeros((M, maxN1, maxN1))
    node2_mask = np.zeros((M, maxN2, maxN2))
    y_input = np.zeros((M))
    
    for i in range(M_pos):
        y_input[i] = 1
        g1 = Gs[pos_ids[i][0]]
        g2 = Gs[pos_ids[i][1]]
        for u in range(g1.node_num):
            X1_input[i, u, :] = np.array( g1.features[u] )
            for v in g1.succs[u]:
                node1_mask[i, u, v] = 1
        for u in range(g2.node_num):
            X2_input[i, u, :] = np.array( g2.features[u] )
            for v in g2.succs[u]:
                node2_mask[i, u, v] = 1
        
    for i in range(M_pos, M_pos + M_neg):
        y_input[i] = -1
        g1 = Gs[neg_ids[i-M_pos][0]]
        g2 = Gs[neg_ids[i-M_pos][1]]
        for u in range(g1.node_num):
            X1_input[i, u, :] = np.array( g1.features[u] )
            for v in g1.succs[u]:
                node1_mask[i, u, v] = 1
        for u in range(g2.node_num):
            X2_input[i, u, :] = np.array( g2.features[u] )
            for v in g2.succs[u]:
                node2_mask[i, u, v] = 1
    if output_id:
        return X1_input,X2_input,node1_mask,node2_mask,y_input,pos_ids,neg_ids
    else:
        return X1_input,X2_input,node1_mask,node2_mask,y_input


def train_epoch(model, graphs, classes, batch_size, load_data=None):
    if load_data is None:
        epoch_data = generate_epoch_pair(graphs, classes, batch_size)
    else:
        epoch_data = load_data

    perm = np.random.permutation(len(epoch_data))   #Random shuffle

    cum_loss = 0.0
    for index in perm:
        cur_data = epoch_data[index]
        X1, X2, mask1, mask2, y = cur_data
        loss = model.train(X1, X2, mask1, mask2, y)
        cum_loss += loss

    return cum_loss / len(perm)


def get_auc_epoch(model, graphs, classes, batch_size, load_data=None):
    tot_diff = []
    tot_truth = []

    if load_data is None:
        epoch_data= generate_epoch_pair(graphs, classes, batch_size)
    else:
        epoch_data = load_data


    for cur_data in epoch_data:
        X1, X2, m1, m2,y  = cur_data
        diff = model.calc_diff(X1, X2, m1, m2)
#         print(diff)

        tot_diff += list(diff)
        tot_truth += list(y > 0)


    diff = np.array(tot_diff)
    truth = np.array(tot_truth)

    fpr, tpr, thres = roc_curve(truth, (1-diff)/2)
    model_auc = auc(fpr, tpr)

    return model_auc, fpr, tpr, thres

def get_retrieval(model, graphs, classes, N_x):
    
    # First, get the embeddings for all graphs in test set 
    embeddings = []
    for graph in graphs:
        X = np.zeros((1, graph.node_num, N_x))
        mask = np.zeros((1, graph.node_num, graph.node_num))
        for u in range(graph.node_num):
            X[0, u, :] = np.array( graph.features[u] )
            for v in graph.succs[u]:
                mask[0, u, v] = 1
        emb = model.get_embed(X, mask)
#         print(emb)
        embeddings.append(emb)
    
    # For each graph embedding, get the reciprocal rank (RR) 
    # First get an ordered list of other graphs acc to cos similarity
    # Then using the relevancy grade, find the top match from the ordered list
    # Calculate the mean reciprocal rate (MRR)
    mrr_list = [] # hold all reciprocal ranks in list then find the mean reciprocal rank
    prec_1_list = []
    prec_5_list = []
    prec_10_list = []
    rec_1_list = []
    rec_5_list = []
    rec_10_list = []
    k_values = [5, 10] # define k for top k precision and recall 
    for query_g_id in range(len(graphs)): # iterate through every query 
        all_data = [] # list to hold dictionaries g_dict of every graph 
        # go thru every other graph and collect info eg relevancy grade, cos sim
        for g_id in range(len(graphs)):
            if g_id == query_g_id:
                continue
            g_dict = {}
            g_dict['query'] = query_g_id
            g_dict['graph'] = g_id
            g_dict['query_fxn'] = graphs[query_g_id].label
            g_dict['graph_fxn'] = graphs[g_id].label
            if graphs[query_g_id].label == graphs[g_id].label:
                g_dict['relevancy_grade'] = 1 # come from the same function
            else:
                g_dict['relevancy_grade'] = 0
            embed1 = embeddings[query_g_id]
#             print(embed1)
            embed2 = embeddings[g_id]
#             print(embed2)
            cos = dot(embed1[0], embed2[0])/(norm(embed1)*norm(embed2))
#             print(cos)
            g_dict['cos_sim'] = cos
            all_data.append(g_dict)
        # order all entries acc to highest cos sim first 
        df = pd.DataFrame(all_data)
        df = df.sort_values(by='cos_sim', axis=0, ascending=False)
        df.reset_index(drop=True, inplace=True)
        df.to_csv('data/14032023_queries/query'+str(query_g_id)+'.csv')
        # then calculate rank acc to relevancy grade = 1 of highest cos sim
        same_fxn = df.loc[df['relevancy_grade']==1]
        rank = same_fxn.iloc[0].name + 1 # index starts with 0, rank starts with 1
        rr = 1/rank # calc reciprocal rank
        mrr_list.append(rr)
        print("Query ", query_g_id)
        print(mrr_list)
        # find for each k the top k precision and recall
        # precision@k = # relevant items in top k / k
        # recall@k = # relevant items in top k / # of all possible relevant items
        top5_relevant = (df.head(5)["relevancy_grade"]==1).sum()
        top10_relevant = (df.head(10)["relevancy_grade"]==1).sum()
        top1_relevant = (df.head(1)["relevancy_grade"]==1).sum()
        tot_relevant = (df["relevancy_grade"]==1).sum()
        
        prec1 = top1_relevant/1
        rec1 = top1_relevant/tot_relevant
        prec5 = top5_relevant/5
        rec5 = top5_relevant/tot_relevant
        prec10 = top10_relevant/10
        rec10 = top10_relevant/tot_relevant
        
        prec_1_list.append(prec1)
        prec_5_list.append(prec5)
        prec_10_list.append(prec10)
        rec_1_list.append(rec1)
        rec_5_list.append(rec5)
        rec_10_list.append(rec10)
            
    mrr = sum(mrr_list)/len(mrr_list)
    precision_top1 = sum(prec_1_list)/len(prec_1_list)
    precision_top5 = sum(prec_5_list)/len(prec_5_list)
    precision_top10 = sum(prec_10_list)/len(prec_10_list)
    recall_top1 = sum(rec_1_list)/len(rec_1_list)
    recall_top5 = sum(rec_5_list)/len(rec_5_list)
    recall_top10 = sum(rec_10_list)/len(rec_10_list)
    
    return mrr, precision_top1, recall_top1, precision_top5, recall_top5, precision_top10, recall_top10
    