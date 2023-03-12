
void lh_free(_LHASH *lh)

{
  LHASH_NODE **ppLVar1;
  LHASH_NODE *pLVar2;
  uint uVar3;
  uint uVar4;
  
  if (lh != (_LHASH *)0x0) {
    uVar3 = lh->num_nodes;
    ppLVar1 = lh->b;
    if (uVar3 != 0) {
      uVar4 = 0;
      do {
        pLVar2 = ppLVar1[uVar4];
        if (pLVar2 != (LHASH_NODE *)0x0) {
          do {
            pLVar2 = pLVar2->next;
            (*(code *)PTR_CRYPTO_free_006a6e88)();
          } while (pLVar2 != (lhash_node_st *)0x0);
          ppLVar1 = lh->b;
          uVar3 = lh->num_nodes;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar3);
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(ppLVar1);
                    /* WARNING: Could not recover jumptable at 0x0052b7e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(lh);
    return;
  }
  return;
}

