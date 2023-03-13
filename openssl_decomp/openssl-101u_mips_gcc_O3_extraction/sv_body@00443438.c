
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int sv_body(undefined4 param_1,uint param_2,int param_3)

{
  byte bVar1;
  undefined *puVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  char cVar16;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  byte bVar17;
  int iVar15;
  char *pcVar18;
  char *pcVar19;
  undefined *puVar20;
  undefined *puVar21;
  undefined4 *puVar22;
  int *piVar23;
  char *pcVar24;
  undefined4 *puVar25;
  uint uVar26;
  undefined *puVar27;
  int iVar28;
  int unaff_s1;
  undefined *unaff_s3;
  char *unaff_s4;
  char *unaff_s5;
  char *unaff_s6;
  uint uVar29;
  char *unaff_s7;
  code *pcVar30;
  char *unaff_s8;
  undefined4 uStack_128;
  int iStack_124;
  undefined *puStack_120;
  int iStack_11c;
  int iStack_118;
  undefined *puStack_114;
  undefined4 *puStack_110;
  char *pcStack_10c;
  char *pcStack_108;
  char *pcStack_104;
  char *pcStack_100;
  code *pcStack_fc;
  undefined4 *local_e8;
  undefined *local_e0;
  char *local_d8;
  int local_d4;
  int local_d0;
  uint local_cc;
  int local_c8;
  int *local_c4;
  undefined *local_c0;
  char *local_bc;
  undefined4 local_b4;
  undefined4 local_b0;
  uint auStack_ac [32];
  int local_2c;
  
  puVar22 = (undefined4 *)0x7b6;
  local_e0 = &_gp;
  local_c4 = (int *)PTR___stack_chk_guard_006a9ae8;
  local_bc = "-check_ss_sig";
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar3 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x4000,"s_server.c");
  if (pcVar3 == (char *)0x0) {
    iStack_118 = 1;
    (**(code **)(local_e0 + -0x7fa8))(**(undefined4 **)(local_e0 + -0x7fa4),"out of memory\n");
    (**(code **)(local_e0 + -0x7fa8))(bio_s_out,"CONNECTION CLOSED\n");
LAB_00443714:
    pcVar18 = s_ACCEPT_0063b138;
    (**(code **)(local_e0 + -0x7fa8))(bio_s_out);
  }
  else {
    if (s_nbio != 0) {
      local_b4 = 1;
      if (s_quiet == 0) {
        (**(code **)(local_e0 + -0x7fa8))
                  (**(undefined4 **)(local_e0 + -0x7fa4),"turning on non blocking io\n");
      }
      iVar4 = (**(code **)(local_e0 + -0x7604))(param_2,0x667e,&local_b4);
      if (iVar4 < 0) {
        (**(code **)(local_e0 + -0x7fa0))(**(undefined4 **)(local_e0 + -0x7fa4));
      }
    }
    unaff_s4 = &_gp_1;
    unaff_s3 = &_gp_1;
    unaff_s1 = (**(code **)(local_e0 + -0x7600))(ctx);
    if (s_tlsextdebug != 0) {
      (**(code **)(local_e0 + -0x75b8))(unaff_s1,0x38,*(undefined4 *)(local_e0 + -0x75b4));
      (**(code **)(local_e0 + -0x7658))(unaff_s1,0x39,0,bio_s_out);
    }
    if (s_tlsextstatus != 0) {
      (**(code **)(local_e0 + -0x75bc))(ctx,0x3f,cert_status_cb);
      tlscstatp._20_4_ = **(undefined4 **)(local_e0 + -0x7fa4);
      (**(code **)(local_e0 + -0x7684))(ctx,0x40,0,tlscstatp);
    }
    if (param_3 != 0) {
      uVar5 = (**(code **)(local_e0 + -0x53bc))(param_3);
      (**(code **)(local_e0 + -0x75fc))(unaff_s1,param_3,uVar5);
    }
    (**(code **)(local_e0 + -0x75f8))(unaff_s1);
    iVar4 = (**(code **)(local_e0 + -0x75f4))(unaff_s1);
    if (iVar4 != 0xfeff) {
      puVar22 = (undefined4 *)(**(code **)(local_e0 + -0x75f0))(param_2,0);
      goto LAB_00443590;
    }
    puVar25 = (undefined4 *)(**(code **)(local_e0 + -0x75a0))(param_2,0);
    if (enable_timeouts != 0) {
      unaff_s4 = (char *)&local_b4;
      local_b4 = 0;
      local_b0 = 250000;
      (**(code **)(local_e0 + -0x7fc8))(puVar25,0x21,0,unaff_s4);
      local_b4 = 0;
      local_b0 = 250000;
      (**(code **)(local_e0 + -0x7fc8))(puVar25,0x23,0,unaff_s4);
    }
    if (socket_mtu == (undefined4 *)0x0) {
      (**(code **)(local_e0 + -0x7fc8))(puVar25,0x27,0,0);
LAB_00443fd4:
      (**(code **)(local_e0 + -0x7658))(unaff_s1,0x20,0x2000,0);
      puVar22 = puVar25;
LAB_00443590:
      if (s_nbio_test != 0) {
        uVar5 = (**(code **)(local_e0 + -0x75ec))();
        uVar5 = (**(code **)(local_e0 + -0x7f3c))(uVar5);
        puVar22 = (undefined4 *)(**(code **)(local_e0 + -0x791c))(uVar5,puVar22);
      }
      (**(code **)(local_e0 + -0x75e8))(unaff_s1,puVar22);
      (**(code **)(local_e0 + -0x75e4))(unaff_s1);
      if (s_debug != 0) {
        (**(code **)(local_e0 + -0x75ac))(unaff_s1,1);
        uVar5 = (**(code **)(local_e0 + -0x75a8))(unaff_s1);
        (**(code **)(local_e0 + -0x7904))(uVar5,*(undefined4 *)(local_e0 + -0x75a4));
        uVar5 = (**(code **)(local_e0 + -0x75a8))(unaff_s1);
        (**(code **)(local_e0 + -0x78fc))(uVar5,bio_s_out);
      }
      if (s_msg != 0) {
        (**(code **)(local_e0 + -0x75e0))(unaff_s1,*(undefined4 *)(local_e0 + -0x75b0));
        puVar22 = (undefined4 *)0x0;
        (**(code **)(local_e0 + -0x7658))(unaff_s1,0x10,0,bio_s_out);
      }
      if (s_tlsextdebug != 0) {
        (**(code **)(local_e0 + -0x75b8))(unaff_s1,0x38,*(undefined4 *)(local_e0 + -0x75b4));
        puVar22 = (undefined4 *)0x0;
        (**(code **)(local_e0 + -0x7658))(unaff_s1,0x39,0,bio_s_out);
      }
      local_c8 = param_2 + 1;
      local_cc = 1 << (param_2 & 0x1f);
      unaff_s6 = "LOOKUP renego during write\n";
      unaff_s7 = "LOOKUP done %s\n";
      local_c0 = &_gp_1;
      local_d8 = "LOOKUP not successful\n";
switchD_0044411c_caseD_4:
      pcVar30 = *(code **)(local_e0 + -0x75dc);
LAB_00443648:
      while (local_d0 = (*pcVar30)(unaff_s1), local_d0 == 0) {
        puVar25 = *(undefined4 **)(local_e0 + -0x53cc);
        (**(code **)(local_e0 + -0x53ec))(auStack_ac,0,0x80);
        unaff_s4 = (char *)(**(code **)(local_e0 + -0x5404))(*puVar25);
        uVar5 = (**(code **)(local_e0 + -0x5404))(*puVar25);
        iVar4 = (**(code **)(local_e0 + -0x5340))(uVar5);
        pcVar30 = *(code **)(local_e0 + -0x5340);
        auStack_ac[iVar4] = 1 << ((uint)unaff_s4 & 0x1f) | auStack_ac[iVar4];
        iVar4 = (*pcVar30)(param_2);
        pcVar30 = *(code **)(local_e0 + -0x75f4);
        auStack_ac[iVar4] = auStack_ac[iVar4] | local_cc;
        iVar4 = (*pcVar30)(unaff_s1);
        if (iVar4 == 0xfeff) {
          puVar6 = &local_b4;
          iVar4 = (**(code **)(local_e0 + -0x7658))(unaff_s1,0x49,0,puVar6);
          unaff_s4 = (char *)puVar6;
          if (iVar4 == 0) goto LAB_00443840;
        }
        else {
LAB_00443840:
          puVar6 = (undefined4 *)0x0;
        }
        puVar22 = (undefined4 *)0x0;
        local_e8 = puVar6;
        unaff_s3 = (undefined *)(**(code **)(local_e0 + -0x531c))(local_c8,auStack_ac,0,0);
        iVar4 = (**(code **)(local_e0 + -0x75f4))(unaff_s1);
        if (iVar4 != 0xfeff) goto code_r0x00443880;
        puVar22 = (undefined4 *)0x0;
        iVar4 = (**(code **)(local_e0 + -0x7658))(unaff_s1,0x4a,0,0);
        if (0 < iVar4) {
          (**(code **)(local_e0 + -0x7fa8))
                    (**(undefined4 **)(local_e0 + -0x7fa4),"TIMEOUT occured\n");
        }
        pcVar30 = *(code **)(local_e0 + -0x75dc);
        if (0 < (int)unaff_s3) goto LAB_00443888;
      }
      goto LAB_0044365c;
    }
    iVar4 = (**(code **)(local_e0 + -0x7658))(unaff_s1,0x79,0,0);
    if ((int)socket_mtu < iVar4) {
      uVar5 = **(undefined4 **)(local_e0 + -0x7fa4);
      puVar22 = (undefined4 *)(**(code **)(local_e0 + -0x7658))(unaff_s1,0x79,0,0);
      (**(code **)(local_e0 + -0x7fa8))(uVar5,"MTU too small. Must be at least %ld\n");
    }
    else {
      (**(code **)(local_e0 + -0x7658))(unaff_s1,0x20,0x1000,0);
      puVar22 = socket_mtu;
      iVar4 = (**(code **)(local_e0 + -0x7658))(unaff_s1,0x78,socket_mtu,0);
      if (iVar4 != 0) goto LAB_00443fd4;
      (**(code **)(local_e0 + -0x7fa8))(**(undefined4 **)(local_e0 + -0x7fa4),"Failed to set MTU\n")
      ;
    }
    iStack_118 = -1;
    (**(code **)(local_e0 + -0x7f70))(puVar25);
LAB_00443694:
    if (unaff_s1 != 0) {
      (**(code **)(local_e0 + -0x7fa8))(bio_s_out,"shutting down SSL\n");
      (**(code **)(local_e0 + -0x75d4))(unaff_s1,3);
      (**(code **)(local_e0 + -0x75d0))(unaff_s1);
    }
    (**(code **)(local_e0 + -0x7fa8))(bio_s_out,"CONNECTION CLOSED\n");
    pcVar18 = (char *)0x4000;
    (**(code **)(local_e0 + -0x7d6c))(pcVar3);
    (**(code **)(local_e0 + -0x7f58))(pcVar3);
    unaff_s8 = pcVar3;
    if (-1 < iStack_118) goto LAB_00443714;
  }
  if (local_2c == *local_c4) {
    return iStack_118;
  }
  pcStack_fc = www_body;
  (**(code **)(local_e0 + -0x5330))();
  puVar7 = PTR___stack_chk_guard_006a9ae8;
  puStack_120 = &_gp_1;
  pcVar3 = "s_server.c";
  piVar23 = (int *)0x9f9;
  iStack_124 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_11c = unaff_s1;
  puStack_114 = unaff_s3;
  puStack_110 = (undefined4 *)unaff_s4;
  pcStack_10c = unaff_s5;
  pcStack_108 = unaff_s6;
  pcStack_104 = unaff_s7;
  pcStack_100 = unaff_s8;
  iVar4 = (*(code *)PTR_CRYPTO_malloc_006a7008)(0x4000);
  if (iVar4 == 0) {
    iVar4 = 0;
  }
  else {
    uVar5 = (*(code *)PTR_BIO_f_buffer_006a7854)();
    iVar8 = (*(code *)PTR_BIO_new_006a6ea4)(uVar5);
    uVar5 = (*(code *)PTR_BIO_f_ssl_006a7858)();
    iVar9 = (*(code *)PTR_BIO_new_006a6ea4)(uVar5);
    if (iVar8 != 0) {
      if (iVar9 != 0) {
        if (s_nbio != 0) {
          uStack_128 = 1;
          if (s_quiet == 0) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)PTR_bio_err_006a6e3c,"turning on non blocking io\n");
          }
          iVar10 = (*(code *)PTR_BIO_socket_ioctl_006a77dc)(pcVar18,0x667e,&uStack_128);
          if (iVar10 < 0) {
            (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)PTR_bio_err_006a6e3c);
          }
        }
        piVar23 = (int *)&DAT_00004000;
        iVar10 = (*(code *)PTR_BIO_int_ctrl_006a785c)(iVar8,0x75,0x4000,1);
        if ((iVar10 != 0) && (iVar10 = (*(code *)PTR_SSL_new_006a77e0)(ctx), iVar10 != 0)) {
          if (s_tlsextdebug != 0) {
            (*(code *)PTR_SSL_callback_ctrl_006a7828)(iVar10,0x38,PTR_tlsext_cb_006a782c);
            (*(code *)PTR_SSL_ctrl_006a7788)(iVar10,0x39,0,bio_s_out);
          }
          if (puVar22 != (undefined4 *)0x0) {
            uVar5 = (*(code *)PTR_strlen_006a9a24)(puVar22);
            (*(code *)PTR_SSL_set_session_id_context_006a77e4)(iVar10,puVar22,uVar5);
          }
          uVar5 = (*(code *)PTR_BIO_new_socket_006a77f0)(pcVar18,0);
          if (s_nbio_test != 0) {
            uVar13 = (*(code *)PTR_BIO_f_nbio_test_006a77f4)();
            uVar13 = (*(code *)PTR_BIO_new_006a6ea4)(uVar13);
            uVar5 = (*(code *)PTR_BIO_push_006a74c4)(uVar13,uVar5);
          }
          (*(code *)PTR_SSL_set_bio_006a77f8)(iVar10,uVar5);
          (*(code *)PTR_SSL_set_accept_state_006a77fc)(iVar10);
          piVar23 = (int *)0x1;
          (*(code *)PTR_BIO_ctrl_006a6e18)(iVar9,0x6d,1,iVar10);
          (*(code *)PTR_BIO_push_006a74c4)(iVar8,iVar9);
          if (s_debug != 0) {
            (*(code *)PTR_SSL_set_debug_006a7834)(iVar10,1);
            uVar5 = (*(code *)PTR_SSL_get_rbio_006a7838)(iVar10);
            (*(code *)PTR_BIO_set_callback_006a74dc)(uVar5,PTR_bio_dump_callback_006a783c);
            uVar5 = (*(code *)PTR_SSL_get_rbio_006a7838)(iVar10);
            (*(code *)PTR_BIO_set_callback_arg_006a74e4)(uVar5,bio_s_out);
          }
          if (s_msg != 0) {
            (*(code *)PTR_SSL_set_msg_callback_006a7800)(iVar10,PTR_msg_cb_006a7830);
            piVar23 = (int *)0x0;
            (*(code *)PTR_SSL_ctrl_006a7788)(iVar10,0x10,0,bio_s_out);
          }
LAB_00444704:
          if (hack != 0) {
            iVar9 = (*(code *)PTR_SSL_accept_006a779c)(iVar10);
            while (iVar9 < 1) {
              while( true ) {
                iVar11 = (*(code *)PTR_SSL_get_error_006a77a0)(iVar10,iVar9);
                if (iVar11 != 4) goto LAB_00444800;
                piVar23 = srp_callback_parm._0_4_;
                (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"LOOKUP during accept %s\n");
                (*(code *)PTR_SRP_user_pwd_free_006a77a4)(srp_callback_parm._8_4_);
                srp_callback_parm._8_4_ =
                     (*(code *)PTR_SRP_VBASE_get1_by_user_006a77a8)
                               (srp_callback_parm._4_4_,srp_callback_parm._0_4_);
                if (srp_callback_parm._8_4_ != 0) break;
                (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"LOOKUP not successful\n");
                iVar9 = (*(code *)PTR_SSL_accept_006a779c)(iVar10);
                if (0 < iVar9) goto LAB_00444800;
              }
              piVar23 = *(int **)(srp_callback_parm._8_4_ + 0x14);
              (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"LOOKUP done %s\n");
              iVar9 = (*(code *)PTR_SSL_accept_006a779c)(iVar10);
            }
LAB_00444800:
            uVar12 = (*(code *)PTR_SSL_get_error_006a77a0)(iVar10,iVar9);
            if (uVar12 < 7) {
              uVar12 = 1 << (uVar12 & 0x1f);
              if ((uVar12 & 0x62) != 0) goto LAB_0044455c;
              if ((uVar12 & 0x1c) != 0) goto LAB_00444704;
            }
            (*(code *)PTR_SSL_renegotiate_006a7848)(iVar10);
            (*(code *)PTR_SSL_write_006a7820)(iVar10,0,0);
          }
          piVar23 = (int *)0x3fff;
          iVar9 = (*(code *)PTR_BIO_gets_006a74d4)(iVar8,iVar4);
          if (iVar9 < 0) {
            iVar9 = (*(code *)PTR_BIO_test_flags_006a7868)(iVar8,8);
            if (iVar9 == 0) {
              if (s_quiet == 0) {
                (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)PTR_bio_err_006a6e3c);
              }
              goto LAB_0044455c;
            }
            (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"read R BLOCK\n");
            iVar9 = (*(code *)PTR_BIO_test_flags_006a7868)(iVar8,4);
            if ((iVar9 == 0) ||
               (iVar9 = (*(code *)PTR_BIO_get_retry_reason_006a786c)(iVar8), iVar9 != 1)) {
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
                piVar23 = *(int **)(srp_callback_parm._8_4_ + 0x14);
                (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"LOOKUP done %s\n");
              }
            }
            goto LAB_00444704;
          }
          if (iVar9 == 0) goto LAB_00444e4c;
          if (www != 1) {
            if (www != 2) {
              if (www == 3) goto LAB_00444b44;
              goto LAB_00444704;
            }
            iVar9 = (*(code *)PTR_strncmp_006a9970)("GET /stats ",iVar4,0xb);
            if (iVar9 == 0) goto LAB_004448cc;
LAB_00444b44:
            piVar23 = (int *)&DAT_00000005;
            iVar9 = (*(code *)PTR_strncmp_006a9970)(&DAT_0063b2b0,iVar4);
            puVar2 = PTR_BIO_puts_006a6f58;
            if (iVar9 == 0) goto code_r0x00444b5c;
            goto LAB_00444704;
          }
          piVar23 = (int *)&SUB_00000004;
          iVar9 = (*(code *)PTR_strncmp_006a9970)(&DAT_0063b16c,iVar4);
          if (iVar9 != 0) goto LAB_00444704;
