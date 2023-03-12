
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 www_body(undefined4 param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  byte bVar14;
  char cVar15;
  int iVar13;
  char *pcVar16;
  undefined *puVar17;
  undefined4 *puVar18;
  undefined *puVar19;
  int *piVar20;
  undefined *puVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  undefined4 local_30;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  pcVar16 = "s_server.c";
  piVar20 = (int *)0x9f9;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar4 = (*(code *)PTR_CRYPTO_malloc_006a7008)(0x4000);
  if (iVar4 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (*(code *)PTR_BIO_f_buffer_006a7854)();
    iVar6 = (*(code *)PTR_BIO_new_006a6ea4)(uVar5);
    uVar5 = (*(code *)PTR_BIO_f_ssl_006a7858)();
    iVar7 = (*(code *)PTR_BIO_new_006a6ea4)(uVar5);
    if (iVar6 != 0) {
      if (iVar7 != 0) {
        if (s_nbio != 0) {
          local_30 = 1;
          if (s_quiet == 0) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)PTR_bio_err_006a6e3c,"turning on non blocking io\n");
          }
          iVar8 = (*(code *)PTR_BIO_socket_ioctl_006a77dc)(param_2,0x667e,&local_30);
          if (iVar8 < 0) {
            (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)PTR_bio_err_006a6e3c);
          }
        }
        piVar20 = (int *)&DAT_00004000;
        iVar8 = (*(code *)PTR_BIO_int_ctrl_006a785c)(iVar6,0x75,0x4000,1);
        if ((iVar8 != 0) && (iVar8 = (*(code *)PTR_SSL_new_006a77e0)(ctx), iVar8 != 0)) {
          if (s_tlsextdebug != 0) {
            (*(code *)PTR_SSL_callback_ctrl_006a7828)(iVar8,0x38,PTR_tlsext_cb_006a782c);
            (*(code *)PTR_SSL_ctrl_006a7788)(iVar8,0x39,0,bio_s_out);
          }
          if (param_3 != 0) {
            uVar5 = (*(code *)PTR_strlen_006a9a24)(param_3);
            (*(code *)PTR_SSL_set_session_id_context_006a77e4)(iVar8,param_3,uVar5);
          }
          uVar5 = (*(code *)PTR_BIO_new_socket_006a77f0)(param_2,0);
          if (s_nbio_test != 0) {
            uVar11 = (*(code *)PTR_BIO_f_nbio_test_006a77f4)();
            uVar11 = (*(code *)PTR_BIO_new_006a6ea4)(uVar11);
            uVar5 = (*(code *)PTR_BIO_push_006a74c4)(uVar11,uVar5);
          }
          (*(code *)PTR_SSL_set_bio_006a77f8)(iVar8,uVar5);
          (*(code *)PTR_SSL_set_accept_state_006a77fc)(iVar8);
          piVar20 = (int *)0x1;
          (*(code *)PTR_BIO_ctrl_006a6e18)(iVar7,0x6d,1,iVar8);
          (*(code *)PTR_BIO_push_006a74c4)(iVar6,iVar7);
          if (s_debug != 0) {
            (*(code *)PTR_SSL_set_debug_006a7834)(iVar8,1);
            uVar5 = (*(code *)PTR_SSL_get_rbio_006a7838)(iVar8);
            (*(code *)PTR_BIO_set_callback_006a74dc)(uVar5,PTR_bio_dump_callback_006a783c);
            uVar5 = (*(code *)PTR_SSL_get_rbio_006a7838)(iVar8);
            (*(code *)PTR_BIO_set_callback_arg_006a74e4)(uVar5,bio_s_out);
          }
          if (s_msg != 0) {
            (*(code *)PTR_SSL_set_msg_callback_006a7800)(iVar8,PTR_msg_cb_006a7830);
            piVar20 = (int *)0x0;
            (*(code *)PTR_SSL_ctrl_006a7788)(iVar8,0x10,0,bio_s_out);
          }
LAB_00444704:
          if (hack != 0) {
            iVar7 = (*(code *)PTR_SSL_accept_006a779c)(iVar8);
            while (iVar7 < 1) {
              while( true ) {
                iVar9 = (*(code *)PTR_SSL_get_error_006a77a0)(iVar8,iVar7);
                if (iVar9 != 4) goto LAB_00444800;
                piVar20 = srp_callback_parm._0_4_;
                (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"LOOKUP during accept %s\n");
                (*(code *)PTR_SRP_user_pwd_free_006a77a4)(srp_callback_parm._8_4_);
                srp_callback_parm._8_4_ =
                     (*(code *)PTR_SRP_VBASE_get1_by_user_006a77a8)
                               (srp_callback_parm._4_4_,srp_callback_parm._0_4_);
                if (srp_callback_parm._8_4_ != 0) break;
                (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"LOOKUP not successful\n");
                iVar7 = (*(code *)PTR_SSL_accept_006a779c)(iVar8);
                if (0 < iVar7) goto LAB_00444800;
              }
              piVar20 = *(int **)(srp_callback_parm._8_4_ + 0x14);
              (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"LOOKUP done %s\n");
              iVar7 = (*(code *)PTR_SSL_accept_006a779c)(iVar8);
            }
LAB_00444800:
            uVar10 = (*(code *)PTR_SSL_get_error_006a77a0)(iVar8,iVar7);
            if (uVar10 < 7) {
              uVar10 = 1 << (uVar10 & 0x1f);
              if ((uVar10 & 0x62) != 0) goto LAB_0044455c;
              if ((uVar10 & 0x1c) != 0) goto LAB_00444704;
            }
            (*(code *)PTR_SSL_renegotiate_006a7848)(iVar8);
            (*(code *)PTR_SSL_write_006a7820)(iVar8,0,0);
          }
          piVar20 = (int *)0x3fff;
          iVar7 = (*(code *)PTR_BIO_gets_006a74d4)(iVar6,iVar4);
          if (iVar7 < 0) {
            iVar7 = (*(code *)PTR_BIO_test_flags_006a7868)(iVar6,8);
            if (iVar7 == 0) {
              if (s_quiet == 0) {
                (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)PTR_bio_err_006a6e3c);
              }
              goto LAB_0044455c;
            }
            (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"read R BLOCK\n");
            iVar7 = (*(code *)PTR_BIO_test_flags_006a7868)(iVar6,4);
            if ((iVar7 == 0) ||
               (iVar7 = (*(code *)PTR_BIO_get_retry_reason_006a786c)(iVar6), iVar7 != 1)) {
              (*(code *)PTR_sleep_006a9ac8)(1);
            }
            else {
              (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"LOOKUP renego during read\n");
              (*(code *)PTR_SRP_user_pwd_free_006a77a4)(srp_callback_parm._8_4_);
              srp_callback_parm._8_4_ =
                   (*(code *)PTR_SRP_VBASE_get1_by_user_006a77a8)
                             (srp_callback_parm._4_4_,srp_callback_parm._0_4_);
              if (srp_callback_parm._8_4_ == 0) {
                (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"LOOKUP not successful\n");
              }
              else {
                piVar20 = *(int **)(srp_callback_parm._8_4_ + 0x14);
                (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"LOOKUP done %s\n");
              }
            }
            goto LAB_00444704;
          }
          if (iVar7 == 0) goto LAB_00444e4c;
          if (www != 1) {
            if (www == 2) {
              iVar7 = (*(code *)PTR_strncmp_006a9970)("GET /stats ",iVar4,0xb);
              if (iVar7 == 0) goto LAB_004448cc;
              goto LAB_00444b44;
            }
            if (www != 3) goto LAB_00444704;
LAB_00444b44:
            piVar20 = (int *)&DAT_00000005;
            iVar7 = (*(code *)PTR_strncmp_006a9970)(&DAT_0063b2b0,iVar4);
            puVar2 = PTR_BIO_puts_006a6f58;
            if (iVar7 == 0) goto code_r0x00444b5c;
            goto LAB_00444704;
          }
          piVar20 = (int *)&SUB_00000004;
          iVar7 = (*(code *)PTR_strncmp_006a9970)(&DAT_0063b16c,iVar4);
          if (iVar7 != 0) goto LAB_00444704;
