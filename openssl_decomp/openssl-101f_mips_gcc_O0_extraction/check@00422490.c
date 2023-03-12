
undefined4
check(undefined4 param_1,char *param_2,undefined4 param_3,int param_4,int param_5,undefined4 param_6
     )

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  puVar1 = PTR_bio_err_006a7f3c;
  iVar3 = (*(code *)PTR_load_cert_006a8178)
                    (*(undefined4 *)PTR_bio_err_006a7f3c,param_2,3,0,param_6,"certificate file");
  puVar2 = PTR_stdout_006aaad4;
  if (iVar3 == 0) {
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar1);
    return 0;
  }
  if (param_2 == (char *)0x0) {
    param_2 = "stdin";
  }
  (*(code *)PTR___fprintf_chk_006aaa8c)(*(undefined4 *)PTR_stdout_006aaad4,1,&DAT_00632848,param_2);
  iVar4 = (*(code *)PTR_X509_STORE_CTX_new_006a855c)();
  if (iVar4 == 0) {
LAB_00422634:
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar1);
  }
  else {
    (*(code *)PTR_X509_STORE_set_flags_006a8560)(param_1,0);
    iVar5 = (*(code *)PTR_X509_STORE_CTX_init_006a8304)(iVar4,param_1,iVar3,param_3);
    if (iVar5 == 0) goto LAB_00422634;
    if (param_4 != 0) {
      (*(code *)PTR_X509_STORE_CTX_trusted_stack_006a8564)(iVar4,param_4);
    }
    if (param_5 != 0) {
      (*(code *)PTR_X509_STORE_CTX_set0_crls_006a8568)(iVar4,param_5);
    }
    iVar5 = (*(code *)PTR_X509_verify_cert_006a8308)(iVar4);
    (*(code *)PTR_X509_STORE_CTX_free_006a856c)(iVar4);
    if (0 < iVar5) {
      uVar6 = 1;
      (*(code *)PTR_fwrite_006aab7c)("OK\n",1,3,*(undefined4 *)puVar2);
      goto LAB_004225fc;
    }
  }
  uVar6 = 0;
  (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar1);
LAB_004225fc:
  (*(code *)PTR_X509_free_006a7f90)(iVar3);
  return uVar6;
}

