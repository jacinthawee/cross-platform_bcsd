
void raw_write_stdout(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_fileno_006a99dc)(*(undefined4 *)PTR_stdout_006a99c8);
                    /* WARNING: Could not recover jumptable at 0x0045ec6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_write_006a9a1c)(uVar1,param_1,param_2);
  return;
}

