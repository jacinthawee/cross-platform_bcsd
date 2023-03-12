
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int init_ssl_connection(undefined *param_1,undefined4 param_2,char *param_3)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  char cVar16;
  char *pcVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  byte bVar17;
  int iVar15;
  char *pcVar18;
  char *pcVar19;
  char *pcVar20;
  undefined4 *puVar21;
  uint uVar22;
  char *unaff_s4;
  char *unaff_s5;
  char *unaff_s6;
  uint uVar23;
  char *unaff_s7;
  code *pcVar24;
  undefined4 uStack_2190;
  int iStack_218c;
  int iStack_2188;
  undefined1 *puStack_2184;
  int iStack_2180;
  undefined *puStack_217c;
  undefined4 *puStack_2178;
  undefined4 *puStack_2174;
  char *pcStack_2170;
  char *pcStack_216c;
  char *pcStack_2168;
  code *pcStack_2164;
  undefined4 *puStack_2150;
  undefined *puStack_2148;
  int iStack_2140;
  char *pcStack_213c;
  int iStack_2138;
  uint uStack_2134;
  char *pcStack_2130;
  int *piStack_212c;
  undefined1 *puStack_2128;
  char *pcStack_2124;
  undefined4 uStack_211c;
  undefined4 uStack_2118;
  uint auStack_2114 [32];
  int iStack_2094;
  int iStack_2090;
  undefined4 *puStack_208c;
  int iStack_2088;
  undefined *puStack_2084;
  undefined4 *puStack_2080;
  undefined4 *puStack_207c;
  char *pcStack_2078;
  char *pcStack_2074;
  undefined *puStack_2070;
  code *pcStack_206c;
  char *pcStack_2064;
  undefined4 local_2058;
  undefined4 local_2054;
  undefined4 local_2050;
  undefined4 local_204c;
  undefined *local_2048;
  char *local_203c;
  int local_2034;
  undefined4 local_2030;
  undefined auStack_202c [8192];
  int local_2c;
  
  pcVar20 = PTR___stack_chk_guard_006aabf0;
  local_2048 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_2088 = (*(code *)PTR_SSL_accept_006a888c)();
  if (iStack_2088 < 1) {
    puStack_208c = (undefined4 *)&_ITM_registerTMCloneTable;
    unaff_s6 = &_ITM_registerTMCloneTable;
    unaff_s4 = "LOOKUP during accept %s\n";
    unaff_s7 = "LOOKUP not successful\n";
    unaff_s5 = "LOOKUP done %s\n";
    do {
      while( true ) {
        iVar4 = (**(code **)(local_2048 + -0x7650))(param_1,iStack_2088);
        if (iVar4 != 4) {
          iStack_2188 = (**(code **)(local_2048 + -0x7620))(iStack_2088);
          if (iStack_2188 == 0) {
            puStack_208c = *(undefined4 **)(local_2048 + -0x7fa4);
            pcStack_2064 = "ERROR\n";
            (**(code **)(local_2048 + -0x7fa8))(*puStack_208c);
            iVar4 = (**(code **)(local_2048 + -0x761c))(param_1);
            if (iVar4 == 0) {
              (**(code **)(local_2048 + -0x7fa0))(*puStack_208c);
            }
            else {
              puStack_208c = (undefined4 *)*puStack_208c;
              param_3 = (char *)(**(code **)(local_2048 + -0x7b44))(iVar4);
              pcStack_2064 = "verify error:%s\n";
              (**(code **)(local_2048 + -0x7fa8))(puStack_208c);
            }
          }
          else {
            iStack_2188 = 1;
            pcStack_2064 = "DELAY\n";
            (**(code **)(local_2048 + -0x7fa8))(bio_s_out);
          }
          goto LAB_00442dc0;
        }
        param_3 = srp_callback_parm._0_4_;
        (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"LOOKUP during accept %s\n");
        srp_callback_parm._8_4_ =
             (**(code **)(local_2048 + -0x764c))(srp_callback_parm._4_4_,srp_callback_parm._0_4_);
        if (srp_callback_parm._8_4_ != 0) break;
        (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"LOOKUP not successful\n");
        iStack_2088 = (**(code **)(local_2048 + -0x7654))(param_1);
        if (0 < iStack_2088) goto LAB_00442a30;
      }
      param_3 = *(char **)(srp_callback_parm._8_4_ + 0x14);
      (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"LOOKUP done %s\n");
      iStack_2088 = (**(code **)(local_2048 + -0x7654))(param_1);
    } while (iStack_2088 < 1);
  }
