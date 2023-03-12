
void print_name(undefined4 param_1,int param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    (*(code *)PTR_BIO_puts_006a6f58)();
  }
  if ((param_4 & 0xf0000) == 0x40000) {
    (*(code *)PTR_BIO_puts_006a6f58)(param_1,"\n");
    uVar1 = 4;
  }
  else {
    uVar1 = 0;
    if (param_4 == 0) {
      uVar1 = (*(code *)PTR_X509_NAME_oneline_006a7010)(param_3,0,0);
      (*(code *)PTR_BIO_puts_006a6f58)(param_1,uVar1);
      (*(code *)PTR_BIO_puts_006a6f58)(param_1,"\n");
                    /* WARNING: Could not recover jumptable at 0x0045bdd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CRYPTO_free_006a6e88)(uVar1);
      return;
    }
  }
  (*(code *)PTR_X509_NAME_print_ex_006a7bc4)(param_1,param_3,uVar1,param_4);
                    /* WARNING: Could not recover jumptable at 0x0045bd54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_BIO_puts_006a6f58)(param_1,"\n");
  return;
}

