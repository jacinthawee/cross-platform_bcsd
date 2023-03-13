
void * sk_pop(_STACK *st)

{
  int iVar1;
  char *pcVar2;
  
  if ((st != (_STACK *)0x0) && (0 < st->num)) {
    iVar1 = st->num + -1;
    pcVar2 = st->data[iVar1];
    st->num = iVar1;
    return pcVar2;
  }
  return (void *)0x0;
}

