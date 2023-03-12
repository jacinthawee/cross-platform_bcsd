
void lh_node_stats_bio(_LHASH *lh,BIO *out)

{
  LHASH_NODE *pLVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (lh->num_nodes != 0) {
    uVar3 = 0;
    do {
      iVar2 = 0;
      for (pLVar1 = lh->b[uVar3]; pLVar1 != (LHASH_NODE *)0x0; pLVar1 = pLVar1->next) {
        iVar2 = iVar2 + 1;
      }
      uVar4 = uVar3 + 1;
      BIO_printf(out,"node %6u -> %3u\n",uVar3,iVar2);
      uVar3 = uVar4;
    } while (uVar4 <= lh->num_nodes && lh->num_nodes != uVar4);
  }
  return;
}

