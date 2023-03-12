
void lh_node_usage_stats(_LHASH *lh,FILE *out)

{
  LHASH_NODE **ppLVar1;
  uint uVar2;
  BIO_METHOD *type;
  BIO *bp;
  LHASH_NODE **ppLVar3;
  int iVar4;
  LHASH_NODE *pLVar5;
  uint uVar6;
  uint uVar7;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    return;
  }
  BIO_ctrl(bp,0x6a,0,out);
  uVar2 = lh->num_nodes;
  if (uVar2 == 0) {
    BIO_printf(bp,"%lu nodes used out of %u\n",0,0);
    BIO_printf(bp,"%lu items\n",0);
  }
  else {
    ppLVar3 = lh->b;
    ppLVar1 = ppLVar3 + uVar2;
    uVar6 = 0;
    uVar7 = 0;
    do {
      pLVar5 = *ppLVar3;
      if (pLVar5 != (LHASH_NODE *)0x0) {
        iVar4 = 0;
        do {
          pLVar5 = pLVar5->next;
          iVar4 = iVar4 + 1;
        } while (pLVar5 != (lhash_node_st *)0x0);
        if (iVar4 != 0) {
          uVar7 = uVar7 + 1;
          uVar6 = uVar6 + iVar4;
        }
      }
      ppLVar3 = ppLVar3 + 1;
    } while (ppLVar1 != ppLVar3);
    BIO_printf(bp,"%lu nodes used out of %u\n",uVar7,uVar2);
    BIO_printf(bp,"%lu items\n",uVar6);
    if (uVar7 != 0) {
      uVar2 = lh->num_nodes;
      BIO_printf(bp,"load %d.%02d  actual load %d.%02d\n",uVar6 / uVar2,
                 ((uVar6 % uVar2) * 100) / uVar2,uVar6 / uVar7,((uVar6 % uVar7) * 100) / uVar7);
      BIO_free(bp);
      return;
    }
  }
  BIO_free(bp);
  return;
}

