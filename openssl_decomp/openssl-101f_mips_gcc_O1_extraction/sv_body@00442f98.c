
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int sv_body(undefined4 param_1,uint param_2,int param_3)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  char cVar15;
  char *pcVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  byte bVar16;
  int iVar14;
  char *pcVar17;
  char *pcVar18;
  char *pcVar19;
  undefined4 *puVar20;
  int unaff_s0;
  undefined4 *puVar21;
  uint uVar22;
  undefined1 *unaff_s3;
  char *unaff_s4;
  char *unaff_s5;
  char *unaff_s6;
  uint uVar23;
  char *unaff_s7;
  code *pcVar24;
  char *unaff_s8;
  undefined4 uStack_128;
  int iStack_124;
  int iStack_120;
  undefined1 *puStack_11c;
  int iStack_118;
  undefined1 *puStack_114;
  undefined4 *puStack_110;
  char *pcStack_10c;
  char *pcStack_108;
  char *pcStack_104;
  char *pcStack_100;
  code *pcStack_fc;
  undefined4 *local_e8;
  undefined *local_e0;
  int local_d8;
  char *local_d4;
  int local_d0;
  uint local_cc;
  int local_c8;
  int *local_c4;
  undefined1 *local_c0;
  char *local_bc;
  undefined4 local_b4;
  undefined4 local_b0;
  uint auStack_ac [32];
  int local_2c;
  
  puVar20 = (undefined4 *)0x7b3;
  local_e0 = &_gp;
  local_c4 = (int *)PTR___stack_chk_guard_006aabf0;
  local_bc = "s\n";
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pcVar4 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x4000,"s_server.c");
  if (pcVar4 != (char *)0x0) {
    if (s_nbio != 0) {
      local_b4 = 1;
      if (s_quiet == 0) {
        (**(code **)(local_e0 + -0x7fa8))
                  (**(undefined4 **)(local_e0 + -0x7fa4),"turning on non blocking io\n");
      }
      iVar5 = (**(code **)(local_e0 + -0x7618))(param_2,0x667e,&local_b4);
      if (iVar5 < 0) {
        (**(code **)(local_e0 + -0x7fa0))(**(undefined4 **)(local_e0 + -0x7fa4));
      }
    }
    unaff_s4 = &_ITM_registerTMCloneTable;
    unaff_s3 = &_ITM_registerTMCloneTable;
    unaff_s0 = (**(code **)(local_e0 + -0x7614))(ctx);
    if (s_tlsextdebug != 0) {
      (**(code **)(local_e0 + -0x75cc))(unaff_s0,0x38,*(undefined4 *)(local_e0 + -0x75c8));
      (**(code **)(local_e0 + -0x7668))(unaff_s0,0x39,0,bio_s_out);
    }
    if (s_tlsextstatus != 0) {
      (**(code **)(local_e0 + -0x75d0))(ctx,0x3f,cert_status_cb);
      tlscstatp._20_4_ = **(undefined4 **)(local_e0 + -0x7fa4);
      (**(code **)(local_e0 + -0x7694))(ctx,0x40,0,tlscstatp);
    }
    if (param_3 != 0) {
      uVar6 = (**(code **)(local_e0 + -0x53b0))(param_3);
      (**(code **)(local_e0 + -0x7610))(unaff_s0,param_3,uVar6);
    }
    (**(code **)(local_e0 + -0x760c))(unaff_s0);
    iVar5 = (**(code **)(local_e0 + -0x7608))(unaff_s0);
    if (iVar5 == 0xfeff) {
      puVar20 = (undefined4 *)(**(code **)(local_e0 + -0x75b4))(param_2,0);
      if (enable_timeouts != 0) {
        unaff_s4 = (char *)&local_b4;
        local_b4 = 0;
        local_b0 = 250000;
        (**(code **)(local_e0 + -0x7fc8))(puVar20,0x21,0,unaff_s4);
        local_b4 = 0;
        local_b0 = 250000;
        (**(code **)(local_e0 + -0x7fc8))(puVar20,0x23,0,unaff_s4);
      }
      if (socket_mtu < 0x1d) {
        (**(code **)(local_e0 + -0x7fc8))(puVar20,0x27,0,0);
      }
      else {
        (**(code **)(local_e0 + -0x7668))(unaff_s0,0x20,0x1000,0);
        (**(code **)(local_e0 + -0x7668))(unaff_s0,0x11,socket_mtu + -0x1c,0);
      }
      (**(code **)(local_e0 + -0x7668))(unaff_s0,0x20,0x2000,0);
    }
    else {
      puVar20 = (undefined4 *)(**(code **)(local_e0 + -0x7604))(param_2,0);
    }
    if (s_nbio_test != 0) {
      uVar6 = (**(code **)(local_e0 + -0x7600))();
      uVar6 = (**(code **)(local_e0 + -0x7f3c))(uVar6);
      puVar20 = (undefined4 *)(**(code **)(local_e0 + -0x7920))(uVar6,puVar20);
    }
    (**(code **)(local_e0 + -0x75fc))(unaff_s0,puVar20);
    (**(code **)(local_e0 + -0x75f8))(unaff_s0);
    if (s_debug != 0) {
      (**(code **)(local_e0 + -0x75c0))(unaff_s0,1);
      uVar6 = (**(code **)(local_e0 + -0x75bc))(unaff_s0);
      (**(code **)(local_e0 + -0x7908))(uVar6,*(undefined4 *)(local_e0 + -0x75b8));
      uVar6 = (**(code **)(local_e0 + -0x75bc))(unaff_s0);
      (**(code **)(local_e0 + -0x7900))(uVar6,bio_s_out);
    }
    if (s_msg != 0) {
      (**(code **)(local_e0 + -0x75f4))(unaff_s0,*(undefined4 *)(local_e0 + -0x75c4));
      puVar20 = (undefined4 *)0x0;
      (**(code **)(local_e0 + -0x7668))(unaff_s0,0x10,0,bio_s_out);
    }
    if (s_tlsextdebug != 0) {
      (**(code **)(local_e0 + -0x75cc))(unaff_s0,0x38,*(undefined4 *)(local_e0 + -0x75c8));
      puVar20 = (undefined4 *)0x0;
      (**(code **)(local_e0 + -0x7668))(unaff_s0,0x39,0,bio_s_out);
    }
    local_c8 = param_2 + 1;
    local_cc = 1 << (param_2 & 0x1f);
    unaff_s6 = "LOOKUP renego during write\n";
    unaff_s7 = "LOOKUP done %s\n";
    local_c0 = &_ITM_registerTMCloneTable;
    local_d4 = "LOOKUP not successful\n";
switchD_00443bc8_caseD_4:
    pcVar24 = *(code **)(local_e0 + -0x75f0);
LAB_004431a8:
    while (local_d0 = (*pcVar24)(unaff_s0), local_d0 == 0) {
      puVar21 = *(undefined4 **)(local_e0 + -0x53c0);
      (**(code **)(local_e0 + -0x53e0))(auStack_ac,0,0x80);
      unaff_s4 = (char *)(**(code **)(local_e0 + -0x53f8))(*puVar21);
      uVar6 = (**(code **)(local_e0 + -0x53f8))(*puVar21);
      iVar5 = (**(code **)(local_e0 + -0x5338))(uVar6);
      pcVar24 = *(code **)(local_e0 + -0x5338);
      auStack_ac[iVar5] = 1 << ((uint)unaff_s4 & 0x1f) | auStack_ac[iVar5];
      iVar5 = (*pcVar24)(param_2);
      pcVar24 = *(code **)(local_e0 + -0x7608);
      auStack_ac[iVar5] = auStack_ac[iVar5] | local_cc;
      iVar5 = (*pcVar24)(unaff_s0);
      if (iVar5 == 0xfeff) {
        puVar7 = &local_b4;
        iVar5 = (**(code **)(local_e0 + -0x7668))(unaff_s0,0x49,0,puVar7);
        unaff_s4 = (char *)puVar7;
        if (iVar5 == 0) goto LAB_004433a0;
      }
      else {
LAB_004433a0:
        puVar7 = (undefined4 *)0x0;
      }
      puVar20 = (undefined4 *)0x0;
      local_e8 = puVar7;
      unaff_s3 = (undefined1 *)(**(code **)(local_e0 + -0x5314))(local_c8,auStack_ac,0,0);
      iVar5 = (**(code **)(local_e0 + -0x7608))(unaff_s0);
      if (iVar5 == 0xfeff) goto LAB_00443bd0;
      pcVar24 = *(code **)(local_e0 + -0x75f0);
      if (0 < (int)unaff_s3) goto LAB_004433e8;
    }
    goto LAB_004431bc;
  }
  iVar5 = 1;
  (**(code **)(local_e0 + -0x7fa8))(**(undefined4 **)(local_e0 + -0x7fa4),"out of memory\n");
  (**(code **)(local_e0 + -0x7fa8))(bio_s_out,"CONNECTION CLOSED\n");
