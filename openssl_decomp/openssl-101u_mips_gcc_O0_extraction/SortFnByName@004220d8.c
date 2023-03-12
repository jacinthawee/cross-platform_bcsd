
int SortFnByName(int *param_1,int *param_2)

{
  int iVar1;
  
  if (*param_1 != *param_2) {
    return *param_1 - *param_2;
  }
  iVar1 = (*(code *)PTR_strcmp_006a9b18)(param_1[1],param_2[1]);
  return iVar1;
}

