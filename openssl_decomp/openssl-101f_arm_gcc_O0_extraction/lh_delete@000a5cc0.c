
void * lh_delete(_LHASH *lh,void *data)

{
  ulong uVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  uint extraout_r1;
  uint extraout_r1_00;
  LHASH_NODE **ppLVar5;
  ulong uVar6;
  uint uVar7;
  LHASH_NODE *pLVar8;
  LHASH_NODE *pLVar9;
  LHASH_NODE *pLVar10;
  uint uVar11;
  lhash_node_st **pplVar12;
  LHASH_COMP_FN_TYPE pLVar13;
  
  lh->error = 0;
  uVar1 = (*lh->hash)(data);
  lh->num_hash_calls = lh->num_hash_calls + 1;
  __aeabi_uidivmod(uVar1,lh->pmax);
  uVar11 = extraout_r1;
  if (extraout_r1 < lh->p) {
    __aeabi_uidivmod(uVar1,lh->num_alloc_nodes);
    uVar11 = extraout_r1_00;
  }
  pLVar13 = lh->comp;
  pplVar12 = lh->b + uVar11;
  pLVar10 = lh->b[uVar11];
  do {
    if (pLVar10 == (LHASH_NODE *)0x0) {
LAB_000a5da2:
      lh->num_no_delete = lh->num_no_delete + 1;
      return (void *)0x0;
    }
    uVar6 = pLVar10->hash;
    lh->num_hash_comps = lh->num_hash_comps + 1;
    if (uVar1 == uVar6) {
      pvVar2 = pLVar10->data;
      lh->num_comp_calls = lh->num_comp_calls + 1;
      iVar3 = (*pLVar13)(pvVar2,data);
      if (iVar3 == 0) {
        pLVar10 = *pplVar12;
        if (pLVar10 != (LHASH_NODE *)0x0) {
          *pplVar12 = pLVar10->next;
          pvVar2 = pLVar10->data;
          CRYPTO_free(pLVar10);
          uVar11 = lh->num_nodes;
          lh->num_delete = lh->num_delete + 1;
          uVar1 = lh->num_items - 1;
          lh->num_items = uVar1;
          if ((uVar11 < 0x11) || (uVar4 = __udivsi3(uVar1 * 0x100,uVar11), lh->down_load < uVar4)) {
            return pvVar2;
          }
          uVar7 = lh->p;
          uVar4 = lh->pmax;
          iVar3 = uVar7 + uVar4 + 0x3fffffff;
          pLVar10 = lh->b[iVar3];
          lh->b[iVar3] = (LHASH_NODE *)0x0;
          if (uVar7 == 0) {
            ppLVar5 = (LHASH_NODE **)CRYPTO_realloc(lh->b,uVar4 << 2,"lhash.c",0x177);
            if (ppLVar5 == (LHASH_NODE **)0x0) {
              lh->error = lh->error + 1;
              return pvVar2;
            }
            uVar7 = lh->pmax >> 1;
            lh->b = ppLVar5;
            lh->pmax = uVar7;
            lh->num_alloc_nodes = lh->num_alloc_nodes >> 1;
            uVar7 = uVar7 - 1;
            lh->p = uVar7;
            uVar11 = lh->num_nodes;
            lh->num_contract_reallocs = lh->num_contract_reallocs + 1;
          }
          else {
            ppLVar5 = lh->b;
            uVar7 = uVar7 - 1;
            lh->p = uVar7;
          }
          pLVar8 = ppLVar5[uVar7];
          lh->num_nodes = uVar11 - 1;
          lh->num_contracts = lh->num_contracts + 1;
          if (pLVar8 == (LHASH_NODE *)0x0) {
            ppLVar5[uVar7] = pLVar10;
            return pvVar2;
          }
          do {
            pLVar9 = pLVar8;
            pLVar8 = pLVar9->next;
          } while (pLVar8 != (lhash_node_st *)0x0);
          pLVar9->next = pLVar10;
          return pvVar2;
        }
        goto LAB_000a5da2;
      }
    }
    pplVar12 = &pLVar10->next;
    pLVar10 = pLVar10->next;
  } while( true );
}

