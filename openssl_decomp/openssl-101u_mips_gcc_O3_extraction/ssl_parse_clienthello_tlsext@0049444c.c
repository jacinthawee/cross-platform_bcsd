
int ssl_parse_clienthello_tlsext(SSL *param_1,ushort **param_2,ushort *param_3,undefined4 *param_4)

{
  char cVar1;
  byte bVar2;
  undefined uVar3;
  ushort uVar4;
  bool bVar5;
  bool bVar6;
  undefined *puVar7;
  undefined *puVar8;
  uint uVar9;
  int iVar10;
  stack_st_SRTP_PROTECTION_PROFILE *psVar11;
  BIO *pBVar12;
  stack_st_OCSP_RESPID *psVar13;
  SRTP_PROTECTION_PROFILE *pSVar14;
  undefined4 uVar15;
  ushort *puVar16;
  uint uVar17;
  char *pcVar18;
  SSL_SESSION *pSVar19;
  ssl3_state_st *psVar20;
  char *pcVar21;
  int iVar22;
  uint uVar23;
  uint unaff_s4;
  ushort *puVar24;
  int iVar25;
  ushort *puVar26;
  ushort *puVar27;
  uint local_4c;
  ushort *local_30;
  int local_2c;
  
  puVar8 = PTR___stack_chk_guard_006a9ae8;
  pSVar14 = param_1->srtp_profile;
  uVar9 = param_1->references;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  psVar20 = param_1->s3;
  puVar24 = *param_2;
  param_1->tlsext_hostname = (char *)0x0;
  param_1->servername_done = -1;
  psVar20->next_proto_neg_seen = 0;
  param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)pSVar14 & 0xfffffffc);
  if (((((uVar9 & 0x40) != 0) && (2 < (int)param_3 - (int)puVar24)) &&
      (3 < (int)param_3 - (int)(puVar24 + 1))) &&
     ((puVar24[1] == 0 &&
      (puVar26 = (ushort *)((int)(puVar24 + 3) + (uint)puVar24[2]),
      (int)(uint)puVar24[2] <= (int)param_3 - (int)(puVar24 + 3))))) {
    if ((param_1->first_packet >> 8 == 3) && (0x302 < param_1->first_packet)) {
      if (((param_3 + -0x11 == puVar26) &&
          (iVar25 = (*(code *)PTR_memcmp_006a9ad0)(puVar26,kSafariExtensionsBlock_17613,0x12),
          iVar25 == 0)) &&
         (iVar25 = (*(code *)PTR_memcmp_006a9ad0)
                             (puVar26 + 9,kSafariTLS12ExtensionsBlock_17614,0x10), iVar25 == 0)) {
        *(undefined *)&psVar20[1].flags = 1;
      }
    }
    else if ((param_3 + -9 == puVar26) &&
            (iVar25 = (*(code *)PTR_memcmp_006a9ad0)(puVar26,kSafariExtensionsBlock_17613,0x12),
            iVar25 == 0)) {
      *(undefined *)&psVar20[1].flags = 1;
    }
  }
  if (param_1[1].rbio != (BIO *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    param_1[1].rbio = (BIO *)0x0;
  }
  param_1->srtp_profiles = (stack_st_SRTP_PROTECTION_PROFILE *)0x0;
  if (puVar24 != param_3) {
    puVar26 = local_30;
    if ((int)param_3 - (int)puVar24 < 2) goto LAB_00494534;
    puVar27 = puVar24 + 1;
    if ((int)param_3 - (int)puVar27 != (uint)*puVar24) goto LAB_00494534;
    puVar16 = puVar24 + 3;
    if (3 < (int)param_3 - (int)puVar27) {
      uVar4 = puVar24[1];
      local_4c = (uint)puVar24[2];
      if ((int)param_3 - (int)puVar16 < (int)local_4c) goto LAB_00494534;
      bVar5 = false;
      bVar6 = false;
      do {
        if ((code *)param_1->max_send_fragment != (code *)0x0) {
          (*(code *)param_1->max_send_fragment)
                    (param_1,0,uVar4,puVar16,local_4c,param_1->tlsext_debug_cb);
        }
        puVar7 = PTR_CRYPTO_malloc_006a7008;
        puVar26 = local_30;
        if (uVar4 == 0) {
          if (local_4c < 2) goto LAB_00494534;
          local_4c = local_4c - 2 & 0xffff;
          uVar9 = (uint)*puVar16;
          if (local_4c < uVar9) goto LAB_00494534;
          iVar22 = uVar9 - 3;
          if (3 < uVar9) {
            unaff_s4 = (uint)*(ushort *)((int)puVar27 + 7);
            cVar1 = *(char *)(puVar27 + 3);
            if (iVar22 < (int)unaff_s4) goto LAB_00494534;
            pcVar18 = param_1->tlsext_hostname;
            pcVar21 = (char *)((int)puVar27 + 9);
            do {
              if ((pcVar18 == (char *)0x0) && (cVar1 == '\0')) {
                iVar25 = param_1->hit;
                if (iVar25 == 0) {
                  pSVar19 = param_1->session;
                  puVar26 = local_30;
                  if (*(int *)(pSVar19->krb5_client_princ + 0x40) != 0) goto LAB_00494534;
                  if (unaff_s4 < 0x100) {
                    iVar10 = (*(code *)PTR_CRYPTO_malloc_006a7008)(unaff_s4 + 1,"t1_lib.c",1099);
                    *(int *)(pSVar19->krb5_client_princ + 0x40) = iVar10;
                    if (iVar10 == 0) goto LAB_00494c34;
                    (*(code *)PTR_memcpy_006a9aec)
                              (*(undefined4 *)(param_1->session->krb5_client_princ + 0x40),pcVar21,
                               unaff_s4);
                    puVar7 = PTR_strlen_006a9a24;
                    *(undefined *)(*(int *)(param_1->session->krb5_client_princ + 0x40) + unaff_s4)
                         = 0;
                    uVar15 = *(undefined4 *)(param_1->session->krb5_client_princ + 0x40);
                    uVar9 = (*(code *)puVar7)(uVar15);
                    if (unaff_s4 == uVar9) {
                      pcVar18 = (char *)0x1;
                      param_1->tlsext_hostname = (char *)0x1;
                      goto LAB_004947d0;
                    }
                    (*(code *)PTR_CRYPTO_free_006a6e88)(uVar15);
                    *(undefined4 *)(param_1->session->krb5_client_princ + 0x40) = 0;
                  }
                  *param_4 = 0x70;
                  goto LAB_0049453c;
                }
                iVar25 = *(int *)(param_1->session->krb5_client_princ + 0x40);
                if ((iVar25 == 0) ||
                   (uVar9 = (*(code *)PTR_strlen_006a9a24)(iVar25), uVar9 != unaff_s4)) {
                  param_1->tlsext_hostname = (char *)0x0;
                }
                else {
                  iVar25 = (*(code *)PTR_strncmp_006a9970)(iVar25,pcVar21,unaff_s4);
                  pcVar18 = (char *)(uint)(iVar25 == 0);
                  param_1->tlsext_hostname = pcVar18;
                }
              }
LAB_004947d0:
              uVar9 = iVar22 - unaff_s4;
              iVar22 = uVar9 - 3;
              if ((int)uVar9 < 4) break;
              unaff_s4 = (uint)*(ushort *)(pcVar21 + 1);
              cVar1 = *pcVar21;
              pcVar21 = pcVar21 + 3;
              puVar26 = local_30;
              if (iVar22 < (int)unaff_s4) goto LAB_00494534;
            } while( true );
          }
          puVar16 = puVar27 + 3;
          puVar26 = local_30;
          if (uVar9 != 0) goto LAB_00494534;
        }
        else if (uVar4 == 0xc) {
          if (local_4c == 0) goto LAB_00494534;
          uVar9 = (uint)*(byte *)(puVar27 + 2);
          if (uVar9 != local_4c - 1) goto LAB_00494534;
          if (param_1[1].rbio != (BIO *)0x0) goto LAB_00494534;
          pBVar12 = (BIO *)(*(code *)PTR_CRYPTO_malloc_006a7008)(local_4c,"t1_lib.c",0x471);
          param_1[1].rbio = pBVar12;
          if (pBVar12 == (BIO *)0x0) {
            iVar25 = -1;
            goto LAB_0049453c;
          }
          (*(code *)PTR_memcpy_006a9aec)(pBVar12,(undefined *)((int)puVar27 + 5),uVar9);
          puVar7 = PTR_strlen_006a9a24;
          *(undefined *)((int)&(param_1[1].rbio)->method + uVar9) = 0;
          uVar23 = (*(code *)puVar7)(param_1[1].rbio);
          puVar26 = local_30;
          if (uVar9 != uVar23) goto LAB_00494534;
        }
        else if (uVar4 == 0xb) {
          uVar9 = (uint)*(byte *)(puVar27 + 2);
          if (uVar9 != local_4c - 1) goto LAB_00494534;
          if (param_1->hit == 0) {
            pSVar19 = param_1->session;
            if (*(int *)(pSVar19->krb5_client_princ + 0x48) != 0) {
              (*(code *)PTR_CRYPTO_free_006a6e88)();
              pSVar19 = param_1->session;
              *(undefined4 *)(pSVar19->krb5_client_princ + 0x48) = 0;
            }
            puVar7 = PTR_CRYPTO_malloc_006a7008;
            *(undefined4 *)(pSVar19->krb5_client_princ + 0x44) = 0;
            iVar25 = (*(code *)puVar7)(uVar9,"t1_lib.c",0x489);
            *(int *)(pSVar19->krb5_client_princ + 0x48) = iVar25;
            puVar7 = PTR_memcpy_006a9aec;
            if (iVar25 == 0) goto LAB_00494c34;
            pSVar19 = param_1->session;
            *(uint *)(pSVar19->krb5_client_princ + 0x44) = uVar9;
            (*(code *)puVar7)(*(undefined4 *)(pSVar19->krb5_client_princ + 0x48),
                              (undefined *)((int)puVar27 + 5),uVar9);
          }
        }
        else if (uVar4 == 10) {
          uVar9 = (uint)*(byte *)((int)puVar27 + 5) + (uint)*(byte *)(puVar27 + 2) * 0x100;
          if (uVar9 != local_4c - 2) goto LAB_00494534;
          if (uVar9 == 0) goto LAB_00494534;
          if ((uVar9 & 1) != 0) goto LAB_00494534;
          if (param_1->hit == 0) {
            pSVar19 = param_1->session;
            if (*(int *)(pSVar19->krb5_client_princ + 0x50) != 0) goto LAB_00494534;
            *(undefined4 *)(pSVar19->krb5_client_princ + 0x4c) = 0;
            iVar25 = (*(code *)puVar7)(uVar9,"t1_lib.c",0x4ac);
            *(int *)(pSVar19->krb5_client_princ + 0x50) = iVar25;
            puVar7 = PTR_memcpy_006a9aec;
            if (iVar25 == 0) goto LAB_00494c34;
            pSVar19 = param_1->session;
            *(uint *)(pSVar19->krb5_client_princ + 0x4c) = uVar9;
            (*(code *)puVar7)(*(undefined4 *)(pSVar19->krb5_client_princ + 0x50),puVar27 + 3,uVar9);
          }
        }
        else if (uVar4 == 0x23) {
          if ((param_1->tlsext_session_ticket != (TLS_SESSION_TICKET_EXT *)0x0) &&
             (iVar25 = (*(code *)param_1->tlsext_session_ticket)
                                 (param_1,puVar16,local_4c,param_1->tls_session_ticket_ext_cb),
             iVar25 == 0)) {
LAB_00494c34:
            iVar25 = 0;
            *param_4 = 0x50;
            goto LAB_0049453c;
          }
        }
        else if (uVar4 == 0xff01) {
          iVar25 = (*(code *)PTR_ssl_parse_clienthello_renegotiate_ext_006a81e4)
                             (param_1,puVar16,local_4c,param_4);
          if (iVar25 == 0) {
LAB_00494904:
            iVar25 = 0;
            goto LAB_0049453c;
          }
          bVar6 = true;
        }
        else if (uVar4 == 0xd) {
          if (bVar5) goto LAB_00494534;
          if (local_4c < 2) goto LAB_00494534;
          uVar4 = *puVar16;
          puVar16 = puVar27 + 3;
          local_4c = local_4c - 2 & 0xffff;
          if (uVar4 != local_4c) goto LAB_00494534;
          if ((uVar4 & 1) != 0) goto LAB_00494534;
          iVar25 = tls1_process_sigalgs(param_1,puVar16);
          puVar26 = local_30;
          if (iVar25 == 0) goto LAB_00494534;
          bVar5 = true;
        }
        else if (uVar4 == 5) {
          if (param_1->version == 0xfeff) {
LAB_004948a4:
            if ((((param_1->method->version == 0xfeff) &&
                 (psVar11 = SSL_get_srtp_profiles(param_1),
                 psVar11 != (stack_st_SRTP_PROTECTION_PROFILE *)0x0)) && (uVar4 == 0xe)) &&
               (iVar25 = ssl_parse_clienthello_use_srtp_ext(param_1,puVar16,local_4c,param_4),
               iVar25 != 0)) goto LAB_00494904;
          }
          else {
            if (local_4c < 5) goto LAB_00494534;
            bVar2 = *(byte *)(puVar27 + 2);
            puVar16 = (ushort *)((int)puVar27 + 5);
            param_1->servername_done = (uint)bVar2;
            if (bVar2 == 1) {
              uVar23 = (uint)*(ushort *)((int)puVar27 + 5);
              uVar9 = local_4c - 3 & 0xffff;
              puVar24 = (ushort *)((int)puVar27 + 7);
              if (uVar9 < uVar23) goto LAB_00494534;
              (*(code *)PTR_sk_pop_free_006a7058)
                        (param_1->tlsext_status_expected,PTR_OCSP_RESPID_free_006a81e8);
              if (uVar23 == 0) {
                param_1->tlsext_status_expected = 0;
                uVar3 = *(undefined *)puVar24;
              }
              else {
                iVar25 = (*(code *)PTR_sk_new_null_006a6fa4)();
                param_1->tlsext_status_expected = iVar25;
                if (iVar25 == 0) {
LAB_00494f90:
                  iVar25 = 0;
                  *param_4 = 0x50;
                  goto LAB_0049453c;
                }
                puVar26 = local_30;
                if (uVar23 < 4) goto LAB_00494534;
                uVar17 = (uint)*(ushort *)((int)puVar27 + 7);
                uVar9 = (uVar9 - uVar17) - 2;
                iVar25 = uVar23 - (uVar17 + 2);
                puVar24 = (ushort *)((int)puVar27 + 9);
                while( true ) {
                  local_30 = puVar24;
                  if (iVar25 < 0) goto LAB_00494534;
                  uVar9 = uVar9 & 0xffff;
                  puVar24 = (ushort *)((int)local_30 + uVar17);
                  unaff_s4 = (*(code *)PTR_d2i_OCSP_RESPID_006a81ec)(0,&local_30,uVar17);
                  puVar26 = local_30;
                  if (unaff_s4 == 0) goto LAB_00494534;
                  if (puVar24 != local_30) goto LAB_00494fb0;
                  iVar22 = (*(code *)PTR_sk_push_006a6fa8)(param_1->tlsext_status_expected,unaff_s4)
                  ;
                  if (iVar22 == 0) {
                    (*(code *)PTR_OCSP_RESPID_free_006a81e8)(unaff_s4);
                    goto LAB_00494f90;
                  }
                  puVar26 = local_30;
                  if (iVar25 == 0) break;
                  if (iVar25 < 4) goto LAB_00494534;
                  uVar17 = (uint)*puVar24;
                  iVar25 = iVar25 - (uVar17 + 2);
                  uVar9 = uVar9 + (-2 - uVar17);
                  puVar24 = puVar24 + 1;
                }
                if (uVar9 < 2) goto LAB_00494534;
                uVar3 = *(undefined *)puVar24;
              }
              puVar16 = puVar24 + 1;
              local_4c = uVar9 - 2 & 0xffff;
              uVar9 = (uint)CONCAT11(uVar3,*(undefined *)((int)puVar24 + 1));
              puVar26 = local_30;
              if (uVar9 != local_4c) goto LAB_00494534;
              local_30 = puVar16;
              if (uVar9 != 0) {
                if (param_1->tlsext_ocsp_ids != (stack_st_OCSP_RESPID *)0x0) {
                  (*(code *)PTR_sk_pop_free_006a7058)
                            (param_1->tlsext_ocsp_ids,PTR_X509_EXTENSION_free_006a7168);
                }
                psVar13 = (stack_st_OCSP_RESPID *)
                          (*(code *)PTR_d2i_X509_EXTENSIONS_006a81f0)(0,&local_30,uVar9);
                param_1->tlsext_ocsp_ids = psVar13;
                puVar26 = local_30;
                if (psVar13 == (stack_st_OCSP_RESPID *)0x0) goto LAB_00494534;
                if (local_30 != (ushort *)((int)puVar16 + uVar9)) goto LAB_00494534;
              }
            }
            else {
              param_1->servername_done = -1;
              local_4c = local_4c - 1 & 0xffff;
            }
          }
        }
        else if (uVar4 == 0xf) {
          if (*(char *)(puVar27 + 2) == '\x01') {
            param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 1);
          }
          else {
            if (*(char *)(puVar27 + 2) != '\x02') {
              iVar25 = 0;
              *param_4 = 0x2f;
              goto LAB_0049453c;
            }
            param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 3);
          }
        }
        else {
          if ((uVar4 != 0x3374) || ((param_1->s3->tmp).finish_md_len != 0)) goto LAB_004948a4;
          param_1->s3->next_proto_neg_seen = 1;
        }
        puVar27 = (ushort *)((int)puVar16 + local_4c);
        puVar16 = puVar27 + 2;
        puVar26 = local_30;
        if ((int)param_3 - (int)puVar27 < 4) goto LAB_00494d88;
        uVar4 = *puVar27;
        local_4c = (uint)puVar27[1];
        if ((int)param_3 - (int)puVar16 < (int)local_4c) goto LAB_00494534;
      } while( true );
    }
    if (param_3 != puVar27) goto LAB_00494534;
    *param_2 = param_3;
  }
LAB_0049491c:
  puVar7 = PTR_ERR_put_error_006a7f34;
  iVar25 = 1;
  if ((param_1->tlsext_hb_seq != 0) && (-1 < param_1->references << 0xd)) {
    *param_4 = 0x28;
    iVar25 = 0;
    (*(code *)puVar7)(0x14,0x12e,0x152,"t1_lib.c",0x58e);
  }
LAB_0049453c:
  while (local_2c != *(int *)puVar8) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00494fb0:
    (*(code *)PTR_OCSP_RESPID_free_006a81e8)(unaff_s4);
    puVar26 = local_30;
LAB_00494534:
    local_30 = puVar26;
    iVar25 = 0;
    *param_4 = 0x32;
  }
  return iVar25;
LAB_00494d88:
  if (param_3 != puVar27) goto LAB_00494534;
  *param_2 = param_3;
  iVar25 = 1;
  if (bVar6) goto LAB_0049453c;
  goto LAB_0049491c;
}

