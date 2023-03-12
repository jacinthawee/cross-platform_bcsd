
int sk_unshift(_STACK *st,void *data)

{
  char **__src;
  int iVar1;
  int iVar2;
  
  if (st == (_STACK *)0x0) {
    return 0;
  }
  iVar1 = st->num;
  iVar2 = iVar1 + 1;
  if (iVar2 < st->num_alloc) {
    __src = st->data;
  }
  else {
    __src = (char **)CRYPTO_realloc(st->data,st->num_alloc << 3,"stack.c",0x96);
    if (__src == (char **)0x0) {
      return 0;
    }
    iVar1 = st->num;
    iVar2 = iVar1 + 1;
    st->data = __src;
    st->num_alloc = st->num_alloc << 1;
  }
  if (iVar1 < 1) {
    __src[iVar1] = (char *)data;
  }
  else {
    memmove(__src + 1,__src,iVar2 << 2);
    *st->data = (char *)data;
  }
  st->num = iVar2;
  st->sorted = 0;
  return iVar2;
}

