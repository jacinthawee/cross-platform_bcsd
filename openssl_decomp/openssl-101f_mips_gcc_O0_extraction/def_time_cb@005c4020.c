
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  uVar7 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar8 = param_3;
  iVar2 = (*(code *)PTR_gettimeofday_006aabd4)(&local_24,0);
  if (iVar2 == 0) {
    uVar3 = 1;
    *param_3 = local_24;
    *param_4 = local_20;
  }
  else {
    (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x6f,0x7a,"ts_rsp_sign.c",0x75);
    TS_RESP_CTX_set_status_info(param_1,2,"Time is not available.");
    iVar2 = TS_RESP_get_status_info(*(undefined4 *)(param_1 + 0x48));
    iVar5 = *(int *)(iVar2 + 8);
    if (iVar5 == 0) {
      iVar5 = (*(code *)PTR_ASN1_BIT_STRING_new_006a9784)();
      *(int *)(iVar2 + 8) = iVar5;
      if (iVar5 != 0) goto LAB_005c410c;
    }
    else {
LAB_005c410c:
      puVar8 = (undefined4 *)0x1;
      uVar7 = 0xe;
      iVar2 = (*(code *)PTR_ASN1_BIT_STRING_set_bit_006a9ee8)(iVar5,0xe);
      if (iVar2 != 0) {
        uVar3 = 0;
        goto LAB_005c408c;
      }
    }
    puVar8 = (undefined4 *)&DAT_00000041;
    uVar7 = 0x7c;
    (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x7c,0x41,"ts_rsp_sign.c",0x18b);
    uVar3 = 0;
  }
LAB_005c408c:
  if (local_1c == *(int *)puVar1) {
    return uVar3;
  }
  iVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar4 = (undefined4 *)TS_RESP_get_status_info(*(undefined4 *)(iVar2 + 0x48));
  iVar5 = (*(code *)PTR_ASN1_INTEGER_get_006a831c)(*puVar4);
  if (iVar5 != 0) {
    return 1;
  }
  puVar4 = (undefined4 *)TS_STATUS_INFO_new();
  if ((puVar4 == (undefined4 *)0x0) ||
     (iVar5 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(*puVar4,uVar7), iVar5 == 0)) {
LAB_005c422c:
    iVar5 = 0;
  }
  else {
    if (puVar8 == (undefined4 *)0x0) {
LAB_005c4304:
      iVar2 = TS_RESP_set_status_info(*(undefined4 *)(iVar2 + 0x48),puVar4);
      if (iVar2 != 0) {
        iVar5 = 0;
        uVar7 = 1;
        goto LAB_005c425c;
      }
      goto LAB_005c422c;
    }
    iVar5 = (*(code *)PTR_ASN1_UTF8STRING_new_006a9e38)();
    if (iVar5 == 0) goto LAB_005c422c;
    uVar7 = (*(code *)PTR_strlen_006aab30)(puVar8);
    iVar6 = (*(code *)PTR_ASN1_STRING_set_006a8e0c)(iVar5,puVar8,uVar7);
    if (iVar6 != 0) {
      iVar6 = puVar4[1];
      if (iVar6 == 0) {
        iVar6 = (*(code *)PTR_sk_new_null_006a80a4)();
        puVar4[1] = iVar6;
        if (iVar6 == 0) goto LAB_005c4230;
      }
      iVar6 = (*(code *)PTR_sk_push_006a80a8)(iVar6,iVar5);
      if (iVar6 != 0) goto LAB_005c4304;
    }
  }
LAB_005c4230:
  (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x84,0x41,"ts_rsp_sign.c",0x16e);
  uVar7 = 0;
LAB_005c425c:
  TS_STATUS_INFO_free(puVar4);
  (*(code *)PTR_ASN1_UTF8STRING_free_006a9e3c)(iVar5);
  return uVar7;
}

