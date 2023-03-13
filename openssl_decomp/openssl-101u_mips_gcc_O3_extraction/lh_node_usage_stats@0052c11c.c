
void lh_node_usage_stats(_LHASH *lh,FILE *out)

{
  BIO_METHOD *type;
  BIO *bp;
  LHASH_NODE *pLVar1;
  int iVar2;
  LHASH_NODE **ppLVar3;
  LHASH_NODE **ppLVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    return;
  }
  BIO_ctrl(bp,0x6a,0,out);
  if (lh->num_nodes == 0) {
    BIO_printf(bp,"%lu nodes used out of %u\n",0,0);
    BIO_printf(bp,"%lu items\n",0);
  }
  else {
    ppLVar3 = lh->b;
    uVar7 = 0;
    uVar6 = 0;
    ppLVar4 = ppLVar3 + lh->num_nodes;
    do {
      pLVar1 = *ppLVar3;
      iVar2 = 0;
      if (pLVar1 != (LHASH_NODE *)0x0) {
        do {
          pLVar1 = pLVar1->next;
          iVar2 = iVar2 + 1;
        } while (pLVar1 != (lhash_node_st *)0x0);
        if (iVar2 != 0) {
          uVar6 = uVar6 + 1;
          uVar7 = uVar7 + iVar2;
        }
      }
      ppLVar3 = ppLVar3 + 1;
    } while (ppLVar4 != ppLVar3);
    BIO_printf(bp,"%lu nodes used out of %u\n",uVar6);
    BIO_printf(bp,"%lu items\n",uVar7);
    if (uVar6 != 0) {
      if (uVar6 == 0) {
        trap(7);
      }
      uVar5 = lh->num_nodes;
      if (uVar5 == 0) {
        trap(7);
      }
      if (uVar6 == 0) {
        trap(7);
      }
      if (uVar5 == 0) {
        trap(7);
      }
      BIO_printf(bp,"load %d.%02d  actual load %d.%02d\n",uVar7 / uVar5,
                 ((uVar7 % uVar5) * 100) / uVar5,uVar7 / uVar6,((uVar7 % uVar6) * 100) / uVar6);
      BIO_free(bp);
      return;
    }
  }
  BIO_free(bp);
  return;
}

