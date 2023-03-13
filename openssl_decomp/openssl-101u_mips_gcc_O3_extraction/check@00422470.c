
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
  
  puVar1 = PTR_bio_err_006a6e3c;
  iVar3 = (*(code *)PTR_load_cert_006a7078)
                    (*(undefined4 *)PTR_bio_err_006a6e3c,param_2,3,0,param_6,"certificate file");
  puVar2 = PTR_stdout_006a99c8;
  if (iVar3 == 0) {
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar1);
    return 0;
  }
  if (param_2 == (char *)0x0) {
    param_2 = "stdin";
  }
  (*(code *)PTR___fprintf_chk_006a9980)(*(undefined4 *)PTR_stdout_006a99c8,1,&DAT_00631e78,param_2);
  iVar4 = (*(code *)PTR_X509_STORE_CTX_new_006a745c)();
  if (iVar4 == 0) {
LAB_00422614:
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar1);
  }
  else {
    (*(code *)PTR_X509_STORE_set_flags_006a7460)(param_1,0);
    iVar5 = (*(code *)PTR_X509_STORE_CTX_init_006a7270)(iVar4,param_1,iVar3,param_3);
    if (iVar5 == 0) goto LAB_00422614;
    if (param_4 != 0) {
      (*(code *)PTR_X509_STORE_CTX_trusted_stack_006a7464)(iVar4,param_4);
    }
    if (param_5 != 0) {
      (*(code *)PTR_X509_STORE_CTX_set0_crls_006a7468)(iVar4,param_5);
    }
    iVar5 = (*(code *)PTR_X509_verify_cert_006a728c)(iVar4);
    (*(code *)PTR_X509_STORE_CTX_free_006a746c)(iVar4);
    if (0 < iVar5) {
      uVar6 = 1;
      (*(code *)PTR_fwrite_006a9a74)("OK\n",1,3,*(undefined4 *)puVar2);
      goto LAB_004225dc;
    }
  }
  uVar6 = 0;
  (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar1);
LAB_004225dc:
  (*(code *)PTR_X509_free_006a6e90)(iVar3);
  return uVar6;
}

