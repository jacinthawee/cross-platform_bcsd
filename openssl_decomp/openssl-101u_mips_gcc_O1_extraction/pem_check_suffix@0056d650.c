
int pem_check_suffix(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_strlen_006a9a24)();
  iVar2 = (*(code *)PTR_strlen_006a9a24)(param_2);
  if (iVar2 + 1 < iVar1) {
    iVar2 = param_1 + (iVar1 - iVar2);
    iVar1 = (*(code *)PTR_strcmp_006a9b18)(iVar2,param_2);
    if (iVar1 == 0) {
      if (*(char *)(iVar2 + -1) != ' ') {
        return 0;
      }
      return (iVar2 + -1) - param_1;
    }
  }
  return 0;
}