LAB_00442a30:
  uVar6 = bio_s_out;
  uVar5 = (**(code **)(local_2048 + -0x7648))(param_1);
  (**(code **)(local_2048 + -0x7644))(uVar6,uVar5);
  iStack_2088 = (**(code **)(local_2048 + -0x7640))(param_1);
  if (iStack_2088 != 0) {
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"Client certificate\n");
    (**(code **)(local_2048 + -0x7ec0))(bio_s_out,iStack_2088);
    uVar6 = (**(code **)(local_2048 + -0x7ee0))(iStack_2088);
    (**(code **)(local_2048 + -0x7dd0))(uVar6,auStack_202c,0x2000);
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"subject=%s\n",auStack_202c);
    uVar6 = (**(code **)(local_2048 + -0x7710))(iStack_2088);
    (**(code **)(local_2048 + -0x7dd0))(uVar6,auStack_202c,0x2000);
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"issuer=%s\n",auStack_202c);
    (**(code **)(local_2048 + -0x7f50))(iStack_2088);
  }
  iVar4 = (**(code **)(local_2048 + -0x763c))(param_1,auStack_202c,0x2000);
  if (iVar4 != 0) {
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"Shared ciphers:%s\n",auStack_202c);
  }
  uVar6 = (**(code **)(local_2048 + -0x7638))(param_1);
  pcVar7 = (char *)(**(code **)(local_2048 + -0x7634))(uVar6);
  if (pcVar7 == (char *)0x0) {
    pcVar7 = "(NONE)";
  }
  (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"CIPHER is %s\n",pcVar7);
  (**(code **)(local_2048 + -0x7630))(param_1,&local_2034,&local_2030);
  if (local_2034 != 0) {
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"NEXTPROTO is ");
    (**(code **)(local_2048 + -0x7fcc))(bio_s_out,local_2034,local_2030);
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"\n");
  }
  puVar8 = (undefined4 *)(**(code **)(local_2048 + -0x762c))(param_1);
  if (puVar8 != (undefined4 *)0x0) {
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"SRTP Extension negotiated, profile=%s\n",*puVar8)
    ;
  }
  iVar4 = (**(code **)(local_2048 + -0x7628))(param_1);
  if (iVar4 != 0) {
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"Reused session-id\n");
  }
  uVar9 = (**(code **)(local_2048 + -0x7668))(param_1,0xd,0,0);
  if ((uVar9 & 8) != 0) {
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"Peer has incorrect TLSv1 block padding\n");
  }
  uVar6 = bio_s_out;
  iVar4 = (**(code **)(local_2048 + -0x7668))(param_1,0x4c,0,0);
  if (iVar4 == 0) {
    param_3 = " NOT";
  }
  else {
    param_3 = "";
  }
  puStack_208c = (undefined4 *)&_ITM_registerTMCloneTable;
  pcStack_2064 = "Secure Renegotiation IS%s supported\n";
  (**(code **)(local_2048 + -0x7fa8))(uVar6);
  if (keymatexportlabel != (undefined4 *)0x0) {
    unaff_s4 = SSL_str_reasons + 0xc0;
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"Keying material exporter:\n");
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"    Label: \'%s\'\n",keymatexportlabel);
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"    Length: %i bytes\n",keymatexportlen);
    param_3 = (char *)0x9bc;
    pcStack_2064 = "s_server.c";
    unaff_s5 = (char *)(**(code **)(local_2048 + -0x7dd8))(keymatexportlen);
    puVar8 = keymatexportlabel;
    if ((undefined4 *)unaff_s5 != (undefined4 *)0x0) {
      local_2058 = (**(code **)(local_2048 + -0x53b0))(keymatexportlabel);
      local_204c = 0;
      local_2050 = 0;
      local_2054 = 0;
      local_203c = keymatexportlen;
      param_3 = keymatexportlen;
      iVar4 = (**(code **)(local_2048 + -0x7624))(param_1,unaff_s5,keymatexportlen,puVar8);
      if (iVar4 == 0) {
        pcStack_2064 = "    Error\n";
        (**(code **)(local_2048 + -0x7fa8))();
      }
      else {
        (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"    Keying material: ");
        if (0 < (int)keymatexportlen) {
          iStack_2088 = 0;
          param_1 = &DAT_00635448;
          puVar8 = (undefined4 *)unaff_s5;
          do {
            param_3 = (char *)(uint)*(byte *)puVar8;
            iStack_2088 = iStack_2088 + 1;
            puVar8 = (undefined4 *)((int)puVar8 + 1);
            (**(code **)(local_2048 + -0x7fa8))(bio_s_out,&DAT_00635448);
          } while (iStack_2088 < (int)keymatexportlen);
        }
        pcStack_2064 = "\n";
        (**(code **)(local_2048 + -0x7fa8))(bio_s_out);
      }
      iStack_2188 = 1;
      (**(code **)(local_2048 + -0x7f58))(unaff_s5);
      puStack_208c = puVar8;
      goto LAB_00442dc0;
    }
  }
  iStack_2188 = 1;
