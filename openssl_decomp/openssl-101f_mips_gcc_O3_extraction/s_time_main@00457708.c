
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 s_time_main(int param_1,undefined1 *param_2)

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
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  char *pcVar14;
  undefined4 *puVar15;
  double dVar16;
  double dVar17;
  undefined1 *local_2034;
  undefined auStack_202c [8192];
  int local_2c;
  
  puVar6 = PTR___stack_chk_guard_006aabf0;
  puVar4 = PTR_bio_err_006a7f3c;
  pcVar14 = &_ITM_registerTMCloneTable;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  bytes_read = 0;
  t_key_file = 0;
  host = s_localhost_4433_0063fae0;
  CApath = 0;
  tm_cipher = 0;
  local_2034 = (undefined1 *)0x6a0000;
  t_cert_file = 0;
  perform = 0;
  CAfile = 0;
  tm_ctx = 0;
  s_time_meth = 0;
  maxTime = 0x1e;
  s_www_path = 0;
  st_bugs = 0;
  if (*(int *)puVar4 == 0) {
    uVar12 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stderr_006aac00,0);
    *(undefined4 *)puVar4 = uVar12;
  }
  puVar5 = PTR_verify_depth_006a897c;
  param_1 = param_1 + -1;
  puVar15 = (undefined4 *)(param_2 + 4);
  s_time_meth = (*(code *)PTR_SSLv23_client_method_006a8a70)();
  *(undefined4 *)puVar5 = 0;
  *(undefined4 *)PTR_verify_error_006a8a74 = 0;
  if (param_1 < 1) {
    if (perform != 0) goto LAB_00457930;
    bVar2 = false;
  }
  else {
    bVar2 = false;
    do {
      while( true ) {
        param_2 = (undefined1 *)*puVar15;
        iVar7 = (*(code *)PTR_strcmp_006aac20)(param_2,"-connect");
        if (iVar7 == 0) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_00457b84;
          host = (undefined *)puVar15[1];
          puVar15 = puVar15 + 1;
          goto LAB_004578c0;
        }
        iVar7 = (*(code *)PTR_strcmp_006aac20)(param_2,"-reuse");
        if (iVar7 == 0) break;
        iVar7 = (*(code *)PTR_strcmp_006aac20)(param_2,&DAT_006330c4);
        if (iVar7 == 0) {
          perform = 1;
LAB_004578c0:
          param_1 = param_1 + -1;
        }
        else {
          iVar7 = (*(code *)PTR_strcmp_006aac20)(param_2,"-verify");
          if (iVar7 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_00457b84;
            puVar1 = puVar15 + 1;
            puVar15 = puVar15 + 1;
            uVar12 = (*(code *)PTR_strtol_006aaa68)(*puVar1,0,10);
            puVar3 = PTR_BIO_printf_006a7f38;
            uVar11 = *(undefined4 *)puVar4;
            *(undefined4 *)puVar5 = uVar12;
            (*(code *)puVar3)(uVar11,"verify depth is %d\n",uVar12);
            goto LAB_004578c0;
          }
          iVar7 = (*(code *)PTR_strcmp_006aac20)(param_2,"-cert");
          if (iVar7 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_00457b84;
            t_cert_file = puVar15[1];
            puVar15 = puVar15 + 1;
            goto LAB_004578c0;
          }
          iVar7 = (*(code *)PTR_strcmp_006aac20)(param_2,&DAT_006330b4);
          if (iVar7 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_00457b84;
            t_key_file = puVar15[1];
            puVar15 = puVar15 + 1;
            goto LAB_004578c0;
          }
          iVar7 = (*(code *)PTR_strcmp_006aac20)(param_2,"-CApath");
          if (iVar7 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_00457b84;
            CApath = puVar15[1];
            puVar15 = puVar15 + 1;
            goto LAB_004578c0;
          }
          iVar7 = (*(code *)PTR_strcmp_006aac20)(param_2,"-CAfile");
          if (iVar7 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_00457b84;
            CAfile = puVar15[1];
            puVar15 = puVar15 + 1;
            goto LAB_004578c0;
          }
          iVar7 = (*(code *)PTR_strcmp_006aac20)(param_2,"-cipher");
          if (iVar7 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_00457b84;
            tm_cipher = puVar15[1];
            puVar15 = puVar15 + 1;
            goto LAB_004578c0;
          }
          iVar7 = (*(code *)PTR_strcmp_006aac20)(param_2,"-nbio");
          if (iVar7 == 0) goto LAB_004578c0;
          iVar7 = (*(code *)PTR_strcmp_006aac20)(param_2,&DAT_0063bff4);
          if (iVar7 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_00457b84;
            s_www_path = puVar15[1];
            puVar15 = puVar15 + 1;
            uVar8 = (*(code *)PTR_strlen_006aab30)(s_www_path);
            if (0x1f9c < uVar8) {
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar4,"-www option too long\n");
              bVar2 = true;
            }
            goto LAB_004578c0;
          }
          iVar7 = (*(code *)PTR_strcmp_006aac20)(param_2,"-bugs");
          if (iVar7 == 0) {
            st_bugs = 1;
            goto LAB_004578c0;
          }
          iVar7 = (*(code *)PTR_strcmp_006aac20)(param_2,"-ssl2");
          if (iVar7 == 0) {
            param_1 = param_1 + -1;
            s_time_meth = (*(code *)PTR_SSLv2_client_method_006a8ac8)();
          }
          else {
            iVar7 = (*(code *)PTR_strcmp_006aac20)(param_2,"-ssl3");
            if (iVar7 != 0) {
              iVar7 = (*(code *)PTR_strcmp_006aac20)(param_2,"-time");
              if (iVar7 != 0) goto LAB_00458610;
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_00457b84;
              puVar1 = puVar15 + 1;
              puVar15 = puVar15 + 1;
              maxTime = (*(code *)PTR_strtol_006aaa68)(*puVar1,0,10);
              goto LAB_004578c0;
            }
            param_1 = param_1 + -1;
            s_time_meth = (*(code *)PTR_SSLv3_client_method_006a8acc)();
          }
        }
        puVar15 = puVar15 + 1;
        if (param_1 == 0) goto LAB_00457914;
      }
      param_1 = param_1 + -1;
      puVar15 = puVar15 + 1;
      perform = 2;
    } while (param_1 != 0);