LAB_00443274:
  pcVar17 = s_ACCEPT_0063b91c;
  (**(code **)(local_e0 + -0x7fa8))(bio_s_out,s_ACCEPT_0063b91c);
LAB_0044328c:
  if (local_2c == *local_c4) {
    return iVar5;
  }
  pcStack_fc = www_body;
  (**(code **)(local_e0 + -0x5328))();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  puStack_11c = &_ITM_registerTMCloneTable;
  pcVar4 = "s_server.c";
  iStack_124 = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_120 = unaff_s0;
  iStack_118 = iVar5;
  puStack_114 = unaff_s3;
  puStack_110 = (undefined4 *)unaff_s4;
  pcStack_10c = unaff_s5;
  pcStack_108 = unaff_s6;
  pcStack_104 = unaff_s7;
  pcStack_100 = unaff_s8;
  pcVar8 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x4000,"s_server.c",0xa09);
  if (pcVar8 == (char *)0x0) {
    iVar9 = 0;
    goto LAB_0044402c;
  }
  uVar6 = (*(code *)PTR_BIO_f_buffer_006a8940)();
  unaff_s7 = (char *)(*(code *)PTR_BIO_new_006a7fa4)(uVar6);
  uVar6 = (*(code *)PTR_BIO_f_ssl_006a8944)();
  iVar9 = (*(code *)PTR_BIO_new_006a7fa4)(uVar6);
  if (unaff_s7 == (char *)0x0) {
    pcVar4 = s_ACCEPT_0063b91c;
    (*(code *)PTR_BIO_printf_006a7f38)(bio_s_out);
    (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar8);
    iVar9 = 1;
    unaff_s8 = pcVar8;
    goto LAB_0044402c;
  }
  if (iVar9 == 0) {
LAB_00444324:
    unaff_s3 = &_ITM_registerTMCloneTable;
    uVar6 = bio_s_out;
    goto LAB_00443ff8;
  }
  if (s_nbio != 0) {
    uStack_128 = 1;
    if (s_quiet == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,"turning on non blocking io\n");
    }
    iVar10 = (*(code *)PTR_BIO_socket_ioctl_006a88c8)(pcVar17,0x667e,&uStack_128);
    if (iVar10 < 0) {
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
    }
  }
  iVar10 = (*(code *)PTR_BIO_int_ctrl_006a8948)(unaff_s7,0x75,0x4000,1);
  uVar6 = bio_s_out;
  if (iVar10 == 0) goto LAB_00443ff8;
  iVar5 = (*(code *)PTR_SSL_new_006a88cc)(ctx);
  if (iVar5 == 0) goto LAB_00444324;
  if (s_tlsextdebug != 0) {
    (*(code *)PTR_SSL_callback_ctrl_006a8914)(iVar5,0x38,PTR_tlsext_cb_006a8918);
    (*(code *)PTR_SSL_ctrl_006a8878)(iVar5,0x39,0,bio_s_out);
  }
  unaff_s3 = &_ITM_registerTMCloneTable;
  if (puVar20 != (undefined4 *)0x0) {
    uVar6 = (*(code *)PTR_strlen_006aab30)(puVar20);
    (*(code *)PTR_SSL_set_session_id_context_006a88d0)(iVar5,puVar20,uVar6);
  }
  uVar6 = (*(code *)PTR_BIO_new_socket_006a88dc)(pcVar17,0);
  if (s_nbio_test != 0) {
    uVar12 = (*(code *)PTR_BIO_f_nbio_test_006a88e0)();
    uVar12 = (*(code *)PTR_BIO_new_006a7fa4)(uVar12);
    uVar6 = (*(code *)PTR_BIO_push_006a85c0)(uVar12,uVar6);
  }
  (*(code *)PTR_SSL_set_bio_006a88e4)(iVar5,uVar6);
  (*(code *)PTR_SSL_set_accept_state_006a88e8)(iVar5);
  (*(code *)PTR_BIO_ctrl_006a7f18)(iVar9,0x6d,1,iVar5);
  (*(code *)PTR_BIO_push_006a85c0)(unaff_s7,iVar9);
  if (s_debug != 0) {
    (*(code *)PTR_SSL_set_debug_006a8920)(iVar5,1);
    uVar6 = (*(code *)PTR_SSL_get_rbio_006a8924)(iVar5);
    (*(code *)PTR_BIO_set_callback_006a85d8)(uVar6,PTR_bio_dump_callback_006a8928);
    uVar6 = (*(code *)PTR_SSL_get_rbio_006a8924)(iVar5);
    (*(code *)PTR_BIO_set_callback_arg_006a85e0)(uVar6,bio_s_out);
  }
  if (s_msg != 0) {
    (*(code *)PTR_SSL_set_msg_callback_006a88ec)(iVar5,PTR_msg_cb_006a891c);
    (*(code *)PTR_SSL_ctrl_006a8878)(iVar5,0x10,0,bio_s_out);
  }
