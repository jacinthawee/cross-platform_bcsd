
void * lh_delete(_LHASH *lh,void *data)

{
  undefined *puVar1;
  ulong uVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  LHASH_NODE **ppLVar6;
  void *pvVar7;
  LHASH_NODE *pLVar8;
  LHASH_NODE *pLVar9;
  uint uVar10;
  LHASH_NODE *pLVar11;
  lhash_node_st **pplVar12;
  LHASH_COMP_FN_TYPE pLVar13;
  uint uVar14;
  
  lh->error = 0;
  uVar2 = (*lh->hash)(data);
  if (lh->pmax == 0) {
    trap(7);
  }
  uVar14 = uVar2 % lh->pmax;
  lh->num_hash_calls = lh->num_hash_calls + 1;
  if (uVar14 < lh->p) {
    if (lh->num_alloc_nodes == 0) {
      trap(7);
    }
    uVar14 = uVar2 % lh->num_alloc_nodes;
  }
  pplVar12 = lh->b + uVar14;
  pLVar11 = *pplVar12;
  pLVar13 = lh->comp;
  if (pLVar11 == (LHASH_NODE *)0x0) {
    uVar2 = lh->num_no_delete;
  }
  else {
    do {
      uVar5 = pLVar11->hash;
      lh->num_hash_comps = lh->num_hash_comps + 1;
      if (uVar2 == uVar5) {
        pvVar7 = pLVar11->data;
        lh->num_comp_calls = lh->num_comp_calls + 1;
        iVar3 = (*pLVar13)(pvVar7,data);
        puVar1 = PTR_CRYPTO_free_006a6e88;
        if (iVar3 == 0) {
          pLVar11 = *pplVar12;
          if (pLVar11 != (LHASH_NODE *)0x0) {
            *pplVar12 = pLVar11->next;
            pvVar7 = pLVar11->data;
            (*(code *)puVar1)(pLVar11);
            uVar14 = lh->num_nodes;
            uVar2 = lh->num_items - 1;
            lh->num_delete = lh->num_delete + 1;
            lh->num_items = uVar2;
            if (uVar14 < 0x11) {
              return pvVar7;
            }
            if (uVar14 == 0) {
              trap(7);
            }
            if (lh->down_load < (uVar2 * 0x100) / uVar14) {
              return pvVar7;
            }
            uVar4 = lh->p;
            uVar10 = lh->pmax;
            pLVar11 = lh->b[uVar4 + uVar10 + -1];
            lh->b[uVar4 + uVar10 + -1] = (LHASH_NODE *)0x0;
            if (uVar4 == 0) {
              ppLVar6 = (LHASH_NODE **)
                        (*(code *)PTR_CRYPTO_realloc_006a7b58)(lh->b,uVar10 << 2,"lhash.c",0x16b);
              if (ppLVar6 == (LHASH_NODE **)0x0) {
                lh->error = lh->error + 1;
                return pvVar7;
              }
              uVar10 = lh->pmax >> 1;
              uVar14 = lh->num_nodes;
              lh->b = ppLVar6;
              uVar4 = uVar10 - 1;
              lh->pmax = uVar10;
              lh->num_contract_reallocs = lh->num_contract_reallocs + 1;
              lh->num_alloc_nodes = lh->num_alloc_nodes >> 1;
              lh->p = uVar4;
            }
            else {
              uVar4 = uVar4 - 1;
              ppLVar6 = lh->b;
              lh->p = uVar4;
            }
            lh->num_nodes = uVar14 - 1;
            pLVar8 = ppLVar6[uVar4];
            lh->num_contracts = lh->num_contracts + 1;
            if (pLVar8 == (LHASH_NODE *)0x0) {
              ppLVar6[uVar4] = pLVar11;
              return pvVar7;
            }
            do {
              pLVar9 = pLVar8;
              pLVar8 = pLVar9->next;
            } while (pLVar8 != (lhash_node_st *)0x0);
            pLVar9->next = pLVar11;
            return pvVar7;
          }
          break;
        }
      }
      pplVar12 = &pLVar11->next;
      pLVar11 = pLVar11->next;
    } while (pLVar11 != (lhash_node_st *)0x0);
    uVar2 = lh->num_no_delete;
  }
  lh->num_no_delete = uVar2 + 1;
  return (void *)0x0;
}

