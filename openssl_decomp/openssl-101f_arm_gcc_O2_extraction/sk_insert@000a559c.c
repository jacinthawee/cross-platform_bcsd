
int sk_insert(_STACK *sk,void *data,int where)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char **ppcVar4;
  
  if (sk == (_STACK *)0x0) {
    return 0;
  }
  iVar1 = sk->num;
  iVar3 = iVar1 + 1;
  if (iVar3 < sk->num_alloc) {
    ppcVar4 = sk->data;
  }
  else {
    ppcVar4 = (char **)CRYPTO_realloc(sk->data,sk->num_alloc << 3,"stack.c",0x96);
    if (ppcVar4 == (char **)0x0) {
      return 0;
    }
    iVar1 = sk->num;
    sk->data = ppcVar4;
    iVar3 = iVar1 + 1;
    sk->num_alloc = sk->num_alloc << 1;
  }
  if ((where < iVar1) && (-1 < where)) {
    iVar2 = iVar1 + (1 - where);
    memmove(ppcVar4 + ((iVar1 + 2) - iVar2),ppcVar4 + ((iVar1 + 1) - iVar2),iVar2 * 4);
    sk->data[where] = (char *)data;
  }
  else {
    ppcVar4[iVar1] = (char *)data;
  }
  sk->num = iVar3;
  sk->sorted = 0;
  return iVar3;
}

