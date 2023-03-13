
void lh_doall(_LHASH *lh,LHASH_DOALL_FN_TYPE func)

{
  void **ppvVar1;
  void **ppvVar2;
  int iVar3;
  int iVar4;
  
  if (lh != (_LHASH *)0x0) {
    iVar3 = lh->num_nodes - 1;
    if (-1 < iVar3) {
      iVar4 = lh->num_nodes * 4;
      do {
        iVar4 = iVar4 + -4;
        ppvVar2 = *(void ***)((int)lh->b + iVar4);
        while (ppvVar2 != (void **)0x0) {
          ppvVar1 = (void **)ppvVar2[1];
          (*func)(*ppvVar2);
          ppvVar2 = ppvVar1;
        }
        iVar3 = iVar3 + -1;
      } while (iVar3 != -1);
    }
  }
  return;
}

