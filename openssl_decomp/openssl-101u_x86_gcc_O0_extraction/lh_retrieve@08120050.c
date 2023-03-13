
void * lh_retrieve(_LHASH *lh,void *data)

{
  LHASH_COMP_FN_TYPE pLVar1;
  LHASH_NODE *pLVar2;
  void *pvVar3;
  lhash_node_st **pplVar4;
  ulong uVar5;
  int iVar6;
  uint uVar7;
  
  lh->error = 0;
  uVar5 = (*lh->hash)(data);
  lh->num_hash_calls = lh->num_hash_calls + 1;
  uVar7 = uVar5 % lh->pmax;
  if (uVar7 < lh->p) {
    uVar7 = uVar5 % lh->num_alloc_nodes;
  }
  pLVar1 = lh->comp;
  pplVar4 = lh->b + uVar7;
  pLVar2 = *pplVar4;
  do {
    if (pLVar2 == (LHASH_NODE *)0x0) {
LAB_081200e8:
      lh->num_retrieve_miss = lh->num_retrieve_miss + 1;
      return (void *)0x0;
    }
    lh->num_hash_comps = lh->num_hash_comps + 1;
    if (uVar5 == pLVar2->hash) {
      lh->num_comp_calls = lh->num_comp_calls + 1;
      iVar6 = (*pLVar1)(pLVar2->data,data);
      if (iVar6 == 0) {
        if (*pplVar4 != (lhash_node_st *)0x0) {
          pvVar3 = (*pplVar4)->data;
          lh->num_retrieve = lh->num_retrieve + 1;
          return pvVar3;
        }
        goto LAB_081200e8;
      }
    }
    pplVar4 = &pLVar2->next;
    pLVar2 = pLVar2->next;
  } while( true );
}

