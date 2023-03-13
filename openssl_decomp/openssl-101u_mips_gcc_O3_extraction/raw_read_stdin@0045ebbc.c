
void raw_read_stdin(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_fileno_006a99dc)(*(undefined4 *)PTR_stdin_006a9a14);
                    /* WARNING: Could not recover jumptable at 0x0045ec10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_read_006a9b10)(uVar1,param_1,param_2);
  return;
}