LAB_004448cc:
          (*(code *)PTR_BIO_puts_006a6f58)
                    (iVar8,"HTTP/1.0 200 ok\r\nContent-type: text/html\r\n\r\n");
          (*(code *)PTR_BIO_puts_006a6f58)(iVar8,"<HTML><BODY BGCOLOR=\"#ffffff\">\n");
          (*(code *)PTR_BIO_puts_006a6f58)(iVar8,"<pre>\n");
          (*(code *)PTR_BIO_puts_006a6f58)(iVar8,"\n");
          if (0 < local_argc) {
            iVar9 = 0;
            do {
              iVar11 = iVar9 * 4;
              iVar9 = iVar9 + 1;
              (*(code *)PTR_BIO_puts_006a6f58)(iVar8,*(undefined4 *)(local_argv + iVar11));
              (*(code *)PTR_BIO_write_006a6e14)(iVar8,&DAT_0063eb84,1);
            } while (iVar9 < local_argc);
          }
          (*(code *)PTR_BIO_puts_006a6f58)(iVar8,"\n");
          iVar9 = (*(code *)PTR_SSL_ctrl_006a7788)(iVar10,0x4c,0,0);
          if (iVar9 == 0) {
            pcVar3 = " NOT";
          }
          else {
            pcVar3 = "";
          }
          (*(code *)PTR_BIO_printf_006a6e38)(iVar8,"Secure Renegotiation IS%s supported\n",pcVar3);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar8,"Ciphers supported in s_server binary\n");
          uVar5 = (*(code *)PTR_SSL_get_ciphers_006a7860)(iVar10);
          uVar12 = (*(code *)PTR_sk_num_006a6e2c)(uVar5);
          if (0 < (int)uVar12) {
            uVar13 = (*(code *)PTR_sk_value_006a6e24)(uVar5,0);
            uVar14 = (*(code *)PTR_SSL_CIPHER_get_version_006a7864)(uVar13);
            uVar13 = (*(code *)PTR_SSL_CIPHER_get_name_006a77c0)(uVar13);
            (*(code *)PTR_BIO_printf_006a6e38)(iVar8,"%-11s:%-25s",uVar14,uVar13);
            uVar26 = 1;
            while (uVar12 != uVar26) {
              uVar29 = uVar26 + 1;
              uVar13 = (*(code *)PTR_sk_value_006a6e24)(uVar5,uVar26);
              uVar14 = (*(code *)PTR_SSL_CIPHER_get_version_006a7864)(uVar13);
              uVar13 = (*(code *)PTR_SSL_CIPHER_get_name_006a77c0)(uVar13);
              (*(code *)PTR_BIO_printf_006a6e38)(iVar8,"%-11s:%-25s",uVar14,uVar13);
              uVar26 = uVar29;
              if ((uVar29 & 1) == 0) {
                if (uVar12 == uVar29) break;
                (*(code *)PTR_BIO_puts_006a6f58)(iVar8,"\n");
              }
            }
          }
          (*(code *)PTR_BIO_puts_006a6f58)(iVar8,"\n");
          pcVar3 = (char *)(*(code *)PTR_SSL_get_shared_ciphers_006a77b8)(iVar10,iVar4,0x4000);
          if (pcVar3 != (char *)0x0) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (iVar8,"---\nCiphers common between both SSL end points:\n");
            cVar16 = *pcVar3;
            if (cVar16 != '\0') {
              iVar11 = 0;
              iVar9 = 0;
              do {
                if (cVar16 == ':') {
                  iVar9 = iVar9 + 1;
                  (*(code *)PTR_BIO_write_006a6e14)(iVar8,&DAT_0063b240,0x1a - iVar11);
                  if (iVar9 == (iVar9 / 3) * 3) {
                    puVar22 = (undefined4 *)0x63b2e4;
                  }
                  else {
                    puVar22 = &DAT_0063eb84;
                  }
                  iVar11 = 0;
                  (*(code *)PTR_BIO_write_006a6e14)(iVar8,puVar22,1);
                }
                else {
                  (*(code *)PTR_BIO_write_006a6e14)(iVar8,pcVar3,1);
                  iVar11 = iVar11 + 1;
                }
                pcVar3 = pcVar3 + 1;
                cVar16 = *pcVar3;
              } while (cVar16 != '\0');
            }
            (*(code *)PTR_BIO_puts_006a6f58)(iVar8,"\n");
          }
          iVar9 = (*(code *)PTR_SSL_cache_hit_006a77cc)(iVar10);
          if (iVar9 == 0) {
            pcVar3 = "---\nNew, ";
          }
          else {
            pcVar3 = "---\nReused, ";
          }
          (*(code *)PTR_BIO_printf_006a6e38)(iVar8,pcVar3);
          uVar5 = (*(code *)PTR_SSL_get_current_cipher_006a77bc)(iVar10);
          uVar13 = (*(code *)PTR_SSL_CIPHER_get_version_006a7864)(uVar5);
          uVar5 = (*(code *)PTR_SSL_CIPHER_get_name_006a77c0)(uVar5);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar8,"%s, Cipher is %s\n",uVar13,uVar5);
          uVar5 = (*(code *)PTR_SSL_get_session_006a77ac)(iVar10);
          (*(code *)PTR_SSL_SESSION_print_006a7870)(iVar8,uVar5);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar8,&DAT_0063b270);
          uVar5 = (*(code *)PTR_SSL_get_SSL_CTX_006a7768)(iVar10);
          print_stats(iVar8,uVar5);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar8,&DAT_0063b270);
          iVar9 = (*(code *)PTR_SSL_get_peer_certificate_006a77b4)(iVar10);
          if (iVar9 == 0) {
            (*(code *)PTR_BIO_puts_006a6f58)(iVar8,"no client certificate available\n");
          }
          else {
            (*(code *)PTR_BIO_printf_006a6e38)(iVar8,"Client certificate\n");
            (*(code *)PTR_X509_print_006a70c0)(iVar8,iVar9);
            (*(code *)PTR_PEM_write_bio_X509_006a6f20)(iVar8,iVar9);
          }
          (*(code *)PTR_BIO_puts_006a6f58)(iVar8,"</BODY></HTML>\r\n\r\n");
          goto LAB_00444e2c;
        }
      }
      goto LAB_0044455c;
    }
    pcVar3 = s_ACCEPT_0063b138;
    (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out);
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar4);
    iVar4 = 1;
  }
  goto LAB_00444590;
