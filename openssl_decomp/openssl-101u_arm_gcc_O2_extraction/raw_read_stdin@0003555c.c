
void raw_read_stdin(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = fileno(stdin);
  (*(code *)PTR_read_00189034)(iVar1,param_1,param_2,param_4);
  return;
}
