
int ssl_parse_clienthello_tlsext(SSL *param_1,ushort **param_2,ushort *param_3,undefined4 *param_4)

{
  byte bVar1;
  ssl3_state_st *psVar2;
  char *__s;
  bool bVar3;
  bool bVar4;
  ushort *puVar5;
  void *pvVar6;
  SSL_SESSION *pSVar7;
  size_t sVar8;
  stack_st_SRTP_PROTECTION_PROFILE *psVar9;
  int iVar10;
  char *pcVar11;
  BIO *pBVar12;
  _STACK *p_Var13;
  int iVar14;
  OCSP_RESPID *a;
  X509_EXTENSIONS *pXVar15;
  char cVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  ushort uVar20;
  undefined4 *puVar21;
  ushort *puVar22;
  ushort *puVar23;
  ushort uVar24;
  undefined4 *puVar25;
  undefined4 *puVar26;
  int in_GS_OFFSET;
  byte bVar27;
  int local_4c;
  ushort *local_44;
  uint local_40;
  ushort *local_24;
  int local_20;
  
  bVar27 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  psVar2 = param_1->s3;
  puVar22 = *param_2;
  param_1->tlsext_hostname = (char *)0x0;
  param_1->servername_done = -1;
  psVar2->next_proto_neg_seen = 0;
  param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile & 0xfffffffc);
  if (((((*(byte *)&param_1->references & 0x40) != 0) && (2 < (int)param_3 - (int)puVar22)) &&
      (3 < (int)param_3 - (int)(puVar22 + 1))) && (puVar22[1] == 0)) {
    uVar18 = (uint)(ushort)(puVar22[2] << 8 | puVar22[2] >> 8);
    if ((int)uVar18 <= (int)param_3 - (int)(puVar22 + 3)) {
      pvVar6 = (void *)((int)(puVar22 + 3) + uVar18);
      if ((param_1->first_packet >> 8 == 3) && (0x302 < param_1->first_packet)) {
        if (((int)param_3 - (int)pvVar6 == 0x22) &&
           (iVar19 = memcmp(pvVar6,kSafariExtensionsBlock_17593,0x12), iVar19 == 0)) {
          iVar19 = memcmp((void *)((int)pvVar6 + 0x12),kSafariTLS12ExtensionsBlock_17594,0x10);
joined_r0x080ad5fc:
          if (iVar19 == 0) {
            *(undefined *)&psVar2[1].flags = 1;
          }
        }
      }
      else if ((int)param_3 - (int)pvVar6 == 0x12) {
        iVar19 = memcmp(pvVar6,kSafariExtensionsBlock_17593,0x12);
        goto joined_r0x080ad5fc;
      }
    }
  }
  if (param_1[1].rbio != (BIO *)0x0) {
    CRYPTO_free(param_1[1].rbio);
    param_1[1].rbio = (BIO *)0x0;
  }
  param_1->srtp_profiles = (stack_st_SRTP_PROTECTION_PROFILE *)0x0;
  if (puVar22 == param_3) {
LAB_080ad310:
    if ((param_1->tlsext_hb_seq == 0) || ((*(byte *)((int)&param_1->references + 2) & 4) != 0)) {
LAB_080ad32b:
      local_4c = 1;
    }
    else {
      *param_4 = 0x28;
      ERR_put_error(0x14,0x12e,0x152,"t1_lib.c",0x58e);
LAB_080ad2bd:
      local_4c = 0;
    }
  }
  else {
    puVar5 = local_24;
    if (1 < (int)param_3 - (int)puVar22) {
      local_44 = puVar22 + 1;
      if ((int)param_3 - (int)local_44 == (uint)(ushort)(*puVar22 << 8 | *puVar22 >> 8)) {
        if ((int)param_3 - (int)local_44 < 4) {
          if (param_3 == local_44) {
            *param_2 = param_3;
            goto LAB_080ad310;
          }
        }
        else {
          puVar23 = puVar22 + 3;
          local_40 = (uint)(ushort)(puVar22[2] << 8 | puVar22[2] >> 8);
          uVar20 = puVar22[1] << 8 | puVar22[1] >> 8;
          if ((int)local_40 <= (int)param_3 - (int)puVar23) {
            bVar3 = false;
            bVar4 = false;
            do {
              if ((code *)param_1->max_send_fragment != (code *)0x0) {
                (*(code *)param_1->max_send_fragment)
                          (param_1,0,uVar20,puVar23,local_40,param_1->tlsext_debug_cb);
              }
              uVar24 = (ushort)local_40;
              puVar5 = local_24;
              if (uVar20 == 0) {
                if (uVar24 < 2) break;
                local_40 = local_40 - 2 & 0xffff;
                uVar18 = (uint)(ushort)(*puVar23 << 8 | *puVar23 >> 8);
                if (local_40 < uVar18) break;
                if (3 < uVar18) {
                  iVar19 = uVar18 - 3;
                  cVar16 = *(char *)(local_44 + 3);
                  puVar21 = (undefined4 *)((int)local_44 + 9);
                  uVar20 = *(ushort *)((int)local_44 + 7) << 8 | *(ushort *)((int)local_44 + 7) >> 8
                  ;
                  uVar18 = (uint)uVar20;
                  if (iVar19 < (int)uVar18) break;
                  pcVar11 = param_1->tlsext_hostname;
                  while( true ) {
                    if ((pcVar11 == (char *)0x0) && (cVar16 == '\0')) {
                      local_4c = param_1->hit;
                      if (local_4c == 0) {
                        pSVar7 = param_1->session;
                        puVar5 = local_24;
                        if (*(int *)(pSVar7->krb5_client_princ + 0x40) != 0) goto LAB_080acebd;
                        if (0xff < uVar20) {
                          *param_4 = 0x70;
                          goto LAB_080acecf;
                        }
                        pvVar6 = CRYPTO_malloc(uVar18 + 1,"t1_lib.c",1099);
                        *(void **)(pSVar7->krb5_client_princ + 0x40) = pvVar6;
                        if (pvVar6 == (void *)0x0) goto LAB_080ad6df;
                        pSVar7 = param_1->session;
                        puVar26 = *(undefined4 **)(pSVar7->krb5_client_princ + 0x40);
                        if (uVar18 < 4) {
                          if (uVar18 != 0) {
                            *(undefined *)puVar26 = *(undefined *)puVar21;
                            if ((uVar18 & 2) == 0) {
                              pSVar7 = param_1->session;
                            }
                            else {
                              *(undefined2 *)((int)puVar26 + (uVar18 - 2)) =
                                   *(undefined2 *)((int)puVar21 + (uVar18 - 2));
                              pSVar7 = param_1->session;
                            }
                          }
                        }
                        else {
                          *puVar26 = *puVar21;
                          *(undefined4 *)((int)puVar26 + (uVar18 - 4)) =
                               *(undefined4 *)((int)puVar21 + (uVar18 - 4));
                          iVar10 = (int)puVar26 -
                                   (int)(undefined4 *)((uint)(puVar26 + 1) & 0xfffffffc);
                          puVar25 = (undefined4 *)((int)puVar21 - iVar10);
                          puVar26 = (undefined4 *)((uint)(puVar26 + 1) & 0xfffffffc);
                          for (uVar17 = iVar10 + uVar18 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
                            *puVar26 = *puVar25;
                            puVar25 = puVar25 + (uint)bVar27 * -2 + 1;
                            puVar26 = puVar26 + (uint)bVar27 * -2 + 1;
                          }
                          pSVar7 = param_1->session;
                        }
                        *(undefined *)(*(int *)(pSVar7->krb5_client_princ + 0x40) + uVar18) = 0;
                        pcVar11 = *(char **)(param_1->session->krb5_client_princ + 0x40);
                        sVar8 = strlen(pcVar11);
                        if (uVar18 != sVar8) {
                          CRYPTO_free(pcVar11);
                          *(undefined4 *)(param_1->session->krb5_client_princ + 0x40) = 0;
                          *param_4 = 0x70;
                          goto LAB_080acecf;
                        }
                        param_1->tlsext_hostname = (char *)0x1;
                        pcVar11 = (char *)0x1;
                      }
                      else {
                        __s = *(char **)(param_1->session->krb5_client_princ + 0x40);
                        if ((__s != (char *)0x0) && (sVar8 = strlen(__s), sVar8 == uVar18)) {
                          iVar10 = strncmp(__s,(char *)puVar21,uVar18);
                          pcVar11 = (char *)(uint)(iVar10 == 0);
                        }
                        param_1->tlsext_hostname = pcVar11;
                      }
                    }
                    uVar18 = iVar19 - uVar18;
                    if ((int)uVar18 < 4) break;
                    puVar22 = (ushort *)((int)puVar21 + 1);
                    iVar19 = uVar18 - 3;
                    cVar16 = *(char *)puVar21;
                    puVar21 = (undefined4 *)((int)puVar21 + 3);
                    uVar20 = *puVar22 << 8 | *puVar22 >> 8;
                    uVar18 = (uint)uVar20;
                    puVar5 = local_24;
                    if (iVar19 < (int)uVar18) goto LAB_080acebd;
                  }
                }
                puVar5 = local_24;
                if (uVar18 != 0) break;
                puVar23 = local_44 + 3;
              }
              else if (uVar20 == 0xc) {
                if (uVar24 == 0) break;
                bVar1 = *(byte *)(local_44 + 2);
                uVar18 = (uint)bVar1;
                if ((uVar18 != local_40 - 1) || (param_1[1].rbio != (BIO *)0x0)) break;
                pBVar12 = (BIO *)CRYPTO_malloc(local_40,"t1_lib.c",0x471);
                param_1[1].rbio = pBVar12;
                if (pBVar12 == (BIO *)0x0) {
                  local_4c = -1;
                  goto LAB_080acecf;
                }
                if (uVar18 < 4) {
                  if ((uVar18 != 0) &&
                     (*(undefined *)&pBVar12->method = *(undefined *)((int)local_44 + 5),
                     (bVar1 & 2) != 0)) {
                    *(undefined2 *)((int)pBVar12 + (uVar18 - 2)) =
                         *(undefined2 *)((int)local_44 + uVar18 + 3);
                  }
                }
                else {
                  puVar26 = (undefined4 *)((uint)&pBVar12->callback & 0xfffffffc);
                  pBVar12->method = *(BIO_METHOD **)((int)local_44 + 5);
                  *(undefined4 *)((int)pBVar12 + (uVar18 - 4)) =
                       *(undefined4 *)((int)local_44 + uVar18 + 1);
                  iVar19 = (int)pBVar12 - (int)puVar26;
                  puVar21 = (undefined4 *)((undefined *)((int)local_44 + 5) + -iVar19);
                  for (uVar17 = iVar19 + uVar18 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
                    *puVar26 = *puVar21;
                    puVar21 = puVar21 + (uint)bVar27 * -2 + 1;
                    puVar26 = puVar26 + (uint)bVar27 * -2 + 1;
                  }
                }
                *(undefined *)((int)&(param_1[1].rbio)->method + uVar18) = 0;
                sVar8 = strlen((char *)param_1[1].rbio);
                puVar5 = local_24;
                if (uVar18 != sVar8) break;
              }
              else if (uVar20 == 0xb) {
                bVar1 = *(byte *)(local_44 + 2);
                uVar18 = (uint)bVar1;
                if (uVar18 != local_40 - 1) break;
                if (param_1->hit == 0) {
                  pSVar7 = param_1->session;
                  if (*(void **)(pSVar7->krb5_client_princ + 0x48) != (void *)0x0) {
                    CRYPTO_free(*(void **)(pSVar7->krb5_client_princ + 0x48));
                    pSVar7 = param_1->session;
                    *(undefined4 *)(pSVar7->krb5_client_princ + 0x48) = 0;
                  }
                  *(undefined4 *)(pSVar7->krb5_client_princ + 0x44) = 0;
                  pvVar6 = CRYPTO_malloc(uVar18,"t1_lib.c",0x489);
                  *(void **)(pSVar7->krb5_client_princ + 0x48) = pvVar6;
                  if (pvVar6 == (void *)0x0) goto LAB_080ad6df;
                  pSVar7 = param_1->session;
                  *(uint *)(pSVar7->krb5_client_princ + 0x44) = uVar18;
                  puVar21 = *(undefined4 **)(pSVar7->krb5_client_princ + 0x48);
                  if (uVar18 < 4) {
                    if ((uVar18 != 0) &&
                       (*(undefined *)puVar21 = *(undefined *)((int)local_44 + 5), (bVar1 & 2) != 0)
                       ) {
                      *(undefined2 *)((int)puVar21 + (uVar18 - 2)) =
                           *(undefined2 *)((int)local_44 + uVar18 + 3);
                    }
                  }
                  else {
                    *puVar21 = *(undefined4 *)((int)local_44 + 5);
                    *(undefined4 *)((int)puVar21 + (uVar18 - 4)) =
                         *(undefined4 *)((int)local_44 + uVar18 + 1);
                    iVar19 = (int)puVar21 - (int)(undefined4 *)((uint)(puVar21 + 1) & 0xfffffffc);
                    puVar26 = (undefined4 *)((undefined *)((int)local_44 + 5) + -iVar19);
                    puVar21 = (undefined4 *)((uint)(puVar21 + 1) & 0xfffffffc);
                    for (uVar18 = iVar19 + uVar18 >> 2; uVar18 != 0; uVar18 = uVar18 - 1) {
                      *puVar21 = *puVar26;
                      puVar26 = puVar26 + (uint)bVar27 * -2 + 1;
                      puVar21 = puVar21 + (uint)bVar27 * -2 + 1;
                    }
                  }
                }
              }
              else if (uVar20 == 10) {
                uVar18 = (uint)CONCAT11(*(undefined *)(local_44 + 2),*(byte *)((int)local_44 + 5));
                if (((local_40 - 2 != uVar18) || (uVar18 == 0)) ||
                   ((*(byte *)((int)local_44 + 5) & 1) != 0)) break;
                if (param_1->hit == 0) {
                  pSVar7 = param_1->session;
                  if (*(int *)(pSVar7->krb5_client_princ + 0x50) != 0) break;
                  *(undefined4 *)(pSVar7->krb5_client_princ + 0x4c) = 0;
                  pvVar6 = CRYPTO_malloc(uVar18,"t1_lib.c",0x4ac);
                  *(void **)(pSVar7->krb5_client_princ + 0x50) = pvVar6;
                  if (pvVar6 == (void *)0x0) goto LAB_080ad6df;
                  pSVar7 = param_1->session;
                  *(uint *)(pSVar7->krb5_client_princ + 0x4c) = uVar18;
                  memcpy(*(void **)(pSVar7->krb5_client_princ + 0x50),local_44 + 3,uVar18);
                }
              }
              else if (uVar20 == 0x23) {
                if ((param_1->tlsext_session_ticket != (TLS_SESSION_TICKET_EXT *)0x0) &&
                   (iVar19 = (*(code *)param_1->tlsext_session_ticket)
                                       (param_1,puVar23,local_40,param_1->tls_session_ticket_ext_cb)
                   , iVar19 == 0)) {
LAB_080ad6df:
                  local_4c = 0;
                  *param_4 = 0x50;
                  goto LAB_080acecf;
                }
              }
              else if (uVar20 == 0xff01) {
                iVar19 = ssl_parse_clienthello_renegotiate_ext(param_1,puVar23,local_40,param_4);
                if (iVar19 == 0) goto LAB_080ad2bd;
                bVar4 = true;
              }
              else if (uVar20 == 0xd) {
                if ((bVar3) || (uVar24 < 2)) break;
                uVar20 = *puVar23;
                local_40 = local_40 - 2 & 0xffff;
                puVar23 = local_44 + 3;
                uVar24 = uVar20 >> 8;
                uVar18 = (uint)(ushort)(uVar20 << 8 | uVar24);
                if ((uVar18 != local_40) ||
                   (((uVar24 & 1) != 0 ||
                    (iVar19 = tls1_process_sigalgs(param_1,puVar23,uVar18), puVar5 = local_24,
                    iVar19 == 0)))) break;
                bVar3 = true;
              }
              else if (uVar20 == 5) {
                if (param_1->version == 0xfeff) {
LAB_080ad26c:
                  if ((param_1->method->version == 0xfeff) &&
                     (((psVar9 = SSL_get_srtp_profiles(param_1),
                       psVar9 != (stack_st_SRTP_PROTECTION_PROFILE *)0x0 && (uVar20 == 0xe)) &&
                      (iVar19 = ssl_parse_clienthello_use_srtp_ext(param_1,puVar23,local_40,param_4)
                      , iVar19 != 0)))) goto LAB_080ad2bd;
                }
                else {
                  if (uVar24 < 5) break;
                  puVar23 = (ushort *)((int)local_44 + 5);
                  bVar1 = *(byte *)(local_44 + 2);
                  param_1->servername_done = (uint)bVar1;
                  if (bVar1 == 1) {
                    iVar19 = local_40 - 3;
                    puVar22 = (ushort *)((int)local_44 + 7);
                    uVar20 = *(ushort *)((int)local_44 + 5) << 8 |
                             *(ushort *)((int)local_44 + 5) >> 8;
                    uVar18 = (uint)uVar20;
                    if ((ushort)iVar19 < uVar20) break;
                    sk_pop_free((_STACK *)param_1->tlsext_status_expected,OCSP_RESPID_free);
                    if (uVar18 == 0) {
                      param_1->tlsext_status_expected = 0;
                    }
                    else {
                      p_Var13 = sk_new_null();
                      param_1->tlsext_status_expected = (int)p_Var13;
                      if (p_Var13 == (_STACK *)0x0) {
                        *param_4 = 0x50;
                        goto LAB_080ad2bd;
                      }
                      puVar5 = local_24;
                      if (uVar18 < 4) break;
                      uVar17 = (uint)(ushort)(*(ushort *)((int)local_44 + 7) << 8 |
                                             *(ushort *)((int)local_44 + 7) >> 8);
                      iVar19 = iVar19 + (-2 - uVar17);
                      iVar10 = uVar18 - (uVar17 + 2);
                      puVar22 = (ushort *)((int)local_44 + 9);
                      while( true ) {
                        local_24 = puVar22;
                        if (iVar10 < 0) goto LAB_080acebd;
                        puVar22 = (ushort *)((int)local_24 + uVar17);
                        a = d2i_OCSP_RESPID((OCSP_RESPID **)0x0,(uchar **)&local_24,uVar17);
                        puVar5 = local_24;
                        if (a == (OCSP_RESPID *)0x0) goto LAB_080acebd;
                        if (puVar22 != local_24) {
                          OCSP_RESPID_free(a);
                          puVar5 = local_24;
                          goto LAB_080acebd;
                        }
                        iVar14 = sk_push((_STACK *)param_1->tlsext_status_expected,a);
                        if (iVar14 == 0) {
                          OCSP_RESPID_free(a);
                          *param_4 = 0x50;
                          goto LAB_080ad2bd;
                        }
                        puVar5 = local_24;
                        if (iVar10 == 0) break;
                        if (iVar10 < 4) goto LAB_080acebd;
                        uVar17 = (uint)(ushort)(*puVar22 << 8 | *puVar22 >> 8);
                        iVar19 = iVar19 + (-2 - uVar17);
                        iVar10 = iVar10 - (uVar17 + 2);
                        puVar22 = puVar22 + 1;
                      }
                      if ((ushort)iVar19 < 2) break;
                    }
                    puVar23 = puVar22 + 1;
                    local_40 = iVar19 - 2U & 0xffff;
                    uVar18 = (uint)(ushort)(*puVar22 << 8 | *puVar22 >> 8);
                    puVar5 = local_24;
                    if (uVar18 != local_40) break;
                    local_24 = puVar23;
                    if (uVar18 != 0) {
                      if ((_STACK *)param_1->tlsext_ocsp_ids != (_STACK *)0x0) {
                        sk_pop_free((_STACK *)param_1->tlsext_ocsp_ids,X509_EXTENSION_free);
                      }
                      pXVar15 = d2i_X509_EXTENSIONS((X509_EXTENSIONS **)0x0,(uchar **)&local_24,
                                                    uVar18);
                      param_1->tlsext_ocsp_ids = (stack_st_OCSP_RESPID *)pXVar15;
                      puVar5 = local_24;
                      if ((pXVar15 == (X509_EXTENSIONS *)0x0) ||
                         (local_24 != (ushort *)(uVar18 + (int)puVar23))) break;
                    }
                  }
                  else {
                    param_1->servername_done = -1;
                    local_40 = local_40 - 1 & 0xffff;
                  }
                }
              }
              else if (uVar20 == 0xf) {
                if (*(char *)(local_44 + 2) == '\x01') {
                  param_1->srtp_profile =
                       (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 1);
                }
                else {
                  if (*(char *)(local_44 + 2) != '\x02') {
                    local_4c = 0;
                    *param_4 = 0x2f;
                    goto LAB_080acecf;
                  }
                  param_1->srtp_profile =
                       (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 3);
                }
              }
              else {
                if ((uVar20 != 0x3374) || ((param_1->s3->tmp).finish_md_len != 0))
                goto LAB_080ad26c;
                param_1->s3->next_proto_neg_seen = 1;
              }
              local_44 = (ushort *)((int)puVar23 + local_40);
              puVar5 = local_24;
              if ((int)param_3 - (int)local_44 < 4) {
                if (param_3 == local_44) {
                  *param_2 = param_3;
                  if (bVar4) goto LAB_080ad32b;
                  goto LAB_080ad310;
                }
                break;
              }
              puVar23 = local_44 + 2;
              uVar20 = *local_44 << 8 | *local_44 >> 8;
              local_40 = (uint)(ushort)(local_44[1] << 8 | local_44[1] >> 8);
            } while ((int)local_40 <= (int)param_3 - (int)puVar23);
          }
        }
      }
    }
LAB_080acebd:
    local_24 = puVar5;
    local_4c = 0;
    *param_4 = 0x32;
  }
LAB_080acecf:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_4c;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

