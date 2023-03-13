
void gnames_stack_print(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar1 = param_2;
  while( true ) {
    iVar1 = (*(code *)PTR_sk_num_006a6e2c)(param_2,iVar1);
    if (iVar1 <= iVar5) break;
    uVar2 = (*(code *)PTR_sk_value_006a6e24)(param_2,iVar5);
    iVar1 = 0;
    while( true ) {
      iVar3 = (*(code *)PTR_sk_num_006a6e2c)(uVar2);
      if (iVar3 <= iVar1) break;
      uVar4 = (*(code *)PTR_sk_value_006a6e24)(uVar2);
      (*(code *)PTR_BIO_puts_006a6f58)(param_1,&DAT_0063d1f8);
      (*(code *)PTR_GENERAL_NAME_print_006a73a8)(param_1,uVar4);
      (*(code *)PTR_BIO_puts_006a6f58)(param_1,"\n");
      iVar1 = iVar1 + 1;
    }
    iVar5 = iVar5 + 1;
  }
  return;
}

