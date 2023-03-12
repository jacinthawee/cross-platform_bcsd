
void raw_read_stdin(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_fileno_006aaae8)(*(undefined4 *)PTR_stdin_006aab20);
                    /* WARNING: Could not recover jumptable at 0x0045e110. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_read_006aac18)(uVar1,param_1,param_2);
  return;
}

