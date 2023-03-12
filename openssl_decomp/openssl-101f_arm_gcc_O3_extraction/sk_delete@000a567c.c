
void * sk_delete(_STACK *st,int loc)

{
  int iVar1;
  char *pcVar2;
  char **ppcVar3;
  int iVar4;
  
  pcVar2 = (char *)((uint)loc >> 0x1f);
  if (st == (_STACK *)0x0) {
    pcVar2 = (char *)0x1;
  }
  if (pcVar2 != (char *)0x0) {
    return (void *)0x0;
  }
  if (loc < st->num) {
    ppcVar3 = st->data;
    iVar4 = st->num + -1;
    pcVar2 = ppcVar3[loc];
    if ((iVar4 != loc) && (iVar1 = loc << 2, loc < iVar4)) {
      while( true ) {
        loc = loc + 1;
        *(undefined4 *)((int)ppcVar3 + iVar1) = *(undefined4 *)((int)ppcVar3 + iVar1 + 4);
        if (loc == iVar4) break;
        ppcVar3 = st->data;
        iVar1 = iVar1 + 4;
      }
    }
    st->num = iVar4;
  }
  return pcVar2;
}

