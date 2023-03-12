
int cb(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  iVar1 = (*(code *)PTR_X509_STORE_CTX_get_error_006a729c)(param_2);
  iVar2 = (*(code *)PTR_X509_STORE_CTX_get_current_cert_006a744c)(param_2);
  if (param_1 == 0) {
    if (iVar2 != 0) {
      uVar4 = *(undefined4 *)PTR_stdout_006a99c8;
      uVar3 = (*(code *)PTR_X509_get_subject_name_006a6f00)(iVar2);
      (*(code *)PTR_X509_NAME_print_ex_fp_006a7450)(uVar4,uVar3,0,0x82031f);
      (*(code *)PTR_putchar_006a99ec)(10);
    }
    iVar2 = (*(code *)PTR_X509_STORE_CTX_get0_parent_ctx_006a7454)(param_2);
    if (iVar2 == 0) {
      pcVar5 = "";
    }
    else {
      pcVar5 = "[CRL path]";
    }
    uVar3 = (*(code *)PTR_X509_STORE_CTX_get_error_depth_006a7458)(param_2);
    uVar4 = (*(code *)PTR_X509_verify_cert_error_string_006a72a0)(iVar1);
    (*(code *)PTR___printf_chk_006a99c4)
              (1,"%serror %d at %d depth lookup:%s\n",pcVar5,iVar1,uVar3,uVar4);
    switch(iVar1) {
    case 10:
    case 0xb:
    case 0xc:
    case 0x12:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x22:
    case 0x25:
      return 1;
    case 0x2b:
      (*(code *)PTR_policies_print_006a72c8)(0,param_2);
      return 1;
    }
  }
  else {
    if ((iVar1 == 0) && (param_1 == 2)) {
      (*(code *)PTR_policies_print_006a72c8)(0,param_2);
    }
    if (v_verbose == 0) {
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
      return param_1;
    }
  }
  return param_1;
}

