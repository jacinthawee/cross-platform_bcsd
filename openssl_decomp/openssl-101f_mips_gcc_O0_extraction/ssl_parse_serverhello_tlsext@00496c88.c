
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
  uint uVar12;
  SSL_SESSION *pSVar13;
  SSL *s;
  undefined1 *puVar14;
  ushort *puVar15;
  undefined uVar16;
  ushort *puVar17;
  int iVar18;
  ushort *puVar19;
  ushort *puVar20;
  uint uVar21;
  SSL_SESSION *pSVar22;
  code *pcVar23;
  undefined local_31;
  undefined4 local_30;
  SSL *local_2c;
  
  puVar9 = PTR___stack_chk_guard_006aabf0;
  pSVar11 = param_1->srtp_profile;
  puVar15 = *param_2;
  local_2c = *(SSL **)PTR___stack_chk_guard_006aabf0;
  param_1->s3->next_proto_neg_seen = 0;
  param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)pSVar11 & 0xfffffffc);
  if (puVar15 < (ushort *)(param_3 + param_4 + -2)) {
    puVar20 = (ushort *)((int)(puVar15 + 1) + (uint)*puVar15);
    if (puVar20 == (ushort *)(param_3 + param_4)) {
      bVar3 = false;
      bVar2 = false;
      puVar15 = puVar15 + 1;
LAB_00496df8:
      puVar19 = puVar15;
      puVar17 = puVar19 + 2;
      if ((ushort *)(param_3 + param_4 + -4) < puVar19) {
        if (puVar19 != puVar20) goto LAB_00496d50;
        if (((param_1->hit == 0) && (bVar2)) && (param_1->tlsext_debug_arg != (void *)0x0)) {
          pSVar22 = param_1->session;
          if (*(int *)(pSVar22->krb5_client_princ + 0x40) != 0) goto LAB_00496d50;
          uVar10 = (*(code *)PTR_BUF_strdup_006a80dc)();
          pSVar13 = param_1->session;
          *(undefined4 *)(pSVar22->krb5_client_princ + 0x40) = uVar10;
          if (*(int *)(pSVar13->krb5_client_princ + 0x40) == 0) goto LAB_004971f0;
        }
        *param_2 = puVar19;
LAB_00497198:
        iVar18 = 1;
        if (bVar3) goto LAB_00496d5c;
        goto LAB_00496d0c;
      }
      uVar1 = *puVar19;
      uVar21 = (uint)puVar19[1];
      puVar15 = (ushort *)((int)puVar17 + uVar21);
      if (puVar20 < puVar15) goto LAB_00497198;
      if ((code *)param_1->max_send_fragment != (code *)0x0) {
        (*(code *)param_1->max_send_fragment)
                  (param_1,1,uVar1,puVar17,uVar21,param_1->tlsext_debug_cb);
      }
      if (uVar1 == 0) {
        if ((param_1->tlsext_debug_arg == (void *)0x0) || (uVar21 != 0)) {
LAB_004971f0:
          iVar18 = 0;
          *param_5 = 0x70;
          goto LAB_00496d5c;
        }
        bVar2 = true;
        goto LAB_00496df8;
      }
      if (uVar1 == 0xb) {
        if (param_1->version != 0xfeff) {
          uVar5 = (uint)*(byte *)(puVar19 + 2);
          if ((uVar5 != uVar21 - 1) || (uVar5 == 0)) goto LAB_00496d50;
          pSVar22 = param_1->session;
          *(undefined4 *)(pSVar22->krb5_client_princ + 0x44) = 0;
          if (*(int *)(pSVar22->krb5_client_princ + 0x48) != 0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)();
            pSVar22 = param_1->session;
          }
          iVar18 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar5,"t1_lib.c",0x5fb);
          *(int *)(pSVar22->krb5_client_princ + 0x48) = iVar18;
          puVar4 = PTR_memcpy_006aabf4;
          if (iVar18 == 0) {
LAB_00497224:
            iVar18 = 0;
            *param_5 = 0x50;
            goto LAB_00496d5c;
          }
          pSVar22 = param_1->session;
          *(uint *)(pSVar22->krb5_client_princ + 0x44) = uVar5;
          (*(code *)puVar4)(*(undefined4 *)(pSVar22->krb5_client_princ + 0x48),(int)puVar19 + 5,
                            uVar5);
        }
        goto LAB_00496df8;
      }
      if (uVar1 == 0x23) {
        if ((param_1->tlsext_session_ticket != (TLS_SESSION_TICKET_EXT *)0x0) &&
           (iVar18 = (*(code *)param_1->tlsext_session_ticket)
                               (param_1,puVar17,uVar21,param_1->tls_session_ticket_ext_cb),
           iVar18 == 0)) goto LAB_00497224;
        uVar5 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
        if (((uVar5 & 0x4000) != 0) || (uVar21 != 0)) {
LAB_00497214:
          iVar18 = 0;
          *param_5 = 0x6e;
          goto LAB_00496d5c;
        }
        param_1->tlsext_ocsp_resplen = 1;
        goto LAB_00496df8;
      }
      if (uVar1 == 5) {
        if (param_1->version != 0xfeff) {
          if ((param_1->servername_done == -1) || (uVar21 != 0)) goto LAB_00497214;
          param_1->tlsext_status_type = 1;
        }
        goto LAB_00496df8;
      }
      if (uVar1 == 0x3374) {
        iVar18 = (param_1->s3->tmp).finish_md_len;
        if (iVar18 == 0) {
          pcVar23 = *(code **)(param_1->psk_server_callback + 0x1ac);
          if (pcVar23 == (code *)0x0) {
            *param_5 = 0x6e;
            goto LAB_00496d5c;
          }
          if (uVar21 != 0) {
            uVar5 = (uint)*(byte *)(puVar19 + 2);
            uVar12 = 0;
            if (uVar5 != 0) {
              while( true ) {
                uVar12 = uVar12 + uVar5 + 1;
                if (uVar21 <= uVar12) break;
                uVar5 = (uint)*(byte *)((int)puVar17 + uVar12);
                if (uVar5 == 0) goto LAB_00497258;
              }
              if (uVar21 == uVar12) goto LAB_00497078;
            }
LAB_00497258:
            *param_5 = 0x32;
            goto LAB_00496d5c;
          }
LAB_00497078:
          iVar8 = (*pcVar23)(param_1,&local_30,&local_31,puVar17,uVar21,
                             *(undefined4 *)(param_1->psk_server_callback + 0x1b0));
          if (iVar8 == 0) {
            pSVar6 = (SSL_CTX *)(*(code *)PTR_CRYPTO_malloc_006a8108)(local_31,"t1_lib.c",0x662);
            param_1->initial_ctx = pSVar6;
            if (pSVar6 != (SSL_CTX *)0x0) {
              (*(code *)PTR_memcpy_006aabf4)(pSVar6,local_30,local_31);
              *(undefined *)&param_1->next_proto_negotiated = local_31;
              param_1->s3->next_proto_neg_seen = 1;
              goto LAB_00496df8;
            }
          }
          *param_5 = 0x50;
          goto LAB_00496d5c;
        }
        goto LAB_00496df8;
      }
      if (uVar1 == 0xff01) {
        iVar18 = (*(code *)PTR_ssl_parse_serverhello_renegotiate_ext_006a92f8)
                           (param_1,puVar17,uVar21,param_5);
        if (iVar18 == 0) goto LAB_00497140;
        bVar3 = true;
        goto LAB_00496df8;
      }
      if (uVar1 == 0xf) {
        if (*(char *)(puVar19 + 2) == '\x01') {
          param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 1);
        }
        else {
          if (*(char *)(puVar19 + 2) != '\x02') {
            iVar18 = 0;
            *param_5 = 0x2f;
            goto LAB_00496d5c;
          }
          param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 3);
        }
        goto LAB_00496df8;
      }
      if ((uVar1 != 0xe) ||
         (iVar18 = ssl_parse_serverhello_use_srtp_ext(param_1,puVar17,uVar21,param_5), iVar18 == 0))
      goto LAB_00496df8;