LAB_0044419c:
  if (hack != 0) {
    iVar9 = (*(code *)PTR_SSL_accept_006a888c)(iVar5);
    if (iVar9 < 1) {
      pcVar17 = &_ITM_registerTMCloneTable;
      do {
        while( true ) {
          iVar10 = (*(code *)PTR_SSL_get_error_006a8890)(iVar5,iVar9);
          if (iVar10 != 4) goto LAB_00444274;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (bio_s_out,"LOOKUP during accept %s\n",srp_callback_parm._0_4_);
          srp_callback_parm._8_4_ =
               (*(code *)PTR_SRP_VBASE_get_by_user_006a8894)
                         (srp_callback_parm._4_4_,srp_callback_parm._0_4_);
          if (srp_callback_parm._8_4_ != 0) break;
          (*(code *)PTR_BIO_printf_006a7f38)(bio_s_out,"LOOKUP not successful\n");
          iVar9 = (*(code *)PTR_SSL_accept_006a888c)(iVar5);
          if (0 < iVar9) goto LAB_00444274;
        }
        (*(code *)PTR_BIO_printf_006a7f38)
                  (bio_s_out,"LOOKUP done %s\n",*(undefined4 *)(srp_callback_parm._8_4_ + 0x14));
        iVar9 = (*(code *)PTR_SSL_accept_006a888c)(iVar5);
      } while (iVar9 < 1);
    }
LAB_00444274:
    uVar11 = (*(code *)PTR_SSL_get_error_006a8890)(iVar5,iVar9);
    if (uVar11 < 7) {
      uVar11 = 1 << (uVar11 & 0x1f);
      if ((uVar11 & 0x62) != 0) goto LAB_00444324;
      if ((uVar11 & 0x1c) != 0) goto LAB_0044419c;
    }
    (*(code *)PTR_SSL_renegotiate_006a8934)(iVar5);
    (*(code *)PTR_SSL_write_006a890c)(iVar5,0,0);
  }
  iVar9 = (*(code *)PTR_BIO_gets_006a85d0)(unaff_s7,pcVar8,0x3fff);
  if (iVar9 < 0) {
    iVar9 = (*(code *)PTR_BIO_test_flags_006a8954)(unaff_s7,8);
    if (iVar9 == 0) {
      if (s_quiet == 0) {
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
        uVar6 = bio_s_out;
        goto LAB_00443ff8;
      }
      goto LAB_00444324;
    }
    (*(code *)PTR_BIO_printf_006a7f38)(bio_s_out,"read R BLOCK\n");
    (*(code *)PTR_sleep_006aabd0)(1);
    goto LAB_0044419c;
  }
  if (iVar9 == 0) goto LAB_004449d8;
  if (www != 1) {
    if (www != 2) {
      if (www == 3) goto LAB_004445d0;
      goto LAB_0044419c;
    }
    iVar9 = (*(code *)PTR_strncmp_006aaa7c)("GET /stats ",pcVar8,10);
    if (iVar9 == 0) goto LAB_00444350;
LAB_004445d0:
    iVar9 = (*(code *)PTR_strncmp_006aaa7c)(&DAT_0063ba94,pcVar8,5);
    if (iVar9 == 0) goto code_r0x004445e8;
    goto LAB_0044419c;
  }
  iVar9 = (*(code *)PTR_strncmp_006aaa7c)(&DAT_0063b950,pcVar8,4);
  if (iVar9 != 0) goto LAB_0044419c;
