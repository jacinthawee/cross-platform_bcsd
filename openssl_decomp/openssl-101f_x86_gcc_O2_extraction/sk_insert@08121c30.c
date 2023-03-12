
int sk_insert(_STACK *sk,void *data,int where)

{
  char **ppcVar1;
  size_t __n;
  int iVar2;
  int iVar3;
  
  if (sk == (_STACK *)0x0) {
    return 0;
  }
  iVar2 = sk->num;
  iVar3 = iVar2 + 1;
  if (iVar3 < sk->num_alloc) {
    ppcVar1 = sk->data;
  }
  else {
    ppcVar1 = (char **)CRYPTO_realloc(sk->data,sk->num_alloc << 3,"stack.c",0x96);
    if (ppcVar1 == (char **)0x0) {
      return 0;
    }
    iVar2 = sk->num;
    sk->data = ppcVar1;
    sk->num_alloc = sk->num_alloc << 1;
    iVar3 = iVar2 + 1;
  }
  if ((where < 0) || (iVar2 <= where)) {
    ppcVar1[iVar2] = (char *)data;
  }
  else {
    __n = (iVar2 - where) * 4 + 4;
    if (iVar2 < where) {
      __n = 4;
    }
    memmove((void *)((int)ppcVar1 + ((iVar2 * 4 + 8) - __n)),
            (void *)(((iVar2 * 4 + 4) - __n) + (int)ppcVar1),__n);
    sk->data[where] = (char *)data;
  }
  sk->num = iVar3;
  sk->sorted = 0;
  return iVar3;
}

