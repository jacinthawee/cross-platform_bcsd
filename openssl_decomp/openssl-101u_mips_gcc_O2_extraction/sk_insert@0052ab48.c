
int sk_insert(_STACK *sk,void *data,int where)

{
  int iVar1;
  char **ppcVar2;
  int iVar3;
  int iVar4;
  
  if (sk == (_STACK *)0x0) {
    return 0;
  }
  iVar1 = sk->num;
  iVar4 = iVar1 + 1;
  if (iVar4 < sk->num_alloc) {
    ppcVar2 = sk->data;
  }
  else {
    ppcVar2 = (char **)(*(code *)PTR_CRYPTO_realloc_006a7b58)
                                 (sk->data,sk->num_alloc << 3,"stack.c",0x99);
    if (ppcVar2 == (char **)0x0) {
      return 0;
    }
    iVar1 = sk->num;
    sk->data = ppcVar2;
    iVar4 = iVar1 + 1;
    sk->num_alloc = sk->num_alloc << 1;
  }
  if ((where < iVar1) && (-1 < where)) {
    iVar3 = (iVar1 - where) + 1;
    (*(code *)PTR_memmove_006a9af4)(ppcVar2 + ((iVar1 + 2) - iVar3),ppcVar2 + ((iVar1 + 1) - iVar3))
    ;
    sk->data[where] = (char *)data;
  }
  else {
    ppcVar2[iVar1] = (char *)data;
  }
  sk->num = iVar4;
  sk->sorted = 0;
  return iVar4;
}

