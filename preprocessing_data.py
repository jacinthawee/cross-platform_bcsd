import os
import json 
import numpy as np
import re
import random

def get_f_name(DATA, SF, CM, OP, VS):
    F_NAME = []
    for sf in SF:
        for cm in CM:
            for op in OP:
                for vs in VS:
                    F_NAME.append(DATA+sf+"_"+cm+"_"+vs+"_"+op+".json")
    return F_NAME


def get_f_dict(F_NAME):
    name_num = 0
    name_dict = {}
    dict_name = {}
    for f_name in F_NAME:
        with open(f_name) as inf:
            for line in inf:
                g_info = json.loads(line.strip())
                if (g_info['f_name'] not in name_dict):
                    name_dict[g_info['f_name']] = name_num
                    dict_name[name_num] = g_info['f_name']
                    name_num += 1
    return name_dict, dict_name

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
        ed = st + part * C # 4695, 5282
        print("end: ", ed)
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

if __name__ == '__main__':
    DATA_FILE_NAME = './data/acfgSSL_8/'
    SOFTWARE = ('openssl-101f', 'openssl-101u')
    OPTIMIZATION = ('O0', 'O1', 'O2', 'O3')
    COMPILER = ('arm', 'x86', 'mips')
    VERSION = ('gcc',)
    NODE_FEATURE_DIM = 8

    FUNC_NAME_DICT = {}

    F_NAME = get_f_name(DATA_FILE_NAME, SOFTWARE, COMPILER, OPTIMIZATION, VERSION)
    FUNC_NAME_DICT, REVERSE_FUNC_NAME_DICT = get_f_dict(F_NAME)
    # print(REVERSE_FUNC_NAME_DICT)

    Gs, classes = read_graph(F_NAME, FUNC_NAME_DICT, NODE_FEATURE_DIM)
    print("{} graphs, {} functions".format(len(Gs), len(classes)))
    # print(classes)

    if os.path.isfile('data/class_perm.npy'):
        perm = np.load('data/class_perm.npy')
    else:
        perm = np.random.permutation(len(classes))
        np.save('data/class_perm.npy', perm)
    if len(perm) < len(classes):
        perm = np.random.permutation(len(classes))
        np.save('data/class_perm.npy', perm)

    Gs_train, classes_train, Gs_dev, classes_dev, Gs_test, classes_test =\
            partition_data(Gs,classes,[0.8,0.1,0.1],perm)

    print("Train: {} graphs, {} functions".format(
            len(Gs_train), len(classes_train)))
    print("Dev: {} graphs, {} functions".format(
            len(Gs_dev), len(classes_dev)))
    print("Test: {} graphs, {} functions".format(
            len(Gs_test), len(classes_test)))
    # print(classes_test)

    test_fxns = []
    for id in range(5282, 5869):
        test_fxns.append(REVERSE_FUNC_NAME_DICT[id])
    # print(len(test_fxns))
    # print(test_fxns)
    with open("test_functions.txt", "w") as output:
        output.write(str(test_fxns))
    
    all_data = []
    actual_test_fxns = [] # out of the original test functions, which ones can be found inside the decomp functions
    path_to_decomp = "./data/decomp/"
    for sw in SOFTWARE:
        for cm in COMPILER:
            for v in VERSION:
                for op in OPTIMIZATION:
                    path_to_folder = path_to_decomp+sw+"_"+cm+"_"+v+"_"+op+"_extraction/"
                    file_list = os.listdir(path_to_folder)  
                    for f in file_list:
                        file_dict = {}
                        file_dict["sw"] = sw
                        file_dict["op"] = op
                        file_dict["arch"] = cm
                        func = re.findall("^.*?(?=@)", f)[0]
                        file_dict["func"] = func
                        file_dict["file_name"] = path_to_folder+f
                        all_data.append(file_dict)
                        with open("decomp_all_fxn.json", "a") as fout:
                            json.dump(file_dict, fout)
                            fout.write("\n")
                        if func in test_fxns:
                            with open("decomp_test.json", "a") as outfile:
                                json.dump(file_dict, outfile)
                                outfile.write("\n")
                            if func not in actual_test_fxns:
                                actual_test_fxns.append(func)
    missing_func = [i for i in test_fxns if i not in actual_test_fxns]
    print("Total no. of functions in original test (gemini): ", len(test_fxns))
    print("Total no. of functions in actual test (lm): ", len(actual_test_fxns))
    print("Missing functions: ", missing_func)
    partial_fxn_100 = random.sample(actual_test_fxns, 100)
    with open("partial_test_fn_100.txt", "w") as output:
        output.write(str(partial_fxn_100))
    

    # print(all_data)
    # with open('data/valid.json') as inf:
    #     valid_ids = json.load(inf)
    # with open('data/test.json') as inf:
    #     test_ids = json.load(inf)