LAB_00444350:
  (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/html\r\n\r\n");
  (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"<HTML><BODY BGCOLOR=\"#ffffff\">\n");
  (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"<pre>\n");
  (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"\n");
  if (0 < local_argc) {
    iVar9 = 0;
    do {
      iVar10 = iVar9 * 4;
      iVar9 = iVar9 + 1;
      (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,*(undefined4 *)(local_argv + iVar10));
      (*(code *)PTR_BIO_write_006a7f14)(unaff_s7,&DAT_0063f0b8,1);
    } while (iVar9 < local_argc);
  }
  (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"\n");
  iVar9 = (*(code *)PTR_SSL_ctrl_006a8878)(iVar5,0x4c,0,0);
  if (iVar9 == 0) {
    pcVar4 = " NOT";
  }
  else {
    pcVar4 = "";
  }
  (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"Secure Renegotiation IS%s supported\n",pcVar4);
  (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"Ciphers supported in s_server binary\n");
  uVar6 = (*(code *)PTR_SSL_get_ciphers_006a894c)(iVar5);
  uVar11 = (*(code *)PTR_sk_num_006a7f2c)(uVar6);
  if (0 < (int)uVar11) {
    uVar12 = (*(code *)PTR_sk_value_006a7f24)(uVar6,0);
    uVar13 = (*(code *)PTR_SSL_CIPHER_get_version_006a8950)(uVar12);
    uVar12 = (*(code *)PTR_SSL_CIPHER_get_name_006a88ac)(uVar12);
    (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"%-11s:%-25s",uVar13,uVar12);
    uVar22 = 1;
    while (uVar11 != uVar22) {
      uVar23 = uVar22 + 1;
      uVar12 = (*(code *)PTR_sk_value_006a7f24)(uVar6,uVar22);
      uVar13 = (*(code *)PTR_SSL_CIPHER_get_version_006a8950)(uVar12);
      uVar12 = (*(code *)PTR_SSL_CIPHER_get_name_006a88ac)(uVar12);
      (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"%-11s:%-25s",uVar13,uVar12);
      uVar22 = uVar23;
      if ((uVar23 & 1) == 0) {
        if (uVar11 == uVar23) break;
        (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"\n");
      }
    }
  }
  (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"\n");
  pcVar4 = (char *)(*(code *)PTR_SSL_get_shared_ciphers_006a88a4)(iVar5,pcVar8,0x4000);
  if (pcVar4 != (char *)0x0) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (unaff_s7,"---\nCiphers common between both SSL end points:\n");
    cVar15 = *pcVar4;
    if (cVar15 != '\0') {
      iVar10 = 0;
      iVar9 = 0;
      do {
        if (cVar15 == ':') {
          iVar9 = iVar9 + 1;
          (*(code *)PTR_BIO_write_006a7f14)(unaff_s7,&DAT_0063ba24,0x1a - iVar10);
          if (iVar9 == (iVar9 / 3) * 3) {
            puVar20 = (undefined4 *)0x63bac8;
          }
          else {
            puVar20 = &DAT_0063f0b8;
          }
          iVar10 = 0;
          (*(code *)PTR_BIO_write_006a7f14)(unaff_s7,puVar20,1);
        }
        else {
          (*(code *)PTR_BIO_write_006a7f14)(unaff_s7,pcVar4,1);
          iVar10 = iVar10 + 1;
        }
        pcVar4 = pcVar4 + 1;
        cVar15 = *pcVar4;
      } while (cVar15 != '\0');
    }
    (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"\n");
  }
  iVar9 = (*(code *)PTR_SSL_cache_hit_006a88b8)(iVar5);
  if (iVar9 == 0) {
    pcVar4 = "---\nNew, ";
  }
  else {
    pcVar4 = "---\nReused, ";
  }
  (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,pcVar4);
  uVar6 = (*(code *)PTR_SSL_get_current_cipher_006a88a8)(iVar5);
  uVar12 = (*(code *)PTR_SSL_CIPHER_get_version_006a8950)(uVar6);
  uVar6 = (*(code *)PTR_SSL_CIPHER_get_name_006a88ac)(uVar6);
  (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"%s, Cipher is %s\n",uVar12,uVar6);
  uVar6 = (*(code *)PTR_SSL_get_session_006a8898)(iVar5);
  (*(code *)PTR_SSL_SESSION_print_006a8958)(unaff_s7,uVar6);
  (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,&DAT_0063ba54);
  uVar6 = (*(code *)PTR_SSL_get_SSL_CTX_006a8858)(iVar5);
  print_stats(unaff_s7,uVar6);
  (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,&DAT_0063ba54);
  pcVar17 = (char *)(*(code *)PTR_SSL_get_peer_certificate_006a88a0)(iVar5);
  if (pcVar17 == (char *)0x0) {
    (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"no client certificate available\n");
  }
  else {
    (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"Client certificate\n");
    (*(code *)PTR_X509_print_006a81c0)(unaff_s7,pcVar17);
    (*(code *)PTR_PEM_write_bio_X509_006a8020)(unaff_s7,pcVar17);
  }
  (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"</BODY></HTML>\r\n\r\n");
  goto LAB_004449b8;