code_r0x00443880:
  pcVar30 = *(code **)(local_e0 + -0x75dc);
  if ((int)unaff_s3 < 1) goto LAB_00443648;
LAB_00443888:
  uVar5 = (**(code **)(local_e0 + -0x5404))(*puVar25);
  iVar4 = (**(code **)(local_e0 + -0x5340))(uVar5);
  uVar26 = auStack_ac[iVar4];
  uVar12 = (**(code **)(local_e0 + -0x5404))(*puVar25);
  uVar26 = 1 << (uVar12 & 0x1f) & uVar26;
  iVar4 = (**(code **)(local_e0 + -0x5340))(param_2);
  if ((local_cc & auStack_ac[iVar4]) == 0) {
    if (uVar26 == 0) goto switchD_0044411c_caseD_4;
    iVar4 = *(int *)(local_c0 + -0x5ecc);
joined_r0x00443aa4:
    if (iVar4 == 0) {
      unaff_s4 = (char *)raw_read_stdin(pcVar3,0x4000);
LAB_00443ac4:
      unaff_s3 = &_gp_1;
      if (s_quiet == 0) {
        if (((int)unaff_s4 < 1) || (cVar16 = *pcVar3, cVar16 == 'Q')) {
LAB_004442d0:
          unaff_s3 = &_gp_1;
          (**(code **)(local_e0 + -0x7fa8))(bio_s_out,"DONE\n");
          (**(code **)(local_e0 + -0x5484))(param_2,0);
          (**(code **)(local_e0 + -0x5494))(param_2);
          (**(code **)(local_e0 + -0x7fa8))
                    (**(undefined4 **)(local_e0 + -0x7fa4),"shutdown accept socket\n");
          if (accept_socket < 0) {
            iStack_118 = -0xb;
          }
          else {
            (**(code **)(local_e0 + -0x5484))(accept_socket,2);
            iStack_118 = -0xb;
            (**(code **)(local_e0 + -0x5494))(accept_socket);
          }
          goto LAB_00443694;
        }
        if (cVar16 == 'q') {
          (**(code **)(local_e0 + -0x7fa8))(bio_s_out,"DONE\n");
          iVar4 = (**(code **)(local_e0 + -0x75f4))(unaff_s1);
          if (iVar4 != 0xfeff) {
            iStack_118 = 1;
            (**(code **)(local_e0 + -0x5484))(param_2,0);
            (**(code **)(local_e0 + -0x5494))(param_2);
            goto LAB_00443694;
          }
          goto LAB_00443690;
        }
        if (cVar16 == 'B') {
          if ((pcVar3[1] == '\n') || (pcVar3[1] == '\r')) {
            unaff_s3 = &_gp_1;
            (**(code **)(local_e0 + -0x7fa8))
                      (**(undefined4 **)(local_e0 + -0x7fa4),"HEARTBEATING\n");
            puVar22 = (undefined4 *)0x0;
            (**(code **)(local_e0 + -0x7658))(unaff_s1,0x55,0,0);
            goto switchD_0044411c_caseD_4;
          }
        }
        else if (cVar16 == 'r') {
          if ((pcVar3[1] == '\n') || (pcVar3[1] == '\r')) {
            pcVar30 = *(code **)(local_e0 + -0x7598);
LAB_004441cc:
            unaff_s3 = &_gp_1;
            (*pcVar30)(unaff_s1);
            puVar22 = (undefined4 *)(**(code **)(local_e0 + -0x7594))(unaff_s1);
            (**(code **)(local_e0 + -0x541c))(1,"SSL_do_handshake -> %d\n");
            goto switchD_0044411c_caseD_4;
          }
        }
        else if (cVar16 == 'R') {
          if ((pcVar3[1] == '\n') || (pcVar3[1] == '\r')) {
            (**(code **)(local_e0 + -0x759c))(unaff_s1,5,0);
            pcVar30 = *(code **)(local_e0 + -0x7598);
            goto LAB_004441cc;
          }
        }
        else {
          if (cVar16 == 'P') {
            uVar5 = (**(code **)(local_e0 + -0x75c4))(unaff_s1);
            (**(code **)(local_e0 + -0x7fcc))(uVar5,"Lets print some clear text\n",0x1b);
            cVar16 = *pcVar3;
          }
          uVar5 = bio_s_out;
          if (cVar16 == 'S') {
            uVar13 = (**(code **)(local_e0 + -0x7678))(unaff_s1);
            print_stats(uVar5,uVar13);
          }
        }
      }
    }
    else {
      unaff_s4 = (char *)raw_read_stdin(pcVar3,0x2000);
      if (0 < (int)unaff_s4) {
        iVar4 = 0;
        pcVar18 = pcVar3;
        do {
          cVar16 = *pcVar18;
          pcVar18 = pcVar18 + 1;
          iVar4 = iVar4 + (uint)(cVar16 == '\n');
        } while (pcVar3 + (int)unaff_s4 != pcVar18);
        puVar7 = (undefined *)((int)unaff_s4 + -1);
        pcVar24 = pcVar3 + iVar4;
        pcVar18 = pcVar3 + (int)puVar7;
        do {
          while( true ) {
            puVar22 = (undefined4 *)(int)*pcVar18;
            pcVar24[(int)puVar7] = *pcVar18;
            if (*pcVar18 != '\n') break;
            iVar4 = iVar4 + -1;
            unaff_s4 = (char *)((int)unaff_s4 + 1);
            pcVar24 = pcVar3 + iVar4;
            pcVar18 = pcVar18 + -1;
            pcVar19 = pcVar24 + (int)puVar7;
            puVar7 = puVar7 + -1;
            *pcVar19 = '\r';
            if (puVar7 == (undefined *)0xffffffff) goto LAB_004439c0;
          }
          puVar7 = puVar7 + -1;
          pcVar18 = pcVar18 + -1;
        } while (puVar7 != (undefined *)0xffffffff);
LAB_004439c0:
        if (iVar4 != 0) {
          iVar4 = (**(code **)(local_e0 + -0x54a4))
                            ("lf_num == 0",local_bc + -0x5050,0x87e,"sv_body");
          return iVar4;
        }
        goto LAB_00443ac4;
      }
      if (s_quiet == 0) goto LAB_004442d0;
    }
    unaff_s3 = &_gp_1;
    local_d4 = 0;
    do {
      pcVar30 = *(code **)(local_e0 + -0x75c0);
      unaff_s5 = pcVar3 + local_d4;
      while( true ) {
        puVar22 = (undefined4 *)unaff_s4;
        iVar4 = (*pcVar30)(unaff_s1,unaff_s5);
        iVar8 = (**(code **)(local_e0 + -0x7640))(unaff_s1,iVar4);
        if (iVar8 != 4) break;
        (**(code **)(local_e0 + -0x7fa8))(bio_s_out,"LOOKUP renego during write\n");
        (**(code **)(local_e0 + -0x763c))(srp_callback_parm._8_4_);
        srp_callback_parm._8_4_ =
             (**(code **)(local_e0 + -0x7638))(srp_callback_parm._4_4_,srp_callback_parm._0_4_);
        if (srp_callback_parm._8_4_ == 0) {
          (**(code **)(local_e0 + -0x7fa8))(bio_s_out,local_d8);
          pcVar30 = *(code **)(local_e0 + -0x75c0);
        }
        else {
          (**(code **)(local_e0 + -0x7fa8))
                    (bio_s_out,"LOOKUP done %s\n",*(undefined4 *)(srp_callback_parm._8_4_ + 0x14));
          pcVar30 = *(code **)(local_e0 + -0x75c0);
        }
      }
      uVar5 = (**(code **)(local_e0 + -0x7640))(unaff_s1,iVar4);
      switch(uVar5) {
      case 1:
      case 5:
        goto switchD_00443c88_caseD_1;
      case 2:
      case 3:
      case 4:
        (**(code **)(local_e0 + -0x7fa8))(bio_s_out,"Write BLOCK\n");
        break;
      case 6:
        goto switchD_00443c88_caseD_6;
      }
      if (0 < iVar4) {
        unaff_s4 = (char *)((int)unaff_s4 - iVar4);
        local_d4 = local_d4 + iVar4;
      }
    } while (0 < (int)unaff_s4);
    pcVar30 = *(code **)(local_e0 + -0x75d8);
    if (local_d0 == 0) goto switchD_0044411c_caseD_4;
  }
  else {
    local_d0 = 1;
    if (uVar26 != 0) {
      iVar4 = *(int *)(local_c0 + -0x5ecc);
      goto joined_r0x00443aa4;
    }
LAB_0044365c:
    pcVar30 = *(code **)(local_e0 + -0x75d8);
  }
  iVar4 = (*pcVar30)(unaff_s1);
  if (iVar4 == 3) {
    unaff_s3 = &_gp_1;
    unaff_s4 = "LOOKUP renego during read\n";
LAB_004439f8:
    while( true ) {
      puVar22 = (undefined4 *)&DAT_00004000;
      uVar5 = (**(code **)(local_e0 + -0x75c8))(unaff_s1,pcVar3);
      iVar4 = (**(code **)(local_e0 + -0x7640))(unaff_s1,uVar5);
      if (iVar4 != 4) break;
      (**(code **)(local_e0 + -0x7fa8))(bio_s_out,"LOOKUP renego during read\n");
      (**(code **)(local_e0 + -0x763c))(srp_callback_parm._8_4_);
      srp_callback_parm._8_4_ =
           (**(code **)(local_e0 + -0x7638))(srp_callback_parm._4_4_,srp_callback_parm._0_4_);
      if (srp_callback_parm._8_4_ == 0) {
        (**(code **)(local_e0 + -0x7fa8))(bio_s_out,local_d8);
      }
      else {
        (**(code **)(local_e0 + -0x7fa8))
                  (bio_s_out,"LOOKUP done %s\n",*(undefined4 *)(srp_callback_parm._8_4_ + 0x14));
      }
    }
    uVar13 = (**(code **)(local_e0 + -0x7640))(unaff_s1,uVar5);
    switch(uVar13) {
    case 0:
      goto switchD_0044411c_caseD_0;
    case 1:
    case 5:
      goto switchD_00443c88_caseD_1;
    case 2:
    case 3:
      (**(code **)(local_e0 + -0x7fa8))(bio_s_out,"Read BLOCK\n");
    default:
      goto switchD_0044411c_caseD_4;
    case 6:
      goto switchD_00443c88_caseD_6;
    }
  }
  iVar4 = init_ssl_connection(unaff_s1);
  if (iVar4 < 0) {
    iStack_118 = 0;
    goto LAB_00443694;
  }
  pcVar30 = *(code **)(local_e0 + -0x75dc);
  if (iVar4 != 0) goto LAB_00443648;
