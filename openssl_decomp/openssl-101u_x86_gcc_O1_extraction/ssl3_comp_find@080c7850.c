
int * ssl3_comp_find(_STACK *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if ((param_2 != 0) && (param_1 != (_STACK *)0x0)) {
    iVar1 = sk_num(param_1);
    if (0 < iVar1) {
      iVar3 = 0;
      do {
        piVar2 = (int *)sk_value(param_1,iVar3);
        if (param_2 == *piVar2) {
          return piVar2;
        }
        iVar3 = iVar3 + 1;
      } while (iVar1 != iVar3);
    }
  }
  return (int *)0x0;
}

