
void sk_pop_free(_STACK *st,func *func)

{
  int iVar1;
  char **ptr;
  int iVar2;
  
  if (st != (_STACK *)0x0) {
    iVar1 = st->num;
    ptr = st->data;
    if (0 < iVar1) {
      iVar2 = 0;
      do {
        if (ptr[iVar2] != (char *)0x0) {
          (*func)(ptr[iVar2]);
          ptr = st->data;
          iVar1 = st->num;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
    if (ptr != (char **)0x0) {
      CRYPTO_free(ptr);
    }
    CRYPTO_free(st);
    return;
  }
  return;
}