LAB_00497140:
      iVar18 = 0;
    }
    else {
LAB_00496d50:
      iVar18 = 0;
      *param_5 = 0x32;
    }
  }
  else {
LAB_00496d0c:
    puVar4 = PTR_ERR_put_error_006a9030;
    if ((param_1->references & 0x40004U) == 0) {
      *param_5 = 0x28;
      (*(code *)puVar4)(0x14,0x12f,0x152,"t1_lib.c",0x6bc);
      iVar18 = 0;
    }
    else {
      iVar18 = 1;
    }
  }
LAB_00496d5c:
  if (local_2c == *(SSL **)puVar9) {
    return iVar18;
  }
  s = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  psVar7 = SSL_get_ciphers(s);
  iVar18 = 0;
  do {
    iVar8 = (*(code *)PTR_sk_num_006a7f2c)(psVar7);
    if (iVar8 <= iVar18) {
      return 1;
    }
    iVar8 = (*(code *)PTR_sk_value_006a7f24)(psVar7,iVar18);
  } while (((*(uint *)(iVar8 + 0xc) & 0xe0) == 0) &&
          (iVar18 = iVar18 + 1, (*(uint *)(iVar8 + 0x10) & 0x40) == 0));
  iVar18 = 1;
  if (0x300 < s->version) {
    if (s->tlsext_ecpointformatlist_length != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    puVar9 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(3,"t1_lib.c",0x6e0);
    s->tlsext_ecpointformatlist_length = (size_t)puVar9;
    if (puVar9 == (undefined *)0x0) {
      uVar10 = 0x6e2;
      pcVar23 = (code *)PTR_ERR_put_error_006a9030;
    }
    else {
      s->tlsext_ticket_expected = 3;
      *puVar9 = 0;
      *(undefined *)(s->tlsext_ecpointformatlist_length + 1) = 1;
      *(undefined *)(s->tlsext_ecpointformatlist_length + 2) = 2;
      if (s->tlsext_ellipticcurvelist_length != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      puVar9 = PTR_CRYPTO_malloc_006a8108;
      s->tlsext_ecpointformatlist = (uchar *)0x32;
      puVar9 = (undefined *)(*(code *)puVar9)(0x32,"t1_lib.c",0x6ed);
      s->tlsext_ellipticcurvelist_length = (size_t)puVar9;
      pcVar23 = (code *)PTR_ERR_put_error_006a9030;
      if (puVar9 != (undefined *)0x0) {
        puVar14 = pref_list;
        do {
          iVar18 = *(int *)puVar14;
          uVar16 = 2;
          if (iVar18 != 0x2d2) {
            if (iVar18 < 0x2d3) {
              uVar16 = 0x12;
              if (iVar18 != 0x2c7) {
                if (iVar18 < 0x2c8) {
                  uVar16 = 0xf;
                  if (iVar18 != 0x2c4) {
                    if (iVar18 < 0x2c5) {
                      if (iVar18 == 0x199) {
                        uVar16 = 0x13;
                      }
                      else {
                        uVar16 = 0x17;
                        if (iVar18 != 0x19f) {
                          uVar16 = 0;
                        }
                      }
                    }
                    else if (iVar18 == 0x2c5) {
                      uVar16 = 0x10;
                    }
                    else {
                      uVar16 = 0x11;
                      if (iVar18 != 0x2c6) {
                        uVar16 = 0;
                      }
                    }
                  }
                }
                else {
                  uVar16 = 0x16;
                  if (iVar18 != 0x2ca) {
                    if (iVar18 < 0x2cb) {
                      if (iVar18 == 0x2c8) {
                        uVar16 = 0x14;
                      }
                      else {
                        uVar16 = 0x15;
                        if (iVar18 != 0x2c9) {
                          uVar16 = 0;
                        }
                      }
                    }
                    else {
                      uVar16 = 0x19;
                      if (iVar18 != 0x2cc) {
                        if (iVar18 < 0x2cc) {
                          uVar16 = 0x18;
                        }
                        else {
                          uVar16 = 1;
                          if (iVar18 != 0x2d1) goto LAB_0049750c;
                        }
                      }
                    }
                  }
                }
              }
            }
            else {
              uVar16 = 8;
              if (iVar18 != 0x2d8) {
                if (iVar18 < 0x2d9) {
                  uVar16 = 5;
                  if (iVar18 != 0x2d5) {
                    if (iVar18 < 0x2d6) {
                      if (iVar18 == 0x2d3) {
                        uVar16 = 3;
                      }
                      else {
                        uVar16 = 4;
                        if (iVar18 != 0x2d4) {
                          uVar16 = 0;
                        }
                      }
                    }
                    else if (iVar18 == 0x2d6) {
                      uVar16 = 6;
                    }
                    else {
                      uVar16 = 7;
                      if (iVar18 != 0x2d7) {
                        uVar16 = 0;
                      }
                    }
                  }
                }
                else {
                  uVar16 = 0xb;
                  if (iVar18 != 0x2db) {
                    if (iVar18 < 0x2dc) {
                      if (iVar18 == 0x2d9) {
                        uVar16 = 9;
                      }
                      else {
                        uVar16 = 10;
                        if (iVar18 != 0x2da) {
                          uVar16 = 0;
                        }
                      }
                    }
                    else {
                      uVar16 = 0xd;
                      if (iVar18 != 0x2dd) {
                        if (iVar18 < 0x2dd) {
                          uVar16 = 0xc;
                        }
                        else {
                          uVar16 = 0xe;
                          if (iVar18 != 0x2de) {
LAB_0049750c:
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
          puVar14 = (undefined1 *)((int)puVar14 + 4);
          *puVar9 = 0;
          puVar9[1] = uVar16;
          puVar9 = puVar9 + 2;
          if (puVar14 == nid_list) {
            return 1;
          }
        } while( true );
      }
      s->tlsext_ecpointformatlist = (uchar *)0x0;
      uVar10 = 0x6f0;
    }
    (*pcVar23)(0x14,0x119,0x41,"t1_lib.c",uVar10);
    iVar18 = -1;
  }
  return iVar18;
}

