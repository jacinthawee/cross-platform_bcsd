
void * sk_delete_ptr(_STACK *st,void *p)

{
  int iVar1;
  int iVar2;
  char **ppcVar3;
  char **ppcVar4;
  int iVar5;
  
  iVar5 = st->num;
  if (iVar5 < 1) {
    return (void *)0x0;
  }
  ppcVar4 = st->data;
  if ((char *)p == *ppcVar4) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    ppcVar3 = ppcVar4;
    do {
      ppcVar3 = ppcVar3 + 1;
      iVar2 = iVar2 + 1;
      if (iVar2 == iVar5) {
        return (void *)0x0;
      }
    } while (*ppcVar3 != (char *)p);
    if (iVar2 < 0) {
      return (void *)0x0;
    }
  }
  iVar5 = iVar5 + -1;
  if ((iVar5 != iVar2) && (iVar2 < iVar5)) {
    iVar1 = iVar2 << 2;
    while( true ) {
      iVar2 = iVar2 + 1;
      *(undefined4 *)((int)ppcVar4 + iVar1) = *(undefined4 *)((int)ppcVar4 + iVar1 + 4);
      if (iVar2 == iVar5) break;
      ppcVar4 = st->data;
      iVar1 = iVar1 + 4;
    }
  }
  st->num = iVar5;
  return p;
}

