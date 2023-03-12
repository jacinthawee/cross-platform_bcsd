
undefined4 ts_resp_cb(int param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  param_2 = (undefined4 *)*param_2;
  if (param_1 == 1) {
    param_2[2] = 0;
    return 1;
  }
  if (param_1 == 3) {
    if (param_2[2] != 0) {
      (*(code *)PTR_ASN1_item_free_006a977c)(param_2[2],TS_TST_INFO_it);
      return 1;
    }
  }
  else if (param_1 == 5) {
    uVar1 = (*(code *)PTR_ASN1_INTEGER_get_006a831c)(*(undefined4 *)*param_2);
    iVar3 = param_2[1];
    if (iVar3 == 0) {
      if (1 < uVar1) {
        return 1;
      }
      uVar4 = 0x82;
      uVar2 = 0xc9;
    }
    else if (1 < uVar1) {
      uVar4 = 0x83;
      uVar2 = 0xbe;
    }
    else {
      if (param_2[2] != 0) {
        (*(code *)PTR_ASN1_item_free_006a977c)(param_2[2],TS_TST_INFO_it);
        iVar3 = param_2[1];
      }
      iVar3 = PKCS7_to_TS_TST_INFO(iVar3);
      param_2[2] = iVar3;
      if (iVar3 != 0) {
        return 1;
      }
      uVar4 = 0x81;
      uVar2 = 0xc5;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x96,uVar4,"ts_asn1.c",uVar2);
    return 0;
  }
  return 1;
}

