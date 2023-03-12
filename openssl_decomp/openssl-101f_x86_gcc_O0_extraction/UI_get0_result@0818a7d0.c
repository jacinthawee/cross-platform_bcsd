
char * UI_get0_result(UI *ui,int i)

{
  int iVar1;
  int *piVar2;
  int line;
  
  if (i < 0) {
    line = 0x1ce;
    iVar1 = 0x67;
  }
  else {
    iVar1 = sk_num(*(_STACK **)(ui + 4));
    if (i < iVar1) {
      piVar2 = (int *)sk_value(*(_STACK **)(ui + 4),i);
      if (piVar2 == (int *)0x0) {
        return (char *)0x0;
      }
      if (1 < *piVar2 - 1U) {
        return (char *)0x0;
      }
      return (char *)piVar2[3];
    }
    line = 0x1d3;
    iVar1 = 0x66;
  }
  ERR_put_error(0x28,0x6b,iVar1,"ui_lib.c",line);
  return (char *)0x0;
}

