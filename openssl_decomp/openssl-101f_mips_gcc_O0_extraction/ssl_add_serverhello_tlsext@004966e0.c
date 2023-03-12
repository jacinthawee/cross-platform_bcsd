
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
  uint uVar10;
  SSL_CTX *pSVar11;
  stack_st_SSL_CIPHER *psVar12;
  int iVar13;
  undefined4 uVar14;
  ushort **ppuVar15;
  ushort **ppuVar16;
  SSL *pSVar17;
  SRTP_PROTECTION_PROFILE *pSVar18;
  uint uVar19;
  SSL_SESSION *pSVar20;
  undefined1 *puVar21;
  ushort ********ppppppppuVar22;
  ushort *puVar23;
  ushort *******pppppppuVar24;
  undefined uVar25;
  ushort ********ppppppppuVar26;
  ushort *puVar27;
  ushort *puVar28;
  ushort *******pppppppuVar29;
  ushort ********ppppppppuVar30;
  ushort ********ppppppppuVar31;
  ushort ********ppppppppuVar32;
  ushort *******pppppppuVar33;
  ushort *******pppppppuVar34;
  ushort ********unaff_s5;
  uint uVar35;
  SSL_SESSION *pSVar36;
  ushort ********unaff_s6;
  code *pcVar37;
  undefined uStack_a1;
  undefined4 uStack_a0;
  SSL *pSStack_9c;
  ushort ********ppppppppuStack_98;
  SSL *pSStack_94;
  ushort ********ppppppppuStack_90;
  ushort ********ppppppppuStack_8c;
  undefined *puStack_88;
  ushort ********ppppppppuStack_84;
  ushort ********ppppppppuStack_80;
  undefined4 *local_60;
  ushort ********local_50;
  ushort ********local_4c;
  ushort *local_48 [8];
  ushort *puStack_28;
  SSL *local_24;
  
  puStack_88 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(SSL **)PTR___stack_chk_guard_006aabf0;
  ppppppppuStack_98 = (ushort ********)((int)param_2 + 2);
  ppppppppuVar22 = param_2;
  ppppppppuVar26 = param_3;
  if (((param_1->version == 0x300) &&
      (ppppppppuVar30 = param_2, param_1->s3->send_connection_binding == 0)) ||
     (ppppppppuVar30 = (ushort ********)0x0, param_3 <= ppppppppuStack_98)) goto LAB_004969b4;
  ppppppppuVar32 = ppppppppuStack_98;
  if (((param_1->hit == 0) && (param_1->tlsext_hostname == (char *)0x1)) &&
     (*(int *)(param_1->session->krb5_client_princ + 0x40) != 0)) {
    ppppppppuVar32 = (ushort ********)((int)param_2 + 6);
    if (3 < (int)param_3 - (int)ppppppppuStack_98) {
      *(undefined *)((int)param_2 + 2) = 0;
      *(undefined *)((int)param_2 + 3) = 0;
      *(undefined *)(param_2 + 1) = 0;
      *(undefined *)((int)param_2 + 5) = 0;
      goto LAB_00496750;
    }
  }
  else {
LAB_00496750:
    ppppppppuStack_98 = ppppppppuVar32;
    if (param_1->s3->send_connection_binding == 0) {
LAB_00496760:
      if ((param_1->tlsext_ecpointformatlist_length != 0) && (param_1->version != 0xfeff)) {
        puVar5 = (undefined *)((int)param_3 + (-5 - (int)ppppppppuStack_98));
        ppppppppuVar32 = ppppppppuStack_98;
        if (((int)puVar5 < 0) || (puVar5 < (undefined *)param_1->tlsext_ticket_expected))
        goto LAB_00496a68;
        if ((undefined *)0xff < (undefined *)param_1->tlsext_ticket_expected) {
          local_60 = (undefined4 *)0x2da;
          goto LAB_00496a54;
        }
        *(undefined *)ppppppppuStack_98 = 0;
        puVar5 = PTR_memcpy_006aabf4;
        *(undefined *)((int)ppppppppuStack_98 + 1) = 0xb;
        *(char *)((int)ppppppppuStack_98 + 2) =
             (char)((uint)(param_1->tlsext_ticket_expected + 1) >> 8);
        *(char *)((int)ppppppppuStack_98 + 3) = (char)param_1->tlsext_ticket_expected + '\x01';
        *(char *)(ppppppppuStack_98 + 1) = (char)param_1->tlsext_ticket_expected;
        ppppppppuVar26 = (ushort ********)param_1->tlsext_ticket_expected;
        ppppppppuVar22 = (ushort ********)param_1->tlsext_ecpointformatlist_length;
        iVar6 = (*(code *)puVar5)((int)ppppppppuStack_98 + 5);
        ppppppppuStack_98 = (ushort ********)(iVar6 + param_1->tlsext_ticket_expected);
      }
      ppppppppuVar31 = ppppppppuStack_98;
      if (param_1->tlsext_ocsp_resplen != 0) {
        param_4 = (char *)0x0;
        ppppppppuVar26 = (ushort ********)0x0;
        ppppppppuVar22 = (ushort ********)&DAT_00000020;
        uVar35 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
        if ((uVar35 & 0x4000) == 0) {
          ppppppppuVar30 = (ushort ********)0x0;
          if ((int)param_3 - (int)ppppppppuStack_98 < 4) goto LAB_004969b4;
          *(undefined *)ppppppppuStack_98 = 0;
          *(undefined *)((int)ppppppppuStack_98 + 2) = 0;
          ppppppppuVar31 = ppppppppuStack_98 + 1;
          *(undefined *)((int)ppppppppuStack_98 + 3) = 0;
          *(undefined *)((int)ppppppppuStack_98 + 1) = 0x23;
        }
      }
      ppppppppuVar32 = ppppppppuVar31;
      if (param_1->tlsext_status_type != 0) {
        ppppppppuVar30 = (ushort ********)0x0;
        ppppppppuStack_98 = ppppppppuVar31;
        if ((int)param_3 - (int)ppppppppuVar31 < 4) goto LAB_004969b4;
        *(undefined *)ppppppppuVar31 = 0;
        *(undefined *)((int)ppppppppuVar31 + 2) = 0;
        ppppppppuVar32 = ppppppppuVar31 + 1;
        *(undefined *)((int)ppppppppuVar31 + 3) = 0;
        *(undefined *)((int)ppppppppuVar31 + 1) = 5;
      }
      if (param_1->srtp_profiles != (stack_st_SRTP_PROTECTION_PROFILE *)0x0) {
        unaff_s5 = (ushort ********)&local_4c;
        ppppppppuVar22 = (ushort ********)0x0;
        ppppppppuVar26 = unaff_s5;
        ssl_add_serverhello_use_srtp_ext(param_1,0,unaff_s5,0);
        param_4 = (char *)local_4c;
        if ((int)((int)param_3 + ((-4 - (int)param_2) - (int)local_4c)) < 0) goto LAB_00496a68;
        *(undefined *)ppppppppuVar32 = 0;
        unaff_s6 = ppppppppuVar32 + 1;
        *(char *)((int)ppppppppuVar32 + 3) = (char)local_4c;
        *(char *)((int)ppppppppuVar32 + 2) = (char)((uint)local_4c >> 8);
        *(undefined *)((int)ppppppppuVar32 + 1) = 0xe;
        ppppppppuVar22 = unaff_s6;
        ppppppppuVar26 = unaff_s5;
        iVar6 = ssl_add_serverhello_use_srtp_ext(param_1);
        if (iVar6 != 0) {
          local_60 = (undefined4 *)0x318;
          goto LAB_00496a54;
        }
        ppppppppuVar32 = (ushort ********)((int)unaff_s6 + (int)local_4c);
      }
      if (*(ushort *)((int)&((param_1->s3->tmp).new_cipher)->id + 2) - 0x80 < 2) {
        param_4 = (char *)0x0;
        ppppppppuVar26 = (ushort ********)0x0;
        ppppppppuVar22 = (ushort ********)&DAT_00000020;
        lVar8 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
        if (lVar8 < 0) {
          ppuVar9 = (ushort **)&DAT_00647a50;
          ppuVar15 = local_48;
          do {
            puVar28 = *ppuVar9;
            ppuVar16 = ppuVar15 + 4;
            param_4 = (char *)ppuVar9[1];
            puVar27 = ppuVar9[2];
            puVar23 = ppuVar9[3];
            ppuVar9 = ppuVar9 + 4;
            *ppuVar15 = puVar28;
            ppuVar15[1] = (ushort *)param_4;
            ppuVar15[2] = puVar27;
            ppuVar15[3] = puVar23;
            ppuVar15 = ppuVar16;
          } while (ppuVar9 != (ushort **)&UNK_00647a70);
          ppppppppuVar22 = (ushort ********)(uint)((int)param_3 - (int)ppppppppuVar32 < 0x24);
          *ppuVar16 = (ushort *)_UNK_00647a70;
          ppppppppuVar26 = _UNK_00647a70;
          if (ppppppppuVar22 != (ushort ********)0x0) goto LAB_00496a68;
          ppppppppuVar30 = ppppppppuVar32;
          ppuVar15 = local_48;
          do {
            param_4 = (char *)*ppuVar15;
            ppuVar9 = ppuVar15 + 4;
            ppppppppuVar26 = (ushort ********)ppuVar15[1];
            ppppppppuVar22 = (ushort ********)ppuVar15[2];
            pppppppuVar24 = (ushort *******)ppuVar15[3];
            *ppppppppuVar30 = (ushort *******)param_4;
            ppppppppuVar30[1] = (ushort *******)ppppppppuVar26;
            ppppppppuVar30[2] = (ushort *******)ppppppppuVar22;
            ppppppppuVar30[3] = pppppppuVar24;
            ppppppppuVar30 = ppppppppuVar30 + 4;
            ppuVar15 = ppuVar9;
          } while (ppuVar9 != &puStack_28);
          ppppppppuVar32 = ppppppppuVar32 + 9;
          *ppppppppuVar30 = (ushort *******)*ppuVar9;
        }
      }
      ppppppppuStack_98 = ppppppppuVar32;
      if (((uint)param_1->srtp_profile & 1) == 0) {
LAB_004968fc:
        iVar6 = param_1->s3->next_proto_neg_seen;
        param_1->s3->next_proto_neg_seen = 0;
        if (iVar6 != 0) {
          p_Var7 = param_1->psk_server_callback;
LAB_00496910:
          ppppppppuVar26 = (ushort ********)&local_4c;
          if (*(code **)(p_Var7 + 0x1a4) != (code *)0x0) {
            param_4 = *(char **)(p_Var7 + 0x1a8);
            ppppppppuVar22 = (ushort ********)&local_50;
            iVar6 = (**(code **)(p_Var7 + 0x1a4))(param_1);
            puVar5 = PTR_memcpy_006aabf4;
            if (iVar6 == 0) {
              param_3 = (ushort ********)
                        ((int)param_3 + ((-4 - (int)local_4c) - (int)ppppppppuStack_98));
              ppppppppuVar32 = ppppppppuStack_98;
              unaff_s5 = local_4c;
              if ((int)param_3 < 0) goto LAB_00496a68;
              *(char *)((int)ppppppppuStack_98 + 3) = (char)local_4c;
              *(undefined *)ppppppppuStack_98 = 0x33;
              *(char *)((int)ppppppppuStack_98 + 2) = (char)((uint)local_4c >> 8);
              *(undefined *)((int)ppppppppuStack_98 + 1) = 0x74;
              ppppppppuVar26 = local_4c;
              iVar6 = (*(code *)puVar5)(ppppppppuStack_98 + 1);
              ppppppppuStack_98 = (ushort ********)(iVar6 + (int)local_4c);
              param_1->s3->next_proto_neg_seen = 1;
              ppppppppuVar22 = local_50;
            }
          }
        }
      }
      else {
        *(undefined *)ppppppppuVar32 = 0;
        *(undefined *)((int)ppppppppuVar32 + 2) = 0;
        *(undefined *)((int)ppppppppuVar32 + 1) = 0xf;
        *(undefined *)((int)ppppppppuVar32 + 3) = 1;
        if (((uint)param_1->srtp_profile & 4) != 0) {
          ppppppppuStack_98 = (ushort ********)((int)ppppppppuVar32 + 5);
          *(undefined *)(ppppppppuVar32 + 1) = 2;
          goto LAB_004968fc;
        }
        *(undefined *)(ppppppppuVar32 + 1) = 1;
        ppppppppuStack_98 = (ushort ********)((int)ppppppppuVar32 + 5);
        iVar6 = param_1->s3->next_proto_neg_seen;
        param_1->s3->next_proto_neg_seen = 0;
        if (iVar6 != 0) {
          p_Var7 = param_1->psk_server_callback;
          goto LAB_00496910;
        }
      }
      iVar6 = (int)ppppppppuStack_98 + (-2 - (int)param_2);
      ppppppppuVar30 = param_2;
      if (iVar6 != 0) {
        *(char *)((int)param_2 + 1) = (char)iVar6;
        *(char *)param_2 = (char)((uint)iVar6 >> 8);
        ppppppppuVar30 = ppppppppuStack_98;
      }
      goto LAB_004969b4;
    }
    unaff_s5 = (ushort ********)&local_4c;
    ppppppppuVar22 = (ushort ********)0x0;
    ppppppppuVar26 = unaff_s5;
    iVar6 = (*(code *)PTR_ssl_add_serverhello_renegotiate_ext_006a92ec)(param_1,0,unaff_s5,0);
    puVar5 = PTR_ssl_add_serverhello_renegotiate_ext_006a92ec;
    if (iVar6 == 0) {
      local_60 = (undefined4 *)0x2bd;
    }
    else {
      param_4 = (char *)local_4c;
      if ((int)((int)param_3 + ((-4 - (int)param_2) - (int)local_4c)) < 0) goto LAB_00496a68;
      *(char *)((int)ppppppppuVar32 + 3) = (char)local_4c;
      unaff_s6 = ppppppppuVar32 + 1;
      *(undefined *)ppppppppuVar32 = 0xff;
      *(char *)((int)ppppppppuVar32 + 2) = (char)((uint)local_4c >> 8);
      *(undefined *)((int)ppppppppuVar32 + 1) = 1;
      ppppppppuVar22 = unaff_s6;
      ppppppppuVar26 = unaff_s5;
      iVar6 = (*(code *)puVar5)(param_1);
      if (iVar6 != 0) {
        ppppppppuStack_98 = (ushort ********)((int)unaff_s6 + (int)local_4c);
        goto LAB_00496760;
      }
      local_60 = (undefined4 *)0x2c8;
    }
LAB_00496a54:
    param_4 = "t1_lib.c";
    ppppppppuVar26 = (ushort ********)0x44;
    ppppppppuVar22 = (ushort ********)&DAT_00000116;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14);
  }
