
void * lh_insert(_LHASH *lh,void *data)

{
  LHASH_COMP_FN_TYPE pLVar1;
  LHASH_NODE *pLVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ulong uVar7;
  int iVar8;
  LHASH_NODE **ppLVar9;
  lhash_node_st *plVar10;
  lhash_node_st **pplVar11;
  
  lh->error = 0;
  uVar6 = (lh->num_items << 8) / lh->num_nodes;
  if (lh->up_load < uVar6 || lh->up_load == uVar6) {
    uVar6 = lh->p;
    uVar4 = lh->pmax;
    lh->num_nodes = lh->num_nodes + 1;
    lh->num_expands = lh->num_expands + 1;
    lh->p = uVar6 + 1;
    pplVar11 = lh->b + uVar6;
    ppLVar9 = lh->b + uVar4 + uVar6;
    uVar5 = lh->num_alloc_nodes;
    *ppLVar9 = (LHASH_NODE *)0x0;
    plVar10 = *pplVar11;
    while (plVar10 != (LHASH_NODE *)0x0) {
      while (uVar6 == plVar10->hash % uVar5) {
        pplVar11 = &plVar10->next;
        plVar10 = *pplVar11;
        if (plVar10 == (lhash_node_st *)0x0) goto LAB_0811fdec;
      }
      *pplVar11 = plVar10->next;
      plVar10->next = *ppLVar9;
      *ppLVar9 = plVar10;
      plVar10 = *pplVar11;
    }
LAB_0811fdec:
    if (uVar4 <= uVar6 + 1) {
      uVar6 = uVar5 * 2;
      ppLVar9 = (LHASH_NODE **)CRYPTO_realloc(lh->b,uVar5 << 3,"lhash.c",0x150);
      if (ppLVar9 == (LHASH_NODE **)0x0) {
        lh->error = lh->error + 1;
        lh->p = 0;
      }
      else {
        uVar4 = lh->num_alloc_nodes;
        if (uVar4 < uVar6) {
          memset(ppLVar9 + uVar4,0,(uVar6 - uVar4) * 4);
        }
        lh->pmax = uVar4;
        lh->num_alloc_nodes = uVar6;
        lh->num_expand_reallocs = lh->num_expand_reallocs + 1;
        lh->p = 0;
        lh->b = ppLVar9;
      }
    }
  }
  uVar7 = (*lh->hash)(data);
  lh->num_hash_calls = lh->num_hash_calls + 1;
  uVar6 = uVar7 % lh->pmax;
  if (uVar6 < lh->p) {
    uVar6 = uVar7 % lh->num_alloc_nodes;
  }
  pLVar1 = lh->comp;
  pplVar11 = lh->b + uVar6;
  pLVar2 = *pplVar11;
  do {
    if (pLVar2 == (LHASH_NODE *)0x0) {
LAB_0811fe60:
      plVar10 = (lhash_node_st *)CRYPTO_malloc(0xc,"lhash.c",0xbf);
      if (plVar10 == (lhash_node_st *)0x0) {
        lh->error = lh->error + 1;
      }
      else {
        plVar10->next = (lhash_node_st *)0x0;
        plVar10->hash = uVar7;
        plVar10->data = data;
        *pplVar11 = plVar10;
        plVar10 = (lhash_node_st *)0x0;
        lh->num_insert = lh->num_insert + 1;
        lh->num_items = lh->num_items + 1;
      }
      return plVar10;
    }
    lh->num_hash_comps = lh->num_hash_comps + 1;
    if (uVar7 == pLVar2->hash) {
      lh->num_comp_calls = lh->num_comp_calls + 1;
      iVar8 = (*pLVar1)(pLVar2->data,data);
      if (iVar8 == 0) {
        plVar10 = *pplVar11;
        if (plVar10 != (lhash_node_st *)0x0) {
          pvVar3 = plVar10->data;
          plVar10->data = data;
          lh->num_replace = lh->num_replace + 1;
          return pvVar3;
        }
        goto LAB_0811fe60;
      }
    }
    pplVar11 = &pLVar2->next;
    pLVar2 = pLVar2->next;
  } while( true );
}

