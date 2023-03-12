
int sk_push(_STACK *st,void *data)

{
  int iVar1;
  int iVar2;
  char **ppcVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = st->num;
  iVar1 = iVar4 + 1;
  if (iVar1 < st->num_alloc) {
    ppcVar3 = st->data;
    iVar2 = iVar4;
  }
  else {
    ppcVar3 = (char **)CRYPTO_realloc(st->data,st->num_alloc << 3,"stack.c",0x96);
    if (ppcVar3 == (char **)0x0) {
      return 0;
    }
    iVar2 = st->num;
    st->data = ppcVar3;
    st->num_alloc = st->num_alloc << 1;
    if ((iVar4 < iVar2) && (-1 < iVar4)) {
      iVar1 = iVar2 + 1;
      iVar5 = iVar1 - iVar4;
      memmove(ppcVar3 + ((iVar2 + 2) - iVar5),ppcVar3 + ((iVar2 + 1) - iVar5),iVar5 * 4);
      ppcVar3 = st->data;
      iVar2 = iVar4;
    }
    else {
      iVar1 = iVar2 + 1;
    }
  }
  ppcVar3[iVar2] = (char *)data;
  st->num = iVar1;
  st->sorted = 0;
  return iVar1;
}

