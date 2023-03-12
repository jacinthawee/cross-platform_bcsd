
void * lh_retrieve(_LHASH *lh,void *data)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  void *pvVar4;
  LHASH_NODE *pLVar5;
  lhash_node_st **pplVar6;
  LHASH_COMP_FN_TYPE pLVar7;
  uint uVar8;
  
  lh->error = 0;
  uVar1 = (*lh->hash)(data);
  if (lh->pmax == 0) {
    trap(7);
  }
  uVar8 = uVar1 % lh->pmax;
  lh->num_hash_calls = lh->num_hash_calls + 1;
  if (uVar8 < lh->p) {
    if (lh->num_alloc_nodes == 0) {
      trap(7);
    }
    uVar8 = uVar1 % lh->num_alloc_nodes;
  }
  pplVar6 = lh->b + uVar8;
  pLVar5 = *pplVar6;
  pLVar7 = lh->comp;
  if (pLVar5 == (LHASH_NODE *)0x0) {
    uVar1 = lh->num_retrieve_miss;
  }
  else {
    do {
      uVar3 = pLVar5->hash;
      lh->num_hash_comps = lh->num_hash_comps + 1;
      if (uVar1 == uVar3) {
        pvVar4 = pLVar5->data;
        lh->num_comp_calls = lh->num_comp_calls + 1;
        iVar2 = (*pLVar7)(pvVar4,data);
        if (iVar2 == 0) {
          if (*pplVar6 != (LHASH_NODE *)0x0) {
            pvVar4 = (*pplVar6)->data;
            lh->num_retrieve = lh->num_retrieve + 1;
            return pvVar4;
          }
          break;
        }
      }
      pplVar6 = &pLVar5->next;
      pLVar5 = pLVar5->next;
    } while (pLVar5 != (lhash_node_st *)0x0);
    uVar1 = lh->num_retrieve_miss;
  }
  lh->num_retrieve_miss = uVar1 + 1;
  return (void *)0x0;
}

