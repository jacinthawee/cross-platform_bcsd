
int X509v3_get_ext_by_critical(stack_st_X509_EXTENSION *x,int crit,int lastpos)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (x == (stack_st_X509_EXTENSION *)0x0) {
    return -1;
  }
  iVar3 = lastpos + 1;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  iVar1 = (*(code *)PTR_sk_num_006a6e2c)();
  if (iVar3 < iVar1) {
    if (crit == 0) {
      do {
        iVar2 = (*(code *)PTR_sk_value_006a6e24)(x,iVar3);
        if (*(int *)(iVar2 + 4) < 1) {
          return iVar3;
        }
        iVar3 = iVar3 + 1;
      } while (iVar1 != iVar3);
    }
    else {
      do {
        iVar2 = (*(code *)PTR_sk_value_006a6e24)(x,iVar3);
        if (0 < *(int *)(iVar2 + 4)) {
          return iVar3;
        }
        iVar3 = iVar3 + 1;
      } while (iVar1 != iVar3);
    }
  }
  return -1;
}