LAB_00443bd0:
  puVar20 = (undefined4 *)0x0;
  iVar5 = (**(code **)(local_e0 + -0x7668))(unaff_s0,0x4a,0,0);
  if (0 < iVar5) {
    (**(code **)(local_e0 + -0x7fa8))(**(undefined4 **)(local_e0 + -0x7fa4),"TIMEOUT occured\n");
  }
  pcVar24 = *(code **)(local_e0 + -0x75f0);
  if ((int)unaff_s3 < 1) goto LAB_004431a8;
LAB_004433e8:
  uVar6 = (**(code **)(local_e0 + -0x53f8))(*puVar21);
  iVar5 = (**(code **)(local_e0 + -0x5338))(uVar6);
  uVar22 = auStack_ac[iVar5];
  uVar11 = (**(code **)(local_e0 + -0x53f8))(*puVar21);
  uVar22 = 1 << (uVar11 & 0x1f) & uVar22;
  iVar5 = (**(code **)(local_e0 + -0x5338))(param_2);
  if ((local_cc & auStack_ac[iVar5]) == 0) {
    if (uVar22 == 0) goto switchD_00443bc8_caseD_4;
    iVar5 = *(int *)(local_c0 + -0x4dbc);
joined_r0x004435f4:
    if (iVar5 == 0) {
      unaff_s4 = (char *)raw_read_stdin(pcVar4,0x4000);
LAB_00443614:
      if (s_quiet == 0) {
        if (((int)unaff_s4 < 1) || (cVar15 = *pcVar4, cVar15 == 'Q')) {
LAB_00443dc8:
          (**(code **)(local_e0 + -0x7fa8))(bio_s_out,"DONE\n");
          (**(code **)(local_e0 + -0x5474))(param_2,0);
          (**(code **)(local_e0 + -0x5484))(param_2);
          (**(code **)(local_e0 + -0x7fa8))
                    (**(undefined4 **)(local_e0 + -0x7fa4),"shutdown accept socket\n");
          if (accept_socket < 0) {
            iVar5 = -0xb;
          }
          else {
            (**(code **)(local_e0 + -0x5474))(accept_socket,2);
            iVar5 = -0xb;
            (**(code **)(local_e0 + -0x5484))(accept_socket);
          }
          goto LAB_004431f4;
        }
        if (cVar15 == 'q') {
          (**(code **)(local_e0 + -0x7fa8))(bio_s_out,"DONE\n");
          iVar5 = (**(code **)(local_e0 + -0x7608))(unaff_s0);
          if (iVar5 != 0xfeff) {
            iVar5 = 1;
            (**(code **)(local_e0 + -0x5474))(param_2,0);
            (**(code **)(local_e0 + -0x5484))(param_2);
            goto LAB_004431f4;
          }
          goto LAB_004431f0;
        }
        if (cVar15 == 'B') {
          if ((pcVar4[1] == '\n') || (pcVar4[1] == '\r')) {
            (**(code **)(local_e0 + -0x7fa8))
                      (**(undefined4 **)(local_e0 + -0x7fa4),"HEARTBEATING\n");
            puVar20 = (undefined4 *)0x0;
            (**(code **)(local_e0 + -0x7668))(unaff_s0,0x55,0,0);
            goto switchD_00443bc8_caseD_4;
          }
        }
        else if (cVar15 == 'r') {
          if ((pcVar4[1] == '\n') || (pcVar4[1] == '\r')) {
            pcVar24 = *(code **)(local_e0 + -0x75ac);
LAB_00443cc4:
            (*pcVar24)(unaff_s0);
            puVar20 = (undefined4 *)(**(code **)(local_e0 + -0x75a8))(unaff_s0);
            (**(code **)(local_e0 + -0x5410))(1,"SSL_do_handshake -> %d\n");
            goto switchD_00443bc8_caseD_4;
          }
        }
        else if (cVar15 == 'R') {
          if ((pcVar4[1] == '\n') || (pcVar4[1] == '\r')) {
            (**(code **)(local_e0 + -0x75b0))(unaff_s0,5,0);
            pcVar24 = *(code **)(local_e0 + -0x75ac);
            goto LAB_00443cc4;
          }
        }
        else {
          if (cVar15 == 'P') {
            uVar6 = (**(code **)(local_e0 + -0x75d8))(unaff_s0);
            (**(code **)(local_e0 + -0x7fcc))(uVar6,"Lets print some clear text\n",0x1b);
            cVar15 = *pcVar4;
          }
          uVar6 = bio_s_out;
          if (cVar15 == 'S') {
            uVar12 = (**(code **)(local_e0 + -0x7688))(unaff_s0);
            print_stats(uVar6,uVar12);
          }
        }
      }
    }
    else {
      unaff_s4 = (char *)raw_read_stdin(pcVar4,0x2000);
      if (0 < (int)unaff_s4) {
        iVar5 = 0;
        pcVar17 = pcVar4;
        do {
          cVar15 = *pcVar17;
          pcVar17 = pcVar17 + 1;
          iVar5 = iVar5 + (uint)(cVar15 == '\n');
        } while (pcVar4 + (int)unaff_s4 != pcVar17);
        pcVar17 = (char *)((int)unaff_s4 + -1);
        pcVar19 = pcVar4 + iVar5;
        pcVar8 = pcVar4 + (int)pcVar17;
        do {
          while( true ) {
            puVar20 = (undefined4 *)(int)*pcVar8;
            pcVar19[(int)pcVar17] = *pcVar8;
            if (*pcVar8 != '\n') break;
            iVar5 = iVar5 + -1;
            unaff_s4 = (char *)((int)unaff_s4 + 1);
            pcVar19 = pcVar4 + iVar5;
            pcVar8 = pcVar8 + -1;
            pcVar18 = pcVar19 + (int)pcVar17;
            pcVar17 = pcVar17 + -1;
            *pcVar18 = '\r';
            if (pcVar17 == (char *)0xffffffff) goto LAB_00443520;
          }
          pcVar17 = pcVar17 + -1;
          pcVar8 = pcVar8 + -1;
        } while (pcVar17 != (char *)0xffffffff);
LAB_00443520:
        if (iVar5 != 0) {
          iVar5 = (**(code **)(local_e0 + -0x5494))
                            ("lf_num == 0",local_bc + -0x4830,0x880,"sv_body");
          return iVar5;
        }
        goto LAB_00443614;
      }
      if (s_quiet == 0) goto LAB_00443dc8;
    }
    local_d8 = 0;
    unaff_s3 = &_ITM_registerTMCloneTable;
    do {
      pcVar24 = *(code **)(local_e0 + -0x75d4);
      unaff_s5 = pcVar4 + local_d8;
      while( true ) {
        puVar20 = (undefined4 *)unaff_s4;
        iVar5 = (*pcVar24)(unaff_s0,unaff_s5);
        iVar9 = (**(code **)(local_e0 + -0x7650))(unaff_s0,iVar5);
        if (iVar9 != 4) break;
        (**(code **)(local_e0 + -0x7fa8))(bio_s_out,"LOOKUP renego during write\n");
        srp_callback_parm._8_4_ =
             (**(code **)(local_e0 + -0x764c))(srp_callback_parm._4_4_,srp_callback_parm._0_4_);
        if (srp_callback_parm._8_4_ == 0) {
          (**(code **)(local_e0 + -0x7fa8))(bio_s_out,local_d4);
          pcVar24 = *(code **)(local_e0 + -0x75d4);
        }
        else {
          (**(code **)(local_e0 + -0x7fa8))
                    (bio_s_out,"LOOKUP done %s\n",*(undefined4 *)(srp_callback_parm._8_4_ + 0x14));
          pcVar24 = *(code **)(local_e0 + -0x75d4);
        }
      }
      uVar6 = (**(code **)(local_e0 + -0x7650))(unaff_s0,iVar5);
      switch(uVar6) {
      case 1:
      case 5:
        goto switchD_004437c8_caseD_1;
      case 2:
      case 3:
      case 4:
        (**(code **)(local_e0 + -0x7fa8))(bio_s_out,"Write BLOCK\n");
        break;
      case 6:
        goto switchD_004437c8_caseD_6;
      }
      unaff_s4 = (char *)((int)unaff_s4 - iVar5);
      local_d8 = local_d8 + iVar5;
    } while (0 < (int)unaff_s4);
    pcVar24 = *(code **)(local_e0 + -0x75ec);
    if (local_d0 == 0) goto switchD_00443bc8_caseD_4;
  }
  else {
    local_d0 = 1;
    if (uVar22 != 0) {
      iVar5 = *(int *)(local_c0 + -0x4dbc);
      goto joined_r0x004435f4;
    }
LAB_004431bc:
    pcVar24 = *(code **)(local_e0 + -0x75ec);
  }
  iVar5 = (*pcVar24)(unaff_s0);
  if (iVar5 == 3) {
    unaff_s3 = &_ITM_registerTMCloneTable;
    unaff_s4 = "LOOKUP renego during read\n";
LAB_00443558:
    while( true ) {
      puVar20 = (undefined4 *)0x4000;
      uVar6 = (**(code **)(local_e0 + -0x75dc))(unaff_s0,pcVar4);
      iVar5 = (**(code **)(local_e0 + -0x7650))(unaff_s0,uVar6);
      if (iVar5 != 4) break;
      (**(code **)(local_e0 + -0x7fa8))(bio_s_out,"LOOKUP renego during read\n");
      srp_callback_parm._8_4_ =
           (**(code **)(local_e0 + -0x764c))(srp_callback_parm._4_4_,srp_callback_parm._0_4_);
      if (srp_callback_parm._8_4_ == 0) {
        (**(code **)(local_e0 + -0x7fa8))(bio_s_out,local_d4);
      }
      else {
        (**(code **)(local_e0 + -0x7fa8))
                  (bio_s_out,"LOOKUP done %s\n",*(undefined4 *)(srp_callback_parm._8_4_ + 0x14));
      }
    }
    uVar12 = (**(code **)(local_e0 + -0x7650))(unaff_s0,uVar6);
    switch(uVar12) {
    case 0:
      goto switchD_00443bc8_caseD_0;
    case 1:
    case 5:
      goto switchD_004437c8_caseD_1;
    case 2:
    case 3:
      (**(code **)(local_e0 + -0x7fa8))(bio_s_out,"Read BLOCK\n");
    default:
      goto switchD_00443bc8_caseD_4;
    case 6:
      goto switchD_004437c8_caseD_6;
    }
  }
  iVar5 = init_ssl_connection(unaff_s0);
  if (iVar5 < 0) {
    iVar5 = 0;
    goto LAB_004431f4;
  }
  pcVar24 = *(code **)(local_e0 + -0x75f0);
  if (iVar5 != 0) goto LAB_004431a8;
