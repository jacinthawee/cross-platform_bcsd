
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort ********
ssl_add_serverhello_tlsext(SSL *param_1,ushort ********param_2,ushort ********param_3,char *param_4)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  _func_3154 *p_Var7;
  long lVar8;
  ushort **ppuVar9;
  ushort ********ppppppppuVar10;
  uint uVar11;
  SSL_CTX *pSVar12;
  stack_st_SSL_CIPHER *psVar13;
  int iVar14;
  undefined4 uVar15;
  ushort **ppuVar16;
  SRTP_PROTECTION_PROFILE *pSVar17;
  SSL_SESSION *pSVar18;
  ushort **ppuVar19;
  SSL *pSVar20;
  ushort *******pppppppuVar21;
  uint uVar22;
  undefined1 *puVar23;
  ushort ********ppppppppuVar24;
  ushort *puVar25;
  undefined uVar26;
  ushort ********ppppppppuVar27;
  ushort *puVar28;
  ushort *puVar29;
  ushort ********ppppppppuVar30;
  ushort ********ppppppppuVar31;
  ushort *******pppppppuVar32;
  SSL_SESSION *pSVar33;
  ushort *******pppppppuVar34;
  uint uVar35;
  ushort ********unaff_s5;
  ushort ********unaff_s6;
  code *pcVar36;
  ushort *******pppppppuVar37;
  undefined uStack_a1;
  undefined4 uStack_a0;
  SSL *pSStack_9c;
  ushort ********ppppppppuStack_98;
  SSL *pSStack_94;
  ushort ********ppppppppuStack_90;
  undefined *puStack_8c;
  ushort ********ppppppppuStack_88;
  ushort ********ppppppppuStack_84;
  ushort ********ppppppppuStack_80;
  undefined4 *local_60;
  ushort ********local_50;
  ushort ********local_4c;
  ushort *local_48 [8];
  ushort *puStack_28;
  SSL *local_24;
  
  puStack_8c = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(SSL **)PTR___stack_chk_guard_006a9ae8;
  ppppppppuStack_98 = (ushort ********)((int)param_2 + 2);
  ppppppppuVar24 = param_2;
  ppppppppuVar27 = param_3;
  if (((param_1->version != 0x300) ||
      (ppppppppuVar10 = param_2, param_1->s3->send_connection_binding != 0)) &&
     (ppppppppuVar10 = (ushort ********)0x0, ppppppppuStack_98 < param_3)) {
    ppppppppuVar31 = ppppppppuStack_98;
    if (((param_1->hit == 0) && (param_1->tlsext_hostname == (char *)0x1)) &&
       (*(int *)(param_1->session->krb5_client_princ + 0x40) != 0)) {
      ppppppppuVar31 = (ushort ********)((int)param_2 + 6);
      if (3 < (int)param_3 - (int)ppppppppuStack_98) {
        *(undefined *)((int)param_2 + 2) = 0;
        *(undefined *)((int)param_2 + 3) = 0;
        *(undefined *)(param_2 + 1) = 0;
        *(undefined *)((int)param_2 + 5) = 0;
        goto LAB_00492870;
      }
    }
    else {
LAB_00492870:
      ppppppppuStack_98 = ppppppppuVar31;
      if (param_1->s3->send_connection_binding == 0) {
LAB_00492880:
        if (param_1->tlsext_ecpointformatlist_length != 0) {
          puVar5 = (undefined *)((int)param_3 + (-5 - (int)ppppppppuStack_98));
          ppppppppuVar31 = ppppppppuStack_98;
          if (((int)puVar5 < 0) || (puVar5 < (undefined *)param_1->tlsext_ticket_expected))
          goto LAB_00492b20;
          if ((undefined *)0xff < (undefined *)param_1->tlsext_ticket_expected) {
            ppppppppuVar27 = (ushort ********)0x44;
            param_4 = "t1_lib.c";
            local_60 = (undefined4 *)0x2fe;
            ppppppppuVar24 = (ushort ********)0x116;
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14);
            ppppppppuVar10 = (ushort ********)0x0;
            goto LAB_00492a6c;
          }
          *(undefined *)ppppppppuStack_98 = 0;
          puVar5 = PTR_memcpy_006a9aec;
          *(undefined *)((int)ppppppppuStack_98 + 1) = 0xb;
          *(char *)((int)ppppppppuStack_98 + 2) =
               (char)((uint)(param_1->tlsext_ticket_expected + 1) >> 8);
          *(char *)((int)ppppppppuStack_98 + 3) = (char)param_1->tlsext_ticket_expected + '\x01';
          *(char *)(ppppppppuStack_98 + 1) = (char)param_1->tlsext_ticket_expected;
          ppppppppuVar27 = (ushort ********)param_1->tlsext_ticket_expected;
          ppppppppuVar24 = (ushort ********)param_1->tlsext_ecpointformatlist_length;
          iVar6 = (*(code *)puVar5)((int)ppppppppuStack_98 + 5);
          ppppppppuStack_98 = (ushort ********)(iVar6 + param_1->tlsext_ticket_expected);
        }
        ppppppppuVar30 = ppppppppuStack_98;
        if (param_1->tlsext_ocsp_resplen != 0) {
          param_4 = (char *)0x0;
          ppppppppuVar27 = (ushort ********)0x0;
          ppppppppuVar24 = (ushort ********)&DAT_00000020;
          uVar35 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
          if ((uVar35 & 0x4000) == 0) {
            ppppppppuVar10 = (ushort ********)0x0;
            if ((int)param_3 - (int)ppppppppuStack_98 < 4) goto LAB_00492a6c;
            *(undefined *)ppppppppuStack_98 = 0;
            *(undefined *)((int)ppppppppuStack_98 + 2) = 0;
            ppppppppuVar30 = ppppppppuStack_98 + 1;
            *(undefined *)((int)ppppppppuStack_98 + 3) = 0;
            *(undefined *)((int)ppppppppuStack_98 + 1) = 0x23;
          }
        }
        ppppppppuVar31 = ppppppppuVar30;
        if (param_1->tlsext_status_type != 0) {
          ppppppppuVar10 = (ushort ********)0x0;
          ppppppppuStack_98 = ppppppppuVar30;
          if ((int)param_3 - (int)ppppppppuVar30 < 4) goto LAB_00492a6c;
          *(undefined *)ppppppppuVar30 = 0;
          *(undefined *)((int)ppppppppuVar30 + 2) = 0;
          ppppppppuVar31 = ppppppppuVar30 + 1;
          *(undefined *)((int)ppppppppuVar30 + 3) = 0;
          *(undefined *)((int)ppppppppuVar30 + 1) = 5;
        }
        if ((param_1->method->version == 0xfeff) &&
           (param_1->srtp_profiles != (stack_st_SRTP_PROTECTION_PROFILE *)0x0)) {
          unaff_s5 = (ushort ********)&local_4c;
          ppppppppuVar24 = (ushort ********)0x0;
          ppppppppuVar27 = unaff_s5;
          ssl_add_serverhello_use_srtp_ext(param_1,0,unaff_s5,0);
          param_4 = (char *)local_4c;
          if ((int)((int)param_3 + ((-4 - (int)ppppppppuVar31) - (int)local_4c)) < 0)
          goto LAB_00492b20;
          *(undefined *)ppppppppuVar31 = 0;
          unaff_s6 = ppppppppuVar31 + 1;
          *(char *)((int)ppppppppuVar31 + 3) = (char)local_4c;
          *(char *)((int)ppppppppuVar31 + 2) = (char)((uint)local_4c >> 8);
          *(undefined *)((int)ppppppppuVar31 + 1) = 0xe;
          ppppppppuVar24 = unaff_s6;
          ppppppppuVar27 = unaff_s5;
          iVar6 = ssl_add_serverhello_use_srtp_ext(param_1);
          if (iVar6 != 0) {
            local_60 = (undefined4 *)0x33b;
            goto LAB_00492b0c;
          }
          ppppppppuVar31 = (ushort ********)((int)unaff_s6 + (int)local_4c);
        }
        if (*(ushort *)((int)&((param_1->s3->tmp).new_cipher)->id + 2) - 0x80 < 2) {
          param_4 = (char *)0x0;
          ppppppppuVar27 = (ushort ********)0x0;
          ppppppppuVar24 = (ushort ********)&DAT_00000020;
          lVar8 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
          if (lVar8 < 0) {
            ppuVar9 = (ushort **)&DAT_00647480;
            ppuVar16 = local_48;
            do {
              puVar29 = *ppuVar9;
              ppuVar19 = ppuVar16 + 4;
              param_4 = (char *)ppuVar9[1];
              puVar28 = ppuVar9[2];
              puVar25 = ppuVar9[3];
              ppuVar9 = ppuVar9 + 4;
              *ppuVar16 = puVar29;
              ppuVar16[1] = (ushort *)param_4;
              ppuVar16[2] = puVar28;
              ppuVar16[3] = puVar25;
              ppuVar16 = ppuVar19;
            } while (ppuVar9 != (ushort **)&UNK_006474a0);
            ppppppppuVar24 = (ushort ********)(uint)((int)param_3 - (int)ppppppppuVar31 < 0x24);
            *ppuVar19 = (ushort *)_UNK_006474a0;
            ppppppppuVar27 = _UNK_006474a0;
            if (ppppppppuVar24 != (ushort ********)0x0) goto LAB_00492b20;
            ppppppppuVar10 = ppppppppuVar31;
            ppuVar16 = local_48;
            do {
              param_4 = (char *)*ppuVar16;
              ppuVar9 = ppuVar16 + 4;
              ppppppppuVar27 = (ushort ********)ppuVar16[1];
              ppppppppuVar24 = (ushort ********)ppuVar16[2];
              pppppppuVar21 = (ushort *******)ppuVar16[3];
              *ppppppppuVar10 = (ushort *******)param_4;
              ppppppppuVar10[1] = (ushort *******)ppppppppuVar27;
              ppppppppuVar10[2] = (ushort *******)ppppppppuVar24;
              ppppppppuVar10[3] = pppppppuVar21;
              ppppppppuVar10 = ppppppppuVar10 + 4;
              ppuVar16 = ppuVar9;
            } while (ppuVar9 != &puStack_28);
            ppppppppuVar31 = ppppppppuVar31 + 9;
            *ppppppppuVar10 = (ushort *******)*ppuVar9;
          }
        }
        ppppppppuStack_98 = ppppppppuVar31;
        if (((uint)param_1->srtp_profile & 1) == 0) {
LAB_004929b4:
          iVar6 = param_1->s3->next_proto_neg_seen;
          param_1->s3->next_proto_neg_seen = 0;
          if (iVar6 != 0) {
            p_Var7 = param_1->psk_server_callback;
LAB_004929c8:
            ppppppppuVar27 = (ushort ********)&local_4c;
            if (*(code **)(p_Var7 + 0x1a4) != (code *)0x0) {
              param_4 = *(char **)(p_Var7 + 0x1a8);
              ppppppppuVar24 = (ushort ********)&local_50;
              iVar6 = (**(code **)(p_Var7 + 0x1a4))(param_1);
              puVar5 = PTR_memcpy_006a9aec;
              if (iVar6 == 0) {
                param_3 = (ushort ********)
                          ((int)param_3 + ((-4 - (int)local_4c) - (int)ppppppppuStack_98));
                ppppppppuVar31 = ppppppppuStack_98;
                unaff_s5 = local_4c;
                if ((int)param_3 < 0) goto LAB_00492b20;
                *(char *)((int)ppppppppuStack_98 + 3) = (char)local_4c;
                *(undefined *)ppppppppuStack_98 = 0x33;
                *(char *)((int)ppppppppuStack_98 + 2) = (char)((uint)local_4c >> 8);
                *(undefined *)((int)ppppppppuStack_98 + 1) = 0x74;
                ppppppppuVar27 = local_4c;
                iVar6 = (*(code *)puVar5)(ppppppppuStack_98 + 1);
                ppppppppuStack_98 = (ushort ********)(iVar6 + (int)local_4c);
                param_1->s3->next_proto_neg_seen = 1;
                ppppppppuVar24 = local_50;
              }
            }
          }
        }
        else {
          if ((int)param_3 - (int)ppppppppuVar31 < 5) goto LAB_00492b20;
          *(undefined *)ppppppppuVar31 = 0;
          *(undefined *)((int)ppppppppuVar31 + 2) = 0;
          *(undefined *)((int)ppppppppuVar31 + 1) = 0xf;
          *(undefined *)((int)ppppppppuVar31 + 3) = 1;
          if (((uint)param_1->srtp_profile & 4) != 0) {
            ppppppppuStack_98 = (ushort ********)((int)ppppppppuVar31 + 5);
            *(undefined *)(ppppppppuVar31 + 1) = 2;
            goto LAB_004929b4;
          }
          *(undefined *)(ppppppppuVar31 + 1) = 1;
          ppppppppuStack_98 = (ushort ********)((int)ppppppppuVar31 + 5);
          iVar6 = param_1->s3->next_proto_neg_seen;
          param_1->s3->next_proto_neg_seen = 0;
          if (iVar6 != 0) {
            p_Var7 = param_1->psk_server_callback;
            goto LAB_004929c8;
          }
        }
        iVar6 = (int)ppppppppuStack_98 + (-2 - (int)param_2);
        ppppppppuVar10 = param_2;
        if (iVar6 != 0) {
          *(char *)((int)param_2 + 1) = (char)iVar6;
          *(char *)param_2 = (char)((uint)iVar6 >> 8);
          ppppppppuVar10 = ppppppppuStack_98;
        }
        goto LAB_00492a6c;
      }
      unaff_s5 = (ushort ********)&local_4c;
      ppppppppuVar24 = (ushort ********)0x0;
      ppppppppuVar27 = unaff_s5;
      iVar6 = (*(code *)PTR_ssl_add_serverhello_renegotiate_ext_006a81c0)(param_1,0,unaff_s5,0);
      puVar5 = PTR_ssl_add_serverhello_renegotiate_ext_006a81c0;
      if (iVar6 == 0) {
        local_60 = (undefined4 *)0x2e1;
      }
      else {
        param_4 = (char *)local_4c;
        if ((int)((int)param_3 + ((-4 - (int)ppppppppuVar31) - (int)local_4c)) < 0)
        goto LAB_00492b20;
        *(char *)((int)ppppppppuVar31 + 3) = (char)local_4c;
        unaff_s6 = ppppppppuVar31 + 1;
        *(undefined *)ppppppppuVar31 = 0xff;
        *(char *)((int)ppppppppuVar31 + 2) = (char)((uint)local_4c >> 8);
        *(undefined *)((int)ppppppppuVar31 + 1) = 1;
        ppppppppuVar24 = unaff_s6;
        ppppppppuVar27 = unaff_s5;
        iVar6 = (*(code *)puVar5)(param_1);
        if (iVar6 != 0) {
          ppppppppuStack_98 = (ushort ********)((int)unaff_s6 + (int)local_4c);
          goto LAB_00492880;
        }
        local_60 = (undefined4 *)0x2ec;
      }
LAB_00492b0c:
      param_4 = "t1_lib.c";
      unaff_s5 = (ushort ********)&local_4c;
      ppppppppuVar27 = (ushort ********)0x44;
      ppppppppuVar24 = (ushort ********)0x116;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14);
    }
