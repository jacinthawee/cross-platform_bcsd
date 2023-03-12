
undefined4 file_gets(int param_1,char *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  *param_2 = '\0';
  iVar1 = (*(code *)PTR_fgets_006a9ae0)(param_2,param_3,*(undefined4 *)(param_1 + 0x20));
  if ((iVar1 != 0) && (*param_2 != '\0')) {
                    /* WARNING: Could not recover jumptable at 0x0052183c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)PTR_strlen_006a9a24)(param_2);
    return uVar2;
  }
  return 0;
}

