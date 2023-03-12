
void * sk_shift(_STACK *st)

{
  char *pcVar1;
  char **ppcVar2;
  int iVar3;
  int iVar4;
  char **ppcVar5;
  int iVar6;
  
  if ((st != (_STACK *)0x0) && (iVar6 = st->num + -1, 0 < st->num)) {
    ppcVar2 = st->data;
    pcVar1 = *ppcVar2;
    if (iVar6 != 0) {
      iVar4 = 4;
      iVar3 = 0;
      while( true ) {
        ppcVar5 = (char **)((int)ppcVar2 + iVar4);
        iVar4 = iVar4 + 4;
        ppcVar2[iVar3] = *ppcVar5;
        if (iVar6 <= iVar3 + 1) break;
        ppcVar2 = st->data;
        iVar3 = iVar3 + 1;
      }
    }
    st->num = iVar6;
    return pcVar1;
  }
  return (void *)0x0;
}

