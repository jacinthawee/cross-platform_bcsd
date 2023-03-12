
int ssl_parse_serverhello_tlsext
              (SSL *param_1,ushort **param_2,int param_3,int param_4,undefined4 *param_5)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  undefined *puVar4;
  uint uVar5;
  SSL_CTX *pSVar6;
  stack_st_SSL_CIPHER *psVar7;
  int iVar8;
  undefined *puVar9;
  undefined4 uVar10;
  SRTP_PROTECTION_PROFILE *pSVar11;
  SSL_SESSION *pSVar12;
  ushort *puVar13;
  uint uVar14;
  SSL *s;
  undefined1 *puVar15;
  undefined uVar16;
  int iVar17;
  ushort *puVar18;
  SSL_SESSION *pSVar19;
  ushort *puVar20;
  uint uVar21;
  code *pcVar22;
  ushort *puVar23;
  undefined local_31;
  undefined4 local_30;
  SSL *local_2c;
  
  puVar9 = PTR___stack_chk_guard_006a9ae8;
  puVar23 = (ushort *)(param_3 + param_4);
  puVar13 = *param_2;
  pSVar11 = param_1->srtp_profile;
  local_2c = *(SSL **)PTR___stack_chk_guard_006a9ae8;
  param_1->s3->next_proto_neg_seen = 0;
  param_1->tlsext_ocsp_resplen = 0;
  param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)pSVar11 & 0xfffffffc);
  if (2 < (int)puVar23 - (int)puVar13) {
    puVar18 = puVar13 + 1;
    if ((int)puVar23 - (int)puVar18 != (uint)*puVar13) {
LAB_00492ea0:
      iVar17 = 0;
      *param_5 = 0x32;
      goto LAB_00492ea8;
    }
    puVar20 = puVar13 + 3;
    if ((int)puVar23 - (int)puVar18 < 4) {
      bVar2 = false;
      bVar3 = false;
LAB_00493320:
      if (puVar23 != puVar18) goto LAB_00492ea0;
      if (((param_1->hit == 0) && (bVar3)) && (param_1->tlsext_debug_arg != (void *)0x0)) {
        pSVar19 = param_1->session;
        if (*(int *)(pSVar19->krb5_client_princ + 0x40) != 0) goto LAB_00492ea0;
        uVar10 = (*(code *)PTR_BUF_strdup_006a6fdc)();
        pSVar12 = param_1->session;
        *(undefined4 *)(pSVar19->krb5_client_princ + 0x40) = uVar10;
        if (*(int *)(pSVar12->krb5_client_princ + 0x40) == 0) {
LAB_0049338c:
          iVar17 = 0;
          *param_5 = 0x70;
          goto LAB_00492ea8;
        }
      }
      *param_2 = puVar23;
    }
    else {
      uVar1 = puVar13[1];
      uVar21 = (uint)puVar13[2];
      if ((int)puVar23 - (int)puVar20 < (int)uVar21) goto LAB_00492e5c;
      bVar2 = false;
      bVar3 = false;
      do {
        if ((code *)param_1->max_send_fragment != (code *)0x0) {
          (*(code *)param_1->max_send_fragment)
                    (param_1,1,uVar1,puVar20,uVar21,param_1->tlsext_debug_cb);
        }
        if (uVar1 == 0) {
          if ((param_1->tlsext_debug_arg == (void *)0x0) || (uVar21 != 0)) goto LAB_0049338c;
          uVar21 = 0;
          bVar3 = true;
        }
        else if (uVar1 == 0xb) {
          uVar5 = (uint)*(byte *)(puVar18 + 2);
          if ((uVar5 != uVar21 - 1) || (uVar5 == 0)) goto LAB_00492ea0;
          if (param_1->hit == 0) {
            pSVar19 = param_1->session;
            *(undefined4 *)(pSVar19->krb5_client_princ + 0x44) = 0;
            if (*(int *)(pSVar19->krb5_client_princ + 0x48) != 0) {
              (*(code *)PTR_CRYPTO_free_006a6e88)();
              pSVar19 = param_1->session;
            }
            iVar17 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar5,"t1_lib.c",0x5ea);
            *(int *)(pSVar19->krb5_client_princ + 0x48) = iVar17;
            puVar4 = PTR_memcpy_006a9aec;
            if (iVar17 == 0) goto LAB_004933c4;
            pSVar19 = param_1->session;
            *(uint *)(pSVar19->krb5_client_princ + 0x44) = uVar5;
            (*(code *)puVar4)(*(undefined4 *)(pSVar19->krb5_client_princ + 0x48),
                              (byte *)((int)puVar18 + 5),uVar5);
          }
        }
        else if (uVar1 == 0x23) {
          if ((param_1->tlsext_session_ticket != (TLS_SESSION_TICKET_EXT *)0x0) &&
             (iVar17 = (*(code *)param_1->tlsext_session_ticket)
                                 (param_1,puVar20,uVar21,param_1->tls_session_ticket_ext_cb),
             iVar17 == 0)) {
LAB_004933c4:
            iVar17 = 0;
            *param_5 = 0x50;
            goto LAB_00492ea8;
          }
          uVar5 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
          if (((uVar5 & 0x4000) != 0) || (uVar21 != 0)) {
LAB_004933b4:
            iVar17 = 0;
            *param_5 = 0x6e;
            goto LAB_00492ea8;
          }
          uVar21 = 0;
          param_1->tlsext_ocsp_resplen = 1;
        }
        else if (uVar1 == 5) {
          if (param_1->version != 0xfeff) {
            if ((param_1->servername_done == -1) || (uVar21 != 0)) goto LAB_004933b4;
            uVar21 = 0;
            param_1->tlsext_status_type = 1;
          }
        }
        else if (uVar1 == 0x3374) {
          iVar17 = (param_1->s3->tmp).finish_md_len;
          if (iVar17 == 0) {
            pcVar22 = *(code **)(param_1->psk_server_callback + 0x1ac);
            if (pcVar22 == (code *)0x0) {
              *param_5 = 0x6e;
            }
            else if (uVar21 == 0) {
LAB_00493220:
              iVar8 = (*pcVar22)(param_1,&local_30,&local_31,puVar20,uVar21,
                                 *(undefined4 *)(param_1->psk_server_callback + 0x1b0));
              if (iVar8 == 0) {
                pSVar6 = (SSL_CTX *)(*(code *)PTR_CRYPTO_malloc_006a7008)(local_31,"t1_lib.c",0x653)
                ;
                param_1->initial_ctx = pSVar6;
                if (pSVar6 != (SSL_CTX *)0x0) {
                  (*(code *)PTR_memcpy_006a9aec)(pSVar6,local_30,local_31);
                  *(undefined *)&param_1->next_proto_negotiated = local_31;
                  param_1->s3->next_proto_neg_seen = 1;
                  goto LAB_00492fc4;
                }
              }
              *param_5 = 0x50;
            }
            else {
              uVar5 = (uint)*(byte *)puVar20;
              uVar14 = 0;
              if (uVar5 != 0) {
                while( true ) {
                  uVar14 = uVar14 + uVar5 + 1;
                  if (uVar21 <= uVar14) break;
                  uVar5 = (uint)*(byte *)((int)puVar20 + uVar14);
                  if (uVar5 == 0) goto LAB_004931e4;
                }
                if (uVar21 == uVar14) goto LAB_00493220;
              }
LAB_004931e4:
              *param_5 = 0x32;
            }
            goto LAB_00492ea8;
          }
        }
        else if (uVar1 == 0xff01) {
          iVar17 = (*(code *)PTR_ssl_parse_serverhello_renegotiate_ext_006a81cc)
                             (param_1,puVar20,uVar21,param_5);
          if (iVar17 == 0) {
LAB_004932d0:
            iVar17 = 0;
            goto LAB_00492ea8;
          }
          bVar2 = true;
        }
        else if (uVar1 == 0xf) {
          if (*(byte *)(puVar18 + 2) == 1) {
            param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 1);
          }
          else {
            if (*(byte *)(puVar18 + 2) != 2) {
              iVar17 = 0;
              *param_5 = 0x2f;
              goto LAB_00492ea8;
            }
            param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 3);
          }
        }
        else if (((param_1->method->version == 0xfeff) && (uVar1 == 0xe)) &&
                (iVar17 = ssl_parse_serverhello_use_srtp_ext(param_1,puVar20,uVar21,param_5),
                iVar17 != 0)) goto LAB_004932d0;