LAB_004448cc:
          (*(code *)PTR_BIO_puts_006a6f58)
                    (iVar6,"HTTP/1.0 200 ok\r\nContent-type: text/html\r\n\r\n");
          (*(code *)PTR_BIO_puts_006a6f58)(iVar6,"<HTML><BODY BGCOLOR=\"#ffffff\">\n");
          (*(code *)PTR_BIO_puts_006a6f58)(iVar6,"<pre>\n");
          (*(code *)PTR_BIO_puts_006a6f58)(iVar6,"\n");
          if (0 < local_argc) {
            iVar7 = 0;
            do {
              iVar9 = iVar7 * 4;
              iVar7 = iVar7 + 1;
              (*(code *)PTR_BIO_puts_006a6f58)(iVar6,*(undefined4 *)(local_argv + iVar9));
              (*(code *)PTR_BIO_write_006a6e14)(iVar6,&DAT_0063eb84,1);
            } while (iVar7 < local_argc);
          }
          (*(code *)PTR_BIO_puts_006a6f58)(iVar6,"\n");
          iVar7 = (*(code *)PTR_SSL_ctrl_006a7788)(iVar8,0x4c,0,0);
          if (iVar7 == 0) {
            pcVar16 = " NOT";
          }
          else {
            pcVar16 = "";
          }
          (*(code *)PTR_BIO_printf_006a6e38)(iVar6,"Secure Renegotiation IS%s supported\n",pcVar16);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar6,"Ciphers supported in s_server binary\n");
          uVar5 = (*(code *)PTR_SSL_get_ciphers_006a7860)(iVar8);
          uVar10 = (*(code *)PTR_sk_num_006a6e2c)(uVar5);
          if (0 < (int)uVar10) {
            uVar11 = (*(code *)PTR_sk_value_006a6e24)(uVar5,0);
            uVar12 = (*(code *)PTR_SSL_CIPHER_get_version_006a7864)(uVar11);
            uVar11 = (*(code *)PTR_SSL_CIPHER_get_name_006a77c0)(uVar11);
            (*(code *)PTR_BIO_printf_006a6e38)(iVar6,"%-11s:%-25s",uVar12,uVar11);
            uVar23 = 1;
            while (uVar10 != uVar23) {
              uVar24 = uVar23 + 1;
              uVar11 = (*(code *)PTR_sk_value_006a6e24)(uVar5,uVar23);
              uVar12 = (*(code *)PTR_SSL_CIPHER_get_version_006a7864)(uVar11);
              uVar11 = (*(code *)PTR_SSL_CIPHER_get_name_006a77c0)(uVar11);
              (*(code *)PTR_BIO_printf_006a6e38)(iVar6,"%-11s:%-25s",uVar12,uVar11);
              uVar23 = uVar24;
              if ((uVar24 & 1) == 0) {
                if (uVar10 == uVar24) break;
                (*(code *)PTR_BIO_puts_006a6f58)(iVar6,"\n");
              }
            }
          }
          (*(code *)PTR_BIO_puts_006a6f58)(iVar6,"\n");
          pcVar16 = (char *)(*(code *)PTR_SSL_get_shared_ciphers_006a77b8)(iVar8,iVar4,0x4000);
          if (pcVar16 != (char *)0x0) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (iVar6,"---\nCiphers common between both SSL end points:\n");
            cVar15 = *pcVar16;
            if (cVar15 != '\0') {
              iVar9 = 0;
              iVar7 = 0;
              do {
                if (cVar15 == ':') {
                  iVar7 = iVar7 + 1;
                  (*(code *)PTR_BIO_write_006a6e14)(iVar6,&DAT_0063b240,0x1a - iVar9);
                  if (iVar7 == (iVar7 / 3) * 3) {
                    puVar18 = (undefined4 *)0x63b2e4;
                  }
                  else {
                    puVar18 = &DAT_0063eb84;
                  }
                  iVar9 = 0;
                  (*(code *)PTR_BIO_write_006a6e14)(iVar6,puVar18,1);
                }
                else {
                  (*(code *)PTR_BIO_write_006a6e14)(iVar6,pcVar16,1);
                  iVar9 = iVar9 + 1;
                }
                pcVar16 = pcVar16 + 1;
                cVar15 = *pcVar16;
              } while (cVar15 != '\0');
            }
            (*(code *)PTR_BIO_puts_006a6f58)(iVar6,"\n");
          }
          iVar7 = (*(code *)PTR_SSL_cache_hit_006a77cc)(iVar8);
          if (iVar7 == 0) {
            pcVar16 = "---\nNew, ";
          }
          else {
            pcVar16 = "---\nReused, ";
          }
          (*(code *)PTR_BIO_printf_006a6e38)(iVar6,pcVar16);
          uVar5 = (*(code *)PTR_SSL_get_current_cipher_006a77bc)(iVar8);
          uVar11 = (*(code *)PTR_SSL_CIPHER_get_version_006a7864)(uVar5);
          uVar5 = (*(code *)PTR_SSL_CIPHER_get_name_006a77c0)(uVar5);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar6,"%s, Cipher is %s\n",uVar11,uVar5);
          uVar5 = (*(code *)PTR_SSL_get_session_006a77ac)(iVar8);
          (*(code *)PTR_SSL_SESSION_print_006a7870)(iVar6,uVar5);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar6,&DAT_0063b270);
          uVar5 = (*(code *)PTR_SSL_get_SSL_CTX_006a7768)(iVar8);
          print_stats(iVar6,uVar5);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar6,&DAT_0063b270);
          iVar7 = (*(code *)PTR_SSL_get_peer_certificate_006a77b4)(iVar8);
          if (iVar7 == 0) {
            (*(code *)PTR_BIO_puts_006a6f58)(iVar6,"no client certificate available\n");
          }
          else {
            (*(code *)PTR_BIO_printf_006a6e38)(iVar6,"Client certificate\n");
            (*(code *)PTR_X509_print_006a70c0)(iVar6,iVar7);
            (*(code *)PTR_PEM_write_bio_X509_006a6f20)(iVar6,iVar7);
          }
          (*(code *)PTR_BIO_puts_006a6f58)(iVar6,"</BODY></HTML>\r\n\r\n");
          goto LAB_00444e2c;
        }
      }
      goto LAB_0044455c;
    }
    pcVar16 = s_ACCEPT_0063b138;
    (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out);
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar4);
    uVar5 = 1;
  }
  goto LAB_00444590;