LAB_00492b20:
    ppppppppuVar10 = (ushort ********)0x0;
    ppppppppuStack_98 = ppppppppuVar31;
  }
LAB_00492a6c:
  if (local_24 == *(SSL **)puStack_8c) {
    return ppppppppuVar10;
  }
  pSVar20 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar5 = PTR___stack_chk_guard_006a9ae8;
  pppppppuVar37 = (ushort *******)((int)ppppppppuVar27 + (int)param_4);
  pppppppuVar21 = *ppppppppuVar24;
  pSVar17 = pSVar20->srtp_profile;
  pSStack_9c = *(SSL **)PTR___stack_chk_guard_006a9ae8;
  pSVar20->s3->next_proto_neg_seen = 0;
  pSVar20->tlsext_ocsp_resplen = 0;
  pSVar20->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)pSVar17 & 0xfffffffc);
  pSStack_94 = param_1;
  ppppppppuStack_90 = param_3;
  ppppppppuStack_88 = param_2;
  ppppppppuStack_84 = unaff_s5;
  ppppppppuStack_80 = unaff_s6;
  if (2 < (int)pppppppuVar37 - (int)pppppppuVar21) {
    pppppppuVar32 = (ushort *******)((int)pppppppuVar21 + 2);
    if ((int)pppppppuVar37 - (int)pppppppuVar32 != (uint)*(ushort *)pppppppuVar21) {
LAB_00492ea0:
      ppppppppuVar27 = (ushort ********)0x0;
      *local_60 = 0x32;
      goto LAB_00492ea8;
    }
    pppppppuVar34 = (ushort *******)((int)pppppppuVar21 + 6);
    if ((int)pppppppuVar37 - (int)pppppppuVar32 < 4) {
      bVar2 = false;
      bVar3 = false;
LAB_00493320:
      if (pppppppuVar37 != pppppppuVar32) goto LAB_00492ea0;
      if (((pSVar20->hit == 0) && (bVar3)) && (pSVar20->tlsext_debug_arg != (void *)0x0)) {
        pSVar33 = pSVar20->session;
        if (*(int *)(pSVar33->krb5_client_princ + 0x40) != 0) goto LAB_00492ea0;
        uVar15 = (*(code *)PTR_BUF_strdup_006a6fdc)();
        pSVar18 = pSVar20->session;
        *(undefined4 *)(pSVar33->krb5_client_princ + 0x40) = uVar15;
        if (*(int *)(pSVar18->krb5_client_princ + 0x40) == 0) {
LAB_0049338c:
          ppppppppuVar27 = (ushort ********)0x0;
          *local_60 = 0x70;
          goto LAB_00492ea8;
        }
      }
      *ppppppppuVar24 = pppppppuVar37;
    }
    else {
      uVar1 = *(ushort *)((int)pppppppuVar21 + 2);
      uVar35 = (uint)*(ushort *)(pppppppuVar21 + 1);
      if ((int)pppppppuVar37 - (int)pppppppuVar34 < (int)uVar35) goto LAB_00492e5c;
      bVar2 = false;
      bVar3 = false;
      do {
        if ((code *)pSVar20->max_send_fragment != (code *)0x0) {
          (*(code *)pSVar20->max_send_fragment)
                    (pSVar20,1,uVar1,pppppppuVar34,uVar35,pSVar20->tlsext_debug_cb);
        }
        if (uVar1 == 0) {
          if ((pSVar20->tlsext_debug_arg == (void *)0x0) || (uVar35 != 0)) goto LAB_0049338c;
          uVar35 = 0;
          bVar3 = true;
        }
        else if (uVar1 == 0xb) {
          uVar11 = (uint)*(byte *)(pppppppuVar32 + 1);
          if ((uVar11 != uVar35 - 1) || (uVar11 == 0)) goto LAB_00492ea0;
          if (pSVar20->hit == 0) {
            pSVar33 = pSVar20->session;
            *(undefined4 *)(pSVar33->krb5_client_princ + 0x44) = 0;
            if (*(int *)(pSVar33->krb5_client_princ + 0x48) != 0) {
              (*(code *)PTR_CRYPTO_free_006a6e88)();
              pSVar33 = pSVar20->session;
            }
            iVar6 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar11,"t1_lib.c",0x5ea);
            *(int *)(pSVar33->krb5_client_princ + 0x48) = iVar6;
            puVar4 = PTR_memcpy_006a9aec;
            if (iVar6 == 0) goto LAB_004933c4;
            pSVar33 = pSVar20->session;
            *(uint *)(pSVar33->krb5_client_princ + 0x44) = uVar11;
            (*(code *)puVar4)(*(undefined4 *)(pSVar33->krb5_client_princ + 0x48),
                              (byte *)((int)pppppppuVar32 + 5),uVar11);
          }
        }
        else if (uVar1 == 0x23) {
          if ((pSVar20->tlsext_session_ticket != (TLS_SESSION_TICKET_EXT *)0x0) &&
             (iVar6 = (*(code *)pSVar20->tlsext_session_ticket)
                                (pSVar20,pppppppuVar34,uVar35,pSVar20->tls_session_ticket_ext_cb),
             iVar6 == 0)) {
LAB_004933c4:
            ppppppppuVar27 = (ushort ********)0x0;
            *local_60 = 0x50;
            goto LAB_00492ea8;
          }
          uVar11 = SSL_ctrl(pSVar20,0x20,0,(void *)0x0);
          if (((uVar11 & 0x4000) != 0) || (uVar35 != 0)) {
LAB_004933b4:
            ppppppppuVar27 = (ushort ********)0x0;
            *local_60 = 0x6e;
            goto LAB_00492ea8;
          }
          uVar35 = 0;
          pSVar20->tlsext_ocsp_resplen = 1;
        }
        else if (uVar1 == 5) {
          if (pSVar20->version != 0xfeff) {
            if ((pSVar20->servername_done == -1) || (uVar35 != 0)) goto LAB_004933b4;
            uVar35 = 0;
            pSVar20->tlsext_status_type = 1;
          }
        }
        else if (uVar1 == 0x3374) {
          ppppppppuVar27 = (ushort ********)(pSVar20->s3->tmp).finish_md_len;
          if (ppppppppuVar27 == (ushort ********)0x0) {
            pcVar36 = *(code **)(pSVar20->psk_server_callback + 0x1ac);
            if (pcVar36 == (code *)0x0) {
              *local_60 = 0x6e;
            }
            else if (uVar35 == 0) {
LAB_00493220:
              iVar6 = (*pcVar36)(pSVar20,&uStack_a0,&uStack_a1,pppppppuVar34,uVar35,
                                 *(undefined4 *)(pSVar20->psk_server_callback + 0x1b0));
              if (iVar6 == 0) {
                pSVar12 = (SSL_CTX *)
                          (*(code *)PTR_CRYPTO_malloc_006a7008)(uStack_a1,"t1_lib.c",0x653);
                pSVar20->initial_ctx = pSVar12;
                if (pSVar12 != (SSL_CTX *)0x0) {
                  (*(code *)PTR_memcpy_006a9aec)(pSVar12,uStack_a0,uStack_a1);
                  *(undefined *)&pSVar20->next_proto_negotiated = uStack_a1;
                  pSVar20->s3->next_proto_neg_seen = 1;
                  goto LAB_00492fc4;
                }
              }
              *local_60 = 0x50;
            }
            else {
              uVar11 = (uint)*(byte *)pppppppuVar34;
              uVar22 = 0;
              if (uVar11 != 0) {
                while( true ) {
                  uVar22 = uVar22 + uVar11 + 1;
                  if (uVar35 <= uVar22) break;
                  uVar11 = (uint)*(byte *)((int)pppppppuVar34 + uVar22);
                  if (uVar11 == 0) goto LAB_004931e4;
                }
                if (uVar35 == uVar22) goto LAB_00493220;
              }
LAB_004931e4:
              *local_60 = 0x32;
            }
            goto LAB_00492ea8;
          }
        }
        else if (uVar1 == 0xff01) {
          iVar6 = (*(code *)PTR_ssl_parse_serverhello_renegotiate_ext_006a81cc)
                            (pSVar20,pppppppuVar34,uVar35,local_60);
          if (iVar6 == 0) {
LAB_004932d0:
            ppppppppuVar27 = (ushort ********)0x0;
            goto LAB_00492ea8;
          }
          bVar2 = true;
        }
        else if (uVar1 == 0xf) {
          if (*(byte *)(pppppppuVar32 + 1) == 1) {
            pSVar20->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)pSVar20->srtp_profile | 1);
          }
          else {
            if (*(byte *)(pppppppuVar32 + 1) != 2) {
              ppppppppuVar27 = (ushort ********)0x0;
              *local_60 = 0x2f;
              goto LAB_00492ea8;
            }
            pSVar20->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)pSVar20->srtp_profile | 3);
          }
        }
        else if (((pSVar20->method->version == 0xfeff) && (uVar1 == 0xe)) &&
                (iVar6 = ssl_parse_serverhello_use_srtp_ext(pSVar20,pppppppuVar34,uVar35,local_60),
                iVar6 != 0)) goto LAB_004932d0;
