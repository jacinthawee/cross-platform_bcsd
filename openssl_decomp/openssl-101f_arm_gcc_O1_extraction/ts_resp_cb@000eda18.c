
undefined4 ts_resp_cb(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  
  param_2 = (undefined4 *)*param_2;
  if (param_1 == 1) {
    param_4 = 0;
  }
  if (param_1 == 1) {
    param_2[2] = param_4;
    return 1;
  }
  if (param_1 == 3) {
    if ((ASN1_VALUE *)param_2[2] != (ASN1_VALUE *)0x0) {
      ASN1_item_free((ASN1_VALUE *)param_2[2],(ASN1_ITEM *)PTR_TS_TST_INFO_it_000edac0);
      return 1;
    }
  }
  else if (param_1 == 5) {
    uVar1 = ASN1_INTEGER_get(*(ASN1_INTEGER **)*param_2);
    iVar2 = param_2[1];
    if (iVar2 == 0) {
      if (1 < uVar1) {
        return 1;
      }
      ERR_put_error(0x2f,0x96,0x82,"ts_asn1.c",0xc9);
    }
    else if (uVar1 < 2) {
      if ((ASN1_VALUE *)param_2[2] != (ASN1_VALUE *)0x0) {
        ASN1_item_free((ASN1_VALUE *)param_2[2],(ASN1_ITEM *)PTR_TS_TST_INFO_it_000edac0);
        iVar2 = param_2[1];
      }
      iVar2 = PKCS7_to_TS_TST_INFO(iVar2);
      param_2[2] = iVar2;
      if (iVar2 != 0) {
        return 1;
      }
      ERR_put_error(0x2f,0x96,0x81,"ts_asn1.c",0xc5);
    }
    else {
      ERR_put_error(0x2f,0x96,0x83,"ts_asn1.c",0xbe);
    }
    return 0;
  }
  return 1;
}