LAB_004431f0:
  iVar5 = 1;
  goto LAB_004431f4;
switchD_004437c8_caseD_6:
  unaff_s3 = &_ITM_registerTMCloneTable;
  iVar5 = 1;
  (**(code **)(local_e0 + -0x7fa8))(bio_s_out,"DONE\n");
  goto LAB_004431f4;
switchD_004437c8_caseD_1:
  unaff_s3 = &_ITM_registerTMCloneTable;
  iVar5 = 1;
  (**(code **)(local_e0 + -0x7fa8))(bio_s_out,"ERROR\n");
  (**(code **)(local_e0 + -0x7fa0))(**(undefined4 **)(local_e0 + -0x7fa4));
LAB_004431f4:
  if (unaff_s0 != 0) {
    (**(code **)(local_e0 + -0x7fa8))(bio_s_out,"shutting down SSL\n");
    (**(code **)(local_e0 + -0x75e8))(unaff_s0,3);
    (**(code **)(local_e0 + -0x75e4))(unaff_s0);
  }
  (**(code **)(local_e0 + -0x7fa8))(bio_s_out,"CONNECTION CLOSED\n");
  pcVar17 = (char *)0x4000;
  (**(code **)(local_e0 + -0x7d6c))(pcVar4,0x4000);
  (**(code **)(local_e0 + -0x7f58))(pcVar4);
  unaff_s8 = pcVar4;
  if (-1 < iVar5) goto LAB_00443274;
  goto LAB_0044328c;
