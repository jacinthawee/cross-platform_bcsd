
void sk_pop_free(_STACK *st,func *func)

{
  int iVar1;
  char **ppcVar2;
  int iVar3;
  int iVar4;
  
  if (st != (_STACK *)0x0) {
    ppcVar2 = st->data;
    iVar3 = st->num;
    if (0 < iVar3) {
      iVar4 = 0;
      iVar1 = 0;
      do {
        iVar4 = iVar4 + 1;
        if (*(void **)((int)ppcVar2 + iVar1) != (void *)0x0) {
          (*func)(*(void **)((int)ppcVar2 + iVar1));
          iVar3 = st->num;
          ppcVar2 = st->data;
        }
        iVar1 = iVar4 * 4;
      } while (iVar4 < iVar3);
    }
    if (ppcVar2 != (char **)0x0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)(ppcVar2);
    }
                    /* WARNING: Could not recover jumptable at 0x0052e75c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a7f88)(st);
    return;
  }
  return;
}

