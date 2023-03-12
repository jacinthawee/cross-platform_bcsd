
void TS_RESP_create_response(X509 **param_1,undefined4 param_2)

{
  char *pcVar1;
  X509 *pXVar2;
  ASN1_INTEGER **ppAVar3;
  int iVar4;
  long lVar5;
  ASN1_BIT_STRING *pAVar6;
  undefined4 uVar7;
  ASN1_OBJECT **ppAVar8;
  int iVar9;
  int iVar10;
  EVP_MD *pEVar11;
  int *piVar12;
  ASN1_OBJECT *pAVar13;
  X509 *pXVar14;
  X509 *pXVar15;
  X509 *s;
  tm *ptVar16;
  X509 *a;
  X509 *pXVar17;
  _STACK *p_Var18;
  void *pvVar19;
  BIO *p7;
  BIO *p7si;
  BIO *bio;
  BIO *pBVar20;
  ASN1_STRING **data;
  ASN1_STRING *pAVar21;
  GENERAL_NAME *a_00;
  X509_NAME *pXVar22;
  PKCS7 *p7_data;
  ASN1_TYPE *pAVar23;
  ASN1_OCTET_STRING *value;
  BIO_METHOD *pBVar24;
  size_t sVar25;
  char *pcVar26;
  X509_CINF *pXVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  ASN1_STRING *pAVar31;
  ASN1_STRING *local_50;
  undefined4 local_4c;
  ASN1_STRING *local_48;
  char acStack_44 [24];
  int local_2c;
  
  local_2c = __TMC_END__;
  param_1[0x11] = (X509 *)0x0;
  param_1[0x12] = (X509 *)0x0;
  param_1[0x13] = (X509 *)0x0;
  pXVar2 = (X509 *)TS_RESP_new();
  param_1[0x12] = pXVar2;
  if (pXVar2 == (X509 *)0x0) {
    ERR_put_error(0x2f,0x7a,0x41,"ts_rsp_sign.c",0x1ad);
    goto LAB_000eb226;
  }
  pXVar2 = (X509 *)d2i_TS_REQ_bio(param_2,0);
  param_1[0x11] = pXVar2;
  if (pXVar2 == (X509 *)0x0) {
    pcVar26 = "Bad request format or system error.";
LAB_000eb32e:
    TS_RESP_CTX_set_status_info(param_1,2,pcVar26);
    iVar4 = TS_RESP_get_status_info(param_1[0x12]);
    pAVar6 = *(ASN1_BIT_STRING **)(iVar4 + 8);
    if (pAVar6 == (ASN1_BIT_STRING *)0x0) {
      pAVar6 = ASN1_BIT_STRING_new();
      *(ASN1_BIT_STRING **)(iVar4 + 8) = pAVar6;
      if (pAVar6 == (ASN1_BIT_STRING *)0x0) goto LAB_000eb2d2;
    }
    iVar4 = ASN1_BIT_STRING_set_bit(pAVar6,5,1);
    goto joined_r0x000eb34c;
  }
  ppAVar3 = (ASN1_INTEGER **)TS_STATUS_INFO_new();
  if (((ppAVar3 == (ASN1_INTEGER **)0x0) || (iVar4 = ASN1_INTEGER_set(*ppAVar3,0), iVar4 == 0)) ||
     (iVar4 = TS_RESP_set_status_info(param_1[0x12],ppAVar3), iVar4 == 0)) {
    ERR_put_error(0x2f,0x84,0x41,"ts_rsp_sign.c",0x16e);
    TS_STATUS_INFO_free(ppAVar3);
    ASN1_UTF8STRING_free((ASN1_UTF8STRING *)0x0);
    goto LAB_000eb226;
  }
  TS_STATUS_INFO_free(ppAVar3);
  ASN1_UTF8STRING_free((ASN1_UTF8STRING *)0x0);
  pXVar2 = param_1[0x11];
  iVar4 = TS_REQ_get_version(pXVar2);
  if (iVar4 == 1) {
    uVar7 = TS_REQ_get_msg_imprint(pXVar2);
    ppAVar8 = (ASN1_OBJECT **)TS_MSG_IMPRINT_get_algo();
    iVar9 = OBJ_obj2nid(*ppAVar8);
    while( true ) {
      iVar10 = sk_num((_STACK *)param_1[5]);
      if (iVar10 <= iVar4 + -1) break;
      pEVar11 = (EVP_MD *)sk_value((_STACK *)param_1[5],iVar4 + -1);
      iVar10 = EVP_MD_type(pEVar11);
      if ((iVar9 == iVar10) && (pEVar11 != (EVP_MD *)0x0)) {
        if ((ppAVar8[1] != (ASN1_OBJECT *)0x0) &&
           (iVar4 = ASN1_TYPE_get((ASN1_TYPE *)ppAVar8[1]), iVar4 != 5)) {
          pcVar26 = "Superfluous message digest parameter.";
          goto LAB_000eb3ce;
        }
        piVar12 = (int *)TS_MSG_IMPRINT_get_msg(uVar7);
        iVar9 = *piVar12;
        iVar4 = EVP_MD_size(pEVar11);
        if (iVar9 != iVar4) {
          pcVar26 = "Bad message digest.";
          goto LAB_000eb32e;
        }
        pAVar13 = (ASN1_OBJECT *)TS_REQ_get_policy_id(param_1[0x11]);
        pXVar2 = param_1[4];
        if (pXVar2 == (X509 *)0x0) {
          ERR_put_error(0x2f,0x85,0x66,"ts_rsp_sign.c",0x240);
          goto LAB_000eb226;
        }
        if ((pAVar13 == (ASN1_OBJECT *)0x0) ||
           ((iVar4 = OBJ_cmp(pAVar13,(ASN1_OBJECT *)pXVar2), iVar4 == 0 &&
            (pXVar2 = param_1[4], pXVar2 != (X509 *)0x0)))) goto LAB_000eb49c;
        iVar4 = 1;
        goto LAB_000eb44a;
      }
      iVar4 = iVar4 + 1;
    }
    pcVar26 = "Message digest algorithm is not supported.";
LAB_000eb3ce:
    TS_RESP_CTX_set_status_info(param_1,2,pcVar26);
    iVar4 = TS_RESP_get_status_info(param_1[0x12]);
    pAVar6 = *(ASN1_BIT_STRING **)(iVar4 + 8);
    if (pAVar6 == (ASN1_BIT_STRING *)0x0) {
      pAVar6 = ASN1_BIT_STRING_new();
      *(ASN1_BIT_STRING **)(iVar4 + 8) = pAVar6;
      if (pAVar6 == (ASN1_BIT_STRING *)0x0) goto LAB_000eb2d2;
    }
    iVar4 = ASN1_BIT_STRING_set_bit(pAVar6,0,1);
    goto joined_r0x000eb34c;
  }
  TS_RESP_CTX_set_status_info(param_1,2,"Bad request version.");
  iVar4 = TS_RESP_get_status_info(param_1[0x12]);
  pAVar6 = *(ASN1_BIT_STRING **)(iVar4 + 8);
  if (pAVar6 != (ASN1_BIT_STRING *)0x0) {
LAB_000eb2c6:
    iVar4 = ASN1_BIT_STRING_set_bit(pAVar6,2,1);
    goto joined_r0x000eb34c;
  }
  pAVar6 = ASN1_BIT_STRING_new();
  *(ASN1_BIT_STRING **)(iVar4 + 8) = pAVar6;
  if (pAVar6 != (ASN1_BIT_STRING *)0x0) goto LAB_000eb2c6;
  goto LAB_000eb2d2;
LAB_000eb44a:
  iVar9 = sk_num((_STACK *)param_1[3]);
  if (iVar9 <= iVar4 + -1) goto code_r0x000eb456;
  pXVar2 = (X509 *)sk_value((_STACK *)param_1[3],iVar4 + -1);
  iVar9 = OBJ_cmp(pAVar13,(ASN1_OBJECT *)pXVar2);
  if ((iVar9 == 0) && (pXVar2 != (X509 *)0x0)) goto LAB_000eb49c;
  iVar4 = iVar4 + 1;
  goto LAB_000eb44a;
LAB_000eb49c:
  pXVar14 = (X509 *)TS_TST_INFO_new();
  pXVar15 = pXVar14;
  a = pXVar14;
  pXVar17 = pXVar14;
  s = pXVar14;
  if (pXVar14 != (X509 *)0x0) {
    iVar4 = TS_TST_INFO_set_version(pXVar14,1);
    if ((((iVar4 == 0) || (iVar4 = TS_TST_INFO_set_policy_id(pXVar14,pXVar2), iVar4 == 0)) ||
        (iVar4 = TS_TST_INFO_set_msg_imprint(pXVar14,param_1[0x11]->sig_alg), iVar4 == 0)) ||
       (pXVar15 = (X509 *)(*(code *)param_1[0xb])(param_1,param_1[0xc]), pXVar15 == (X509 *)0x0)) {
      pXVar15 = (X509 *)0x0;
      a = (X509 *)0x0;
      pXVar17 = (X509 *)0x0;
      s = (X509 *)0x0;
    }
    else {
      s = (X509 *)TS_TST_INFO_set_serial(pXVar14,pXVar15);
      a = s;
      pXVar17 = s;
      if ((s != (X509 *)0x0) &&
         (s = (X509 *)(*(code *)param_1[0xd])(param_1,param_1[0xe],&local_50,&local_4c), a = s,
         pXVar17 = s, s != (X509 *)0x0)) {
        pXVar2 = param_1[9];
        local_48 = local_50;
        if ((pXVar2 < (X509 *)0x7) && (ptVar16 = gmtime((time_t *)&local_48), ptVar16 != (tm *)0x0))
        {
          iVar9 = ptVar16->tm_mon + 1;
          iVar10 = ptVar16->tm_mday;
          iVar28 = ptVar16->tm_hour;
          iVar29 = ptVar16->tm_min;
          iVar30 = ptVar16->tm_sec;
          iVar4 = BIO_snprintf(acStack_44,0x17,"%04d%02d%02d%02d%02d%02d",ptVar16->tm_year + 0x76c,
                               iVar9,iVar10,iVar28,iVar29,iVar30);
          pcVar26 = acStack_44 + iVar4;
          if (pXVar2 != (X509 *)0x0) {
            BIO_snprintf(pcVar26,(size_t)((int)&pXVar2->cert_info + 2),".%ld",local_4c,iVar9,iVar10,
                         iVar28,iVar29,iVar30);
            sVar25 = strlen(pcVar26);
            pcVar1 = pcVar26 + sVar25;
            do {
              pcVar26 = pcVar1;
              pcVar1 = pcVar26 + -1;
            } while (pcVar26[-1] == '0');
            if (pcVar26[-1] == '.') {
              pcVar26 = pcVar26 + -1;
            }
          }
          *pcVar26 = 'Z';
          pcVar26[1] = '\0';
          s = (X509 *)ASN1_STRING_type_new(0x18);
          if (s != (X509 *)0x0) {
            iVar4 = ASN1_GENERALIZEDTIME_set_string((ASN1_GENERALIZEDTIME *)s,acStack_44);
            if (iVar4 != 0) {
              a = (X509 *)TS_TST_INFO_set_time(pXVar14,s);
              pXVar17 = a;
              if (((a != (X509 *)0x0) &&
                  (((((param_1[6] == (X509 *)0x0 && (param_1[7] == (X509 *)0x0)) &&
                     (pXVar17 = param_1[8], pXVar17 == (X509 *)0x0)) ||
                    ((((pXVar17 = (X509 *)TS_ACCURACY_new(), a = pXVar17, pXVar17 != (X509 *)0x0 &&
                       ((param_1[6] == (X509 *)0x0 ||
                        (a = (X509 *)TS_ACCURACY_set_seconds(), a != (X509 *)0x0)))) &&
                      ((param_1[7] == (X509 *)0x0 ||
                       (a = (X509 *)TS_ACCURACY_set_millis(pXVar17), a != (X509 *)0x0)))) &&
                     ((param_1[8] == (X509 *)0x0 ||
                      (a = (X509 *)TS_ACCURACY_set_micros(pXVar17), a != (X509 *)0x0)))))) &&
                   (((pXVar17 == (X509 *)0x0 ||
                     (a = (X509 *)TS_TST_INFO_set_accuracy(pXVar14,pXVar17), a != (X509 *)0x0)) &&
                    ((-1 < (int)param_1[10] << 0x1e ||
                     (a = (X509 *)TS_TST_INFO_set_ordering(pXVar14,1), a != (X509 *)0x0)))))))) &&
                 ((iVar4 = TS_REQ_get_nonce(param_1[0x11]), iVar4 == 0 ||
                  (a = (X509 *)TS_TST_INFO_set_nonce(pXVar14,iVar4), a != (X509 *)0x0)))) {
                a = (X509 *)((uint)param_1[10] & 1);
                if (a == (X509 *)0x0) {
LAB_000eb6d6:
                  iVar4 = 0;
                  GENERAL_NAME_free((GENERAL_NAME *)a);
                  TS_ACCURACY_free(pXVar17);
                  ASN1_GENERALIZEDTIME_free((ASN1_GENERALIZEDTIME *)s);
                  ASN1_INTEGER_free((ASN1_INTEGER *)pXVar15);
                  param_1[0x13] = pXVar14;
                  p_Var18 = (_STACK *)TS_REQ_get_exts(param_1[0x11]);
LAB_000eb718:
                  iVar9 = sk_num(p_Var18);
                  if (iVar4 < iVar9) goto LAB_000eb6fe;
                  p7 = (BIO *)X509_check_private_key(*param_1,(EVP_PKEY *)param_1[1]);
                  if (p7 == (BIO *)0x0) {
                    ERR_put_error(0x2f,0x88,0x78,"ts_rsp_sign.c",0x2d2);
                    p7si = p7;
                    bio = p7;
                    goto LAB_000eb74a;
                  }
                  p7 = (BIO *)PKCS7_new();
                  if (p7 == (BIO *)0x0) {
                    ERR_put_error(0x2f,0x88,0x41,"ts_rsp_sign.c",0x2d8);
                    p7si = p7;
                    bio = p7;
                    goto LAB_000eb74a;
                  }
                  p7si = (BIO *)PKCS7_set_type((PKCS7 *)p7,0x16);
                  bio = p7si;
                  if ((p7si == (BIO *)0x0) ||
                     (p7si = (BIO *)ASN1_INTEGER_set(((_union_444 *)&p7->flags)->sign->version,3),
                     bio = p7si, p7si == (BIO *)0x0)) goto LAB_000eb74a;
                  iVar4 = TS_REQ_get_cert_req(param_1[0x11]);
                  if ((iVar4 != 0) &&
                     (PKCS7_add_certificate((PKCS7 *)p7,*param_1), param_1[2] != (X509 *)0x0)) {
                    for (iVar4 = 0; iVar9 = sk_num((_STACK *)param_1[2]), iVar4 < iVar9;
                        iVar4 = iVar4 + 1) {
                      pXVar2 = (X509 *)sk_value((_STACK *)param_1[2],iVar4);
                      PKCS7_add_certificate((PKCS7 *)p7,pXVar2);
                    }
                  }
                  pXVar15 = *param_1;
                  pXVar2 = param_1[1];
                  pEVar11 = EVP_sha1();
                  p7si = (BIO *)PKCS7_add_signature((PKCS7 *)p7,pXVar15,(EVP_PKEY *)pXVar2,pEVar11);
                  if (p7si == (BIO *)0x0) {
                    ERR_put_error(0x2f,0x88,0x76,"ts_rsp_sign.c",0x2f2);
                    bio = p7si;
                  }
                  else {
                    pAVar13 = OBJ_nid2obj(0xcf);
                    bio = (BIO *)PKCS7_add_signed_attribute
                                           ((PKCS7_SIGNER_INFO *)p7si,0x32,6,pAVar13);
                    if (bio == (BIO *)0x0) {
                      ERR_put_error(0x2f,0x88,0x77,"ts_rsp_sign.c",0x2fb);
                      p7si = bio;
                    }
                    else {
                      pXVar15 = *param_1;
                      pXVar2 = (X509 *)((uint)param_1[10] & 4);
                      if (pXVar2 != (X509 *)0x0) {
                        pXVar2 = param_1[2];
                      }
                      pBVar20 = (BIO *)ESS_SIGNING_CERT_new();
                      if (pBVar20 != (BIO *)0x0) {
                        if (pBVar20->method == (BIO_METHOD *)0x0) {
                          pBVar24 = (BIO_METHOD *)sk_new_null();
                          pBVar20->method = pBVar24;
                          if (pBVar24 == (BIO_METHOD *)0x0) goto LAB_000eb910;
                        }
                        X509_check_purpose(pXVar15,-1,0);
                        data = (ASN1_STRING **)ESS_CERT_ID_new();
                        if ((data == (ASN1_STRING **)0x0) ||
                           (iVar4 = ASN1_OCTET_STRING_set(*data,&pXVar15->rfc3779_addr,0x14),
                           iVar4 == 0)) {
                          a_00 = (GENERAL_NAME *)0x0;
LAB_000eb8ee:
                          GENERAL_NAME_free(a_00);
                          ESS_CERT_ID_free(data);
                          ERR_put_error(0x2f,0x71,0x41,"ts_rsp_sign.c",0x37b);
                        }
                        else {
                          iVar4 = sk_push((_STACK *)pBVar20->method,data);
                          if (iVar4 != 0) {
                            iVar4 = 0;
                            do {
                              iVar9 = sk_num((_STACK *)pXVar2);
                              if (iVar9 <= iVar4) {
                                iVar4 = i2d_ESS_SIGNING_CERT(pBVar20,0);
                                pAVar21 = (ASN1_STRING *)CRYPTO_malloc(iVar4,"ts_rsp_sign.c",0x39d);
                                if (pAVar21 == (ASN1_STRING *)0x0) {
                                  ERR_put_error(0x2f,0x70,0x41,"ts_rsp_sign.c",0x39f);
                                  pAVar31 = pAVar21;
LAB_000eb9bc:
                                  ASN1_STRING_free(pAVar31);
                                  CRYPTO_free(pAVar21);
                                }
                                else {
                                  local_48 = pAVar21;
                                  i2d_ESS_SIGNING_CERT(pBVar20,&local_48);
                                  pAVar31 = ASN1_STRING_new();
                                  if ((pAVar31 == (ASN1_STRING *)0x0) ||
                                     (iVar4 = ASN1_STRING_set(pAVar31,pAVar21,iVar4), iVar4 == 0)) {
                                    ERR_put_error(0x2f,0x70,0x41,"ts_rsp_sign.c",0x3a6);
                                    goto LAB_000eb9bc;
                                  }
                                  CRYPTO_free(pAVar21);
                                  iVar4 = PKCS7_add_signed_attribute
                                                    ((PKCS7_SIGNER_INFO *)p7si,0xdf,0x10,pAVar31);
                                  if (iVar4 != 0) {
                                    p7_data = PKCS7_new();
                                    if (p7_data != (PKCS7 *)0x0) {
                                      pAVar23 = ASN1_TYPE_new();
                                      (p7_data->d).other = pAVar23;
                                      if (pAVar23 != (ASN1_TYPE *)0x0) {
                                        pAVar13 = OBJ_nid2obj(0xcf);
                                        p7_data->type = pAVar13;
                                        value = ASN1_OCTET_STRING_new();
                                        if (value != (ASN1_OCTET_STRING *)0x0) {
                                          ASN1_TYPE_set((p7_data->d).other,4,value);
                                          iVar4 = PKCS7_set_content((PKCS7 *)p7,p7_data);
                                          if (iVar4 != 0) {
                                            bio = PKCS7_dataInit((PKCS7 *)p7,(BIO *)0x0);
                                            if (bio == (BIO *)0x0) {
                                              ERR_put_error(0x2f,0x88,0x41,"ts_rsp_sign.c",0x311);
                                              p7si = pBVar20;
                                            }
                                            else {
                                              iVar4 = i2d_TS_TST_INFO_bio(bio,param_1[0x13]);
                                              if (iVar4 == 0) {
                                                iVar4 = 0x318;
                                              }
                                              else {
                                                iVar4 = PKCS7_dataFinal((PKCS7 *)p7,bio);
                                                if (iVar4 != 0) {
                                                  TS_RESP_set_tst_info
                                                            (param_1[0x12],p7,param_1[0x13]);
                                                  param_1[0x13] = (X509 *)0x0;
                                                  BIO_free_all(bio);
                                                  ESS_SIGNING_CERT_free(pBVar20);
                                                  PKCS7_free((PKCS7 *)0x0);
                                                  pXVar2 = param_1[0x12];
                                                  goto LAB_000eb254;
                                                }
                                                iVar4 = 799;
                                              }
                                              ERR_put_error(0x2f,0x88,0x7c,"ts_rsp_sign.c",iVar4);
                                              p7si = pBVar20;
                                            }
                                            goto LAB_000eb74a;
                                          }
                                        }
                                      }
                                    }
                                    ASN1_OCTET_STRING_free((ASN1_OCTET_STRING *)0x0);
                                    PKCS7_free(p7_data);
                                    p7si = pBVar20;
                                    bio = (BIO *)0x0;
                                    goto LAB_000eb74a;
                                  }
                                }
                                ERR_put_error(0x2f,0x88,0x74,"ts_rsp_sign.c",0x308);
                                p7si = pBVar20;
                                bio = (BIO *)0x0;
                                goto LAB_000eb74a;
                              }
                              pXVar15 = (X509 *)sk_value((_STACK *)pXVar2,iVar4);
                              X509_check_purpose(pXVar15,-1,0);
                              data = (ASN1_STRING **)ESS_CERT_ID_new();
                              if ((data == (ASN1_STRING **)0x0) ||
                                 (iVar9 = ASN1_OCTET_STRING_set(*data,&pXVar15->rfc3779_addr,0x14),
                                 iVar9 == 0)) {
LAB_000eb95e:
                                a_00 = (GENERAL_NAME *)0x0;
                                goto LAB_000eb8ee;
                              }
                              if (data[1] == (ASN1_STRING *)0x0) {
                                pAVar21 = (ASN1_STRING *)ESS_ISSUER_SERIAL_new();
                                data[1] = pAVar21;
                                if (pAVar21 == (ASN1_STRING *)0x0) goto LAB_000eb95e;
                              }
                              a_00 = GENERAL_NAME_new();
                              if (a_00 == (GENERAL_NAME *)0x0) goto LAB_000eb95e;
                              pXVar27 = pXVar15->cert_info;
                              a_00->type = 4;
                              pXVar22 = X509_NAME_dup(pXVar27->issuer);
                              (a_00->d).directoryName = pXVar22;
                              if ((pXVar22 == (X509_NAME *)0x0) ||
                                 (iVar9 = sk_push((_STACK *)data[1]->length,a_00), iVar9 == 0))
                              goto LAB_000eb8ee;
                              ASN1_INTEGER_free((ASN1_INTEGER *)data[1]->type);
                              pAVar31 = data[1];
                              pAVar21 = ASN1_INTEGER_dup(pXVar15->cert_info->serialNumber);
                              pAVar31->type = (int)pAVar21;
                              if (pAVar21 == (ASN1_STRING *)0x0) goto LAB_000eb95e;
                              iVar9 = sk_push((_STACK *)pBVar20->method,data);
                              if (iVar9 == 0) break;
                              iVar4 = iVar4 + 1;
                            } while( true );
                          }
                        }
                      }
LAB_000eb910:
                      ESS_SIGNING_CERT_free(pBVar20);
                      ERR_put_error(0x2f,0x72,0x41,"ts_rsp_sign.c",0x350);
                      p7si = (BIO *)0x0;
                      bio = (BIO *)0x0;
                    }
                  }
LAB_000eb74a:
                  ppAVar3 = (ASN1_INTEGER **)TS_RESP_get_status_info(param_1[0x12]);
                  lVar5 = ASN1_INTEGER_get(*ppAVar3);
                  if (lVar5 == 0) {
                    TS_RESP_CTX_set_status_info(param_1,2,"Error during signature generation.");
                  }
                  BIO_free_all(bio);
                  ESS_SIGNING_CERT_free(p7si);
                  PKCS7_free((PKCS7 *)p7);
                  goto LAB_000eb226;
                }
                a = (X509 *)GENERAL_NAME_new();
                if (a != (X509 *)0x0) {
                  pXVar2 = *param_1;
                  a->cert_info = (X509_CINF *)0x4;
                  pXVar22 = X509_NAME_dup(pXVar2->cert_info->subject);
                  a->sig_alg = (X509_ALGOR *)pXVar22;
                  if ((pXVar22 != (X509_NAME *)0x0) &&
                     (iVar4 = TS_TST_INFO_set_tsa(pXVar14,a), iVar4 != 0)) goto LAB_000eb6d6;
                }
              }
              goto LAB_000eb4b4;
            }
            ASN1_GENERALIZEDTIME_free((ASN1_GENERALIZEDTIME *)s);
          }
        }
        ERR_put_error(0x2f,0x86,0x73,"ts_rsp_sign.c",0x3fa);
        a = (X509 *)0x0;
        pXVar17 = (X509 *)0x0;
        s = (X509 *)0x0;
      }
    }
  }
LAB_000eb4b4:
  TS_TST_INFO_free(pXVar14);
  ERR_put_error(0x2f,0x7b,0x7b,"ts_rsp_sign.c",0x29f);
  ppAVar3 = (ASN1_INTEGER **)TS_RESP_get_status_info(param_1[0x12]);
  lVar5 = ASN1_INTEGER_get(*ppAVar3);
  if (lVar5 == 0) {
    TS_RESP_CTX_set_status_info(param_1,2,"Error during TSTInfo generation.");
  }
  GENERAL_NAME_free((GENERAL_NAME *)a);
  TS_ACCURACY_free(pXVar17);
  ASN1_GENERALIZEDTIME_free((ASN1_GENERALIZEDTIME *)s);
  ASN1_INTEGER_free((ASN1_INTEGER *)pXVar15);
  param_1[0x13] = (X509 *)0x0;
  goto LAB_000eb226;
LAB_000eb6fe:
  pvVar19 = sk_value(p_Var18,iVar4);
  iVar4 = iVar4 + 1;
  iVar9 = (*(code *)param_1[0xf])(param_1,pvVar19,0);
  if (iVar9 == 0) goto LAB_000eb226;
  goto LAB_000eb718;
code_r0x000eb456:
  ERR_put_error(0x2f,0x85,0x7d,"ts_rsp_sign.c",0x251);
  TS_RESP_CTX_set_status_info(param_1,2,"Requested policy is not supported.");
  iVar4 = TS_RESP_get_status_info(param_1[0x12]);
  pAVar6 = *(ASN1_BIT_STRING **)(iVar4 + 8);
  if (pAVar6 == (ASN1_BIT_STRING *)0x0) {
    pAVar6 = ASN1_BIT_STRING_new();
    *(ASN1_BIT_STRING **)(iVar4 + 8) = pAVar6;
    if (pAVar6 == (ASN1_BIT_STRING *)0x0) goto LAB_000eb2d2;
  }
  iVar4 = ASN1_BIT_STRING_set_bit(pAVar6,0xf,1);
joined_r0x000eb34c:
  if (iVar4 != 0) goto LAB_000eb226;
LAB_000eb2d2:
  ERR_put_error(0x2f,0x7c,0x41,"ts_rsp_sign.c",0x18b);
LAB_000eb226:
  ERR_put_error(0x2f,0x7a,0x79,"ts_rsp_sign.c",0x1d4);
  pXVar2 = param_1[0x12];
  if (pXVar2 != (X509 *)0x0) {
    ppAVar3 = (ASN1_INTEGER **)TS_RESP_get_status_info(pXVar2);
    lVar5 = ASN1_INTEGER_get(*ppAVar3);
    if ((lVar5 == 0) &&
       (pXVar2 = (X509 *)TS_RESP_CTX_set_status_info(param_1,2,"Error during response generation."),
       pXVar2 == (X509 *)0x0)) {
      TS_RESP_free(param_1[0x12]);
    }
    else {
      pXVar2 = param_1[0x12];
    }
  }
LAB_000eb254:
  param_1[0x12] = (X509 *)0x0;
  TS_REQ_free(param_1[0x11]);
  param_1[0x11] = (X509 *)0x0;
  TS_RESP_free(param_1[0x12]);
  param_1[0x12] = (X509 *)0x0;
  TS_TST_INFO_free(param_1[0x13]);
  iVar4 = __TMC_END__;
  param_1[0x13] = (X509 *)0x0;
  if (local_2c == iVar4) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pXVar2);
}

