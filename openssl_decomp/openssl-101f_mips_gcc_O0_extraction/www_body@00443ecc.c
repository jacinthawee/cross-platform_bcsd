
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 www_body(undefined4 param_1,char *param_2,int param_3)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  byte bVar12;
  char cVar13;
  int iVar11;
  char *pcVar14;
  char *pcVar15;
  undefined4 *puVar16;
  int unaff_s2;
  undefined1 *unaff_s3;
  uint uVar17;
  uint uVar18;
  int unaff_s7;
  int unaff_s8;
  undefined4 local_30;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  pcVar14 = "s_server.c";
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar4 = (*(code *)PTR_CRYPTO_malloc_006a8108)(0x4000,"s_server.c",0xa09);
  if (iVar4 == 0) {
    uVar5 = 0;
    goto LAB_0044402c;
  }
  uVar5 = (*(code *)PTR_BIO_f_buffer_006a8940)();
  unaff_s7 = (*(code *)PTR_BIO_new_006a7fa4)(uVar5);
  uVar5 = (*(code *)PTR_BIO_f_ssl_006a8944)();
  iVar6 = (*(code *)PTR_BIO_new_006a7fa4)(uVar5);
  if (unaff_s7 == 0) {
    pcVar14 = s_ACCEPT_0063b91c;
    (*(code *)PTR_BIO_printf_006a7f38)(bio_s_out);
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar4);
    uVar5 = 1;
    unaff_s8 = iVar4;
    goto LAB_0044402c;
  }
  if (iVar6 != 0) {
    if (s_nbio != 0) {
      local_30 = 1;
      if (s_quiet == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)PTR_bio_err_006a7f3c,"turning on non blocking io\n");
      }
      iVar7 = (*(code *)PTR_BIO_socket_ioctl_006a88c8)(param_2,0x667e,&local_30);
      if (iVar7 < 0) {
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
      }
    }
    iVar7 = (*(code *)PTR_BIO_int_ctrl_006a8948)(unaff_s7,0x75,0x4000,1);
    uVar5 = bio_s_out;
    if (iVar7 == 0) goto LAB_00443ff8;
    unaff_s2 = (*(code *)PTR_SSL_new_006a88cc)(ctx);
    if (unaff_s2 != 0) {
      if (s_tlsextdebug != 0) {
        (*(code *)PTR_SSL_callback_ctrl_006a8914)(unaff_s2,0x38,PTR_tlsext_cb_006a8918);
        (*(code *)PTR_SSL_ctrl_006a8878)(unaff_s2,0x39,0,bio_s_out);
      }
      unaff_s3 = &_ITM_registerTMCloneTable;
      if (param_3 != 0) {
        uVar5 = (*(code *)PTR_strlen_006aab30)(param_3);
        (*(code *)PTR_SSL_set_session_id_context_006a88d0)(unaff_s2,param_3,uVar5);
      }
      uVar5 = (*(code *)PTR_BIO_new_socket_006a88dc)(param_2,0);
      if (s_nbio_test != 0) {
        uVar9 = (*(code *)PTR_BIO_f_nbio_test_006a88e0)();
        uVar9 = (*(code *)PTR_BIO_new_006a7fa4)(uVar9);
        uVar5 = (*(code *)PTR_BIO_push_006a85c0)(uVar9,uVar5);
      }
      (*(code *)PTR_SSL_set_bio_006a88e4)(unaff_s2,uVar5);
      (*(code *)PTR_SSL_set_accept_state_006a88e8)(unaff_s2);
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar6,0x6d,1,unaff_s2);
      (*(code *)PTR_BIO_push_006a85c0)(unaff_s7,iVar6);
      if (s_debug != 0) {
        (*(code *)PTR_SSL_set_debug_006a8920)(unaff_s2,1);
        uVar5 = (*(code *)PTR_SSL_get_rbio_006a8924)(unaff_s2);
        (*(code *)PTR_BIO_set_callback_006a85d8)(uVar5,PTR_bio_dump_callback_006a8928);
        uVar5 = (*(code *)PTR_SSL_get_rbio_006a8924)(unaff_s2);
        (*(code *)PTR_BIO_set_callback_arg_006a85e0)(uVar5,bio_s_out);
      }
      if (s_msg != 0) {
        (*(code *)PTR_SSL_set_msg_callback_006a88ec)(unaff_s2,PTR_msg_cb_006a891c);
        (*(code *)PTR_SSL_ctrl_006a8878)(unaff_s2,0x10,0,bio_s_out);
      }
