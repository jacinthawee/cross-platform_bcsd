
/* WARNING: Could not reconcile some variable overlaps */

void TS_RESP_verify_response(int *param_1,undefined4 param_2)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  ASN1_INTEGER **ppAVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  ASN1_STRING *pAVar9;
  size_t __n;
  uchar *__src;
  ASN1_INTEGER *pAVar10;
  ASN1_OBJECT *b;
  _STACK *p_Var11;
  ASN1_INTEGER *x;
  ASN1_OBJECT *a;
  int iVar12;
  char *pcVar13;
  char *local_148;
  char *local_144;
  X509 *local_140;
  X509_ALGOR *local_13c;
  void *local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  int local_2c;
  
  local_2c = __TMC_END__;
  uVar3 = TS_RESP_get_token(param_2);
  uVar4 = TS_RESP_get_tst_info(param_2);
  ppAVar5 = (ASN1_INTEGER **)TS_RESP_get_status_info(param_2);
  uVar6 = ASN1_INTEGER_get(*ppAVar5);
  local_130 = 0;
  memset(&uStack_12c,0,0xfc);
  if (uVar6 < 2) {
    local_140 = (X509 *)0x0;
    iVar7 = TS_TST_INFO_get_tsa(uVar4);
    iVar12 = *param_1;
    local_13c = (X509_ALGOR *)0x0;
    local_138 = (void *)0x0;
    local_134 = 0;
    if (iVar12 << 0x1f < 0) {
      iVar12 = TS_RESP_verify_signature(uVar3,param_1[2],param_1[1],&local_140);
      if (iVar12 != 0) {
        iVar12 = *param_1;
        goto LAB_000ec30a;
      }
    }
    else {
LAB_000ec30a:
      if (iVar12 << 0x1e < 0) {
        iVar12 = TS_TST_INFO_get_version(uVar4);
        if (iVar12 != 1) {
          ERR_put_error(0x2f,0x95,0x71,"ts_rsp_verify.c",0x1ac);
          goto LAB_000ec384;
        }
        iVar12 = *param_1;
      }
      if (iVar12 << 0x1d < 0) {
        a = (ASN1_OBJECT *)param_1[3];
        b = (ASN1_OBJECT *)TS_TST_INFO_get_policy_id(uVar4);
        iVar12 = OBJ_cmp(a,b);
        if (iVar12 != 0) {
          ERR_put_error(0x2f,0x66,0x6c,"ts_rsp_verify.c",0x23f);
          goto LAB_000ec384;
        }
        iVar12 = *param_1;
      }
      if (iVar12 << 0x1c < 0) {
        iVar12 = TS_check_imprints(param_1[4],param_1[5],param_1[6],uVar4);
        if (iVar12 == 0) goto LAB_000ec384;
        iVar12 = *param_1;
      }
      if (iVar12 << 0x1b < 0) {
        iVar12 = TS_compute_imprint(param_1[7],uVar4,&local_13c,&local_138,&local_134);
        if ((iVar12 == 0) ||
           (iVar12 = TS_check_imprints(local_13c,local_138,local_134,uVar4), iVar12 == 0))
        goto LAB_000ec384;
        iVar12 = *param_1;
      }
      if (iVar12 << 0x1a < 0) {
        x = (ASN1_INTEGER *)param_1[8];
        pAVar10 = (ASN1_INTEGER *)TS_TST_INFO_get_nonce(uVar4);
        if (pAVar10 == (ASN1_INTEGER *)0x0) {
          ERR_put_error(0x2f,0x65,0x69,"ts_rsp_verify.c",0x2a1);
        }
        else {
          iVar12 = ASN1_INTEGER_cmp(x,pAVar10);
          if (iVar12 == 0) {
            iVar12 = *param_1;
            goto LAB_000ec31e;
          }
          ERR_put_error(0x2f,0x65,0x68,"ts_rsp_verify.c",0x2a8);
        }
      }
      else {
LAB_000ec31e:
        if ((iVar12 << 0x19 < 0) && (iVar7 != 0)) {
          iVar7 = TS_check_signer_name(iVar7,local_140);
          if (iVar7 == 0) {
            ERR_put_error(0x2f,0x95,0x6f,"ts_rsp_verify.c",0x1cb);
            goto LAB_000ec384;
          }
          iVar12 = *param_1;
        }
        if ((-1 < iVar12 << 0x18) ||
           (iVar7 = TS_check_signer_name(param_1[9],local_140), iVar7 != 0)) {
          X509_free(local_140);
          X509_ALGOR_free(local_13c);
          CRYPTO_free(local_138);
          uVar3 = 1;
          goto LAB_000ec2d0;
        }
        ERR_put_error(0x2f,0x95,0x70,"ts_rsp_verify.c",0x1d3);
      }
    }
LAB_000ec384:
    X509_free(local_140);
    X509_ALGOR_free(local_13c);
    CRYPTO_free(local_138);
  }
  else {
    if (uVar6 < 6) {
      local_144 = *(char **)(&TS_status_text + uVar6 * 4);
    }
    else {
      local_144 = "unknown code";
    }
    iVar7 = sk_num((_STACK *)ppAVar5[1]);
    if (iVar7 < 1) {
      pAVar10 = ppAVar5[2];
      local_148 = (char *)0x0;
      puVar2 = PTR_TS_failure_info_000ec4b4;
    }
    else {
      iVar12 = 0;
      p_Var11 = (_STACK *)ppAVar5[1];
      for (iVar7 = 0; iVar8 = sk_num(p_Var11), iVar7 < iVar8; iVar7 = iVar7 + 1) {
        pAVar9 = (ASN1_STRING *)sk_value(p_Var11,iVar7);
        iVar8 = ASN1_STRING_length(pAVar9);
        iVar12 = iVar12 + iVar8 + 1;
      }
      local_148 = (char *)CRYPTO_malloc(iVar12,"ts_rsp_verify.c",0x225);
      if (local_148 == (char *)0x0) {
        ERR_put_error(0x2f,0x69,0x41,"ts_rsp_verify.c",0x227);
        goto LAB_000ec2ce;
      }
      iVar7 = 0;
      pcVar13 = local_148;
      while (iVar12 = sk_num(p_Var11), iVar7 < iVar12) {
        pAVar9 = (ASN1_STRING *)sk_value(p_Var11,iVar7);
        __n = ASN1_STRING_length(pAVar9);
        if (0 < iVar7) {
          *pcVar13 = '/';
          pcVar13 = pcVar13 + 1;
        }
        __src = ASN1_STRING_data(pAVar9);
        strncpy(pcVar13,(char *)__src,__n);
        pcVar13 = pcVar13 + __n;
        iVar7 = iVar7 + 1;
      }
      *pcVar13 = '\0';
      pAVar10 = ppAVar5[2];
      puVar2 = PTR_TS_failure_info_000ec4b4;
    }
    PTR_TS_failure_info_000ec4b4 = puVar2;
    if (pAVar10 != (ASN1_INTEGER *)0x0) {
      iVar7 = 0;
      bVar1 = true;
      while( true ) {
        iVar12 = ASN1_BIT_STRING_get_bit(pAVar10,*(int *)(puVar2 + iVar7));
        if (iVar12 != 0) {
          if (!bVar1) {
            local_130 = CONCAT22(local_130._2_2_,0x2c);
          }
          bVar1 = false;
          __strcat_chk(&local_130,*(undefined4 *)(puVar2 + iVar7 + 4),0x100);
        }
        iVar7 = iVar7 + 8;
        if (iVar7 == 0x40) break;
        pAVar10 = ppAVar5[2];
      }
    }
    if ((char)local_130 == '\0') {
      local_130 = s_unspecified_0012864c._0_4_;
      uStack_12c = s_unspecified_0012864c._4_4_;
      uStack_128 = s_unspecified_0012864c._8_4_;
    }
    ERR_put_error(0x2f,0x68,0x6b,"ts_rsp_verify.c",0x20b);
    pcVar13 = "unspecified";
    if (local_148 != (char *)0x0) {
      pcVar13 = local_148;
    }
    ERR_add_error_data(6,"status code: ",local_144,", status text: ",pcVar13,", failure codes: ",
                       &local_130);
    CRYPTO_free(local_148);
  }
LAB_000ec2ce:
  uVar3 = 0;
LAB_000ec2d0:
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar3);
}

