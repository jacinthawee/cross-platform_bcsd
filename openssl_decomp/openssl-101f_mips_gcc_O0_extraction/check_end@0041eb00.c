
undefined4 check_end(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = (*(code *)PTR_strlen_006aab30)(param_2);
  iVar2 = (*(code *)PTR_strlen_006aab30)(param_1);
  if (iVar1 <= iVar2) {
    uVar3 = (*(code *)PTR_strcmp_006aac20)(param_1 + (iVar2 - iVar1),param_2);
    return uVar3;
  }
  return 1;
}

