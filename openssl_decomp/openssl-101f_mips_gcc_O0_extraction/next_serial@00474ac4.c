
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_ASN1_INTEGER_new_006a8260)();
  if (iVar2 == 0) {
    iVar4 = 0;
    iVar3 = 0;
  }
  else {
    iVar3 = (*(code *)PTR_BIO_new_file_006a7fac)(param_1,"r");
    if (iVar3 == 0) {
      (*(code *)PTR_ERR_clear_error_006a7fe0)();
      iVar4 = 0;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,
                 "Warning: could not open file %s for reading, using serial number: 1\n",param_1);
      param_2 = (char *)0x1;
      iVar5 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(iVar2,1);
joined_r0x00474c94:
      iVar6 = iVar2;
      if (iVar5 != 0) goto LAB_00474b8c;
    }
    else {
      iVar4 = (*(code *)PTR_a2i_ASN1_INTEGER_006a8cd4)(iVar3,iVar2,auStack_41c,0x400);
      if (iVar4 == 0) {
        param_2 = "unable to load number from %s\n";
        iVar4 = 0;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)PTR_bio_err_006a7f3c,"unable to load number from %s\n",param_1);
      }
      else {
        param_2 = (char *)0x0;
        iVar4 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a8114)(iVar2,0);
        if (iVar4 != 0) {
          (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar2);
          param_2 = (char *)0x1;
          iVar2 = (*(code *)PTR_BN_add_word_006a81bc)(iVar4,1);
          if (iVar2 != 0) {
            param_2 = (char *)0x0;
            iVar2 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a81f4)(iVar4,0);
            iVar5 = iVar2;
            goto joined_r0x00474c94;
          }
          iVar2 = 0;
        }
      }
    }
  }
  iVar6 = 0;
  (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar2);
LAB_00474b8c:
  (*(code *)PTR_BIO_free_all_006a7f74)(iVar3);
  (*(code *)PTR_BN_free_006a811c)(iVar4);
  if (local_1c == *(int *)puVar1) {
    return iVar6;
  }
  iVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar4 = next_serial(param_2);
  if (iVar4 == 0) {
    (*(code *)PTR_TS_RESP_CTX_set_status_info_006a8f38)
              (iVar2,2,"Error during serial number generation.");
    (*(code *)PTR_TS_RESP_CTX_add_failure_info_006a8f3c)(iVar2,0x11);
    return 0;
  }
  iVar2 = (*(code *)PTR_BIO_new_file_006a7fac)(param_2,"w");
  if (((iVar2 == 0) || (iVar3 = (*(code *)PTR_i2a_ASN1_INTEGER_006a86e4)(iVar2,iVar4), iVar3 < 1))
     || (iVar3 = (*(code *)PTR_BIO_puts_006a8058)(iVar2,"\n"), iVar3 < 1)) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)PTR_bio_err_006a7f3c,"could not save serial number to %s\n",param_2);
  }
  (*(code *)PTR_BIO_free_all_006a7f74)(iVar2);
  return iVar4;
}

