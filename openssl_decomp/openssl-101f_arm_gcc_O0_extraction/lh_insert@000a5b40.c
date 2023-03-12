
void * lh_insert(_LHASH *lh,void *data)

{
  void **ppvVar1;
  uint uVar2;
  ulong uVar3;
  void *pvVar4;
  int iVar5;
  LHASH_NODE **ppLVar6;
  uint extraout_r1;
  uint extraout_r1_00;
  uint extraout_r1_01;
  ulong uVar7;
  LHASH_NODE *pLVar8;
  LHASH_NODE *pLVar9;
  ulong uVar10;
  uint uVar11;
  LHASH_COMP_FN_TYPE pLVar12;
  lhash_node_st **pplVar13;
  uint uVar14;
  
  uVar11 = lh->num_nodes;
  lh->error = 0;
  uVar2 = __udivsi3(lh->num_items << 8,uVar11);
  if (lh->up_load <= uVar2) {
    uVar2 = lh->p;
    uVar14 = lh->pmax;
    pLVar8 = (LHASH_NODE *)lh->b;
    iVar5 = uVar14 + uVar2;
    ppvVar1 = &pLVar8->data;
    lh->num_nodes = uVar11 + 1;
    pplVar13 = (lhash_node_st **)(&pLVar8->data + uVar2);
    lh->p = uVar2 + 1;
    lh->num_expands = lh->num_expands + 1;
    (&pLVar8->data)[iVar5] = (void *)0x0;
    uVar11 = lh->num_alloc_nodes;
    pLVar9 = (LHASH_NODE *)(&pLVar8->data)[uVar2];
    while (pLVar9 != (LHASH_NODE *)0x0) {
      __aeabi_uidivmod(pLVar9->hash,uVar11);
      if (uVar2 == extraout_r1_01) {
        pplVar13 = &pLVar9->next;
      }
      else {
        *pplVar13 = pLVar9->next;
        pLVar8 = (LHASH_NODE *)ppvVar1[iVar5];
      }
      if (uVar2 != extraout_r1_01) {
        pLVar9->next = pLVar8;
        ppvVar1[iVar5] = pLVar9;
      }
      pLVar9 = *pplVar13;
    }
    if (uVar14 <= uVar2 + 1) {
      uVar2 = uVar11 * 2;
      ppLVar6 = (LHASH_NODE **)CRYPTO_realloc(lh->b,uVar11 << 3,"lhash.c",0x15b);
      if (ppLVar6 == (LHASH_NODE **)0x0) {
        lh->p = 0;
        lh->error = lh->error + 1;
      }
      else {
        uVar11 = lh->num_alloc_nodes;
        if (uVar11 < uVar2) {
          memset(ppLVar6 + uVar11,0,(uVar2 - uVar11) * 4);
        }
        lh->pmax = uVar11;
        lh->num_alloc_nodes = uVar2;
        lh->b = ppLVar6;
        lh->num_expand_reallocs = lh->num_expand_reallocs + 1;
        lh->p = 0;
      }
    }
  }
  uVar3 = (*lh->hash)(data);
  lh->num_hash_calls = lh->num_hash_calls + 1;
  __aeabi_uidivmod(uVar3,lh->pmax);
  uVar2 = extraout_r1;
  if (extraout_r1 < lh->p) {
    __aeabi_uidivmod(uVar3,lh->num_alloc_nodes);
    uVar2 = extraout_r1_00;
  }
  pLVar12 = lh->comp;
  pplVar13 = lh->b + uVar2;
  pLVar8 = lh->b[uVar2];
  do {
    if (pLVar8 == (LHASH_NODE *)0x0) {
LAB_000a5c7c:
      pLVar8 = (LHASH_NODE *)CRYPTO_malloc(0xc,"lhash.c",0xc1);
      if (pLVar8 == (LHASH_NODE *)0x0) {
        lh->error = lh->error + 1;
      }
      else {
        uVar10 = lh->num_insert;
        uVar7 = lh->num_items;
        pLVar8->data = data;
        pLVar8->hash = uVar3;
        pLVar8->next = (lhash_node_st *)0x0;
        *pplVar13 = pLVar8;
        lh->num_insert = uVar10 + 1;
        lh->num_items = uVar7 + 1;
        pLVar8 = (LHASH_NODE *)0x0;
      }
      return pLVar8;
    }
    uVar7 = pLVar8->hash;
    lh->num_hash_comps = lh->num_hash_comps + 1;
    if (uVar3 == uVar7) {
      pvVar4 = pLVar8->data;
      lh->num_comp_calls = lh->num_comp_calls + 1;
      iVar5 = (*pLVar12)(pvVar4,data);
      if (iVar5 == 0) {
        pLVar8 = *pplVar13;
        if (pLVar8 != (LHASH_NODE *)0x0) {
          uVar3 = lh->num_replace;
          pvVar4 = pLVar8->data;
          pLVar8->data = data;
          lh->num_replace = uVar3 + 1;
          return pvVar4;
        }
        goto LAB_000a5c7c;
      }
    }
    pplVar13 = &pLVar8->next;
    pLVar8 = pLVar8->next;
  } while( true );
}

