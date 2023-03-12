
int sk_unshift(_STACK *st,void *data)

{
  int iVar1;
  char **ppcVar2;
  int iVar3;
  
  if (st == (_STACK *)0x0) {
    return 0;
  }
  iVar1 = st->num;
  iVar3 = iVar1 + 1;
  if (iVar3 < st->num_alloc) {
    ppcVar2 = st->data;
  }
  else {
    ppcVar2 = (char **)(*(code *)PTR_CRYPTO_realloc_006a8c44)
                                 (st->data,st->num_alloc << 3,"stack.c",0x96);
    if (ppcVar2 == (char **)0x0) {
      return 0;
    }
    iVar1 = st->num;
    st->data = ppcVar2;
    iVar3 = iVar1 + 1;
    st->num_alloc = st->num_alloc << 1;
  }
  if (iVar1 < 1) {
    ppcVar2[iVar1] = (char *)data;
  }
  else {
    (*(code *)PTR_memmove_006aabfc)(ppcVar2 + 1,ppcVar2,iVar3 << 2);
    *st->data = (char *)data;
  }
  st->num = iVar3;
  st->sorted = 0;
  return iVar3;
}