LAB_00442dc0:
  if (local_2c == *(int *)pcVar20) {
    return iStack_2188;
  }
  pcStack_206c = sv_body;
  (**(code **)(local_2048 + -0x5328))();
  puVar8 = (undefined4 *)0x7b3;
  puStack_2148 = &_gp;
  piStack_212c = (int *)PTR___stack_chk_guard_006aabf0;
  puStack_2070 = pcVar20;
  pcStack_2124 = "s\n";
  iStack_2094 = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_2090 = iStack_2188;
  puStack_2084 = param_1;
  puStack_2080 = (undefined4 *)unaff_s4;
  puStack_207c = (undefined4 *)unaff_s5;
  pcStack_2078 = unaff_s6;
  pcStack_2074 = unaff_s7;
  pcVar7 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x4000,"s_server.c");
  if (pcVar7 != (char *)0x0) {
    if (s_nbio != 0) {
      uStack_211c = 1;
      if (s_quiet == 0) {
        (**(code **)(puStack_2148 + -0x7fa8))
                  (**(undefined4 **)(puStack_2148 + -0x7fa4),"turning on non blocking io\n");
      }
      iVar4 = (**(code **)(puStack_2148 + -0x7618))(pcStack_2064,0x667e,&uStack_211c);
      if (iVar4 < 0) {
        (**(code **)(puStack_2148 + -0x7fa0))(**(undefined4 **)(puStack_2148 + -0x7fa4));
      }
    }
    unaff_s4 = &_ITM_registerTMCloneTable;
    param_1 = &_ITM_registerTMCloneTable;
    iStack_2188 = (**(code **)(puStack_2148 + -0x7614))(ctx);
    if (s_tlsextdebug != 0) {
      (**(code **)(puStack_2148 + -0x75cc))
                (iStack_2188,0x38,*(undefined4 *)(puStack_2148 + -0x75c8));
      (**(code **)(puStack_2148 + -0x7668))(iStack_2188,0x39,0,bio_s_out);
    }
    if (s_tlsextstatus != 0) {
      (**(code **)(puStack_2148 + -0x75d0))(ctx,0x3f,cert_status_cb);
      tlscstatp._20_4_ = **(undefined4 **)(puStack_2148 + -0x7fa4);
      (**(code **)(puStack_2148 + -0x7694))(ctx,0x40,0,tlscstatp);
    }
    if (param_3 != (char *)0x0) {
      uVar6 = (**(code **)(puStack_2148 + -0x53b0))(param_3);
      (**(code **)(puStack_2148 + -0x7610))(iStack_2188,param_3,uVar6);
    }
    (**(code **)(puStack_2148 + -0x760c))(iStack_2188);
    iVar4 = (**(code **)(puStack_2148 + -0x7608))(iStack_2188);
    if (iVar4 == 0xfeff) {
      puVar8 = (undefined4 *)(**(code **)(puStack_2148 + -0x75b4))(pcStack_2064,0);
      if (enable_timeouts != 0) {
        unaff_s4 = (char *)&uStack_211c;
        uStack_211c = 0;
        uStack_2118 = 250000;
        (**(code **)(puStack_2148 + -0x7fc8))(puVar8,0x21,0,unaff_s4);
        uStack_211c = 0;
        uStack_2118 = 250000;
        (**(code **)(puStack_2148 + -0x7fc8))(puVar8,0x23,0,unaff_s4);
      }
      if (socket_mtu < 0x1d) {
        (**(code **)(puStack_2148 + -0x7fc8))(puVar8,0x27,0,0);
      }
      else {
        (**(code **)(puStack_2148 + -0x7668))(iStack_2188,0x20,0x1000,0);
        (**(code **)(puStack_2148 + -0x7668))(iStack_2188,0x11,socket_mtu + -0x1c,0);
      }
      (**(code **)(puStack_2148 + -0x7668))(iStack_2188,0x20,0x2000,0);
    }
    else {
      puVar8 = (undefined4 *)(**(code **)(puStack_2148 + -0x7604))(pcStack_2064,0);
    }
    if (s_nbio_test != 0) {
      uVar6 = (**(code **)(puStack_2148 + -0x7600))();
      uVar6 = (**(code **)(puStack_2148 + -0x7f3c))(uVar6);
      puVar8 = (undefined4 *)(**(code **)(puStack_2148 + -0x7920))(uVar6,puVar8);
    }
    (**(code **)(puStack_2148 + -0x75fc))(iStack_2188,puVar8);
    (**(code **)(puStack_2148 + -0x75f8))(iStack_2188);
    if (s_debug != 0) {
      (**(code **)(puStack_2148 + -0x75c0))(iStack_2188,1);
      uVar6 = (**(code **)(puStack_2148 + -0x75bc))(iStack_2188);
      (**(code **)(puStack_2148 + -0x7908))(uVar6,*(undefined4 *)(puStack_2148 + -0x75b8));
      uVar6 = (**(code **)(puStack_2148 + -0x75bc))(iStack_2188);
      (**(code **)(puStack_2148 + -0x7900))(uVar6,bio_s_out);
    }
    if (s_msg != 0) {
      (**(code **)(puStack_2148 + -0x75f4))(iStack_2188,*(undefined4 *)(puStack_2148 + -0x75c4));
      puVar8 = (undefined4 *)0x0;
      (**(code **)(puStack_2148 + -0x7668))(iStack_2188,0x10,0,bio_s_out);
    }
    if (s_tlsextdebug != 0) {
      (**(code **)(puStack_2148 + -0x75cc))
                (iStack_2188,0x38,*(undefined4 *)(puStack_2148 + -0x75c8));
      puVar8 = (undefined4 *)0x0;
      (**(code **)(puStack_2148 + -0x7668))(iStack_2188,0x39,0,bio_s_out);
    }
    pcStack_2130 = pcStack_2064 + 1;
    uStack_2134 = 1 << ((uint)pcStack_2064 & 0x1f);
    unaff_s6 = "LOOKUP renego during write\n";
    unaff_s7 = "LOOKUP done %s\n";
    puStack_2128 = &_ITM_registerTMCloneTable;
    pcStack_213c = "LOOKUP not successful\n";
switchD_00443bc8_caseD_4:
    pcVar24 = *(code **)(puStack_2148 + -0x75f0);
LAB_004431a8:
    while (iStack_2138 = (*pcVar24)(iStack_2188), iStack_2138 == 0) {
      puVar21 = *(undefined4 **)(puStack_2148 + -0x53c0);
      (**(code **)(puStack_2148 + -0x53e0))(auStack_2114,0,0x80);
      unaff_s4 = (char *)(**(code **)(puStack_2148 + -0x53f8))(*puVar21);
      uVar6 = (**(code **)(puStack_2148 + -0x53f8))(*puVar21);
      iVar4 = (**(code **)(puStack_2148 + -0x5338))(uVar6);
      pcVar20 = pcStack_2064;
      pcVar24 = *(code **)(puStack_2148 + -0x5338);
      auStack_2114[iVar4] = 1 << ((uint)unaff_s4 & 0x1f) | auStack_2114[iVar4];
      iVar4 = (*pcVar24)(pcVar20);
      pcVar24 = *(code **)(puStack_2148 + -0x7608);
      auStack_2114[iVar4] = auStack_2114[iVar4] | uStack_2134;
      iVar4 = (*pcVar24)(iStack_2188);
      if (iVar4 == 0xfeff) {
        puVar10 = &uStack_211c;
        iVar4 = (**(code **)(puStack_2148 + -0x7668))(iStack_2188,0x49,0,puVar10);
        unaff_s4 = (char *)puVar10;
        if (iVar4 == 0) goto LAB_004433a0;
      }
      else {
LAB_004433a0:
        puVar10 = (undefined4 *)0x0;
      }
      puVar8 = (undefined4 *)0x0;
      puStack_2150 = puVar10;
      param_1 = (undefined *)(**(code **)(puStack_2148 + -0x5314))(pcStack_2130,auStack_2114,0,0);
      iVar4 = (**(code **)(puStack_2148 + -0x7608))(iStack_2188);
      if (iVar4 == 0xfeff) goto LAB_00443bd0;
      pcVar24 = *(code **)(puStack_2148 + -0x75f0);
      if (0 < (int)param_1) goto LAB_004433e8;
    }
    goto LAB_004431bc;
  }
  iVar4 = 1;
  (**(code **)(puStack_2148 + -0x7fa8))(**(undefined4 **)(puStack_2148 + -0x7fa4),"out of memory\n")
  ;
  (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,"CONNECTION CLOSED\n");
LAB_00443274:
  pcVar18 = s_ACCEPT_0063b91c;
  (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,s_ACCEPT_0063b91c);
