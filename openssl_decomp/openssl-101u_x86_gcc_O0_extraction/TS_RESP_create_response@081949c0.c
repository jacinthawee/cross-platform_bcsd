
X509 * TS_RESP_create_response(X509 **param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  X509 *pXVar3;
  ASN1_INTEGER **ppAVar4;
  int iVar5;
  long lVar6;
  undefined4 uVar7;
  ASN1_OBJECT **ppAVar8;
  int iVar9;
  EVP_MD *pEVar10;
  int *piVar11;
  ASN1_BIT_STRING *a;
  ASN1_OBJECT *pAVar12;
  X509 *pXVar13;
  tm *ptVar14;
  _STACK *p_Var15;
  void *pvVar16;
  PKCS7_SIGNER_INFO *p7si;
  X509_NAME *pXVar17;
  X509_ALGOR *pXVar18;
  rsa_st *prVar19;
  X509 *pXVar20;
  X509 *extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  uint uVar21;
  undefined4 extraout_ECX_02;
  X509 *extraout_ECX_03;
  X509 *extraout_ECX_04;
  GENERAL_NAME *a_00;
  X509 *extraout_EDX;
  int iVar22;
  PKCS7 *p7;
  ASN1_INTEGER *a_01;
  ASN1_STRING *pAVar23;
  _STACK **pp_Var24;
  int in_GS_OFFSET;
  byte bVar25;
  undefined8 uVar26;
  char *pcVar27;
  X509 *pXVar28;
  X509 *local_58;
  int local_54;
  X509 *local_44;
  undefined4 local_40;
  X509 *local_3c;
  char acStack_38 [24];
  int local_20;
  
  bVar25 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  param_1[0x11] = (X509 *)0x0;
  param_1[0x12] = (X509 *)0x0;
  param_1[0x13] = (X509 *)0x0;
  pXVar3 = (X509 *)TS_RESP_new();
  param_1[0x12] = pXVar3;
  if (pXVar3 == (X509 *)0x0) {
    ERR_put_error(0x2f,0x7a,0x41,"ts_rsp_sign.c",0x1b5);
    goto LAB_08194a6e;
  }
  pXVar3 = (X509 *)d2i_TS_REQ_bio(param_2,0);
  param_1[0x11] = pXVar3;
  if (pXVar3 == (X509 *)0x0) {
    pcVar27 = "Bad request format or system error.";
LAB_08194c18:
    TS_RESP_CTX_set_status_info(param_1,2,pcVar27);
    iVar5 = TS_RESP_get_status_info(param_1[0x12]);
    a = *(ASN1_BIT_STRING **)(iVar5 + 8);
    if (a == (ASN1_BIT_STRING *)0x0) {
      a = ASN1_BIT_STRING_new();
      *(ASN1_BIT_STRING **)(iVar5 + 8) = a;
      if (a == (ASN1_BIT_STRING *)0x0) goto LAB_08194b94;
    }
    iVar5 = 5;
    goto LAB_08194b83;
  }
  ppAVar4 = (ASN1_INTEGER **)TS_STATUS_INFO_new();
  if (((ppAVar4 == (ASN1_INTEGER **)0x0) || (iVar5 = ASN1_INTEGER_set(*ppAVar4,0), iVar5 == 0)) ||
     (iVar5 = TS_RESP_set_status_info(param_1[0x12],ppAVar4), iVar5 == 0)) {
    ERR_put_error(0x2f,0x84,0x41,"ts_rsp_sign.c",0x177);
    TS_STATUS_INFO_free(ppAVar4);
    ASN1_UTF8STRING_free((ASN1_UTF8STRING *)0x0);
    goto LAB_08194a6e;
  }
  TS_STATUS_INFO_free(ppAVar4);
  ASN1_UTF8STRING_free((ASN1_UTF8STRING *)0x0);
  pXVar3 = param_1[0x11];
  iVar5 = TS_REQ_get_version(pXVar3);
  if (iVar5 == 1) {
    iVar22 = 1;
    uVar7 = TS_REQ_get_msg_imprint(pXVar3);
    ppAVar8 = (ASN1_OBJECT **)TS_MSG_IMPRINT_get_algo(uVar7);
    iVar5 = OBJ_obj2nid(*ppAVar8);
    while( true ) {
      iVar9 = sk_num((_STACK *)param_1[5]);
      if (iVar9 <= iVar22 + -1) break;
      pEVar10 = (EVP_MD *)sk_value((_STACK *)param_1[5],iVar22 + -1);
      iVar9 = EVP_MD_type(pEVar10);
      if ((iVar5 == iVar9) && (pEVar10 != (EVP_MD *)0x0)) {
        if ((ppAVar8[1] != (ASN1_OBJECT *)0x0) &&
           (iVar22 = ASN1_TYPE_get((ASN1_TYPE *)ppAVar8[1]), iVar22 != 5)) {
          pcVar27 = "Superfluous message digest parameter.";
          goto LAB_08194d08;
        }
        piVar11 = (int *)TS_MSG_IMPRINT_get_msg(uVar7);
        iVar22 = *piVar11;
        iVar9 = EVP_MD_size(pEVar10);
        if (iVar22 != iVar9) {
          pcVar27 = "Bad message digest.";
          goto LAB_08194c18;
        }
        pAVar12 = (ASN1_OBJECT *)TS_REQ_get_policy_id(param_1[0x11]);
        pXVar3 = param_1[4];
        if (pXVar3 == (X509 *)0x0) {
          ERR_put_error(0x2f,0x85,0x66,"ts_rsp_sign.c",0x241);
          goto LAB_08194a6e;
        }
        if ((pAVar12 == (ASN1_OBJECT *)0x0) ||
           ((iVar22 = OBJ_cmp(pAVar12,(ASN1_OBJECT *)pXVar3), iVar22 == 0 &&
            (pXVar3 = param_1[4], pXVar3 != (X509 *)0x0)))) goto LAB_08194e30;
        iVar5 = 1;
        goto LAB_08194dc5;
      }
      iVar22 = iVar22 + 1;
    }
    pcVar27 = "Message digest algorithm is not supported.";
LAB_08194d08:
    TS_RESP_CTX_set_status_info(param_1,2,pcVar27);
    iVar5 = TS_RESP_get_status_info(param_1[0x12]);
    a = *(ASN1_BIT_STRING **)(iVar5 + 8);
    if (a == (ASN1_BIT_STRING *)0x0) {
      a = ASN1_BIT_STRING_new();
      *(ASN1_BIT_STRING **)(iVar5 + 8) = a;
      if (a == (ASN1_BIT_STRING *)0x0) goto LAB_08194b94;
    }
    iVar5 = 0;
    goto LAB_08194b83;
  }
  TS_RESP_CTX_set_status_info(param_1,2,"Bad request version.");
  iVar5 = TS_RESP_get_status_info(param_1[0x12]);
  a = *(ASN1_BIT_STRING **)(iVar5 + 8);
  if (a != (ASN1_BIT_STRING *)0x0) {
LAB_08194b7c:
    iVar5 = 2;
    goto LAB_08194b83;
  }
  a = ASN1_BIT_STRING_new();
  *(ASN1_BIT_STRING **)(iVar5 + 8) = a;
  if (a != (ASN1_BIT_STRING *)0x0) goto LAB_08194b7c;
  goto LAB_08194b94;
LAB_08194dc5:
  iVar22 = sk_num((_STACK *)param_1[3]);
  if (iVar22 <= iVar5 + -1) goto code_r0x08194dda;
  pXVar3 = (X509 *)sk_value((_STACK *)param_1[3],iVar5 + -1);
  iVar22 = OBJ_cmp(pAVar12,(ASN1_OBJECT *)pXVar3);
  if ((iVar22 == 0) && (pXVar3 != (X509 *)0x0)) goto LAB_08194e30;
  iVar5 = iVar5 + 1;
  goto LAB_08194dc5;
LAB_08194e30:
  pXVar13 = (X509 *)TS_TST_INFO_new();
  if ((pXVar13 == (X509 *)0x0) ||
     ((((iVar22 = TS_TST_INFO_set_version(pXVar13,1), iVar22 == 0 ||
        (iVar22 = TS_TST_INFO_set_policy_id(pXVar13,pXVar3), iVar22 == 0)) ||
       (iVar22 = TS_TST_INFO_set_msg_imprint(pXVar13,param_1[0x11]->sig_alg), iVar22 == 0)) ||
      (a_01 = (ASN1_INTEGER *)(*(code *)param_1[0xb])(param_1,param_1[0xc],iVar5,iVar5),
      a_01 == (ASN1_INTEGER *)0x0)))) {
    a_00 = (GENERAL_NAME *)0x0;
    iVar5 = 0;
    pAVar23 = (ASN1_GENERALIZEDTIME *)0x0;
    a_01 = (ASN1_INTEGER *)0x0;
  }
  else {
    iVar5 = TS_TST_INFO_set_serial(pXVar13,a_01,pXVar3,pXVar3);
    if ((iVar5 == 0) ||
       (iVar5 = (*(code *)param_1[0xd])(param_1,param_1[0xe],&local_44,&local_40), iVar5 == 0)) {
      a_00 = (GENERAL_NAME *)0x0;
      iVar5 = 0;
      pAVar23 = (ASN1_GENERALIZEDTIME *)0x0;
    }
    else {
      pXVar3 = param_1[9];
      local_3c = local_44;
      if ((pXVar3 < (X509 *)0x7) && (ptVar14 = gmtime((time_t *)&local_3c), ptVar14 != (tm *)0x0)) {
        iVar5 = BIO_snprintf(acStack_38 + 1,0x17,"%04d%02d%02d%02d%02d%02d",ptVar14->tm_year + 0x76c
                             ,ptVar14->tm_mon + 1,ptVar14->tm_mday,ptVar14->tm_hour,ptVar14->tm_min,
                             ptVar14->tm_sec);
        pcVar27 = acStack_38 + iVar5 + 1;
        if (pXVar3 != (X509 *)0x0) {
          BIO_snprintf(pcVar27,(size_t)((int)&pXVar3->cert_info + 2),".%06ld",local_40);
          uVar21 = 0xffffffff;
          do {
            if (uVar21 == 0) break;
            uVar21 = uVar21 - 1;
            cVar1 = *pcVar27;
            pcVar27 = pcVar27 + (uint)bVar25 * -2 + 1;
          } while (cVar1 != '\0');
          pcVar2 = acStack_38 + ~uVar21 + iVar5;
          do {
            pcVar27 = pcVar2;
            pcVar2 = pcVar27 + -1;
          } while (pcVar27[-1] == '0');
          if (pcVar27[-1] == '.') {
            pcVar27 = pcVar27 + -1;
          }
        }
        *pcVar27 = 'Z';
        pcVar27[1] = '\0';
        pAVar23 = ASN1_STRING_type_new(0x18);
        if (pAVar23 != (ASN1_STRING *)0x0) {
          pXVar3 = (X509 *)ASN1_GENERALIZEDTIME_set_string(pAVar23,acStack_38 + 1);
          if (pXVar3 != (X509 *)0x0) {
            iVar5 = TS_TST_INFO_set_time(pXVar13,pAVar23,pXVar3,pXVar3);
            if (iVar5 == 0) {
              a_00 = (GENERAL_NAME *)0x0;
              iVar5 = 0;
              goto LAB_08194e5e;
            }
            if (((param_1[6] == (X509 *)0x0) && (param_1[7] == (X509 *)0x0)) &&
               (param_1[8] == (X509 *)0x0)) {
              iVar5 = 0;
              pXVar28 = extraout_ECX;
LAB_08195166:
              if (((*(byte *)(param_1 + 10) & 2) == 0) ||
                 (iVar22 = TS_TST_INFO_set_ordering(pXVar13,1,pXVar28,pXVar28), pXVar3 = pXVar28,
                 iVar22 != 0)) {
                uVar26 = TS_REQ_get_nonce(param_1[0x11]);
                pXVar20 = (X509 *)((ulonglong)uVar26 >> 0x20);
                if (((int)uVar26 == 0) ||
                   (iVar22 = TS_TST_INFO_set_nonce(pXVar13,uVar26,pXVar20), pXVar3 = pXVar20,
                   iVar22 != 0)) {
                  if ((*(byte *)(param_1 + 10) & 1) == 0) {
                    a_00 = (GENERAL_NAME *)0x0;
LAB_081951b5:
                    GENERAL_NAME_free(a_00);
                    TS_ACCURACY_free(iVar5);
                    ASN1_GENERALIZEDTIME_free(pAVar23);
                    ASN1_INTEGER_free(a_01);
                    param_1[0x13] = pXVar13;
                    p_Var15 = (_STACK *)TS_REQ_get_exts(param_1[0x11]);
                    iVar5 = 0;
LAB_08195212:
                    iVar22 = sk_num(p_Var15);
                    if (iVar5 < iVar22) goto LAB_081951f0;
                    pcVar27 = (char *)param_1[1];
                    iVar5 = X509_check_private_key(*param_1,(EVP_PKEY *)pcVar27);
                    if (iVar5 == 0) {
                      pXVar13 = (X509 *)0x0;
                      pp_Var24 = (_STACK **)0x0;
                      p7 = (PKCS7 *)0x0;
                      ERR_put_error(0x2f,0x88,0x78,"ts_rsp_sign.c",0x2d3);
                      goto LAB_0819525b;
                    }
                    p7 = PKCS7_new();
                    if (p7 == (PKCS7 *)0x0) {
                      iVar22 = 0x2d9;
                      iVar5 = 0x41;
                      goto LAB_08195544;
                    }
                    pXVar13 = (X509 *)0x0;
                    pp_Var24 = (_STACK **)0x0;
                    pcVar27 = (char *)0x16;
                    iVar5 = PKCS7_set_type(p7,0x16);
                    if (iVar5 == 0) goto LAB_0819525b;
                    pcVar27 = (char *)0x3;
                    iVar5 = ASN1_INTEGER_set(((p7->d).sign)->version,3);
                    if (iVar5 == 0) goto LAB_0819525b;
                    iVar5 = TS_REQ_get_cert_req(param_1[0x11]);
                    if ((iVar5 != 0) &&
                       (PKCS7_add_certificate(p7,*param_1), param_1[2] != (X509 *)0x0)) {
                      for (iVar5 = 0; iVar22 = sk_num((_STACK *)param_1[2]), iVar5 < iVar22;
                          iVar5 = iVar5 + 1) {
                        pXVar3 = (X509 *)sk_value((_STACK *)param_1[2],iVar5);
                        PKCS7_add_certificate(p7,pXVar3);
                      }
                    }
                    pEVar10 = EVP_sha1();
                    pXVar3 = param_1[1];
                    pcVar27 = (char *)*param_1;
                    p7si = PKCS7_add_signature(p7,(X509 *)pcVar27,(EVP_PKEY *)pXVar3,pEVar10);
                    if (p7si == (PKCS7_SIGNER_INFO *)0x0) {
                      iVar22 = 0x2f1;
                      iVar5 = 0x76;
LAB_08195544:
                      iVar9 = 0x88;
LAB_08195522:
                      pXVar13 = (X509 *)0x0;
                      pp_Var24 = (_STACK **)0x0;
                      ERR_put_error(0x2f,iVar9,iVar5,"ts_rsp_sign.c",iVar22);
                    }
                    else {
                      pAVar12 = OBJ_nid2obj(0xcf);
                      iVar5 = PKCS7_add_signed_attribute(p7si,0x32,6,pAVar12);
                      if (iVar5 == 0) {
                        iVar22 = 0x2f9;
                        iVar5 = 0x77;
                        goto LAB_08195544;
                      }
                      local_58 = (X509 *)0x0;
                      if ((*(byte *)(param_1 + 10) & 4) != 0) {
                        local_58 = param_1[2];
                      }
                      pXVar13 = *param_1;
                      pp_Var24 = (_STACK **)ESS_SIGNING_CERT_new();
                      if (pp_Var24 == (_STACK **)0x0) {
LAB_08195509:
                        ESS_SIGNING_CERT_free(pp_Var24,pcVar27,pXVar3);
                        iVar22 = 0x34e;
                        iVar5 = 0x41;
                        iVar9 = 0x72;
                        goto LAB_08195522;
                      }
                      if (*pp_Var24 == (_STACK *)0x0) {
                        p_Var15 = sk_new_null();
                        *pp_Var24 = p_Var15;
                        if (p_Var15 == (_STACK *)0x0) goto LAB_08195509;
                      }
                      pXVar28 = (X509 *)0x0;
                      pXVar20 = (X509 *)0xffffffff;
                      X509_check_purpose(pXVar13,-1,0);
                      pcVar27 = (char *)ESS_CERT_ID_new();
                      if ((X509 *)pcVar27 == (X509 *)0x0) {
LAB_081956a8:
                        pXVar3 = pXVar28;
                        GENERAL_NAME_free((GENERAL_NAME *)0x0);
LAB_081954ea:
                        ESS_CERT_ID_free(pcVar27);
                        ERR_put_error(0x2f,0x71,0x41,"ts_rsp_sign.c",0x37a);
                        pcVar27 = (char *)pXVar20;
                        goto LAB_08195509;
                      }
                      pXVar3 = (X509 *)&pXVar13->rfc3779_addr;
                      pXVar28 = (X509 *)&DAT_00000014;
                      pXVar20 = pXVar3;
                      iVar5 = ASN1_OCTET_STRING_set
                                        ((ASN1_STRING *)*(X509_CINF **)pcVar27,pXVar3,0x14);
                      if (iVar5 == 0) goto LAB_081956a8;
                      iVar5 = sk_push(*pp_Var24,pcVar27);
                      if (iVar5 == 0) goto LAB_08195509;
                      for (local_54 = 0; iVar5 = sk_num((_STACK *)local_58), local_54 < iVar5;
                          local_54 = local_54 + 1) {
                        pXVar13 = (X509 *)sk_value((_STACK *)local_58,local_54);
                        pXVar3 = (X509 *)0x0;
                        pXVar20 = (X509 *)0xffffffff;
                        X509_check_purpose(pXVar13,-1,0);
                        pcVar27 = (char *)ESS_CERT_ID_new();
                        if ((X509 *)pcVar27 == (X509 *)0x0) {
LAB_0819555b:
                          pXVar28 = (X509 *)0x0;
LAB_081954de:
                          GENERAL_NAME_free((GENERAL_NAME *)pXVar28);
                          goto LAB_081954ea;
                        }
                        pXVar20 = (X509 *)&pXVar13->rfc3779_addr;
                        pXVar3 = (X509 *)&DAT_00000014;
                        iVar5 = ASN1_OCTET_STRING_set
                                          ((ASN1_STRING *)*(X509_CINF **)pcVar27,pXVar20,0x14);
                        if (iVar5 == 0) goto LAB_0819555b;
                        if (*(X509_ALGOR **)((int)pcVar27 + 4) == (X509_ALGOR *)0x0) {
                          pXVar18 = (X509_ALGOR *)ESS_ISSUER_SERIAL_new();
                          *(X509_ALGOR **)((int)pcVar27 + 4) = pXVar18;
                          if (pXVar18 == (X509_ALGOR *)0x0) goto LAB_0819555b;
                        }
                        pXVar28 = (X509 *)GENERAL_NAME_new();
                        if (pXVar28 == (X509 *)0x0) goto LAB_0819555b;
                        pXVar28->cert_info = (X509_CINF *)0x4;
                        pXVar17 = X509_NAME_dup(pXVar13->cert_info->issuer);
                        pXVar28->sig_alg = (X509_ALGOR *)pXVar17;
                        if ((pXVar17 == (X509_NAME *)0x0) ||
                           (pXVar20 = pXVar28,
                           iVar5 = sk_push((_STACK *)(*(X509_ALGOR **)((int)pcVar27 + 4))->algorithm
                                           ,pXVar28), iVar5 == 0)) goto LAB_081954de;
                        ASN1_INTEGER_free((ASN1_INTEGER *)
                                          (*(X509_ALGOR **)((int)pcVar27 + 4))->parameter);
                        pXVar18 = *(X509_ALGOR **)((int)pcVar27 + 4);
                        pAVar23 = ASN1_INTEGER_dup(pXVar13->cert_info->serialNumber);
                        pXVar18->parameter = (ASN1_TYPE *)pAVar23;
                        if (pAVar23 == (ASN1_STRING *)0x0) goto LAB_0819555b;
                        iVar5 = sk_push(*pp_Var24,pcVar27);
                        if (iVar5 == 0) goto LAB_08195509;
                      }
                      pXVar3 = (X509 *)i2d_ESS_SIGNING_CERT
                                                 (pp_Var24,0,extraout_ECX_02,extraout_ECX_02);
                      pXVar20 = (X509 *)0x3a0;
                      pcVar27 = "ts_rsp_sign.c";
                      pXVar13 = (X509 *)CRYPTO_malloc((int)pXVar3,"ts_rsp_sign.c",0x3a0);
                      if (pXVar13 == (X509 *)0x0) {
                        ERR_put_error(0x2f,0x70,0x41,"ts_rsp_sign.c",0x3a1);
                        pAVar23 = (ASN1_STRING *)0x0;
                        pXVar3 = pXVar20;
LAB_08195601:
                        ASN1_STRING_free(pAVar23);
                        CRYPTO_free(pXVar13);
LAB_08195615:
                        pXVar13 = (X509 *)0x0;
                        ERR_put_error(0x2f,0x88,0x74,"ts_rsp_sign.c",0x307);
                      }
                      else {
                        pcVar27 = (char *)&local_3c;
                        pXVar20 = pXVar13;
                        local_3c = pXVar13;
                        i2d_ESS_SIGNING_CERT(pp_Var24,pcVar27,pXVar13,pXVar13);
                        pAVar23 = ASN1_STRING_new();
                        if ((pAVar23 == (ASN1_STRING *)0x0) ||
                           (pcVar27 = (char *)pXVar13,
                           iVar5 = ASN1_STRING_set(pAVar23,pXVar13,(int)pXVar3), pXVar20 = pXVar3,
                           iVar5 == 0)) {
                          ERR_put_error(0x2f,0x70,0x41,"ts_rsp_sign.c",0x3a7);
                          pXVar3 = pXVar20;
                          goto LAB_08195601;
                        }
                        CRYPTO_free(pXVar13);
                        iVar5 = PKCS7_add_signed_attribute(p7si,0xdf,0x10,pAVar23);
                        if (iVar5 == 0) goto LAB_08195615;
                        pXVar20 = (X509 *)PKCS7_new();
                        if (pXVar20 == (X509 *)0x0) {
LAB_0819573a:
                          ASN1_OCTET_STRING_free((ASN1_OCTET_STRING *)0x0);
                          pXVar13 = (X509 *)0x0;
                          PKCS7_free((PKCS7 *)pXVar20);
                        }
                        else {
                          prVar19 = (rsa_st *)ASN1_TYPE_new();
                          ((_union_271 *)&pXVar20->name)->rsa = prVar19;
                          if (prVar19 == (rsa_st *)0x0) goto LAB_0819573a;
                          pAVar12 = OBJ_nid2obj(0xcf);
                          pXVar20->references = (int)pAVar12;
                          pXVar13 = (X509 *)ASN1_OCTET_STRING_new();
                          if (pXVar13 == (X509 *)0x0) goto LAB_0819573a;
                          ASN1_TYPE_set((ASN1_TYPE *)((_union_271 *)&pXVar20->name)->rsa,4,pXVar13);
                          pcVar27 = (char *)pXVar20;
                          iVar5 = PKCS7_set_content(p7,(PKCS7 *)pXVar20);
                          pXVar3 = pXVar13;
                          if (iVar5 == 0) goto LAB_0819573a;
                          pcVar27 = (char *)0x0;
                          pXVar3 = extraout_EDX;
                          pXVar13 = (X509 *)PKCS7_dataInit(p7,(BIO *)0x0);
                          if (pXVar13 == (X509 *)0x0) {
                            ERR_put_error(0x2f,0x88,0x41,"ts_rsp_sign.c",0x311);
                          }
                          else {
                            pcVar27 = (char *)param_1[0x13];
                            pXVar20 = pXVar13;
                            pXVar3 = (X509 *)i2d_TS_TST_INFO_bio(pXVar13,pcVar27,pXVar13,pXVar13);
                            if (pXVar3 == (X509 *)0x0) {
                              iVar5 = 0x317;
                              pXVar3 = pXVar20;
                            }
                            else {
                              pcVar27 = (char *)pXVar13;
                              pXVar20 = pXVar3;
                              iVar5 = PKCS7_dataFinal(p7,(BIO *)pXVar13);
                              if (iVar5 != 0) {
                                TS_RESP_set_tst_info(param_1[0x12],p7,param_1[0x13],pXVar20);
                                param_1[0x13] = (X509 *)0x0;
                                BIO_free_all((BIO *)pXVar13);
                                ESS_SIGNING_CERT_free(pp_Var24);
                                PKCS7_free((PKCS7 *)0x0);
                                pXVar3 = param_1[0x12];
                                goto LAB_08194aaf;
                              }
                              iVar5 = 0x31d;
                            }
                            ERR_put_error(0x2f,0x88,0x7c,"ts_rsp_sign.c",iVar5);
                          }
                        }
                      }
                    }
LAB_0819525b:
                    ppAVar4 = (ASN1_INTEGER **)TS_RESP_get_status_info(param_1[0x12],pcVar27,pXVar3)
                    ;
                    lVar6 = ASN1_INTEGER_get(*ppAVar4);
                    if (lVar6 == 0) {
                      TS_RESP_CTX_set_status_info(param_1,2,"Error during signature generation.");
                    }
                    BIO_free_all((BIO *)pXVar13);
                    ESS_SIGNING_CERT_free(pp_Var24);
                    PKCS7_free(p7);
                    goto LAB_08194a6e;
                  }
                  a_00 = GENERAL_NAME_new();
                  if (a_00 != (GENERAL_NAME *)0x0) {
                    a_00->type = 4;
                    pXVar3 = (X509 *)X509_NAME_dup((*param_1)->cert_info->subject);
                    (a_00->d).directoryName = (X509_NAME *)pXVar3;
                    if ((pXVar3 != (X509 *)0x0) &&
                       (iVar22 = TS_TST_INFO_set_tsa(pXVar13,a_00,pXVar3,pXVar3), iVar22 != 0))
                    goto LAB_081951b5;
                  }
                  goto LAB_08194e5e;
                }
              }
            }
            else {
              uVar26 = TS_ACCURACY_new();
              pXVar3 = (X509 *)((ulonglong)uVar26 >> 0x20);
              iVar5 = (int)uVar26;
              if (iVar5 != 0) {
                uVar7 = extraout_ECX_00;
                if (param_1[6] != (X509 *)0x0) {
                  uVar26 = TS_ACCURACY_set_seconds(iVar5,param_1[6],pXVar3,pXVar3);
                  pXVar3 = (X509 *)((ulonglong)uVar26 >> 0x20);
                  uVar7 = extraout_ECX_01;
                  if ((int)uVar26 == 0) goto LAB_08195107;
                }
                if (param_1[7] != (X509 *)0x0) {
                  uVar26 = TS_ACCURACY_set_millis(iVar5,param_1[7],uVar7,uVar7);
                  pXVar3 = (X509 *)((ulonglong)uVar26 >> 0x20);
                  if ((int)uVar26 == 0) goto LAB_08195107;
                }
                pXVar20 = param_1[8];
                if (pXVar20 != (X509 *)0x0) {
                  pXVar20 = (X509 *)TS_ACCURACY_set_micros(iVar5,pXVar20,pXVar3,pXVar3);
                  if (pXVar20 == (X509 *)0x0) goto LAB_08195107;
                  pXVar28 = extraout_ECX_03;
                  if (iVar5 == 0) goto LAB_08195166;
                }
                iVar22 = TS_TST_INFO_set_accuracy(pXVar13,iVar5,pXVar20,pXVar20);
                pXVar28 = extraout_ECX_04;
                pXVar3 = pXVar20;
                if (iVar22 != 0) goto LAB_08195166;
              }
            }
LAB_08195107:
            a_00 = (GENERAL_NAME *)0x0;
            goto LAB_08194e5e;
          }
          ASN1_GENERALIZEDTIME_free(pAVar23);
        }
      }
      iVar5 = 0;
      pAVar23 = (ASN1_GENERALIZEDTIME *)0x0;
      ERR_put_error(0x2f,0x86,0x73,"ts_rsp_sign.c",0x3ff);
      a_00 = (GENERAL_NAME *)0x0;
    }
  }
LAB_08194e5e:
  TS_TST_INFO_free(pXVar13);
  ERR_put_error(0x2f,0x7b,0x7b,"ts_rsp_sign.c",0x2a3);
  TS_RESP_CTX_set_status_info_cond(param_1,2,"Error during TSTInfo generation.");
  GENERAL_NAME_free(a_00);
  TS_ACCURACY_free(iVar5);
  ASN1_GENERALIZEDTIME_free(pAVar23);
  ASN1_INTEGER_free(a_01);
  param_1[0x13] = (X509 *)0x0;
  goto LAB_08194a6e;
LAB_081951f0:
  pvVar16 = sk_value(p_Var15,iVar5);
  pXVar3 = (X509 *)0x0;
  iVar22 = (*(code *)param_1[0xf])(param_1,pvVar16,0);
  iVar5 = iVar5 + 1;
  if (iVar22 == 0) goto LAB_08194a6e;
  goto LAB_08195212;
code_r0x08194dda:
  ERR_put_error(0x2f,0x85,0x7d,"ts_rsp_sign.c",0x252);
  TS_RESP_CTX_set_status_info(param_1,2,"Requested policy is not supported.");
  iVar5 = TS_RESP_get_status_info(param_1[0x12]);
  a = *(ASN1_BIT_STRING **)(iVar5 + 8);
  if (a == (ASN1_BIT_STRING *)0x0) {
    a = ASN1_BIT_STRING_new();
    *(ASN1_BIT_STRING **)(iVar5 + 8) = a;
    if (a == (ASN1_BIT_STRING *)0x0) goto LAB_08194b94;
  }
  iVar5 = 0xf;
LAB_08194b83:
  iVar5 = ASN1_BIT_STRING_set_bit(a,iVar5,1);
  if (iVar5 != 0) goto LAB_08194a6e;
LAB_08194b94:
  ERR_put_error(0x2f,0x7c,0x41,"ts_rsp_sign.c",0x193);
LAB_08194a6e:
  ERR_put_error(0x2f,0x7a,0x79,"ts_rsp_sign.c",0x1dd);
  pXVar3 = param_1[0x12];
  if (pXVar3 != (X509 *)0x0) {
    ppAVar4 = (ASN1_INTEGER **)TS_RESP_get_status_info(pXVar3);
    lVar6 = ASN1_INTEGER_get(*ppAVar4);
    if ((lVar6 == 0) &&
       (iVar5 = TS_RESP_CTX_set_status_info(param_1,2,"Error during response generation."),
       iVar5 == 0)) {
      pXVar3 = (X509 *)0x0;
      TS_RESP_free(param_1[0x12]);
    }
    else {
      pXVar3 = param_1[0x12];
    }
  }
LAB_08194aaf:
  param_1[0x12] = (X509 *)0x0;
  TS_REQ_free(param_1[0x11]);
  param_1[0x11] = (X509 *)0x0;
  TS_RESP_free(param_1[0x12]);
  param_1[0x12] = (X509 *)0x0;
  TS_TST_INFO_free(param_1[0x13]);
  param_1[0x13] = (X509 *)0x0;
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pXVar3;
}

