
int conf_value_LHASH_COMP(int *param_1,int *param_2)

{
  int iVar1;
  
  if ((*param_1 != *param_2) && (iVar1 = (*(code *)PTR_strcmp_006a9b18)(), iVar1 != 0)) {
    return iVar1;
  }
  if (param_1[1] == 0) {
    return -(uint)(param_2[1] != 0);
  }
  if (param_2[1] == 0) {
    return 1;
  }
  iVar1 = (*(code *)PTR_strcmp_006a9b18)();
  return iVar1;
}

