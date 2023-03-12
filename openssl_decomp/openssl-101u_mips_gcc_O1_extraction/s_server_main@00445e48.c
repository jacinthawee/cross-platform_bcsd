
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int s_server_main(int param_1,undefined4 *param_2)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined *puVar11;
  undefined *puVar12;
  uint uVar13;
  int iVar14;
  int *piVar15;
  int iVar16;
  undefined4 uVar17;
  byte *pbVar18;
  char *pcVar19;
  code *pcVar20;
  byte *pbVar21;
  int iVar22;
  undefined4 uVar23;
  undefined4 *puVar24;
  int iVar25;
  int iVar26;
  int unaff_s5;
  int iVar27;
  char *unaff_s8;
  int local_res0 [4];
  undefined4 local_fc;
  undefined4 local_c8;
  uint local_c4;
  int local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  int local_88;
  int local_84;
  int local_80;
  undefined4 local_7c;
  undefined4 local_6c;
  undefined4 *local_5c [2];
  short local_54;
  ushort local_52;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  uint local_3c;
  int local_38;
  int local_34;
  undefined4 local_30;
  int local_2c;
  
  puVar12 = PTR___stack_chk_guard_006a9ae8;
  puVar10 = PTR_bio_err_006a6e3c;
  local_54 = 0x1151;
  local_30 = 1;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_38 = 0;
  local_34 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_res0[0] = param_1;
  local_5c[0] = param_2;
  local_fc = (*(code *)PTR_SSLv23_server_method_006a788c)();
  local_argc = local_res0[0];
  local_argv = local_5c[0];
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  iVar16 = *(int *)puVar10;
  s_server_verify = 0;
  cipher = 0;
  accept_socket = 0xffffffff;
  s_dcert_file = 0;
  s_dkey_file = 0;
  s_cert_file = s_server_pem_0063b5ec;
  s_key_file2 = (undefined *)0x0;
  s_cert_file2 = s_server2_pem_0063b5f8;
  ctx2 = 0;
  s_nbio = 0;
  s_nbio_test = 0;
  ctx = 0;
  www = 0;
  s_key_file = (undefined *)0x0;
  bio_s_out = 0;
  s_debug = 0;
  s_msg = 0;
  s_quiet = 0;
  hack = 0;
  engine_id = 0;
  if (iVar16 == 0) {
    iVar16 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stderr_006a9af8,0);
    *(int *)puVar10 = iVar16;
  }
  iVar16 = load_config(iVar16,0);
  puVar11 = PTR_verify_depth_006a7894;
  if (iVar16 != 0) {
    local_88 = 0;
    local_6c = 0;
    local_res0[0] = local_res0[0] + -1;
    local_a8 = 0;
    unaff_s8 = "-verify";
    s_nbio_test = 0;
    *(undefined4 *)PTR_verify_depth_006a7894 = 0;
    s_nbio = 0;
    bVar5 = false;
    local_b4 = 0;
    local_5c[0] = local_5c[0] + 1;
    local_b8 = 0;
    local_ac = 0;
    bVar4 = false;
    bVar7 = false;
    bVar2 = false;
    local_9c = 3;
    local_a0 = 3;
    local_7c = 3;
    local_b0 = 3;
    bVar6 = false;
    bVar8 = false;
    local_bc = 2;
    local_c4 = 0;
    bVar3 = false;
    local_80 = 0;
    local_84 = 0;
    local_c8 = 0;
    local_a4 = 0;
    local_98 = 0;
LAB_00446308:
    if (0 < local_res0[0]) {
LAB_00446310:
      puVar24 = local_5c[0];
      unaff_s5 = local_res0[0];
      uVar23 = *local_5c[0];
      iVar16 = (*(code *)PTR_strcmp_006a9b18)(uVar23,"-port");
      if ((iVar16 == 0) || (iVar16 = (*(code *)PTR_strcmp_006a9b18)(uVar23,"-accept"), iVar16 == 0))
      {
        unaff_s5 = unaff_s5 + -1;
        local_res0[0] = unaff_s5;
        if (unaff_s5 != 0) {
          local_5c[0] = puVar24 + 1;
          iVar25 = extract_port(puVar24[1],&local_54);
          puVar24 = local_5c[0];
          iVar16 = local_res0[0];
          if (iVar25 != 0) goto LAB_004463c0;
        }
        goto LAB_00446af8;
      }
      iVar16 = (*(code *)PTR_strcmp_006a9b18)(uVar23,"-verify");
      if (iVar16 == 0) {
        unaff_s5 = unaff_s5 + -1;
        s_server_verify = 5;
        local_res0[0] = unaff_s5;
        if (unaff_s5 == 0) goto LAB_00446af8;
        local_5c[0] = puVar24 + 1;
        uVar23 = (*(code *)PTR_strtol_006a9958)(puVar24[1],0,10);
        uVar17 = *(undefined4 *)puVar10;
        pcVar19 = "verify depth is %d\n";
LAB_004463a4:
        puVar9 = PTR_BIO_printf_006a6e38;
        *(undefined4 *)puVar11 = uVar23;
        (*(code *)puVar9)(uVar17,pcVar19,uVar23);
        puVar24 = local_5c[0];
        iVar16 = local_res0[0];
      }
      else {
        iVar16 = (*(code *)PTR_strcmp_006a9b18)(uVar23,"-Verify");
        if (iVar16 == 0) {
          unaff_s5 = unaff_s5 + -1;
          s_server_verify = 7;
          local_res0[0] = unaff_s5;
          if (unaff_s5 != 0) {
            local_5c[0] = puVar24 + 1;
            uVar23 = (*(code *)PTR_strtol_006a9958)(puVar24[1],0,10);
            uVar17 = *(undefined4 *)puVar10;
            pcVar19 = "verify depth is %d, must return a certificate\n";
            goto LAB_004463a4;
          }
          goto LAB_00446af8;
        }
        iVar16 = (*(code *)PTR_strcmp_006a9b18)(uVar23,"-context");
        if (iVar16 == 0) {
          unaff_s5 = unaff_s5 + -1;
          local_res0[0] = unaff_s5;
          if (unaff_s5 == 0) goto LAB_00446af8;
          local_c8 = puVar24[1];
          puVar24 = puVar24 + 1;
          iVar16 = unaff_s5;
        }
        else {
          iVar16 = (*(code *)PTR_strcmp_006a9b18)(uVar23,"-cert");
          if (iVar16 == 0) {
            unaff_s5 = unaff_s5 + -1;
            local_res0[0] = unaff_s5;
            if (unaff_s5 == 0) goto LAB_00446af8;
            s_cert_file = (undefined *)puVar24[1];
            puVar24 = puVar24 + 1;
            iVar16 = unaff_s5;
          }
          else {
            iVar16 = (*(code *)PTR_strcmp_006a9b18)(uVar23,"-certform");
            if (iVar16 == 0) {
              unaff_s5 = unaff_s5 + -1;
              local_res0[0] = unaff_s5;
              if (unaff_s5 == 0) goto LAB_00446af8;
              local_5c[0] = puVar24 + 1;
              local_b0 = str2fmt(puVar24[1]);
              puVar24 = local_5c[0];
              iVar16 = local_res0[0];
            }
            else {
              iVar16 = (*(code *)PTR_strcmp_006a9b18)(uVar23,&DAT_006326ec);
              if (iVar16 == 0) {
                unaff_s5 = unaff_s5 + -1;
                local_res0[0] = unaff_s5;
                if (unaff_s5 == 0) goto LAB_00446af8;
                s_key_file = (undefined *)puVar24[1];
                puVar24 = puVar24 + 1;
                iVar16 = unaff_s5;
              }
              else {
                iVar16 = (*(code *)PTR_strcmp_006a9b18)(uVar23,"-keyform");
                if (iVar16 == 0) {
                  unaff_s5 = unaff_s5 + -1;
                  local_res0[0] = unaff_s5;
                  if (unaff_s5 == 0) goto LAB_00446af8;
                  local_5c[0] = puVar24 + 1;
                  local_7c = str2fmt(puVar24[1]);
                  puVar24 = local_5c[0];
                  iVar16 = local_res0[0];
                }
                else {
                  iVar16 = (*(code *)PTR_strcmp_006a9b18)(uVar23,"-pass");
                  if (iVar16 == 0) {
                    unaff_s5 = unaff_s5 + -1;
                    local_res0[0] = unaff_s5;
                    if (unaff_s5 == 0) goto LAB_00446af8;
                    local_b8 = puVar24[1];
                    puVar24 = puVar24 + 1;
                    iVar16 = unaff_s5;
                  }
                  else {
                    iVar16 = (*(code *)PTR_strcmp_006a9b18)(uVar23,"-dhparam");
                    if (iVar16 == 0) {
                      unaff_s5 = unaff_s5 + -1;
                      local_res0[0] = unaff_s5;
                      if (unaff_s5 == 0) goto LAB_00446af8;
                      local_84 = puVar24[1];
                      puVar24 = puVar24 + 1;
                      iVar16 = unaff_s5;
                    }
                    else {
                      iVar16 = (*(code *)PTR_strcmp_006a9b18)(uVar23,"-named_curve");
                      if (iVar16 == 0) {
                        unaff_s5 = unaff_s5 + -1;
                        local_res0[0] = unaff_s5;
                        if (unaff_s5 == 0) goto LAB_00446af8;
                        local_80 = puVar24[1];
                        puVar24 = puVar24 + 1;
                        iVar16 = unaff_s5;
                      }
                      else {
                        iVar16 = (*(code *)PTR_strcmp_006a9b18)(uVar23,"-dcertform");
                        if (iVar16 == 0) {
                          unaff_s5 = unaff_s5 + -1;
                          local_res0[0] = unaff_s5;
                          if (unaff_s5 == 0) goto LAB_00446af8;
                          local_5c[0] = puVar24 + 1;
                          local_a0 = str2fmt(puVar24[1]);
                          puVar24 = local_5c[0];
                          iVar16 = local_res0[0];
                        }
                        else {
                          iVar16 = (*(code *)PTR_strcmp_006a9b18)(uVar23,"-dcert");
                          if (iVar16 == 0) {
                            unaff_s5 = unaff_s5 + -1;
                            local_res0[0] = unaff_s5;
                            if (unaff_s5 == 0) goto LAB_00446af8;
                            s_dcert_file = puVar24[1];
                            puVar24 = puVar24 + 1;
                            iVar16 = unaff_s5;
                          }
                          else {
                            iVar16 = (*(code *)PTR_strcmp_006a9b18)(uVar23,"-dkeyform");
                            if (iVar16 == 0) {
                              unaff_s5 = unaff_s5 + -1;
                              local_res0[0] = unaff_s5;
                              if (unaff_s5 == 0) goto LAB_00446af8;
                              local_5c[0] = puVar24 + 1;
                              local_9c = str2fmt(puVar24[1]);
                              puVar24 = local_5c[0];
                              iVar16 = local_res0[0];
                            }
                            else {
                              iVar16 = (*(code *)PTR_strcmp_006a9b18)(uVar23,"-dpass");
                              if (iVar16 == 0) {
                                unaff_s5 = unaff_s5 + -1;
                                local_res0[0] = unaff_s5;
                                if (unaff_s5 == 0) goto LAB_00446af8;
                                local_b4 = puVar24[1];
                                puVar24 = puVar24 + 1;
                                iVar16 = unaff_s5;
                              }
                              else {
                                iVar16 = (*(code *)PTR_strcmp_006a9b18)(uVar23,"-dkey");
                                if (iVar16 == 0) {
                                  unaff_s5 = unaff_s5 + -1;
                                  local_res0[0] = unaff_s5;
                                  if (unaff_s5 == 0) goto LAB_00446af8;
                                  s_dkey_file = puVar24[1];
                                  puVar24 = puVar24 + 1;
                                  iVar16 = unaff_s5;
                                }
                                else {
                                  iVar25 = (*(code *)PTR_strcmp_006a9b18)(uVar23,"-nocert");
                                  iVar16 = unaff_s5;
                                  if (iVar25 == 0) {
                                    bVar2 = true;
                                  }
                                  else {
                                    iVar25 = (*(code *)PTR_strcmp_006a9b18)(uVar23,"-CApath");
                                    if (iVar25 == 0) {
                                      unaff_s5 = unaff_s5 + -1;
                                      local_res0[0] = unaff_s5;
                                      if (unaff_s5 == 0) goto LAB_00446af8;
                                      local_98 = puVar24[1];
                                      puVar24 = puVar24 + 1;
                                      iVar16 = unaff_s5;
                                    }
                                    else {
                                      iVar25 = (*(code *)PTR_strcmp_006a9b18)(uVar23,"-no_cache");
                                      if (iVar25 == 0) {
                                        bVar5 = true;
                                      }
                                      else {
                                        iVar16 = args_verify(local_5c,local_res0,&local_4c,
                                                             *(undefined4 *)puVar10,&local_50);
                                        puVar24 = local_5c[0];
                                        if (iVar16 != 0) goto code_r0x00448348;
                                        uVar23 = *local_5c[0];
                                        iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                           (uVar23,"-verify_return_error");
                                        if (iVar16 == 0) {
                                          *(undefined4 *)PTR_verify_return_error_006a7924 = 1;
                                          iVar16 = local_res0[0];
                                        }
                                        else {
                                          iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                             (uVar23,"-serverpref");
                                          if (iVar16 == 0) {
                                            local_c4 = local_c4 | 0x400000;
                                            iVar16 = local_res0[0];
                                          }
                                          else {
                                            iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                               (uVar23,"-legacy_renegotiation");
                                            if (iVar16 == 0) {
                                              local_c4 = local_c4 | 0x40000;
                                              iVar16 = local_res0[0];
                                            }
                                            else {
                                              iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                 (uVar23,"-cipher");
                                              if (iVar16 == 0) {
                                                unaff_s5 = local_res0[0] + -1;
                                                local_res0[0] = unaff_s5;
                                                if (unaff_s5 < 1) goto LAB_00446af8;
                                                cipher = puVar24[1];
                                                puVar24 = puVar24 + 1;
                                                iVar16 = unaff_s5;
                                              }
                                              else {
                                                iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                   (uVar23,"-CAfile");
                                                if (iVar16 == 0) {
                                                  unaff_s5 = local_res0[0] + -1;
                                                  local_res0[0] = unaff_s5;
                                                  if (unaff_s5 < 1) goto LAB_00446af8;
                                                  local_a4 = puVar24[1];
                                                  puVar24 = puVar24 + 1;
                                                  iVar16 = unaff_s5;
                                                }
                                                else {
                                                  iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                     (uVar23,"-nbio");
                                                  if (iVar16 == 0) {
                                                    s_nbio = 1;
                                                    iVar16 = local_res0[0];
                                                  }
                                                  else {
                                                    iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar23,"-nbio_test");
                                                    if (iVar16 == 0) {
                                                      s_nbio = 1;
                                                      s_nbio_test = 1;
                                                      iVar16 = local_res0[0];
                                                    }
                                                    else {
                                                      iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (uVar23,"-debug");
                                                      if (iVar16 == 0) {
                                                        s_debug = 1;
                                                        iVar16 = local_res0[0];
                                                      }
                                                      else {
                                                        iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (uVar23,"-tlsextdebug");
                                                        if (iVar16 == 0) {
                                                          s_tlsextdebug = 1;
                                                          iVar16 = local_res0[0];
                                                        }
                                                        else {
                                                          iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                             (uVar23,"-status");
                                                          if (iVar16 == 0) {
                                                            s_tlsextstatus = 1;
                                                            iVar16 = local_res0[0];
                                                          }
                                                          else {
                                                            iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                               (uVar23,
                                                  "-status_verbose");
                                                  if (iVar16 == 0) {
                                                    tlscstatp._24_4_ = 1;
                                                    s_tlsextstatus = 1;
                                                    iVar16 = local_res0[0];
                                                  }
                                                  else {
                                                    iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar23,"-status_timeout");
                                                    if (iVar16 == 0) {
                                                      local_res0[0] = local_res0[0] + -1;
                                                      s_tlsextstatus = 1;
                                                      if (local_res0[0] < 1) goto LAB_00446af8;
                                                      local_5c[0] = puVar24 + 1;
                                                      tlscstatp._16_4_ =
                                                           (*(code *)PTR_strtol_006a9958)
                                                                     (puVar24[1],0,10);
                                                      puVar24 = local_5c[0];
                                                      iVar16 = local_res0[0];
                                                    }
                                                    else {
                                                      iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (uVar23,"-status_url");
                                                      if (iVar16 == 0) {
                                                        local_res0[0] = local_res0[0] + -1;
                                                        s_tlsextstatus = 1;
                                                        if (local_res0[0] < 1) goto LAB_00446af8;
                                                        local_5c[0] = puVar24 + 1;
                                                        iVar25 = (*(code *)
                                                  PTR_OCSP_parse_url_006a7764)
                                                            (*local_5c[0],tlscstatp,0x69b738,
                                                             0x69b734,0x69b73c);
                                                  puVar24 = local_5c[0];
                                                  iVar16 = local_res0[0];
                                                  if (iVar25 == 0) {
                                                    (*(code *)PTR_BIO_printf_006a6e38)
                                                              (*(undefined4 *)puVar10,
                                                               "Error parsing URL\n");
                                                    goto LAB_00446af8;
                                                  }
                                                  }
                                                  else {
                                                    iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar23,&DAT_0063b780);
                                                    if (iVar16 == 0) {
                                                      s_msg = 1;
                                                      iVar16 = local_res0[0];
                                                    }
                                                    else {
                                                      iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (uVar23,"-hack");
                                                      if (iVar16 == 0) {
                                                        hack = 1;
                                                        iVar16 = local_res0[0];
                                                      }
                                                      else {
                                                        iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (uVar23,"-state");
                                                        if (iVar16 == 0) {
                                                          bVar4 = true;
                                                          iVar16 = local_res0[0];
                                                        }
                                                        else {
                                                          iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                             (uVar23,"-crlf");
                                                          if (iVar16 == 0) {
                                                            s_crlf = 1;
                                                            iVar16 = local_res0[0];
                                                          }
                                                          else {
                                                            iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                               (uVar23,"-quiet");
                                                            if (iVar16 == 0) {
                                                              s_quiet = 1;
                                                              iVar16 = local_res0[0];
                                                            }
                                                            else {
                                                              iVar16 = (*(code *)PTR_strcmp_006a9b18
                                                                       )(uVar23,"-bugs");
                                                              if (iVar16 == 0) {
                                                                bVar3 = true;
                                                                iVar16 = local_res0[0];
                                                              }
                                                              else {
                                                                iVar16 = (*(code *)
                                                  PTR_strcmp_006a9b18)(uVar23,"-no_tmp_rsa");
                                                  if (iVar16 == 0) {
                                                    bVar8 = true;
                                                    iVar16 = local_res0[0];
                                                  }
                                                  else {
                                                    iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar23,"-no_dhe");
                                                    if (iVar16 == 0) {
                                                      bVar6 = true;
                                                      iVar16 = local_res0[0];
                                                    }
                                                    else {
                                                      iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (uVar23,"-no_ecdhe");
                                                      if (iVar16 == 0) {
                                                        bVar7 = true;
                                                        iVar16 = local_res0[0];
                                                      }
                                                      else {
                                                        iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (uVar23,"-psk_hint");
                                                        if (iVar16 == 0) {
                                                          unaff_s5 = local_res0[0] + -1;
                                                          local_res0[0] = unaff_s5;
                                                          if (unaff_s5 < 1) goto LAB_00446af8;
                                                          psk_identity_hint_18462 = puVar24[1];
                                                          puVar24 = puVar24 + 1;
                                                          iVar16 = unaff_s5;
                                                        }
                                                        else {
                                                          iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                             (uVar23,&DAT_0063b7d4);
                                                          if (iVar16 == 0) {
                                                            unaff_s5 = local_res0[0] + -1;
                                                            local_res0[0] = unaff_s5;
                                                            if (unaff_s5 < 1) goto LAB_00446af8;
                                                            pbVar21 = (byte *)puVar24[1];
                                                            psk_key = pbVar21;
                                                            local_5c[0] = puVar24 + 1;
                                                            iVar25 = (*(code *)PTR_strlen_006a9a24)
                                                                               (pbVar21);
                                                            pbVar18 = pbVar21;
                                                            while (puVar24 = puVar24 + 1,
                                                                  iVar16 = unaff_s5,
                                                                  pbVar21 + iVar25 != pbVar18) {
                                                              piVar15 = (int *)(*(code *)
                                                  PTR___ctype_b_loc_006a9938)();
                                                  bVar1 = *pbVar18;
                                                  pbVar18 = pbVar18 + 1;
                                                  if ((*(ushort *)(*piVar15 + (uint)bVar1 * 2) &
                                                      0x10) == 0) {
                                                    (*(code *)PTR_BIO_printf_006a6e38)
                                                              (*(undefined4 *)puVar10,
                                                               "Not a hex number \'%s\'\n",pbVar21);
                                                    goto LAB_00446af8;
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar23,"-srpvfile");
                                                    if (iVar16 == 0) {
                                                      local_res0[0] = local_res0[0] + -1;
                                                      if (local_res0[0] < 1) goto LAB_00446af8;
                                                      local_88 = puVar24[1];
LAB_00448974:
                                                      local_5c[0] = puVar24 + 1;
                                                      pcVar20 = (code *)
                                                  PTR_TLSv1_server_method_006a7928;
                                                  }
                                                  else {
                                                    iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar23,"-srpuserseed");
                                                    if (iVar16 == 0) {
                                                      local_res0[0] = local_res0[0] + -1;
                                                      if (0 < local_res0[0]) {
                                                        local_6c = puVar24[1];
                                                        goto LAB_00448974;
                                                      }
                                                      goto LAB_00446af8;
                                                    }
                                                    iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar23,&DAT_0063b810);
                                                    if (iVar16 == 0) {
                                                      www = 1;
                                                      iVar16 = local_res0[0];
                                                      goto LAB_004463c0;
                                                    }
                                                    iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar23,&DAT_0063b818);
                                                    if (iVar16 == 0) {
                                                      www = 2;
                                                      iVar16 = local_res0[0];
                                                      goto LAB_004463c0;
                                                    }
                                                    iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar23,"-HTTP");
                                                    if (iVar16 == 0) {
                                                      www = 3;
                                                      iVar16 = local_res0[0];
                                                      goto LAB_004463c0;
                                                    }
                                                    iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar23,"-no_ssl2");
                                                    if (iVar16 == 0) {
                                                      local_c4 = local_c4 | 0x1000000;
                                                      iVar16 = local_res0[0];
                                                      goto LAB_004463c0;
                                                    }
                                                    iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar23,"-no_ssl3");
                                                    if (iVar16 == 0) {
                                                      local_c4 = local_c4 | 0x2000000;
                                                      iVar16 = local_res0[0];
                                                      goto LAB_004463c0;
                                                    }
                                                    iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar23,"-no_tls1");
                                                    if (iVar16 == 0) {
                                                      local_c4 = local_c4 | 0x4000000;
                                                      iVar16 = local_res0[0];
                                                      goto LAB_004463c0;
                                                    }
                                                    iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar23,"-no_tls1_1");
                                                    if (iVar16 == 0) {
                                                      local_c4 = local_c4 | 0x10000000;
                                                      iVar16 = local_res0[0];
                                                      goto LAB_004463c0;
                                                    }
                                                    iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar23,"-no_tls1_2");
                                                    if (iVar16 == 0) {
                                                      local_c4 = local_c4 | 0x8000000;
                                                      iVar16 = local_res0[0];
                                                      goto LAB_004463c0;
                                                    }
                                                    iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar23,"-no_comp");
                                                    if (iVar16 == 0) {
                                                      local_c4 = local_c4 | 0x20000;
                                                      iVar16 = local_res0[0];
                                                      goto LAB_004463c0;
                                                    }
                                                    iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar23,"-no_ticket");
                                                    if (iVar16 == 0) {
                                                      local_c4 = local_c4 | 0x4000;
                                                      iVar16 = local_res0[0];
                                                      goto LAB_004463c0;
                                                    }
                                                    iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar23,"-ssl3");
                                                    pcVar20 = (code *)
                                                  PTR_SSLv3_server_method_006a792c;
                                                  if ((((iVar16 != 0) &&
                                                       (iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (uVar23,"-tls1"),
                                                       pcVar20 = (code *)
                                                  PTR_TLSv1_server_method_006a7928, iVar16 != 0)) &&
                                                  (iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                      (uVar23,"-tls1_1"),
                                                  pcVar20 = (code *)
                                                  PTR_TLSv1_1_server_method_006a7934, iVar16 != 0))
                                                  && (iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (uVar23,"-tls1_2"),
                                                     pcVar20 = (code *)
                                                  PTR_TLSv1_2_server_method_006a7938, iVar16 != 0))
                                                  {
                                                    iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar23,"-dtls1");
                                                    if (iVar16 == 0) {
                                                      local_fc = (*(code *)
                                                  PTR_DTLSv1_server_method_006a7930)();
                                                  local_bc = 1;
                                                  puVar24 = local_5c[0];
                                                  iVar16 = local_res0[0];
                                                  }
                                                  else {
                                                    iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar23,"-timeout");
                                                    if (iVar16 == 0) {
                                                      enable_timeouts = 1;
                                                      iVar16 = local_res0[0];
                                                    }
                                                    else {
                                                      iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (uVar23,&DAT_0063b8b0);
                                                      if (iVar16 == 0) {
                                                        local_res0[0] = local_res0[0] + -1;
                                                        if (0 < local_res0[0]) {
                                                          local_5c[0] = puVar24 + 1;
                                                          socket_mtu = (*(code *)PTR_strtol_006a9958
                                                                       )(puVar24[1],0,10);
                                                          puVar24 = local_5c[0];
                                                          iVar16 = local_res0[0];
                                                          goto LAB_004463c0;
                                                        }
                                                        goto LAB_00446af8;
                                                      }
                                                      iVar25 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (uVar23,"-chain");
                                                      iVar16 = local_res0[0];
                                                      if (iVar25 != 0) {
                                                        iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (uVar23,"-id_prefix");
                                                        if (iVar16 == 0) {
                                                          unaff_s5 = local_res0[0] + -1;
                                                          local_res0[0] = unaff_s5;
                                                          if (unaff_s5 < 1) goto LAB_00446af8;
                                                          session_id_prefix = puVar24[1];
                                                          puVar24 = puVar24 + 1;
                                                          iVar16 = unaff_s5;
                                                        }
                                                        else {
                                                          iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                             (uVar23,"-engine");
                                                          if (iVar16 == 0) {
                                                            unaff_s5 = local_res0[0] + -1;
                                                            local_res0[0] = unaff_s5;
                                                            if (unaff_s5 < 1) goto LAB_00446af8;
                                                            engine_id = puVar24[1];
                                                            puVar24 = puVar24 + 1;
                                                            iVar16 = unaff_s5;
                                                          }
                                                          else {
                                                            iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                               (uVar23,"-rand");
                                                            if (iVar16 == 0) {
                                                              unaff_s5 = local_res0[0] + -1;
                                                              local_res0[0] = unaff_s5;
                                                              if (unaff_s5 < 1) goto LAB_00446af8;
                                                              local_ac = puVar24[1];
                                                              puVar24 = puVar24 + 1;
                                                              iVar16 = unaff_s5;
                                                            }
                                                            else {
                                                              iVar16 = (*(code *)PTR_strcmp_006a9b18
                                                                       )(uVar23,"-servername");
                                                              if (iVar16 == 0) {
                                                                unaff_s5 = local_res0[0] + -1;
                                                                local_res0[0] = unaff_s5;
                                                                if (unaff_s5 < 1) goto LAB_00446af8;
                                                                local_38 = puVar24[1];
                                                                puVar24 = puVar24 + 1;
                                                                iVar16 = unaff_s5;
                                                              }
                                                              else {
                                                                iVar16 = (*(code *)
                                                  PTR_strcmp_006a9b18)(uVar23,"-servername_fatal");
                                                  if (iVar16 == 0) {
                                                    local_30 = 2;
                                                    iVar16 = local_res0[0];
                                                  }
                                                  else {
                                                    iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar23,"-cert2");
                                                    if (iVar16 == 0) {
                                                      unaff_s5 = local_res0[0] + -1;
                                                      local_res0[0] = unaff_s5;
                                                      if (unaff_s5 < 1) goto LAB_00446af8;
                                                      s_cert_file2 = (undefined *)puVar24[1];
                                                      puVar24 = puVar24 + 1;
                                                      iVar16 = unaff_s5;
                                                    }
                                                    else {
                                                      iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (uVar23,"-key2");
                                                      if (iVar16 == 0) {
                                                        unaff_s5 = local_res0[0] + -1;
                                                        local_res0[0] = unaff_s5;
                                                        if (unaff_s5 < 1) goto LAB_00446af8;
                                                        s_key_file2 = (undefined *)puVar24[1];
                                                        puVar24 = puVar24 + 1;
                                                        iVar16 = unaff_s5;
                                                      }
                                                      else {
                                                        iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (uVar23,"-nextprotoneg");
                                                        if (iVar16 == 0) {
                                                          unaff_s5 = local_res0[0] + -1;
                                                          local_res0[0] = unaff_s5;
                                                          if (unaff_s5 < 1) goto LAB_00446af8;
                                                          local_a8 = puVar24[1];
                                                          puVar24 = puVar24 + 1;
                                                          iVar16 = unaff_s5;
                                                        }
                                                        else {
                                                          iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                             (uVar23,"-use_srtp");
                                                          if (iVar16 == 0) {
                                                            unaff_s5 = local_res0[0] + -1;
                                                            local_res0[0] = unaff_s5;
                                                            if (unaff_s5 < 1) goto LAB_00446af8;
                                                            srtp_profiles = puVar24[1];
                                                            puVar24 = puVar24 + 1;
                                                            iVar16 = unaff_s5;
                                                          }
                                                          else {
                                                            iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                               (uVar23,
                                                  "-keymatexport");
                                                  if (iVar16 == 0) {
                                                    unaff_s5 = local_res0[0] + -1;
                                                    local_res0[0] = unaff_s5;
                                                    if (unaff_s5 < 1) goto LAB_00446af8;
                                                    keymatexportlabel = puVar24[1];
                                                    puVar24 = puVar24 + 1;
                                                    iVar16 = unaff_s5;
                                                  }
                                                  else {
                                                    iVar16 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar23,"-keymatexportlen");
                                                    if (iVar16 != 0) {
                                                      (*(code *)PTR_BIO_printf_006a6e38)
                                                                (*(undefined4 *)puVar10,
                                                                 "unknown option %s\n",uVar23);
                                                      goto LAB_00446af8;
                                                    }
                                                    local_res0[0] = local_res0[0] + -1;
                                                    if (local_res0[0] < 1) goto LAB_00446af8;
                                                    local_5c[0] = puVar24 + 1;
                                                    keymatexportlen =
                                                         (*(code *)PTR_strtol_006a9958)
                                                                   (puVar24[1],0,10);
                                                    puVar24 = local_5c[0];
                                                    iVar16 = local_res0[0];
                                                    if (keymatexportlen == 0) goto LAB_00446af8;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_004463c0;
                                                  }
                                                  }
                                                  local_fc = (*pcVar20)();
                                                  puVar24 = local_5c[0];
                                                  iVar16 = local_res0[0];
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
LAB_004463c0:
      local_res0[0] = iVar16 + -1;
      local_5c[0] = puVar24 + 1;
      if (local_res0[0] < 1) goto LAB_004463d8;
      goto LAB_00446310;
    }
LAB_004463d8:
    unaff_s5 = local_res0[0];
    if ((www != 0) && (local_bc == 1)) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar10,"Can\'t use -HTTP, -www or -WWW with DTLS\n");
      goto LAB_00446054;
    }
    (*(code *)PTR_SSL_load_error_strings_006a7588)();
    (*(code *)PTR_SSL_library_init_006a7898)();
    uVar23 = setup_engine(*(undefined4 *)puVar10,engine_id,1);
    iVar16 = app_passwd(*(undefined4 *)puVar10,local_b8,local_b4,&local_48,&local_44);
    puVar11 = PTR_bio_err_006a6e3c;
    if (iVar16 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,"Error getting password\n");
      goto LAB_00446054;
    }
    if (s_key_file == (undefined *)0x0) {
      s_key_file = s_cert_file;
    }
    if (s_key_file2 == (undefined *)0x0) {
      s_key_file2 = s_cert_file2;
    }
    iVar16 = 0;
    if (bVar2) {
      iVar22 = 0;
      unaff_s5 = 0;
      unaff_s8 = (char *)0x0;
    }
    else {
      unaff_s5 = load_key(*(undefined4 *)puVar10,s_key_file,local_7c,0,local_48,uVar23,
                          "server certificate private key file");
      if (unaff_s5 == 0) {
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar11);
        goto LAB_00446054;
      }
      unaff_s8 = (char *)load_cert(*(undefined4 *)puVar11,s_cert_file,local_b0,0,uVar23,
                                   "server certificate file");
      if (unaff_s8 == (char *)0x0) {
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar11);
        if (ctx != 0) goto LAB_004482cc;
        iVar25 = 0;
        iVar22 = 0;
        iVar16 = 0;
        iVar27 = 1;
        goto LAB_004460c0;
      }
      if (local_38 == 0) {
        iVar16 = 0;
        iVar22 = 0;
      }
      else {
        iVar22 = load_key(*(undefined4 *)puVar11,s_key_file2,local_7c,0,local_48,uVar23,
                          "second server certificate private key file");
        if ((iVar22 == 0) ||
           (iVar16 = load_cert(*(undefined4 *)puVar11,s_cert_file2,local_b0,0,uVar23,
                               "second server certificate file"), iVar16 == 0)) {
          iVar16 = 0;
          iVar26 = 0;
          iVar25 = 0;
          iVar27 = 1;
          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar11);
          if (ctx == 0) goto LAB_00446094;
          goto LAB_00446080;
        }
      }
    }
    if (local_a8 == 0) {
      local_40 = 0;
LAB_004464bc:
      puVar11 = PTR_bio_err_006a6e3c;
      if (s_dcert_file == 0) {
        iVar25 = 0;
        iVar26 = 0;
LAB_00446554:
        iVar27 = app_RAND_load_file(0,*(undefined4 *)puVar10,1);
        if (iVar27 == 0) {
          if (local_ac == 0) {
            iVar27 = (*(code *)PTR_RAND_status_006a773c)();
            if (iVar27 == 0) {
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)PTR_bio_err_006a6e3c,
                         "warning, not much extra random data, consider using the -rand option\n");
            }
          }
          else {
LAB_0044657c:
            uVar17 = *(undefined4 *)puVar10;
            uVar23 = app_RAND_load_files(local_ac);
            (*(code *)PTR_BIO_printf_006a6e38)(uVar17,"%ld semi-random bytes loaded\n",uVar23);
          }
        }
        else if (local_ac != 0) goto LAB_0044657c;
        if (bio_s_out == 0) {
          if (((s_quiet == 0) || (s_debug != 0)) || (s_msg != 0)) {
            bio_s_out = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdout_006a99c8,0);
          }
          else {
            uVar23 = (*(code *)PTR_BIO_s_null_006a7908)();
            bio_s_out = (*(code *)PTR_BIO_new_006a6ea4)(uVar23);
          }
        }
        if (bVar2) {
          s_cert_file = (undefined *)0x0;
          s_key_file = (undefined *)0x0;
          s_dcert_file = 0;
          s_dkey_file = 0;
          s_cert_file2 = (undefined *)0x0;
          s_key_file2 = (undefined *)0x0;
        }
        iVar27 = (*(code *)PTR_SSL_CTX_new_006a78a0)(local_fc);
        ctx = iVar27;
        if (iVar27 == 0) goto LAB_00447d00;
        if (session_id_prefix != 0) {
          uVar13 = (*(code *)PTR_strlen_006a9a24)();
          if (uVar13 < 0x20) {
            if (0xf < uVar13) {
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar10,"warning: id_prefix is too long if you use SSLv2\n")
              ;
              iVar27 = ctx;
            }
          }
          else {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar10,
                       "warning: id_prefix is too long, only one new session will be possible\n");
            iVar27 = ctx;
          }
          iVar27 = (*(code *)PTR_SSL_CTX_set_generate_session_id_006a78a4)
                             (iVar27,generate_session_id);
          if (iVar27 != 0) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar10,"id_prefix \'%s\' set.\n",session_id_prefix);
            goto LAB_0044668c;
          }
LAB_00447634:
          uVar23 = *(undefined4 *)puVar10;
          pcVar19 = "error setting \'id_prefix\'\n";
          goto LAB_00447644;
        }
LAB_0044668c:
        (*(code *)PTR_SSL_CTX_set_quiet_shutdown_006a78a8)(ctx,1);
        if (bVar3) {
          (*(code *)PTR_SSL_CTX_ctrl_006a775c)(ctx,0x20,0x80000bff,0);
        }
        if (hack != 0) {
          (*(code *)PTR_SSL_CTX_ctrl_006a775c)(ctx,0x20,0x40000000,0);
        }
        (*(code *)PTR_SSL_CTX_ctrl_006a775c)(ctx,0x20,local_c4,0);
        if (bVar4) {
          (*(code *)PTR_SSL_CTX_set_info_callback_006a78fc)(ctx,PTR_apps_ssl_info_callback_006a7900)
          ;
        }
        if (bVar5) {
          (*(code *)PTR_SSL_CTX_ctrl_006a775c)(ctx,0x2c,0);
        }
        else {
          (*(code *)PTR_SSL_CTX_ctrl_006a775c)(ctx,0x2a,0x80,0);
        }
        if (srtp_profiles != 0) {
          (*(code *)PTR_SSL_CTX_set_tlsext_use_srtp_006a78ac)(ctx);
        }
        iVar27 = (*(code *)PTR_SSL_CTX_load_verify_locations_006a78b0)(ctx,local_a4,local_98);
        if ((iVar27 == 0) ||
           (iVar27 = (*(code *)PTR_SSL_CTX_set_default_verify_paths_006a78b4)(ctx), iVar27 == 0)) {
          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar10);
        }
        if (local_50 != 0) {
          (*(code *)PTR_SSL_CTX_set1_param_006a78b8)(ctx);
        }
        if (iVar16 == 0) {
          if (ctx2 != 0) goto LAB_004467b4;
        }
        else {
          ctx2 = (*(code *)PTR_SSL_CTX_new_006a78a0)(local_fc);
          if (ctx2 == 0) goto LAB_00447d00;
LAB_004467b4:
          (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"Setting secondary ctx parameters\n");
          if (session_id_prefix != 0) {
            uVar13 = (*(code *)PTR_strlen_006a9a24)();
            if (uVar13 < 0x20) {
              if (0xf < uVar13) {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar10,
                           "warning: id_prefix is too long if you use SSLv2\n");
              }
            }
            else {
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar10,
                         "warning: id_prefix is too long, only one new session will be possible\n");
            }
            iVar27 = (*(code *)PTR_SSL_CTX_set_generate_session_id_006a78a4)
                               (ctx2,generate_session_id);
            if (iVar27 == 0) goto LAB_00447634;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar10,"id_prefix \'%s\' set.\n",session_id_prefix);
          }
          (*(code *)PTR_SSL_CTX_set_quiet_shutdown_006a78a8)(ctx2,1);
          if (bVar3) {
            (*(code *)PTR_SSL_CTX_ctrl_006a775c)(ctx2,0x20,0x80000bff,0);
          }
          if (hack != 0) {
            (*(code *)PTR_SSL_CTX_ctrl_006a775c)(ctx2,0x20,0x40000000,0);
          }
          (*(code *)PTR_SSL_CTX_ctrl_006a775c)(ctx2,0x20,local_c4,0);
          if (bVar4) {
            (*(code *)PTR_SSL_CTX_set_info_callback_006a78fc)
                      (ctx2,PTR_apps_ssl_info_callback_006a7900);
          }
          if (bVar5) {
            (*(code *)PTR_SSL_CTX_ctrl_006a775c)(ctx2,0x2c,0);
          }
          else {
            (*(code *)PTR_SSL_CTX_ctrl_006a775c)(ctx2,0x2a,0x80,0);
          }
          iVar27 = (*(code *)PTR_SSL_CTX_load_verify_locations_006a78b0)(ctx2,local_a4,local_98);
          if ((iVar27 == 0) ||
             (iVar27 = (*(code *)PTR_SSL_CTX_set_default_verify_paths_006a78b4)(ctx2), iVar27 == 0))
          {
            (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar10);
          }
          if (local_50 != 0) {
            (*(code *)PTR_SSL_CTX_set1_param_006a78b8)(ctx2);
          }
        }
        if (local_40 != 0) {
          (*(code *)PTR_SSL_CTX_set_next_protos_advertised_cb_006a78bc)(ctx,next_proto_cb,&local_40)
          ;
        }
        if (!bVar6) {
          if (local_84 == 0) {
            if (s_cert_file != (undefined *)0x0) {
              iVar27 = load_dh_param();
              goto LAB_004469b8;
            }
LAB_00447c6c:
            (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"Using default temp DH parameters\n");
            iVar27 = (*(code *)PTR_DH_new_006a751c)();
            if (iVar27 != 0) {
              uVar23 = (*(code *)PTR_BN_bin2bn_006a7904)(dh2048_p,0x100,0);
              *(undefined4 *)(iVar27 + 8) = uVar23;
              iVar14 = (*(code *)PTR_BN_bin2bn_006a7904)(&dh2048_g,1,0);
              *(int *)(iVar27 + 0xc) = iVar14;
              if ((*(int *)(iVar27 + 8) != 0) && (iVar14 != 0)) goto LAB_004469dc;
              (*(code *)PTR_DH_free_006a7508)(iVar27);
            }
LAB_00447d00:
            iVar27 = 1;
            (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar10);
            goto LAB_00446ab0;
          }
          iVar14 = (*(code *)PTR_BIO_new_file_006a6eac)(local_84,"r");
          if (iVar14 == 0) goto LAB_00447c6c;
          iVar27 = (*(code *)PTR_PEM_read_bio_DHparams_006a750c)(iVar14,0,0,0);
          (*(code *)PTR_BIO_free_006a6e70)(iVar14);
LAB_004469b8:
          if (iVar27 == 0) goto LAB_00447c6c;
          (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"Setting temp DH parameters\n");
LAB_004469dc:
          (*(code *)PTR_BIO_ctrl_006a6e18)(bio_s_out,0xb,0,0);
          (*(code *)PTR_SSL_CTX_ctrl_006a775c)(ctx,3,0,iVar27);
          if (ctx2 != 0) {
            if ((local_84 == 0) && (iVar14 = load_dh_param(s_cert_file2), iVar14 != 0)) {
              (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"Setting temp DH parameters\n");
              (*(code *)PTR_BIO_ctrl_006a6e18)(bio_s_out,0xb,0,0);
              (*(code *)PTR_DH_free_006a7508)(iVar27);
              iVar27 = iVar14;
            }
            (*(code *)PTR_SSL_CTX_ctrl_006a775c)(ctx2,3,0,iVar27);
          }
          (*(code *)PTR_DH_free_006a7508)(iVar27);
        }
        if (bVar7) {
LAB_004477b0:
          iVar27 = set_cert_key_stuff(ctx,unaff_s8,unaff_s5);
          if (((iVar27 == 0) ||
              ((ctx2 != 0 && (iVar27 = set_cert_key_stuff(ctx2,iVar16,iVar22), iVar27 == 0)))) ||
             ((iVar26 != 0 && (iVar27 = set_cert_key_stuff(ctx,iVar26,iVar25), iVar27 == 0)))) {
            iVar27 = 1;
          }
          else {
            if ((!bVar8) &&
               ((*(code *)PTR_SSL_CTX_set_tmp_rsa_callback_006a790c)(ctx,tmp_rsa_cb), ctx2 != 0)) {
              (*(code *)PTR_SSL_CTX_set_tmp_rsa_callback_006a790c)(ctx2,tmp_rsa_cb);
            }
            if (psk_key != (byte *)0x0) {
              if (s_debug != 0) {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (bio_s_out,"PSK key given or JPAKE in use, setting server callback\n");
              }
              (*(code *)PTR_SSL_CTX_set_psk_server_callback_006a78cc)(ctx,psk_server_cb);
            }
            iVar27 = (*(code *)PTR_SSL_CTX_use_psk_identity_hint_006a78d0)
                               (ctx,psk_identity_hint_18462);
            if (iVar27 == 0) {
              uVar23 = *(undefined4 *)puVar10;
              pcVar19 = "error setting PSK identity hint to context\n";
            }
            else {
              if ((cipher == 0) ||
                 ((iVar27 = (*(code *)PTR_SSL_CTX_set_cipher_list_006a78d4)(ctx), iVar27 != 0 &&
                  ((ctx2 == 0 ||
                   (iVar27 = (*(code *)PTR_SSL_CTX_set_cipher_list_006a78d4)(ctx2,cipher),
                   iVar27 != 0)))))) {
                (*(code *)PTR_SSL_CTX_set_verify_006a78d8)
                          (ctx,s_server_verify,PTR_verify_callback_006a78dc);
                (*(code *)PTR_SSL_CTX_set_session_id_context_006a78e0)
                          (ctx,&s_server_session_id_context,4);
                (*(code *)PTR_SSL_CTX_set_cookie_generate_cb_006a78e4)
                          (ctx,PTR_generate_cookie_callback_006a78e8);
                (*(code *)PTR_SSL_CTX_set_cookie_verify_cb_006a78ec)
                          (ctx,PTR_verify_cookie_callback_006a78f0);
                if (ctx2 != 0) {
                  (*(code *)PTR_SSL_CTX_set_verify_006a78d8)
                            (ctx2,s_server_verify,PTR_verify_callback_006a78dc);
                  (*(code *)PTR_SSL_CTX_set_session_id_context_006a78e0)
                            (ctx2,&s_server_session_id_context,4);
                  local_34 = bio_s_out;
                  (*(code *)PTR_SSL_CTX_callback_ctrl_006a7824)(ctx2,0x35,ssl_servername_cb);
                  (*(code *)PTR_SSL_CTX_ctrl_006a775c)(ctx2,0x36,0,&local_38);
                  (*(code *)PTR_SSL_CTX_callback_ctrl_006a7824)(ctx,0x35,ssl_servername_cb);
                  (*(code *)PTR_SSL_CTX_ctrl_006a775c)(ctx,0x36,0,&local_38);
                }
                iVar27 = ctx;
                if (local_88 == 0) {
                  if (local_a4 != 0) {
                    uVar23 = (*(code *)PTR_SSL_load_client_CA_file_006a791c)(local_a4);
                    (*(code *)PTR_SSL_CTX_set_client_CA_list_006a7920)(iVar27,uVar23);
                    iVar27 = ctx2;
                    if (ctx2 != 0) {
                      uVar23 = (*(code *)PTR_SSL_load_client_CA_file_006a791c)(local_a4);
                      (*(code *)PTR_SSL_CTX_set_client_CA_list_006a7920)(iVar27,uVar23);
                    }
                  }
                }
                else {
                  srp_callback_parm._4_4_ = (*(code *)PTR_SRP_VBASE_new_006a78f4)(local_6c);
                  srp_callback_parm._0_4_ = 0;
                  srp_callback_parm._8_4_ = 0;
                  iVar27 = (*(code *)PTR_SRP_VBASE_init_006a78f8)(srp_callback_parm._4_4_,local_88);
                  if (iVar27 != 0) {
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar10,
                               "Cannot initialize SRP verifier file \"%s\":ret=%d\n",local_88,iVar27
                              );
                    goto LAB_00446ab0;
                  }
                  (*(code *)PTR_SSL_CTX_set_verify_006a78d8)(ctx,0,PTR_verify_callback_006a78dc);
                  (*(code *)PTR_SSL_CTX_set_srp_cb_arg_006a7910)(ctx,srp_callback_parm);
                  (*(code *)PTR_SSL_CTX_set_srp_username_callback_006a7914)
                            (ctx,ssl_srp_server_param_cb);
                }
                (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,s_ACCEPT_0063b138);
                (*(code *)PTR_BIO_ctrl_006a6e18)(bio_s_out,0xb,0,0);
                if (www == 0) {
                  pcVar20 = sv_body;
                }
                else {
                  pcVar20 = www_body;
                }
                iVar27 = 0;
                do_server((int)local_54,local_bc,&accept_socket,pcVar20,local_c8);
                print_stats(bio_s_out,ctx);
                goto LAB_00446ab0;
              }
              uVar23 = *(undefined4 *)puVar10;
              pcVar19 = "error setting cipher list\n";
            }
LAB_00447644:
            iVar27 = 1;
            (*(code *)PTR_BIO_printf_006a6e38)(uVar23,pcVar19);
            (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar10);
          }
        }
        else if (local_80 == 0) {
          (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"Using default temp ECDH parameters\n");
          iVar27 = (*(code *)PTR_EC_KEY_new_by_curve_name_006a78c4)(0x19f);
          if (iVar27 != 0) {
LAB_00447738:
            (*(code *)PTR_BIO_ctrl_006a6e18)(bio_s_out,0xb,0,0);
            (*(code *)PTR_SSL_CTX_ctrl_006a775c)(ctx,4,0,iVar27);
            if (ctx2 != 0) {
              (*(code *)PTR_SSL_CTX_ctrl_006a775c)(ctx2,4,0,iVar27);
            }
            (*(code *)PTR_EC_KEY_free_006a71d4)(iVar27);
            goto LAB_004477b0;
          }
          iVar27 = 1;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar10,"unable to create curve (nistp256)\n");
        }
        else {
          iVar27 = (*(code *)PTR_OBJ_sn2nid_006a71a4)(local_80);
          if (iVar27 == 0) {
            iVar27 = 1;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar10,"unknown curve name (%s)\n",local_80);
          }
          else {
            iVar27 = (*(code *)PTR_EC_KEY_new_by_curve_name_006a78c4)(iVar27);
            if (iVar27 != 0) {
              (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"Setting temp ECDH parameters\n");
              goto LAB_00447738;
            }
            iVar27 = 1;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar10,"unable to create curve (%s)\n",local_80);
          }
        }
      }
      else {
        if (s_dkey_file == 0) {
          s_dkey_file = s_dcert_file;
        }
        iVar25 = load_key(*(undefined4 *)puVar10,s_dkey_file,local_9c,0,local_44,uVar23,
                          "second certificate private key file");
        if (iVar25 == 0) {
          iVar26 = 0;
          iVar27 = 1;
          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar11);
        }
        else {
          iVar26 = load_cert(*(undefined4 *)puVar11,s_dcert_file,local_a0,0,uVar23,
                             "second server certificate file");
          if (iVar26 != 0) goto LAB_00446554;
          iVar27 = 1;
          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar11);
        }
      }
    }
    else {
      local_40 = next_protos_parse(&local_52,local_a8);
      if (local_40 != 0) {
        local_3c = (uint)local_52;
        goto LAB_004464bc;
      }
      iVar25 = 0;
      iVar26 = 0;
      iVar27 = 1;
    }
LAB_00446ab0:
    if (ctx == 0) goto LAB_0044608c;
    goto LAB_00446080;
  }
LAB_00446054:
  iVar22 = 0;
  if (ctx == 0) {
    iVar16 = 0;
    iVar27 = 1;
    goto LAB_004460e4;
  }
  iVar16 = 0;
  iVar25 = 0;
  unaff_s5 = 0;
  iVar26 = 0;
  unaff_s8 = (char *)0x0;
  iVar27 = 1;
LAB_00446080:
  while( true ) {
    (*(code *)PTR_SSL_CTX_free_006a7890)();
LAB_0044608c:
    if (unaff_s8 != (char *)0x0) {
LAB_00446094:
      (*(code *)PTR_X509_free_006a6e90)(unaff_s8);
    }
    if (iVar26 != 0) {
      (*(code *)PTR_X509_free_006a6e90)(iVar26);
    }
    if (unaff_s5 != 0) {
LAB_004460c0:
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(unaff_s5);
    }
    if (iVar25 != 0) {
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar25);
    }
LAB_004460e4:
    if (local_48 != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if (local_44 != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if (local_50 != 0) {
      (*(code *)PTR_X509_VERIFY_PARAM_free_006a72cc)();
    }
    if (tlscstatp._0_4_ != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if (tlscstatp._8_4_ != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if (tlscstatp._4_4_ != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if (ctx2 != 0) {
      (*(code *)PTR_SSL_CTX_free_006a7890)();
    }
    if (iVar16 != 0) {
      (*(code *)PTR_X509_free_006a6e90)(iVar16);
    }
    if (iVar22 != 0) {
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar22);
    }
    if (bio_s_out != 0) {
      (*(code *)PTR_BIO_free_006a6e70)();
      bio_s_out = 0;
    }
    if (local_2c == *(int *)puVar12) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004482cc:
    iVar16 = 0;
    iVar22 = 0;
    iVar25 = 0;
    iVar26 = 0;
    iVar27 = 1;
  }
  return iVar27;
code_r0x00448348:
  if (local_4c != 0) goto LAB_00446af8;
  goto LAB_00446308;
LAB_00446af8:
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"usage: s_server [args ...]\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -accept arg   - port to accept on (default is %d)\n",0x1151);
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -context arg  - set session ID context\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -verify arg   - turn on peer certificate verification\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,
             " -Verify arg   - turn on peer certificate verification, must have a cert.\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -verify_return_error - return verification errors\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -cert arg     - certificate file to use\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,"                 (default is %s)\n","server.pem");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,
             " -crl_check    - check the peer certificate has not been revoked by its CA.\n                 The CRL(s) are appended to the certificate file\n"
            );
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,
             " -crl_check_all - check the peer certificate has not been revoked by its CA\n                 or any other CRL in the CA chain. CRL(s) are appened to the\n                 the certificate file.\n"
            );
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -certform arg - certificate format (PEM or DER) PEM default\n"
            );
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -key arg      - Private Key file to use, in cert file if\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,"                 not specified (default is %s)\n","server.pem")
  ;
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -keyform arg  - key format (PEM, DER or ENGINE) PEM default\n"
            );
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -pass arg     - private key file pass phrase source\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,
             " -dcert arg    - second certificate file to use (usually for DSA)\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,
             " -dcertform x  - second certificate format (PEM or DER) PEM default\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,
             " -dkey arg     - second private key file to use (usually for DSA)\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,
             " -dkeyform arg - second key format (PEM, DER or ENGINE) PEM default\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -dpass arg    - second private key file pass phrase source\n")
  ;
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,
             " -dhparam arg  - DH parameter file to use, in cert file if not specified\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,"                 or a default set of parameters is used\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,
             " -named_curve arg  - Elliptic curve name to use for ephemeral ECDH keys.\n                 Use \"openssl ecparam -list_curves\" for all names\n                 (default is nistp256).\n"
            );
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -nbio         - Run with non-blocking IO\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -nbio_test    - test with the non-blocking test bio\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -crlf         - convert LF from terminal into CRLF\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10," -debug        - Print more output\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -msg          - Show protocol messages\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -state        - Print the SSL states\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -CApath arg   - PEM format directory of CA\'s\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -CAfile arg   - PEM format file of CA\'s\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,
             " -no_alt_chains - only ever use the first certificate chain found\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -nocert       - Don\'t use any certificates (Anon-DH)\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,
             " -cipher arg   - play with \'openssl ciphers\' to see what goes here\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -serverpref   - Use server\'s cipher preferences\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10," -quiet        - No server output\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -no_tmp_rsa   - Do not generate a tmp RSA key\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -psk_hint arg - PSK identity hint to use\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -psk arg      - PSK in hex (without 0x)\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -srpvfile file      - The verifier file for SRP\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,
             " -srpuserseed string - A seed string for a default user salt.\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10," -ssl2         - Just talk SSLv2\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10," -ssl3         - Just talk SSLv3\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10," -tls1_2       - Just talk TLSv1.2\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10," -tls1_1       - Just talk TLSv1.1\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10," -tls1         - Just talk TLSv1\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10," -dtls1        - Just talk DTLSv1\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10," -timeout      - Enable timeouts\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10," -mtu          - Set link layer MTU\n")
  ;
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -chain        - Read a certificate chain\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10," -no_ssl2      - Just disable SSLv2\n")
  ;
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10," -no_ssl3      - Just disable SSLv3\n")
  ;
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10," -no_tls1      - Just disable TLSv1\n")
  ;
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -no_tls1_1    - Just disable TLSv1.1\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -no_tls1_2    - Just disable TLSv1.2\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -no_dhe       - Disable ephemeral DH\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -no_ecdhe     - Disable ephemeral ECDH\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -bugs         - Turn on SSL bug compatibility\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -hack         - workaround for early Netscape code\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -www          - Respond to a \'GET /\' with a status page\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,
             " -WWW          - Respond to a \'GET /<path> HTTP/1.0\' with file ./<path>\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,
             " -HTTP         - Respond to a \'GET /<path> HTTP/1.0\' with file ./<path>\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,
             "                 with the assumption it contains a complete HTTP response.\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -engine id    - Initialise and use the specified engine\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,
             " -id_prefix arg - Generate SSL/TLS session IDs prefixed by \'arg\'\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10," -rand file%cfile%c...\n",0x3a,0x3a);
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -servername host - servername for HostName TLS extension\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,
             " -servername_fatal - on mismatch send fatal alert (default warning alert)\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -cert2 arg    - certificate file to use for servername\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,"                 (default is %s)\n","server2.pem");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,
             " -key2 arg     - Private Key file to use for servername, in cert file if\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,"                 not specified (default is %s)\n","server2.pem"
            );
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -tlsextdebug  - hex dump of all TLS extensions received\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -no_ticket    - disable use of RFC4507bis session tickets\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,
             " -legacy_renegotiation - enable use of legacy renegotiation (dangerous)\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,
             " -nextprotoneg arg - set the advertised protocols for the NPN extension (comma-separated list)\n"
            );
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,
             " -use_srtp profiles - Offer SRTP key management with a colon-separated profile list\n"
            );
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -keymatexport label   - Export keying material using label\n")
  ;
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10,
             " -keymatexportlen len  - Export len bytes of keying material (default 20)\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -status           - respond to certificate status requests\n")
  ;
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -status_verbose   - enable status request verbose printout\n")
  ;
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -status_timeout n - status request responder timeout\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)puVar10," -status_url URL   - status request fallback URL\n");
  goto LAB_00446054;
}