switchD_00443bc8_caseD_0:
  raw_write_stdout(pcVar4,uVar6);
  iVar5 = (**(code **)(local_e0 + -0x75f0))(unaff_s0);
  if (iVar5 == 0) goto code_r0x00443da4;
  goto LAB_00443558;
code_r0x00443da4:
  pcVar24 = *(code **)(local_e0 + -0x75f0);
  goto LAB_004431a8;
code_r0x004445e8:
  bVar1 = pcVar8[5];
  pcVar17 = pcVar8 + 5;
  if (bVar1 == 0) goto LAB_00444c24;
  uVar11 = 1;
  pcVar19 = pcVar17;
  pcVar4 = pcVar17;
  if (bVar1 != 0x20) {
    do {
      if (uVar11 == 1) {
        bVar16 = bVar1 ^ 0x2f;
        if (bVar1 != 0x2e) goto LAB_00444a24;
        bVar16 = pcVar19[1];
        if (bVar16 == 0) goto LAB_00444c24;
        pcVar4 = pcVar19 + 1;
        if (bVar16 == 0x20) goto LAB_00444bac;
        if (bVar16 != 0x2e) {
LAB_00444a1c:
          pcVar19 = pcVar4;
          bVar16 = bVar16 ^ 0x2f;
          goto LAB_00444a24;
        }
        bVar16 = pcVar19[2];
        pcVar4 = pcVar19 + 2;
        if (bVar16 == 0) goto LAB_00444c24;
        if (bVar16 == 0x20) goto LAB_00444c74;
        if (bVar16 != 0x2f) goto LAB_00444a1c;
        iVar9 = (int)pcVar19[3];
        pcVar4 = pcVar19 + 3;
        if (iVar9 == 0) goto LAB_00444c24;
        if (iVar9 == 0x20) goto LAB_00444c68;
        pcVar4 = pcVar19 + 4;
        pcVar19 = pcVar19 + 4;
        if (*pcVar4 == '\0') goto LAB_00444c24;
        if (*pcVar4 != ' ') {
          uVar11 = 0xffffffff;
          goto LAB_00444624;
        }
        uVar11 = 0xffffffff;
        break;
      }
      bVar16 = bVar1 ^ 0x2f;
      if (uVar11 == 0) {
LAB_00444a24:
        uVar11 = (uint)(bVar16 == 0);
      }
LAB_00444624:
      bVar1 = pcVar19[1];
      pcVar19 = pcVar19 + 1;
      if (bVar1 == 0) goto LAB_00444c24;
    } while (bVar1 != 0x20);
    pcVar4 = pcVar19;
    if (uVar11 == 0xffffffff) goto LAB_00444c74;
  }
