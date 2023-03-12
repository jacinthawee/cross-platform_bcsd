
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int doConnection(int param_1,char *param_2)

{
  uint **ppuVar1;
  bool bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined4 uVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  int unaff_s0;
  undefined *unaff_s1;
  int iVar14;
  undefined4 unaff_s3;
  char *unaff_s4;
  char *pcVar15;
  undefined *unaff_s6;
  uint unaff_s7;
  uint **ppuVar16;
  int iVar17;
  double dVar18;
  double dVar19;
  int iVar20;
  uint *puStack_2104;
  undefined auStack_20fc [8192];
  int iStack_fc;
  int iStack_f8;
  undefined *puStack_f4;
  int iStack_f0;
  undefined4 uStack_ec;
  char *pcStack_e8;
  undefined *puStack_e4;
  undefined *puStack_e0;
  uint uStack_dc;
  uint auStack_ac [32];
  int local_2c;
  
  puStack_e4 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar7 = (*(code *)PTR_BIO_s_connect_006a7af4)();
  puVar8 = (uint *)(*(code *)PTR_BIO_new_006a6ea4)(uVar7);
  iStack_f8 = unaff_s0;
  if (puVar8 == (uint *)0x0) {
LAB_0045805c:
    iVar17 = 0;
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a6e18)(puVar8,100,0,host);
    if (param_1 == 0) {
      iVar17 = (*(code *)PTR_SSL_new_006a77e0)(tm_ctx);
    }
    else {
      (*(code *)PTR_SSL_set_connect_state_006a79bc)(param_1);
      iVar17 = param_1;
    }
    unaff_s6 = PTR_bio_err_006a6e3c;
    (*(code *)PTR_SSL_set_bio_006a77f8)(iVar17,puVar8,puVar8);
    unaff_s4 = "DELAY\n";
    unaff_s3 = 0x8000001f;
    while( true ) {
      unaff_s1 = (undefined *)(*(code *)PTR_SSL_connect_006a7af8)(iVar17);
      iVar9 = (*(code *)PTR_BIO_sock_should_retry_006a77d4)(unaff_s1);
      puVar4 = PTR_bio_err_006a6e3c;
      if (iVar9 == 0) break;
      puVar8 = auStack_ac;
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)unaff_s6,"DELAY\n");
      unaff_s7 = (*(code *)PTR_SSL_get_fd_006a79c0)(iVar17);
      (*(code *)PTR_memset_006a99f4)(puVar8,0,0x80);
      iVar9 = (*(code *)PTR___fdelt_chk_006a9aa0)(unaff_s7);
      auStack_ac[iVar9] = 1 << (unaff_s7 & 0x1f) | auStack_ac[iVar9];
      (*(code *)PTR_select_006a9ac4)(unaff_s7 + 1,puVar8,0,0);
    }
    param_2 = (char *)puVar8;
    iStack_f8 = iVar17;
    if ((int)unaff_s1 < 1) {
      param_2 = "ERROR\n";
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c);
      if (*(int *)PTR_verify_error_006a7988 == 0) {
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
        unaff_s1 = puVar4;
      }
      else {
        unaff_s1 = *(undefined **)puVar4;
        uVar7 = (*(code *)PTR_X509_verify_cert_error_string_006a72a0)();
        param_2 = "verify error:%s\n";
        (*(code *)PTR_BIO_printf_006a6e38)(unaff_s1,"verify error:%s\n",uVar7);
      }
      if (param_1 == 0) {
        (*(code *)PTR_SSL_free_006a7810)(iVar17);
      }
      goto LAB_0045805c;
    }
  }
  if (local_2c == *(int *)puStack_e4) {
    return iVar17;
  }
  iVar17 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar6 = PTR___stack_chk_guard_006a9ae8;
  puVar4 = PTR_bio_err_006a6e3c;
  pcVar15 = &_gp_1;
  iStack_fc = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_f4 = unaff_s1;
  iStack_f0 = param_1;
  uStack_ec = unaff_s3;
  pcStack_e8 = unaff_s4;
  puStack_e0 = unaff_s6;
  uStack_dc = unaff_s7;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  bytes_read = 0;
  t_key_file = (uint *)0x0;
  host = s_localhost_4433_0063f540;
  CApath = (uint *)0x0;
  tm_cipher = (uint *)0x0;
  puStack_2104 = (uint *)(methods_sockp + 0x10);
  t_cert_file = (uint *)0x0;
  perform = 0;
  CAfile = (uint *)0x0;
  tm_ctx = 0;
  s_time_meth = 0;
  maxTime = 0x1e;
  s_www_path = (uint *)0x0;
  st_bugs = 0;
  if (*(int *)puVar4 == 0) {
    uVar7 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stderr_006a9af8,0);
    *(undefined4 *)puVar4 = uVar7;
  }
  puVar5 = PTR_verify_depth_006a7894;
  iVar17 = iVar17 + -1;
  ppuVar16 = (uint **)((int)param_2 + 4);
  s_time_meth = (*(code *)PTR_SSLv23_client_method_006a7984)();
  *(undefined4 *)puVar5 = 0;
  *(undefined4 *)PTR_verify_error_006a7988 = 0;
  if (iVar17 < 1) {
    if (perform != 0) goto LAB_004582e0;
    bVar2 = false;
  }
  else {
    bVar2 = false;
    do {
      while( true ) {
        param_2 = (char *)*ppuVar16;
        iVar9 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-connect");
        if (iVar9 != 0) break;
        iVar17 = iVar17 + -1;
        if (iVar17 == 0) goto LAB_00458534;
        host = (undefined *)ppuVar16[1];
        ppuVar16 = ppuVar16 + 1;
LAB_00458274:
        iVar17 = iVar17 + -1;
        ppuVar16 = ppuVar16 + 1;
        if (iVar17 == 0) goto LAB_004582c4;
      }
      iVar9 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-reuse");
      if (iVar9 != 0) {
        iVar9 = (*(code *)PTR_strcmp_006a9b18)(param_2,&DAT_006326fc);
        if (iVar9 == 0) {
          perform = 1;
        }
        else {
          iVar9 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-verify");
          if (iVar9 == 0) {
            iVar17 = iVar17 + -1;
            if (iVar17 == 0) goto LAB_00458534;
            ppuVar1 = ppuVar16 + 1;
            ppuVar16 = ppuVar16 + 1;
            uVar7 = (*(code *)PTR_strtol_006a9958)(*ppuVar1,0,10);
            puVar3 = PTR_BIO_printf_006a6e38;
            uVar13 = *(undefined4 *)puVar4;
            *(undefined4 *)puVar5 = uVar7;
            (*(code *)puVar3)(uVar13,"verify depth is %d\n",uVar7);
          }
          else {
            iVar9 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-cert");
            if (iVar9 == 0) {
              iVar17 = iVar17 + -1;
              if (iVar17 == 0) goto LAB_00458534;
              t_cert_file = ppuVar16[1];
              ppuVar16 = ppuVar16 + 1;
            }
            else {
              iVar9 = (*(code *)PTR_strcmp_006a9b18)(param_2,&DAT_006326ec);
              if (iVar9 == 0) {
                iVar17 = iVar17 + -1;
                if (iVar17 == 0) goto LAB_00458534;
                t_key_file = ppuVar16[1];
                ppuVar16 = ppuVar16 + 1;
              }
              else {
                iVar9 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-CApath");
                if (iVar9 == 0) {
                  iVar17 = iVar17 + -1;
                  if (iVar17 == 0) goto LAB_00458534;
                  CApath = ppuVar16[1];
                  ppuVar16 = ppuVar16 + 1;
                }
                else {
                  iVar9 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-CAfile");
                  if (iVar9 == 0) {
                    iVar17 = iVar17 + -1;
                    if (iVar17 == 0) goto LAB_00458534;
                    CAfile = ppuVar16[1];
                    ppuVar16 = ppuVar16 + 1;
                  }
                  else {
                    iVar9 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-cipher");
                    if (iVar9 == 0) {
                      iVar17 = iVar17 + -1;
                      if (iVar17 == 0) goto LAB_00458534;
                      tm_cipher = ppuVar16[1];
                      ppuVar16 = ppuVar16 + 1;
                    }
                    else {
                      iVar9 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-nbio");
                      if (iVar9 != 0) {
                        iVar9 = (*(code *)PTR_strcmp_006a9b18)(param_2,&DAT_0063b810);
                        if (iVar9 == 0) {
                          iVar17 = iVar17 + -1;
                          if (iVar17 == 0) goto LAB_00458534;
                          s_www_path = ppuVar16[1];
                          ppuVar16 = ppuVar16 + 1;
                          uVar10 = (*(code *)PTR_strlen_006a9a24)(s_www_path);
                          if (0x1f9c < uVar10) {
                            (*(code *)PTR_BIO_printf_006a6e38)
                                      (*(undefined4 *)puVar4,"-www option too long\n");
                            bVar2 = true;
                          }
                        }
                        else {
                          iVar9 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-bugs");
                          if (iVar9 == 0) {
                            st_bugs = 1;
                          }
                          else {
                            iVar9 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-ssl3");
                            if (iVar9 == 0) {
                              s_time_meth = (*(code *)PTR_SSLv3_client_method_006a79d8)();
                            }
                            else {
                              iVar9 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-time");
                              if (iVar9 != 0) goto LAB_00458fb8;
                              iVar17 = iVar17 + -1;
                              if (iVar17 == 0) goto LAB_00458534;
                              ppuVar1 = ppuVar16 + 1;
                              ppuVar16 = ppuVar16 + 1;
                              maxTime = (*(code *)PTR_strtol_006a9958)(*ppuVar1,0,10);
                              if (maxTime < 1) {
                                (*(code *)PTR_BIO_printf_006a6e38)
                                          (*(undefined4 *)puVar4,"time must be > 0\n");
                                bVar2 = true;
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
        goto LAB_00458274;
      }
      iVar17 = iVar17 + -1;
      ppuVar16 = ppuVar16 + 1;
      perform = 2;
    } while (iVar17 != 0);
LAB_004582c4:
    if (perform != 0) goto LAB_004582d0;
  }
  perform = 3;
LAB_004582d0:
  if (bVar2) goto LAB_00458534;
LAB_004582e0:
  (*(code *)PTR_SSL_library_init_006a7898)();
  tm_ctx = (*(code *)PTR_SSL_CTX_new_006a78a0)(s_time_meth);
  if (tm_ctx == 0) {
    iVar17 = 1;
    goto LAB_004583a0;
  }
  (*(code *)PTR_SSL_CTX_set_quiet_shutdown_006a78a8)(tm_ctx,1);
  if (st_bugs != 0) {
    (*(code *)PTR_SSL_CTX_ctrl_006a775c)(tm_ctx,0x20,0x80000bff,0);
  }
  param_2 = &_gp_1;
  (*(code *)PTR_SSL_CTX_set_cipher_list_006a78d4)(tm_ctx,tm_cipher);
  iVar17 = set_cert_stuff(tm_ctx,t_cert_file,t_key_file);
  if (iVar17 != 0) {
    (*(code *)PTR_SSL_load_error_strings_006a7588)();
    iVar17 = (*(code *)PTR_SSL_CTX_load_verify_locations_006a78b0)(tm_ctx,CAfile,CApath);
    if ((iVar17 == 0) ||
       (iVar17 = (*(code *)PTR_SSL_CTX_set_default_verify_paths_006a78b4)(tm_ctx), iVar17 == 0)) {
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
    }
    if ((tm_cipher == (uint *)0x0) &&
       (tm_cipher = (uint *)(*(code *)PTR_getenv_006a9a60)("SSL_CIPHER"), tm_cipher == (uint *)0x0))
    {
      (*(code *)PTR_fwrite_006a9a74)
                ("No CIPHER specified\n",1,0x14,*(undefined4 *)PTR_stderr_006a9af8);
    }
    puVar5 = PTR_stdout_006a99c8;
    uVar10 = *(uint *)(pcVar15 + -0x5750);
    if ((uVar10 & 1) != 0) {
      iVar9 = 0;
      (*(code *)PTR___printf_chk_006a99c4)
                (1,"Collecting connection statistics for %d seconds\n",maxTime);
      bytes_read = 0;
      iVar17 = (*(code *)PTR_time_006a9adc)(0);
      iVar17 = iVar17 + maxTime;
      app_tminterval(0,1);
      param_2 = (char *)puStack_2104;
      while (iVar14 = (*(code *)PTR_time_006a9adc)(0), iVar14 <= iVar17) {
        param_2 = (char *)doConnection(0);
        if ((uint *)param_2 == (uint *)0x0) goto LAB_00458370;
        if (s_www_path != (uint *)0x0) {
          (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_20fc,0x2000,"GET %s HTTP/1.0\r\n\r\n");
          uVar7 = (*(code *)PTR_strlen_006a9a24)(auStack_20fc);
          (*(code *)PTR_SSL_write_006a7820)(param_2,auStack_20fc,uVar7);
          while (iVar14 = (*(code *)PTR_SSL_read_006a7818)(param_2,auStack_20fc,0x2000), 0 < iVar14)
          {
            bytes_read = bytes_read + iVar14;
          }
        }
        iVar9 = iVar9 + 1;
        (*(code *)PTR_SSL_set_shutdown_006a780c)(param_2,3);
        uVar7 = (*(code *)PTR_SSL_get_fd_006a79c0)(param_2);
        (*(code *)PTR_shutdown_006a995c)(uVar7,2);
        uVar7 = (*(code *)PTR_SSL_get_fd_006a79c0)(param_2);
        (*(code *)PTR_close_006a994c)(uVar7);
        iVar14 = (*(code *)PTR_SSL_ctrl_006a7788)(param_2,8,0,0);
        if (iVar14 == 0) {
          iVar14 = (*(code *)PTR_SSL_version_006a77ec)(param_2);
          if (iVar14 == 0x301) {
            uVar7 = 0x74;
          }
          else if (iVar14 == 0x300) {
            uVar7 = 0x33;
          }
          else {
            uVar7 = 0x2a;
            if (iVar14 == 2) {
              uVar7 = 0x32;
            }
          }
        }
        else {
          uVar7 = 0x72;
        }
        (*(code *)PTR_fputc_006a99a4)(uVar7,*(undefined4 *)puVar5);
        (*(code *)PTR_fflush_006a9b04)(*(undefined4 *)puVar5);
        (*(code *)PTR_SSL_free_006a7810)(param_2);
      }
      dVar18 = (double)app_tminterval(1,1);
      dVar18 = dVar18 + 0.0;
      (*(code *)PTR_time_006a9adc)(0);
      dVar19 = (double)iVar9 / dVar18;
      iVar14 = bytes_read;
      (*(code *)PTR___printf_chk_006a99c4)
                (1,"\n\n%d connections in %.2fs; %.2f connections/user sec, bytes read %ld\n",iVar9)
      ;
      uVar7 = SUB84(dVar18,0);
      iVar11 = (*(code *)PTR_time_006a9adc)(0);
      if (iVar9 == 0) {
        trap(7);
      }
      (*(code *)PTR___printf_chk_006a99c4)
                (1,"%d connections in %ld real seconds, %ld bytes read per connection\n",iVar9,
                 (iVar11 - iVar17) + maxTime,bytes_read / iVar9,uVar7,dVar19,iVar14);
      uVar10 = *(uint *)(pcVar15 + -0x5750);
    }
    iVar17 = 1;
    if ((uVar10 & 2) == 0) goto LAB_00458374;
    (*(code *)PTR_puts_006a9a54)("\n\nNow timing with session id reuse.");
    param_2 = (char *)doConnection(0);
    if ((uint *)param_2 != (uint *)0x0) {
      if (s_www_path != (uint *)0x0) {
        (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_20fc,0x2000,"GET %s HTTP/1.0\r\n\r\n");
        uVar7 = (*(code *)PTR_strlen_006a9a24)(auStack_20fc);
        (*(code *)PTR_SSL_write_006a7820)(param_2,auStack_20fc,uVar7);
        do {
          iVar17 = (*(code *)PTR_SSL_read_006a7818)(param_2,auStack_20fc,0x2000);
        } while (0 < iVar17);
      }
      puVar5 = PTR_stdout_006a99c8;
      (*(code *)PTR_SSL_set_shutdown_006a780c)(param_2,3);
      iVar14 = 0;
      pcVar15 = "GET %s HTTP/1.0\r\n\r\n";
      uVar7 = (*(code *)PTR_SSL_get_fd_006a79c0)(param_2);
      (*(code *)PTR_shutdown_006a995c)(uVar7,2);
      uVar7 = (*(code *)PTR_SSL_get_fd_006a79c0)(param_2);
      (*(code *)PTR_close_006a994c)(uVar7);
      iVar9 = (*(code *)PTR_time_006a9adc)(0);
      iVar9 = iVar9 + maxTime;
      (*(code *)PTR_puts_006a9a54)("starting");
      bytes_read = 0;
      app_tminterval(0,1);
      while (iVar17 = (*(code *)PTR_time_006a9adc)(0), iVar17 <= iVar9) {
        iVar17 = doConnection(param_2);
        if (iVar17 == 0) {
          iVar17 = 1;
          goto LAB_00458e4c;
        }
        if (s_www_path != (uint *)0x0) {
          (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_20fc,0x2000,"GET %s HTTP/1.0\r\n\r\n");
          uVar7 = (*(code *)PTR_strlen_006a9a24)(auStack_20fc);
          (*(code *)PTR_SSL_write_006a7820)(param_2,auStack_20fc,uVar7);
          while (iVar17 = (*(code *)PTR_SSL_read_006a7818)(param_2,auStack_20fc,0x2000), 0 < iVar17)
          {
            bytes_read = bytes_read + iVar17;
          }
        }
        iVar14 = iVar14 + 1;
        (*(code *)PTR_SSL_set_shutdown_006a780c)(param_2,3);
        uVar7 = (*(code *)PTR_SSL_get_fd_006a79c0)(param_2);
        (*(code *)PTR_shutdown_006a995c)(uVar7,2);
        uVar7 = (*(code *)PTR_SSL_get_fd_006a79c0)(param_2);
        (*(code *)PTR_close_006a994c)(uVar7);
        iVar17 = (*(code *)PTR_SSL_ctrl_006a7788)(param_2,8,0,0);
        if (iVar17 == 0) {
          iVar17 = (*(code *)PTR_SSL_version_006a77ec)(param_2);
          if (iVar17 == 0x301) {
            uVar7 = 0x74;
          }
          else if (iVar17 == 0x300) {
            uVar7 = 0x33;
          }
          else {
            uVar7 = 0x2a;
            if (iVar17 == 2) {
              uVar7 = 0x32;
            }
          }
        }
        else {
          uVar7 = 0x72;
        }
        (*(code *)PTR_fputc_006a99a4)(uVar7,*(undefined4 *)puVar5);
        (*(code *)PTR_fflush_006a9b04)(*(undefined4 *)puVar5);
      }
      dVar18 = (double)app_tminterval(1,1);
      dVar18 = dVar18 + 0.0;
      dVar19 = (double)iVar14 / dVar18;
      iVar20 = bytes_read;
      (*(code *)PTR___printf_chk_006a99c4)
                (1,"\n\n%d connections in %.2fs; %.2f connections/user sec, bytes read %ld\n",iVar14
                );
      uVar7 = SUB84(dVar18,0);
      iVar12 = (*(code *)PTR_time_006a9adc)(0);
      iVar11 = 1;
      if (iVar14 != 0) {
        iVar11 = iVar14;
      }
      iVar17 = 0;
      if (iVar11 == 0) {
        trap(7);
      }
      (*(code *)PTR___printf_chk_006a99c4)
                (1,"%d connections in %ld real seconds, %ld bytes read per connection\n",iVar14,
                 (iVar12 - iVar9) + maxTime,bytes_read / iVar11,uVar7,dVar19,iVar20);
LAB_00458e4c:
      (*(code *)PTR_SSL_free_006a7810)(param_2);
      goto LAB_00458374;
    }
    (*(code *)PTR_fwrite_006a9a74)
              ("Unable to get connection\n",1,0x19,*(undefined4 *)PTR_stderr_006a9af8);
  }
LAB_00458370:
  iVar17 = 1;
LAB_00458374:
  if (tm_ctx == 0) goto LAB_004583a0;
  do {
    (*(code *)PTR_SSL_CTX_free_006a7890)();
    tm_ctx = 0;
LAB_004583a0:
    while( true ) {
      if (iStack_fc == *(int *)puVar6) {
        return iVar17;
      }
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00458fb8:
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,"unknown option %s\n",param_2);
      if (*(int *)(pcVar15 + -0x5750) == 0) {
        bVar2 = true;
        *(undefined4 *)(pcVar15 + -0x5750) = 3;
        goto LAB_004582d0;
      }
LAB_00458534:
      iVar17 = 1;
      (*(code *)PTR_puts_006a9a54)("usage: s_time <args>\n");
      (*(code *)PTR___printf_chk_006a99c4)
                (1,"-connect host:port - host:port to connect to (default is %s)\n","localhost:4433"
                );
      (*(code *)PTR_puts_006a9a54)("-nbio         - Run with non-blocking IO");
      (*(code *)PTR_puts_006a9a54)("-ssl2         - Just use SSLv2");
      (*(code *)PTR_puts_006a9a54)("-ssl3         - Just use SSLv3");
      (*(code *)PTR_puts_006a9a54)("-bugs         - Turn on SSL bug compatibility");
      (*(code *)PTR_puts_006a9a54)("-new          - Just time new connections");
      (*(code *)PTR_puts_006a9a54)("-reuse        - Just time connection reuse");
      (*(code *)PTR_puts_006a9a54)("-www page     - Retrieve \'page\' from the site");
      (*(code *)PTR___printf_chk_006a99c4)
                (1,
                 "-time arg     - max number of seconds to collect data, default %d\n-verify arg   - turn on peer certificate verification, arg == depth\n-cert arg     - certificate file to use, PEM format assumed\n-key arg      - RSA file to use, PEM format assumed, key is in cert file\n                file if not specified by this option\n-CApath arg   - PEM format directory of CA\'s\n-CAfile arg   - PEM format file of CA\'s\n-cipher       - preferred cipher to use, play with \'openssl ciphers\'\n\n"
                 ,0x1e);
      if (tm_ctx != 0) break;
      iVar17 = 1;
    }
  } while( true );
}

