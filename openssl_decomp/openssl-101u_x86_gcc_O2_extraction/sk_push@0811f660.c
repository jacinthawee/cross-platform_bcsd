
int sk_push(_STACK *st,void *data)

{
  int iVar1;
  int iVar2;
  char **ppcVar3;
  size_t __n;
  int iVar4;
  
  iVar1 = st->num;
  iVar2 = iVar1 + 1;
  iVar4 = iVar1;
  if (st->num_alloc <= iVar2) {
    ppcVar3 = (char **)CRYPTO_realloc(st->data,st->num_alloc << 3,"stack.c",0x99);
    if (ppcVar3 == (char **)0x0) {
      return 0;
    }
    st->num_alloc = st->num_alloc << 1;
    st->data = ppcVar3;
    iVar4 = st->num;
    if ((-1 < iVar1) && (iVar1 < iVar4)) {
      iVar2 = iVar4 + 1;
      __n = (iVar2 - iVar1) * 4;
      if (iVar4 < iVar1) {
        __n = 4;
      }
      memmove((void *)((int)ppcVar3 + ((iVar4 * 4 + 8) - __n)),
              (void *)(((iVar4 * 4 + 4) - __n) + (int)ppcVar3),__n);
      st->data[iVar1] = (char *)data;
      goto LAB_0811f681;
    }
    iVar2 = iVar4 + 1;
  }
  st->data[iVar4] = (char *)data;
LAB_0811f681:
  st->num = iVar2;
  st->sorted = 0;
  return iVar2;
}

