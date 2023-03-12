
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 s_time_main(int param_1,undefined *param_2)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  char *pcVar15;
  undefined4 *puVar16;
  double dVar17;
  double dVar18;
  undefined *local_2034;
  undefined auStack_202c [8192];
  int local_2c;
  
  puVar6 = PTR___stack_chk_guard_006a9ae8;
  puVar4 = PTR_bio_err_006a6e3c;
  pcVar15 = &_gp_1;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  bytes_read = 0;
  t_key_file = 0;
  host = s_localhost_4433_0063f540;
  CApath = 0;
  tm_cipher = 0;
  local_2034 = (undefined *)0x6a0000;
  t_cert_file = 0;
  perform = 0;
  CAfile = 0;
  tm_ctx = 0;
  s_time_meth = 0;
  maxTime = 0x1e;
  s_www_path = 0;
  st_bugs = 0;
  if (*(int *)puVar4 == 0) {
    uVar13 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stderr_006a9af8,0);
    *(undefined4 *)puVar4 = uVar13;
  }
  puVar5 = PTR_verify_depth_006a7894;
  param_1 = param_1 + -1;
  puVar16 = (undefined4 *)(param_2 + 4);
  s_time_meth = (*(code *)PTR_SSLv23_client_method_006a7984)();
  *(undefined4 *)puVar5 = 0;
  *(undefined4 *)PTR_verify_error_006a7988 = 0;
  if (param_1 < 1) {
    if (perform != 0) goto LAB_004582e0;
    bVar2 = false;
  }
  else {
    bVar2 = false;
    do {
      while( true ) {
        param_2 = (undefined *)*puVar16;
        iVar7 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-connect");
        if (iVar7 != 0) break;
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_00458534;
        host = (undefined *)puVar16[1];
        puVar16 = puVar16 + 1;
LAB_00458274:
        param_1 = param_1 + -1;
        puVar16 = puVar16 + 1;
        if (param_1 == 0) goto LAB_004582c4;
      }
      iVar7 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-reuse");
      if (iVar7 != 0) {
        iVar7 = (*(code *)PTR_strcmp_006a9b18)(param_2,&DAT_006326fc);
        if (iVar7 == 0) {
          perform = 1;
        }
        else {
          iVar7 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-verify");
          if (iVar7 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_00458534;
            puVar1 = puVar16 + 1;
            puVar16 = puVar16 + 1;
            uVar13 = (*(code *)PTR_strtol_006a9958)(*puVar1,0,10);
            puVar3 = PTR_BIO_printf_006a6e38;
            uVar12 = *(undefined4 *)puVar4;
            *(undefined4 *)puVar5 = uVar13;
            (*(code *)puVar3)(uVar12,"verify depth is %d\n",uVar13);
          }
          else {
            iVar7 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-cert");
            if (iVar7 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_00458534;
              t_cert_file = puVar16[1];
              puVar16 = puVar16 + 1;
            }
            else {
              iVar7 = (*(code *)PTR_strcmp_006a9b18)(param_2,&DAT_006326ec);
              if (iVar7 == 0) {
                param_1 = param_1 + -1;
                if (param_1 == 0) goto LAB_00458534;
                t_key_file = puVar16[1];
                puVar16 = puVar16 + 1;
              }
              else {
                iVar7 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-CApath");
                if (iVar7 == 0) {
                  param_1 = param_1 + -1;
                  if (param_1 == 0) goto LAB_00458534;
                  CApath = puVar16[1];
                  puVar16 = puVar16 + 1;
                }
                else {
                  iVar7 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-CAfile");
                  if (iVar7 == 0) {
                    param_1 = param_1 + -1;
                    if (param_1 == 0) goto LAB_00458534;
                    CAfile = puVar16[1];
                    puVar16 = puVar16 + 1;
                  }
                  else {
                    iVar7 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-cipher");
                    if (iVar7 == 0) {
                      param_1 = param_1 + -1;
                      if (param_1 == 0) goto LAB_00458534;
                      tm_cipher = puVar16[1];
                      puVar16 = puVar16 + 1;
                    }
                    else {
                      iVar7 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-nbio");
                      if (iVar7 != 0) {
                        iVar7 = (*(code *)PTR_strcmp_006a9b18)(param_2,&DAT_0063b810);
                        if (iVar7 == 0) {
                          param_1 = param_1 + -1;
                          if (param_1 == 0) goto LAB_00458534;
                          s_www_path = puVar16[1];
                          puVar16 = puVar16 + 1;
                          uVar8 = (*(code *)PTR_strlen_006a9a24)(s_www_path);
                          if (0x1f9c < uVar8) {
                            (*(code *)PTR_BIO_printf_006a6e38)
                                      (*(undefined4 *)puVar4,"-www option too long\n");
                            bVar2 = true;
                          }
                        }
                        else {
                          iVar7 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-bugs");
                          if (iVar7 == 0) {
                            st_bugs = 1;
                          }
                          else {
                            iVar7 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-ssl3");
                            if (iVar7 == 0) {
                              s_time_meth = (*(code *)PTR_SSLv3_client_method_006a79d8)();
                            }
                            else {
                              iVar7 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-time");
                              if (iVar7 != 0) goto LAB_00458fb8;
                              param_1 = param_1 + -1;
                              if (param_1 == 0) goto LAB_00458534;
                              puVar1 = puVar16 + 1;
                              puVar16 = puVar16 + 1;
                              maxTime = (*(code *)PTR_strtol_006a9958)(*puVar1,0,10);
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
      param_1 = param_1 + -1;
      puVar16 = puVar16 + 1;
      perform = 2;
    } while (param_1 != 0);
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
    uVar13 = 1;
    goto LAB_004583a0;
  }
  (*(code *)PTR_SSL_CTX_set_quiet_shutdown_006a78a8)(tm_ctx,1);
  if (st_bugs != 0) {
    (*(code *)PTR_SSL_CTX_ctrl_006a775c)(tm_ctx,0x20,0x80000bff,0);
  }
  param_2 = &_gp_1;
  (*(code *)PTR_SSL_CTX_set_cipher_list_006a78d4)(tm_ctx,tm_cipher);
  iVar7 = set_cert_stuff(tm_ctx,t_cert_file,t_key_file);
  if (iVar7 != 0) {
    (*(code *)PTR_SSL_load_error_strings_006a7588)();
    iVar7 = (*(code *)PTR_SSL_CTX_load_verify_locations_006a78b0)(tm_ctx,CAfile,CApath);
    if ((iVar7 == 0) ||
       (iVar7 = (*(code *)PTR_SSL_CTX_set_default_verify_paths_006a78b4)(tm_ctx), iVar7 == 0)) {
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
    }
    if ((tm_cipher == 0) &&
       (tm_cipher = (*(code *)PTR_getenv_006a9a60)("SSL_CIPHER"), tm_cipher == 0)) {
      (*(code *)PTR_fwrite_006a9a74)
                ("No CIPHER specified\n",1,0x14,*(undefined4 *)PTR_stderr_006a9af8);
    }
    puVar5 = PTR_stdout_006a99c8;
    uVar8 = *(uint *)(pcVar15 + -0x5750);
    if ((uVar8 & 1) != 0) {
      iVar14 = 0;
      (*(code *)PTR___printf_chk_006a99c4)
                (1,"Collecting connection statistics for %d seconds\n",maxTime);
      bytes_read = 0;
      iVar7 = (*(code *)PTR_time_006a9adc)(0);
      iVar7 = iVar7 + maxTime;
      app_tminterval(0,1);
      param_2 = local_2034;
      while (iVar9 = (*(code *)PTR_time_006a9adc)(0), iVar9 <= iVar7) {
        param_2 = (undefined *)doConnection(0);
        if (param_2 == (undefined *)0x0) goto LAB_00458370;
        if (s_www_path != 0) {
          (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_202c,0x2000,"GET %s HTTP/1.0\r\n\r\n");
          uVar13 = (*(code *)PTR_strlen_006a9a24)(auStack_202c);
          (*(code *)PTR_SSL_write_006a7820)(param_2,auStack_202c,uVar13);
          while (iVar9 = (*(code *)PTR_SSL_read_006a7818)(param_2,auStack_202c,0x2000), 0 < iVar9) {
            bytes_read = bytes_read + iVar9;
          }
        }
        iVar14 = iVar14 + 1;
        (*(code *)PTR_SSL_set_shutdown_006a780c)(param_2,3);
        uVar13 = (*(code *)PTR_SSL_get_fd_006a79c0)(param_2);
        (*(code *)PTR_shutdown_006a995c)(uVar13,2);
        uVar13 = (*(code *)PTR_SSL_get_fd_006a79c0)(param_2);
        (*(code *)PTR_close_006a994c)(uVar13);
        iVar9 = (*(code *)PTR_SSL_ctrl_006a7788)(param_2,8,0,0);
        if (iVar9 == 0) {
          iVar9 = (*(code *)PTR_SSL_version_006a77ec)(param_2);
          if (iVar9 == 0x301) {
            uVar13 = 0x74;
          }
          else if (iVar9 == 0x300) {
            uVar13 = 0x33;
          }
          else {
            uVar13 = 0x2a;
            if (iVar9 == 2) {
              uVar13 = 0x32;
            }
          }
        }
        else {
          uVar13 = 0x72;
        }
        (*(code *)PTR_fputc_006a99a4)(uVar13,*(undefined4 *)puVar5);
        (*(code *)PTR_fflush_006a9b04)(*(undefined4 *)puVar5);
        (*(code *)PTR_SSL_free_006a7810)(param_2);
      }
      dVar17 = (double)app_tminterval(1,1);
      dVar17 = dVar17 + 0.0;
      (*(code *)PTR_time_006a9adc)(0);
      dVar18 = (double)iVar14 / dVar17;
      iVar9 = bytes_read;
      (*(code *)PTR___printf_chk_006a99c4)
                (1,"\n\n%d connections in %.2fs; %.2f connections/user sec, bytes read %ld\n",iVar14
                );
      uVar13 = SUB84(dVar17,0);
      iVar10 = (*(code *)PTR_time_006a9adc)(0);
      if (iVar14 == 0) {
        trap(7);
      }
      (*(code *)PTR___printf_chk_006a99c4)
                (1,"%d connections in %ld real seconds, %ld bytes read per connection\n",iVar14,
                 (iVar10 - iVar7) + maxTime,bytes_read / iVar14,uVar13,dVar18,iVar9);
      uVar8 = *(uint *)(pcVar15 + -0x5750);
    }
    uVar13 = 1;
    if ((uVar8 & 2) == 0) goto LAB_00458374;
    (*(code *)PTR_puts_006a9a54)("\n\nNow timing with session id reuse.");
    param_2 = (undefined *)doConnection(0);
    if (param_2 != (undefined *)0x0) {
      if (s_www_path != 0) {
        (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_202c,0x2000,"GET %s HTTP/1.0\r\n\r\n");
        uVar13 = (*(code *)PTR_strlen_006a9a24)(auStack_202c);
        (*(code *)PTR_SSL_write_006a7820)(param_2,auStack_202c,uVar13);
        do {
          iVar7 = (*(code *)PTR_SSL_read_006a7818)(param_2,auStack_202c,0x2000);
        } while (0 < iVar7);
      }
      puVar5 = PTR_stdout_006a99c8;
      (*(code *)PTR_SSL_set_shutdown_006a780c)(param_2,3);
      iVar14 = 0;
      pcVar15 = "GET %s HTTP/1.0\r\n\r\n";
      uVar13 = (*(code *)PTR_SSL_get_fd_006a79c0)(param_2);
      (*(code *)PTR_shutdown_006a995c)(uVar13,2);
      uVar13 = (*(code *)PTR_SSL_get_fd_006a79c0)(param_2);
      (*(code *)PTR_close_006a994c)(uVar13);
      iVar7 = (*(code *)PTR_time_006a9adc)(0);
      iVar7 = iVar7 + maxTime;
      (*(code *)PTR_puts_006a9a54)("starting");
      bytes_read = 0;
      app_tminterval(0,1);
      while (iVar9 = (*(code *)PTR_time_006a9adc)(0), iVar9 <= iVar7) {
        iVar9 = doConnection(param_2);
        if (iVar9 == 0) {
          uVar13 = 1;
          goto LAB_00458e4c;
        }
        if (s_www_path != 0) {
          (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_202c,0x2000,"GET %s HTTP/1.0\r\n\r\n");
          uVar13 = (*(code *)PTR_strlen_006a9a24)(auStack_202c);
          (*(code *)PTR_SSL_write_006a7820)(param_2,auStack_202c,uVar13);
          while (iVar9 = (*(code *)PTR_SSL_read_006a7818)(param_2,auStack_202c,0x2000), 0 < iVar9) {
            bytes_read = bytes_read + iVar9;
          }
        }
        iVar14 = iVar14 + 1;
        (*(code *)PTR_SSL_set_shutdown_006a780c)(param_2,3);
        uVar13 = (*(code *)PTR_SSL_get_fd_006a79c0)(param_2);
        (*(code *)PTR_shutdown_006a995c)(uVar13,2);
        uVar13 = (*(code *)PTR_SSL_get_fd_006a79c0)(param_2);
        (*(code *)PTR_close_006a994c)(uVar13);
        iVar9 = (*(code *)PTR_SSL_ctrl_006a7788)(param_2,8,0,0);
        if (iVar9 == 0) {
          iVar9 = (*(code *)PTR_SSL_version_006a77ec)(param_2);
          if (iVar9 == 0x301) {
            uVar13 = 0x74;
          }
          else if (iVar9 == 0x300) {
            uVar13 = 0x33;
          }
          else {
            uVar13 = 0x2a;
            if (iVar9 == 2) {
              uVar13 = 0x32;
            }
          }
        }
        else {
          uVar13 = 0x72;
        }
        (*(code *)PTR_fputc_006a99a4)(uVar13,*(undefined4 *)puVar5);
        (*(code *)PTR_fflush_006a9b04)(*(undefined4 *)puVar5);
      }
      dVar17 = (double)app_tminterval(1,1);
      dVar17 = dVar17 + 0.0;
      dVar18 = (double)iVar14 / dVar17;
      iVar10 = bytes_read;
      (*(code *)PTR___printf_chk_006a99c4)
                (1,"\n\n%d connections in %.2fs; %.2f connections/user sec, bytes read %ld\n",iVar14
                );
      uVar12 = SUB84(dVar17,0);
      iVar11 = (*(code *)PTR_time_006a9adc)(0);
      iVar9 = 1;
      if (iVar14 != 0) {
        iVar9 = iVar14;
      }
      uVar13 = 0;
      if (iVar9 == 0) {
        trap(7);
      }
      (*(code *)PTR___printf_chk_006a99c4)
                (1,"%d connections in %ld real seconds, %ld bytes read per connection\n",iVar14,
                 (iVar11 - iVar7) + maxTime,bytes_read / iVar9,uVar12,dVar18,iVar10);
LAB_00458e4c:
      (*(code *)PTR_SSL_free_006a7810)(param_2);
      goto LAB_00458374;
    }
    (*(code *)PTR_fwrite_006a9a74)
              ("Unable to get connection\n",1,0x19,*(undefined4 *)PTR_stderr_006a9af8);
  }
LAB_00458370:
  uVar13 = 1;
LAB_00458374:
  if (tm_ctx == 0) goto LAB_004583a0;
  do {
    (*(code *)PTR_SSL_CTX_free_006a7890)();
    tm_ctx = 0;
LAB_004583a0:
    while( true ) {
      if (local_2c == *(int *)puVar6) {
        return uVar13;
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
      uVar13 = 1;
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
      uVar13 = 1;
    }
  } while( true );
}