LAB_0044328c:
  if (iStack_2094 == *piStack_212c) {
    return iVar4;
  }
  pcStack_2164 = www_body;
  (**(code **)(puStack_2148 + -0x5328))();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  puStack_2184 = &_ITM_registerTMCloneTable;
  pcVar7 = "s_server.c";
  iStack_218c = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_2180 = iVar4;
  puStack_217c = param_1;
  puStack_2178 = (undefined4 *)unaff_s4;
  puStack_2174 = (undefined4 *)unaff_s5;
  pcStack_2170 = unaff_s6;
  pcStack_216c = unaff_s7;
  pcStack_2168 = pcVar20;
  pcVar11 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x4000,"s_server.c",0xa09);
  if (pcVar11 == (char *)0x0) {
    iVar12 = 0;
    goto LAB_0044402c;
  }
  uVar6 = (*(code *)PTR_BIO_f_buffer_006a8940)();
  unaff_s7 = (char *)(*(code *)PTR_BIO_new_006a7fa4)(uVar6);
  uVar6 = (*(code *)PTR_BIO_f_ssl_006a8944)();
  iVar12 = (*(code *)PTR_BIO_new_006a7fa4)(uVar6);
  if (unaff_s7 == (char *)0x0) {
    pcVar7 = s_ACCEPT_0063b91c;
    (*(code *)PTR_BIO_printf_006a7f38)(bio_s_out);
    (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar11);
    iVar12 = 1;
    pcVar20 = pcVar11;
    goto LAB_0044402c;
  }
  if (iVar12 == 0) {
LAB_00444324:
    param_1 = &_ITM_registerTMCloneTable;
    uVar6 = bio_s_out;
    goto LAB_00443ff8;
  }
  if (s_nbio != 0) {
    uStack_2190 = 1;
    if (s_quiet == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,"turning on non blocking io\n");
    }
    iVar13 = (*(code *)PTR_BIO_socket_ioctl_006a88c8)(pcVar18,0x667e,&uStack_2190);
    if (iVar13 < 0) {
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
    }
  }
  iVar13 = (*(code *)PTR_BIO_int_ctrl_006a8948)(unaff_s7,0x75,0x4000,1);
  uVar6 = bio_s_out;
  if (iVar13 == 0) goto LAB_00443ff8;
  iVar4 = (*(code *)PTR_SSL_new_006a88cc)(ctx);
  if (iVar4 == 0) goto LAB_00444324;
  if (s_tlsextdebug != 0) {
    (*(code *)PTR_SSL_callback_ctrl_006a8914)(iVar4,0x38,PTR_tlsext_cb_006a8918);
    (*(code *)PTR_SSL_ctrl_006a8878)(iVar4,0x39,0,bio_s_out);
  }
  param_1 = &_ITM_registerTMCloneTable;
  if (puVar8 != (undefined4 *)0x0) {
    uVar6 = (*(code *)PTR_strlen_006aab30)(puVar8);
    (*(code *)PTR_SSL_set_session_id_context_006a88d0)(iVar4,puVar8,uVar6);
  }
  uVar6 = (*(code *)PTR_BIO_new_socket_006a88dc)(pcVar18,0);
  if (s_nbio_test != 0) {
    uVar5 = (*(code *)PTR_BIO_f_nbio_test_006a88e0)();
    uVar5 = (*(code *)PTR_BIO_new_006a7fa4)(uVar5);
    uVar6 = (*(code *)PTR_BIO_push_006a85c0)(uVar5,uVar6);
  }
  (*(code *)PTR_SSL_set_bio_006a88e4)(iVar4,uVar6);
  (*(code *)PTR_SSL_set_accept_state_006a88e8)(iVar4);
  (*(code *)PTR_BIO_ctrl_006a7f18)(iVar12,0x6d,1,iVar4);
  (*(code *)PTR_BIO_push_006a85c0)(unaff_s7,iVar12);
  if (s_debug != 0) {
    (*(code *)PTR_SSL_set_debug_006a8920)(iVar4,1);
    uVar6 = (*(code *)PTR_SSL_get_rbio_006a8924)(iVar4);
    (*(code *)PTR_BIO_set_callback_006a85d8)(uVar6,PTR_bio_dump_callback_006a8928);
    uVar6 = (*(code *)PTR_SSL_get_rbio_006a8924)(iVar4);
    (*(code *)PTR_BIO_set_callback_arg_006a85e0)(uVar6,bio_s_out);
  }
  if (s_msg != 0) {
    (*(code *)PTR_SSL_set_msg_callback_006a88ec)(iVar4,PTR_msg_cb_006a891c);
    (*(code *)PTR_SSL_ctrl_006a8878)(iVar4,0x10,0,bio_s_out);
  }
