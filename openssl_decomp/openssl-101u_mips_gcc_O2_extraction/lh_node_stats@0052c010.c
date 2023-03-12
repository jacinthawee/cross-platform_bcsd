
void lh_node_stats(_LHASH *lh,FILE *out)

{
  BIO_METHOD *type;
  BIO *bp;
  LHASH_NODE *pLVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  
  puVar4 = &_gp;
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    return;
  }
  BIO_ctrl(bp,0x6a,0,out);
  if (lh->num_nodes != 0) {
    uVar3 = 0;
    do {
      iVar2 = 0;
      for (pLVar1 = lh->b[uVar3]; pLVar1 != (LHASH_NODE *)0x0; pLVar1 = pLVar1->next) {
        iVar2 = iVar2 + 1;
      }
      BIO_printf(bp,"node %6u -> %3u\n",uVar3,iVar2,puVar4);
      uVar3 = uVar3 + 1;
    } while (uVar3 < lh->num_nodes);
  }
  BIO_free(bp);
  return;
}