LAB_00457914:
    if (perform != 0) goto LAB_00457920;
  }
  perform = 3;
LAB_00457920:
  if (bVar2) goto LAB_00457b84;
LAB_00457930:
  (*(code *)PTR_SSL_library_init_006a8980)();
  tm_ctx = (*(code *)PTR_SSL_CTX_new_006a8988)(s_time_meth);
  if (tm_ctx == 0) {
    uVar12 = 1;
    goto LAB_004579f0;
  }
  (*(code *)PTR_SSL_CTX_set_quiet_shutdown_006a8990)(tm_ctx,1);
  if (st_bugs != 0) {
    (*(code *)PTR_SSL_CTX_ctrl_006a884c)(tm_ctx,0x20,0x80000bff,0);
  }
  param_2 = &_ITM_registerTMCloneTable;
  (*(code *)PTR_SSL_CTX_set_cipher_list_006a89bc)(tm_ctx,tm_cipher);
  iVar7 = set_cert_stuff(tm_ctx,t_cert_file,t_key_file);
  if (iVar7 != 0) {
    (*(code *)PTR_SSL_load_error_strings_006a867c)();
    iVar7 = (*(code *)PTR_SSL_CTX_load_verify_locations_006a8998)(tm_ctx,CAfile,CApath);
    if ((iVar7 == 0) ||
       (iVar7 = (*(code *)PTR_SSL_CTX_set_default_verify_paths_006a899c)(tm_ctx), iVar7 == 0)) {
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar4);
    }
    if ((tm_cipher == 0) &&
       (tm_cipher = (*(code *)PTR_getenv_006aab6c)("SSL_CIPHER"), tm_cipher == 0)) {
      (*(code *)PTR_fwrite_006aab7c)
                ("No CIPHER specified\n",1,0x14,*(undefined4 *)PTR_stderr_006aac00);
    }
    puVar5 = PTR_stdout_006aaad4;
    uVar8 = *(uint *)(pcVar14 + -0x4640);
    if ((uVar8 & 1) != 0) {
      iVar13 = 0;
      (*(code *)PTR___printf_chk_006aaad0)
                (1,"Collecting connection statistics for %d seconds\n",maxTime);
      bytes_read = 0;
      iVar7 = (*(code *)PTR_time_006aabe4)(0);
      iVar7 = iVar7 + maxTime;
      app_tminterval(0,1);
      param_2 = local_2034;
      while (iVar9 = (*(code *)PTR_time_006aabe4)(0), iVar9 <= iVar7) {
        param_2 = (undefined1 *)doConnection(0);
        if (param_2 == (undefined1 *)0x0) goto LAB_004579c0;
        if (s_www_path != 0) {
          (*(code *)PTR_BIO_snprintf_006a8060)(auStack_202c,0x2000,"GET %s HTTP/1.0\r\n\r\n");
          uVar12 = (*(code *)PTR_strlen_006aab30)(auStack_202c);
          (*(code *)PTR_SSL_write_006a890c)(param_2,auStack_202c,uVar12);
          while (iVar9 = (*(code *)PTR_SSL_read_006a8904)(param_2,auStack_202c,0x2000), 0 < iVar9) {
            bytes_read = bytes_read + iVar9;
          }
        }
        iVar13 = iVar13 + 1;
        (*(code *)PTR_SSL_set_shutdown_006a88f8)(param_2,3);
        uVar12 = (*(code *)PTR_SSL_get_fd_006a8aac)(param_2);
        (*(code *)PTR_shutdown_006aaa6c)(uVar12,2);
        uVar12 = (*(code *)PTR_SSL_get_fd_006a8aac)(param_2);
        (*(code *)PTR_close_006aaa5c)(uVar12);
        iVar9 = (*(code *)PTR_SSL_ctrl_006a8878)(param_2,8,0,0);
        if (iVar9 == 0) {
          iVar9 = (*(code *)PTR_SSL_version_006a88d8)(param_2);
          if (iVar9 == 0x301) {
            uVar12 = 0x74;
          }
          else if (iVar9 == 0x300) {
            uVar12 = 0x33;
          }
          else {
            uVar12 = 0x2a;
            if (iVar9 == 2) {
              uVar12 = 0x32;
            }
          }
        }
        else {
          uVar12 = 0x72;
        }
        (*(code *)PTR_fputc_006aaab0)(uVar12,*(undefined4 *)puVar5);
        (*(code *)PTR_fflush_006aac0c)(*(undefined4 *)puVar5);
        (*(code *)PTR_SSL_free_006a88fc)(param_2);
      }
      dVar16 = (double)app_tminterval(1,1);
      dVar16 = dVar16 + 0.0;
      (*(code *)PTR_time_006aabe4)(0);
      dVar17 = (double)iVar13 / dVar16;
      iVar9 = bytes_read;
      (*(code *)PTR___printf_chk_006aaad0)
                (1,"\n\n%d connections in %.2fs; %.2f connections/user sec, bytes read %ld\n",iVar13
                );
      uVar12 = SUB84(dVar16,0);
      iVar10 = (*(code *)PTR_time_006aabe4)(0);
      if (iVar13 == 0) {
        trap(7);
      }
      (*(code *)PTR___printf_chk_006aaad0)
                (1,"%d connections in %ld real seconds, %ld bytes read per connection\n",iVar13,
                 (iVar10 - iVar7) + maxTime,bytes_read / iVar13,uVar12,dVar17,iVar9);
      uVar8 = *(uint *)(pcVar14 + -0x4640);
    }
    uVar12 = 1;
    if ((uVar8 & 2) == 0) goto LAB_004579c4;
    (*(code *)PTR_puts_006aab60)("\n\nNow timing with session id reuse.");
    param_2 = (undefined1 *)doConnection(0);
    if (param_2 != (undefined1 *)0x0) {
      if (s_www_path != 0) {
        (*(code *)PTR_BIO_snprintf_006a8060)(auStack_202c,0x2000,"GET %s HTTP/1.0\r\n\r\n");
        uVar12 = (*(code *)PTR_strlen_006aab30)(auStack_202c);
        (*(code *)PTR_SSL_write_006a890c)(param_2,auStack_202c,uVar12);
        do {
          iVar7 = (*(code *)PTR_SSL_read_006a8904)(param_2,auStack_202c,0x2000);
        } while (0 < iVar7);
      }
      puVar5 = PTR_stdout_006aaad4;
      (*(code *)PTR_SSL_set_shutdown_006a88f8)(param_2,3);
      iVar13 = 0;
      pcVar14 = "GET %s HTTP/1.0\r\n\r\n";
      uVar12 = (*(code *)PTR_SSL_get_fd_006a8aac)(param_2);
      (*(code *)PTR_shutdown_006aaa6c)(uVar12,2);
      uVar12 = (*(code *)PTR_SSL_get_fd_006a8aac)(param_2);
      (*(code *)PTR_close_006aaa5c)(uVar12);
      iVar7 = (*(code *)PTR_time_006aabe4)(0);
      iVar7 = iVar7 + maxTime;
      (*(code *)PTR_puts_006aab60)("starting");
      bytes_read = 0;
      app_tminterval(0,1);
      while (iVar9 = (*(code *)PTR_time_006aabe4)(0), iVar9 <= iVar7) {
        iVar9 = doConnection(param_2);
        if (iVar9 == 0) {
          uVar12 = 1;
          goto LAB_00458494;
        }
        if (s_www_path != 0) {
          (*(code *)PTR_BIO_snprintf_006a8060)(auStack_202c,0x2000,"GET %s HTTP/1.0\r\n\r\n");
          uVar12 = (*(code *)PTR_strlen_006aab30)(auStack_202c);
          (*(code *)PTR_SSL_write_006a890c)(param_2,auStack_202c,uVar12);
          while (iVar9 = (*(code *)PTR_SSL_read_006a8904)(param_2,auStack_202c,0x2000), 0 < iVar9) {
            bytes_read = bytes_read + iVar9;
          }
        }
        iVar13 = iVar13 + 1;
        (*(code *)PTR_SSL_set_shutdown_006a88f8)(param_2,3);
        uVar12 = (*(code *)PTR_SSL_get_fd_006a8aac)(param_2);
        (*(code *)PTR_shutdown_006aaa6c)(uVar12,2);
        uVar12 = (*(code *)PTR_SSL_get_fd_006a8aac)(param_2);
        (*(code *)PTR_close_006aaa5c)(uVar12);
        iVar9 = (*(code *)PTR_SSL_ctrl_006a8878)(param_2,8,0,0);
        if (iVar9 == 0) {
          iVar9 = (*(code *)PTR_SSL_version_006a88d8)(param_2);
          if (iVar9 == 0x301) {
            uVar12 = 0x74;
          }
          else if (iVar9 == 0x300) {
            uVar12 = 0x33;
          }
          else {
            uVar12 = 0x2a;
            if (iVar9 == 2) {
              uVar12 = 0x32;
            }
          }
        }
        else {
          uVar12 = 0x72;
        }
        (*(code *)PTR_fputc_006aaab0)(uVar12,*(undefined4 *)puVar5);
        (*(code *)PTR_fflush_006aac0c)(*(undefined4 *)puVar5);
      }
      dVar16 = (double)app_tminterval(1,1);
      dVar16 = dVar16 + 0.0;
      dVar17 = (double)iVar13 / dVar16;
      iVar9 = bytes_read;
      (*(code *)PTR___printf_chk_006aaad0)
                (1,"\n\n%d connections in %.2fs; %.2f connections/user sec, bytes read %ld\n",iVar13
                );
      uVar11 = SUB84(dVar16,0);
      iVar10 = (*(code *)PTR_time_006aabe4)(0);
      if (iVar13 == 0) {
        trap(7);
      }
      uVar12 = 0;
      (*(code *)PTR___printf_chk_006aaad0)
                (1,"%d connections in %ld real seconds, %ld bytes read per connection\n",iVar13,
                 (iVar10 - iVar7) + maxTime,bytes_read / iVar13,uVar11,dVar17,iVar9);
LAB_00458494:
      (*(code *)PTR_SSL_free_006a88fc)(param_2);
      goto LAB_004579c4;
    }
    (*(code *)PTR_fwrite_006aab7c)
              ("Unable to get connection\n",1,0x19,*(undefined4 *)PTR_stderr_006aac00);
  }