LAB_00443690:
  iStack_118 = 1;
  goto LAB_00443694;
switchD_00443c88_caseD_6:
  unaff_s3 = &_gp_1;
  iStack_118 = 1;
  (**(code **)(local_e0 + -0x7fa8))(bio_s_out,"DONE\n");
  goto LAB_00443694;
switchD_00443c88_caseD_1:
  unaff_s3 = &_gp_1;
  iStack_118 = 1;
  (**(code **)(local_e0 + -0x7fa8))(bio_s_out,"ERROR\n");
  (**(code **)(local_e0 + -0x7fa0))(**(undefined4 **)(local_e0 + -0x7fa4));
  goto LAB_00443694;
switchD_0044411c_caseD_0:
  raw_write_stdout(pcVar3,uVar5);
  iVar4 = (**(code **)(local_e0 + -0x75dc))(unaff_s1);
  if (iVar4 == 0) goto code_r0x004442ac;
  goto LAB_004439f8;
code_r0x004442ac:
  pcVar30 = *(code **)(local_e0 + -0x75dc);
  goto LAB_00443648;
code_r0x00444b5c:
  bVar1 = *(byte *)(iVar4 + 5);
  puVar27 = (undefined *)(iVar4 + 5);
  if (bVar1 == 0) {
LAB_0044525c:
    (*(code *)PTR_BIO_puts_006a6f58)(iVar8,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
    (*(code *)PTR_BIO_printf_006a6e38)(iVar8,"\'%s\' is an invalid file name\r\n",puVar27);
  }
  else {
    uVar12 = 1;
    puVar20 = puVar27;
    puVar21 = puVar27;
    if (bVar1 != 0x20) {
      do {
        if (uVar12 == 1) {
          bVar17 = bVar1 ^ 0x2f;
          if (bVar1 == 0x2e) {
            bVar17 = puVar20[1];
            if (bVar17 == 0) goto LAB_0044525c;
            puVar21 = puVar20 + 1;
            if (bVar17 == 0x20) goto LAB_004451cc;
            if (bVar17 == 0x2e) {
              bVar17 = puVar20[2];
              if (bVar17 == 0) goto LAB_0044525c;
              puVar21 = puVar20 + 2;
              if (bVar17 == 0x20) goto LAB_004453bc;
              if (bVar17 == 0x2f) {
                if (puVar20[3] == '\0') goto LAB_0044525c;
                puVar21 = puVar20 + 3;
                if (puVar20[3] == ' ') goto LAB_004453bc;
                pcVar3 = puVar20 + 4;
                puVar20 = puVar20 + 4;
                if (*pcVar3 == '\0') goto LAB_0044525c;
                if (*pcVar3 != ' ') {
                  uVar12 = 0xffffffff;
                  goto LAB_00444b98;
                }
                uVar12 = 0xffffffff;
                break;
              }
            }
            puVar20 = puVar21;
            bVar17 = bVar17 ^ 0x2f;
          }
LAB_00444ed0:
          uVar12 = (uint)(bVar17 == 0);
        }
        else {
          bVar17 = bVar1 ^ 0x2f;
          if (uVar12 == 0) goto LAB_00444ed0;
        }
LAB_00444b98:
        bVar1 = puVar20[1];
        puVar20 = puVar20 + 1;
        if (bVar1 == 0) goto LAB_0044525c;
      } while (bVar1 != 0x20);
      puVar21 = puVar20;
      if (uVar12 == 0xffffffff) {
LAB_004453bc:
        *puVar21 = 0;
        (*(code *)puVar2)(iVar8,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
        (*(code *)PTR_BIO_printf_006a6e38)(iVar8,"\'%s\' contains \'..\' reference\r\n",puVar27);
        goto LAB_00444e2c;
      }
    }
LAB_004451cc:
    *puVar21 = 0;
    if (*(char *)(iVar4 + 5) == '/') {
      (*(code *)PTR_BIO_puts_006a6f58)(iVar8,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
      (*(code *)PTR_BIO_printf_006a6e38)(iVar8,"\'%s\' is an invalid path\r\n",puVar27);
    }
    else {
      iVar9 = app_isdir(puVar27);
      if (iVar9 < 1) {
        iVar9 = (*(code *)PTR_BIO_new_file_006a6eac)(puVar27,"r");
        if (iVar9 == 0) {
          (*(code *)PTR_BIO_puts_006a6f58)
                    (iVar8,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
          (*(code *)PTR_BIO_printf_006a6e38)(iVar8,"Error opening \'%s\'\r\n",puVar27);
          (*(code *)PTR_ERR_print_errors_006a6e40)(iVar8);
        }
        else {
          if (s_quiet == 0) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)PTR_bio_err_006a6e3c,"FILE:%s\n",puVar27);
          }
          if (www == 2) {
            iVar11 = (*(code *)PTR_strlen_006a9a24)(puVar27);
            if (iVar11 < 6) {
              if (iVar11 == 5) goto LAB_004454d0;
LAB_00445514:
              (*(code *)PTR_BIO_puts_006a6f58)
                        (iVar8,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
            }
            else {
              iVar28 = (*(code *)PTR_strcmp_006a9b18)(puVar27 + iVar11 + -5,".html");
              if (iVar28 != 0) {
LAB_004454d0:
                iVar28 = (*(code *)PTR_strcmp_006a9b18)(puVar27 + iVar11 + -4,&DAT_0063b360);
                if ((iVar28 != 0) &&
                   (iVar11 = (*(code *)PTR_strcmp_006a9b18)(puVar27 + iVar11 + -4,&DAT_0063b368),
                   iVar11 != 0)) goto LAB_00445514;
              }
              (*(code *)PTR_BIO_puts_006a6f58)
                        (iVar8,"HTTP/1.0 200 ok\r\nContent-type: text/html\r\n\r\n");
            }
          }
          while (iVar11 = (*(code *)PTR_BIO_read_006a74c0)(iVar9,iVar4,0x4000), 0 < iVar11) {
            iVar28 = 0;
            do {
              iVar15 = (*(code *)PTR_BIO_write_006a6e14)(iVar8,iVar4 + iVar28,iVar11 - iVar28);
              if (iVar15 < 1) {
                iVar15 = (*(code *)PTR_BIO_test_flags_006a7868)(iVar8,8);
                if (iVar15 == 0) goto LAB_00445364;
                (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"rwrite W BLOCK\n");
              }
              else {
                iVar28 = iVar28 + iVar15;
              }
            } while (iVar28 < iVar11);
          }
LAB_00445364:
          (*(code *)PTR_BIO_free_006a6e70)(iVar9);
        }
      }
      else {
        (*(code *)PTR_BIO_puts_006a6f58)
                  (iVar8,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
        (*(code *)PTR_BIO_printf_006a6e38)(iVar8,"\'%s\' is a directory\r\n",puVar27);
      }
    }
  }
LAB_00444e2c:
  do {
    piVar23 = (int *)0x0;
    iVar9 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar8,0xb,0,0);
    if (0 < iVar9) break;
    iVar9 = (*(code *)PTR_BIO_test_flags_006a7868)(iVar8,8);
  } while (iVar9 != 0);
LAB_00444e4c:
  (*(code *)PTR_SSL_set_shutdown_006a780c)(iVar10,3);
LAB_0044455c:
  pcVar3 = s_ACCEPT_0063b138;
  (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out);
  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar4);
  (*(code *)PTR_BIO_free_all_006a6e74)(iVar8);
  iVar4 = 1;
LAB_00444590:
  if (iStack_124 == *(int *)puVar7) {
    return iVar4;
  }
  iVar4 = iStack_124;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar8 = piVar23[2];
  if (*piVar23 == 0) {
    if (iVar8 == 0) {
      iVar4 = (*(code *)PTR_SSL_get_srp_username_006a7878)();
      *piVar23 = iVar4;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,"SRP username = \"%s\"\n",iVar4);
      return -1;
    }
  }
  else if (iVar8 == 0) {
    iVar4 = 2;
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,"User %s doesn\'t exist\n");
    goto LAB_004455d4;
  }
  iVar4 = (*(code *)PTR_SSL_set_srp_server_param_006a7874)
                    (iVar4,*(undefined4 *)(iVar8 + 0x10),*(undefined4 *)(iVar8 + 0xc),
                     *(undefined4 *)(iVar8 + 4),*(undefined4 *)(iVar8 + 8),
                     *(undefined4 *)(iVar8 + 0x14));
  if (iVar4 < 0) {
    iVar4 = 2;
    *(undefined4 *)pcVar3 = 0x50;
  }
  else {
    iVar4 = 0;
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,
               "SRP parameters set: username = \"%s\" info=\"%s\" \n",*piVar23,
               *(undefined4 *)(piVar23[2] + 0x14));
  }
LAB_004455d4:
  (*(code *)PTR_SRP_user_pwd_free_006a77a4)(piVar23[2]);
  piVar23[2] = 0;
  *piVar23 = 0;
  return iVar4;
}

