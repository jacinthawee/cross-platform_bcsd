
void * sk_shift(_STACK *st)

{
  char **ppcVar1;
  char *pcVar2;
  char **ppcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if ((st != (_STACK *)0x0) && (0 < st->num)) {
    ppcVar3 = st->data;
    iVar6 = st->num + -1;
    pcVar2 = *ppcVar3;
    if (iVar6 != 0) {
      iVar5 = 4;
      iVar4 = 0;
      while( true ) {
        ppcVar1 = (char **)((int)ppcVar3 + iVar5);
        iVar5 = iVar5 + 4;
        ppcVar3[iVar4] = *ppcVar1;
        iVar4 = iVar4 + 1;
        if (iVar6 <= iVar4) break;
        ppcVar3 = st->data;
      }
    }
    st->num = iVar6;
    return pcVar2;
  }
  return (void *)0x0;
}

