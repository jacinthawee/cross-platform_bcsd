
undefined4 null_puts(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00520e48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)PTR_strlen_006a9a24)(param_2);
    return uVar1;
  }
  return 0;
}

