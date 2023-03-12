
void lh_node_usage_stats_bio(_LHASH *lh,BIO *out)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int extraout_r1;
  int extraout_r1_00;
  LHASH_NODE *pLVar5;
  int iVar6;
  LHASH_NODE **ppLVar7;
  int iVar9;
  int iVar10;
  uint uVar11;
  LHASH_NODE **ppLVar8;
  
  uVar11 = lh->num_nodes;
  if (uVar11 != 0) {
    iVar9 = 0;
    iVar10 = 0;
    ppLVar7 = lh->b;
    do {
      ppLVar8 = ppLVar7 + 1;
      pLVar5 = *ppLVar7;
      if (pLVar5 != (LHASH_NODE *)0x0) {
        iVar6 = 0;
        do {
          pLVar5 = pLVar5->next;
          iVar6 = iVar6 + 1;
        } while (pLVar5 != (lhash_node_st *)0x0);
        if (iVar6 != 0) {
          iVar9 = iVar9 + 1;
          iVar10 = iVar10 + iVar6;
        }
      }
      ppLVar7 = ppLVar8;
    } while (ppLVar8 != lh->b + uVar11);
    BIO_printf(out,"%lu nodes used out of %u\n",iVar9,uVar11);
    BIO_printf(out,"%lu items\n",iVar10);
    if (iVar9 != 0) {
      uVar11 = lh->num_nodes;
      uVar1 = __udivsi3(iVar10,uVar11);
      __aeabi_uidivmod(iVar10,uVar11);
      uVar2 = __udivsi3(extraout_r1 * 100,uVar11);
      uVar3 = __udivsi3(iVar10,iVar9);
      __aeabi_uidivmod(iVar10,iVar9);
      uVar4 = __udivsi3(extraout_r1_00 * 100,iVar9);
      BIO_printf(out,"load %d.%02d  actual load %d.%02d\n",uVar1,uVar2,uVar3,uVar4);
    }
    return;
  }
  BIO_printf(out,"%lu nodes used out of %u\n",0);
  BIO_vprintf(out,"%lu items\n",&stack0xfffffff8);
  return;
}