code_r0x00444b5c:
  bVar1 = *(byte *)(iVar4 + 5);
  puVar21 = (undefined *)(iVar4 + 5);
  if (bVar1 == 0) {
LAB_0044525c:
    (*(code *)PTR_BIO_puts_006a6f58)(iVar6,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
    (*(code *)PTR_BIO_printf_006a6e38)(iVar6,"\'%s\' is an invalid file name\r\n",puVar21);
  }
  else {
    uVar10 = 1;
    puVar17 = puVar21;
    puVar19 = puVar21;
    if (bVar1 != 0x20) {
      do {
        if (uVar10 == 1) {
          bVar14 = bVar1 ^ 0x2f;
          if (bVar1 == 0x2e) {
            bVar14 = puVar17[1];
            if (bVar14 == 0) goto LAB_0044525c;
            puVar19 = puVar17 + 1;
            if (bVar14 == 0x20) goto LAB_004451cc;
            if (bVar14 == 0x2e) {
              bVar14 = puVar17[2];
              if (bVar14 == 0) goto LAB_0044525c;
              puVar19 = puVar17 + 2;
              if (bVar14 == 0x20) goto LAB_004453bc;
              if (bVar14 == 0x2f) {
                if (puVar17[3] == '\0') goto LAB_0044525c;
                puVar19 = puVar17 + 3;
                if (puVar17[3] == ' ') goto LAB_004453bc;
                pcVar16 = puVar17 + 4;
                puVar17 = puVar17 + 4;
                if (*pcVar16 == '\0') goto LAB_0044525c;
                if (*pcVar16 != ' ') {
                  uVar10 = 0xffffffff;
                  goto LAB_00444b98;
                }
                uVar10 = 0xffffffff;
                break;
              }
            }
            puVar17 = puVar19;
            bVar14 = bVar14 ^ 0x2f;
          }
LAB_00444ed0:
          uVar10 = (uint)(bVar14 == 0);
        }
        else {
          bVar14 = bVar1 ^ 0x2f;
          if (uVar10 == 0) goto LAB_00444ed0;
        }
LAB_00444b98:
        bVar1 = puVar17[1];
        puVar17 = puVar17 + 1;
        if (bVar1 == 0) goto LAB_0044525c;
      } while (bVar1 != 0x20);
      puVar19 = puVar17;
      if (uVar10 == 0xffffffff) {
LAB_004453bc:
        *puVar19 = 0;
        (*(code *)puVar2)(iVar6,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
        (*(code *)PTR_BIO_printf_006a6e38)(iVar6,"\'%s\' contains \'..\' reference\r\n",puVar21);
        goto LAB_00444e2c;
      }
    }
LAB_004451cc:
    *puVar19 = 0;
    if (*(char *)(iVar4 + 5) == '/') {
      (*(code *)PTR_BIO_puts_006a6f58)(iVar6,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
      (*(code *)PTR_BIO_printf_006a6e38)(iVar6,"\'%s\' is an invalid path\r\n",puVar21);
    }
    else {
      iVar7 = app_isdir(puVar21);
      if (iVar7 < 1) {
        iVar7 = (*(code *)PTR_BIO_new_file_006a6eac)(puVar21,"r");
        if (iVar7 == 0) {
          (*(code *)PTR_BIO_puts_006a6f58)
                    (iVar6,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
          (*(code *)PTR_BIO_printf_006a6e38)(iVar6,"Error opening \'%s\'\r\n",puVar21);
          (*(code *)PTR_ERR_print_errors_006a6e40)(iVar6);
        }
        else {
          if (s_quiet == 0) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)PTR_bio_err_006a6e3c,"FILE:%s\n",puVar21);
          }
          if (www == 2) {
            iVar9 = (*(code *)PTR_strlen_006a9a24)(puVar21);
            if (iVar9 < 6) {
              if (iVar9 == 5) goto LAB_004454d0;
LAB_00445514:
              (*(code *)PTR_BIO_puts_006a6f58)
                        (iVar6,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
            }
            else {
              iVar22 = (*(code *)PTR_strcmp_006a9b18)(puVar21 + iVar9 + -5,".html");
              if (iVar22 != 0) {
LAB_004454d0:
                iVar22 = (*(code *)PTR_strcmp_006a9b18)(puVar21 + iVar9 + -4,&DAT_0063b360);
                if ((iVar22 != 0) &&
                   (iVar9 = (*(code *)PTR_strcmp_006a9b18)(puVar21 + iVar9 + -4,&DAT_0063b368),
                   iVar9 != 0)) goto LAB_00445514;
              }
              (*(code *)PTR_BIO_puts_006a6f58)
                        (iVar6,"HTTP/1.0 200 ok\r\nContent-type: text/html\r\n\r\n");
            }
          }
          while (iVar9 = (*(code *)PTR_BIO_read_006a74c0)(iVar7,iVar4,0x4000), 0 < iVar9) {
            iVar22 = 0;
            do {
              iVar13 = (*(code *)PTR_BIO_write_006a6e14)(iVar6,iVar4 + iVar22,iVar9 - iVar22);
              if (iVar13 < 1) {
                iVar13 = (*(code *)PTR_BIO_test_flags_006a7868)(iVar6,8);
                if (iVar13 == 0) goto LAB_00445364;
                (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"rwrite W BLOCK\n");
              }
              else {
                iVar22 = iVar22 + iVar13;
              }
            } while (iVar22 < iVar9);
          }
LAB_00445364:
          (*(code *)PTR_BIO_free_006a6e70)(iVar7);
        }
      }
      else {
        (*(code *)PTR_BIO_puts_006a6f58)
                  (iVar6,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
        (*(code *)PTR_BIO_printf_006a6e38)(iVar6,"\'%s\' is a directory\r\n",puVar21);
      }
    }
  }
LAB_00444e2c:
  do {
    piVar20 = (int *)0x0;
    iVar7 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar6,0xb,0,0);
    if (0 < iVar7) break;
    iVar7 = (*(code *)PTR_BIO_test_flags_006a7868)(iVar6,8);
  } while (iVar7 != 0);
LAB_00444e4c:
  (*(code *)PTR_SSL_set_shutdown_006a780c)(iVar8,3);
LAB_0044455c:
  pcVar16 = s_ACCEPT_0063b138;
  (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out);
  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar4);
  (*(code *)PTR_BIO_free_all_006a6e74)(iVar6);
  uVar5 = 1;
LAB_00444590:
  if (local_2c == *(int *)puVar3) {
    return uVar5;
  }
  iVar4 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar6 = piVar20[2];
  if (*piVar20 == 0) {
    if (iVar6 == 0) {
      iVar4 = (*(code *)PTR_SSL_get_srp_username_006a7878)();
      *piVar20 = iVar4;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,"SRP username = \"%s\"\n",iVar4);
      return 0xffffffff;
    }
  }
  else if (iVar6 == 0) {
    uVar5 = 2;
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,"User %s doesn\'t exist\n");
    goto LAB_004455d4;
  }
  iVar4 = (*(code *)PTR_SSL_set_srp_server_param_006a7874)
                    (iVar4,*(undefined4 *)(iVar6 + 0x10),*(undefined4 *)(iVar6 + 0xc),
                     *(undefined4 *)(iVar6 + 4),*(undefined4 *)(iVar6 + 8),
                     *(undefined4 *)(iVar6 + 0x14));
  if (iVar4 < 0) {
    uVar5 = 2;
    *(undefined4 *)pcVar16 = 0x50;
  }
  else {
    uVar5 = 0;
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,
               "SRP parameters set: username = \"%s\" info=\"%s\" \n",*piVar20,
               *(undefined4 *)(piVar20[2] + 0x14));
  }
LAB_004455d4:
  (*(code *)PTR_SRP_user_pwd_free_006a77a4)(piVar20[2]);
  piVar20[2] = 0;
  *piVar20 = 0;
  return uVar5;
}

