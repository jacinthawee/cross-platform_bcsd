
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

SSL_SESSION *
ssl_add_clienthello_tlsext(SSL *param_1,SSL_SESSION *param_2,SSL_SESSION *param_3,char *param_4)

{
  short sVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined *puVar7;
  undefined4 *puVar8;
  SSL_SESSION *pSVar9;
  char *pcVar10;
  uchar *puVar11;
  uint uVar12;
  int iVar13;
  stack_st_SRTP_PROTECTION_PROFILE *psVar14;
  undefined2 uVar25;
  ushort *puVar15;
  _func_3154 *p_Var16;
  long lVar17;
  SSL_SESSION **ppSVar18;
  uint uVar19;
  SSL_CTX *pSVar20;
  stack_st_SSL_CIPHER *psVar21;
  int iVar22;
  undefined *puVar23;
  undefined4 uVar24;
  SSL_SESSION **ppSVar26;
  SSL_SESSION **ppSVar27;
  SSL *pSVar28;
  SRTP_PROTECTION_PROFILE *pSVar29;
  uint uVar30;
  undefined1 *puVar31;
  SSL_SESSION *pSVar32;
  BIO_METHOD *pBVar33;
  undefined uVar34;
  SSL_SESSION *pSVar35;
  char **ppcVar36;
  SSL_SESSION *pSVar37;
  BIO_METHOD *pBVar38;
  SSL_SESSION *pSVar39;
  BIO_METHOD *pBVar40;
  SSL_SESSION *unaff_s5;
  _func_603 **unaff_s6;
  uint unaff_s7;
  code *pcVar41;
  SSL_SESSION *unaff_s8;
  undefined uStack_f9;
  undefined4 uStack_f8;
  SSL *pSStack_f4;
  SSL_SESSION *pSStack_f0;
  SSL *pSStack_ec;
  char *pcStack_e8;
  SSL_SESSION *pSStack_e4;
  undefined *puStack_e0;
  SSL_SESSION *pSStack_dc;
  _func_603 **pp_Stack_d8;
  uint uStack_d4;
  SSL_SESSION *pSStack_d0;
  code *pcStack_cc;
  undefined4 *puStack_b8;
  undefined *puStack_b0;
  SSL_SESSION *pSStack_a8;
  SSL_SESSION *pSStack_a4;
  SSL_SESSION *apSStack_a0 [8];
  SSL_SESSION *pSStack_80;
  SSL *pSStack_7c;
  SSL *pSStack_78;
  SSL_SESSION *pSStack_74;
  SSL_SESSION *pSStack_70;
  undefined *puStack_6c;
  SSL_SESSION *pSStack_68;
  SSL_SESSION *pSStack_64;
  _func_603 **pp_Stack_60;
  code *pcStack_5c;
  undefined4 local_48;
  undefined *local_40;
  SSL_SESSION *local_34;
  SSL_SESSION *local_30;
  SSL *local_2c;
  
  puStack_6c = PTR___stack_chk_guard_006aabf0;
  local_40 = &_gp;
  local_2c = *(SSL **)PTR___stack_chk_guard_006aabf0;
  pSStack_74 = (SSL_SESSION *)((int)&param_2->ssl_version + 2);
  pSStack_e4 = param_3;
  pcStack_e8 = (char *)param_2;
  pSVar32 = param_2;
  if ((param_1->first_packet != 0x300) ||
     (local_34 = param_2, param_1->s3->send_connection_binding != 0)) {
    pSVar35 = pSStack_74;
    pSVar37 = pSStack_74;
    if (pSStack_74 < param_3) {
      if (param_1->tlsext_debug_arg == (void *)0x0) {
LAB_00495d2c:
        local_34 = pSStack_74;
        if (param_1->tlsext_hb_seq == 0) {
LAB_00495d38:
          pSVar35 = local_34;
          if (param_1[1].rbio != (BIO *)0x0) {
            unaff_s5 = (SSL_SESSION *)(**(code **)(local_40 + -0x53b0))();
            if ((0xff < (int)unaff_s5) || (unaff_s5 == (SSL_SESSION *)0x0)) {
              pcVar41 = *(code **)(local_40 + -0x6eb0);
              local_48 = 0x1b2;
              goto LAB_004961b8;
            }
            pcStack_e8 = &SUB_0000000c;
            pSVar37 = local_34;
            if ((int)((int)param_3 + ((-5 - (int)pSVar35) - (int)unaff_s5)) < 0) goto LAB_004961cc;
            *(char *)&pSVar35->ssl_version = '\0';
            pcVar41 = *(code **)(local_40 + -0x52ec);
            *(char *)((int)&local_34->ssl_version + 1) = '\f';
            param_4 = (char *)((int)&local_34->ssl_version + 2);
            *(char *)((int)&local_34->ssl_version + 2) =
                 (char)((uint)((int)&unaff_s5->ssl_version + 1) >> 8);
            *(char *)((int)&local_34->ssl_version + 3) = (char)unaff_s5 + '\x01';
            puVar23 = (undefined *)((int)&local_34->key_arg_length + 1);
            *(char *)&local_34->key_arg_length = (char)unaff_s5;
            pcStack_e8 = (char *)param_1[1].rbio;
            pSStack_e4 = unaff_s5;
            local_34 = (SSL_SESSION *)puVar23;
            (*pcVar41)(puVar23);
            local_34 = (SSL_SESSION *)((int)local_34 + (int)unaff_s5);
          }
          if (param_1->tlsext_ecpointformatlist_length == 0) {
LAB_00495e8c:
            pSStack_74 = local_34;
            if ((param_1->tlsext_ellipticcurvelist_length != 0) && (param_1->version != 0xfeff)) {
              puVar11 = (uchar *)((int)param_3 + (-6 - (int)local_34));
              pSVar35 = local_34;
              pSVar37 = local_34;
              if (((int)puVar11 < 0) || (puVar11 < param_1->tlsext_ecpointformatlist))
              goto LAB_004961cc;
              if ((uchar *)0xfffc < param_1->tlsext_ecpointformatlist) {
                pcVar41 = *(code **)(local_40 + -0x6eb0);
                local_48 = 0x1e5;
                goto LAB_004961b8;
              }
              *(char *)&local_34->ssl_version = '\0';
              pcVar41 = *(code **)(local_40 + -0x52ec);
              *(char *)((int)&local_34->ssl_version + 1) = '\n';
              *(char *)((int)&local_34->ssl_version + 2) =
                   (char)((uint)(param_1->tlsext_ecpointformatlist + 2) >> 8);
              *(char *)((int)&local_34->ssl_version + 3) =
                   (char)param_1->tlsext_ecpointformatlist + '\x02';
              *(char *)&local_34->key_arg_length =
                   (char)((uint)param_1->tlsext_ecpointformatlist >> 8);
              *(char *)((int)&local_34->key_arg_length + 1) =
                   (char)param_1->tlsext_ecpointformatlist;
              local_34 = (SSL_SESSION *)((int)&local_34->key_arg_length + 2);
              (*pcVar41)(local_34,param_1->tlsext_ellipticcurvelist_length,
                         param_1->tlsext_ecpointformatlist);
              local_34 = (SSL_SESSION *)((int)local_34 + (int)param_1->tlsext_ecpointformatlist);
            }
          }
          else {
            pSStack_74 = local_34;
            if (param_1->version != 0xfeff) {
              pcVar10 = (char *)((int)param_3 + (-5 - (int)local_34));
              pSVar35 = local_34;
              pSVar37 = local_34;
              if (((int)pcVar10 < 0) || (pcVar10 < (char *)param_1->tlsext_ticket_expected))
              goto LAB_004961cc;
              if ((char *)0xff < (char *)param_1->tlsext_ticket_expected) {
                pcVar41 = *(code **)(local_40 + -0x6eb0);
                local_48 = 0x1d1;
                goto LAB_004961b8;
              }
              *(char *)&local_34->ssl_version = '\0';
              pcVar41 = *(code **)(local_40 + -0x52ec);
              *(char *)((int)&local_34->ssl_version + 1) = '\v';
              *(char *)((int)&local_34->ssl_version + 2) =
                   (char)((uint)(param_1->tlsext_ticket_expected + 1) >> 8);
              *(char *)((int)&local_34->ssl_version + 3) =
                   (char)param_1->tlsext_ticket_expected + '\x01';
              puVar23 = (undefined *)((int)&local_34->key_arg_length + 1);
              *(char *)&local_34->key_arg_length = (char)param_1->tlsext_ticket_expected;
              pSStack_e4 = (SSL_SESSION *)param_1->tlsext_ticket_expected;
              pcStack_e8 = (char *)param_1->tlsext_ecpointformatlist_length;
              local_34 = (SSL_SESSION *)puVar23;
              (*pcVar41)(puVar23);
              local_34 = (SSL_SESSION *)((int)local_34 + param_1->tlsext_ticket_expected);
              goto LAB_00495e8c;
            }
          }
          param_4 = (char *)0x0;
          pSVar35 = (SSL_SESSION *)0x0;
          pcStack_e8 = &DAT_00000020;
          uVar12 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
          if ((uVar12 & 0x4000) == 0) {
            unaff_s5 = param_1->session;
            if (param_1->new_session != 0) {
              if (unaff_s5 == (SSL_SESSION *)0x0) goto LAB_0049660c;
LAB_0049659c:
              puVar15 = (ushort *)param_1->tlsext_opaque_prf_input_len;
              pSStack_74 = (SSL_SESSION *)0x0;
              pSStack_e4 = pSVar35;
              if (puVar15 == (ushort *)0x0) goto LAB_00495fb0;
              pcStack_e8 = "s\n";
              if (*(int *)(puVar15 + 2) != 0) {
                pSStack_e4 = (SSL_SESSION *)(uint)*puVar15;
                pcStack_e8 = "t1_lib.c";
                uVar24 = (**(code **)(local_40 + -0x7dd8))(pSStack_e4,"t1_lib.c",0x200);
                pSVar39 = param_1->session;
                *(undefined4 *)(unaff_s5->krb5_client_princ + 0x54) = uVar24;
                pSVar35 = pSStack_e4;
                pSVar37 = local_34;
                if (*(int *)(pSVar39->krb5_client_princ + 0x54) == 0) goto LAB_004961cc;
                pcStack_e8 = *(char **)(param_1->tlsext_opaque_prf_input_len + 4);
                (**(code **)(local_40 + -0x52ec))();
                *(SSL_SESSION **)(param_1->session->krb5_client_princ + 0x58) = pSStack_e4;
                pSStack_74 = pSStack_e4;
                goto LAB_00495fa4;
              }
              goto LAB_00495ffc;
            }
            if (unaff_s5 != (SSL_SESSION *)0x0) {
              if (*(int *)(unaff_s5->krb5_client_princ + 0x54) == 0) goto LAB_0049659c;
              pSStack_74 = *(SSL_SESSION **)(unaff_s5->krb5_client_princ + 0x58);
LAB_00495fa4:
              pSStack_e4 = pSVar35;
              if (pSStack_74 == (SSL_SESSION *)0x0) goto LAB_0049660c;
LAB_00495fb0:
              pSVar35 = pSStack_74;
              pSVar37 = local_34;
              if ((int)((int)param_3 + ((-4 - (int)local_34) - (int)pSStack_74)) < 0)
              goto LAB_004961cc;
              *(char *)&local_34->ssl_version = '\0';
              *(char *)((int)&local_34->ssl_version + 1) = '#';
              *(char *)((int)&local_34->ssl_version + 2) = (char)((uint)pSStack_74 >> 8);
              *(char *)((int)&local_34->ssl_version + 3) = (char)pSStack_74;
              local_34 = (SSL_SESSION *)&local_34->key_arg_length;
              pSVar35 = pSStack_e4;
              if (pSStack_74 != (SSL_SESSION *)0x0) {
                pcStack_e8 = *(char **)(param_1->session->krb5_client_princ + 0x54);
                pSVar35 = pSStack_74;
                (**(code **)(local_40 + -0x52ec))();
                pSStack_74 = (SSL_SESSION *)((int)pSStack_74->key_arg + (int)local_34 + -8);
                local_34 = pSStack_74;
              }
              goto LAB_00495ffc;
            }
LAB_0049660c:
            pSStack_74 = (SSL_SESSION *)0x0;
            pSStack_e4 = pSVar35;
            if ((param_1->tlsext_opaque_prf_input_len == 0) ||
               (*(int *)(param_1->tlsext_opaque_prf_input_len + 4) != 0)) goto LAB_00495fb0;
            iVar13 = param_1->first_packet;
          }
          else {
LAB_00495ffc:
            iVar13 = param_1->first_packet;
            pSStack_e4 = pSVar35;
          }
          if ((iVar13 >> 8 == 3) && (0x302 < iVar13)) {
            pSVar35 = pSStack_74;
            pSVar37 = local_34;
            if ((uint)((int)param_3 - (int)local_34) < 0x24) goto LAB_004961cc;
            *(char *)&local_34->ssl_version = '\0';
            *(char *)((int)&local_34->ssl_version + 1) = '\r';
            *(char *)((int)&local_34->ssl_version + 2) = '\0';
            *(char *)((int)&local_34->ssl_version + 3) = ' ';
            *(undefined *)&local_34->key_arg_length = 0;
            *(undefined *)((int)&local_34->key_arg_length + 1) = 0x1e;
            uVar6 = tls12_sigalgs._24_4_;
            pcStack_e8 = (char *)tls12_sigalgs._20_4_;
            pSStack_e4 = tls12_sigalgs._16_4_;
            param_4 = (char *)tls12_sigalgs._12_4_;
            uVar5 = tls12_sigalgs._8_4_;
            uVar24 = tls12_sigalgs._4_4_;
            *(undefined4 *)((int)&local_34->key_arg_length + 2) = tls12_sigalgs._0_4_;
            *(undefined4 *)((int)local_34->key_arg + 2) = uVar24;
            *(undefined4 *)((int)local_34->key_arg + 6) = uVar5;
            *(char **)((int)&local_34->master_key_length + 2) = param_4;
            *(SSL_SESSION **)((int)local_34->master_key + 2) = pSStack_e4;
            *(char **)((int)local_34->master_key + 6) = pcStack_e8;
            *(undefined4 *)((int)local_34->master_key + 10) = uVar6;
            *(undefined *)((int)local_34->master_key + 0xe) = tls12_sigalgs[28];
            *(undefined *)((int)local_34->master_key + 0xf) = tls12_sigalgs[29];
            local_34 = (SSL_SESSION *)((int)local_34->master_key + 0x10);
          }
          if ((param_1->servername_done != 1) ||
             (unaff_s5 = (SSL_SESSION *)0x0, param_1->version == 0xfeff)) {
LAB_00496024:
            pSVar39 = local_34;
            *(char *)&local_34->ssl_version = '\0';
            *(char *)((int)&local_34->ssl_version + 1) = '\x0f';
            *(char *)((int)&local_34->ssl_version + 2) = '\0';
            *(char *)((int)&local_34->ssl_version + 3) = '\x01';
            if (((uint)param_1->srtp_profile & 4) == 0) {
              *(undefined *)&local_34->key_arg_length = 1;
            }
            else {
              *(undefined *)&local_34->key_arg_length = 2;
            }
            local_34 = (SSL_SESSION *)((int)&local_34->key_arg_length + 1);
            if ((*(int *)(param_1->psk_server_callback + 0x1ac) != 0) &&
               ((param_1->s3->tmp).finish_md_len == 0)) {
              pSVar35 = pSStack_74;
              pSVar37 = local_34;
              if ((int)param_3 - (int)local_34 < 4) goto LAB_004961cc;
              *(char *)&local_34->ssl_version = '3';
              *(undefined *)((int)&pSVar39->key_arg_length + 2) = 0x74;
              *(undefined *)((int)&pSVar39->key_arg_length + 3) = 0;
              pSVar39->key_arg[0] = 0;
              local_34 = (SSL_SESSION *)((int)pSVar39->key_arg + 1);
            }
            psVar14 = SSL_get_srtp_profiles(param_1);
            pSVar35 = local_34;
            if (psVar14 != (stack_st_SRTP_PROTECTION_PROFILE *)0x0) {
              pSStack_74 = (SSL_SESSION *)&local_30;
              param_4 = (char *)0x0;
              pcStack_e8 = (char *)0x0;
              pSStack_e4 = pSStack_74;
              ssl_add_clienthello_use_srtp_ext(param_1);
              pSVar35 = pSStack_74;
              pSVar37 = local_34;
              if ((int)((int)param_3 + ((-4 - (int)param_2) - (int)local_30)) < 0)
              goto LAB_004961cc;
              *(char *)&local_34->ssl_version = '\0';
              *(char *)((int)&local_34->ssl_version + 1) = '\x0e';
              *(char *)((int)&local_34->ssl_version + 2) = (char)((uint)local_30 >> 8);
              *(char *)((int)&local_34->ssl_version + 3) = (char)local_30;
              pcStack_e8 = (char *)&local_34->key_arg_length;
              pSStack_e4 = pSStack_74;
              param_4 = (char *)local_30;
              local_34 = (SSL_SESSION *)pcStack_e8;
              iVar13 = ssl_add_clienthello_use_srtp_ext(param_1);
              if (iVar13 != 0) {
                pcVar41 = *(code **)(local_40 + -0x6eb0);
                local_48 = 0x292;
                goto LAB_004961b8;
              }
              pSVar35 = (SSL_SESSION *)((int)local_30->key_arg + (int)local_34->key_arg + -0x10);
            }
            pcVar10 = (char *)((int)pSVar35 + (-2 - (int)param_2));
            if (pcVar10 != (char *)0x0) {
              *(char *)((int)&param_2->ssl_version + 1) = (char)pcVar10;
              *(char *)&param_2->ssl_version = (char)((uint)pcVar10 >> 8);
              pSVar32 = pSVar35;
            }
            goto LAB_004961d0;
          }
          for (pSVar35 = (SSL_SESSION *)0x0;
              iVar13 = (**(code **)(local_40 + -0x7fb4))(param_1->tlsext_status_expected),
              (int)pSVar35 < iVar13; pSVar35 = (SSL_SESSION *)((int)&pSVar35->ssl_version + 1)) {
            uVar24 = (**(code **)(local_40 + -0x7fbc))(param_1->tlsext_status_expected,pSVar35);
            pcStack_e8 = (char *)0x0;
            iVar13 = (**(code **)(local_40 + -0x6bfc))(uVar24);
            pSVar37 = local_34;
            if (iVar13 < 1) goto LAB_004961cc;
            unaff_s5 = (SSL_SESSION *)((int)unaff_s5->key_arg + iVar13 + -6);
          }
          if (param_1->tlsext_ocsp_ids == (stack_st_OCSP_RESPID *)0x0) {
            unaff_s6 = (_func_603 **)0x0;
          }
          else {
            pcStack_e8 = (char *)0x0;
            unaff_s6 = (_func_603 **)(**(code **)(local_40 + -0x6bf8))();
            pSVar37 = local_34;
            if ((int)unaff_s6 < 0) goto LAB_004961cc;
          }
          pSVar37 = local_34;
          if (-1 < (int)((int)param_3 + (((-7 - (int)local_34) - (int)unaff_s6) - (int)unaff_s5))) {
            *(char *)&local_34->ssl_version = '\0';
            iVar13 = (int)unaff_s5->key_arg + (int)(unaff_s6 + -2);
            *(char *)((int)&local_34->ssl_version + 1) = '\x05';
            pcStack_e8 = (char *)((int)&local_34->ssl_version + 2);
            pSVar37 = (SSL_SESSION *)pcStack_e8;
            if (iVar13 < 0xfff1) {
              pcStack_e8 = (char *)((uint)unaff_s5 & 0xff);
              unaff_s7 = (uint)unaff_s6 & 0xff;
              *(char *)((int)&local_34->ssl_version + 2) = (char)((uint)(iVar13 + 5) >> 8);
              unaff_s8 = (SSL_SESSION *)&local_34;
              *(char *)((int)&local_34->ssl_version + 3) =
                   (char)unaff_s7 + (char)pcStack_e8 + '\x05';
              *(undefined *)&local_34->key_arg_length = 1;
              *(char *)((int)&local_34->key_arg_length + 1) = (char)((uint)unaff_s5 >> 8);
              *(char *)((int)&local_34->key_arg_length + 2) = (char)pcStack_e8;
              local_34 = (SSL_SESSION *)((int)&local_34->key_arg_length + 3);
              unaff_s5 = (SSL_SESSION *)((int)unaff_s5 >> 8);
              for (pSStack_74 = (SSL_SESSION *)0x0;
                  iVar13 = (**(code **)(local_40 + -0x7fb4))(param_1->tlsext_status_expected),
                  pSVar35 = local_34, (int)pSStack_74 < iVar13;
                  pSStack_74 = (SSL_SESSION *)((int)&pSStack_74->ssl_version + 1)) {
                uVar24 = (**(code **)(local_40 + -0x7fbc))
                                   (param_1->tlsext_status_expected,pSStack_74);
                local_34 = (SSL_SESSION *)((int)&local_34->ssl_version + 2);
                pcStack_e8 = (char *)unaff_s8;
                uVar25 = (**(code **)(local_40 + -0x6bfc))(uVar24);
                *(char *)((int)&pSVar35->ssl_version + 1) = (char)uVar25;
                *(char *)&pSVar35->ssl_version = (char)((ushort)uVar25 >> 8);
                unaff_s5 = pSVar35;
              }
              *(char *)&local_34->ssl_version = (char)((uint)unaff_s6 >> 8);
              *(char *)((int)&local_34->ssl_version + 1) = (char)unaff_s7;
              local_34 = (SSL_SESSION *)((int)&local_34->ssl_version + 2);
              if (unaff_s6 != (_func_603 **)0x0) {
                pcStack_e8 = (char *)&local_34;
                (**(code **)(local_40 + -0x6bf8))(param_1->tlsext_ocsp_ids);
              }
              goto LAB_00496024;
            }
          }
        }
        else {
          pSVar35 = (SSL_SESSION *)&local_30;
          param_4 = (char *)0x0;
          pcStack_e8 = (char *)0x0;
          pSStack_e4 = pSVar35;
          iVar13 = (**(code **)(local_40 + -0x6c08))(param_1);
          if (iVar13 == 0) {
            pcVar41 = *(code **)(local_40 + -0x6eb0);
            local_48 = 0x198;
          }
          else {
            pSVar37 = local_34;
            if ((int)((int)param_3 + ((-4 - (int)param_2) - (int)local_30)) < 0) goto LAB_004961cc;
            pcVar41 = *(code **)(local_40 + -0x6c08);
            *(char *)&local_34->ssl_version = -1;
            *(char *)((int)&local_34->ssl_version + 1) = '\x01';
            *(char *)((int)&local_34->ssl_version + 2) = (char)((uint)local_30 >> 8);
            *(char *)((int)&local_34->ssl_version + 3) = (char)local_30;
            pcStack_e8 = (char *)&local_34->key_arg_length;
            pSStack_e4 = pSVar35;
            param_4 = (char *)local_30;
            local_34 = (SSL_SESSION *)pcStack_e8;
            iVar13 = (*pcVar41)(param_1);
            if (iVar13 != 0) {
              local_34 = (SSL_SESSION *)((int)local_30->key_arg + (int)local_34->key_arg + -0x10);
              goto LAB_00495d38;
            }
            pcVar41 = *(code **)(local_40 + -0x6eb0);
            local_48 = 0x1a3;
          }
LAB_004961b8:
          param_4 = "t1_lib.c";
          pSStack_e4 = (SSL_SESSION *)0x44;
          pcStack_e8 = (char *)0x115;
          (*pcVar41)(0x14);
          pSVar37 = local_34;
        }
      }
      else {
        pSVar39 = (SSL_SESSION *)((int)param_3 + (-9 - (int)pSStack_74));
        pSVar35 = pSVar39;
        pSVar37 = pSStack_74;
        if (-1 < (int)pSVar39) {
          local_34 = pSStack_74;
          pSVar9 = (SSL_SESSION *)(*(code *)PTR_strlen_006aab30)();
          pSVar35 = (SSL_SESSION *)(uint)(pSVar39 < pSVar9);
          pSVar37 = local_34;
          if ((SSL_SESSION *)(uint)(pSVar39 < pSVar9) == (SSL_SESSION *)0x0) {
            cVar2 = (char)pSVar9;
            pcVar41 = *(code **)(local_40 + -0x52ec);
            *(char *)((int)&param_2->ssl_version + 2) = '\0';
            *(char *)((int)param_2->key_arg + 2) = cVar2;
            *(char *)((int)&param_2->ssl_version + 3) = '\0';
            param_2->key_arg[0] = 0;
            *(char *)((int)&param_2->key_arg_length + 1) = cVar2 + '\x05';
            param_4 = (char *)((uint)pSVar9 >> 8);
            *(char *)&param_2->key_arg_length =
                 (char)((uint)((int)&pSVar9->key_arg_length + 1) >> 8);
            *(char *)((int)&param_2->key_arg_length + 2) =
                 (char)((uint)((int)&pSVar9->ssl_version + 3) >> 8);
            local_34 = (SSL_SESSION *)((int)param_2->key_arg + 3);
            *(char *)((int)&param_2->key_arg_length + 3) = cVar2 + '\x03';
            *(char *)((int)param_2->key_arg + 1) = (char)((uint)pSVar9 >> 8);
            pSStack_74 = (SSL_SESSION *)((int)local_34 + (int)pSVar9);
            pcStack_e8 = (char *)param_1->tlsext_debug_arg;
            (*pcVar41)();
            pSStack_e4 = pSVar9;
            goto LAB_00495d2c;
          }
        }
      }
    }
LAB_004961cc:
    local_34 = pSVar37;
    pSVar32 = (SSL_SESSION *)0x0;
    pSStack_74 = pSVar35;
  }
LAB_004961d0:
  if (local_2c == *(SSL **)puStack_6c) {
    return pSVar32;
  }
  pcStack_5c = ssl_add_serverhello_tlsext;
  pSStack_ec = local_2c;
  (**(code **)(local_40 + -0x5328))();
  puStack_e0 = PTR___stack_chk_guard_006aabf0;
  puStack_b0 = &_gp;
  pSStack_7c = *(SSL **)PTR___stack_chk_guard_006aabf0;
  pSStack_f0 = (SSL_SESSION *)((int)(BIO_METHOD **)pcStack_e8 + 2);
  pSVar32 = (SSL_SESSION *)pcStack_e8;
  pSVar35 = pSStack_e4;
  pSStack_78 = param_1;
  pSStack_70 = param_2;
  pSStack_68 = param_3;
  pSStack_64 = unaff_s5;
  pp_Stack_60 = unaff_s6;
  if (((pSStack_ec->version == 0x300) &&
      (pSVar37 = (SSL_SESSION *)pcStack_e8, pSStack_ec->s3->send_connection_binding == 0)) ||
     (pSVar37 = (SSL_SESSION *)0x0, pSStack_e4 <= pSStack_f0)) goto LAB_004969b4;
  pSVar39 = pSStack_f0;
  if (((pSStack_ec->hit == 0) && (pSStack_ec->tlsext_hostname == (char *)0x1)) &&
     (*(int *)(pSStack_ec->session->krb5_client_princ + 0x40) != 0)) {
    pSVar39 = (SSL_SESSION *)((int)((int)pcStack_e8 + 4) + 2);
    if (3 < (int)pSStack_e4 - (int)pSStack_f0) {
      *(char *)((int)(BIO_METHOD **)pcStack_e8 + 2) = '\0';
      *(char *)((int)(BIO_METHOD **)pcStack_e8 + 3) = '\0';
      *(undefined *)((int)pcStack_e8 + 4) = 0;
      *(undefined *)((int)((int)pcStack_e8 + 4) + 1) = 0;
      goto LAB_00496750;
    }
  }
  else {
LAB_00496750:
    pSStack_f0 = pSVar39;
    if (pSStack_ec->s3->send_connection_binding == 0) {
LAB_00496760:
      if ((pSStack_ec->tlsext_ecpointformatlist_length != 0) && (pSStack_ec->version != 0xfeff)) {
        pcVar10 = (char *)((int)pSStack_e4 + (-5 - (int)pSStack_f0));
        pSVar39 = pSStack_f0;
        if (((int)pcVar10 < 0) || (pcVar10 < (char *)pSStack_ec->tlsext_ticket_expected))
        goto LAB_00496a68;
        if ((char *)0xff < (char *)pSStack_ec->tlsext_ticket_expected) {
          pcVar41 = *(code **)(puStack_b0 + -0x6eb0);
          puStack_b8 = (undefined4 *)0x2da;
          pSVar37 = unaff_s5;
          goto LAB_00496a54;
        }
        *(char *)&pSStack_f0->ssl_version = '\0';
        pcVar41 = *(code **)(puStack_b0 + -0x52ec);
        *(char *)((int)&pSStack_f0->ssl_version + 1) = '\v';
        *(char *)((int)&pSStack_f0->ssl_version + 2) =
             (char)((uint)(pSStack_ec->tlsext_ticket_expected + 1) >> 8);
        *(char *)((int)&pSStack_f0->ssl_version + 3) =
             (char)pSStack_ec->tlsext_ticket_expected + '\x01';
        *(char *)&pSStack_f0->key_arg_length = (char)pSStack_ec->tlsext_ticket_expected;
        pSVar35 = (SSL_SESSION *)pSStack_ec->tlsext_ticket_expected;
        pSVar32 = (SSL_SESSION *)pSStack_ec->tlsext_ecpointformatlist_length;
        iVar13 = (*pcVar41)((undefined *)((int)&pSStack_f0->key_arg_length + 1));
        pSStack_f0 = (SSL_SESSION *)(iVar13 + pSStack_ec->tlsext_ticket_expected);
      }
      pSVar9 = pSStack_f0;
      if (pSStack_ec->tlsext_ocsp_resplen != 0) {
        param_4 = (char *)0x0;
        pSVar35 = (SSL_SESSION *)0x0;
        pSVar32 = (SSL_SESSION *)&DAT_00000020;
        uVar12 = SSL_ctrl(pSStack_ec,0x20,0,(void *)0x0);
        if ((uVar12 & 0x4000) == 0) {
          pSVar37 = (SSL_SESSION *)0x0;
          if ((int)pSStack_e4 - (int)pSStack_f0 < 4) goto LAB_004969b4;
          *(char *)&pSStack_f0->ssl_version = '\0';
          *(char *)((int)&pSStack_f0->ssl_version + 2) = '\0';
          pSVar9 = (SSL_SESSION *)&pSStack_f0->key_arg_length;
          *(char *)((int)&pSStack_f0->ssl_version + 3) = '\0';
          *(char *)((int)&pSStack_f0->ssl_version + 1) = '#';
        }
      }
      pSVar39 = pSVar9;
      if (pSStack_ec->tlsext_status_type != 0) {
        pSVar37 = (SSL_SESSION *)0x0;
        pSStack_f0 = pSVar9;
        if ((int)pSStack_e4 - (int)pSVar9 < 4) goto LAB_004969b4;
        *(char *)&pSVar9->ssl_version = '\0';
        *(char *)((int)&pSVar9->ssl_version + 2) = '\0';
        pSVar39 = (SSL_SESSION *)&pSVar9->key_arg_length;
        *(char *)((int)&pSVar9->ssl_version + 3) = '\0';
        *(char *)((int)&pSVar9->ssl_version + 1) = '\x05';
      }
      if (pSStack_ec->srtp_profiles != (stack_st_SRTP_PROTECTION_PROFILE *)0x0) {
        unaff_s5 = (SSL_SESSION *)&pSStack_a4;
        pSVar32 = (SSL_SESSION *)0x0;
        pSVar35 = unaff_s5;
        ssl_add_serverhello_use_srtp_ext(pSStack_ec,0,unaff_s5,0);
        param_4 = (char *)pSStack_a4;
        if ((int)((int)pSStack_e4 + ((-4 - (int)pcStack_e8) - (int)pSStack_a4)) < 0)
        goto LAB_00496a68;
        *(char *)&pSVar39->ssl_version = '\0';
        unaff_s6 = (_func_603 **)&pSVar39->key_arg_length;
        *(char *)((int)&pSVar39->ssl_version + 3) = (char)pSStack_a4;
        *(char *)((int)&pSVar39->ssl_version + 2) = (char)((uint)pSStack_a4 >> 8);
        *(char *)((int)&pSVar39->ssl_version + 1) = '\x0e';
        pSVar32 = (SSL_SESSION *)unaff_s6;
        pSVar35 = unaff_s5;
        iVar13 = ssl_add_serverhello_use_srtp_ext(pSStack_ec);
        if (iVar13 != 0) {
          pcVar41 = *(code **)(puStack_b0 + -0x6eb0);
          puStack_b8 = (undefined4 *)0x318;
          pSVar37 = unaff_s5;
          goto LAB_00496a54;
        }
        pSVar39 = (SSL_SESSION *)((int)pSStack_a4->key_arg + (int)(unaff_s6 + -2));
      }
      if (*(ushort *)((int)&((pSStack_ec->s3->tmp).new_cipher)->id + 2) - 0x80 < 2) {
        param_4 = (char *)0x0;
        pSVar35 = (SSL_SESSION *)0x0;
        pSVar32 = (SSL_SESSION *)&DAT_00000020;
        lVar17 = SSL_ctrl(pSStack_ec,0x20,0,(void *)0x0);
        if (lVar17 < 0) {
          ppSVar18 = (SSL_SESSION **)&DAT_00647a50;
          ppSVar26 = apSStack_a0;
          do {
            pSVar37 = *ppSVar18;
            ppSVar27 = ppSVar26 + 4;
            param_4 = (char *)ppSVar18[1];
            pSVar35 = ppSVar18[2];
            pSVar32 = ppSVar18[3];
            ppSVar18 = ppSVar18 + 4;
            *ppSVar26 = pSVar37;
            ppSVar26[1] = (SSL_SESSION *)param_4;
            ppSVar26[2] = pSVar35;
            ppSVar26[3] = pSVar32;
            ppSVar26 = ppSVar27;
          } while (ppSVar18 != (SSL_SESSION **)&UNK_00647a70);
          pSVar32 = (SSL_SESSION *)(uint)((int)pSStack_e4 - (int)pSVar39 < 0x24);
          *ppSVar27 = _UNK_00647a70;
          pSVar35 = _UNK_00647a70;
          if (pSVar32 != (SSL_SESSION *)0x0) goto LAB_00496a68;
          pSVar37 = pSVar39;
          ppSVar26 = apSStack_a0;
          do {
            param_4 = (char *)*ppSVar26;
            ppSVar18 = ppSVar26 + 4;
            pSVar35 = ppSVar26[1];
            pSVar32 = ppSVar26[2];
            pSVar9 = ppSVar26[3];
            pSVar37->ssl_version = (int)param_4;
            pSVar37->key_arg_length = (uint)pSVar35;
            *(SSL_SESSION **)pSVar37->key_arg = pSVar32;
            *(SSL_SESSION **)((int)pSVar37->key_arg + 4) = pSVar9;
            pSVar37 = (SSL_SESSION *)&pSVar37->master_key_length;
            ppSVar26 = ppSVar18;
          } while (ppSVar18 != &pSStack_80);
          pSVar39 = (SSL_SESSION *)((int)pSVar39->master_key + 0x10);
          *(SSL_SESSION **)pSVar37 = *ppSVar18;
        }
      }
      pSStack_f0 = pSVar39;
      if (((uint)pSStack_ec->srtp_profile & 1) == 0) {
LAB_004968fc:
        iVar13 = pSStack_ec->s3->next_proto_neg_seen;
        pSStack_ec->s3->next_proto_neg_seen = 0;
        if (iVar13 != 0) {
          p_Var16 = pSStack_ec->psk_server_callback;
LAB_00496910:
          pSVar35 = (SSL_SESSION *)&pSStack_a4;
          if (*(code **)(p_Var16 + 0x1a4) != (code *)0x0) {
            param_4 = *(char **)(p_Var16 + 0x1a8);
            pSVar32 = (SSL_SESSION *)&pSStack_a8;
            iVar13 = (**(code **)(p_Var16 + 0x1a4))(pSStack_ec);
            if (iVar13 == 0) {
              pSStack_e4 = (SSL_SESSION *)
                           ((int)pSStack_e4 + ((-4 - (int)pSStack_a4) - (int)pSStack_f0));
              pSVar39 = pSStack_f0;
              unaff_s5 = pSStack_a4;
              if ((int)pSStack_e4 < 0) goto LAB_00496a68;
              pcVar41 = *(code **)(puStack_b0 + -0x52ec);
              *(char *)((int)&pSStack_f0->ssl_version + 3) = (char)pSStack_a4;
              *(char *)&pSStack_f0->ssl_version = '3';
              *(char *)((int)&pSStack_f0->ssl_version + 2) = (char)((uint)pSStack_a4 >> 8);
              *(char *)((int)&pSStack_f0->ssl_version + 1) = 't';
              pSVar35 = pSStack_a4;
              iVar13 = (*pcVar41)(&pSStack_f0->key_arg_length);
              pSStack_f0 = (SSL_SESSION *)((int)pSStack_a4->key_arg + iVar13 + -8);
              pSStack_ec->s3->next_proto_neg_seen = 1;
              pSVar32 = pSStack_a8;
            }
          }
        }
      }
      else {
        *(char *)&pSVar39->ssl_version = '\0';
        *(char *)((int)&pSVar39->ssl_version + 2) = '\0';
        *(char *)((int)&pSVar39->ssl_version + 1) = '\x0f';
        *(char *)((int)&pSVar39->ssl_version + 3) = '\x01';
        if (((uint)pSStack_ec->srtp_profile & 4) != 0) {
          pSStack_f0 = (SSL_SESSION *)((int)&pSVar39->key_arg_length + 1);
          *(undefined *)&pSVar39->key_arg_length = 2;
          goto LAB_004968fc;
        }
        *(undefined *)&pSVar39->key_arg_length = 1;
        pSStack_f0 = (SSL_SESSION *)((int)&pSVar39->key_arg_length + 1);
        iVar13 = pSStack_ec->s3->next_proto_neg_seen;
        pSStack_ec->s3->next_proto_neg_seen = 0;
        if (iVar13 != 0) {
          p_Var16 = pSStack_ec->psk_server_callback;
          goto LAB_00496910;
        }
      }
      pcVar10 = (char *)((int)pSStack_f0 + (-2 - (int)pcStack_e8));
      pSVar37 = (SSL_SESSION *)pcStack_e8;
      if (pcVar10 != (char *)0x0) {
        *(char *)((int)(BIO_METHOD **)pcStack_e8 + 1) = (char)pcVar10;
        *(char *)(BIO_METHOD **)pcStack_e8 = (char)((uint)pcVar10 >> 8);
        pSVar37 = pSStack_f0;
      }
      goto LAB_004969b4;
    }
    pSVar37 = (SSL_SESSION *)&pSStack_a4;
    pSVar32 = (SSL_SESSION *)0x0;
    pSVar35 = pSVar37;
    iVar13 = (*(code *)PTR_ssl_add_serverhello_renegotiate_ext_006a92ec)(pSStack_ec,0,pSVar37,0);
    if (iVar13 == 0) {
      pcVar41 = *(code **)(puStack_b0 + -0x6eb0);
      puStack_b8 = (undefined4 *)0x2bd;
    }
    else {
      param_4 = (char *)pSStack_a4;
      unaff_s5 = pSVar37;
      if ((int)((int)pSStack_e4 + ((-4 - (int)pcStack_e8) - (int)pSStack_a4)) < 0)
      goto LAB_00496a68;
      pcVar41 = *(code **)(puStack_b0 + -0x6bf4);
      *(char *)((int)&pSVar39->ssl_version + 3) = (char)pSStack_a4;
      unaff_s6 = (_func_603 **)&pSVar39->key_arg_length;
      *(char *)&pSVar39->ssl_version = -1;
      *(char *)((int)&pSVar39->ssl_version + 2) = (char)((uint)pSStack_a4 >> 8);
      *(char *)((int)&pSVar39->ssl_version + 1) = '\x01';
      pSVar32 = (SSL_SESSION *)unaff_s6;
      pSVar35 = pSVar37;
      iVar13 = (*pcVar41)(pSStack_ec);
      if (iVar13 != 0) {
        pSStack_f0 = (SSL_SESSION *)((int)pSStack_a4->key_arg + (int)(unaff_s6 + -2));
        goto LAB_00496760;
      }
      pcVar41 = *(code **)(puStack_b0 + -0x6eb0);
      puStack_b8 = (undefined4 *)0x2c8;
    }
LAB_00496a54:
    param_4 = "t1_lib.c";
    pSVar35 = (SSL_SESSION *)0x44;
    pSVar32 = (SSL_SESSION *)&DAT_00000116;
    (*pcVar41)(0x14);
    unaff_s5 = pSVar37;
  }
LAB_00496a68:
  pSVar37 = (SSL_SESSION *)0x0;
  pSStack_f0 = pSVar39;
LAB_004969b4:
  if (pSStack_7c == *(SSL **)puStack_e0) {
    return pSVar37;
  }
  pcStack_cc = ssl_parse_serverhello_tlsext;
  pSVar28 = pSStack_7c;
  (**(code **)(puStack_b0 + -0x5328))();
  puVar8 = puStack_b8;
  puVar23 = PTR___stack_chk_guard_006aabf0;
  pSVar29 = pSVar28->srtp_profile;
  pBVar33 = (BIO_METHOD *)pSVar32->ssl_version;
  pSStack_f4 = *(SSL **)PTR___stack_chk_guard_006aabf0;
  pSVar28->s3->next_proto_neg_seen = 0;
  pSVar28->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)pSVar29 & 0xfffffffc);
  pBVar40 = (BIO_METHOD *)((int)&pBVar33->type + 2);
  pSStack_dc = unaff_s5;
  pp_Stack_d8 = unaff_s6;
  uStack_d4 = unaff_s7;
  pSStack_d0 = unaff_s8;
  if (pBVar33 < (BIO_METHOD *)
                ((undefined *)
                 ((int)&((SSL_SESSION *)((int)param_4 + -500))->tlsext_tick_lifetime_hint + 2) +
                (int)((int)pSVar35->key_arg + -8))) {
    pBVar33 = (BIO_METHOD *)((int)&pBVar40->type + (uint)*(ushort *)&pBVar33->type);
    if (pBVar33 == (BIO_METHOD *)((int)((int)param_4 + 8) + (int)pSVar35->key_arg + -0x10)) {
      bVar4 = false;
      bVar3 = false;
LAB_00496df8:
      pBVar38 = pBVar40;
      ppcVar36 = &pBVar38->name;
      if ((BIO_METHOD *)
          ((int)&((SSL_SESSION *)((int)param_4 + -500))->tlsext_tick_lifetime_hint +
          (int)((int)pSVar35->key_arg + -8)) < pBVar38) {
        if (pBVar38 != pBVar33) goto LAB_00496d50;
        if (((pSVar28->hit == 0) && (bVar3)) && (pSVar28->tlsext_debug_arg != (void *)0x0)) {
          pSVar35 = pSVar28->session;
          if (*(int *)(pSVar35->krb5_client_princ + 0x40) != 0) goto LAB_00496d50;
          uVar24 = (*(code *)PTR_BUF_strdup_006a80dc)();
          pSVar37 = pSVar28->session;
          *(undefined4 *)(pSVar35->krb5_client_princ + 0x40) = uVar24;
          if (*(int *)(pSVar37->krb5_client_princ + 0x40) == 0) goto LAB_004971f0;
        }
        pSVar32->ssl_version = (int)pBVar38;
LAB_00497198:
        pSVar37 = (SSL_SESSION *)0x1;
        if (bVar4) goto LAB_00496d5c;
        goto LAB_00496d0c;
      }
      sVar1 = *(short *)&pBVar38->type;
      uVar12 = (uint)*(ushort *)((int)&pBVar38->type + 2);
      pBVar40 = (BIO_METHOD *)((int)ppcVar36 + uVar12);
      if (pBVar33 < pBVar40) goto LAB_00497198;
      if ((code *)pSVar28->max_send_fragment != (code *)0x0) {
        (*(code *)pSVar28->max_send_fragment)
                  (pSVar28,1,sVar1,ppcVar36,uVar12,pSVar28->tlsext_debug_cb);
      }
      if (sVar1 == 0) {
        if ((pSVar28->tlsext_debug_arg == (void *)0x0) || (uVar12 != 0)) {
LAB_004971f0:
          pSVar37 = (SSL_SESSION *)0x0;
          *puVar8 = 0x70;
          goto LAB_00496d5c;
        }
        bVar3 = true;
        goto LAB_00496df8;
      }
      if (sVar1 == 0xb) {
        if (pSVar28->version != 0xfeff) {
          uVar19 = (uint)*(byte *)&pBVar38->name;
          if ((uVar19 != uVar12 - 1) || (uVar19 == 0)) goto LAB_00496d50;
          pSVar37 = pSVar28->session;
          *(undefined4 *)(pSVar37->krb5_client_princ + 0x44) = 0;
          if (*(int *)(pSVar37->krb5_client_princ + 0x48) != 0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)();
            pSVar37 = pSVar28->session;
          }
          iVar13 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar19,"t1_lib.c",0x5fb);
          *(int *)(pSVar37->krb5_client_princ + 0x48) = iVar13;
          puVar7 = PTR_memcpy_006aabf4;
          if (iVar13 == 0) {
LAB_00497224:
            pSVar37 = (SSL_SESSION *)0x0;
            *puVar8 = 0x50;
            goto LAB_00496d5c;
          }
          pSVar37 = pSVar28->session;
          *(uint *)(pSVar37->krb5_client_princ + 0x44) = uVar19;
          (*(code *)puVar7)(*(undefined4 *)(pSVar37->krb5_client_princ + 0x48),
                            (undefined *)((int)&pBVar38->name + 1),uVar19);
        }
        goto LAB_00496df8;
      }
      if (sVar1 == 0x23) {
        if ((pSVar28->tlsext_session_ticket != (TLS_SESSION_TICKET_EXT *)0x0) &&
           (iVar13 = (*(code *)pSVar28->tlsext_session_ticket)
                               (pSVar28,ppcVar36,uVar12,pSVar28->tls_session_ticket_ext_cb),
           iVar13 == 0)) goto LAB_00497224;
        uVar19 = SSL_ctrl(pSVar28,0x20,0,(void *)0x0);
        if (((uVar19 & 0x4000) != 0) || (uVar12 != 0)) {
LAB_00497214:
          pSVar37 = (SSL_SESSION *)0x0;
          *puVar8 = 0x6e;
          goto LAB_00496d5c;
        }
        pSVar28->tlsext_ocsp_resplen = 1;
        goto LAB_00496df8;
      }
      if (sVar1 == 5) {
        if (pSVar28->version != 0xfeff) {
          if ((pSVar28->servername_done == -1) || (uVar12 != 0)) goto LAB_00497214;
          pSVar28->tlsext_status_type = 1;
        }
        goto LAB_00496df8;
      }
      if (sVar1 == 0x3374) {
        pSVar37 = (SSL_SESSION *)(pSVar28->s3->tmp).finish_md_len;
        if (pSVar37 == (SSL_SESSION *)0x0) {
          pcVar41 = *(code **)(pSVar28->psk_server_callback + 0x1ac);
          if (pcVar41 == (code *)0x0) {
            *puVar8 = 0x6e;
            goto LAB_00496d5c;
          }
          if (uVar12 != 0) {
            uVar19 = (uint)*(byte *)&pBVar38->name;
            uVar30 = 0;
            if (uVar19 != 0) {
              while( true ) {
                uVar30 = uVar30 + uVar19 + 1;
                if (uVar12 <= uVar30) break;
                uVar19 = (uint)*(byte *)((int)ppcVar36 + uVar30);
                if (uVar19 == 0) goto LAB_00497258;
              }
              if (uVar12 == uVar30) goto LAB_00497078;
            }
LAB_00497258:
            *puVar8 = 0x32;
            goto LAB_00496d5c;
          }
LAB_00497078:
          iVar13 = (*pcVar41)(pSVar28,&uStack_f8,&uStack_f9,ppcVar36,uVar12,
                              *(undefined4 *)(pSVar28->psk_server_callback + 0x1b0));
          if (iVar13 == 0) {
            pSVar20 = (SSL_CTX *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uStack_f9,"t1_lib.c",0x662);
            pSVar28->initial_ctx = pSVar20;
            if (pSVar20 != (SSL_CTX *)0x0) {
              (*(code *)PTR_memcpy_006aabf4)(pSVar20,uStack_f8,uStack_f9);
              *(undefined *)&pSVar28->next_proto_negotiated = uStack_f9;
              pSVar28->s3->next_proto_neg_seen = 1;
              goto LAB_00496df8;
            }
          }
          *puVar8 = 0x50;
          goto LAB_00496d5c;
        }
        goto LAB_00496df8;
      }
      if (sVar1 == -0xff) {
        iVar13 = (*(code *)PTR_ssl_parse_serverhello_renegotiate_ext_006a92f8)
                           (pSVar28,ppcVar36,uVar12,puVar8);
        if (iVar13 == 0) goto LAB_00497140;
        bVar4 = true;
        goto LAB_00496df8;
      }
      if (sVar1 == 0xf) {
        if (*(char *)&pBVar38->name == '\x01') {
          pSVar28->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)pSVar28->srtp_profile | 1);
        }
        else {
          if (*(char *)&pBVar38->name != '\x02') {
            pSVar37 = (SSL_SESSION *)0x0;
            *puVar8 = 0x2f;
            goto LAB_00496d5c;
          }
          pSVar28->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)pSVar28->srtp_profile | 3);
        }
        goto LAB_00496df8;
      }
      if ((sVar1 != 0xe) ||
         (iVar13 = ssl_parse_serverhello_use_srtp_ext(pSVar28,ppcVar36,uVar12,puVar8), iVar13 == 0))
      goto LAB_00496df8;
