
void program_name(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_strrchr_006a99ac)(param_1,0x2f);
  iVar2 = iVar1 + 1;
  if (iVar1 == 0) {
    iVar2 = param_1;
  }
                    /* WARNING: Could not recover jumptable at 0x0045a0f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_BUF_strlcpy_006a6f64)(param_2,iVar2,param_3);
  return;
}

