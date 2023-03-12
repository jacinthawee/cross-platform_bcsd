
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
  
  puStack_e4 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar7 = (*(code *)PTR_BIO_s_connect_006a8be0)();
  puVar8 = (uint *)(*(code *)PTR_BIO_new_006a7fa4)(uVar7);
  iStack_f8 = unaff_s0;
  if (puVar8 == (uint *)0x0) {
LAB_004576ac:
    iVar17 = 0;
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a7f18)(puVar8,100,0,host);
    if (param_1 == 0) {
      iVar17 = (*(code *)PTR_SSL_new_006a88cc)(tm_ctx);
    }
    else {
      (*(code *)PTR_SSL_set_connect_state_006a8aa8)(param_1);
      iVar17 = param_1;
    }
    unaff_s6 = PTR_bio_err_006a7f3c;
    (*(code *)PTR_SSL_set_bio_006a88e4)(iVar17,puVar8,puVar8);
    unaff_s4 = "DELAY\n";
    unaff_s3 = 0x8000001f;
    while( true ) {
      unaff_s1 = (undefined *)(*(code *)PTR_SSL_connect_006a8be4)(iVar17);
      iVar9 = (*(code *)PTR_BIO_sock_should_retry_006a88c0)(unaff_s1);
      puVar4 = PTR_bio_err_006a7f3c;
      if (iVar9 == 0) break;
      puVar8 = auStack_ac;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)unaff_s6,"DELAY\n");
      unaff_s7 = (*(code *)PTR_SSL_get_fd_006a8aac)(iVar17);
      (*(code *)PTR_memset_006aab00)(puVar8,0,0x80);
      iVar9 = (*(code *)PTR___fdelt_chk_006aaba8)(unaff_s7);
      auStack_ac[iVar9] = 1 << (unaff_s7 & 0x1f) | auStack_ac[iVar9];
      (*(code *)PTR_select_006aabcc)(unaff_s7 + 1,puVar8,0,0);
    }
    param_2 = (char *)puVar8;
    iStack_f8 = iVar17;
    if ((int)unaff_s1 < 1) {
      param_2 = "ERROR\n";
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
      if (*(int *)PTR_verify_error_006a8a74 == 0) {
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar4);
        unaff_s1 = puVar4;
      }
      else {
        unaff_s1 = *(undefined **)puVar4;
        uVar7 = (*(code *)PTR_X509_verify_cert_error_string_006a839c)();
        param_2 = "verify error:%s\n";
        (*(code *)PTR_BIO_printf_006a7f38)(unaff_s1,"verify error:%s\n",uVar7);
      }
      if (param_1 == 0) {
        (*(code *)PTR_SSL_free_006a88fc)(iVar17);
      }
      goto LAB_004576ac;
    }
  }
  if (local_2c == *(int *)puStack_e4) {
    return iVar17;
  }
  iVar17 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar6 = PTR___stack_chk_guard_006aabf0;
  puVar4 = PTR_bio_err_006a7f3c;
  pcVar15 = &_ITM_registerTMCloneTable;
  iStack_fc = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_f4 = unaff_s1;
  iStack_f0 = param_1;
  uStack_ec = unaff_s3;
  pcStack_e8 = unaff_s4;
  puStack_e0 = unaff_s6;
  uStack_dc = unaff_s7;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  bytes_read = 0;
  t_key_file = (uint *)0x0;
  host = s_localhost_4433_0063fae0;
  CApath = (uint *)0x0;
  tm_cipher = (uint *)0x0;
  puStack_2104 = (uint *)(SSL_str_reasons + 0xc0);
  t_cert_file = (uint *)0x0;
  perform = 0;
  CAfile = (uint *)0x0;
  tm_ctx = 0;
  s_time_meth = 0;
  maxTime = 0x1e;
  s_www_path = (uint *)0x0;
  st_bugs = 0;
  if (*(int *)puVar4 == 0) {
    uVar7 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stderr_006aac00,0);
    *(undefined4 *)puVar4 = uVar7;
  }
  puVar5 = PTR_verify_depth_006a897c;
  iVar17 = iVar17 + -1;
  ppuVar16 = (uint **)((int)param_2 + 4);
  s_time_meth = (*(code *)PTR_SSLv23_client_method_006a8a70)();
  *(undefined4 *)puVar5 = 0;
  *(undefined4 *)PTR_verify_error_006a8a74 = 0;
  if (iVar17 < 1) {
    if (perform != 0) goto LAB_00457930;
    bVar2 = false;
  }
  else {
    bVar2 = false;
    do {
      while( true ) {
        param_2 = (char *)*ppuVar16;
        iVar9 = (*(code *)PTR_strcmp_006aac20)(param_2,"-connect");
        if (iVar9 == 0) {
          iVar17 = iVar17 + -1;
          if (iVar17 == 0) goto LAB_00457b84;
          host = (undefined *)ppuVar16[1];
          ppuVar16 = ppuVar16 + 1;
          goto LAB_004578c0;
        }
        iVar9 = (*(code *)PTR_strcmp_006aac20)(param_2,"-reuse");
        if (iVar9 == 0) break;
        iVar9 = (*(code *)PTR_strcmp_006aac20)(param_2,&DAT_006330c4);
        if (iVar9 == 0) {
          perform = 1;
LAB_004578c0:
          iVar17 = iVar17 + -1;
        }
        else {
          iVar9 = (*(code *)PTR_strcmp_006aac20)(param_2,"-verify");
          if (iVar9 == 0) {
            iVar17 = iVar17 + -1;
            if (iVar17 == 0) goto LAB_00457b84;
            ppuVar1 = ppuVar16 + 1;
            ppuVar16 = ppuVar16 + 1;
            uVar7 = (*(code *)PTR_strtol_006aaa68)(*ppuVar1,0,10);
            puVar3 = PTR_BIO_printf_006a7f38;
            uVar13 = *(undefined4 *)puVar4;
            *(undefined4 *)puVar5 = uVar7;
            (*(code *)puVar3)(uVar13,"verify depth is %d\n",uVar7);
            goto LAB_004578c0;
          }
          iVar9 = (*(code *)PTR_strcmp_006aac20)(param_2,"-cert");
          if (iVar9 == 0) {
            iVar17 = iVar17 + -1;
            if (iVar17 == 0) goto LAB_00457b84;
            t_cert_file = ppuVar16[1];
            ppuVar16 = ppuVar16 + 1;
            goto LAB_004578c0;
          }
          iVar9 = (*(code *)PTR_strcmp_006aac20)(param_2,&DAT_006330b4);
          if (iVar9 == 0) {
            iVar17 = iVar17 + -1;
            if (iVar17 == 0) goto LAB_00457b84;
            t_key_file = ppuVar16[1];
            ppuVar16 = ppuVar16 + 1;
            goto LAB_004578c0;
          }
          iVar9 = (*(code *)PTR_strcmp_006aac20)(param_2,"-CApath");
          if (iVar9 == 0) {
            iVar17 = iVar17 + -1;
            if (iVar17 == 0) goto LAB_00457b84;
            CApath = ppuVar16[1];
            ppuVar16 = ppuVar16 + 1;
            goto LAB_004578c0;
          }
          iVar9 = (*(code *)PTR_strcmp_006aac20)(param_2,"-CAfile");
          if (iVar9 == 0) {
            iVar17 = iVar17 + -1;
            if (iVar17 == 0) goto LAB_00457b84;
            CAfile = ppuVar16[1];
            ppuVar16 = ppuVar16 + 1;
            goto LAB_004578c0;
          }
          iVar9 = (*(code *)PTR_strcmp_006aac20)(param_2,"-cipher");
          if (iVar9 == 0) {
            iVar17 = iVar17 + -1;
            if (iVar17 == 0) goto LAB_00457b84;
            tm_cipher = ppuVar16[1];
            ppuVar16 = ppuVar16 + 1;
            goto LAB_004578c0;
          }
          iVar9 = (*(code *)PTR_strcmp_006aac20)(param_2,"-nbio");
          if (iVar9 == 0) goto LAB_004578c0;
          iVar9 = (*(code *)PTR_strcmp_006aac20)(param_2,&DAT_0063bff4);
          if (iVar9 == 0) {
            iVar17 = iVar17 + -1;
            if (iVar17 == 0) goto LAB_00457b84;
            s_www_path = ppuVar16[1];
            ppuVar16 = ppuVar16 + 1;
            uVar10 = (*(code *)PTR_strlen_006aab30)(s_www_path);
            if (0x1f9c < uVar10) {
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar4,"-www option too long\n");
              bVar2 = true;
            }
            goto LAB_004578c0;
          }
          iVar9 = (*(code *)PTR_strcmp_006aac20)(param_2,"-bugs");
          if (iVar9 == 0) {
            st_bugs = 1;
            goto LAB_004578c0;
          }
          iVar9 = (*(code *)PTR_strcmp_006aac20)(param_2,"-ssl2");
          if (iVar9 == 0) {
            iVar17 = iVar17 + -1;
            s_time_meth = (*(code *)PTR_SSLv2_client_method_006a8ac8)();
          }
          else {
            iVar9 = (*(code *)PTR_strcmp_006aac20)(param_2,"-ssl3");
            if (iVar9 != 0) {
              iVar9 = (*(code *)PTR_strcmp_006aac20)(param_2,"-time");
              if (iVar9 != 0) goto LAB_00458610;
              iVar17 = iVar17 + -1;
              if (iVar17 == 0) goto LAB_00457b84;
              ppuVar1 = ppuVar16 + 1;
              ppuVar16 = ppuVar16 + 1;
              maxTime = (*(code *)PTR_strtol_006aaa68)(*ppuVar1,0,10);
              goto LAB_004578c0;
            }
            iVar17 = iVar17 + -1;
            s_time_meth = (*(code *)PTR_SSLv3_client_method_006a8acc)();
          }
        }
        ppuVar16 = ppuVar16 + 1;
        if (iVar17 == 0) goto LAB_00457914;
      }
      iVar17 = iVar17 + -1;
      ppuVar16 = ppuVar16 + 1;
      perform = 2;
    } while (iVar17 != 0);
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
    iVar17 = 1;
    goto LAB_004579f0;
  }
  (*(code *)PTR_SSL_CTX_set_quiet_shutdown_006a8990)(tm_ctx,1);
  if (st_bugs != 0) {
    (*(code *)PTR_SSL_CTX_ctrl_006a884c)(tm_ctx,0x20,0x80000bff,0);
  }
  param_2 = &_ITM_registerTMCloneTable;
  (*(code *)PTR_SSL_CTX_set_cipher_list_006a89bc)(tm_ctx,tm_cipher);
  iVar17 = set_cert_stuff(tm_ctx,t_cert_file,t_key_file);
  if (iVar17 != 0) {
    (*(code *)PTR_SSL_load_error_strings_006a867c)();
    iVar17 = (*(code *)PTR_SSL_CTX_load_verify_locations_006a8998)(tm_ctx,CAfile,CApath);
    if ((iVar17 == 0) ||
       (iVar17 = (*(code *)PTR_SSL_CTX_set_default_verify_paths_006a899c)(tm_ctx), iVar17 == 0)) {
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar4);
    }
    if ((tm_cipher == (uint *)0x0) &&
       (tm_cipher = (uint *)(*(code *)PTR_getenv_006aab6c)("SSL_CIPHER"), tm_cipher == (uint *)0x0))
    {
      (*(code *)PTR_fwrite_006aab7c)
                ("No CIPHER specified\n",1,0x14,*(undefined4 *)PTR_stderr_006aac00);
    }
    puVar5 = PTR_stdout_006aaad4;
    uVar10 = *(uint *)(pcVar15 + -0x4640);
    if ((uVar10 & 1) != 0) {
      iVar9 = 0;
      (*(code *)PTR___printf_chk_006aaad0)
                (1,"Collecting connection statistics for %d seconds\n",maxTime);
      bytes_read = 0;
      iVar17 = (*(code *)PTR_time_006aabe4)(0);
      iVar17 = iVar17 + maxTime;
      app_tminterval(0,1);
      param_2 = (char *)puStack_2104;
      while (iVar14 = (*(code *)PTR_time_006aabe4)(0), iVar14 <= iVar17) {
        param_2 = (char *)doConnection(0);
        if ((uint *)param_2 == (uint *)0x0) goto LAB_004579c0;
        if (s_www_path != (uint *)0x0) {
          (*(code *)PTR_BIO_snprintf_006a8060)(auStack_20fc,0x2000,"GET %s HTTP/1.0\r\n\r\n");
          uVar7 = (*(code *)PTR_strlen_006aab30)(auStack_20fc);
          (*(code *)PTR_SSL_write_006a890c)(param_2,auStack_20fc,uVar7);
          while (iVar14 = (*(code *)PTR_SSL_read_006a8904)(param_2,auStack_20fc,0x2000), 0 < iVar14)
          {
            bytes_read = bytes_read + iVar14;
          }
        }
        iVar9 = iVar9 + 1;
        (*(code *)PTR_SSL_set_shutdown_006a88f8)(param_2,3);
        uVar7 = (*(code *)PTR_SSL_get_fd_006a8aac)(param_2);
        (*(code *)PTR_shutdown_006aaa6c)(uVar7,2);
        uVar7 = (*(code *)PTR_SSL_get_fd_006a8aac)(param_2);
        (*(code *)PTR_close_006aaa5c)(uVar7);
        iVar14 = (*(code *)PTR_SSL_ctrl_006a8878)(param_2,8,0,0);
        if (iVar14 == 0) {
          iVar14 = (*(code *)PTR_SSL_version_006a88d8)(param_2);
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
        (*(code *)PTR_fputc_006aaab0)(uVar7,*(undefined4 *)puVar5);
        (*(code *)PTR_fflush_006aac0c)(*(undefined4 *)puVar5);
        (*(code *)PTR_SSL_free_006a88fc)(param_2);
      }
      dVar18 = (double)app_tminterval(1,1);
      dVar18 = dVar18 + 0.0;
      (*(code *)PTR_time_006aabe4)(0);
      dVar19 = (double)iVar9 / dVar18;
      iVar14 = bytes_read;
      (*(code *)PTR___printf_chk_006aaad0)
                (1,"\n\n%d connections in %.2fs; %.2f connections/user sec, bytes read %ld\n",iVar9)
      ;
      uVar7 = SUB84(dVar18,0);
      iVar11 = (*(code *)PTR_time_006aabe4)(0);
      if (iVar9 == 0) {
        trap(7);
      }
      (*(code *)PTR___printf_chk_006aaad0)
                (1,"%d connections in %ld real seconds, %ld bytes read per connection\n",iVar9,
                 (iVar11 - iVar17) + maxTime,bytes_read / iVar9,uVar7,dVar19,iVar14);
      uVar10 = *(uint *)(pcVar15 + -0x4640);
    }
    iVar17 = 1;
    if ((uVar10 & 2) == 0) goto LAB_004579c4;
    (*(code *)PTR_puts_006aab60)("\n\nNow timing with session id reuse.");
    param_2 = (char *)doConnection(0);
    if ((uint *)param_2 != (uint *)0x0) {
      if (s_www_path != (uint *)0x0) {
        (*(code *)PTR_BIO_snprintf_006a8060)(auStack_20fc,0x2000,"GET %s HTTP/1.0\r\n\r\n");
        uVar7 = (*(code *)PTR_strlen_006aab30)(auStack_20fc);
        (*(code *)PTR_SSL_write_006a890c)(param_2,auStack_20fc,uVar7);
        do {
          iVar17 = (*(code *)PTR_SSL_read_006a8904)(param_2,auStack_20fc,0x2000);
        } while (0 < iVar17);
      }
      puVar5 = PTR_stdout_006aaad4;
      (*(code *)PTR_SSL_set_shutdown_006a88f8)(param_2,3);
      iVar14 = 0;
      pcVar15 = "GET %s HTTP/1.0\r\n\r\n";
      uVar7 = (*(code *)PTR_SSL_get_fd_006a8aac)(param_2);
      (*(code *)PTR_shutdown_006aaa6c)(uVar7,2);
      uVar7 = (*(code *)PTR_SSL_get_fd_006a8aac)(param_2);
      (*(code *)PTR_close_006aaa5c)(uVar7);
      iVar9 = (*(code *)PTR_time_006aabe4)(0);
      iVar9 = iVar9 + maxTime;
      (*(code *)PTR_puts_006aab60)("starting");
      bytes_read = 0;
      app_tminterval(0,1);
      while (iVar17 = (*(code *)PTR_time_006aabe4)(0), iVar17 <= iVar9) {
        iVar17 = doConnection(param_2);
        if (iVar17 == 0) {
          iVar17 = 1;
          goto LAB_00458494;
        }
        if (s_www_path != (uint *)0x0) {
          (*(code *)PTR_BIO_snprintf_006a8060)(auStack_20fc,0x2000,"GET %s HTTP/1.0\r\n\r\n");
          uVar7 = (*(code *)PTR_strlen_006aab30)(auStack_20fc);
          (*(code *)PTR_SSL_write_006a890c)(param_2,auStack_20fc,uVar7);
          while (iVar17 = (*(code *)PTR_SSL_read_006a8904)(param_2,auStack_20fc,0x2000), 0 < iVar17)
          {
            bytes_read = bytes_read + iVar17;
          }
        }
        iVar14 = iVar14 + 1;
        (*(code *)PTR_SSL_set_shutdown_006a88f8)(param_2,3);
        uVar7 = (*(code *)PTR_SSL_get_fd_006a8aac)(param_2);
        (*(code *)PTR_shutdown_006aaa6c)(uVar7,2);
        uVar7 = (*(code *)PTR_SSL_get_fd_006a8aac)(param_2);
        (*(code *)PTR_close_006aaa5c)(uVar7);
        iVar17 = (*(code *)PTR_SSL_ctrl_006a8878)(param_2,8,0,0);
        if (iVar17 == 0) {
          iVar17 = (*(code *)PTR_SSL_version_006a88d8)(param_2);
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
        (*(code *)PTR_fputc_006aaab0)(uVar7,*(undefined4 *)puVar5);
        (*(code *)PTR_fflush_006aac0c)(*(undefined4 *)puVar5);
      }
      dVar18 = (double)app_tminterval(1,1);
      dVar18 = dVar18 + 0.0;
      dVar19 = (double)iVar14 / dVar18;
      iVar11 = bytes_read;
      (*(code *)PTR___printf_chk_006aaad0)
                (1,"\n\n%d connections in %.2fs; %.2f connections/user sec, bytes read %ld\n",iVar14
                );
      uVar7 = SUB84(dVar18,0);
      iVar12 = (*(code *)PTR_time_006aabe4)(0);
      if (iVar14 == 0) {
        trap(7);
      }
      iVar17 = 0;
      (*(code *)PTR___printf_chk_006aaad0)
                (1,"%d connections in %ld real seconds, %ld bytes read per connection\n",iVar14,
                 (iVar12 - iVar9) + maxTime,bytes_read / iVar14,uVar7,dVar19,iVar11);
LAB_00458494:
      (*(code *)PTR_SSL_free_006a88fc)(param_2);
      goto LAB_004579c4;
    }
    (*(code *)PTR_fwrite_006aab7c)
              ("Unable to get connection\n",1,0x19,*(undefined4 *)PTR_stderr_006aac00);
  }
LAB_004579c0:
  iVar17 = 1;
LAB_004579c4:
  if (tm_ctx == 0) goto LAB_004579f0;
  do {
    (*(code *)PTR_SSL_CTX_free_006a8978)();
    tm_ctx = 0;
LAB_004579f0:
    while( true ) {
      if (iStack_fc == *(int *)puVar6) {
        return iVar17;
      }
      (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00458610:
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar4,"unknown option %s\n",param_2);
      if (*(int *)(pcVar15 + -0x4640) == 0) {
        bVar2 = true;
        *(undefined4 *)(pcVar15 + -0x4640) = 3;
        goto LAB_00457920;
      }
LAB_00457b84:
      iVar17 = 1;
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
      iVar17 = 1;
    }
  } while( true );
}

