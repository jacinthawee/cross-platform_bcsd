
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

SSL_SESSION *
ssl_add_clienthello_tlsext
          (SSL_SESSION *param_1,SSL_SESSION *param_2,SSL_SESSION *param_3,char *param_4)

{
  ushort uVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined *puVar7;
  undefined4 *puVar8;
  SSL_SESSION *pSVar9;
  undefined *puVar10;
  uchar *puVar11;
  uint uVar12;
  int iVar13;
  undefined2 uVar23;
  stack_st_SRTP_PROTECTION_PROFILE *psVar14;
  _func_3154 *p_Var15;
  long lVar16;
  SSL_SESSION **ppSVar17;
  uint uVar18;
  SSL_CTX *pSVar19;
  stack_st_SSL_CIPHER *psVar20;
  int iVar21;
  undefined4 uVar22;
  SSL_SESSION *pSVar24;
  undefined uVar27;
  SSL_SESSION **ppSVar25;
  SRTP_PROTECTION_PROFILE *pSVar26;
  undefined uVar33;
  SSL_SESSION **ppSVar28;
  SSL *pSVar29;
  ushort *puVar30;
  uint uVar31;
  undefined1 *puVar32;
  SSL_SESSION *pSVar34;
  SSL_SESSION *pSVar35;
  ushort *puVar36;
  SSL_SESSION *pSVar37;
  ushort *puVar38;
  SSL_SESSION *unaff_s5;
  uint *unaff_s6;
  uint unaff_s7;
  code *pcVar39;
  SSL_SESSION *unaff_s8;
  ushort *puVar40;
  undefined uStack_f9;
  undefined4 uStack_f8;
  SSL *pSStack_f4;
  SSL_SESSION *pSStack_f0;
  SSL *pSStack_ec;
  SSL_SESSION *pSStack_e8;
  undefined *puStack_e4;
  char *pcStack_e0;
  SSL_SESSION *pSStack_dc;
  uint *puStack_d8;
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
  SSL_SESSION *pSStack_78;
  SSL_SESSION *pSStack_74;
  SSL_SESSION *pSStack_70;
  undefined *puStack_6c;
  SSL_SESSION *pSStack_68;
  SSL_SESSION *pSStack_64;
  uint *puStack_60;
  code *pcStack_5c;
  undefined4 local_48;
  undefined *local_40;
  SSL_SESSION *local_34;
  SSL_SESSION *local_30;
  SSL *local_2c;
  
  puStack_6c = PTR___stack_chk_guard_006a9ae8;
  local_40 = &_gp;
  local_2c = *(SSL **)PTR___stack_chk_guard_006a9ae8;
  pSStack_74 = (SSL_SESSION *)((int)&param_2->ssl_version + 2);
  pSStack_e8 = param_3;
  pcStack_e0 = (char *)param_2;
  pSVar34 = param_2;
  if ((*(int *)((int)param_1->krb5_client_princ + 0x80) != 0x300) ||
     (local_34 = param_2, *(int *)(*(int *)(param_1->session_id + 0x10) + 0x418) != 0)) {
    pSVar35 = pSStack_74;
    pSVar24 = pSStack_74;
    if (pSStack_74 < param_3) {
      if (*(void **)((int)param_1->krb5_client_princ + 0x90) == (void *)0x0) {
LAB_00491d88:
        local_34 = pSStack_74;
        if (param_1->psk_identity_hint == (char *)0x0) {
LAB_00491d94:
          pSVar35 = local_34;
          if (param_1->verify_result != 0) {
            unaff_s5 = (SSL_SESSION *)(**(code **)(local_40 + -0x53bc))();
            if ((0xff < (int)unaff_s5) || (unaff_s5 == (SSL_SESSION *)0x0)) {
              pcVar39 = *(code **)(local_40 + -0x6eac);
              local_48 = 0x1be;
              goto LAB_00492218;
            }
            pcStack_e0 = &SUB_0000000c;
            pSVar24 = local_34;
            if ((int)((int)param_3 + ((-5 - (int)pSVar35) - (int)unaff_s5)) < 0) goto LAB_0049222c;
            *(undefined *)&pSVar35->ssl_version = 0;
            pcVar39 = *(code **)(local_40 + -0x52f4);
            *(undefined *)((int)&local_34->ssl_version + 1) = 0xc;
            param_4 = (char *)((int)&local_34->ssl_version + 2);
            *(char *)((int)&local_34->ssl_version + 2) =
                 (char)((uint)((int)&unaff_s5->ssl_version + 1) >> 8);
            *(char *)((int)&local_34->ssl_version + 3) = (char)unaff_s5 + '\x01';
            puVar10 = (undefined *)((int)&local_34->key_arg_length + 1);
            *(char *)&local_34->key_arg_length = (char)unaff_s5;
            pcStack_e0 = (char *)param_1->verify_result;
            pSStack_e8 = unaff_s5;
            local_34 = (SSL_SESSION *)puVar10;
            (*pcVar39)(puVar10);
            local_34 = (SSL_SESSION *)((int)local_34 + (int)unaff_s5);
          }
          if (*(size_t *)((int)param_1->krb5_client_princ + 0xb8) != 0) {
            puVar10 = (undefined *)((int)param_3 + (-5 - (int)local_34));
            pSVar35 = local_34;
            pSVar24 = local_34;
            if (((int)puVar10 < 0) ||
               (puVar10 < *(undefined **)((int)param_1->krb5_client_princ + 0xb4)))
            goto LAB_0049222c;
            if ((undefined *)0xff < *(undefined **)((int)param_1->krb5_client_princ + 0xb4)) {
              pcVar39 = *(code **)(local_40 + -0x6eac);
              local_48 = 0x1e0;
              goto LAB_00492218;
            }
            *(undefined *)&local_34->ssl_version = 0;
            pcVar39 = *(code **)(local_40 + -0x52f4);
            *(undefined *)((int)&local_34->ssl_version + 1) = 0xb;
            *(char *)((int)&local_34->ssl_version + 2) =
                 (char)((uint)(*(int *)((int)param_1->krb5_client_princ + 0xb4) + 1) >> 8);
            *(char *)((int)&local_34->ssl_version + 3) =
                 (char)*(int *)((int)param_1->krb5_client_princ + 0xb4) + '\x01';
            puVar10 = (undefined *)((int)&local_34->key_arg_length + 1);
            *(char *)&local_34->key_arg_length =
                 (char)*(int *)((int)param_1->krb5_client_princ + 0xb4);
            pSStack_e8 = *(SSL_SESSION **)((int)param_1->krb5_client_princ + 0xb4);
            pcStack_e0 = *(char **)((int)param_1->krb5_client_princ + 0xb8);
            local_34 = (SSL_SESSION *)puVar10;
            (*pcVar39)(puVar10);
            local_34 = (SSL_SESSION *)
                       ((int)local_34 + *(int *)((int)param_1->krb5_client_princ + 0xb4));
          }
          pSStack_74 = local_34;
          if (*(size_t *)((int)param_1->krb5_client_princ + 0xc0) != 0) {
            puVar11 = (uchar *)((int)param_3 + (-6 - (int)local_34));
            pSVar35 = local_34;
            pSVar24 = local_34;
            if (((int)puVar11 < 0) ||
               (puVar11 < *(uchar **)((int)param_1->krb5_client_princ + 0xbc))) goto LAB_0049222c;
            if ((uchar *)0xfffc < *(uchar **)((int)param_1->krb5_client_princ + 0xbc)) {
              pcVar39 = *(code **)(local_40 + -0x6eac);
              local_48 = 0x1f6;
              goto LAB_00492218;
            }
            *(undefined *)&local_34->ssl_version = 0;
            pcVar39 = *(code **)(local_40 + -0x52f4);
            *(undefined *)((int)&local_34->ssl_version + 1) = 10;
            *(char *)((int)&local_34->ssl_version + 2) =
                 (char)((uint)(*(uchar **)((int)param_1->krb5_client_princ + 0xbc) + 2) >> 8);
            *(char *)((int)&local_34->ssl_version + 3) =
                 (char)*(uchar **)((int)param_1->krb5_client_princ + 0xbc) + '\x02';
            *(char *)&local_34->key_arg_length =
                 (char)((uint)*(uchar **)((int)param_1->krb5_client_princ + 0xbc) >> 8);
            *(char *)((int)&local_34->key_arg_length + 1) =
                 (char)*(uchar **)((int)param_1->krb5_client_princ + 0xbc);
            local_34 = (SSL_SESSION *)((int)&local_34->key_arg_length + 2);
            (*pcVar39)(local_34,*(size_t *)((int)param_1->krb5_client_princ + 0xc0),
                       *(uchar **)((int)param_1->krb5_client_princ + 0xbc));
            local_34 = (SSL_SESSION *)
                       ((int)local_34 + (int)*(uchar **)((int)param_1->krb5_client_princ + 0xbc));
          }
          param_4 = (char *)0x0;
          pSVar35 = (SSL_SESSION *)0x0;
          pcStack_e0 = &DAT_00000020;
          uVar12 = SSL_ctrl((SSL *)param_1,0x20,0,(void *)0x0);
          if ((uVar12 & 0x4000) == 0) {
            unaff_s5 = *(SSL_SESSION **)((int)param_1->krb5_client_princ + 0x30);
            if (*(int *)((int)param_1->master_key + 0x14) != 0) {
              if (unaff_s5 == (SSL_SESSION *)0x0) goto LAB_00492664;
LAB_004925fc:
              puVar30 = *(ushort **)(param_1->krb5_client_princ + 0xcc);
              pSStack_74 = (SSL_SESSION *)0x0;
              pSStack_e8 = pSVar35;
              if (puVar30 == (ushort *)0x0) goto LAB_00491ff4;
              pcStack_e0 = "-check_ss_sig";
              if (*(int *)(puVar30 + 2) != 0) {
                pSStack_e8 = (SSL_SESSION *)(uint)*puVar30;
                pcStack_e0 = "t1_lib.c";
                p_Var15 = (_func_3154 *)
                          (**(code **)(local_40 + -0x7dd8))(pSStack_e8,"t1_lib.c",0x20b);
                iVar13 = *(int *)(param_1->krb5_client_princ + 0x30);
                *(_func_3154 **)((int)unaff_s5->krb5_client_princ + 0x54) = p_Var15;
                pSVar35 = pSStack_e8;
                pSVar24 = local_34;
                if (*(int *)(iVar13 + 0xe4) == 0) goto LAB_0049222c;
                pcStack_e0 = *(char **)(*(int *)(param_1->krb5_client_princ + 0xcc) + 4);
                (**(code **)(local_40 + -0x52f4))();
                *(SSL_SESSION **)(*(int *)(param_1->krb5_client_princ + 0x30) + 0xe8) = pSStack_e8;
                pSStack_74 = pSStack_e8;
                goto LAB_00491fe8;
              }
              goto LAB_00492040;
            }
            if (unaff_s5 != (SSL_SESSION *)0x0) {
              if (*(_func_3154 **)((int)unaff_s5->krb5_client_princ + 0x54) == (_func_3154 *)0x0)
              goto LAB_004925fc;
              pSStack_74 = *(SSL_SESSION **)((int)unaff_s5->krb5_client_princ + 0x58);
LAB_00491fe8:
              pSStack_e8 = pSVar35;
              if (pSStack_74 == (SSL_SESSION *)0x0) goto LAB_00492664;
LAB_00491ff4:
              pSVar35 = pSStack_74;
              pSVar24 = local_34;
              if ((int)((int)param_3 + ((-4 - (int)local_34) - (int)pSStack_74)) < 0)
              goto LAB_0049222c;
              *(undefined *)&local_34->ssl_version = 0;
              *(undefined *)((int)&local_34->ssl_version + 1) = 0x23;
              *(char *)((int)&local_34->ssl_version + 2) = (char)((uint)pSStack_74 >> 8);
              *(char *)((int)&local_34->ssl_version + 3) = (char)pSStack_74;
              local_34 = (SSL_SESSION *)&local_34->key_arg_length;
              pSVar35 = pSStack_e8;
              if (pSStack_74 != (SSL_SESSION *)0x0) {
                pcStack_e0 = *(char **)(*(int *)(param_1->krb5_client_princ + 0x30) + 0xe4);
                pSVar35 = pSStack_74;
                (**(code **)(local_40 + -0x52f4))();
                pSStack_74 = (SSL_SESSION *)((int)pSStack_74->key_arg + (int)local_34 + -8);
                local_34 = pSStack_74;
              }
              goto LAB_00492040;
            }
LAB_00492664:
            pSStack_74 = (SSL_SESSION *)0x0;
            pSStack_e8 = pSVar35;
            if ((*(int *)(param_1->krb5_client_princ + 0xcc) == 0) ||
               (*(int *)(*(int *)(param_1->krb5_client_princ + 0xcc) + 4) != 0)) goto LAB_00491ff4;
            iVar13 = *(int *)(param_1->krb5_client_princ + 0x80);
          }
          else {
LAB_00492040:
            iVar13 = *(int *)(param_1->krb5_client_princ + 0x80);
            pSStack_e8 = pSVar35;
          }
          if ((iVar13 >> 8 == 3) && (0x302 < iVar13)) {
            pSVar35 = pSStack_74;
            pSVar24 = local_34;
            if ((uint)((int)param_3 - (int)local_34) < 0x24) goto LAB_0049222c;
            *(undefined *)&local_34->ssl_version = 0;
            *(undefined *)((int)&local_34->ssl_version + 1) = 0xd;
            *(undefined *)((int)&local_34->ssl_version + 2) = 0;
            *(undefined *)((int)&local_34->ssl_version + 3) = 0x20;
            *(undefined *)&local_34->key_arg_length = 0;
            *(undefined *)((int)&local_34->key_arg_length + 1) = 0x1e;
            uVar6 = tls12_sigalgs._24_4_;
            pcStack_e0 = (char *)tls12_sigalgs._20_4_;
            pSStack_e8 = tls12_sigalgs._16_4_;
            param_4 = (char *)tls12_sigalgs._12_4_;
            uVar5 = tls12_sigalgs._8_4_;
            uVar22 = tls12_sigalgs._4_4_;
            *(undefined4 *)((int)&local_34->key_arg_length + 2) = tls12_sigalgs._0_4_;
            *(undefined4 *)((int)local_34->key_arg + 2) = uVar22;
            *(undefined4 *)((int)local_34->key_arg + 6) = uVar5;
            *(char **)((int)&local_34->master_key_length + 2) = param_4;
            *(SSL_SESSION **)((int)local_34->master_key + 2) = pSStack_e8;
            *(char **)((int)local_34->master_key + 6) = pcStack_e0;
            *(undefined4 *)((int)local_34->master_key + 10) = uVar6;
            *(undefined *)((int)local_34->master_key + 0xe) = tls12_sigalgs[28];
            *(undefined *)((int)local_34->master_key + 0xf) = tls12_sigalgs[29];
            local_34 = (SSL_SESSION *)((int)local_34->master_key + 0x10);
          }
          if ((*(int *)(param_1->krb5_client_princ + 0x98) == 1) &&
             (unaff_s5 = (SSL_SESSION *)0x0, param_1->ssl_version != 0xfeff)) {
            for (pSVar35 = (SSL_SESSION *)0x0;
                iVar13 = (**(code **)(local_40 + -0x7fb4))
                                   (*(undefined4 *)(param_1->krb5_client_princ + 0xa0)),
                (int)pSVar35 < iVar13; pSVar35 = (SSL_SESSION *)((int)&pSVar35->ssl_version + 1)) {
              uVar22 = (**(code **)(local_40 + -0x7fbc))
                                 (*(undefined4 *)(param_1->krb5_client_princ + 0xa0),pSVar35);
              pcStack_e0 = (char *)0x0;
              iVar13 = (**(code **)(local_40 + -0x6c2c))(uVar22);
              pSVar24 = local_34;
              if (iVar13 < 1) goto LAB_0049222c;
              unaff_s5 = (SSL_SESSION *)((int)unaff_s5->key_arg + iVar13 + -6);
            }
            if (*(int *)(param_1->krb5_client_princ + 0xa4) == 0) {
              unaff_s6 = (uint *)0x0;
            }
            else {
              pcStack_e0 = (char *)0x0;
              unaff_s6 = (uint *)(**(code **)(local_40 + -0x6c28))();
              pSVar24 = local_34;
              if ((int)unaff_s6 < 0) goto LAB_0049222c;
            }
            pSVar24 = local_34;
            if (-1 < (int)((int)param_3 + (((-7 - (int)local_34) - (int)unaff_s6) - (int)unaff_s5)))
            {
              *(undefined *)&local_34->ssl_version = 0;
              iVar13 = (int)unaff_s5->key_arg + (int)(unaff_s6 + -2);
              *(undefined *)((int)&local_34->ssl_version + 1) = 5;
              pcStack_e0 = (char *)((int)&local_34->ssl_version + 2);
              pSVar24 = (SSL_SESSION *)pcStack_e0;
              if (iVar13 < 0xfff1) {
                pcStack_e0 = (char *)((uint)unaff_s5 & 0xff);
                unaff_s7 = (uint)unaff_s6 & 0xff;
                *(char *)((int)&local_34->ssl_version + 2) = (char)((uint)(iVar13 + 5) >> 8);
                unaff_s8 = (SSL_SESSION *)&local_34;
                *(char *)((int)&local_34->ssl_version + 3) =
                     (char)unaff_s7 + (char)pcStack_e0 + '\x05';
                *(undefined *)&local_34->key_arg_length = 1;
                *(char *)((int)&local_34->key_arg_length + 1) = (char)((uint)unaff_s5 >> 8);
                *(char *)((int)&local_34->key_arg_length + 2) = (char)pcStack_e0;
                local_34 = (SSL_SESSION *)((int)&local_34->key_arg_length + 3);
                unaff_s5 = (SSL_SESSION *)((int)unaff_s5 >> 8);
                for (pSStack_74 = (SSL_SESSION *)0x0;
                    iVar13 = (**(code **)(local_40 + -0x7fb4))
                                       (*(undefined4 *)(param_1->krb5_client_princ + 0xa0)),
                    pSVar35 = local_34, (int)pSStack_74 < iVar13;
                    pSStack_74 = (SSL_SESSION *)((int)&pSStack_74->ssl_version + 1)) {
                  uVar22 = (**(code **)(local_40 + -0x7fbc))
                                     (*(undefined4 *)(param_1->krb5_client_princ + 0xa0),pSStack_74)
                  ;
                  local_34 = (SSL_SESSION *)((int)&local_34->ssl_version + 2);
                  pcStack_e0 = (char *)unaff_s8;
                  uVar23 = (**(code **)(local_40 + -0x6c2c))(uVar22);
                  *(char *)((int)&pSVar35->ssl_version + 1) = (char)uVar23;
                  *(char *)&pSVar35->ssl_version = (char)((ushort)uVar23 >> 8);
                  unaff_s5 = pSVar35;
                }
                *(char *)&local_34->ssl_version = (char)((uint)unaff_s6 >> 8);
                *(char *)((int)&local_34->ssl_version + 1) = (char)unaff_s7;
                local_34 = (SSL_SESSION *)((int)&local_34->ssl_version + 2);
                if (unaff_s6 != (uint *)0x0) {
                  pcStack_e0 = (char *)&local_34;
                  (**(code **)(local_40 + -0x6c28))
                            (*(undefined4 *)(param_1->krb5_client_princ + 0xa4));
                }
                goto LAB_00492068;
              }
            }
          }
          else {
LAB_00492068:
            pSVar37 = local_34;
            pSVar35 = pSStack_74;
            pSVar24 = local_34;
            if (4 < (int)param_3 - (int)local_34) {
              *(undefined *)&local_34->ssl_version = 0;
              *(undefined *)((int)&local_34->ssl_version + 1) = 0xf;
              *(undefined *)((int)&local_34->ssl_version + 2) = 0;
              *(undefined *)((int)&local_34->ssl_version + 3) = 1;
              if ((*(uint *)(param_1->krb5_client_princ + 0xf4) & 4) == 0) {
                *(undefined *)&local_34->key_arg_length = 1;
              }
              else {
                *(undefined *)&local_34->key_arg_length = 2;
              }
              local_34 = (SSL_SESSION *)((int)&local_34->key_arg_length + 1);
              if ((*(int *)(*(int *)(param_1->krb5_client_princ + 0x54) + 0x1ac) != 0) &&
                 (*(int *)(*(int *)(param_1->session_id + 0x10) + 0x2b4) == 0)) {
                pSVar24 = local_34;
                if ((int)param_3 - (int)local_34 < 4) goto LAB_0049222c;
                *(undefined *)&local_34->ssl_version = 0x33;
                *(undefined *)((int)&pSVar37->key_arg_length + 2) = 0x74;
                *(undefined *)((int)&pSVar37->key_arg_length + 3) = 0;
                pSVar37->key_arg[0] = 0;
                local_34 = (SSL_SESSION *)((int)pSVar37->key_arg + 1);
              }
              if ((**(int **)param_1->key_arg == 0xfeff) &&
                 (psVar14 = SSL_get_srtp_profiles((SSL *)param_1),
                 psVar14 != (stack_st_SRTP_PROTECTION_PROFILE *)0x0)) {
                pSStack_74 = (SSL_SESSION *)&local_30;
                param_4 = (char *)0x0;
                pcStack_e0 = (char *)0x0;
                pSStack_e8 = pSStack_74;
                ssl_add_clienthello_use_srtp_ext(param_1);
                pSVar35 = pSStack_74;
                pSVar24 = local_34;
                if ((int)((int)param_3 + ((-4 - (int)local_34) - (int)local_30)) < 0)
                goto LAB_0049222c;
                *(undefined *)&local_34->ssl_version = 0;
                *(undefined *)((int)&local_34->ssl_version + 1) = 0xe;
                *(char *)((int)&local_34->ssl_version + 2) = (char)((uint)local_30 >> 8);
                *(char *)((int)&local_34->ssl_version + 3) = (char)local_30;
                pcStack_e0 = (char *)&local_34->key_arg_length;
                pSStack_e8 = pSStack_74;
                param_4 = (char *)local_30;
                local_34 = (SSL_SESSION *)pcStack_e0;
                iVar13 = ssl_add_clienthello_use_srtp_ext(param_1);
                if (iVar13 != 0) {
                  pcVar39 = *(code **)(local_40 + -0x6eac);
                  local_48 = 0x296;
                  goto LAB_00492218;
                }
                local_34 = (SSL_SESSION *)((int)local_30->key_arg + (int)local_34->key_arg + -0x10);
              }
              iVar13 = (int)local_34 - (int)param_2;
              pSVar35 = local_34;
              if ((*(uint *)(param_1->krb5_client_princ + 0x70) & 0x10) != 0) {
                pSVar24 = (SSL_SESSION *)
                          ((int)local_34 - *(int *)(*(int *)(param_1->master_key + 0x28) + 4));
                pcStack_e0 = (char *)((int)&pSVar24[-1].tlsext_ticklen + 3);
                if (*(int *)(param_1->master_key + 0x20) == 0x1210) {
                  pSVar24 = (SSL_SESSION *)pcStack_e0;
                }
                if (pSVar24[-1].krb5_client_princ + 100 < (uchar *)0x100) {
                  param_1 = (SSL_SESSION *)0x0;
                  if (0x200 - (int)pSVar24 < 4) {
                    uVar27 = 0;
                    uVar33 = 0;
                  }
                  else {
                    param_1 = (SSL_SESSION *)(0x1fc - (int)pSVar24);
                    uVar33 = (undefined)((uint)param_1 >> 8);
                    uVar27 = SUB41(param_1,0);
                  }
                  *(undefined *)&local_34->ssl_version = 0;
                  pcStack_e0 = (char *)0x0;
                  pcVar39 = *(code **)(local_40 + -0x53ec);
                  *(undefined *)((int)&local_34->ssl_version + 1) = 0x15;
                  param_4 = (char *)((int)&local_34->ssl_version + 2);
                  *(undefined *)((int)&local_34->ssl_version + 2) = uVar33;
                  *(undefined *)((int)&local_34->ssl_version + 3) = uVar27;
                  local_34 = (SSL_SESSION *)&local_34->key_arg_length;
                  pSStack_e8 = param_1;
                  (*pcVar39)(local_34);
                  pSVar35 = (SSL_SESSION *)((int)param_1->key_arg + (int)local_34->key_arg + -0x10);
                }
                iVar13 = (int)pSVar35 - (int)param_2;
              }
              iVar13 = iVar13 + -2;
              if (iVar13 != 0) {
                *(char *)((int)&param_2->ssl_version + 1) = (char)iVar13;
                *(char *)&param_2->ssl_version = (char)((uint)iVar13 >> 8);
                pSVar34 = pSVar35;
              }
              goto LAB_00492230;
            }
          }
        }
        else {
          pSVar35 = (SSL_SESSION *)&local_30;
          param_4 = (char *)0x0;
          pcStack_e0 = (char *)0x0;
          pSStack_e8 = pSVar35;
          iVar13 = (**(code **)(local_40 + -0x6c34))(param_1);
          if (iVar13 == 0) {
            pcVar39 = *(code **)(local_40 + -0x6eac);
            local_48 = 0x1a6;
          }
          else {
            pSVar24 = local_34;
            if ((int)((int)param_3 + ((-4 - (int)local_34) - (int)local_30)) < 0) goto LAB_0049222c;
            pcVar39 = *(code **)(local_40 + -0x6c34);
            *(undefined *)&local_34->ssl_version = 0xff;
            *(undefined *)((int)&local_34->ssl_version + 1) = 1;
            *(char *)((int)&local_34->ssl_version + 2) = (char)((uint)local_30 >> 8);
            *(char *)((int)&local_34->ssl_version + 3) = (char)local_30;
            pcStack_e0 = (char *)&local_34->key_arg_length;
            pSStack_e8 = pSVar35;
            param_4 = (char *)local_30;
            local_34 = (SSL_SESSION *)pcStack_e0;
            iVar13 = (*pcVar39)(param_1);
            if (iVar13 != 0) {
              local_34 = (SSL_SESSION *)((int)local_30->key_arg + (int)local_34->key_arg + -0x10);
              goto LAB_00491d94;
            }
            pcVar39 = *(code **)(local_40 + -0x6eac);
            local_48 = 0x1b1;
          }
LAB_00492218:
          param_4 = "t1_lib.c";
          pSStack_e8 = (SSL_SESSION *)0x44;
          pcStack_e0 = (char *)0x115;
          (*pcVar39)(0x14);
          pSVar24 = local_34;
        }
      }
      else {
        pSVar37 = (SSL_SESSION *)((int)param_3 + (-9 - (int)pSStack_74));
        pSVar35 = pSVar37;
        pSVar24 = pSStack_74;
        if (-1 < (int)pSVar37) {
          local_34 = pSStack_74;
          pSVar9 = (SSL_SESSION *)(*(code *)PTR_strlen_006a9a24)();
          pSVar35 = (SSL_SESSION *)(uint)(pSVar37 < pSVar9);
          pSVar24 = local_34;
          if ((SSL_SESSION *)(uint)(pSVar37 < pSVar9) == (SSL_SESSION *)0x0) {
            cVar2 = (char)pSVar9;
            pcVar39 = *(code **)(local_40 + -0x52f4);
            *(undefined *)((int)&param_2->ssl_version + 2) = 0;
            *(char *)((int)param_2->key_arg + 2) = cVar2;
            *(undefined *)((int)&param_2->ssl_version + 3) = 0;
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
            pcStack_e0 = *(char **)((int)param_1->krb5_client_princ + 0x90);
            (*pcVar39)();
            pSStack_e8 = pSVar9;
            goto LAB_00491d88;
          }
        }
      }
    }
LAB_0049222c:
    local_34 = pSVar24;
    pSVar34 = (SSL_SESSION *)0x0;
    pSStack_74 = pSVar35;
  }
LAB_00492230:
  if (local_2c == *(SSL **)puStack_6c) {
    return pSVar34;
  }
  pcStack_5c = ssl_add_serverhello_tlsext;
  pSStack_ec = local_2c;
  (**(code **)(local_40 + -0x5330))();
  puStack_e4 = PTR___stack_chk_guard_006a9ae8;
  puStack_b0 = &_gp;
  pSStack_7c = *(SSL **)PTR___stack_chk_guard_006a9ae8;
  pSStack_f0 = (SSL_SESSION *)((int)(int *)pcStack_e0 + 2);
  pSVar34 = (SSL_SESSION *)pcStack_e0;
  pSVar35 = pSStack_e8;
  pSStack_78 = param_1;
  pSStack_70 = param_2;
  pSStack_68 = param_3;
  pSStack_64 = unaff_s5;
  puStack_60 = unaff_s6;
  if (((pSStack_ec->version != 0x300) ||
      (pSVar24 = (SSL_SESSION *)pcStack_e0, pSStack_ec->s3->send_connection_binding != 0)) &&
     (pSVar24 = (SSL_SESSION *)0x0, pSStack_f0 < pSStack_e8)) {
    pSVar37 = pSStack_f0;
    if (((pSStack_ec->hit == 0) && (pSStack_ec->tlsext_hostname == (char *)0x1)) &&
       (*(int *)(pSStack_ec->session->krb5_client_princ + 0x40) != 0)) {
      pSVar37 = (SSL_SESSION *)((int)((int)pcStack_e0 + 4) + 2);
      if (3 < (int)pSStack_e8 - (int)pSStack_f0) {
        *(undefined *)((int)(int *)pcStack_e0 + 2) = 0;
        *(undefined *)((int)(int *)pcStack_e0 + 3) = 0;
        *(undefined *)((int)pcStack_e0 + 4) = 0;
        *(undefined *)((int)((int)pcStack_e0 + 4) + 1) = 0;
        goto LAB_00492870;
      }
    }
    else {
LAB_00492870:
      pSStack_f0 = pSVar37;
      if (pSStack_ec->s3->send_connection_binding == 0) {
LAB_00492880:
        if (pSStack_ec->tlsext_ecpointformatlist_length != 0) {
          puVar10 = (undefined *)((int)pSStack_e8 + (-5 - (int)pSStack_f0));
          pSVar37 = pSStack_f0;
          if (((int)puVar10 < 0) || (puVar10 < (undefined *)pSStack_ec->tlsext_ticket_expected))
          goto LAB_00492b20;
          if ((undefined *)0xff < (undefined *)pSStack_ec->tlsext_ticket_expected) {
            pSVar35 = (SSL_SESSION *)0x44;
            param_4 = "t1_lib.c";
            puStack_b8 = (undefined4 *)0x2fe;
            pSVar34 = (SSL_SESSION *)0x116;
            (**(code **)(puStack_b0 + -0x6eac))(0x14);
            pSVar24 = (SSL_SESSION *)0x0;
            goto LAB_00492a6c;
          }
          *(undefined *)&pSStack_f0->ssl_version = 0;
          pcVar39 = *(code **)(puStack_b0 + -0x52f4);
          *(undefined *)((int)&pSStack_f0->ssl_version + 1) = 0xb;
          *(char *)((int)&pSStack_f0->ssl_version + 2) =
               (char)((uint)(pSStack_ec->tlsext_ticket_expected + 1) >> 8);
          *(char *)((int)&pSStack_f0->ssl_version + 3) =
               (char)pSStack_ec->tlsext_ticket_expected + '\x01';
          *(char *)&pSStack_f0->key_arg_length = (char)pSStack_ec->tlsext_ticket_expected;
          pSVar35 = (SSL_SESSION *)pSStack_ec->tlsext_ticket_expected;
          pSVar34 = (SSL_SESSION *)pSStack_ec->tlsext_ecpointformatlist_length;
          iVar13 = (*pcVar39)((undefined *)((int)&pSStack_f0->key_arg_length + 1));
          pSStack_f0 = (SSL_SESSION *)(iVar13 + pSStack_ec->tlsext_ticket_expected);
        }
        pSVar9 = pSStack_f0;
        if (pSStack_ec->tlsext_ocsp_resplen != 0) {
          param_4 = (char *)0x0;
          pSVar35 = (SSL_SESSION *)0x0;
          pSVar34 = (SSL_SESSION *)&DAT_00000020;
          uVar12 = SSL_ctrl(pSStack_ec,0x20,0,(void *)0x0);
          if ((uVar12 & 0x4000) == 0) {
            pSVar24 = (SSL_SESSION *)0x0;
            if ((int)pSStack_e8 - (int)pSStack_f0 < 4) goto LAB_00492a6c;
            *(undefined *)&pSStack_f0->ssl_version = 0;
            *(undefined *)((int)&pSStack_f0->ssl_version + 2) = 0;
            pSVar9 = (SSL_SESSION *)&pSStack_f0->key_arg_length;
            *(undefined *)((int)&pSStack_f0->ssl_version + 3) = 0;
            *(undefined *)((int)&pSStack_f0->ssl_version + 1) = 0x23;
          }
        }
        pSVar37 = pSVar9;
        if (pSStack_ec->tlsext_status_type != 0) {
          pSVar24 = (SSL_SESSION *)0x0;
          pSStack_f0 = pSVar9;
          if ((int)pSStack_e8 - (int)pSVar9 < 4) goto LAB_00492a6c;
          *(undefined *)&pSVar9->ssl_version = 0;
          *(undefined *)((int)&pSVar9->ssl_version + 2) = 0;
          pSVar37 = (SSL_SESSION *)&pSVar9->key_arg_length;
          *(undefined *)((int)&pSVar9->ssl_version + 3) = 0;
          *(undefined *)((int)&pSVar9->ssl_version + 1) = 5;
        }
        if ((pSStack_ec->method->version == 0xfeff) &&
           (pSStack_ec->srtp_profiles != (stack_st_SRTP_PROTECTION_PROFILE *)0x0)) {
          unaff_s5 = (SSL_SESSION *)&pSStack_a4;
          pSVar34 = (SSL_SESSION *)0x0;
          pSVar35 = unaff_s5;
          ssl_add_serverhello_use_srtp_ext(pSStack_ec,0,unaff_s5,0);
          param_4 = (char *)pSStack_a4;
          if ((int)((int)pSStack_e8 + ((-4 - (int)pSVar37) - (int)pSStack_a4)) < 0)
          goto LAB_00492b20;
          *(undefined *)&pSVar37->ssl_version = 0;
          unaff_s6 = &pSVar37->key_arg_length;
          *(char *)((int)&pSVar37->ssl_version + 3) = (char)pSStack_a4;
          *(char *)((int)&pSVar37->ssl_version + 2) = (char)((uint)pSStack_a4 >> 8);
          *(undefined *)((int)&pSVar37->ssl_version + 1) = 0xe;
          pSVar34 = (SSL_SESSION *)unaff_s6;
          pSVar35 = unaff_s5;
          iVar13 = ssl_add_serverhello_use_srtp_ext(pSStack_ec);
          if (iVar13 != 0) {
            pcVar39 = *(code **)(puStack_b0 + -0x6eac);
            puStack_b8 = (undefined4 *)0x33b;
            goto LAB_00492b0c;
          }
          pSVar37 = (SSL_SESSION *)((int)pSStack_a4->key_arg + (int)(unaff_s6 + -2));
        }
        if (*(ushort *)((int)&((pSStack_ec->s3->tmp).new_cipher)->id + 2) - 0x80 < 2) {
          param_4 = (char *)0x0;
          pSVar35 = (SSL_SESSION *)0x0;
          pSVar34 = (SSL_SESSION *)&DAT_00000020;
          lVar16 = SSL_ctrl(pSStack_ec,0x20,0,(void *)0x0);
          if (lVar16 < 0) {
            ppSVar17 = (SSL_SESSION **)&DAT_00647480;
            ppSVar25 = apSStack_a0;
            do {
              pSVar24 = *ppSVar17;
              ppSVar28 = ppSVar25 + 4;
              param_4 = (char *)ppSVar17[1];
              pSVar35 = ppSVar17[2];
              pSVar34 = ppSVar17[3];
              ppSVar17 = ppSVar17 + 4;
              *ppSVar25 = pSVar24;
              ppSVar25[1] = (SSL_SESSION *)param_4;
              ppSVar25[2] = pSVar35;
              ppSVar25[3] = pSVar34;
              ppSVar25 = ppSVar28;
            } while (ppSVar17 != (SSL_SESSION **)&UNK_006474a0);
            pSVar34 = (SSL_SESSION *)(uint)((int)pSStack_e8 - (int)pSVar37 < 0x24);
            *ppSVar28 = _UNK_006474a0;
            pSVar35 = _UNK_006474a0;
            if (pSVar34 != (SSL_SESSION *)0x0) goto LAB_00492b20;
            pSVar24 = pSVar37;
            ppSVar25 = apSStack_a0;
            do {
              param_4 = (char *)*ppSVar25;
              ppSVar17 = ppSVar25 + 4;
              pSVar35 = ppSVar25[1];
              pSVar34 = ppSVar25[2];
              pSVar9 = ppSVar25[3];
              pSVar24->ssl_version = (int)param_4;
              pSVar24->key_arg_length = (uint)pSVar35;
              *(SSL_SESSION **)pSVar24->key_arg = pSVar34;
              *(SSL_SESSION **)((int)pSVar24->key_arg + 4) = pSVar9;
              pSVar24 = (SSL_SESSION *)&pSVar24->master_key_length;
              ppSVar25 = ppSVar17;
            } while (ppSVar17 != &pSStack_80);
            pSVar37 = (SSL_SESSION *)((int)pSVar37->master_key + 0x10);
            *(SSL_SESSION **)pSVar24 = *ppSVar17;
          }
        }
        pSStack_f0 = pSVar37;
        if (((uint)pSStack_ec->srtp_profile & 1) == 0) {
LAB_004929b4:
          iVar13 = pSStack_ec->s3->next_proto_neg_seen;
          pSStack_ec->s3->next_proto_neg_seen = 0;
          if (iVar13 != 0) {
            p_Var15 = pSStack_ec->psk_server_callback;
LAB_004929c8:
            pSVar35 = (SSL_SESSION *)&pSStack_a4;
            if (*(code **)(p_Var15 + 0x1a4) != (code *)0x0) {
              param_4 = *(char **)(p_Var15 + 0x1a8);
              pSVar34 = (SSL_SESSION *)&pSStack_a8;
              iVar13 = (**(code **)(p_Var15 + 0x1a4))(pSStack_ec);
              if (iVar13 == 0) {
                pSStack_e8 = (SSL_SESSION *)
                             ((int)pSStack_e8 + ((-4 - (int)pSStack_a4) - (int)pSStack_f0));
                pSVar37 = pSStack_f0;
                unaff_s5 = pSStack_a4;
                if ((int)pSStack_e8 < 0) goto LAB_00492b20;
                pcVar39 = *(code **)(puStack_b0 + -0x52f4);
                *(char *)((int)&pSStack_f0->ssl_version + 3) = (char)pSStack_a4;
                *(undefined *)&pSStack_f0->ssl_version = 0x33;
                *(char *)((int)&pSStack_f0->ssl_version + 2) = (char)((uint)pSStack_a4 >> 8);
                *(undefined *)((int)&pSStack_f0->ssl_version + 1) = 0x74;
                pSVar35 = pSStack_a4;
                iVar13 = (*pcVar39)(&pSStack_f0->key_arg_length);
                pSStack_f0 = (SSL_SESSION *)((int)pSStack_a4->key_arg + iVar13 + -8);
                pSStack_ec->s3->next_proto_neg_seen = 1;
                pSVar34 = pSStack_a8;
              }
            }
          }
        }
        else {
          if ((int)pSStack_e8 - (int)pSVar37 < 5) goto LAB_00492b20;
          *(undefined *)&pSVar37->ssl_version = 0;
          *(undefined *)((int)&pSVar37->ssl_version + 2) = 0;
          *(undefined *)((int)&pSVar37->ssl_version + 1) = 0xf;
          *(undefined *)((int)&pSVar37->ssl_version + 3) = 1;
          if (((uint)pSStack_ec->srtp_profile & 4) != 0) {
            pSStack_f0 = (SSL_SESSION *)((int)&pSVar37->key_arg_length + 1);
            *(undefined *)&pSVar37->key_arg_length = 2;
            goto LAB_004929b4;
          }
          *(undefined *)&pSVar37->key_arg_length = 1;
          pSStack_f0 = (SSL_SESSION *)((int)&pSVar37->key_arg_length + 1);
          iVar13 = pSStack_ec->s3->next_proto_neg_seen;
          pSStack_ec->s3->next_proto_neg_seen = 0;
          if (iVar13 != 0) {
            p_Var15 = pSStack_ec->psk_server_callback;
            goto LAB_004929c8;
          }
        }
        puVar10 = (undefined *)((int)pSStack_f0 + (-2 - (int)pcStack_e0));
        pSVar24 = (SSL_SESSION *)pcStack_e0;
        if (puVar10 != (undefined *)0x0) {
          *(char *)((int)(int *)pcStack_e0 + 1) = (char)puVar10;
          *(char *)(int *)pcStack_e0 = (char)((uint)puVar10 >> 8);
          pSVar24 = pSStack_f0;
        }
        goto LAB_00492a6c;
      }
      pSVar34 = (SSL_SESSION *)0x0;
      pSVar35 = (SSL_SESSION *)&pSStack_a4;
      iVar13 = (*(code *)PTR_ssl_add_serverhello_renegotiate_ext_006a81c0)
                         (pSStack_ec,0,(SSL_SESSION *)&pSStack_a4,0);
      if (iVar13 == 0) {
        pcVar39 = *(code **)(puStack_b0 + -0x6eac);
        puStack_b8 = (undefined4 *)0x2e1;
      }
      else {
        param_4 = (char *)pSStack_a4;
        unaff_s5 = (SSL_SESSION *)&pSStack_a4;
        if ((int)((int)pSStack_e8 + ((-4 - (int)pSVar37) - (int)pSStack_a4)) < 0) goto LAB_00492b20;
        pcVar39 = *(code **)(puStack_b0 + -0x6c20);
        *(char *)((int)&pSVar37->ssl_version + 3) = (char)pSStack_a4;
        unaff_s6 = &pSVar37->key_arg_length;
        *(undefined *)&pSVar37->ssl_version = 0xff;
        *(char *)((int)&pSVar37->ssl_version + 2) = (char)((uint)pSStack_a4 >> 8);
        *(undefined *)((int)&pSVar37->ssl_version + 1) = 1;
        pSVar34 = (SSL_SESSION *)unaff_s6;
        pSVar35 = (SSL_SESSION *)&pSStack_a4;
        iVar13 = (*pcVar39)(pSStack_ec);
        if (iVar13 != 0) {
          pSStack_f0 = (SSL_SESSION *)((int)pSStack_a4->key_arg + (int)(unaff_s6 + -2));
          goto LAB_00492880;
        }
        pcVar39 = *(code **)(puStack_b0 + -0x6eac);
        puStack_b8 = (undefined4 *)0x2ec;
      }
LAB_00492b0c:
      param_4 = "t1_lib.c";
      pSVar35 = (SSL_SESSION *)0x44;
      pSVar34 = (SSL_SESSION *)0x116;
      (*pcVar39)(0x14);
      unaff_s5 = (SSL_SESSION *)&pSStack_a4;
    }
LAB_00492b20:
    pSVar24 = (SSL_SESSION *)0x0;
    pSStack_f0 = pSVar37;
  }
LAB_00492a6c:
  if (pSStack_7c == *(SSL **)puStack_e4) {
    return pSVar24;
  }
  pcStack_cc = ssl_parse_serverhello_tlsext;
  pSVar29 = pSStack_7c;
  (**(code **)(puStack_b0 + -0x5330))();
  puVar8 = puStack_b8;
  puVar10 = PTR___stack_chk_guard_006a9ae8;
  puVar40 = (ushort *)((int)((int)param_4 + 8) + (int)pSVar35->key_arg + -0x10);
  puVar30 = (ushort *)pSVar34->ssl_version;
  pSVar26 = pSVar29->srtp_profile;
  pSStack_f4 = *(SSL **)PTR___stack_chk_guard_006a9ae8;
  pSVar29->s3->next_proto_neg_seen = 0;
  pSVar29->tlsext_ocsp_resplen = 0;
  pSVar29->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)pSVar26 & 0xfffffffc);
  pSStack_dc = unaff_s5;
  puStack_d8 = unaff_s6;
  uStack_d4 = unaff_s7;
  pSStack_d0 = unaff_s8;
  if (2 < (int)puVar40 - (int)puVar30) {
    puVar36 = puVar30 + 1;
    if ((int)puVar40 - (int)puVar36 != (uint)*puVar30) {
LAB_00492ea0:
      pSVar35 = (SSL_SESSION *)0x0;
      *puVar8 = 0x32;
      goto LAB_00492ea8;
    }
    puVar38 = puVar30 + 3;
    if ((int)puVar40 - (int)puVar36 < 4) {
      bVar3 = false;
      bVar4 = false;
LAB_00493320:
      if (puVar40 != puVar36) goto LAB_00492ea0;
      if (((pSVar29->hit == 0) && (bVar4)) && (pSVar29->tlsext_debug_arg != (void *)0x0)) {
        pSVar35 = pSVar29->session;
        if (*(int *)(pSVar35->krb5_client_princ + 0x40) != 0) goto LAB_00492ea0;
        uVar22 = (*(code *)PTR_BUF_strdup_006a6fdc)();
        pSVar24 = pSVar29->session;
        *(undefined4 *)(pSVar35->krb5_client_princ + 0x40) = uVar22;
        if (*(int *)(pSVar24->krb5_client_princ + 0x40) == 0) {
LAB_0049338c:
          pSVar35 = (SSL_SESSION *)0x0;
          *puVar8 = 0x70;
          goto LAB_00492ea8;
        }
      }
      pSVar34->ssl_version = (int)puVar40;
    }
    else {
      uVar1 = puVar30[1];
      uVar12 = (uint)puVar30[2];
      if ((int)puVar40 - (int)puVar38 < (int)uVar12) goto LAB_00492e5c;
      bVar3 = false;
      bVar4 = false;
      do {
        if ((code *)pSVar29->max_send_fragment != (code *)0x0) {
          (*(code *)pSVar29->max_send_fragment)
                    (pSVar29,1,uVar1,puVar38,uVar12,pSVar29->tlsext_debug_cb);
        }
        if (uVar1 == 0) {
          if ((pSVar29->tlsext_debug_arg == (void *)0x0) || (uVar12 != 0)) goto LAB_0049338c;
          uVar12 = 0;
          bVar4 = true;
        }
        else if (uVar1 == 0xb) {
          uVar18 = (uint)*(byte *)(puVar36 + 2);
          if ((uVar18 != uVar12 - 1) || (uVar18 == 0)) goto LAB_00492ea0;
          if (pSVar29->hit == 0) {
            pSVar35 = pSVar29->session;
            *(undefined4 *)(pSVar35->krb5_client_princ + 0x44) = 0;
            if (*(int *)(pSVar35->krb5_client_princ + 0x48) != 0) {
              (*(code *)PTR_CRYPTO_free_006a6e88)();
              pSVar35 = pSVar29->session;
            }
            iVar13 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar18,"t1_lib.c",0x5ea);
            *(int *)(pSVar35->krb5_client_princ + 0x48) = iVar13;
            puVar7 = PTR_memcpy_006a9aec;
            if (iVar13 == 0) goto LAB_004933c4;
            pSVar35 = pSVar29->session;
            *(uint *)(pSVar35->krb5_client_princ + 0x44) = uVar18;
            (*(code *)puVar7)(*(undefined4 *)(pSVar35->krb5_client_princ + 0x48),
                              (byte *)((int)puVar36 + 5),uVar18);
          }
        }
        else if (uVar1 == 0x23) {
          if ((pSVar29->tlsext_session_ticket != (TLS_SESSION_TICKET_EXT *)0x0) &&
             (iVar13 = (*(code *)pSVar29->tlsext_session_ticket)
                                 (pSVar29,puVar38,uVar12,pSVar29->tls_session_ticket_ext_cb),
             iVar13 == 0)) {
LAB_004933c4:
            pSVar35 = (SSL_SESSION *)0x0;
            *puVar8 = 0x50;
            goto LAB_00492ea8;
          }
          uVar18 = SSL_ctrl(pSVar29,0x20,0,(void *)0x0);
          if (((uVar18 & 0x4000) != 0) || (uVar12 != 0)) {
LAB_004933b4:
            pSVar35 = (SSL_SESSION *)0x0;
            *puVar8 = 0x6e;
            goto LAB_00492ea8;
          }
          uVar12 = 0;
          pSVar29->tlsext_ocsp_resplen = 1;
        }
        else if (uVar1 == 5) {
          if (pSVar29->version != 0xfeff) {
            if ((pSVar29->servername_done == -1) || (uVar12 != 0)) goto LAB_004933b4;
            uVar12 = 0;
            pSVar29->tlsext_status_type = 1;
          }
        }
        else if (uVar1 == 0x3374) {
          pSVar35 = (SSL_SESSION *)(pSVar29->s3->tmp).finish_md_len;
          if (pSVar35 == (SSL_SESSION *)0x0) {
            pcVar39 = *(code **)(pSVar29->psk_server_callback + 0x1ac);
            if (pcVar39 == (code *)0x0) {
              *puVar8 = 0x6e;
            }
            else if (uVar12 == 0) {
LAB_00493220:
              iVar13 = (*pcVar39)(pSVar29,&uStack_f8,&uStack_f9,puVar38,uVar12,
                                  *(undefined4 *)(pSVar29->psk_server_callback + 0x1b0));
              if (iVar13 == 0) {
                pSVar19 = (SSL_CTX *)
                          (*(code *)PTR_CRYPTO_malloc_006a7008)(uStack_f9,"t1_lib.c",0x653);
                pSVar29->initial_ctx = pSVar19;
                if (pSVar19 != (SSL_CTX *)0x0) {
                  (*(code *)PTR_memcpy_006a9aec)(pSVar19,uStack_f8,uStack_f9);
                  *(undefined *)&pSVar29->next_proto_negotiated = uStack_f9;
                  pSVar29->s3->next_proto_neg_seen = 1;
                  goto LAB_00492fc4;
                }
              }
              *puVar8 = 0x50;
            }
            else {
              uVar18 = (uint)*(byte *)puVar38;
              uVar31 = 0;
              if (uVar18 != 0) {
                while( true ) {
                  uVar31 = uVar31 + uVar18 + 1;
                  if (uVar12 <= uVar31) break;
                  uVar18 = (uint)*(byte *)((int)puVar38 + uVar31);
                  if (uVar18 == 0) goto LAB_004931e4;
                }
                if (uVar12 == uVar31) goto LAB_00493220;
              }
LAB_004931e4:
              *puVar8 = 0x32;
            }
            goto LAB_00492ea8;
          }
        }
        else if (uVar1 == 0xff01) {
          iVar13 = (*(code *)PTR_ssl_parse_serverhello_renegotiate_ext_006a81cc)
                             (pSVar29,puVar38,uVar12,puVar8);
          if (iVar13 == 0) {
LAB_004932d0:
            pSVar35 = (SSL_SESSION *)0x0;
            goto LAB_00492ea8;
          }
          bVar3 = true;
        }
        else if (uVar1 == 0xf) {
          if (*(byte *)(puVar36 + 2) == 1) {
            pSVar29->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)pSVar29->srtp_profile | 1);
          }
          else {
            if (*(byte *)(puVar36 + 2) != 2) {
              pSVar35 = (SSL_SESSION *)0x0;
              *puVar8 = 0x2f;
              goto LAB_00492ea8;
            }
            pSVar29->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)pSVar29->srtp_profile | 3);
          }
        }
        else if (((pSVar29->method->version == 0xfeff) && (uVar1 == 0xe)) &&
                (iVar13 = ssl_parse_serverhello_use_srtp_ext(pSVar29,puVar38,uVar12,puVar8),
                iVar13 != 0)) goto LAB_004932d0;
