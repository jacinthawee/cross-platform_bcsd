
void * sk_delete(_STACK *st,int loc)

{
  char *pcVar1;
  int iVar2;
  char **ppcVar3;
  int iVar4;
  
  if (((st != (_STACK *)0x0) && (-1 < loc)) && (loc < st->num)) {
    ppcVar3 = st->data;
    iVar4 = st->num + -1;
    iVar2 = loc * 4;
    pcVar1 = ppcVar3[loc];
    if ((loc != iVar4) && (loc < iVar4)) {
      while( true ) {
        loc = loc + 1;
        *(undefined4 *)((int)ppcVar3 + iVar2) = *(undefined4 *)((int)ppcVar3 + iVar2 + 4);
        if (loc == iVar4) break;
        ppcVar3 = st->data;
        iVar2 = iVar2 + 4;
      }
    }
    st->num = iVar4;
    return pcVar1;
  }
  return (void *)0x0;
}

