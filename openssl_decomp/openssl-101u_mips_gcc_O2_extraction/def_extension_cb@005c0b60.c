
undefined4 def_extension_cb(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)TS_STATUS_INFO_new();
  if (((puVar1 == (undefined4 *)0x0) ||
      (iVar2 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(*puVar1,2), iVar2 == 0)) ||
     (iVar2 = (*(code *)PTR_ASN1_UTF8STRING_new_006a8d18)(), iVar2 == 0)) {
LAB_005c0bb0:
    iVar2 = 0;
LAB_005c0bb4:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x84,0x41,"ts_rsp_sign.c",0x177);
  }
  else {
    iVar3 = (*(code *)PTR_ASN1_STRING_set_006a7d1c)(iVar2,"Unsupported extension.",0x16);
    if (iVar3 == 0) goto LAB_005c0bb4;
    iVar3 = puVar1[1];
    if (iVar3 == 0) {
      iVar3 = (*(code *)PTR_sk_new_null_006a6fa4)();
      puVar1[1] = iVar3;
      if (iVar3 == 0) goto LAB_005c0bb4;
    }
    iVar3 = (*(code *)PTR_sk_push_006a6fa8)(iVar3,iVar2);
    if (iVar3 == 0) goto LAB_005c0bb4;
    iVar2 = TS_RESP_set_status_info(*(undefined4 *)(param_1 + 0x48),puVar1);
    if (iVar2 == 0) goto LAB_005c0bb0;
    iVar2 = 0;
  }
  TS_STATUS_INFO_free(puVar1);
  (*(code *)PTR_ASN1_UTF8STRING_free_006a8d1c)(iVar2);
  iVar2 = TS_RESP_get_status_info(*(undefined4 *)(param_1 + 0x48));
  iVar3 = *(int *)(iVar2 + 8);
  if (iVar3 == 0) {
    iVar3 = (*(code *)PTR_ASN1_BIT_STRING_new_006a8660)();
    *(int *)(iVar2 + 8) = iVar3;
    if (iVar3 == 0) goto LAB_005c0c34;
  }
  iVar2 = (*(code *)PTR_ASN1_BIT_STRING_set_bit_006a8de0)(iVar3,0x10,1);
  if (iVar2 != 0) {
    return 0;
  }
LAB_005c0c34:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x7c,0x41,"ts_rsp_sign.c",0x193);
  return 0;
}

