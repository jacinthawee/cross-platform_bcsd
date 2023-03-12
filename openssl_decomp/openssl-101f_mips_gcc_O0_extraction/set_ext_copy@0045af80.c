
undefined4 set_ext_copy(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcasecmp_006aab24)(param_2,"none");
  if (iVar1 == 0) {
    *param_1 = 0;
    return 1;
  }
  iVar1 = (*(code *)PTR_strcasecmp_006aab24)(param_2,&DAT_00640118);
  if (iVar1 != 0) {
    iVar1 = (*(code *)PTR_strcasecmp_006aab24)(param_2,"copyall");
    if (iVar1 == 0) {
      *param_1 = 2;
      return 1;
    }
    return 0;
  }
  *param_1 = 1;
  return 1;
}

