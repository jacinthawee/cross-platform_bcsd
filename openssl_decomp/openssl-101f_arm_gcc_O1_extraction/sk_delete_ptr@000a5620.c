
void * sk_delete_ptr(_STACK *st,void *p)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  char **ppcVar4;
  int iVar5;
  char **ppcVar6;
  
  iVar5 = st->num;
  if (iVar5 < 1) {
    return (void *)0x0;
  }
  ppcVar6 = st->data;
  pcVar2 = *ppcVar6;
  if (pcVar2 == (char *)p) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0;
    ppcVar4 = ppcVar6;
    do {
      iVar3 = iVar3 + 1;
      if (iVar3 == iVar5) {
        return (void *)0x0;
      }
      ppcVar4 = ppcVar4 + 1;
      pcVar2 = *ppcVar4;
    } while (pcVar2 != (char *)p);
    if (iVar3 < 0) {
      return (void *)0x0;
    }
  }
  iVar5 = iVar5 + -1;
  if ((iVar3 != iVar5) && (iVar3 < iVar5)) {
    iVar1 = iVar3 << 2;
    while( true ) {
      iVar3 = iVar3 + 1;
      *(undefined4 *)((int)ppcVar6 + iVar1) = *(undefined4 *)((int)ppcVar6 + iVar1 + 4);
      if (iVar3 == iVar5) break;
      ppcVar6 = st->data;
      iVar1 = iVar1 + 4;
    }
  }
  st->num = iVar5;
  return pcVar2;
}