LAB_00496a68:
  ppppppppuVar30 = (ushort ********)0x0;
  ppppppppuStack_98 = ppppppppuVar32;
LAB_004969b4:
  if (local_24 == *(SSL **)puStack_88) {
    return ppppppppuVar30;
  }
  pSVar17 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar5 = PTR___stack_chk_guard_006aabf0;
  pSVar18 = pSVar17->srtp_profile;
  pppppppuVar24 = *ppppppppuVar22;
  pSStack_9c = *(SSL **)PTR___stack_chk_guard_006aabf0;
  pSVar17->s3->next_proto_neg_seen = 0;
  pSVar17->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)pSVar18 & 0xfffffffc);
  pSStack_94 = param_1;
  ppppppppuStack_90 = param_2;
  ppppppppuStack_8c = param_3;
  ppppppppuStack_84 = unaff_s5;
  ppppppppuStack_80 = unaff_s6;
  if (pppppppuVar24 < (ushort *******)((int)ppppppppuVar26 + (int)((int)param_4 + -2))) {
    pppppppuVar34 =
         (ushort *******)
         ((int)(ushort *******)((int)pppppppuVar24 + 2) + (uint)*(ushort *)pppppppuVar24);
    if (pppppppuVar34 == (ushort *******)((int)ppppppppuVar26 + (int)param_4)) {
      bVar3 = false;
      bVar2 = false;
      pppppppuVar24 = (ushort *******)((int)pppppppuVar24 + 2);
LAB_00496df8:
      pppppppuVar33 = pppppppuVar24;
      pppppppuVar29 = pppppppuVar33 + 1;
      if ((ushort *******)((int)ppppppppuVar26 + (int)((int)param_4 + -4)) < pppppppuVar33) {
        if (pppppppuVar33 != pppppppuVar34) goto LAB_00496d50;
        if (((pSVar17->hit == 0) && (bVar2)) && (pSVar17->tlsext_debug_arg != (void *)0x0)) {
          pSVar36 = pSVar17->session;
          if (*(int *)(pSVar36->krb5_client_princ + 0x40) != 0) goto LAB_00496d50;
          uVar14 = (*(code *)PTR_BUF_strdup_006a80dc)();
          pSVar20 = pSVar17->session;
          *(undefined4 *)(pSVar36->krb5_client_princ + 0x40) = uVar14;
          if (*(int *)(pSVar20->krb5_client_princ + 0x40) == 0) goto LAB_004971f0;
        }
        *ppppppppuVar22 = pppppppuVar33;
LAB_00497198:
        ppppppppuVar30 = (ushort ********)0x1;
        if (bVar3) goto LAB_00496d5c;
        goto LAB_00496d0c;
      }
      uVar1 = *(ushort *)pppppppuVar33;
      uVar35 = (uint)*(ushort *)((int)pppppppuVar33 + 2);
      pppppppuVar24 = (ushort *******)((int)pppppppuVar29 + uVar35);
      if (pppppppuVar34 < pppppppuVar24) goto LAB_00497198;
      if ((code *)pSVar17->max_send_fragment != (code *)0x0) {
        (*(code *)pSVar17->max_send_fragment)
                  (pSVar17,1,uVar1,pppppppuVar29,uVar35,pSVar17->tlsext_debug_cb);
      }
      if (uVar1 == 0) {
        if ((pSVar17->tlsext_debug_arg == (void *)0x0) || (uVar35 != 0)) {
LAB_004971f0:
          ppppppppuVar30 = (ushort ********)0x0;
          *local_60 = 0x70;
          goto LAB_00496d5c;
        }
        bVar2 = true;
        goto LAB_00496df8;
      }
      if (uVar1 == 0xb) {
        if (pSVar17->version != 0xfeff) {
          uVar10 = (uint)*(byte *)(pppppppuVar33 + 1);
          if ((uVar10 != uVar35 - 1) || (uVar10 == 0)) goto LAB_00496d50;
          pSVar36 = pSVar17->session;
          *(undefined4 *)(pSVar36->krb5_client_princ + 0x44) = 0;
          if (*(int *)(pSVar36->krb5_client_princ + 0x48) != 0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)();
            pSVar36 = pSVar17->session;
          }
          iVar6 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar10,"t1_lib.c",0x5fb);
          *(int *)(pSVar36->krb5_client_princ + 0x48) = iVar6;
          puVar4 = PTR_memcpy_006aabf4;
          if (iVar6 == 0) {
LAB_00497224:
            ppppppppuVar30 = (ushort ********)0x0;
            *local_60 = 0x50;
            goto LAB_00496d5c;
          }
          pSVar36 = pSVar17->session;
          *(uint *)(pSVar36->krb5_client_princ + 0x44) = uVar10;
          (*(code *)puVar4)(*(undefined4 *)(pSVar36->krb5_client_princ + 0x48),
                            (undefined *)((int)pppppppuVar33 + 5),uVar10);
        }
        goto LAB_00496df8;
      }
      if (uVar1 == 0x23) {
        if ((pSVar17->tlsext_session_ticket != (TLS_SESSION_TICKET_EXT *)0x0) &&
           (iVar6 = (*(code *)pSVar17->tlsext_session_ticket)
                              (pSVar17,pppppppuVar29,uVar35,pSVar17->tls_session_ticket_ext_cb),
           iVar6 == 0)) goto LAB_00497224;
        uVar10 = SSL_ctrl(pSVar17,0x20,0,(void *)0x0);
        if (((uVar10 & 0x4000) != 0) || (uVar35 != 0)) {
LAB_00497214:
          ppppppppuVar30 = (ushort ********)0x0;
          *local_60 = 0x6e;
          goto LAB_00496d5c;
        }
        pSVar17->tlsext_ocsp_resplen = 1;
        goto LAB_00496df8;
      }
      if (uVar1 == 5) {
        if (pSVar17->version != 0xfeff) {
          if ((pSVar17->servername_done == -1) || (uVar35 != 0)) goto LAB_00497214;
          pSVar17->tlsext_status_type = 1;
        }
        goto LAB_00496df8;
      }
      if (uVar1 == 0x3374) {
        ppppppppuVar30 = (ushort ********)(pSVar17->s3->tmp).finish_md_len;
        if (ppppppppuVar30 == (ushort ********)0x0) {
          pcVar37 = *(code **)(pSVar17->psk_server_callback + 0x1ac);
          if (pcVar37 == (code *)0x0) {
            *local_60 = 0x6e;
            goto LAB_00496d5c;
          }
          if (uVar35 != 0) {
            uVar10 = (uint)*(byte *)(pppppppuVar33 + 1);
            uVar19 = 0;
            if (uVar10 != 0) {
              while( true ) {
                uVar19 = uVar19 + uVar10 + 1;
                if (uVar35 <= uVar19) break;
                uVar10 = (uint)*(byte *)((int)pppppppuVar29 + uVar19);
                if (uVar10 == 0) goto LAB_00497258;
              }
              if (uVar35 == uVar19) goto LAB_00497078;
            }
LAB_00497258:
            *local_60 = 0x32;
            goto LAB_00496d5c;
          }
LAB_00497078:
          iVar6 = (*pcVar37)(pSVar17,&uStack_a0,&uStack_a1,pppppppuVar29,uVar35,
                             *(undefined4 *)(pSVar17->psk_server_callback + 0x1b0));
          if (iVar6 == 0) {
            pSVar11 = (SSL_CTX *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uStack_a1,"t1_lib.c",0x662);
            pSVar17->initial_ctx = pSVar11;
            if (pSVar11 != (SSL_CTX *)0x0) {
              (*(code *)PTR_memcpy_006aabf4)(pSVar11,uStack_a0,uStack_a1);
              *(undefined *)&pSVar17->next_proto_negotiated = uStack_a1;
              pSVar17->s3->next_proto_neg_seen = 1;
              goto LAB_00496df8;
            }
          }
          *local_60 = 0x50;
          goto LAB_00496d5c;
        }
        goto LAB_00496df8;
      }
      if (uVar1 == 0xff01) {
        iVar6 = (*(code *)PTR_ssl_parse_serverhello_renegotiate_ext_006a92f8)
                          (pSVar17,pppppppuVar29,uVar35,local_60);
        if (iVar6 == 0) goto LAB_00497140;
        bVar3 = true;
        goto LAB_00496df8;
      }
      if (uVar1 == 0xf) {
        if (*(char *)(pppppppuVar33 + 1) == '\x01') {
          pSVar17->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)pSVar17->srtp_profile | 1);
        }
        else {
          if (*(char *)(pppppppuVar33 + 1) != '\x02') {
            ppppppppuVar30 = (ushort ********)0x0;
            *local_60 = 0x2f;
            goto LAB_00496d5c;
          }
          pSVar17->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)pSVar17->srtp_profile | 3);
        }
        goto LAB_00496df8;
      }
      if ((uVar1 != 0xe) ||
         (iVar6 = ssl_parse_serverhello_use_srtp_ext(pSVar17,pppppppuVar29,uVar35,local_60),
         iVar6 == 0)) goto LAB_00496df8;