LAB_00497140:
      pSVar37 = (SSL_SESSION *)0x0;
    }
    else {
LAB_00496d50:
      pSVar37 = (SSL_SESSION *)0x0;
      *puVar8 = 0x32;
    }
  }
  else {
LAB_00496d0c:
    puVar7 = PTR_ERR_put_error_006a9030;
    if ((pSVar28->references & 0x40004U) == 0) {
      *puVar8 = 0x28;
      (*(code *)puVar7)(0x14,0x12f,0x152,"t1_lib.c",0x6bc);
      pSVar37 = (SSL_SESSION *)0x0;
    }
    else {
      pSVar37 = (SSL_SESSION *)0x1;
    }
  }
LAB_00496d5c:
  if (pSStack_f4 == *(SSL **)puVar23) {
    return pSVar37;
  }
  pSVar28 = pSStack_f4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  psVar21 = SSL_get_ciphers(pSVar28);
  iVar13 = 0;
  do {
    iVar22 = (*(code *)PTR_sk_num_006a7f2c)(psVar21);
    if (iVar22 <= iVar13) {
      return (SSL_SESSION *)0x1;
    }
    iVar22 = (*(code *)PTR_sk_value_006a7f24)(psVar21,iVar13);
  } while (((*(uint *)(iVar22 + 0xc) & 0xe0) == 0) &&
          (iVar13 = iVar13 + 1, (*(uint *)(iVar22 + 0x10) & 0x40) == 0));
  pSVar32 = (SSL_SESSION *)0x1;
  if (0x300 < pSVar28->version) {
    if (pSVar28->tlsext_ecpointformatlist_length != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    puVar23 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(3,"t1_lib.c",0x6e0);
    pSVar28->tlsext_ecpointformatlist_length = (size_t)puVar23;
    if (puVar23 == (undefined *)0x0) {
      uVar24 = 0x6e2;
      pcVar41 = (code *)PTR_ERR_put_error_006a9030;
    }
    else {
      pSVar28->tlsext_ticket_expected = 3;
      *puVar23 = 0;
      *(undefined *)(pSVar28->tlsext_ecpointformatlist_length + 1) = 1;
      *(undefined *)(pSVar28->tlsext_ecpointformatlist_length + 2) = 2;
      if (pSVar28->tlsext_ellipticcurvelist_length != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      puVar23 = PTR_CRYPTO_malloc_006a8108;
      pSVar28->tlsext_ecpointformatlist = (uchar *)0x32;
      puVar23 = (undefined *)(*(code *)puVar23)(0x32,"t1_lib.c",0x6ed);
      pSVar28->tlsext_ellipticcurvelist_length = (size_t)puVar23;
      pcVar41 = (code *)PTR_ERR_put_error_006a9030;
      if (puVar23 != (undefined *)0x0) {
        puVar31 = pref_list;
        do {
          iVar13 = *(int *)puVar31;
          uVar34 = 2;
          if (iVar13 != 0x2d2) {
            if (iVar13 < 0x2d3) {
              uVar34 = 0x12;
              if (iVar13 != 0x2c7) {
                if (iVar13 < 0x2c8) {
                  uVar34 = 0xf;
                  if (iVar13 != 0x2c4) {
                    if (iVar13 < 0x2c5) {
                      if (iVar13 == 0x199) {
                        uVar34 = 0x13;
                      }
                      else {
                        uVar34 = 0x17;
                        if (iVar13 != 0x19f) {
                          uVar34 = 0;
                        }
                      }
                    }
                    else if (iVar13 == 0x2c5) {
                      uVar34 = 0x10;
                    }
                    else {
                      uVar34 = 0x11;
                      if (iVar13 != 0x2c6) {
                        uVar34 = 0;
                      }
                    }
                  }
                }
                else {
                  uVar34 = 0x16;
                  if (iVar13 != 0x2ca) {
                    if (iVar13 < 0x2cb) {
                      if (iVar13 == 0x2c8) {
                        uVar34 = 0x14;
                      }
                      else {
                        uVar34 = 0x15;
                        if (iVar13 != 0x2c9) {
                          uVar34 = 0;
                        }
                      }
                    }
                    else {
                      uVar34 = 0x19;
                      if (iVar13 != 0x2cc) {
                        if (iVar13 < 0x2cc) {
                          uVar34 = 0x18;
                        }
                        else {
                          uVar34 = 1;
                          if (iVar13 != 0x2d1) goto LAB_0049750c;
                        }
                      }
                    }
                  }
                }
              }
            }
            else {
              uVar34 = 8;
              if (iVar13 != 0x2d8) {
                if (iVar13 < 0x2d9) {
                  uVar34 = 5;
                  if (iVar13 != 0x2d5) {
                    if (iVar13 < 0x2d6) {
                      if (iVar13 == 0x2d3) {
                        uVar34 = 3;
                      }
                      else {
                        uVar34 = 4;
                        if (iVar13 != 0x2d4) {
                          uVar34 = 0;
                        }
                      }
                    }
                    else if (iVar13 == 0x2d6) {
                      uVar34 = 6;
                    }
                    else {
                      uVar34 = 7;
                      if (iVar13 != 0x2d7) {
                        uVar34 = 0;
                      }
                    }
                  }
                }
                else {
                  uVar34 = 0xb;
                  if (iVar13 != 0x2db) {
                    if (iVar13 < 0x2dc) {
                      if (iVar13 == 0x2d9) {
                        uVar34 = 9;
                      }
                      else {
                        uVar34 = 10;
                        if (iVar13 != 0x2da) {
                          uVar34 = 0;
                        }
                      }
                    }
                    else {
                      uVar34 = 0xd;
                      if (iVar13 != 0x2dd) {
                        if (iVar13 < 0x2dd) {
                          uVar34 = 0xc;
                        }
                        else {
                          uVar34 = 0xe;
                          if (iVar13 != 0x2de) {
LAB_0049750c:
                            uVar34 = 0;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          puVar31 = (undefined1 *)((int)puVar31 + 4);
          *puVar23 = 0;
          puVar23[1] = uVar34;
          puVar23 = puVar23 + 2;
          if (puVar31 == nid_list) {
            return (SSL_SESSION *)0x1;
          }
        } while( true );
      }
      pSVar28->tlsext_ecpointformatlist = (uchar *)0x0;
      uVar24 = 0x6f0;
    }
    (*pcVar41)(0x14,0x119,0x41,"t1_lib.c",uVar24);
    pSVar32 = (SSL_SESSION *)0xffffffff;
  }
  return pSVar32;
}

