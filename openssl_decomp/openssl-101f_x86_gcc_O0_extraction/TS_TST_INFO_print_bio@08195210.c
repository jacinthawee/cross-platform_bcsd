
undefined4 TS_TST_INFO_print_bio(BIO *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  ASN1_GENERALIZEDTIME *a;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  GENERAL_NAME *gen;
  _STACK *st;
  
  uVar1 = 0;
  if (param_2 != 0) {
    uVar1 = TS_TST_INFO_get_version(param_2);
    BIO_printf(param_1,"Version: %d\n",uVar1);
    BIO_printf(param_1,"Policy OID: ");
    uVar1 = TS_TST_INFO_get_policy_id(param_2);
    TS_OBJ_print_bio(param_1,uVar1);
    uVar1 = TS_TST_INFO_get_msg_imprint(param_2);
    TS_MSG_IMPRINT_print_bio(param_1,uVar1);
    BIO_printf(param_1,"Serial number: ");
    iVar2 = TS_TST_INFO_get_serial(param_2);
    if (iVar2 == 0) {
      BIO_printf(param_1,"unspecified");
    }
    else {
      TS_ASN1_INTEGER_print_bio(param_1,iVar2);
    }
    BIO_write(param_1,&DAT_081f11d3,1);
    BIO_printf(param_1,"Time stamp: ");
    a = (ASN1_GENERALIZEDTIME *)TS_TST_INFO_get_time(param_2);
    ASN1_GENERALIZEDTIME_print(param_1,a);
    BIO_write(param_1,&DAT_081f11d3,1);
    BIO_printf(param_1,"Accuracy: ");
    iVar2 = TS_TST_INFO_get_accuracy(param_2);
    if (iVar2 == 0) {
      BIO_printf(param_1,"unspecified");
    }
    else {
      iVar3 = TS_ACCURACY_get_seconds(iVar2);
      iVar4 = TS_ACCURACY_get_millis(iVar2);
      iVar2 = TS_ACCURACY_get_micros(iVar2);
      if (iVar3 == 0) {
        BIO_printf(param_1,"unspecified");
      }
      else {
        TS_ASN1_INTEGER_print_bio(param_1,iVar3);
      }
      BIO_printf(param_1," seconds, ");
      if (iVar4 == 0) {
        BIO_printf(param_1,"unspecified");
      }
      else {
        TS_ASN1_INTEGER_print_bio(param_1,iVar4);
      }
      BIO_printf(param_1," millis, ");
      if (iVar2 == 0) {
        BIO_printf(param_1,"unspecified");
      }
      else {
        TS_ASN1_INTEGER_print_bio(param_1,iVar2);
      }
      BIO_printf(param_1," micros");
    }
    BIO_write(param_1,&DAT_081f11d3,1);
    iVar2 = TS_TST_INFO_get_ordering(param_2);
    puVar5 = &UNK_081f75bd;
    if (iVar2 == 0) {
      puVar5 = &UNK_081f75c1;
    }
    BIO_printf(param_1,"Ordering: %s\n",puVar5);
    BIO_printf(param_1,"Nonce: ");
    iVar2 = TS_TST_INFO_get_nonce(param_2);
    if (iVar2 == 0) {
      BIO_printf(param_1,"unspecified",puVar5);
    }
    else {
      TS_ASN1_INTEGER_print_bio(param_1,iVar2);
    }
    BIO_write(param_1,&DAT_081f11d3,1);
    BIO_printf(param_1,"TSA: ");
    gen = (GENERAL_NAME *)TS_TST_INFO_get_tsa(param_2);
    if (gen == (GENERAL_NAME *)0x0) {
      BIO_printf(param_1,"unspecified");
    }
    else {
      st = (_STACK *)i2v_GENERAL_NAME((X509V3_EXT_METHOD *)0x0,gen,(stack_st_CONF_VALUE *)0x0);
      if (st != (_STACK *)0x0) {
        X509V3_EXT_val_prn(param_1,(stack_st_CONF_VALUE *)st,0,0);
      }
      sk_pop_free(st,X509V3_conf_free);
    }
    BIO_write(param_1,&DAT_081f11d3,1);
    uVar1 = TS_TST_INFO_get_exts(param_2);
    TS_ext_print_bio(param_1,uVar1);
    uVar1 = 1;
  }
  return uVar1;
}