LAB_0044419c:
  if (hack != 0) {
    iVar12 = (*(code *)PTR_SSL_accept_006a888c)(iVar4);
    if (iVar12 < 1) {
      pcVar18 = &_ITM_registerTMCloneTable;
      do {
        while( true ) {
          iVar13 = (*(code *)PTR_SSL_get_error_006a8890)(iVar4,iVar12);
          if (iVar13 != 4) goto LAB_00444274;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (bio_s_out,"LOOKUP during accept %s\n",srp_callback_parm._0_4_);
          srp_callback_parm._8_4_ =
               (*(code *)PTR_SRP_VBASE_get_by_user_006a8894)
                         (srp_callback_parm._4_4_,srp_callback_parm._0_4_);
          if (srp_callback_parm._8_4_ != 0) break;
          (*(code *)PTR_BIO_printf_006a7f38)(bio_s_out,"LOOKUP not successful\n");
          iVar12 = (*(code *)PTR_SSL_accept_006a888c)(iVar4);
          if (0 < iVar12) goto LAB_00444274;
        }
        (*(code *)PTR_BIO_printf_006a7f38)
                  (bio_s_out,"LOOKUP done %s\n",*(undefined4 *)(srp_callback_parm._8_4_ + 0x14));
        iVar12 = (*(code *)PTR_SSL_accept_006a888c)(iVar4);
      } while (iVar12 < 1);
    }
LAB_00444274:
    uVar9 = (*(code *)PTR_SSL_get_error_006a8890)(iVar4,iVar12);
    if (uVar9 < 7) {
      uVar9 = 1 << (uVar9 & 0x1f);
      if ((uVar9 & 0x62) != 0) goto LAB_00444324;
      if ((uVar9 & 0x1c) != 0) goto LAB_0044419c;
    }
    (*(code *)PTR_SSL_renegotiate_006a8934)(iVar4);
    (*(code *)PTR_SSL_write_006a890c)(iVar4,0,0);
  }
  iVar12 = (*(code *)PTR_BIO_gets_006a85d0)(unaff_s7,pcVar11,0x3fff);
  if (iVar12 < 0) {
    iVar12 = (*(code *)PTR_BIO_test_flags_006a8954)(unaff_s7,8);
    if (iVar12 == 0) {
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
  if (iVar12 == 0) goto LAB_004449d8;
  if (www != 1) {
    if (www != 2) {
      if (www == 3) goto LAB_004445d0;
      goto LAB_0044419c;
    }
    iVar12 = (*(code *)PTR_strncmp_006aaa7c)("GET /stats ",pcVar11,10);
    if (iVar12 == 0) goto LAB_00444350;
LAB_004445d0:
    iVar12 = (*(code *)PTR_strncmp_006aaa7c)(&DAT_0063ba94,pcVar11,5);
    if (iVar12 == 0) goto code_r0x004445e8;
    goto LAB_0044419c;
  }
  iVar12 = (*(code *)PTR_strncmp_006aaa7c)(&DAT_0063b950,pcVar11,4);
  if (iVar12 != 0) goto LAB_0044419c;
LAB_00444350:
  (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/html\r\n\r\n");
  (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"<HTML><BODY BGCOLOR=\"#ffffff\">\n");
  (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"<pre>\n");
  (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"\n");
  if (0 < local_argc) {
    iVar12 = 0;
    do {
      iVar13 = iVar12 * 4;
      iVar12 = iVar12 + 1;
      (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,*(undefined4 *)(local_argv + iVar13));
      (*(code *)PTR_BIO_write_006a7f14)(unaff_s7,&DAT_0063f0b8,1);
    } while (iVar12 < local_argc);
  }
  (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"\n");
  iVar12 = (*(code *)PTR_SSL_ctrl_006a8878)(iVar4,0x4c,0,0);
  if (iVar12 == 0) {
    pcVar20 = " NOT";
  }
  else {
    pcVar20 = "";
  }
  (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"Secure Renegotiation IS%s supported\n",pcVar20);
  (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"Ciphers supported in s_server binary\n");
  uVar6 = (*(code *)PTR_SSL_get_ciphers_006a894c)(iVar4);
  uVar9 = (*(code *)PTR_sk_num_006a7f2c)(uVar6);
  if (0 < (int)uVar9) {
    uVar5 = (*(code *)PTR_sk_value_006a7f24)(uVar6,0);
    uVar14 = (*(code *)PTR_SSL_CIPHER_get_version_006a8950)(uVar5);
    uVar5 = (*(code *)PTR_SSL_CIPHER_get_name_006a88ac)(uVar5);
    (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"%-11s:%-25s",uVar14,uVar5);
    uVar22 = 1;
    while (uVar9 != uVar22) {
      uVar23 = uVar22 + 1;
      uVar5 = (*(code *)PTR_sk_value_006a7f24)(uVar6,uVar22);
      uVar14 = (*(code *)PTR_SSL_CIPHER_get_version_006a8950)(uVar5);
      uVar5 = (*(code *)PTR_SSL_CIPHER_get_name_006a88ac)(uVar5);
      (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"%-11s:%-25s",uVar14,uVar5);
      uVar22 = uVar23;
      if ((uVar23 & 1) == 0) {
        if (uVar9 == uVar23) break;
        (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"\n");
      }
    }
  }
  (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"\n");
  pcVar20 = (char *)(*(code *)PTR_SSL_get_shared_ciphers_006a88a4)(iVar4,pcVar11,0x4000);
  if (pcVar20 != (char *)0x0) {
    (*(code *)PTR_BIO_printf_006a7f38)
              (unaff_s7,"---\nCiphers common between both SSL end points:\n");
    cVar16 = *pcVar20;
    if (cVar16 != '\0') {
      iVar13 = 0;
      iVar12 = 0;
      do {
        if (cVar16 == ':') {
          iVar12 = iVar12 + 1;
          (*(code *)PTR_BIO_write_006a7f14)(unaff_s7,&DAT_0063ba24,0x1a - iVar13);
          if (iVar12 == (iVar12 / 3) * 3) {
            puVar8 = (undefined4 *)0x63bac8;
          }
          else {
            puVar8 = &DAT_0063f0b8;
          }
          iVar13 = 0;
          (*(code *)PTR_BIO_write_006a7f14)(unaff_s7,puVar8,1);
        }
        else {
          (*(code *)PTR_BIO_write_006a7f14)(unaff_s7,pcVar20,1);
          iVar13 = iVar13 + 1;
        }
        pcVar20 = pcVar20 + 1;
        cVar16 = *pcVar20;
      } while (cVar16 != '\0');
    }
    (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"\n");
  }
  iVar12 = (*(code *)PTR_SSL_cache_hit_006a88b8)(iVar4);
  if (iVar12 == 0) {
    pcVar20 = "---\nNew, ";
  }
  else {
    pcVar20 = "---\nReused, ";
  }
  (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,pcVar20);
  uVar6 = (*(code *)PTR_SSL_get_current_cipher_006a88a8)(iVar4);
  uVar5 = (*(code *)PTR_SSL_CIPHER_get_version_006a8950)(uVar6);
  uVar6 = (*(code *)PTR_SSL_CIPHER_get_name_006a88ac)(uVar6);
  (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"%s, Cipher is %s\n",uVar5,uVar6);
  uVar6 = (*(code *)PTR_SSL_get_session_006a8898)(iVar4);
  (*(code *)PTR_SSL_SESSION_print_006a8958)(unaff_s7,uVar6);
  (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,&DAT_0063ba54);
  uVar6 = (*(code *)PTR_SSL_get_SSL_CTX_006a8858)(iVar4);
  print_stats(unaff_s7,uVar6);
  (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,&DAT_0063ba54);
  pcVar18 = (char *)(*(code *)PTR_SSL_get_peer_certificate_006a88a0)(iVar4);
  if (pcVar18 == (char *)0x0) {
    (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"no client certificate available\n");
  }
  else {
    (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"Client certificate\n");
    (*(code *)PTR_X509_print_006a81c0)(unaff_s7,pcVar18);
    (*(code *)PTR_PEM_write_bio_X509_006a8020)(unaff_s7,pcVar18);
  }
  (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"</BODY></HTML>\r\n\r\n");
  goto LAB_004449b8;
LAB_00443bd0:
  puVar8 = (undefined4 *)0x0;
  iVar4 = (**(code **)(puStack_2148 + -0x7668))(iStack_2188,0x4a,0,0);
  if (0 < iVar4) {
    (**(code **)(puStack_2148 + -0x7fa8))
              (**(undefined4 **)(puStack_2148 + -0x7fa4),"TIMEOUT occured\n");
  }
  pcVar24 = *(code **)(puStack_2148 + -0x75f0);
  if ((int)param_1 < 1) goto LAB_004431a8;
LAB_004433e8:
  uVar6 = (**(code **)(puStack_2148 + -0x53f8))(*puVar21);
  iVar4 = (**(code **)(puStack_2148 + -0x5338))(uVar6);
  uVar22 = auStack_2114[iVar4];
  uVar9 = (**(code **)(puStack_2148 + -0x53f8))(*puVar21);
  uVar22 = 1 << (uVar9 & 0x1f) & uVar22;
  iVar4 = (**(code **)(puStack_2148 + -0x5338))(pcStack_2064);
  if ((uStack_2134 & auStack_2114[iVar4]) == 0) {
    if (uVar22 == 0) goto switchD_00443bc8_caseD_4;
    iVar4 = *(int *)(puStack_2128 + -0x4dbc);
joined_r0x004435f4:
    if (iVar4 == 0) {
      unaff_s4 = (char *)raw_read_stdin(pcVar7,0x4000);
LAB_00443614:
      if (s_quiet == 0) {
        if (((int)unaff_s4 < 1) || (cVar16 = *pcVar7, cVar16 == 'Q')) {
LAB_00443dc8:
          (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,"DONE\n");
          (**(code **)(puStack_2148 + -0x5474))(pcStack_2064,0);
          (**(code **)(puStack_2148 + -0x5484))(pcStack_2064);
          (**(code **)(puStack_2148 + -0x7fa8))
                    (**(undefined4 **)(puStack_2148 + -0x7fa4),"shutdown accept socket\n");
          if (accept_socket < 0) {
            iVar4 = -0xb;
          }
          else {
            (**(code **)(puStack_2148 + -0x5474))(accept_socket,2);
            iVar4 = -0xb;
            (**(code **)(puStack_2148 + -0x5484))(accept_socket);
          }
          goto LAB_004431f4;
        }
        if (cVar16 == 'q') {
          (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,"DONE\n");
          iVar4 = (**(code **)(puStack_2148 + -0x7608))(iStack_2188);
          if (iVar4 != 0xfeff) {
            iVar4 = 1;
            (**(code **)(puStack_2148 + -0x5474))(pcStack_2064,0);
            (**(code **)(puStack_2148 + -0x5484))(pcStack_2064);
            goto LAB_004431f4;
          }
          goto LAB_004431f0;
        }
        if (cVar16 == 'B') {
          if ((pcVar7[1] == '\n') || (pcVar7[1] == '\r')) {
            (**(code **)(puStack_2148 + -0x7fa8))
                      (**(undefined4 **)(puStack_2148 + -0x7fa4),"HEARTBEATING\n");
            puVar8 = (undefined4 *)0x0;
            (**(code **)(puStack_2148 + -0x7668))(iStack_2188,0x55,0,0);
            goto switchD_00443bc8_caseD_4;
          }
        }
        else if (cVar16 == 'r') {
          if ((pcVar7[1] == '\n') || (pcVar7[1] == '\r')) {
            pcVar24 = *(code **)(puStack_2148 + -0x75ac);
LAB_00443cc4:
            (*pcVar24)(iStack_2188);
            puVar8 = (undefined4 *)(**(code **)(puStack_2148 + -0x75a8))(iStack_2188);
            (**(code **)(puStack_2148 + -0x5410))(1,"SSL_do_handshake -> %d\n");
            goto switchD_00443bc8_caseD_4;
          }
        }
        else if (cVar16 == 'R') {
          if ((pcVar7[1] == '\n') || (pcVar7[1] == '\r')) {
            (**(code **)(puStack_2148 + -0x75b0))(iStack_2188,5,0);
            pcVar24 = *(code **)(puStack_2148 + -0x75ac);
            goto LAB_00443cc4;
          }
        }
        else {
          if (cVar16 == 'P') {
            uVar6 = (**(code **)(puStack_2148 + -0x75d8))(iStack_2188);
            (**(code **)(puStack_2148 + -0x7fcc))(uVar6,"Lets print some clear text\n",0x1b);
            cVar16 = *pcVar7;
          }
          uVar6 = bio_s_out;
          if (cVar16 == 'S') {
            uVar5 = (**(code **)(puStack_2148 + -0x7688))(iStack_2188);
            print_stats(uVar6,uVar5);
          }
        }
      }
    }
    else {
      unaff_s4 = (char *)raw_read_stdin(pcVar7,0x2000);
      if (0 < (int)unaff_s4) {
        iVar4 = 0;
        pcVar20 = pcVar7;
        do {
          cVar16 = *pcVar20;
          pcVar20 = pcVar20 + 1;
          iVar4 = iVar4 + (uint)(cVar16 == '\n');
        } while (pcVar7 + (int)unaff_s4 != pcVar20);
        pcVar20 = (char *)((int)unaff_s4 + -1);
        pcVar11 = pcVar7 + iVar4;
        pcVar18 = pcVar7 + (int)pcVar20;
        do {
          while( true ) {
            puVar8 = (undefined4 *)(int)*pcVar18;
            pcVar11[(int)pcVar20] = *pcVar18;
            if (*pcVar18 != '\n') break;
            iVar4 = iVar4 + -1;
            unaff_s4 = (char *)((int)unaff_s4 + 1);
            pcVar11 = pcVar7 + iVar4;
            pcVar18 = pcVar18 + -1;
            pcVar19 = pcVar11 + (int)pcVar20;
            pcVar20 = pcVar20 + -1;
            *pcVar19 = '\r';
            if (pcVar20 == (char *)0xffffffff) goto LAB_00443520;
          }
          pcVar20 = pcVar20 + -1;
          pcVar18 = pcVar18 + -1;
        } while (pcVar20 != (char *)0xffffffff);
LAB_00443520:
        if (iVar4 != 0) {
          iVar4 = (**(code **)(puStack_2148 + -0x5494))
                            ("lf_num == 0",pcStack_2124 + -0x4830,0x880,"sv_body");
          return iVar4;
        }
        goto LAB_00443614;
      }
      if (s_quiet == 0) goto LAB_00443dc8;
    }
    iStack_2140 = 0;
    param_1 = &_ITM_registerTMCloneTable;
    do {
      pcVar24 = *(code **)(puStack_2148 + -0x75d4);
      unaff_s5 = pcVar7 + iStack_2140;
      while( true ) {
        puVar8 = (undefined4 *)unaff_s4;
        iVar4 = (*pcVar24)(iStack_2188,unaff_s5);
        iVar12 = (**(code **)(puStack_2148 + -0x7650))(iStack_2188,iVar4);
        if (iVar12 != 4) break;
        (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,"LOOKUP renego during write\n");
        srp_callback_parm._8_4_ =
             (**(code **)(puStack_2148 + -0x764c))(srp_callback_parm._4_4_,srp_callback_parm._0_4_);
        if (srp_callback_parm._8_4_ == 0) {
          (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,pcStack_213c);
          pcVar24 = *(code **)(puStack_2148 + -0x75d4);
        }
        else {
          (**(code **)(puStack_2148 + -0x7fa8))
                    (bio_s_out,"LOOKUP done %s\n",*(undefined4 *)(srp_callback_parm._8_4_ + 0x14));
          pcVar24 = *(code **)(puStack_2148 + -0x75d4);
        }
      }
      uVar6 = (**(code **)(puStack_2148 + -0x7650))(iStack_2188,iVar4);
      switch(uVar6) {
      case 1:
      case 5:
        goto switchD_004437c8_caseD_1;
      case 2:
      case 3:
      case 4:
        (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,"Write BLOCK\n");
        break;
      case 6:
        goto switchD_004437c8_caseD_6;
      }
      unaff_s4 = (char *)((int)unaff_s4 - iVar4);
      iStack_2140 = iStack_2140 + iVar4;
    } while (0 < (int)unaff_s4);
    pcVar24 = *(code **)(puStack_2148 + -0x75ec);
    if (iStack_2138 == 0) goto switchD_00443bc8_caseD_4;
  }
  else {
    iStack_2138 = 1;
    if (uVar22 != 0) {
      iVar4 = *(int *)(puStack_2128 + -0x4dbc);
      goto joined_r0x004435f4;
    }
LAB_004431bc:
    pcVar24 = *(code **)(puStack_2148 + -0x75ec);
  }
  iVar4 = (*pcVar24)(iStack_2188);
  if (iVar4 == 3) {
    param_1 = &_ITM_registerTMCloneTable;
    unaff_s4 = "LOOKUP renego during read\n";
LAB_00443558:
    while( true ) {
      puVar8 = (undefined4 *)0x4000;
      uVar6 = (**(code **)(puStack_2148 + -0x75dc))(iStack_2188,pcVar7);
      iVar4 = (**(code **)(puStack_2148 + -0x7650))(iStack_2188,uVar6);
      if (iVar4 != 4) break;
      (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,"LOOKUP renego during read\n");
      srp_callback_parm._8_4_ =
           (**(code **)(puStack_2148 + -0x764c))(srp_callback_parm._4_4_,srp_callback_parm._0_4_);
      if (srp_callback_parm._8_4_ == 0) {
        (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,pcStack_213c);
      }
      else {
        (**(code **)(puStack_2148 + -0x7fa8))
                  (bio_s_out,"LOOKUP done %s\n",*(undefined4 *)(srp_callback_parm._8_4_ + 0x14));
      }
    }
    uVar5 = (**(code **)(puStack_2148 + -0x7650))(iStack_2188,uVar6);
    switch(uVar5) {
    case 0:
      goto switchD_00443bc8_caseD_0;
    case 1:
    case 5:
      goto switchD_004437c8_caseD_1;
    case 2:
    case 3:
      (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,"Read BLOCK\n");
    default:
      goto switchD_00443bc8_caseD_4;
    case 6:
      goto switchD_004437c8_caseD_6;
    }
  }
  iVar4 = init_ssl_connection(iStack_2188);
  if (iVar4 < 0) {
    iVar4 = 0;
    goto LAB_004431f4;
  }
  pcVar24 = *(code **)(puStack_2148 + -0x75f0);
  if (iVar4 != 0) goto LAB_004431a8;
LAB_004431f0:
  iVar4 = 1;
  goto LAB_004431f4;
switchD_004437c8_caseD_6:
  param_1 = &_ITM_registerTMCloneTable;
  iVar4 = 1;
  (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,"DONE\n");
  goto LAB_004431f4;
switchD_004437c8_caseD_1:
  param_1 = &_ITM_registerTMCloneTable;
  iVar4 = 1;
  (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,"ERROR\n");
  (**(code **)(puStack_2148 + -0x7fa0))(**(undefined4 **)(puStack_2148 + -0x7fa4));
LAB_004431f4:
  if (iStack_2188 != 0) {
    (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,"shutting down SSL\n");
    (**(code **)(puStack_2148 + -0x75e8))(iStack_2188,3);
    (**(code **)(puStack_2148 + -0x75e4))(iStack_2188);
  }
  (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,"CONNECTION CLOSED\n");
  pcVar18 = (char *)0x4000;
  (**(code **)(puStack_2148 + -0x7d6c))(pcVar7,0x4000);
  (**(code **)(puStack_2148 + -0x7f58))(pcVar7);
  pcVar20 = pcVar7;
  if (-1 < iVar4) goto LAB_00443274;
  goto LAB_0044328c;
switchD_00443bc8_caseD_0:
  raw_write_stdout(pcVar7,uVar6);
  iVar4 = (**(code **)(puStack_2148 + -0x75f0))(iStack_2188);
  if (iVar4 == 0) goto code_r0x00443da4;
  goto LAB_00443558;
code_r0x00443da4:
  pcVar24 = *(code **)(puStack_2148 + -0x75f0);
  goto LAB_004431a8;
code_r0x004445e8:
  bVar1 = pcVar11[5];
  pcVar18 = pcVar11 + 5;
  if (bVar1 == 0) goto LAB_00444c24;
  uVar9 = 1;
  pcVar20 = pcVar18;
  pcVar7 = pcVar18;
  if (bVar1 != 0x20) {
    do {
      if (uVar9 == 1) {
        bVar17 = bVar1 ^ 0x2f;
        if (bVar1 != 0x2e) goto LAB_00444a24;
        bVar17 = pcVar20[1];
        if (bVar17 == 0) goto LAB_00444c24;
        pcVar7 = pcVar20 + 1;
        if (bVar17 == 0x20) goto LAB_00444bac;
        if (bVar17 != 0x2e) {
LAB_00444a1c:
          pcVar20 = pcVar7;
          bVar17 = bVar17 ^ 0x2f;
          goto LAB_00444a24;
        }
        bVar17 = pcVar20[2];
        pcVar7 = pcVar20 + 2;
        if (bVar17 == 0) goto LAB_00444c24;
        if (bVar17 == 0x20) goto LAB_00444c74;
        if (bVar17 != 0x2f) goto LAB_00444a1c;
        iVar12 = (int)pcVar20[3];
        pcVar7 = pcVar20 + 3;
        if (iVar12 == 0) goto LAB_00444c24;
        if (iVar12 == 0x20) goto LAB_00444c68;
        pcVar7 = pcVar20 + 4;
        pcVar20 = pcVar20 + 4;
        if (*pcVar7 == '\0') goto LAB_00444c24;
        if (*pcVar7 != ' ') {
          uVar9 = 0xffffffff;
          goto LAB_00444624;
        }
        uVar9 = 0xffffffff;
        break;
      }
      bVar17 = bVar1 ^ 0x2f;
      if (uVar9 == 0) {
LAB_00444a24:
        uVar9 = (uint)(bVar17 == 0);
      }
LAB_00444624:
      bVar1 = pcVar20[1];
      pcVar20 = pcVar20 + 1;
      if (bVar1 == 0) goto LAB_00444c24;
    } while (bVar1 != 0x20);
    pcVar7 = pcVar20;
    if (uVar9 == 0xffffffff) goto LAB_00444c74;
  }
LAB_00444bac:
  *pcVar7 = '\0';
  if (pcVar11[5] == '/') {
    (*(code *)PTR_BIO_puts_006a8058)(unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n")
    ;
    (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"\'%s\' is an invalid path\r\n",pcVar18);
  }
  else {
    iVar12 = app_isdir(pcVar18);
    if (iVar12 < 1) {
      iVar12 = (*(code *)PTR_BIO_new_file_006a7fac)(pcVar18,"r");
      if (iVar12 == 0) {
        (*(code *)PTR_BIO_puts_006a8058)
                  (unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
        (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"Error opening \'%s\'\r\n",pcVar18);
        (*(code *)PTR_ERR_print_errors_006a7f40)(unaff_s7);
      }
      else {
        if (s_quiet == 0) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)PTR_bio_err_006a7f3c,"FILE:%s\n",pcVar18);
        }
        if (www == 2) {
          iVar13 = (*(code *)PTR_strlen_006aab30)(pcVar18);
          if (iVar13 < 6) {
            if (iVar13 == 5) goto LAB_00444ea4;
LAB_00444ee8:
            (*(code *)PTR_BIO_puts_006a8058)
                      (unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
          }
          else {
            iVar15 = (*(code *)PTR_strcmp_006aac20)(pcVar18 + iVar13 + -5,".html");
            if (iVar15 != 0) {
LAB_00444ea4:
              pcVar18 = pcVar18 + iVar13 + -4;
              iVar13 = (*(code *)PTR_strcmp_006aac20)(pcVar18,&DAT_0063bb44);
              if ((iVar13 != 0) &&
                 (iVar13 = (*(code *)PTR_strcmp_006aac20)(pcVar18,&DAT_0063bb4c), iVar13 != 0))
              goto LAB_00444ee8;
            }
            (*(code *)PTR_BIO_puts_006a8058)
                      (unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/html\r\n\r\n");
          }
        }
        while (iVar13 = (*(code *)PTR_BIO_read_006a85bc)(iVar12,pcVar11,0x4000), 0 < iVar13) {
          pcVar18 = (char *)0x0;
          do {
            iVar15 = (*(code *)PTR_BIO_write_006a7f14)
                               (unaff_s7,pcVar11 + (int)pcVar18,iVar13 - (int)pcVar18);
            if (iVar15 < 1) {
              iVar15 = (*(code *)PTR_BIO_test_flags_006a8954)(unaff_s7,8);
              if (iVar15 == 0) goto LAB_00444d78;
              (*(code *)PTR_BIO_printf_006a7f38)(bio_s_out,"rwrite W BLOCK\n");
            }
            else {
              pcVar18 = pcVar18 + iVar15;
            }
          } while ((int)pcVar18 < iVar13);
        }
LAB_00444d78:
        (*(code *)PTR_BIO_free_006a7f70)(iVar12);
      }
    }
    else {
      (*(code *)PTR_BIO_puts_006a8058)
                (unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
      (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"\'%s\' is a directory\r\n",pcVar18);
    }
  }
LAB_004449b8:
  iVar12 = (*(code *)PTR_BIO_ctrl_006a7f18)(unaff_s7,0xb,0,0);
  if (iVar12 < 1) goto LAB_004449a0;
  goto LAB_004449d8;
LAB_004449a0:
  iVar12 = (*(code *)PTR_BIO_test_flags_006a8954)(unaff_s7,8);
  if (iVar12 == 0) {
LAB_004449d8:
    (*(code *)PTR_SSL_set_shutdown_006a88f8)(iVar4,3);
    uVar6 = *(undefined4 *)(param_1 + -0x4d6c);
LAB_00443ff8:
    pcVar7 = s_ACCEPT_0063b91c;
    (*(code *)PTR_BIO_printf_006a7f38)(uVar6);
    (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar11);
    (*(code *)PTR_BIO_free_all_006a7f74)(unaff_s7);
    iVar12 = 1;
    pcVar20 = pcVar11;
LAB_0044402c:
    if (iStack_218c == *(int *)puVar3) {
      return iVar12;
    }
    iVar12 = (*(code *)PTR___stack_chk_fail_006aabb8)();
    pcVar11 = pcVar20;
LAB_00444c68:
    if (iVar12 == 0) {
LAB_00444c24:
      (*(code *)PTR_BIO_puts_006a8058)
                (unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
      (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"\'%s\' is an invalid file name\r\n",pcVar18);
    }
    else {
LAB_00444c74:
      puVar2 = PTR_BIO_puts_006a8058;
      *pcVar7 = '\0';
      (*(code *)puVar2)(unaff_s7,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
      (*(code *)PTR_BIO_printf_006a7f38)(unaff_s7,"\'%s\' contains \'..\' reference\r\n",pcVar18);
    }
  }
  goto LAB_004449b8;
}

