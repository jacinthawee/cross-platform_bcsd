
void lh_node_usage_stats(_LHASH *lh,FILE *out)

{
  BIO_METHOD *type;
  BIO *bp;
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
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    return;
  }
  BIO_ctrl(bp,0x6a,0,out);
  uVar11 = lh->num_nodes;
  if (uVar11 == 0) {
    BIO_printf(bp,"%lu nodes used out of %u\n",0,0);
    BIO_printf(bp,"%lu items\n",0);
  }
  else {
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
          iVar10 = iVar10 + 1;
          iVar9 = iVar9 + iVar6;
        }
      }
      ppLVar7 = ppLVar8;
    } while (ppLVar8 != lh->b + uVar11);
    BIO_printf(bp,"%lu nodes used out of %u\n",iVar10,uVar11);
    BIO_printf(bp,"%lu items\n",iVar9);
    if (iVar10 != 0) {
      uVar11 = lh->num_nodes;
      uVar1 = __udivsi3(iVar9,uVar11);
      __aeabi_uidivmod(iVar9,uVar11);
      uVar2 = __udivsi3(extraout_r1 * 100,uVar11);
      uVar3 = __udivsi3(iVar9,iVar10);
      __aeabi_uidivmod(iVar9,iVar10);
      uVar4 = __udivsi3(extraout_r1_00 * 100,iVar10);
      BIO_printf(bp,"load %d.%02d  actual load %d.%02d\n",uVar1,uVar2,uVar3,uVar4);
      BIO_free(bp);
      return;
    }
  }
  BIO_free(bp);
  return;
}