LAB_00492fc4:
        puVar18 = (ushort *)((int)puVar20 + uVar21);
        puVar20 = puVar18 + 2;
        if ((int)puVar23 - (int)puVar18 < 4) goto LAB_00493320;
        uVar1 = *puVar18;
        uVar21 = (uint)puVar18[1];
      } while ((int)uVar21 <= (int)puVar23 - (int)puVar20);
    }
    iVar17 = 1;
    if (bVar2) goto LAB_00492ea8;
  }
LAB_00492e5c:
  puVar4 = PTR_ERR_put_error_006a7f34;
  if ((param_1->references & 0x40004U) == 0) {
    *param_5 = 0x28;
    (*(code *)puVar4)(0x14,0x12f,0x152,"t1_lib.c",0x6a0);
    iVar17 = 0;
  }
  else {
    iVar17 = 1;
  }
LAB_00492ea8:
  if (local_2c == *(SSL **)puVar9) {
    return iVar17;
  }
  s = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  psVar7 = SSL_get_ciphers(s);
  iVar17 = 0;
  do {
    iVar8 = (*(code *)PTR_sk_num_006a6e2c)(psVar7);
    if (iVar8 <= iVar17) {
      return 1;
    }
    iVar8 = (*(code *)PTR_sk_value_006a6e24)(psVar7,iVar17);
  } while (((*(uint *)(iVar8 + 0xc) & 0xe0) == 0) &&
          (iVar17 = iVar17 + 1, (*(uint *)(iVar8 + 0x10) & 0x40) == 0));
  iVar17 = 1;
  if (0x300 < s->version) {
    if (s->tlsext_ecpointformatlist_length != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    puVar9 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(3,"t1_lib.c",0x6c3);
    s->tlsext_ecpointformatlist_length = (size_t)puVar9;
    if (puVar9 == (undefined *)0x0) {
      uVar10 = 0x6c5;
      pcVar22 = (code *)PTR_ERR_put_error_006a7f34;
    }
    else {
      s->tlsext_ticket_expected = 3;
      *puVar9 = 0;
      *(undefined *)(s->tlsext_ecpointformatlist_length + 1) = 1;
      *(undefined *)(s->tlsext_ecpointformatlist_length + 2) = 2;
      if (s->tlsext_ellipticcurvelist_length != 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      puVar9 = PTR_CRYPTO_malloc_006a7008;
      s->tlsext_ecpointformatlist = &DAT_00000032;
      puVar9 = (undefined *)(*(code *)puVar9)(0x32,"t1_lib.c",0x6d5);
      s->tlsext_ellipticcurvelist_length = (size_t)puVar9;
      pcVar22 = (code *)PTR_ERR_put_error_006a7f34;
      if (puVar9 != (undefined *)0x0) {
        puVar15 = pref_list;
        do {
          iVar17 = *(int *)puVar15;
          uVar16 = 2;
          if (iVar17 != 0x2d2) {
            if (iVar17 < 0x2d3) {
              uVar16 = 0x12;
              if (iVar17 != 0x2c7) {
                if (iVar17 < 0x2c8) {
                  uVar16 = 0xf;
                  if (iVar17 != 0x2c4) {
                    if (iVar17 < 0x2c5) {
                      if (iVar17 == 0x199) {
                        uVar16 = 0x13;
                      }
                      else {
                        uVar16 = 0x17;
                        if (iVar17 != 0x19f) {
                          uVar16 = 0;
                        }
                      }
                    }
                    else if (iVar17 == 0x2c5) {
                      uVar16 = 0x10;
                    }
                    else {
                      uVar16 = 0x11;
                      if (iVar17 != 0x2c6) {
                        uVar16 = 0;
                      }
                    }
                  }
                }
                else {
                  uVar16 = 0x16;
                  if (iVar17 != 0x2ca) {
                    if (iVar17 < 0x2cb) {
                      if (iVar17 == 0x2c8) {
                        uVar16 = 0x14;
                      }
                      else {
                        uVar16 = 0x15;
                        if (iVar17 != 0x2c9) {
                          uVar16 = 0;
                        }
                      }
                    }
                    else {
                      uVar16 = 0x19;
                      if (iVar17 != 0x2cc) {
                        if (iVar17 < 0x2cc) {
                          uVar16 = 0x18;
                        }
                        else {
                          uVar16 = 1;
                          if (iVar17 != 0x2d1) goto LAB_0049369c;
                        }
                      }
                    }
                  }
                }
              }
            }
            else {
              uVar16 = 8;
              if (iVar17 != 0x2d8) {
                if (iVar17 < 0x2d9) {
                  uVar16 = 5;
                  if (iVar17 != 0x2d5) {
                    if (iVar17 < 0x2d6) {
                      if (iVar17 == 0x2d3) {
                        uVar16 = 3;
                      }
                      else {
                        uVar16 = 4;
                        if (iVar17 != 0x2d4) {
                          uVar16 = 0;
                        }
                      }
                    }
                    else if (iVar17 == 0x2d6) {
                      uVar16 = 6;
                    }
                    else {
                      uVar16 = 7;
                      if (iVar17 != 0x2d7) {
                        uVar16 = 0;
                      }
                    }
                  }
                }
                else {
                  uVar16 = 0xb;
                  if (iVar17 != 0x2db) {
                    if (iVar17 < 0x2dc) {
                      if (iVar17 == 0x2d9) {
                        uVar16 = 9;
                      }
                      else {
                        uVar16 = 10;
                        if (iVar17 != 0x2da) {
                          uVar16 = 0;
                        }
                      }
                    }
                    else {
                      uVar16 = 0xd;
                      if (iVar17 != 0x2dd) {
                        if (iVar17 < 0x2dd) {
                          uVar16 = 0xc;
                        }
                        else {
                          uVar16 = 0xe;
                          if (iVar17 != 0x2de) {
LAB_0049369c:
                            uVar16 = 0;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          puVar15 = (undefined1 *)((int)puVar15 + 4);
          *puVar9 = 0;
          puVar9[1] = uVar16;
          puVar9 = puVar9 + 2;
          if (puVar15 == nid_list) {
            return 1;
          }
        } while( true );
      }
      s->tlsext_ecpointformatlist = (uchar *)0x0;
      uVar10 = 0x6d8;
    }
    (*pcVar22)(0x14,0x119,0x41,"t1_lib.c",uVar10);
    iVar17 = -1;
  }
  return iVar17;
}