LAB_00497140:
      ppppppppuVar30 = (ushort ********)0x0;
    }
    else {
LAB_00496d50:
      ppppppppuVar30 = (ushort ********)0x0;
      *local_60 = 0x32;
    }
  }
  else {
LAB_00496d0c:
    puVar4 = PTR_ERR_put_error_006a9030;
    if ((pSVar17->references & 0x40004U) == 0) {
      *local_60 = 0x28;
      (*(code *)puVar4)(0x14,0x12f,0x152,"t1_lib.c",0x6bc);
      ppppppppuVar30 = (ushort ********)0x0;
    }
    else {
      ppppppppuVar30 = (ushort ********)0x1;
    }
  }
LAB_00496d5c:
  if (pSStack_9c == *(SSL **)puVar5) {
    return ppppppppuVar30;
  }
  pSVar17 = pSStack_9c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  psVar12 = SSL_get_ciphers(pSVar17);
  iVar6 = 0;
  do {
    iVar13 = (*(code *)PTR_sk_num_006a7f2c)(psVar12);
    if (iVar13 <= iVar6) {
      return (ushort ********)0x1;
    }
    iVar13 = (*(code *)PTR_sk_value_006a7f24)(psVar12,iVar6);
  } while (((*(uint *)(iVar13 + 0xc) & 0xe0) == 0) &&
          (iVar6 = iVar6 + 1, (*(uint *)(iVar13 + 0x10) & 0x40) == 0));
  ppppppppuVar22 = (ushort ********)0x1;
  if (0x300 < pSVar17->version) {
    if (pSVar17->tlsext_ecpointformatlist_length != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    puVar5 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(3,"t1_lib.c",0x6e0);
    pSVar17->tlsext_ecpointformatlist_length = (size_t)puVar5;
    if (puVar5 == (undefined *)0x0) {
      uVar14 = 0x6e2;
      pcVar37 = (code *)PTR_ERR_put_error_006a9030;
    }
    else {
      pSVar17->tlsext_ticket_expected = 3;
      *puVar5 = 0;
      *(undefined *)(pSVar17->tlsext_ecpointformatlist_length + 1) = 1;
      *(undefined *)(pSVar17->tlsext_ecpointformatlist_length + 2) = 2;
      if (pSVar17->tlsext_ellipticcurvelist_length != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      puVar5 = PTR_CRYPTO_malloc_006a8108;
      pSVar17->tlsext_ecpointformatlist = (uchar *)0x32;
      puVar5 = (undefined *)(*(code *)puVar5)(0x32,"t1_lib.c",0x6ed);
      pSVar17->tlsext_ellipticcurvelist_length = (size_t)puVar5;
      pcVar37 = (code *)PTR_ERR_put_error_006a9030;
      if (puVar5 != (undefined *)0x0) {
        puVar21 = pref_list;
        do {
          iVar6 = *(int *)puVar21;
          uVar25 = 2;
          if (iVar6 != 0x2d2) {
            if (iVar6 < 0x2d3) {
              uVar25 = 0x12;
              if (iVar6 != 0x2c7) {
                if (iVar6 < 0x2c8) {
                  uVar25 = 0xf;
                  if (iVar6 != 0x2c4) {
                    if (iVar6 < 0x2c5) {
                      if (iVar6 == 0x199) {
                        uVar25 = 0x13;
                      }
                      else {
                        uVar25 = 0x17;
                        if (iVar6 != 0x19f) {
                          uVar25 = 0;
                        }
                      }
                    }
                    else if (iVar6 == 0x2c5) {
                      uVar25 = 0x10;
                    }
                    else {
                      uVar25 = 0x11;
                      if (iVar6 != 0x2c6) {
                        uVar25 = 0;
                      }
                    }
                  }
                }
                else {
                  uVar25 = 0x16;
                  if (iVar6 != 0x2ca) {
                    if (iVar6 < 0x2cb) {
                      if (iVar6 == 0x2c8) {
                        uVar25 = 0x14;
                      }
                      else {
                        uVar25 = 0x15;
                        if (iVar6 != 0x2c9) {
                          uVar25 = 0;
                        }
                      }
                    }
                    else {
                      uVar25 = 0x19;
                      if (iVar6 != 0x2cc) {
                        if (iVar6 < 0x2cc) {
                          uVar25 = 0x18;
                        }
                        else {
                          uVar25 = 1;
                          if (iVar6 != 0x2d1) goto LAB_0049750c;
                        }
                      }
                    }
                  }
                }
              }
            }
            else {
              uVar25 = 8;
              if (iVar6 != 0x2d8) {
                if (iVar6 < 0x2d9) {
                  uVar25 = 5;
                  if (iVar6 != 0x2d5) {
                    if (iVar6 < 0x2d6) {
                      if (iVar6 == 0x2d3) {
                        uVar25 = 3;
                      }
                      else {
                        uVar25 = 4;
                        if (iVar6 != 0x2d4) {
                          uVar25 = 0;
                        }
                      }
                    }
                    else if (iVar6 == 0x2d6) {
                      uVar25 = 6;
                    }
                    else {
                      uVar25 = 7;
                      if (iVar6 != 0x2d7) {
                        uVar25 = 0;
                      }
                    }
                  }
                }
                else {
                  uVar25 = 0xb;
                  if (iVar6 != 0x2db) {
                    if (iVar6 < 0x2dc) {
                      if (iVar6 == 0x2d9) {
                        uVar25 = 9;
                      }
                      else {
                        uVar25 = 10;
                        if (iVar6 != 0x2da) {
                          uVar25 = 0;
                        }
                      }
                    }
                    else {
                      uVar25 = 0xd;
                      if (iVar6 != 0x2dd) {
                        if (iVar6 < 0x2dd) {
                          uVar25 = 0xc;
                        }
                        else {
                          uVar25 = 0xe;
                          if (iVar6 != 0x2de) {
LAB_0049750c:
                            uVar25 = 0;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          puVar21 = (undefined1 *)((int)puVar21 + 4);
          *puVar5 = 0;
          puVar5[1] = uVar25;
          puVar5 = puVar5 + 2;
          if (puVar21 == nid_list) {
            return (ushort ********)0x1;
          }
        } while( true );
      }
      pSVar17->tlsext_ecpointformatlist = (uchar *)0x0;
      uVar14 = 0x6f0;
    }
    (*pcVar37)(0x14,0x119,0x41,"t1_lib.c",uVar14);
    ppppppppuVar22 = (ushort ********)0xffffffff;
  }
  return ppppppppuVar22;
}

