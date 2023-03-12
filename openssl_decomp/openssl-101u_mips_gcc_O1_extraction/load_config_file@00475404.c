
char * load_config_file(int param_1,char *param_2)

{
  undefined *puVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 *unaff_s3;
  undefined auStack_454 [1024];
  int iStack_54;
  char *pcStack_4c;
  int iStack_48;
  undefined *puStack_44;
  undefined4 *puStack_40;
  code *pcStack_3c;
  undefined *local_28;
  int local_20;
  int local_1c;
  
  puStack_44 = PTR___stack_chk_guard_006a9ae8;
  local_20 = -1;
  local_28 = &_gp;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (((param_1 == 0) && (param_1 = (*(code *)PTR_getenv_006a9a60)("OPENSSL_CONF"), param_1 == 0))
     && (param_1 = (**(code **)(local_28 + -0x5380))("SSLEAY_CONF"), param_1 == 0)) {
    pcStack_4c = (char *)0x0;
    goto LAB_00475528;
  }
  pcStack_4c = (char *)(**(code **)(local_28 + -0x7f88))(0);
  if ((pcStack_4c == (char *)0x0) ||
     (iVar2 = (**(code **)(local_28 + -0x7f84))(pcStack_4c,param_1,&local_20), iVar2 < 1)) {
    unaff_s3 = *(undefined4 **)(local_28 + -0x7fa4);
    if (local_20 < 1) {
      param_2 = "error loading the config file \'%s\'\n";
      (**(code **)(local_28 + -0x7fa8))(*unaff_s3,"error loading the config file \'%s\'\n",param_1);
      if (pcStack_4c != (char *)0x0) goto LAB_00475480;
      pcStack_4c = (char *)0x0;
    }
    else {
      param_2 = "error on line %ld of config file \'%s\'\n";
      (**(code **)(local_28 + -0x7fa8))
                (*unaff_s3,"error on line %ld of config file \'%s\'\n",local_20,param_1);
      if (pcStack_4c != (char *)0x0) goto LAB_00475480;
      pcStack_4c = (char *)0x0;
    }
  }
  else {
    unaff_s3 = *(undefined4 **)(local_28 + -0x7fa4);
LAB_00475480:
    (**(code **)(local_28 + -0x7fa8))(*unaff_s3,"Using configuration from %s\n",param_1);
    iVar2 = (**(code **)(local_28 + -0x7f38))(pcStack_4c,0,"oid_file");
    if (iVar2 == 0) {
      (**(code **)(local_28 + -0x7f00))();
    }
    else {
      param_1 = (**(code **)(local_28 + -0x7f34))(iVar2,"r");
      if (param_1 == 0) {
        (**(code **)(local_28 + -0x7fa0))(**(undefined4 **)(local_28 + -0x7fa4));
      }
      else {
        (**(code **)(local_28 + -0x7f30))(param_1);
        (**(code **)(local_28 + -0x7f6c))(param_1);
      }
    }
    param_2 = pcStack_4c;
    iVar2 = add_oid_section(*unaff_s3,pcStack_4c);
    if (iVar2 == 0) {
      (**(code **)(local_28 + -0x7fa0))(**(undefined4 **)(local_28 + -0x7fa4));
    }
  }
LAB_00475528:
  if (local_1c == *(int *)puStack_44) {
    return pcStack_4c;
  }
  pcStack_3c = next_serial;
  iVar2 = local_1c;
  (**(code **)(local_28 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_54 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_48 = param_1;
  puStack_40 = unaff_s3;
  pcVar3 = (char *)(*(code *)PTR_ASN1_INTEGER_new_006a7160)();
  if (pcVar3 == (char *)0x0) {
    iVar5 = 0;
    iVar4 = 0;
  }
  else {
    iVar4 = (*(code *)PTR_BIO_new_file_006a6eac)(iVar2,"r");
    if (iVar4 == 0) {
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
      iVar5 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,
                 "Warning: could not open file %s for reading, using serial number: 1\n",iVar2);
      param_2 = (char *)0x1;
      pcVar6 = (char *)(*(code *)PTR_ASN1_INTEGER_set_006a7164)(pcVar3,1);
joined_r0x004757f4:
      pcVar7 = pcVar3;
      if (pcVar6 != (char *)0x0) goto LAB_004756ec;
    }
    else {
      iVar5 = (*(code *)PTR_a2i_ASN1_INTEGER_006a7be8)(iVar4,pcVar3,auStack_454,0x400);
      if (iVar5 == 0) {
        param_2 = "unable to load number from %s\n";
        iVar5 = 0;
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)PTR_bio_err_006a6e3c,"unable to load number from %s\n",iVar2);
      }
      else {
        param_2 = (char *)0x0;
        iVar5 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a7014)(pcVar3,0);
        if (iVar5 != 0) {
          (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(pcVar3);
          param_2 = (char *)0x1;
          iVar2 = (*(code *)PTR_BN_add_word_006a70bc)(iVar5,1);
          if (iVar2 != 0) {
            param_2 = (char *)0x0;
            pcVar3 = (char *)(*(code *)PTR_BN_to_ASN1_INTEGER_006a70f4)(iVar5,0);
            pcVar6 = pcVar3;
            goto joined_r0x004757f4;
          }
          pcVar3 = (char *)0x0;
        }
      }
    }
  }
  pcVar7 = (char *)0x0;
  (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(pcVar3);
LAB_004756ec:
  (*(code *)PTR_BIO_free_all_006a6e74)(iVar4);
  (*(code *)PTR_BN_free_006a701c)(iVar5);
  if (iStack_54 == *(int *)puVar1) {
    return pcVar7;
  }
  iVar2 = iStack_54;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  pcVar3 = (char *)next_serial(param_2);
  if (pcVar3 == (char *)0x0) {
    (*(code *)PTR_TS_RESP_CTX_set_status_info_006a7e48)
              (iVar2,2,"Error during serial number generation.");
    (*(code *)PTR_TS_RESP_CTX_add_failure_info_006a7e4c)(iVar2,0x11);
    return (char *)0x0;
  }
  iVar2 = (*(code *)PTR_BIO_new_file_006a6eac)(param_2,"w");
  if (((iVar2 == 0) || (iVar5 = (*(code *)PTR_i2a_ASN1_INTEGER_006a75f0)(iVar2,pcVar3), iVar5 < 1))
     || (iVar5 = (*(code *)PTR_BIO_puts_006a6f58)(iVar2,"\n"), iVar5 < 1)) {
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,"could not save serial number to %s\n",param_2);
  }
  (*(code *)PTR_BIO_free_all_006a6e74)(iVar2);
  return pcVar3;
}

