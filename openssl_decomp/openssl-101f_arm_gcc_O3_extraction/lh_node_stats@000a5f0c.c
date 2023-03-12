
void lh_node_stats(_LHASH *lh,FILE *out)

{
  BIO_METHOD *type;
  BIO *bp;
  LHASH_NODE *pLVar1;
  LHASH_NODE *pLVar2;
  uint uVar3;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    return;
  }
  BIO_ctrl(bp,0x6a,0,out);
  uVar3 = 0;
  if (lh->num_nodes != 0) {
    do {
      pLVar1 = lh->b[uVar3];
      pLVar2 = pLVar1;
      if (pLVar1 != (LHASH_NODE *)0x0) {
        pLVar2 = (LHASH_NODE *)0x0;
        do {
          pLVar1 = pLVar1->next;
          pLVar2 = (LHASH_NODE *)((int)&pLVar2->data + 1);
        } while (pLVar1 != (lhash_node_st *)0x0);
      }
      BIO_printf(bp,"node %6u -> %3u\n",uVar3,pLVar2);
      uVar3 = uVar3 + 1;
    } while (uVar3 < lh->num_nodes);
  }
  BIO_free(bp);
  return;
}