LAB_00444bac:
  *pcVar4 = '\0';
  if (pcVar8[5] == '/') {
    (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n")
    ;
    (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"\'%s\' is an invalid path\r\n",pcVar17);
  }
  else {
    iVar9 = app_isdir(pcVar17);
    if (iVar9 < 1) {
      iVar9 = (*(code *)PTR_BIO_new_file_006a7fac)(pcVar17,"r");
      if (iVar9 == 0) {
        (*(code *)PTR_BIO_puts_006a8058)
                  (unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
        (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"Error opening \'%s\'\r\n",pcVar17);
        (*(code *)PTR_ERR_print_errors_006a7f40)(unaff_s7);
      }
      else {
        if (s_quiet == 0) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)PTR_bio_err_006a7f3c,"FILE:%s\n",pcVar17);
        }
        if (www == 2) {
          iVar10 = (*(code *)PTR_strlen_006aab30)(pcVar17);
          if (iVar10 < 6) {
            if (iVar10 == 5) goto LAB_00444ea4;
LAB_00444ee8:
            (*(code *)PTR_BIO_puts_006a8058)
                      (unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
          }
          else {
            iVar14 = (*(code *)PTR_strcmp_006aac20)(pcVar17 + iVar10 + -5,".html");
            if (iVar14 != 0) {
LAB_00444ea4:
              pcVar17 = pcVar17 + iVar10 + -4;
              iVar10 = (*(code *)PTR_strcmp_006aac20)(pcVar17,&DAT_0063bb44);
              if ((iVar10 != 0) &&
                 (iVar10 = (*(code *)PTR_strcmp_006aac20)(pcVar17,&DAT_0063bb4c), iVar10 != 0))
              goto LAB_00444ee8;
            }
            (*(code *)PTR_BIO_puts_006a8058)
                      (unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/html\r\n\r\n");
          }
        }
        while (iVar10 = (*(code *)PTR_BIO_read_006a85bc)(iVar9,pcVar8,0x4000), 0 < iVar10) {
          pcVar17 = (char *)0x0;
          do {
            iVar14 = (*(code *)PTR_BIO_write_006a7f14)
                               (unaff_s7,pcVar8 + (int)pcVar17,iVar10 - (int)pcVar17);
            if (iVar14 < 1) {
              iVar14 = (*(code *)PTR_BIO_test_flags_006a8954)(unaff_s7,8);
              if (iVar14 == 0) goto LAB_00444d78;
              (*(code *)PTR_BIO_printf_006a7f38)(bio_s_out,"rwrite W BLOCK\n");
            }
            else {
              pcVar17 = pcVar17 + iVar14;
            }
          } while ((int)pcVar17 < iVar10);
        }
LAB_00444d78:
        (*(code *)PTR_BIO_free_006a7f70)(iVar9);
      }
    }
    else {
      (*(code *)PTR_BIO_puts_006a8058)
                (unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
      (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"\'%s\' is a directory\r\n",pcVar17);
    }
  }
LAB_004449b8:
  iVar9 = (*(code *)PTR_BIO_ctrl_006a7f18)(unaff_s7,0xb,0,0);
  if (iVar9 < 1) goto LAB_004449a0;
  goto LAB_004449d8;
LAB_004449a0:
  iVar9 = (*(code *)PTR_BIO_test_flags_006a8954)(unaff_s7,8);
  if (iVar9 == 0) {
LAB_004449d8:
    (*(code *)PTR_SSL_set_shutdown_006a88f8)(iVar5,3);
    uVar6 = *(undefined4 *)(unaff_s3 + -0x4d6c);
LAB_00443ff8:
    pcVar4 = s_ACCEPT_0063b91c;
    (*(code *)PTR_BIO_printf_006a7f38)(uVar6);
    (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar8);
    (*(code *)PTR_BIO_free_all_006a7f74)(unaff_s7);
    iVar9 = 1;
    unaff_s8 = pcVar8;
LAB_0044402c:
    if (iStack_124 == *(int *)puVar3) {
      return iVar9;
    }
    iVar9 = (*(code *)PTR___stack_chk_fail_006aabb8)();
    pcVar8 = unaff_s8;
LAB_00444c68:
    if (iVar9 == 0) {
LAB_00444c24:
      (*(code *)PTR_BIO_puts_006a8058)
                (unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
      (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"\'%s\' is an invalid file name\r\n",pcVar17);
    }
    else {
LAB_00444c74:
      puVar2 = PTR_BIO_puts_006a8058;
      *pcVar4 = '\0';
      (*(code *)puVar2)(unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
      (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"\'%s\' contains \'..\' reference\r\n",pcVar17);
    }
  }
  goto LAB_004449b8;
}

