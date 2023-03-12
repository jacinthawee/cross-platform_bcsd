
void lh_node_stats_bio(_LHASH *lh,BIO *out)

{
  LHASH_NODE *pLVar1;
  LHASH_NODE *pLVar2;
  LHASH_NODE *pLVar3;
  uint uVar4;
  
  if (lh->num_nodes != 0) {
    uVar4 = 0;
    do {
      pLVar2 = lh->b[uVar4];
      if (pLVar2 != (LHASH_NODE *)0x0) {
        pLVar1 = (LHASH_NODE *)0x0;
        pLVar3 = pLVar2;
        do {
          pLVar3 = pLVar3->next;
          pLVar2 = (LHASH_NODE *)((int)&pLVar1->data + 1);
          pLVar1 = pLVar2;
        } while (pLVar3 != (lhash_node_st *)0x0);
      }
      BIO_printf(out,"node %6u -> %3u\n",uVar4,pLVar2);
      uVar4 = uVar4 + 1;
    } while (uVar4 < lh->num_nodes);
  }
  return;
}

