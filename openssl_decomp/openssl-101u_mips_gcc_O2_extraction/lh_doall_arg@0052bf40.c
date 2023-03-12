
void lh_doall_arg(_LHASH *lh,LHASH_DOALL_ARG_FN_TYPE func,void *arg)

{
  void **ppvVar1;
  int iVar2;
  void **ppvVar3;
  int iVar4;
  
  if (lh != (_LHASH *)0x0) {
    iVar4 = lh->num_nodes - 1;
    if (-1 < iVar4) {
      iVar2 = lh->num_nodes * 4;
      do {
        iVar2 = iVar2 + -4;
        ppvVar1 = *(void ***)((int)lh->b + iVar2);
        while (ppvVar1 != (void **)0x0) {
          ppvVar3 = (void **)ppvVar1[1];
          (*func)(*ppvVar1,arg);
          ppvVar1 = ppvVar3;
        }
        iVar4 = iVar4 + -1;
      } while (iVar4 != -1);
    }
  }
  return;
}

