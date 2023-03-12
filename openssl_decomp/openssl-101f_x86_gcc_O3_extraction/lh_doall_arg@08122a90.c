
void lh_doall_arg(_LHASH *lh,LHASH_DOALL_ARG_FN_TYPE func,void *arg)

{
  void **ppvVar1;
  void **ppvVar2;
  int iVar3;
  int local_20;
  
  if (lh != (_LHASH *)0x0) {
    local_20 = lh->num_nodes - 1;
    if (-1 < local_20) {
      iVar3 = lh->num_nodes * 4;
      do {
        iVar3 = iVar3 + -4;
        ppvVar2 = *(void ***)((int)lh->b + iVar3);
        while (ppvVar2 != (void **)0x0) {
          ppvVar1 = (void **)ppvVar2[1];
          (*func)(*ppvVar2,arg);
          ppvVar2 = ppvVar1;
        }
        local_20 = local_20 + -1;
      } while (local_20 != -1);
    }
  }
  return;
}