LAB_00492fc4:
        pppppppuVar32 = (ushort *******)((int)pppppppuVar34 + uVar35);
        pppppppuVar34 = pppppppuVar32 + 1;
        if ((int)pppppppuVar37 - (int)pppppppuVar32 < 4) goto LAB_00493320;
        uVar1 = *(ushort *)pppppppuVar32;
        uVar35 = (uint)*(ushort *)((int)pppppppuVar32 + 2);
      } while ((int)uVar35 <= (int)pppppppuVar37 - (int)pppppppuVar34);
    }
    ppppppppuVar27 = (ushort ********)0x1;
    if (bVar2) goto LAB_00492ea8;
  }
LAB_00492e5c:
  puVar4 = PTR_ERR_put_error_006a7f34;
  if ((pSVar20->references & 0x40004U) == 0) {
    *local_60 = 0x28;
    (*(code *)puVar4)(0x14,0x12f,0x152,"t1_lib.c",0x6a0);
    ppppppppuVar27 = (ushort ********)0x0;
  }
  else {
    ppppppppuVar27 = (ushort ********)0x1;
  }
LAB_00492ea8:
  if (pSStack_9c == *(SSL **)puVar5) {
    return ppppppppuVar27;
  }
  pSVar20 = pSStack_9c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  psVar13 = SSL_get_ciphers(pSVar20);
  iVar6 = 0;
  do {
    iVar14 = (*(code *)PTR_sk_num_006a6e2c)(psVar13);
    if (iVar14 <= iVar6) {
      return (ushort ********)0x1;
    }
    iVar14 = (*(code *)PTR_sk_value_006a6e24)(psVar13,iVar6);
  } while (((*(uint *)(iVar14 + 0xc) & 0xe0) == 0) &&
          (iVar6 = iVar6 + 1, (*(uint *)(iVar14 + 0x10) & 0x40) == 0));
  ppppppppuVar24 = (ushort ********)0x1;
  if (0x300 < pSVar20->version) {
    if (pSVar20->tlsext_ecpointformatlist_length != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    puVar5 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(3,"t1_lib.c",0x6c3);
    pSVar20->tlsext_ecpointformatlist_length = (size_t)puVar5;
    if (puVar5 == (undefined *)0x0) {
      uVar15 = 0x6c5;
      pcVar36 = (code *)PTR_ERR_put_error_006a7f34;
    }
    else {
      pSVar20->tlsext_ticket_expected = 3;
      *puVar5 = 0;
      *(undefined *)(pSVar20->tlsext_ecpointformatlist_length + 1) = 1;
      *(undefined *)(pSVar20->tlsext_ecpointformatlist_length + 2) = 2;
      if (pSVar20->tlsext_ellipticcurvelist_length != 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      puVar5 = PTR_CRYPTO_malloc_006a7008;
      pSVar20->tlsext_ecpointformatlist = &DAT_00000032;
      puVar5 = (undefined *)(*(code *)puVar5)(0x32,"t1_lib.c",0x6d5);
      pSVar20->tlsext_ellipticcurvelist_length = (size_t)puVar5;
      pcVar36 = (code *)PTR_ERR_put_error_006a7f34;
      if (puVar5 != (undefined *)0x0) {
        puVar23 = pref_list;
        do {
          iVar6 = *(int *)puVar23;
          uVar26 = 2;
          if (iVar6 != 0x2d2) {
            if (iVar6 < 0x2d3) {
              uVar26 = 0x12;
              if (iVar6 != 0x2c7) {
                if (iVar6 < 0x2c8) {
                  uVar26 = 0xf;
                  if (iVar6 != 0x2c4) {
                    if (iVar6 < 0x2c5) {
                      if (iVar6 == 0x199) {
                        uVar26 = 0x13;
                      }
                      else {
                        uVar26 = 0x17;
                        if (iVar6 != 0x19f) {
                          uVar26 = 0;
                        }
                      }
                    }
                    else if (iVar6 == 0x2c5) {
                      uVar26 = 0x10;
                    }
                    else {
                      uVar26 = 0x11;
                      if (iVar6 != 0x2c6) {
                        uVar26 = 0;
                      }
                    }
                  }
                }
                else {
                  uVar26 = 0x16;
                  if (iVar6 != 0x2ca) {
                    if (iVar6 < 0x2cb) {
                      if (iVar6 == 0x2c8) {
                        uVar26 = 0x14;
                      }
                      else {
                        uVar26 = 0x15;
                        if (iVar6 != 0x2c9) {
                          uVar26 = 0;
                        }
                      }
                    }
                    else {
                      uVar26 = 0x19;
                      if (iVar6 != 0x2cc) {
                        if (iVar6 < 0x2cc) {
                          uVar26 = 0x18;
                        }
                        else {
                          uVar26 = 1;
                          if (iVar6 != 0x2d1) goto LAB_0049369c;
                        }
                      }
                    }
                  }
                }
              }
            }
            else {
              uVar26 = 8;
              if (iVar6 != 0x2d8) {
                if (iVar6 < 0x2d9) {
                  uVar26 = 5;
                  if (iVar6 != 0x2d5) {
                    if (iVar6 < 0x2d6) {
                      if (iVar6 == 0x2d3) {
                        uVar26 = 3;
                      }
                      else {
                        uVar26 = 4;
                        if (iVar6 != 0x2d4) {
                          uVar26 = 0;
                        }
                      }
                    }
                    else if (iVar6 == 0x2d6) {
                      uVar26 = 6;
                    }
                    else {
                      uVar26 = 7;
                      if (iVar6 != 0x2d7) {
                        uVar26 = 0;
                      }
                    }
                  }
                }
                else {
                  uVar26 = 0xb;
                  if (iVar6 != 0x2db) {
                    if (iVar6 < 0x2dc) {
                      if (iVar6 == 0x2d9) {
                        uVar26 = 9;
                      }
                      else {
                        uVar26 = 10;
                        if (iVar6 != 0x2da) {
                          uVar26 = 0;
                        }
                      }
                    }
                    else {
                      uVar26 = 0xd;
                      if (iVar6 != 0x2dd) {
                        if (iVar6 < 0x2dd) {
                          uVar26 = 0xc;
                        }
                        else {
                          uVar26 = 0xe;
                          if (iVar6 != 0x2de) {
LAB_0049369c:
                            uVar26 = 0;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          puVar23 = (undefined1 *)((int)puVar23 + 4);
          *puVar5 = 0;
          puVar5[1] = uVar26;
          puVar5 = puVar5 + 2;
          if (puVar23 == nid_list) {
            return (ushort ********)0x1;
          }
        } while( true );
      }
      pSVar20->tlsext_ecpointformatlist = (uchar *)0x0;
      uVar15 = 0x6d8;
    }
    (*pcVar36)(0x14,0x119,0x41,"t1_lib.c",uVar15);
    ppppppppuVar24 = (ushort ********)0xffffffff;
  }
  return ppppppppuVar24;
}

