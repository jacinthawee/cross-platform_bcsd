
int ts_resp_cb(int param_1,int *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)*param_2;
  if (param_1 == 1) {
    puVar1[2] = 0;
    return param_1;
  }
  if (param_1 == 3) {
    if ((ASN1_VALUE *)puVar1[2] != (ASN1_VALUE *)0x0) {
      ASN1_item_free((ASN1_VALUE *)puVar1[2],(ASN1_ITEM *)TS_TST_INFO_it);
      return 1;
    }
  }
  else if (param_1 == 5) {
    uVar2 = ASN1_INTEGER_get(*(ASN1_INTEGER **)*puVar1);
    iVar3 = puVar1[1];
    if (iVar3 == 0) {
      if (uVar2 < 2) {
        ERR_put_error(0x2f,0x96,0x82,"ts_asn1.c",0xcf);
        return 0;
      }
    }
    else {
      if (1 < uVar2) {
        ERR_put_error(0x2f,0x96,0x83,"ts_asn1.c",0xc3);
        return 0;
      }
      if ((ASN1_VALUE *)puVar1[2] != (ASN1_VALUE *)0x0) {
        ASN1_item_free((ASN1_VALUE *)puVar1[2],(ASN1_ITEM *)TS_TST_INFO_it);
        iVar3 = puVar1[1];
      }
      iVar3 = PKCS7_to_TS_TST_INFO(iVar3);
      puVar1[2] = iVar3;
      if (iVar3 == 0) {
        ERR_put_error(0x2f,0x96,0x81,"ts_asn1.c",0xcb);
        return 0;
      }
    }
  }
  return 1;
}

