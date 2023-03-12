
int next_serial(undefined4 param_1,char *param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined auStack_41c [1024];
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_ASN1_INTEGER_new_006a7160)();
  if (iVar2 == 0) {
    iVar4 = 0;
    iVar3 = 0;
  }
  else {
    iVar3 = (*(code *)PTR_BIO_new_file_006a6eac)(param_1,"r");
    if (iVar3 == 0) {
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
      iVar4 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,
                 "Warning: could not open file %s for reading, using serial number: 1\n",param_1);
      param_2 = (char *)0x1;
      iVar5 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(iVar2,1);
joined_r0x004757f4:
      iVar6 = iVar2;
      if (iVar5 != 0) goto LAB_004756ec;
    }
    else {
      iVar4 = (*(code *)PTR_a2i_ASN1_INTEGER_006a7be8)(iVar3,iVar2,auStack_41c,0x400);
      if (iVar4 == 0) {
        param_2 = "unable to load number from %s\n";
        iVar4 = 0;
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)PTR_bio_err_006a6e3c,"unable to load number from %s\n",param_1);
      }
      else {
        param_2 = (char *)0x0;
        iVar4 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a7014)(iVar2,0);
        if (iVar4 != 0) {
          (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar2);
          param_2 = (char *)0x1;
          iVar2 = (*(code *)PTR_BN_add_word_006a70bc)(iVar4,1);
          if (iVar2 != 0) {
            param_2 = (char *)0x0;
            iVar2 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a70f4)(iVar4,0);
            iVar5 = iVar2;
            goto joined_r0x004757f4;
          }
          iVar2 = 0;
        }
      }
    }
  }
  iVar6 = 0;
  (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar2);
LAB_004756ec:
  (*(code *)PTR_BIO_free_all_006a6e74)(iVar3);
  (*(code *)PTR_BN_free_006a701c)(iVar4);
  if (local_1c == *(int *)puVar1) {
    return iVar6;
  }
  iVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar4 = next_serial(param_2);
  if (iVar4 == 0) {
    (*(code *)PTR_TS_RESP_CTX_set_status_info_006a7e48)
              (iVar2,2,"Error during serial number generation.");
    (*(code *)PTR_TS_RESP_CTX_add_failure_info_006a7e4c)(iVar2,0x11);
    return 0;
  }
  iVar2 = (*(code *)PTR_BIO_new_file_006a6eac)(param_2,"w");
  if (((iVar2 == 0) || (iVar3 = (*(code *)PTR_i2a_ASN1_INTEGER_006a75f0)(iVar2,iVar4), iVar3 < 1))
     || (iVar3 = (*(code *)PTR_BIO_puts_006a6f58)(iVar2,"\n"), iVar3 < 1)) {
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,"could not save serial number to %s\n",param_2);
  }
  (*(code *)PTR_BIO_free_all_006a6e74)(iVar2);
  return iVar4;
}

