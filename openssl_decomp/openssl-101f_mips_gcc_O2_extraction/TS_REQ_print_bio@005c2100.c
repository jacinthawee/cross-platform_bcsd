
undefined4 TS_REQ_print_bio(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  
  if (param_2 != 0) {
    uVar1 = TS_REQ_get_version(param_2);
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Version: %d\n",uVar1);
    uVar1 = TS_REQ_get_msg_imprint(param_2);
    TS_MSG_IMPRINT_print_bio(param_1,uVar1);
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Policy OID: ");
    iVar2 = TS_REQ_get_policy_id(param_2);
    if (iVar2 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(param_1,"unspecified\n");
    }
    else {
      TS_OBJ_print_bio(param_1,iVar2);
    }
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Nonce: ");
    iVar2 = TS_REQ_get_nonce(param_2);
    if (iVar2 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(param_1,"unspecified");
    }
    else {
      TS_ASN1_INTEGER_print_bio(param_1,iVar2);
    }
    (*(code *)PTR_BIO_write_006a7f14)(param_1,"\n",1);
    iVar2 = TS_REQ_get_cert_req(param_2);
    if (iVar2 == 0) {
      puVar3 = &DAT_0064033c;
    }
    else {
      puVar3 = &DAT_00640338;
    }
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Certificate required: %s\n",puVar3);
    uVar1 = TS_REQ_get_exts(param_2);
    TS_ext_print_bio(param_1,uVar1);
    return 1;
  }
  return 0;
}

