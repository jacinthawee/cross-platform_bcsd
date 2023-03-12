
int TS_RESP_verify_token(uint *param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = PKCS7_to_TS_TST_INFO(param_2);
  if (iVar2 == 0) {
    iVar3 = 0;
    goto LAB_005c6d1c;
  }
  local_2c = 0;
  iVar3 = TS_TST_INFO_get_tsa(iVar2);
  uVar6 = *param_1;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  if ((uVar6 & 1) == 0) {
LAB_005c6c6c:
    if ((uVar6 & 2) != 0) {
      iVar4 = TS_TST_INFO_get_version(iVar2);
      if (iVar4 == 1) {
        uVar6 = *param_1;
        goto joined_r0x005c6d6c;
      }
      uVar7 = 0x71;
      uVar5 = 0x1ac;
LAB_005c6db4:
      (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x95,uVar7,"ts_rsp_verify.c",uVar5);
      goto LAB_005c6dc8;
    }
joined_r0x005c6d6c:
    if ((uVar6 & 4) == 0) {
joined_r0x005c6e08:
      if ((uVar6 & 8) != 0) {
        iVar4 = TS_check_imprints(param_1[4],param_1[5],param_1[6],iVar2);
        if (iVar4 == 0) goto LAB_005c6dc8;
        uVar6 = *param_1;
      }
      if ((uVar6 & 0x10) != 0) {
        iVar4 = TS_compute_imprint(param_1[7],iVar2,&local_28,&local_24,&local_20);
        if ((iVar4 == 0) ||
           (iVar4 = TS_check_imprints(local_28,local_24,local_20,iVar2), iVar4 == 0))
        goto LAB_005c6dc8;
        uVar6 = *param_1;
      }
      if ((uVar6 & 0x20) == 0) {
LAB_005c6ca4:
        if (((uVar6 & 0x40) != 0) && (iVar3 != 0)) {
          iVar3 = TS_check_signer_name(iVar3,local_2c);
          if (iVar3 == 0) {
            uVar7 = 0x6f;
            uVar5 = 0x1cb;
            goto LAB_005c6db4;
          }
          uVar6 = *param_1;
        }
        if (((uVar6 & 0x80) == 0) || (iVar3 = TS_check_signer_name(param_1[9],local_2c), iVar3 != 0)
           ) {
          iVar3 = 1;
        }
        else {
          iVar3 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x95,0x70,"ts_rsp_verify.c",0x1d3);
        }
      }
      else {
        uVar6 = param_1[8];
        iVar4 = TS_TST_INFO_get_nonce(iVar2);
        if (iVar4 == 0) {
          uVar7 = 0x69;
          uVar5 = 0x2a1;
        }
        else {
          iVar4 = (*(code *)PTR_ASN1_INTEGER_cmp_006a9e58)(uVar6,iVar4);
          if (iVar4 == 0) {
            uVar6 = *param_1;
            goto LAB_005c6ca4;
          }
          uVar7 = 0x68;
          uVar5 = 0x2a8;
        }
        iVar3 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x65,uVar7,"ts_rsp_verify.c",uVar5);
      }
    }
    else {
      uVar6 = param_1[3];
      uVar5 = TS_TST_INFO_get_policy_id(iVar2);
      iVar4 = (*(code *)PTR_OBJ_cmp_006a9de4)(uVar6,uVar5);
      if (iVar4 == 0) {
        uVar6 = *param_1;
        goto joined_r0x005c6e08;
      }
      iVar3 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x66,0x6c,"ts_rsp_verify.c",0x23f);
    }
  }
  else {
    iVar4 = TS_RESP_verify_signature(param_2,param_1[2],param_1[1],&local_2c);
    if (iVar4 != 0) {
      uVar6 = *param_1;
      goto LAB_005c6c6c;
    }
LAB_005c6dc8:
    iVar3 = 0;
  }
  (*(code *)PTR_X509_free_006a7f90)(local_2c);
  (*(code *)PTR_X509_ALGOR_free_006a8f94)(local_28);
  (*(code *)PTR_CRYPTO_free_006a7f88)(local_24);
  TS_TST_INFO_free(iVar2);
LAB_005c6d1c:
  if (local_1c == *(int *)puVar1) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar2 = (*(code *)PTR_CRYPTO_malloc_006a8108)(0x28,"ts_verify_ctx.c",0x42);
  if (iVar2 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x90,0x41,"ts_verify_ctx.c",0x46);
    return 0;
  }
  (*(code *)PTR_memset_006aab00)(iVar2,0,0x28);
  return iVar2;
}