LAB_0044419c:
      if (hack != 0) {
        iVar6 = (*(code *)PTR_SSL_accept_006a888c)(unaff_s2);
        if (iVar6 < 1) {
          param_2 = &_ITM_registerTMCloneTable;
          do {
            while( true ) {
              iVar7 = (*(code *)PTR_SSL_get_error_006a8890)(unaff_s2,iVar6);
              if (iVar7 != 4) goto LAB_00444274;
              (*(code *)PTR_BIO_printf_006a7f38)
                        (bio_s_out,"LOOKUP during accept %s\n",srp_callback_parm._0_4_);
              srp_callback_parm._8_4_ =
                   (*(code *)PTR_SRP_VBASE_get_by_user_006a8894)
                             (srp_callback_parm._4_4_,srp_callback_parm._0_4_);
              if (srp_callback_parm._8_4_ != 0) break;
              (*(code *)PTR_BIO_printf_006a7f38)(bio_s_out,"LOOKUP not successful\n");
              iVar6 = (*(code *)PTR_SSL_accept_006a888c)(unaff_s2);
              if (0 < iVar6) goto LAB_00444274;
            }
            (*(code *)PTR_BIO_printf_006a7f38)
                      (bio_s_out,"LOOKUP done %s\n",*(undefined4 *)(srp_callback_parm._8_4_ + 0x14))
            ;
            iVar6 = (*(code *)PTR_SSL_accept_006a888c)(unaff_s2);
          } while (iVar6 < 1);
        }
LAB_00444274:
        uVar8 = (*(code *)PTR_SSL_get_error_006a8890)(unaff_s2,iVar6);
        if (uVar8 < 7) {
          uVar8 = 1 << (uVar8 & 0x1f);
          if ((uVar8 & 0x62) != 0) goto LAB_00444324;
          if ((uVar8 & 0x1c) != 0) goto LAB_0044419c;
        }
        (*(code *)PTR_SSL_renegotiate_006a8934)(unaff_s2);
        (*(code *)PTR_SSL_write_006a890c)(unaff_s2,0,0);
      }
      iVar6 = (*(code *)PTR_BIO_gets_006a85d0)(unaff_s7,iVar4,0x3fff);
      if (iVar6 < 0) {
        iVar6 = (*(code *)PTR_BIO_test_flags_006a8954)(unaff_s7,8);
        if (iVar6 == 0) {
          if (s_quiet != 0) goto LAB_00444324;
          (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
          uVar5 = bio_s_out;
          goto LAB_00443ff8;
        }
        (*(code *)PTR_BIO_printf_006a7f38)(bio_s_out,"read R BLOCK\n");
        (*(code *)PTR_sleep_006aabd0)(1);
        goto LAB_0044419c;
      }
      if (iVar6 == 0) goto LAB_004449d8;
      if (www != 1) {
        if (www == 2) {
          iVar6 = (*(code *)PTR_strncmp_006aaa7c)("GET /stats ",iVar4,10);
          if (iVar6 == 0) goto LAB_00444350;
        }
        else if (www != 3) goto LAB_0044419c;
        iVar6 = (*(code *)PTR_strncmp_006aaa7c)(&DAT_0063ba94,iVar4,5);
        if (iVar6 == 0) goto code_r0x004445e8;
        goto LAB_0044419c;
      }
      iVar6 = (*(code *)PTR_strncmp_006aaa7c)(&DAT_0063b950,iVar4,4);
      if (iVar6 != 0) goto LAB_0044419c;
LAB_00444350:
      (*(code *)PTR_BIO_puts_006a8058)
                (unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/html\r\n\r\n");
      (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"<HTML><BODY BGCOLOR=\"#ffffff\">\n");
      (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"<pre>\n");
      (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"\n");
      if (0 < local_argc) {
        iVar6 = 0;
        do {
          iVar7 = iVar6 * 4;
          iVar6 = iVar6 + 1;
          (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,*(undefined4 *)(local_argv + iVar7));
          (*(code *)PTR_BIO_write_006a7f14)(unaff_s7,&DAT_0063f0b8,1);
        } while (iVar6 < local_argc);
      }
      (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"\n");
      iVar6 = (*(code *)PTR_SSL_ctrl_006a8878)(unaff_s2,0x4c,0,0);
      if (iVar6 == 0) {
        pcVar14 = " NOT";
      }
      else {
        pcVar14 = "";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"Secure Renegotiation IS%s supported\n",pcVar14);
      (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"Ciphers supported in s_server binary\n");
      uVar5 = (*(code *)PTR_SSL_get_ciphers_006a894c)(unaff_s2);
      uVar8 = (*(code *)PTR_sk_num_006a7f2c)(uVar5);
      if (0 < (int)uVar8) {
        uVar9 = (*(code *)PTR_sk_value_006a7f24)(uVar5,0);
        uVar10 = (*(code *)PTR_SSL_CIPHER_get_version_006a8950)(uVar9);
        uVar9 = (*(code *)PTR_SSL_CIPHER_get_name_006a88ac)(uVar9);
        (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"%-11s:%-25s",uVar10,uVar9);
        uVar17 = 1;
        while (uVar8 != uVar17) {
          uVar18 = uVar17 + 1;
          uVar9 = (*(code *)PTR_sk_value_006a7f24)(uVar5,uVar17);
          uVar10 = (*(code *)PTR_SSL_CIPHER_get_version_006a8950)(uVar9);
          uVar9 = (*(code *)PTR_SSL_CIPHER_get_name_006a88ac)(uVar9);
          (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"%-11s:%-25s",uVar10,uVar9);
          uVar17 = uVar18;
          if ((uVar18 & 1) == 0) {
            if (uVar8 == uVar18) break;
            (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"\n");
          }
        }
      }
      (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"\n");
      pcVar14 = (char *)(*(code *)PTR_SSL_get_shared_ciphers_006a88a4)(unaff_s2,iVar4,0x4000);
      if (pcVar14 != (char *)0x0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (unaff_s7,"---\nCiphers common between both SSL end points:\n");
        cVar13 = *pcVar14;
        if (cVar13 != '\0') {
          iVar7 = 0;
          iVar6 = 0;
          do {
            if (cVar13 == ':') {
              iVar6 = iVar6 + 1;
              (*(code *)PTR_BIO_write_006a7f14)(unaff_s7,&DAT_0063ba24,0x1a - iVar7);
              if (iVar6 == (iVar6 / 3) * 3) {
                puVar16 = (undefined4 *)0x63bac8;
              }
              else {
                puVar16 = &DAT_0063f0b8;
              }
              iVar7 = 0;
              (*(code *)PTR_BIO_write_006a7f14)(unaff_s7,puVar16,1);
            }
            else {
              (*(code *)PTR_BIO_write_006a7f14)(unaff_s7,pcVar14,1);
              iVar7 = iVar7 + 1;
            }
            pcVar14 = pcVar14 + 1;
            cVar13 = *pcVar14;
          } while (cVar13 != '\0');
        }
        (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"\n");
      }
      iVar6 = (*(code *)PTR_SSL_cache_hit_006a88b8)(unaff_s2);
      if (iVar6 == 0) {
        pcVar14 = "---\nNew, ";
      }
      else {
        pcVar14 = "---\nReused, ";
      }
      (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,pcVar14);
      uVar5 = (*(code *)PTR_SSL_get_current_cipher_006a88a8)(unaff_s2);
      uVar9 = (*(code *)PTR_SSL_CIPHER_get_version_006a8950)(uVar5);
      uVar5 = (*(code *)PTR_SSL_CIPHER_get_name_006a88ac)(uVar5);
      (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"%s, Cipher is %s\n",uVar9,uVar5);
      uVar5 = (*(code *)PTR_SSL_get_session_006a8898)(unaff_s2);
      (*(code *)PTR_SSL_SESSION_print_006a8958)(unaff_s7,uVar5);
      (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,&DAT_0063ba54);
      uVar5 = (*(code *)PTR_SSL_get_SSL_CTX_006a8858)(unaff_s2);
      print_stats(unaff_s7,uVar5);
      (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,&DAT_0063ba54);
      param_2 = (char *)(*(code *)PTR_SSL_get_peer_certificate_006a88a0)(unaff_s2);
      if (param_2 == (char *)0x0) {
        (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"no client certificate available\n");
      }
      else {
        (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"Client certificate\n");
        (*(code *)PTR_X509_print_006a81c0)(unaff_s7,param_2);
        (*(code *)PTR_PEM_write_bio_X509_006a8020)(unaff_s7,param_2);
      }
      (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"</BODY></HTML>\r\n\r\n");
      goto LAB_004449b8;
    }
  }
