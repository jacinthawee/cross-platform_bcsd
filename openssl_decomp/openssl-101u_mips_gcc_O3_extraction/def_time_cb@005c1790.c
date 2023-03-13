
undefined4 def_time_cb(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  uVar7 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  puVar8 = param_3;
  iVar2 = (*(code *)PTR_gettimeofday_006a9acc)(&local_24,0);
  if (iVar2 == 0) {
    uVar3 = 1;
    *param_3 = local_24;
    *param_4 = local_20;
  }
  else {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x6f,0x7a,"ts_rsp_sign.c",0x78);
    TS_RESP_CTX_set_status_info(param_1,2,"Time is not available.");
    iVar2 = TS_RESP_get_status_info(*(undefined4 *)(param_1 + 0x48));
    iVar5 = *(int *)(iVar2 + 8);
    if (iVar5 == 0) {
      iVar5 = (*(code *)PTR_ASN1_BIT_STRING_new_006a8660)();
      *(int *)(iVar2 + 8) = iVar5;
      if (iVar5 != 0) goto LAB_005c187c;
    }
    else {
LAB_005c187c:
      puVar8 = (undefined4 *)0x1;
      uVar7 = 0xe;
      iVar2 = (*(code *)PTR_ASN1_BIT_STRING_set_bit_006a8de0)(iVar5,0xe);
      if (iVar2 != 0) {
        uVar3 = 0;
        goto LAB_005c17fc;
      }
    }
    puVar8 = (undefined4 *)&DAT_00000041;
    uVar7 = 0x7c;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x7c,0x41,"ts_rsp_sign.c",0x193);
    uVar3 = 0;
  }
LAB_005c17fc:
  if (local_1c == *(int *)puVar1) {
    return uVar3;
  }
  iVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar4 = (undefined4 *)TS_RESP_get_status_info(*(undefined4 *)(iVar2 + 0x48));
  iVar5 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)(*puVar4);
  if (iVar5 != 0) {
    return 1;
  }
  puVar4 = (undefined4 *)TS_STATUS_INFO_new();
  if ((puVar4 == (undefined4 *)0x0) ||
     (iVar5 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(*puVar4,uVar7), iVar5 == 0)) {
LAB_005c199c:
    iVar5 = 0;
  }
  else {
    if (puVar8 == (undefined4 *)0x0) {
LAB_005c1a74:
      iVar2 = TS_RESP_set_status_info(*(undefined4 *)(iVar2 + 0x48),puVar4);
      if (iVar2 != 0) {
        iVar5 = 0;
        uVar7 = 1;
        goto LAB_005c19cc;
      }
      goto LAB_005c199c;
    }
    iVar5 = (*(code *)PTR_ASN1_UTF8STRING_new_006a8d18)();
    if (iVar5 == 0) goto LAB_005c199c;
    uVar7 = (*(code *)PTR_strlen_006a9a24)(puVar8);
    iVar6 = (*(code *)PTR_ASN1_STRING_set_006a7d1c)(iVar5,puVar8,uVar7);
    if (iVar6 != 0) {
      iVar6 = puVar4[1];
      if (iVar6 == 0) {
        iVar6 = (*(code *)PTR_sk_new_null_006a6fa4)();
        puVar4[1] = iVar6;
        if (iVar6 == 0) goto LAB_005c19a0;
      }
      iVar6 = (*(code *)PTR_sk_push_006a6fa8)(iVar6,iVar5);
      if (iVar6 != 0) goto LAB_005c1a74;
    }
  }
LAB_005c19a0:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x84,0x41,"ts_rsp_sign.c",0x177);
  uVar7 = 0;
LAB_005c19cc:
  TS_STATUS_INFO_free(puVar4);
  (*(code *)PTR_ASN1_UTF8STRING_free_006a8d1c)(iVar5);
  return uVar7;
}

