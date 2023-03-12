
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
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = PKCS7_to_TS_TST_INFO(param_2);
  if (iVar2 == 0) {
    iVar3 = 0;
    goto LAB_005c44ac;
  }
  local_2c = 0;
  iVar3 = TS_TST_INFO_get_tsa(iVar2);
  uVar6 = *param_1;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  if ((uVar6 & 1) == 0) {
LAB_005c43fc:
    if ((uVar6 & 2) != 0) {
      iVar4 = TS_TST_INFO_get_version(iVar2);
      if (iVar4 == 1) {
        uVar6 = *param_1;
        goto joined_r0x005c44fc;
      }
      uVar7 = 0x71;
      uVar5 = 0x1be;
LAB_005c4544:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x95,uVar7,"ts_rsp_verify.c",uVar5);
      goto LAB_005c4558;
    }
joined_r0x005c44fc:
    if ((uVar6 & 4) == 0) {
joined_r0x005c4598:
      if ((uVar6 & 8) != 0) {
        iVar4 = TS_check_imprints(param_1[4],param_1[5],param_1[6],iVar2);
        if (iVar4 == 0) goto LAB_005c4558;
        uVar6 = *param_1;
      }
      if ((uVar6 & 0x10) != 0) {
        iVar4 = TS_compute_imprint(param_1[7],iVar2,&local_28,&local_24,&local_20);
        if ((iVar4 == 0) ||
           (iVar4 = TS_check_imprints(local_28,local_24,local_20,iVar2), iVar4 == 0))
        goto LAB_005c4558;
        uVar6 = *param_1;
      }
      if ((uVar6 & 0x20) == 0) {
LAB_005c4434:
        if (((uVar6 & 0x40) != 0) && (iVar3 != 0)) {
          iVar3 = TS_check_signer_name(iVar3,local_2c);
          if (iVar3 == 0) {
            uVar7 = 0x6f;
            uVar5 = 0x1dc;
            goto LAB_005c4544;
          }
          uVar6 = *param_1;
        }
        if (((uVar6 & 0x80) == 0) || (iVar3 = TS_check_signer_name(param_1[9],local_2c), iVar3 != 0)
           ) {
          iVar3 = 1;
        }
        else {
          iVar3 = 0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x95,0x70,"ts_rsp_verify.c",0x1e3);
        }
      }
      else {
        uVar6 = param_1[8];
        iVar4 = TS_TST_INFO_get_nonce(iVar2);
        if (iVar4 == 0) {
          uVar7 = 0x69;
          uVar5 = 0x2aa;
        }
        else {
          iVar4 = (*(code *)PTR_ASN1_INTEGER_cmp_006a8d38)(uVar6,iVar4);
          if (iVar4 == 0) {
            uVar6 = *param_1;
            goto LAB_005c4434;
          }
          uVar7 = 0x68;
          uVar5 = 0x2b0;
        }
        iVar3 = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x65,uVar7,"ts_rsp_verify.c",uVar5);
      }
    }
    else {
      uVar6 = param_1[3];
      uVar5 = TS_TST_INFO_get_policy_id(iVar2);
      iVar4 = (*(code *)PTR_OBJ_cmp_006a8cc4)(uVar6,uVar5);
      if (iVar4 == 0) {
        uVar6 = *param_1;
        goto joined_r0x005c4598;
      }
      iVar3 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x66,0x6c,"ts_rsp_verify.c",0x24a);
    }
  }
  else {
    iVar4 = TS_RESP_verify_signature(param_2,param_1[2],param_1[1],&local_2c);
    if (iVar4 != 0) {
      uVar6 = *param_1;
      goto LAB_005c43fc;
    }
LAB_005c4558:
    iVar3 = 0;
  }
  (*(code *)PTR_X509_free_006a6e90)(local_2c);
  (*(code *)PTR_X509_ALGOR_free_006a7ea4)(local_28);
  (*(code *)PTR_CRYPTO_free_006a6e88)(local_24);
  TS_TST_INFO_free(iVar2);
LAB_005c44ac:
  if (local_1c == *(int *)puVar1) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar2 = (*(code *)PTR_CRYPTO_malloc_006a7008)(0x28,"ts_verify_ctx.c",0x43);
  if (iVar2 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x90,0x41,"ts_verify_ctx.c",0x47);
    return 0;
  }
  (*(code *)PTR_memset_006a99f4)(iVar2,0,0x28);
  return iVar2;
}

