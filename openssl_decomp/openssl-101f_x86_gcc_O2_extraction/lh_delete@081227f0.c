
void * lh_delete(_LHASH *lh,void *data)

{
  LHASH_COMP_FN_TYPE pLVar1;
  LHASH_NODE *pLVar2;
  lhash_node_st *ptr;
  void *pvVar3;
  uint uVar4;
  LHASH_NODE *pLVar5;
  lhash_node_st **pplVar6;
  ulong uVar7;
  int iVar8;
  LHASH_NODE **ppLVar9;
  uint uVar10;
  LHASH_NODE *pLVar11;
  uint uVar12;
  
  lh->error = 0;
  uVar7 = (*lh->hash)(data);
  lh->num_hash_calls = lh->num_hash_calls + 1;
  uVar10 = uVar7 % lh->pmax;
  if (uVar10 < lh->p) {
    uVar10 = uVar7 % lh->num_alloc_nodes;
  }
  pLVar1 = lh->comp;
  pplVar6 = lh->b + uVar10;
  pLVar2 = *pplVar6;
  do {
    if (pLVar2 == (LHASH_NODE *)0x0) {
LAB_08122958:
      lh->num_no_delete = lh->num_no_delete + 1;
      return (void *)0x0;
    }
    lh->num_hash_comps = lh->num_hash_comps + 1;
    if (uVar7 == pLVar2->hash) {
      lh->num_comp_calls = lh->num_comp_calls + 1;
      iVar8 = (*pLVar1)(pLVar2->data,data);
      if (iVar8 == 0) {
        ptr = *pplVar6;
        if (ptr != (lhash_node_st *)0x0) {
          *pplVar6 = ptr->next;
          pvVar3 = ptr->data;
          CRYPTO_free(ptr);
          uVar10 = lh->num_nodes;
          lh->num_delete = lh->num_delete + 1;
          uVar7 = lh->num_items - 1;
          lh->num_items = uVar7;
          if (uVar10 < 0x11) {
            return pvVar3;
          }
          if (lh->down_load < (uVar7 * 0x100) / uVar10) {
            return pvVar3;
          }
          uVar4 = lh->pmax;
          uVar12 = lh->p;
          pLVar2 = lh->b[uVar12 + 0x3fffffff + uVar4];
          lh->b[uVar12 + 0x3fffffff + uVar4] = (LHASH_NODE *)0x0;
          if (uVar12 == 0) {
            ppLVar9 = (LHASH_NODE **)CRYPTO_realloc(lh->b,uVar4 << 2,"lhash.c",0x177);
            if (ppLVar9 == (LHASH_NODE **)0x0) {
              lh->error = lh->error + 1;
              return pvVar3;
            }
            lh->num_contract_reallocs = lh->num_contract_reallocs + 1;
            lh->num_alloc_nodes = lh->num_alloc_nodes >> 1;
            lh->b = ppLVar9;
            uVar10 = lh->num_nodes;
            uVar12 = lh->pmax >> 1;
            lh->pmax = uVar12;
            uVar12 = uVar12 - 1;
            lh->p = uVar12;
          }
          else {
            uVar12 = uVar12 - 1;
            ppLVar9 = lh->b;
            lh->p = uVar12;
          }
          lh->num_contracts = lh->num_contracts + 1;
          lh->num_nodes = uVar10 - 1;
          pLVar5 = ppLVar9[uVar12];
          if (pLVar5 == (LHASH_NODE *)0x0) {
            ppLVar9[uVar12] = pLVar2;
            return pvVar3;
          }
          do {
            pLVar11 = pLVar5;
            pLVar5 = pLVar11->next;
          } while (pLVar5 != (lhash_node_st *)0x0);
          pLVar11->next = pLVar2;
          return pvVar3;
        }
        goto LAB_08122958;
      }
    }
    pplVar6 = &pLVar2->next;
    pLVar2 = pLVar2->next;
  } while( true );
}

