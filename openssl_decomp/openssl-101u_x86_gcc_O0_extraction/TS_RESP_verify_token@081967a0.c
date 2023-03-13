
undefined4 TS_RESP_verify_token(uint *param_1,undefined4 param_2)

{
  ASN1_OBJECT *a;
  ASN1_INTEGER *x;
  int iVar1;
  int iVar2;
  uint uVar3;
  ASN1_OBJECT *b;
  ASN1_INTEGER *y;
  undefined4 uVar4;
  int in_GS_OFFSET;
  int iVar5;
  X509 *local_30;
  X509_ALGOR *local_2c;
  void *local_28;
  undefined4 local_24;
  int local_20;
  
  uVar4 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = PKCS7_to_TS_TST_INFO(param_2);
  if (iVar1 == 0) goto LAB_08196885;
  local_30 = (X509 *)0x0;
  iVar2 = TS_TST_INFO_get_tsa(iVar1);
  uVar3 = *param_1;
  local_2c = (X509_ALGOR *)0x0;
  local_28 = (void *)0x0;
  local_24 = 0;
  if ((uVar3 & 1) == 0) {
LAB_08196808:
    if ((uVar3 & 2) != 0) {
      iVar5 = TS_TST_INFO_get_version(iVar1);
      if (iVar5 == 1) {
        uVar3 = *param_1;
        goto joined_r0x081968b5;
      }
      iVar5 = 0x1be;
      iVar2 = 0x71;
LAB_081968ef:
      ERR_put_error(0x2f,0x95,iVar2,"ts_rsp_verify.c",iVar5);
      goto LAB_081968fe;
    }
joined_r0x081968b5:
    if ((uVar3 & 4) == 0) {
joined_r0x0819692c:
      if ((uVar3 & 8) != 0) {
        iVar5 = TS_check_imprints(iVar1);
        if (iVar5 == 0) goto LAB_081968fe;
        uVar3 = *param_1;
      }
      if ((uVar3 & 0x10) != 0) {
        iVar5 = TS_compute_imprint(&local_28,&local_24);
        if ((iVar5 == 0) || (iVar5 = TS_check_imprints(iVar1), iVar5 == 0)) goto LAB_081968fe;
        uVar3 = *param_1;
      }
      if ((uVar3 & 0x20) == 0) {
LAB_08196830:
        if (((uVar3 & 0x40) != 0) && (iVar2 != 0)) {
          iVar2 = TS_check_signer_name();
          if (iVar2 == 0) {
            iVar5 = 0x1dc;
            iVar2 = 0x6f;
            goto LAB_081968ef;
          }
          uVar3 = *param_1;
        }
        if (((uVar3 & 0x80) != 0) && (iVar2 = TS_check_signer_name(), iVar2 == 0)) {
          iVar5 = 0x1e3;
          iVar2 = 0x70;
          goto LAB_081968ef;
        }
        uVar4 = 1;
      }
      else {
        x = (ASN1_INTEGER *)param_1[8];
        y = (ASN1_INTEGER *)TS_TST_INFO_get_nonce(iVar1);
        if (y == (ASN1_INTEGER *)0x0) {
          uVar4 = 0;
          ERR_put_error(0x2f,0x65,0x69,"ts_rsp_verify.c",0x2aa);
        }
        else {
          iVar5 = ASN1_INTEGER_cmp(x,y);
          if (iVar5 == 0) {
            uVar3 = *param_1;
            goto LAB_08196830;
          }
          uVar4 = 0;
          ERR_put_error(0x2f,0x65,0x68,"ts_rsp_verify.c",0x2b0);
        }
      }
    }
    else {
      a = (ASN1_OBJECT *)param_1[3];
      b = (ASN1_OBJECT *)TS_TST_INFO_get_policy_id(iVar1);
      iVar5 = OBJ_cmp(a,b);
      if (iVar5 == 0) {
        uVar3 = *param_1;
        goto joined_r0x0819692c;
      }
      uVar4 = 0;
      ERR_put_error(0x2f,0x66,0x6c,"ts_rsp_verify.c",0x24a);
    }
  }
  else {
    iVar5 = TS_RESP_verify_signature(param_2,param_1[2],param_1[1],&local_30);
    if (iVar5 != 0) {
      uVar3 = *param_1;
      goto LAB_08196808;
    }
LAB_081968fe:
    uVar4 = 0;
  }
  X509_free(local_30);
  X509_ALGOR_free(local_2c);
  CRYPTO_free(local_28);
  TS_TST_INFO_free(iVar1);
LAB_08196885:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}