LAB_00444324:
  unaff_s3 = &_ITM_registerTMCloneTable;
  uVar5 = bio_s_out;
LAB_00443ff8:
  do {
    pcVar14 = s_ACCEPT_0063b91c;
    (*(code *)PTR_BIO_printf_006a7f38)(uVar5);
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar4);
    (*(code *)PTR_BIO_free_all_006a7f74)(unaff_s7);
    uVar5 = 1;
    unaff_s8 = iVar4;
LAB_0044402c:
    if (local_2c == *(int *)puVar3) {
      return uVar5;
    }
    iVar6 = (*(code *)PTR___stack_chk_fail_006aabb8)();
    iVar4 = unaff_s8;
LAB_00444c68:
    if (iVar6 == 0) {
LAB_00444c24:
      (*(code *)PTR_BIO_puts_006a8058)
                (unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
      (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"\'%s\' is an invalid file name\r\n",param_2);
    }
    else {
LAB_00444c74:
      puVar2 = PTR_BIO_puts_006a8058;
      *pcVar14 = '\0';
      (*(code *)puVar2)(unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
      (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"\'%s\' contains \'..\' reference\r\n",param_2);
    }
LAB_004449b8:
    do {
      iVar6 = (*(code *)PTR_BIO_ctrl_006a7f18)(unaff_s7,0xb,0,0);
      if (0 < iVar6) break;
      iVar6 = (*(code *)PTR_BIO_test_flags_006a8954)(unaff_s7,8);
    } while (iVar6 != 0);
LAB_004449d8:
    (*(code *)PTR_SSL_set_shutdown_006a88f8)(unaff_s2,3);
    uVar5 = *(undefined4 *)(unaff_s3 + -0x4d6c);
  } while( true );
code_r0x004445e8:
  bVar1 = *(byte *)(iVar4 + 5);
  param_2 = (char *)(iVar4 + 5);
  if (bVar1 == 0) goto LAB_00444c24;
  uVar8 = 1;
  pcVar15 = param_2;
  pcVar14 = param_2;
  if (bVar1 != 0x20) {
    do {
      if (uVar8 == 1) {
        bVar12 = bVar1 ^ 0x2f;
        if (bVar1 == 0x2e) {
          bVar12 = pcVar15[1];
          if (bVar12 == 0) goto LAB_00444c24;
          pcVar14 = pcVar15 + 1;
          if (bVar12 == 0x20) goto LAB_00444bac;
          if (bVar12 == 0x2e) {
            bVar12 = pcVar15[2];
            pcVar14 = pcVar15 + 2;
            if (bVar12 == 0) goto LAB_00444c24;
            if (bVar12 == 0x20) goto LAB_00444c74;
            if (bVar12 == 0x2f) {
              iVar6 = (int)pcVar15[3];
              pcVar14 = pcVar15 + 3;
              if (iVar6 == 0) goto LAB_00444c24;
              if (iVar6 == 0x20) goto LAB_00444c68;
              pcVar14 = pcVar15 + 4;
              pcVar15 = pcVar15 + 4;
              if (*pcVar14 == '\0') goto LAB_00444c24;
              if (*pcVar14 != ' ') {
                uVar8 = 0xffffffff;
                goto LAB_00444624;
              }
              uVar8 = 0xffffffff;
              break;
            }
          }
          pcVar15 = pcVar14;
          bVar12 = bVar12 ^ 0x2f;
        }
LAB_00444a24:
        uVar8 = (uint)(bVar12 == 0);
      }
      else {
        bVar12 = bVar1 ^ 0x2f;
        if (uVar8 == 0) goto LAB_00444a24;
      }
LAB_00444624:
      bVar1 = pcVar15[1];
      pcVar15 = pcVar15 + 1;
      if (bVar1 == 0) goto LAB_00444c24;
    } while (bVar1 != 0x20);
    pcVar14 = pcVar15;
    if (uVar8 == 0xffffffff) goto LAB_00444c74;
  }
LAB_00444bac:
  *pcVar14 = '\0';
  if (*(char *)(iVar4 + 5) == '/') {
    (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n")
    ;
    (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"\'%s\' is an invalid path\r\n",param_2);
    goto LAB_004449b8;
  }
  iVar6 = app_isdir(param_2);
  if (0 < iVar6) {
    (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n")
    ;
    (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"\'%s\' is a directory\r\n",param_2);
    goto LAB_004449b8;
  }
  iVar6 = (*(code *)PTR_BIO_new_file_006a7fac)(param_2,"r");
  if (iVar6 == 0) {
    (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n")
    ;
    (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"Error opening \'%s\'\r\n",param_2);
    (*(code *)PTR_ERR_print_errors_006a7f40)(unaff_s7);
    goto LAB_004449b8;
  }
  if (s_quiet == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,"FILE:%s\n",param_2);
  }
  if (www != 2) goto LAB_00444cf8;
  iVar7 = (*(code *)PTR_strlen_006aab30)(param_2);
  if (iVar7 < 6) {
    if (iVar7 == 5) goto LAB_00444ea4;
LAB_00444ee8:
    (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n")
    ;
  }
  else {
    iVar11 = (*(code *)PTR_strcmp_006aac20)(param_2 + iVar7 + -5,".html");
    if (iVar11 != 0) {
LAB_00444ea4:
      param_2 = param_2 + iVar7 + -4;
      iVar7 = (*(code *)PTR_strcmp_006aac20)(param_2,&DAT_0063bb44);
      if ((iVar7 != 0) &&
         (iVar7 = (*(code *)PTR_strcmp_006aac20)(param_2,&DAT_0063bb4c), iVar7 != 0))
      goto LAB_00444ee8;
    }
    (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/html\r\n\r\n");
  }
LAB_00444cf8:
  while (iVar7 = (*(code *)PTR_BIO_read_006a85bc)(iVar6,iVar4,0x4000), 0 < iVar7) {
    param_2 = (char *)0x0;
    do {
      iVar11 = (*(code *)PTR_BIO_write_006a7f14)(unaff_s7,param_2 + iVar4,iVar7 - (int)param_2);
      if (iVar11 < 1) {
        iVar11 = (*(code *)PTR_BIO_test_flags_006a8954)(unaff_s7,8);
        if (iVar11 == 0) goto LAB_00444d78;
        (*(code *)PTR_BIO_printf_006a7f38)(bio_s_out,"rwrite W BLOCK\n");
      }
      else {
        param_2 = param_2 + iVar11;
      }
    } while ((int)param_2 < iVar7);
  }
LAB_00444d78:
  (*(code *)PTR_BIO_free_006a7f70)(iVar6);
  goto LAB_004449b8;
}

