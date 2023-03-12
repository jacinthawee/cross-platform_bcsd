
/* WARNING: Removing unreachable block (ram,0x004209f4) */
/* WARNING: Removing unreachable block (ram,0x00420a38) */

undefined4
ecparam_print_var(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"static unsigned char %s_%d[] = {");
  if (*(int *)(param_2 + 4) == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"\n\t0x00");
  }
  else {
    iVar1 = (*(code *)PTR_BN_bn2bin_006a8300)(param_2,param_5);
    iVar2 = 0;
    while( true ) {
      puVar3 = (undefined *)(param_5 + iVar2);
      if (iVar1 + -1 <= iVar2) break;
      iVar4 = iVar2 % 0xc;
      iVar2 = iVar2 + 1;
      if (iVar4 == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)(param_1,&DAT_00634a58);
      }
      (*(code *)PTR_BIO_printf_006a7f38)(param_1,"0x%02X,",*puVar3);
    }
    if (iVar2 % 0xc == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(param_1,&DAT_00634a58);
    }
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"0x%02X",*puVar3);
  }
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,&DAT_00638e9c);
  return 1;
}

