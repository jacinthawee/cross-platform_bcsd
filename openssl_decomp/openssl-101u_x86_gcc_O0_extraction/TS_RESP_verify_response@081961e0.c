
/* WARNING: Could not reconcile some variable overlaps */

undefined4 TS_RESP_verify_response(uint *param_1,undefined4 param_2)

{
  _STACK *p_Var1;
  ASN1_OBJECT *a;
  bool bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  ASN1_INTEGER **ppAVar5;
  uint uVar6;
  int iVar7;
  ASN1_STRING *pAVar8;
  size_t __n;
  uchar *__src;
  ASN1_INTEGER *pAVar9;
  char *pcVar10;
  ASN1_OBJECT *b;
  ASN1_INTEGER *y;
  int iVar11;
  int iVar12;
  char *__dest;
  undefined4 *puVar13;
  undefined1 *puVar14;
  int in_GS_OFFSET;
  byte bVar15;
  char *local_144;
  char *local_140;
  X509 *local_130;
  X509_ALGOR *local_12c;
  void *local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  int local_20;
  
  bVar15 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar3 = TS_RESP_get_token(param_2);
  uVar4 = TS_RESP_get_tst_info(param_2);
  ppAVar5 = (ASN1_INTEGER **)TS_RESP_get_status_info(param_2);
  uVar6 = ASN1_INTEGER_get(*ppAVar5);
  local_120 = 0;
  puVar13 = &local_11c;
  for (iVar11 = 0x3f; iVar11 != 0; iVar11 = iVar11 + -1) {
    *puVar13 = 0;
    puVar13 = puVar13 + (uint)bVar15 * -2 + 1;
  }
  if (1 < uVar6) {
    local_144 = "unknown code";
    if (uVar6 < 6) {
      local_144 = *(char **)(TS_status_text + uVar6 * 4);
    }
    iVar11 = sk_num((_STACK *)ppAVar5[1]);
    if (iVar11 < 1) {
      local_140 = (char *)0x0;
      pAVar9 = ppAVar5[2];
    }
    else {
      p_Var1 = (_STACK *)ppAVar5[1];
      iVar11 = 0;
      for (iVar12 = 0; iVar7 = sk_num(p_Var1), iVar12 < iVar7; iVar12 = iVar12 + 1) {
        pAVar8 = (ASN1_STRING *)sk_value(p_Var1,iVar12);
        iVar7 = ASN1_STRING_length(pAVar8);
        iVar11 = iVar7 + 1 + iVar11;
      }
      local_140 = (char *)CRYPTO_malloc(iVar11,"ts_rsp_verify.c",0x232);
      if (local_140 == (char *)0x0) {
        ERR_put_error(0x2f,0x69,0x41,"ts_rsp_verify.c",0x233);
        uVar3 = 0;
        goto LAB_08196446;
      }
      pcVar10 = local_140;
      for (iVar11 = 0; iVar12 = sk_num(p_Var1), iVar11 < iVar12; iVar11 = iVar11 + 1) {
        pAVar8 = (ASN1_STRING *)sk_value(p_Var1,iVar11);
        __n = ASN1_STRING_length(pAVar8);
        __dest = pcVar10;
        if (0 < iVar11) {
          __dest = pcVar10 + 1;
          *pcVar10 = '/';
        }
        __src = ASN1_STRING_data(pAVar8);
        strncpy(__dest,(char *)__src,__n);
        pcVar10 = __dest + __n;
      }
      *pcVar10 = '\0';
      pAVar9 = ppAVar5[2];
    }
    if (pAVar9 != (ASN1_INTEGER *)0x0) {
      puVar14 = TS_failure_info;
      bVar2 = true;
      while( true ) {
        iVar11 = ASN1_BIT_STRING_get_bit(pAVar9,*(int *)puVar14);
        if (iVar11 != 0) {
          if (!bVar2) {
            __strcat_chk(&local_120,",",0x100);
          }
          bVar2 = false;
          __strcat_chk(&local_120,*(int *)((int)puVar14 + 4),0x100);
        }
        puVar14 = (undefined1 *)((int)puVar14 + 8);
        if (puVar14 == TS_status_text) break;
        pAVar9 = ppAVar5[2];
      }
    }
    if ((char)local_120 == '\0') {
      local_120 = 0x70736e75;
      local_11c = 0x66696365;
      local_118 = 0x646569;
    }
    ERR_put_error(0x2f,0x68,0x6b,"ts_rsp_verify.c",0x219);
    pcVar10 = "unspecified";
    if (local_140 != (char *)0x0) {
      pcVar10 = local_140;
    }
    ERR_add_error_data(6,"status code: ",local_144,", status text: ",pcVar10,", failure codes: ",
                       &local_120);
    CRYPTO_free(local_140);
    uVar3 = 0;
    goto LAB_08196446;
  }
  local_130 = (X509 *)0x0;
  iVar11 = TS_TST_INFO_get_tsa(uVar4);
  uVar6 = *param_1;
  local_12c = (X509_ALGOR *)0x0;
  local_128 = (void *)0x0;
  local_124 = 0;
  if ((uVar6 & 1) == 0) {
LAB_081964a0:
    if ((uVar6 & 2) != 0) {
      iVar12 = TS_TST_INFO_get_version(uVar4);
      if (iVar12 != 1) {
        ERR_put_error(0x2f,0x95,0x71,"ts_rsp_verify.c",0x1be);
        goto LAB_08196590;
      }
      uVar6 = *param_1;
    }
    if ((uVar6 & 4) != 0) {
      a = (ASN1_OBJECT *)param_1[3];
      b = (ASN1_OBJECT *)TS_TST_INFO_get_policy_id(uVar4);
      iVar12 = OBJ_cmp(a,b);
      if (iVar12 != 0) {
        ERR_put_error(0x2f,0x66,0x6c,"ts_rsp_verify.c",0x24a);
        goto LAB_08196590;
      }
      uVar6 = *param_1;
    }
    if ((uVar6 & 8) != 0) {
      iVar12 = TS_check_imprints(uVar4);
      if (iVar12 == 0) goto LAB_08196590;
      uVar6 = *param_1;
    }
    if ((uVar6 & 0x10) != 0) {
      iVar12 = TS_compute_imprint(&local_128,&local_124);
      if ((iVar12 == 0) || (iVar12 = TS_check_imprints(uVar4), iVar12 == 0)) goto LAB_08196590;
      uVar6 = *param_1;
    }
    if ((uVar6 & 0x20) == 0) {
LAB_081964c8:
      if (((uVar6 & 0x40) != 0) && (iVar11 != 0)) {
        iVar11 = TS_check_signer_name();
        if (iVar11 == 0) {
          ERR_put_error(0x2f,0x95,0x6f,"ts_rsp_verify.c",0x1dc);
          goto LAB_08196590;
        }
        uVar6 = *param_1;
      }
      if (((uVar6 & 0x80) == 0) || (iVar11 = TS_check_signer_name(), iVar11 != 0)) {
        X509_free(local_130);
        X509_ALGOR_free(local_12c);
        CRYPTO_free(local_128);
        uVar3 = 1;
        goto LAB_08196446;
      }
      ERR_put_error(0x2f,0x95,0x70,"ts_rsp_verify.c",0x1e3);
    }
    else {
      pAVar9 = (ASN1_INTEGER *)param_1[8];
      y = (ASN1_INTEGER *)TS_TST_INFO_get_nonce(uVar4);
      if (y == (ASN1_INTEGER *)0x0) {
        ERR_put_error(0x2f,0x65,0x69,"ts_rsp_verify.c",0x2aa);
      }
      else {
        iVar12 = ASN1_INTEGER_cmp(pAVar9,y);
        if (iVar12 == 0) {
          uVar6 = *param_1;
          goto LAB_081964c8;
        }
        ERR_put_error(0x2f,0x65,0x68,"ts_rsp_verify.c",0x2b0);
      }
    }
  }
  else {
    iVar12 = TS_RESP_verify_signature(uVar3,param_1[2],param_1[1],&local_130);
    if (iVar12 != 0) {
      uVar6 = *param_1;
      goto LAB_081964a0;
    }
  }
LAB_08196590:
  X509_free(local_130);
  X509_ALGOR_free(local_12c);
  CRYPTO_free(local_128);
  uVar3 = 0;
LAB_08196446:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

