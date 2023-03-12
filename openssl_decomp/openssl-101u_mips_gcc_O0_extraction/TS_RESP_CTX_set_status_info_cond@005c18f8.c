
undefined4 TS_RESP_CTX_set_status_info_cond(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar1 = (undefined4 *)TS_RESP_get_status_info(*(undefined4 *)(param_1 + 0x48));
  iVar2 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)(*puVar1);
  if (iVar2 != 0) {
    return 1;
  }
  puVar1 = (undefined4 *)TS_STATUS_INFO_new();
  if ((puVar1 == (undefined4 *)0x0) ||
     (iVar2 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(*puVar1,param_2), iVar2 == 0)) {
LAB_005c199c:
    iVar2 = 0;
  }
  else {
    if (param_3 == 0) {
LAB_005c1a74:
      iVar2 = TS_RESP_set_status_info(*(undefined4 *)(param_1 + 0x48),puVar1);
      if (iVar2 != 0) {
        iVar2 = 0;
        uVar3 = 1;
        goto LAB_005c19cc;
      }
      goto LAB_005c199c;
    }
    iVar2 = (*(code *)PTR_ASN1_UTF8STRING_new_006a8d18)();
    if (iVar2 == 0) goto LAB_005c199c;
    uVar3 = (*(code *)PTR_strlen_006a9a24)(param_3);
    iVar4 = (*(code *)PTR_ASN1_STRING_set_006a7d1c)(iVar2,param_3,uVar3);
    if (iVar4 != 0) {
      iVar4 = puVar1[1];
      if (iVar4 == 0) {
        iVar4 = (*(code *)PTR_sk_new_null_006a6fa4)();
        puVar1[1] = iVar4;
        if (iVar4 == 0) goto LAB_005c19a0;
      }
      iVar4 = (*(code *)PTR_sk_push_006a6fa8)(iVar4,iVar2);
      if (iVar4 != 0) goto LAB_005c1a74;
    }
  }
LAB_005c19a0:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x84,0x41,"ts_rsp_sign.c",0x177);
  uVar3 = 0;
LAB_005c19cc:
  TS_STATUS_INFO_free(puVar1);
  (*(code *)PTR_ASN1_UTF8STRING_free_006a8d1c)(iVar2);
  return uVar3;
}

