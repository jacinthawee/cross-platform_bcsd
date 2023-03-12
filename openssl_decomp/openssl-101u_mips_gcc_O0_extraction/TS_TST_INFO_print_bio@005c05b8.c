
undefined4 TS_TST_INFO_print_bio(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  
  if (param_2 != 0) {
    uVar1 = TS_TST_INFO_get_version(param_2);
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Version: %d\n",uVar1);
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Policy OID: ");
    uVar1 = TS_TST_INFO_get_policy_id(param_2);
    TS_OBJ_print_bio(param_1,uVar1);
    uVar1 = TS_TST_INFO_get_msg_imprint(param_2);
    TS_MSG_IMPRINT_print_bio(param_1,uVar1);
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Serial number: ");
    iVar2 = TS_TST_INFO_get_serial(param_2);
    if (iVar2 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(param_1,"unspecified");
    }
    else {
      TS_ASN1_INTEGER_print_bio(param_1,iVar2);
    }
    (*(code *)PTR_BIO_write_006a6e14)(param_1,"\n",1);
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Time stamp: ");
    uVar1 = TS_TST_INFO_get_time(param_2);
    (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a7e20)(param_1,uVar1);
    (*(code *)PTR_BIO_write_006a6e14)(param_1,"\n",1);
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Accuracy: ");
    iVar2 = TS_TST_INFO_get_accuracy(param_2);
    if (iVar2 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(param_1,"unspecified");
    }
    else {
      iVar3 = TS_ACCURACY_get_seconds(iVar2);
      iVar4 = TS_ACCURACY_get_millis(iVar2);
      iVar2 = TS_ACCURACY_get_micros(iVar2);
      if (iVar3 == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)(param_1,"unspecified");
      }
      else {
        TS_ASN1_INTEGER_print_bio(param_1,iVar3);
      }
      (*(code *)PTR_BIO_printf_006a6e38)(param_1," seconds, ");
      if (iVar4 == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)(param_1,"unspecified");
      }
      else {
        TS_ASN1_INTEGER_print_bio(param_1,iVar4);
      }
      (*(code *)PTR_BIO_printf_006a6e38)(param_1," millis, ");
      if (iVar2 == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)(param_1,"unspecified");
      }
      else {
        TS_ASN1_INTEGER_print_bio(param_1,iVar2);
      }
      (*(code *)PTR_BIO_printf_006a6e38)(param_1," micros");
    }
    (*(code *)PTR_BIO_write_006a6e14)(param_1,"\n",1);
    iVar2 = TS_TST_INFO_get_ordering(param_2);
    if (iVar2 == 0) {
      puVar5 = &DAT_0063fda0;
    }
    else {
      puVar5 = &DAT_0063fd9c;
    }
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Ordering: %s\n",puVar5);
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Nonce: ");
    iVar2 = TS_TST_INFO_get_nonce(param_2);
    if (iVar2 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(param_1,"unspecified");
    }
    else {
      TS_ASN1_INTEGER_print_bio(param_1,iVar2);
    }
    (*(code *)PTR_BIO_write_006a6e14)(param_1,"\n",1);
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"TSA: ");
    iVar2 = TS_TST_INFO_get_tsa(param_2);
    if (iVar2 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(param_1,"unspecified");
    }
    else {
      iVar2 = (*(code *)PTR_i2v_GENERAL_NAME_006a907c)(0,iVar2,0);
      if (iVar2 != 0) {
        (*(code *)PTR_X509V3_EXT_val_prn_006a9478)(param_1,iVar2,0,0);
      }
      (*(code *)PTR_sk_pop_free_006a7058)(iVar2,PTR_X509V3_conf_free_006a7b4c);
    }
    (*(code *)PTR_BIO_write_006a6e14)(param_1,"\n",1);
    uVar1 = TS_TST_INFO_get_exts(param_2);
    TS_ext_print_bio(param_1,uVar1);
    return 1;
  }
  return 0;
}

