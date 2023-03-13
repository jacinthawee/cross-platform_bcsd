
void * sk_delete_ptr(_STACK *st,void *p)

{
  char **ppcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = st->num;
  if (iVar3 < 1) {
    return (void *)0x0;
  }
  ppcVar1 = st->data;
  iVar2 = 0;
  if ((char *)p != *ppcVar1) {
    do {
      iVar2 = iVar2 + 1;
      if (iVar2 == iVar3) {
        return (void *)0x0;
      }
    } while (ppcVar1[iVar2] != (char *)p);
    if (iVar2 < 0) {
      return (void *)0x0;
    }
  }
  iVar3 = iVar3 + -1;
  if ((iVar2 != iVar3) && (iVar2 < iVar3)) {
    iVar4 = iVar2 * 4;
    while( true ) {
      iVar2 = iVar2 + 1;
      *(undefined4 *)((int)ppcVar1 + iVar4) = *(undefined4 *)((int)ppcVar1 + iVar4 + 4);
      if (iVar3 == iVar2) break;
      ppcVar1 = st->data;
      iVar4 = iVar4 + 4;
    }
  }
  st->num = iVar3;
  return p;
}