LAB_004579c0:
  uVar12 = 1;
LAB_004579c4:
  if (tm_ctx == 0) goto LAB_004579f0;
  do {
    (*(code *)PTR_SSL_CTX_free_006a8978)();
    tm_ctx = 0;
LAB_004579f0:
    while( true ) {
      if (local_2c == *(int *)puVar6) {
        return uVar12;
      }
      (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00458610:
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar4,"unknown option %s\n",param_2);
      if (*(int *)(pcVar14 + -0x4640) == 0) {
        bVar2 = true;
        *(undefined4 *)(pcVar14 + -0x4640) = 3;
        goto LAB_00457920;
      }
LAB_00457b84:
      uVar12 = 1;
      (*(code *)PTR_puts_006aab60)("usage: s_time <args>\n");
      (*(code *)PTR___printf_chk_006aaad0)
                (1,"-connect host:port - host:port to connect to (default is %s)\n","localhost:4433"
                );
      (*(code *)PTR_puts_006aab60)("-nbio         - Run with non-blocking IO");
      (*(code *)PTR_puts_006aab60)("-ssl2         - Just use SSLv2");
      (*(code *)PTR_puts_006aab60)("-ssl3         - Just use SSLv3");
      (*(code *)PTR_puts_006aab60)("-bugs         - Turn on SSL bug compatibility");
      (*(code *)PTR_puts_006aab60)("-new          - Just time new connections");
      (*(code *)PTR_puts_006aab60)("-reuse        - Just time connection reuse");
      (*(code *)PTR_puts_006aab60)("-www page     - Retrieve \'page\' from the site");
      (*(code *)PTR___printf_chk_006aaad0)
                (1,
                 "-time arg     - max number of seconds to collect data, default %d\n-verify arg   - turn on peer certificate verification, arg == depth\n-cert arg     - certificate file to use, PEM format assumed\n-key arg      - RSA file to use, PEM format assumed, key is in cert file\n                file if not specified by this option\n-CApath arg   - PEM format directory of CA\'s\n-CAfile arg   - PEM format file of CA\'s\n-cipher       - preferred cipher to use, play with \'openssl ciphers\'\n\n"
                 ,0x1e);
      if (tm_ctx != 0) break;
      uVar12 = 1;
    }
  } while( true );
}

