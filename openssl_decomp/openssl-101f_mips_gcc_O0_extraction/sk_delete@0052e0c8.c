
void * sk_delete(_STACK *st,int loc)

{
  char *pcVar1;
  int iVar2;
  char **ppcVar3;
  char **ppcVar4;
  int iVar5;
  
  if ((st != (_STACK *)0x0) && (-1 < loc)) {
    iVar2 = loc * 4;
    if (loc < st->num) {
      ppcVar3 = st->data;
      iVar5 = st->num + -1;
      ppcVar4 = ppcVar3 + loc;
      pcVar1 = *ppcVar4;
      if (loc != iVar5) {
        if (iVar5 <= loc) {
          st->num = iVar5;
          return pcVar1;
        }
        while( true ) {
          iVar2 = iVar2 + 4;
          loc = loc + 1;
          *ppcVar4 = *(char **)((int)ppcVar3 + iVar2);
          if (loc == iVar5) break;
          ppcVar3 = st->data;
          ppcVar4 = (char **)((int)ppcVar3 + iVar2);
        }
      }
      st->num = iVar5;
      return pcVar1;
    }
  }
  return (void *)0x0;
}

