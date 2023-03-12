
void * lh_insert(_LHASH *lh,void *data)

{
  ulong uVar1;
  int iVar2;
  LHASH_NODE **ppLVar3;
  lhash_node_st *plVar4;
  uint uVar5;
  void *pvVar6;
  lhash_node_st **pplVar7;
  ulong uVar8;
  LHASH_NODE **ppLVar9;
  ulong uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  LHASH_NODE *pLVar14;
  LHASH_COMP_FN_TYPE pLVar15;
  
  lh->error = 0;
  uVar5 = lh->num_nodes;
  if (uVar5 == 0) {
    trap(7);
  }
  if (lh->up_load <= (lh->num_items << 8) / uVar5) {
    uVar11 = lh->p;
    uVar13 = lh->pmax;
    ppLVar3 = lh->b;
    uVar12 = lh->num_alloc_nodes;
    lh->num_nodes = uVar5 + 1;
    ppLVar9 = ppLVar3 + uVar11 + uVar13;
    lh->num_expands = lh->num_expands + 1;
    lh->p = uVar11 + 1;
    *ppLVar9 = (LHASH_NODE *)0x0;
    pplVar7 = ppLVar3 + uVar11;
    while (pLVar14 = *pplVar7, pLVar14 != (lhash_node_st *)0x0) {
      while( true ) {
        if (uVar12 == 0) {
          trap(7);
        }
        if (uVar11 == pLVar14->hash % uVar12) break;
        *pplVar7 = pLVar14->next;
        pLVar14->next = *ppLVar9;
        *ppLVar9 = pLVar14;
        pLVar14 = *pplVar7;
        if (pLVar14 == (lhash_node_st *)0x0) goto LAB_0052b9d4;
      }
      pplVar7 = &pLVar14->next;
    }
LAB_0052b9d4:
    if (uVar13 <= uVar11 + 1) {
      uVar5 = uVar12 * 2;
      ppLVar3 = (LHASH_NODE **)
                (*(code *)PTR_CRYPTO_realloc_006a7b58)(lh->b,uVar12 << 3,"lhash.c",0x150);
      if (ppLVar3 == (LHASH_NODE **)0x0) {
        lh->p = 0;
        lh->error = lh->error + 1;
      }
      else {
        uVar11 = lh->num_alloc_nodes;
        if (uVar11 < uVar5) {
          (*(code *)PTR_memset_006a99f4)(ppLVar3 + uVar11,0,(uVar5 - uVar11) * 4);
        }
        lh->pmax = uVar11;
        lh->num_alloc_nodes = uVar5;
        lh->p = 0;
        lh->b = ppLVar3;
        lh->num_expand_reallocs = lh->num_expand_reallocs + 1;
      }
    }
  }
  uVar1 = (*lh->hash)(data);
  if (lh->pmax == 0) {
    trap(7);
  }
  uVar5 = uVar1 % lh->pmax;
  lh->num_hash_calls = lh->num_hash_calls + 1;
  if (uVar5 < lh->p) {
    if (lh->num_alloc_nodes == 0) {
      trap(7);
    }
    uVar5 = uVar1 % lh->num_alloc_nodes;
  }
  pplVar7 = lh->b + uVar5;
  pLVar14 = *pplVar7;
  pLVar15 = lh->comp;
  do {
    if (pLVar14 == (LHASH_NODE *)0x0) {
LAB_0052ba58:
      plVar4 = (lhash_node_st *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0xc,"lhash.c",0xbf);
      if (plVar4 == (lhash_node_st *)0x0) {
        lh->error = lh->error + 1;
      }
      else {
        uVar10 = lh->num_insert;
        uVar8 = lh->num_items;
        plVar4->data = data;
        plVar4->next = (lhash_node_st *)0x0;
        plVar4->hash = uVar1;
        *pplVar7 = plVar4;
        lh->num_insert = uVar10 + 1;
        lh->num_items = uVar8 + 1;
      }
      return (void *)0x0;
    }
    uVar8 = pLVar14->hash;
    lh->num_hash_comps = lh->num_hash_comps + 1;
    if (uVar1 == uVar8) {
      pvVar6 = pLVar14->data;
      lh->num_comp_calls = lh->num_comp_calls + 1;
      iVar2 = (*pLVar15)(pvVar6,data);
      if (iVar2 == 0) {
        plVar4 = *pplVar7;
        if (plVar4 != (lhash_node_st *)0x0) {
          uVar1 = lh->num_replace;
          pvVar6 = plVar4->data;
          plVar4->data = data;
          lh->num_replace = uVar1 + 1;
          return pvVar6;
        }
        goto LAB_0052ba58;
      }
    }
    pplVar7 = &pLVar14->next;
    pLVar14 = pLVar14->next;
  } while( true );
}