LAB_00492fc4:
        puVar36 = (ushort *)((int)puVar38 + uVar12);
        puVar38 = puVar36 + 2;
        if ((int)puVar40 - (int)puVar36 < 4) goto LAB_00493320;
        uVar1 = *puVar36;
        uVar12 = (uint)puVar36[1];
      } while ((int)uVar12 <= (int)puVar40 - (int)puVar38);
    }
    pSVar35 = (SSL_SESSION *)0x1;
    if (bVar3) goto LAB_00492ea8;
  }
LAB_00492e5c:
  puVar7 = PTR_ERR_put_error_006a7f34;
  if ((pSVar29->references & 0x40004U) == 0) {
    *puVar8 = 0x28;
    (*(code *)puVar7)(0x14,0x12f,0x152,"t1_lib.c",0x6a0);
    pSVar35 = (SSL_SESSION *)0x0;
  }
  else {
    pSVar35 = (SSL_SESSION *)0x1;
  }
LAB_00492ea8:
  if (pSStack_f4 == *(SSL **)puVar10) {
    return pSVar35;
  }
  pSVar29 = pSStack_f4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  psVar20 = SSL_get_ciphers(pSVar29);
  iVar13 = 0;
  do {
    iVar21 = (*(code *)PTR_sk_num_006a6e2c)(psVar20);
    if (iVar21 <= iVar13) {
      return (SSL_SESSION *)0x1;
    }
    iVar21 = (*(code *)PTR_sk_value_006a6e24)(psVar20,iVar13);
  } while (((*(uint *)(iVar21 + 0xc) & 0xe0) == 0) &&
          (iVar13 = iVar13 + 1, (*(uint *)(iVar21 + 0x10) & 0x40) == 0));
  pSVar34 = (SSL_SESSION *)0x1;
  if (0x300 < pSVar29->version) {
    if (pSVar29->tlsext_ecpointformatlist_length != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    puVar10 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(3,"t1_lib.c",0x6c3);
    pSVar29->tlsext_ecpointformatlist_length = (size_t)puVar10;
    if (puVar10 == (undefined *)0x0) {
      uVar22 = 0x6c5;
      pcVar39 = (code *)PTR_ERR_put_error_006a7f34;
    }
    else {
      pSVar29->tlsext_ticket_expected = 3;
      *puVar10 = 0;
      *(undefined *)(pSVar29->tlsext_ecpointformatlist_length + 1) = 1;
      *(undefined *)(pSVar29->tlsext_ecpointformatlist_length + 2) = 2;
      if (pSVar29->tlsext_ellipticcurvelist_length != 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      puVar10 = PTR_CRYPTO_malloc_006a7008;
      pSVar29->tlsext_ecpointformatlist = &DAT_00000032;
      puVar10 = (undefined *)(*(code *)puVar10)(0x32,"t1_lib.c",0x6d5);
      pSVar29->tlsext_ellipticcurvelist_length = (size_t)puVar10;
      pcVar39 = (code *)PTR_ERR_put_error_006a7f34;
      if (puVar10 != (undefined *)0x0) {
        puVar32 = pref_list;
        do {
          iVar13 = *(int *)puVar32;
          uVar33 = 2;
          if (iVar13 != 0x2d2) {
            if (iVar13 < 0x2d3) {
              uVar33 = 0x12;
              if (iVar13 != 0x2c7) {
                if (iVar13 < 0x2c8) {
                  uVar33 = 0xf;
                  if (iVar13 != 0x2c4) {
                    if (iVar13 < 0x2c5) {
                      if (iVar13 == 0x199) {
                        uVar33 = 0x13;
                      }
                      else {
                        uVar33 = 0x17;
                        if (iVar13 != 0x19f) {
                          uVar33 = 0;
                        }
                      }
                    }
                    else if (iVar13 == 0x2c5) {
                      uVar33 = 0x10;
                    }
                    else {
                      uVar33 = 0x11;
                      if (iVar13 != 0x2c6) {
                        uVar33 = 0;
                      }
                    }
                  }
                }
                else {
                  uVar33 = 0x16;
                  if (iVar13 != 0x2ca) {
                    if (iVar13 < 0x2cb) {
                      if (iVar13 == 0x2c8) {
                        uVar33 = 0x14;
                      }
                      else {
                        uVar33 = 0x15;
                        if (iVar13 != 0x2c9) {
                          uVar33 = 0;
                        }
                      }
                    }
                    else {
                      uVar33 = 0x19;
                      if (iVar13 != 0x2cc) {
                        if (iVar13 < 0x2cc) {
                          uVar33 = 0x18;
                        }
                        else {
                          uVar33 = 1;
                          if (iVar13 != 0x2d1) goto LAB_0049369c;
                        }
                      }
                    }
                  }
                }
              }
            }
            else {
              uVar33 = 8;
              if (iVar13 != 0x2d8) {
                if (iVar13 < 0x2d9) {
                  uVar33 = 5;
                  if (iVar13 != 0x2d5) {
                    if (iVar13 < 0x2d6) {
                      if (iVar13 == 0x2d3) {
                        uVar33 = 3;
                      }
                      else {
                        uVar33 = 4;
                        if (iVar13 != 0x2d4) {
                          uVar33 = 0;
                        }
                      }
                    }
                    else if (iVar13 == 0x2d6) {
                      uVar33 = 6;
                    }
                    else {
                      uVar33 = 7;
                      if (iVar13 != 0x2d7) {
                        uVar33 = 0;
                      }
                    }
                  }
                }
                else {
                  uVar33 = 0xb;
                  if (iVar13 != 0x2db) {
                    if (iVar13 < 0x2dc) {
                      if (iVar13 == 0x2d9) {
                        uVar33 = 9;
                      }
                      else {
                        uVar33 = 10;
                        if (iVar13 != 0x2da) {
                          uVar33 = 0;
                        }
                      }
                    }
                    else {
                      uVar33 = 0xd;
                      if (iVar13 != 0x2dd) {
                        if (iVar13 < 0x2dd) {
                          uVar33 = 0xc;
                        }
                        else {
                          uVar33 = 0xe;
                          if (iVar13 != 0x2de) {
LAB_0049369c:
                            uVar33 = 0;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          puVar32 = (undefined1 *)((int)puVar32 + 4);
          *puVar10 = 0;
          puVar10[1] = uVar33;
          puVar10 = puVar10 + 2;
          if (puVar32 == nid_list) {
            return (SSL_SESSION *)0x1;
          }
        } while( true );
      }
      pSVar29->tlsext_ecpointformatlist = (uchar *)0x0;
      uVar22 = 0x6d8;
    }
    (*pcVar39)(0x14,0x119,0x41,"t1_lib.c",uVar22);
    pSVar34 = (SSL_SESSION *)0xffffffff;
  }
  return pSVar34;
}

