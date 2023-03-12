
void raw_write_stdout(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = fileno(stdout);
  (*(code *)PTR_write_0018a174)(iVar1,param_1,param_2,param_4);
  return;
}

