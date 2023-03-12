
undefined4
ssl_parse_clienthello_tlsext(SSL *param_1,uchar **param_2,uchar *param_3,undefined4 *param_4)

{
  uchar uVar1;
  uchar uVar2;
  byte bVar3;
  short sVar4;
  bool bVar5;
  bool bVar6;
  void *pvVar7;
  size_t sVar8;
  int iVar9;
  uint uVar10;
  stack_st_SRTP_PROTECTION_PROFILE *psVar11;
  BIO *__dest;
  _STACK *p_Var12;
  OCSP_RESPID *a;
  X509_EXTENSIONS *pXVar13;
  int iVar14;
  SRTP_PROTECTION_PROFILE *pSVar15;
  ssl3_state_st *psVar16;
  byte *__s2;
  uchar *puVar17;
  uint num;
  uchar *puVar18;
  uint uVar19;
  uint len;
  char *pcVar20;
  uchar *puVar21;
  undefined4 uVar22;
  char *pcVar23;
  SSL_SESSION *pSVar24;
  uchar *local_2c [2];
  
  psVar16 = param_1->s3;
  pSVar15 = param_1->srtp_profile;
  iVar14 = param_1->references;
  puVar17 = *param_2;
  param_1->servername_done = -1;
  param_1->tlsext_hostname = (char *)0x0;
  psVar16->next_proto_neg_seen = 0;
  param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)pSVar15 & 0xfffffffc);
  if (((iVar14 << 0x19 < 0) && (2 < (int)param_3 - (int)puVar17)) &&
     (3 < (int)param_3 - (int)(puVar17 + 2))) {
    if (CONCAT11(puVar17[2],puVar17[3]) == 0) {
      if ((int)(uint)CONCAT11(puVar17[4],puVar17[5]) <= (int)param_3 - (int)(puVar17 + 6)) {
        puVar21 = puVar17 + 6 + CONCAT11(puVar17[4],puVar17[5]);
        if ((param_1->first_packet >> 8 == 3) && (0x302 < param_1->first_packet)) {
          if (((int)param_3 - (int)puVar21 == 0x22) &&
             (iVar14 = memcmp(puVar21,PTR_kSafariExtensionsBlock_20244_000546ec,0x12), iVar14 == 0))
          {
            iVar14 = memcmp(puVar21 + 0x12,PTR_kSafariTLS12ExtensionsBlock_20245_000546f0,0x10);
joined_r0x000540a4:
            if (iVar14 == 0) {
              *(undefined *)&psVar16[1].flags = 1;
            }
          }
        }
        else if ((int)param_3 - (int)puVar21 == 0x12) {
          iVar14 = memcmp(puVar21,PTR_kSafariExtensionsBlock_20244_000543b4,0x12);
          goto joined_r0x000540a4;
        }
      }
    }
  }
  if (param_1[1].rbio != (BIO *)0x0) {
    CRYPTO_free(param_1[1].rbio);
    param_1[1].rbio = (BIO *)0x0;
  }
  param_1->srtp_profiles = (stack_st_SRTP_PROTECTION_PROFILE *)0x0;
  if (puVar17 == param_3) {
LAB_0005428a:
    if ((param_1->tlsext_hb_seq != 0) && ((param_1->references & 0x40000U) == 0)) {
      *param_4 = 0x28;
      ERR_put_error(0x14,0x12e,0x152,"t1_lib.c",0x58e);
      return 0;
    }
LAB_0005429a:
    uVar22 = 1;
  }
  else {
    if (1 < (int)param_3 - (int)puVar17) {
      puVar21 = puVar17 + 2;
      if ((int)param_3 - (int)puVar21 == (uint)CONCAT11(*puVar17,puVar17[1])) {
        if ((int)param_3 - (int)puVar21 < 4) {
          bVar5 = false;
LAB_0005427a:
          if (puVar21 == param_3) {
            *param_2 = puVar21;
            if (!bVar5) goto LAB_0005428a;
            goto LAB_0005429a;
          }
        }
        else {
          puVar18 = puVar17 + 6;
          num = (uint)CONCAT11(puVar17[4],puVar17[5]);
          sVar4 = CONCAT11(puVar17[2],puVar17[3]);
          if ((int)num <= (int)param_3 - (int)puVar18) {
            bVar6 = false;
            bVar5 = false;
            do {
              if ((code *)param_1->max_send_fragment != (code *)0x0) {
                (*(code *)param_1->max_send_fragment)
                          (param_1,0,sVar4,puVar18,num,param_1->tlsext_debug_cb);
              }
              if (sVar4 == 0) {
                if (num < 2) break;
                num = num - 2 & 0xffff;
                uVar19 = (uint)CONCAT11(puVar21[4],puVar21[5]);
                if (num < uVar19) break;
                if (3 < uVar19) {
                  iVar14 = uVar19 - 3;
                  bVar3 = puVar21[6];
                  uVar19 = (uint)CONCAT11(puVar21[7],puVar21[8]);
                  if (iVar14 < (int)uVar19) break;
                  pcVar20 = param_1->tlsext_hostname;
                  __s2 = puVar21 + 9;
                  while( true ) {
                    pcVar23 = (char *)(uint)bVar3;
                    if ((pcVar20 == (char *)0x0) && (pcVar23 == (char *)0x0)) {
                      if (param_1->hit == 0) {
                        pSVar24 = param_1->session;
                        if (*(int *)(pSVar24->krb5_client_princ + 0x40) != 0) goto LAB_00054044;
                        if (0xff < uVar19) {
                          *param_4 = 0x70;
                          return 0;
                        }
                        pvVar7 = CRYPTO_malloc(uVar19 + 1,"t1_lib.c",1099);
                        *(void **)(pSVar24->krb5_client_princ + 0x40) = pvVar7;
                        if (pvVar7 == (void *)0x0) goto LAB_000544aa;
                        memcpy(*(void **)(param_1->session->krb5_client_princ + 0x40),__s2,uVar19);
                        *(undefined *)
                         (*(int *)(param_1->session->krb5_client_princ + 0x40) + uVar19) = 0;
                        pcVar20 = *(char **)(param_1->session->krb5_client_princ + 0x40);
                        sVar8 = strlen(pcVar20);
                        if (uVar19 != sVar8) {
                          CRYPTO_free(pcVar20);
                          *(undefined4 *)(param_1->session->krb5_client_princ + 0x40) = 0;
                          *param_4 = 0x70;
                          return 0;
                        }
                        param_1->tlsext_hostname = (char *)0x1;
                        pcVar20 = (char *)0x1;
                      }
                      else {
                        pcVar20 = *(char **)(param_1->session->krb5_client_princ + 0x40);
                        if ((pcVar20 != (char *)0x0) && (sVar8 = strlen(pcVar20), sVar8 == uVar19))
                        {
                          iVar9 = strncmp(pcVar20,(char *)__s2,uVar19);
                          uVar10 = count_leading_zeroes(iVar9);
                          pcVar23 = (char *)(uVar10 >> 5);
                        }
                        param_1->tlsext_hostname = pcVar23;
                        pcVar20 = pcVar23;
                      }
                    }
                    uVar19 = iVar14 - uVar19;
                    if ((int)uVar19 < 4) break;
                    iVar14 = uVar19 - 3;
                    bVar3 = *__s2;
                    uVar19 = (uint)CONCAT11(__s2[1],__s2[2]);
                    __s2 = __s2 + 3;
                    if (iVar14 < (int)uVar19) goto LAB_00054044;
                  }
                }
                if (uVar19 != 0) break;
                puVar18 = puVar21 + 6;
              }
              else if (sVar4 == 0xc) {
                if (((num == 0) || (uVar19 = (uint)puVar21[4], uVar19 != num - 1)) ||
                   (param_1[1].rbio != (BIO *)0x0)) break;
                __dest = (BIO *)CRYPTO_malloc(num,"t1_lib.c",0x471);
                param_1[1].rbio = __dest;
                if (__dest == (BIO *)0x0) {
                  return 0xffffffff;
                }
                memcpy(__dest,puVar21 + 5,uVar19);
                *(undefined *)((int)&(param_1[1].rbio)->method + uVar19) = 0;
                sVar8 = strlen((char *)param_1[1].rbio);
                if (uVar19 != sVar8) break;
              }
              else if (sVar4 == 0xb) {
                uVar19 = (uint)puVar21[4];
                if (num - 1 != uVar19) break;
                if (param_1->hit == 0) {
                  pSVar24 = param_1->session;
                  if (*(void **)(pSVar24->krb5_client_princ + 0x48) != (void *)0x0) {
                    CRYPTO_free(*(void **)(pSVar24->krb5_client_princ + 0x48));
                    pSVar24 = param_1->session;
                    *(undefined4 *)(pSVar24->krb5_client_princ + 0x48) = 0;
                  }
                  *(undefined4 *)(pSVar24->krb5_client_princ + 0x44) = 0;
                  pvVar7 = CRYPTO_malloc(num - 1,"t1_lib.c",0x489);
                  *(void **)(pSVar24->krb5_client_princ + 0x48) = pvVar7;
                  if (pvVar7 == (void *)0x0) goto LAB_000544aa;
                  pSVar24 = param_1->session;
                  *(uint *)(pSVar24->krb5_client_princ + 0x44) = uVar19;
                  memcpy(*(void **)(pSVar24->krb5_client_princ + 0x48),puVar21 + 5,uVar19);
                }
              }
              else if (sVar4 == 10) {
                sVar8 = num - 2;
                if (((sVar8 != (uint)puVar21[5] + (uint)puVar21[4] * 0x100) || (sVar8 == 0)) ||
                   ((int)(num * -0x80000000) < 0)) break;
                if (param_1->hit == 0) {
                  pSVar24 = param_1->session;
                  if (*(int *)(pSVar24->krb5_client_princ + 0x50) != 0) break;
                  *(undefined4 *)(pSVar24->krb5_client_princ + 0x4c) = 0;
                  pvVar7 = CRYPTO_malloc(sVar8,"t1_lib.c",0x4ac);
                  *(void **)(pSVar24->krb5_client_princ + 0x50) = pvVar7;
                  if (pvVar7 == (void *)0x0) goto LAB_000544aa;
                  pSVar24 = param_1->session;
                  *(size_t *)(pSVar24->krb5_client_princ + 0x4c) = sVar8;
                  memcpy(*(void **)(pSVar24->krb5_client_princ + 0x50),puVar21 + 6,sVar8);
                }
              }
              else if (sVar4 == 0x23) {
                if ((param_1->tlsext_session_ticket != (TLS_SESSION_TICKET_EXT *)0x0) &&
                   (iVar14 = (*(code *)param_1->tlsext_session_ticket)
                                       (param_1,puVar18,num,param_1->tls_session_ticket_ext_cb),
                   iVar14 == 0)) {
LAB_000544aa:
                  *param_4 = 0x50;
                  return 0;
                }
              }
              else if (sVar4 == -0xff) {
                iVar14 = ssl_parse_clienthello_renegotiate_ext(param_1,puVar18,num,param_4);
                if (iVar14 == 0) {
                  return 0;
                }
                bVar5 = true;
              }
              else if (sVar4 == 0xd) {
                if (num < 2) {
                  bVar6 = true;
                }
                if (bVar6) break;
                uVar19 = num - 2;
                puVar18 = puVar21 + 6;
                num = uVar19 & 0xffff;
                if (((num != CONCAT11(puVar21[4],puVar21[5])) || ((uVar19 & 1) != 0)) ||
                   (iVar14 = tls1_process_sigalgs(param_1,puVar18,num), iVar14 == 0)) break;
                bVar6 = true;
              }
              else if (sVar4 == 5) {
                if (param_1->version == 0xfeff) {
LAB_0005424c:
                  if ((param_1->method->version == 0xfeff) &&
                     (((psVar11 = SSL_get_srtp_profiles(param_1),
                       psVar11 != (stack_st_SRTP_PROTECTION_PROFILE *)0x0 && (sVar4 == 0xe)) &&
                      (iVar14 = ssl_parse_clienthello_use_srtp_ext(param_1,puVar18,num,param_4),
                      iVar14 != 0)))) {
                    return 0;
                  }
                }
                else {
                  if (num < 5) break;
                  bVar3 = puVar21[4];
                  param_1->servername_done = (uint)bVar3;
                  if (bVar3 == 1) {
                    puVar18 = puVar21 + 7;
                    uVar19 = num - 3 & 0xffff;
                    uVar10 = (uint)CONCAT11(puVar21[5],puVar21[6]);
                    if (uVar19 < uVar10) break;
                    sk_pop_free((_STACK *)param_1->tlsext_status_expected,OCSP_RESPID_free);
                    if (uVar10 == 0) {
                      param_1->tlsext_status_expected = 0;
                    }
                    else {
                      p_Var12 = sk_new_null();
                      param_1->tlsext_status_expected = (int)p_Var12;
                      if (p_Var12 == (_STACK *)0x0) {
LAB_000546dc:
                        *param_4 = 0x50;
                        return 0;
                      }
                      if (uVar10 < 4) break;
                      puVar17 = puVar21 + 9;
                      len = (uint)CONCAT11(puVar21[7],puVar21[8]);
                      uVar19 = (num - 5) - len;
                      iVar14 = uVar10 + (-2 - len);
                      while( true ) {
                        if (iVar14 < 0) goto LAB_00054044;
                        uVar19 = uVar19 & 0xffff;
                        local_2c[0] = puVar17;
                        a = d2i_OCSP_RESPID((OCSP_RESPID **)0x0,local_2c,len);
                        puVar18 = puVar17 + len;
                        if (a == (OCSP_RESPID *)0x0) goto LAB_00054044;
                        if (puVar18 != local_2c[0]) {
                          OCSP_RESPID_free(a);
                          goto LAB_00054044;
                        }
                        puVar17 = puVar18 + 2;
                        iVar9 = sk_push((_STACK *)param_1->tlsext_status_expected,a);
                        if (iVar9 == 0) {
                          OCSP_RESPID_free(a);
                          goto LAB_000546dc;
                        }
                        if (iVar14 < 1) break;
                        if (iVar14 < 4) goto LAB_00054044;
                        len = (uint)CONCAT11(*puVar18,puVar18[1]);
                        uVar19 = uVar19 + (-2 - len);
                        iVar14 = iVar14 + (-2 - len);
                      }
                      if (uVar19 < 2) break;
                    }
                    uVar1 = *puVar18;
                    uVar2 = puVar18[1];
                    puVar18 = puVar18 + 2;
                    num = uVar19 - 2 & 0xffff;
                    if (num != CONCAT11(uVar1,uVar2)) break;
                    local_2c[0] = puVar18;
                    if (num != 0) {
                      if ((_STACK *)param_1->tlsext_ocsp_ids != (_STACK *)0x0) {
                        sk_pop_free((_STACK *)param_1->tlsext_ocsp_ids,X509_EXTENSION_free + 1);
                      }
                      pXVar13 = d2i_X509_EXTENSIONS((X509_EXTENSIONS **)0x0,local_2c,num);
                      param_1->tlsext_ocsp_ids = (stack_st_OCSP_RESPID *)pXVar13;
                      if ((pXVar13 == (X509_EXTENSIONS *)0x0) ||
                         (local_2c[0] != puVar18 + CONCAT11(uVar1,uVar2))) break;
                    }
                  }
                  else {
                    puVar18 = puVar21 + 5;
                    param_1->servername_done = -1;
                    num = num - 1 & 0xffff;
                  }
                }
              }
              else if (sVar4 == 0xf) {
                if (puVar21[4] == '\x01') {
                  param_1->srtp_profile =
                       (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 1);
                }
                else {
                  if (puVar21[4] != '\x02') {
                    *param_4 = 0x2f;
                    return 0;
                  }
                  param_1->srtp_profile =
                       (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 3);
                }
              }
              else {
                if ((sVar4 != 0x3374) || ((param_1->s3->tmp).finish_md_len != 0)) goto LAB_0005424c;
                param_1->s3->next_proto_neg_seen = 1;
              }
              puVar21 = puVar18 + num;
              if ((int)param_3 - (int)puVar21 < 4) goto LAB_0005427a;
              puVar17 = puVar18 + num;
              puVar18 = puVar21 + 4;
              num = (uint)CONCAT11(puVar21[2],puVar21[3]);
              sVar4 = CONCAT11(*puVar17,puVar21[1]);
            } while ((int)num <= (int)param_3 - (int)puVar18);
          }
        }
      }
    }
LAB_00054044:
    uVar22 = 0;
    *param_4 = 0x32;
  }
  return uVar22;
}

