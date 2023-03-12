
undefined4 TS_REQ_print_bio(BIO *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  
  uVar1 = 0;
  if (param_2 != 0) {
    uVar1 = TS_REQ_get_version(param_2);
    BIO_printf(param_1,"Version: %d\n",uVar1);
    uVar1 = TS_REQ_get_msg_imprint(param_2);
    TS_MSG_IMPRINT_print_bio(param_1,uVar1);
    BIO_printf(param_1,"Policy OID: ");
    iVar2 = TS_REQ_get_policy_id(param_2);
    if (iVar2 == 0) {
      BIO_printf(param_1,"unspecified\n");
    }
    else {
      TS_OBJ_print_bio(param_1,iVar2);
    }
    BIO_printf(param_1,"Nonce: ");
    iVar2 = TS_REQ_get_nonce(param_2);
    if (iVar2 == 0) {
      BIO_printf(param_1,"unspecified");
    }
    else {
      TS_ASN1_INTEGER_print_bio(param_1,iVar2);
    }
    BIO_write(param_1,&DAT_081f11d3,1);
    iVar2 = TS_REQ_get_cert_req(param_2);
    puVar3 = &DAT_081f75bd;
    if (iVar2 == 0) {
      puVar3 = &DAT_081f75c1;
    }
    BIO_printf(param_1,"Certificate required: %s\n",puVar3);
    uVar1 = TS_REQ_get_exts(param_2);
    TS_ext_print_bio(param_1,uVar1);
    uVar1 = 1;
  }
  return uVar1;
}

