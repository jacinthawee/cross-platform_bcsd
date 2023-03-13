
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int init_ssl_connection(undefined *param_1,undefined4 param_2,int *param_3)

{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined *puVar11;
  char cVar17;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  byte bVar18;
  int iVar16;
  char *pcVar19;
  char *pcVar20;
  undefined *puVar21;
  undefined *puVar22;
  int *piVar23;
  char *pcVar24;
  byte *pbVar25;
  undefined4 *puVar26;
  uint uVar27;
  undefined *puVar28;
  int iVar29;
  undefined4 *unaff_s1;
  char *unaff_s4;
  char *unaff_s5;
  char *unaff_s6;
  uint uVar30;
  char *unaff_s7;
  code *pcVar31;
  undefined4 uStack_2190;
  int iStack_218c;
  undefined *puStack_2188;
  undefined4 *puStack_2184;
  int iStack_2180;
  undefined *puStack_217c;
  undefined4 *puStack_2178;
  byte *pbStack_2174;
  char *pcStack_2170;
  char *pcStack_216c;
  char *pcStack_2168;
  code *pcStack_2164;
  undefined4 *puStack_2150;
  undefined *puStack_2148;
  char *pcStack_2140;
  int iStack_213c;
  int iStack_2138;
  uint uStack_2134;
  char *pcStack_2130;
  int *piStack_212c;
  undefined *puStack_2128;
  char *pcStack_2124;
  undefined4 uStack_211c;
  undefined4 uStack_2118;
  uint auStack_2114 [32];
  int iStack_2094;
  int iStack_2090;
  undefined4 *puStack_208c;
  undefined *puStack_2088;
  undefined *puStack_2084;
  undefined4 *puStack_2080;
  byte *pbStack_207c;
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
  int *local_203c;
  int local_2034;
  undefined4 local_2030;
  undefined auStack_202c [8192];
  int local_2c;
  
  pcStack_2168 = PTR___stack_chk_guard_006a9ae8;
  local_2048 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar3 = (*(code *)PTR_SSL_accept_006a779c)();
  if (iVar3 < 1) {
    puStack_2088 = &_gp_1;
    unaff_s6 = &_gp_1;
    unaff_s4 = "LOOKUP during accept %s\n";
    unaff_s7 = "LOOKUP not successful\n";
    unaff_s5 = "LOOKUP done %s\n";
    do {
      while( true ) {
        iVar4 = (**(code **)(local_2048 + -0x7640))(param_1,iVar3);
        if (iVar4 != 4) {
          iStack_2090 = (**(code **)(local_2048 + -0x760c))(iVar3);
          if (iStack_2090 == 0) {
            unaff_s1 = *(undefined4 **)(local_2048 + -0x7fa4);
            pcStack_2064 = "ERROR\n";
            (**(code **)(local_2048 + -0x7fa8))(*unaff_s1);
            iVar3 = (**(code **)(local_2048 + -0x7608))(param_1);
            if (iVar3 == 0) {
              (**(code **)(local_2048 + -0x7fa0))(*unaff_s1);
            }
            else {
              unaff_s1 = (undefined4 *)*unaff_s1;
              param_3 = (int *)(**(code **)(local_2048 + -0x7b40))(iVar3);
              pcStack_2064 = "verify error:%s\n";
              (**(code **)(local_2048 + -0x7fa8))(unaff_s1);
            }
          }
          else {
            iStack_2090 = 1;
            pcStack_2064 = "DELAY\n";
            (**(code **)(local_2048 + -0x7fa8))(bio_s_out);
          }
          goto LAB_00443260;
        }
        unaff_s1 = (undefined4 *)&_gp_1;
        param_3 = srp_callback_parm._0_4_;
        (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"LOOKUP during accept %s\n");
        (**(code **)(local_2048 + -0x763c))(srp_callback_parm._8_4_);
        srp_callback_parm._8_4_ =
             (**(code **)(local_2048 + -0x7638))(srp_callback_parm._4_4_,srp_callback_parm._0_4_);
        if (srp_callback_parm._8_4_ != 0) break;
        (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"LOOKUP not successful\n");
        iVar3 = (**(code **)(local_2048 + -0x7644))(param_1);
        if (0 < iVar3) goto LAB_00442ed0;
      }
      param_3 = *(int **)(srp_callback_parm._8_4_ + 0x14);
      (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"LOOKUP done %s\n");
      iVar3 = (**(code **)(local_2048 + -0x7644))(param_1);
    } while (iVar3 < 1);
  }
LAB_00442ed0:
  uVar6 = bio_s_out;
  unaff_s1 = (undefined4 *)&_gp_1;
  uVar5 = (**(code **)(local_2048 + -0x7634))(param_1);
  (**(code **)(local_2048 + -0x7630))(uVar6,uVar5);
  puStack_2088 = (undefined *)(**(code **)(local_2048 + -0x762c))(param_1);
  if (puStack_2088 != (undefined *)0x0) {
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"Client certificate\n");
    (**(code **)(local_2048 + -0x7ec0))(bio_s_out,puStack_2088);
    uVar6 = (**(code **)(local_2048 + -0x7ee0))(puStack_2088);
    (**(code **)(local_2048 + -0x7dd0))(uVar6,auStack_202c,0x2000);
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"subject=%s\n",auStack_202c);
    uVar6 = (**(code **)(local_2048 + -0x76fc))(puStack_2088);
    (**(code **)(local_2048 + -0x7dd0))(uVar6,auStack_202c,0x2000);
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"issuer=%s\n",auStack_202c);
    (**(code **)(local_2048 + -0x7f50))(puStack_2088);
  }
  iVar3 = (**(code **)(local_2048 + -0x7628))(param_1,auStack_202c,0x2000);
  if (iVar3 != 0) {
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"Shared ciphers:%s\n",auStack_202c);
  }
  uVar6 = (**(code **)(local_2048 + -0x7624))(param_1);
  pcVar7 = (char *)(**(code **)(local_2048 + -0x7620))(uVar6);
  if (pcVar7 == (char *)0x0) {
    pcVar7 = "(NONE)";
  }
  (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"CIPHER is %s\n",pcVar7);
  (**(code **)(local_2048 + -0x761c))(param_1,&local_2034,&local_2030);
  if (local_2034 != 0) {
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"NEXTPROTO is ");
    (**(code **)(local_2048 + -0x7fcc))(bio_s_out,local_2034,local_2030);
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"\n");
  }
  puVar8 = (undefined4 *)(**(code **)(local_2048 + -0x7618))(param_1);
  if (puVar8 != (undefined4 *)0x0) {
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"SRTP Extension negotiated, profile=%s\n",*puVar8)
    ;
  }
  iVar3 = (**(code **)(local_2048 + -0x7614))(param_1);
  if (iVar3 != 0) {
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"Reused session-id\n");
  }
  uVar9 = (**(code **)(local_2048 + -0x7658))(param_1,0xd,0,0);
  if ((uVar9 & 8) != 0) {
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"Peer has incorrect TLSv1 block padding\n");
  }
  uVar6 = bio_s_out;
  iVar3 = (**(code **)(local_2048 + -0x7658))(param_1,0x4c,0,0);
  if (iVar3 == 0) {
    param_3 = (int *)&DAT_0063ae0c;
  }
  else {
    param_3 = (int *)0x638d8c;
  }
  pcStack_2064 = "Secure Renegotiation IS%s supported\n";
  (**(code **)(local_2048 + -0x7fa8))(uVar6);
  if (keymatexportlabel == 0) {
LAB_00443328:
    iStack_2090 = 1;
  }
  else {
    unaff_s4 = methods_sockp + 0x10;
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"Keying material exporter:\n");
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"    Label: \'%s\'\n",keymatexportlabel);
    (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"    Length: %i bytes\n",keymatexportlen);
    param_3 = (int *)0x9b0;
    pcStack_2064 = "s_server.c";
    unaff_s5 = (char *)(**(code **)(local_2048 + -0x7dd8))(keymatexportlen);
    iVar3 = keymatexportlabel;
    if ((byte *)unaff_s5 == (byte *)0x0) goto LAB_00443328;
    local_2058 = (**(code **)(local_2048 + -0x53bc))(keymatexportlabel);
    local_204c = 0;
    local_2050 = 0;
    local_2054 = 0;
    local_203c = keymatexportlen;
    param_3 = keymatexportlen;
    iVar3 = (**(code **)(local_2048 + -0x7610))(param_1,unaff_s5,keymatexportlen,iVar3);
    if (iVar3 == 0) {
      pcStack_2064 = "    Error\n";
      (**(code **)(local_2048 + -0x7fa8))();
    }
    else {
      (**(code **)(local_2048 + -0x7fa8))(bio_s_out,"    Keying material: ");
      if (0 < (int)keymatexportlen) {
        puStack_2088 = (undefined *)0x0;
        param_1 = &DAT_00634b80;
        pbVar25 = (byte *)unaff_s5;
        do {
          param_3 = (int *)(uint)*pbVar25;
          puStack_2088 = puStack_2088 + 1;
          pbVar25 = pbVar25 + 1;
          (**(code **)(local_2048 + -0x7fa8))(bio_s_out,&DAT_00634b80);
        } while ((int)puStack_2088 < (int)keymatexportlen);
      }
      pcStack_2064 = "\n";
      (**(code **)(local_2048 + -0x7fa8))(bio_s_out);
    }
    iStack_2090 = 1;
    (**(code **)(local_2048 + -0x7f58))(unaff_s5);
  }
LAB_00443260:
  if (local_2c == *(int *)pcStack_2168) {
    return iStack_2090;
  }
  pcStack_206c = sv_body;
  (**(code **)(local_2048 + -0x5330))();
  puVar8 = (undefined4 *)0x7b6;
  puStack_2148 = &_gp;
  piStack_212c = (int *)PTR___stack_chk_guard_006a9ae8;
  puStack_2070 = pcStack_2168;
  pcStack_2124 = "-check_ss_sig";
  iStack_2094 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_208c = unaff_s1;
  puStack_2084 = param_1;
  puStack_2080 = (undefined4 *)unaff_s4;
  pbStack_207c = (byte *)unaff_s5;
  pcStack_2078 = unaff_s6;
  pcStack_2074 = unaff_s7;
  pcVar7 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x4000,"s_server.c");
  if (pcVar7 == (char *)0x0) {
    iStack_2180 = 1;
    (**(code **)(puStack_2148 + -0x7fa8))
              (**(undefined4 **)(puStack_2148 + -0x7fa4),"out of memory\n");
    (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,"CONNECTION CLOSED\n");
LAB_00443714:
    pcVar19 = s_ACCEPT_0063b138;
    (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out);
  }
  else {
    if (s_nbio != 0) {
      uStack_211c = 1;
      if (s_quiet == 0) {
        (**(code **)(puStack_2148 + -0x7fa8))
                  (**(undefined4 **)(puStack_2148 + -0x7fa4),"turning on non blocking io\n");
      }
      iVar3 = (**(code **)(puStack_2148 + -0x7604))(pcStack_2064,0x667e,&uStack_211c);
      if (iVar3 < 0) {
        (**(code **)(puStack_2148 + -0x7fa0))(**(undefined4 **)(puStack_2148 + -0x7fa4));
      }
    }
    unaff_s4 = &_gp_1;
    param_1 = &_gp_1;
    unaff_s1 = (undefined4 *)(**(code **)(puStack_2148 + -0x7600))(ctx);
    if (s_tlsextdebug != 0) {
      (**(code **)(puStack_2148 + -0x75b8))(unaff_s1,0x38,*(undefined4 *)(puStack_2148 + -0x75b4));
      (**(code **)(puStack_2148 + -0x7658))(unaff_s1,0x39,0,bio_s_out);
    }
    if (s_tlsextstatus != 0) {
      (**(code **)(puStack_2148 + -0x75bc))(ctx,0x3f,cert_status_cb);
      tlscstatp._20_4_ = **(undefined4 **)(puStack_2148 + -0x7fa4);
      (**(code **)(puStack_2148 + -0x7684))(ctx,0x40,0,tlscstatp);
    }
    if (param_3 != (int *)0x0) {
      uVar6 = (**(code **)(puStack_2148 + -0x53bc))(param_3);
      (**(code **)(puStack_2148 + -0x75fc))(unaff_s1,param_3,uVar6);
    }
    (**(code **)(puStack_2148 + -0x75f8))(unaff_s1);
    iVar3 = (**(code **)(puStack_2148 + -0x75f4))(unaff_s1);
    if (iVar3 != 0xfeff) {
      puVar8 = (undefined4 *)(**(code **)(puStack_2148 + -0x75f0))(pcStack_2064,0);
      goto LAB_00443590;
    }
    puVar26 = (undefined4 *)(**(code **)(puStack_2148 + -0x75a0))(pcStack_2064,0);
    if (enable_timeouts != 0) {
      unaff_s4 = (char *)&uStack_211c;
      uStack_211c = 0;
      uStack_2118 = 250000;
      (**(code **)(puStack_2148 + -0x7fc8))(puVar26,0x21,0,unaff_s4);
      uStack_211c = 0;
      uStack_2118 = 250000;
      (**(code **)(puStack_2148 + -0x7fc8))(puVar26,0x23,0,unaff_s4);
    }
    if (socket_mtu == (undefined4 *)0x0) {
      (**(code **)(puStack_2148 + -0x7fc8))(puVar26,0x27,0,0);
LAB_00443fd4:
      (**(code **)(puStack_2148 + -0x7658))(unaff_s1,0x20,0x2000,0);
      puVar8 = puVar26;
LAB_00443590:
      if (s_nbio_test != 0) {
        uVar6 = (**(code **)(puStack_2148 + -0x75ec))();
        uVar6 = (**(code **)(puStack_2148 + -0x7f3c))(uVar6);
        puVar8 = (undefined4 *)(**(code **)(puStack_2148 + -0x791c))(uVar6,puVar8);
      }
      (**(code **)(puStack_2148 + -0x75e8))(unaff_s1,puVar8);
      (**(code **)(puStack_2148 + -0x75e4))(unaff_s1);
      if (s_debug != 0) {
        (**(code **)(puStack_2148 + -0x75ac))(unaff_s1,1);
        uVar6 = (**(code **)(puStack_2148 + -0x75a8))(unaff_s1);
        (**(code **)(puStack_2148 + -0x7904))(uVar6,*(undefined4 *)(puStack_2148 + -0x75a4));
        uVar6 = (**(code **)(puStack_2148 + -0x75a8))(unaff_s1);
        (**(code **)(puStack_2148 + -0x78fc))(uVar6,bio_s_out);
      }
      if (s_msg != 0) {
        (**(code **)(puStack_2148 + -0x75e0))(unaff_s1,*(undefined4 *)(puStack_2148 + -0x75b0));
        puVar8 = (undefined4 *)0x0;
        (**(code **)(puStack_2148 + -0x7658))(unaff_s1,0x10,0,bio_s_out);
      }
      if (s_tlsextdebug != 0) {
        (**(code **)(puStack_2148 + -0x75b8))(unaff_s1,0x38,*(undefined4 *)(puStack_2148 + -0x75b4))
        ;
        puVar8 = (undefined4 *)0x0;
        (**(code **)(puStack_2148 + -0x7658))(unaff_s1,0x39,0,bio_s_out);
      }
      pcStack_2130 = pcStack_2064 + 1;
      uStack_2134 = 1 << ((uint)pcStack_2064 & 0x1f);
      unaff_s6 = "LOOKUP renego during write\n";
      unaff_s7 = "LOOKUP done %s\n";
      puStack_2128 = &_gp_1;
      pcStack_2140 = "LOOKUP not successful\n";
switchD_0044411c_caseD_4:
      pcVar31 = *(code **)(puStack_2148 + -0x75dc);
LAB_00443648:
      while (iStack_2138 = (*pcVar31)(unaff_s1), iStack_2138 == 0) {
        puVar26 = *(undefined4 **)(puStack_2148 + -0x53cc);
        (**(code **)(puStack_2148 + -0x53ec))(auStack_2114,0,0x80);
        unaff_s4 = (char *)(**(code **)(puStack_2148 + -0x5404))(*puVar26);
        uVar6 = (**(code **)(puStack_2148 + -0x5404))(*puVar26);
        iVar3 = (**(code **)(puStack_2148 + -0x5340))(uVar6);
        pcVar19 = pcStack_2064;
        pcVar31 = *(code **)(puStack_2148 + -0x5340);
        auStack_2114[iVar3] = 1 << ((uint)unaff_s4 & 0x1f) | auStack_2114[iVar3];
        iVar3 = (*pcVar31)(pcVar19);
        pcVar31 = *(code **)(puStack_2148 + -0x75f4);
        auStack_2114[iVar3] = auStack_2114[iVar3] | uStack_2134;
        iVar3 = (*pcVar31)(unaff_s1);
        if (iVar3 == 0xfeff) {
          puVar10 = &uStack_211c;
          iVar3 = (**(code **)(puStack_2148 + -0x7658))(unaff_s1,0x49,0,puVar10);
          unaff_s4 = (char *)puVar10;
          if (iVar3 == 0) goto LAB_00443840;
        }
        else {
LAB_00443840:
          puVar10 = (undefined4 *)0x0;
        }
        puVar8 = (undefined4 *)0x0;
        puStack_2150 = puVar10;
        param_1 = (undefined *)(**(code **)(puStack_2148 + -0x531c))(pcStack_2130,auStack_2114,0,0);
        iVar3 = (**(code **)(puStack_2148 + -0x75f4))(unaff_s1);
        if (iVar3 != 0xfeff) goto code_r0x00443880;
        puVar8 = (undefined4 *)0x0;
        iVar3 = (**(code **)(puStack_2148 + -0x7658))(unaff_s1,0x4a,0,0);
        if (0 < iVar3) {
          (**(code **)(puStack_2148 + -0x7fa8))
                    (**(undefined4 **)(puStack_2148 + -0x7fa4),"TIMEOUT occured\n");
        }
        pcVar31 = *(code **)(puStack_2148 + -0x75dc);
        if (0 < (int)param_1) goto LAB_00443888;
      }
      goto LAB_0044365c;
    }
    iVar3 = (**(code **)(puStack_2148 + -0x7658))(unaff_s1,0x79,0,0);
    if ((int)socket_mtu < iVar3) {
      uVar6 = **(undefined4 **)(puStack_2148 + -0x7fa4);
      puVar8 = (undefined4 *)(**(code **)(puStack_2148 + -0x7658))(unaff_s1,0x79,0,0);
      (**(code **)(puStack_2148 + -0x7fa8))(uVar6,"MTU too small. Must be at least %ld\n");
    }
    else {
      (**(code **)(puStack_2148 + -0x7658))(unaff_s1,0x20,0x1000,0);
      puVar8 = socket_mtu;
      iVar3 = (**(code **)(puStack_2148 + -0x7658))(unaff_s1,0x78,socket_mtu,0);
      if (iVar3 != 0) goto LAB_00443fd4;
      (**(code **)(puStack_2148 + -0x7fa8))
                (**(undefined4 **)(puStack_2148 + -0x7fa4),"Failed to set MTU\n");
    }
    iStack_2180 = -1;
    (**(code **)(puStack_2148 + -0x7f70))(puVar26);
LAB_00443694:
    if (unaff_s1 != (undefined4 *)0x0) {
      (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,"shutting down SSL\n");
      (**(code **)(puStack_2148 + -0x75d4))(unaff_s1,3);
      (**(code **)(puStack_2148 + -0x75d0))(unaff_s1);
    }
    (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,"CONNECTION CLOSED\n");
    pcVar19 = (char *)0x4000;
    (**(code **)(puStack_2148 + -0x7d6c))(pcVar7);
    (**(code **)(puStack_2148 + -0x7f58))(pcVar7);
    pcStack_2168 = pcVar7;
    if (-1 < iStack_2180) goto LAB_00443714;
  }
  if (iStack_2094 == *piStack_212c) {
    return iStack_2180;
  }
  pcStack_2164 = www_body;
  (**(code **)(puStack_2148 + -0x5330))();
  puVar11 = PTR___stack_chk_guard_006a9ae8;
  puStack_2188 = &_gp_1;
  pcVar7 = "s_server.c";
  piVar23 = (int *)0x9f9;
  iStack_218c = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_2184 = unaff_s1;
  puStack_217c = param_1;
  puStack_2178 = (undefined4 *)unaff_s4;
  pbStack_2174 = (byte *)unaff_s5;
  pcStack_2170 = unaff_s6;
  pcStack_216c = unaff_s7;
  iVar3 = (*(code *)PTR_CRYPTO_malloc_006a7008)(0x4000);
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    uVar6 = (*(code *)PTR_BIO_f_buffer_006a7854)();
    iVar4 = (*(code *)PTR_BIO_new_006a6ea4)(uVar6);
    uVar6 = (*(code *)PTR_BIO_f_ssl_006a7858)();
    iVar12 = (*(code *)PTR_BIO_new_006a6ea4)(uVar6);
    if (iVar4 != 0) {
      if (iVar12 != 0) {
        if (s_nbio != 0) {
          uStack_2190 = 1;
          if (s_quiet == 0) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)PTR_bio_err_006a6e3c,"turning on non blocking io\n");
          }
          iVar13 = (*(code *)PTR_BIO_socket_ioctl_006a77dc)(pcVar19,0x667e,&uStack_2190);
          if (iVar13 < 0) {
            (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)PTR_bio_err_006a6e3c);
          }
        }
        piVar23 = (int *)&DAT_00004000;
        iVar13 = (*(code *)PTR_BIO_int_ctrl_006a785c)(iVar4,0x75,0x4000,1);
        if ((iVar13 != 0) && (iVar13 = (*(code *)PTR_SSL_new_006a77e0)(ctx), iVar13 != 0)) {
          if (s_tlsextdebug != 0) {
            (*(code *)PTR_SSL_callback_ctrl_006a7828)(iVar13,0x38,PTR_tlsext_cb_006a782c);
            (*(code *)PTR_SSL_ctrl_006a7788)(iVar13,0x39,0,bio_s_out);
          }
          if (puVar8 != (undefined4 *)0x0) {
            uVar6 = (*(code *)PTR_strlen_006a9a24)(puVar8);
            (*(code *)PTR_SSL_set_session_id_context_006a77e4)(iVar13,puVar8,uVar6);
          }
          uVar6 = (*(code *)PTR_BIO_new_socket_006a77f0)(pcVar19,0);
          if (s_nbio_test != 0) {
            uVar5 = (*(code *)PTR_BIO_f_nbio_test_006a77f4)();
            uVar5 = (*(code *)PTR_BIO_new_006a6ea4)(uVar5);
            uVar6 = (*(code *)PTR_BIO_push_006a74c4)(uVar5,uVar6);
          }
          (*(code *)PTR_SSL_set_bio_006a77f8)(iVar13,uVar6);
          (*(code *)PTR_SSL_set_accept_state_006a77fc)(iVar13);
          piVar23 = (int *)0x1;
          (*(code *)PTR_BIO_ctrl_006a6e18)(iVar12,0x6d,1,iVar13);
          (*(code *)PTR_BIO_push_006a74c4)(iVar4,iVar12);
          if (s_debug != 0) {
            (*(code *)PTR_SSL_set_debug_006a7834)(iVar13,1);
            uVar6 = (*(code *)PTR_SSL_get_rbio_006a7838)(iVar13);
            (*(code *)PTR_BIO_set_callback_006a74dc)(uVar6,PTR_bio_dump_callback_006a783c);
            uVar6 = (*(code *)PTR_SSL_get_rbio_006a7838)(iVar13);
            (*(code *)PTR_BIO_set_callback_arg_006a74e4)(uVar6,bio_s_out);
          }
          if (s_msg != 0) {
            (*(code *)PTR_SSL_set_msg_callback_006a7800)(iVar13,PTR_msg_cb_006a7830);
            piVar23 = (int *)0x0;
            (*(code *)PTR_SSL_ctrl_006a7788)(iVar13,0x10,0,bio_s_out);
          }
LAB_00444704:
          if (hack != 0) {
            iVar12 = (*(code *)PTR_SSL_accept_006a779c)(iVar13);
            while (iVar12 < 1) {
              while( true ) {
                iVar14 = (*(code *)PTR_SSL_get_error_006a77a0)(iVar13,iVar12);
                if (iVar14 != 4) goto LAB_00444800;
                piVar23 = srp_callback_parm._0_4_;
                (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"LOOKUP during accept %s\n");
                (*(code *)PTR_SRP_user_pwd_free_006a77a4)(srp_callback_parm._8_4_);
                srp_callback_parm._8_4_ =
                     (*(code *)PTR_SRP_VBASE_get1_by_user_006a77a8)
                               (srp_callback_parm._4_4_,srp_callback_parm._0_4_);
                if (srp_callback_parm._8_4_ != 0) break;
                (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"LOOKUP not successful\n");
                iVar12 = (*(code *)PTR_SSL_accept_006a779c)(iVar13);
                if (0 < iVar12) goto LAB_00444800;
              }
              piVar23 = *(int **)(srp_callback_parm._8_4_ + 0x14);
              (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"LOOKUP done %s\n");
              iVar12 = (*(code *)PTR_SSL_accept_006a779c)(iVar13);
            }
LAB_00444800:
            uVar9 = (*(code *)PTR_SSL_get_error_006a77a0)(iVar13,iVar12);
            if (uVar9 < 7) {
              uVar9 = 1 << (uVar9 & 0x1f);
              if ((uVar9 & 0x62) != 0) goto LAB_0044455c;
              if ((uVar9 & 0x1c) != 0) goto LAB_00444704;
            }
            (*(code *)PTR_SSL_renegotiate_006a7848)(iVar13);
            (*(code *)PTR_SSL_write_006a7820)(iVar13,0,0);
          }
          piVar23 = (int *)0x3fff;
          iVar12 = (*(code *)PTR_BIO_gets_006a74d4)(iVar4,iVar3);
          if (iVar12 < 0) {
            iVar12 = (*(code *)PTR_BIO_test_flags_006a7868)(iVar4,8);
            if (iVar12 == 0) {
              if (s_quiet == 0) {
                (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)PTR_bio_err_006a6e3c);
              }
              goto LAB_0044455c;
            }
            (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"read R BLOCK\n");
            iVar12 = (*(code *)PTR_BIO_test_flags_006a7868)(iVar4,4);
            if ((iVar12 == 0) ||
               (iVar12 = (*(code *)PTR_BIO_get_retry_reason_006a786c)(iVar4), iVar12 != 1)) {
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
          if (iVar12 == 0) goto LAB_00444e4c;
          if (www != 1) {
            if (www != 2) {
              if (www == 3) goto LAB_00444b44;
              goto LAB_00444704;
            }
            iVar12 = (*(code *)PTR_strncmp_006a9970)("GET /stats ",iVar3,0xb);
            if (iVar12 == 0) goto LAB_004448cc;
LAB_00444b44:
            piVar23 = (int *)&DAT_00000005;
            iVar12 = (*(code *)PTR_strncmp_006a9970)(&DAT_0063b2b0,iVar3);
            puVar2 = PTR_BIO_puts_006a6f58;
            if (iVar12 == 0) goto code_r0x00444b5c;
            goto LAB_00444704;
          }
          piVar23 = (int *)&SUB_00000004;
          iVar12 = (*(code *)PTR_strncmp_006a9970)(&DAT_0063b16c,iVar3);
          if (iVar12 != 0) goto LAB_00444704;
LAB_004448cc:
          (*(code *)PTR_BIO_puts_006a6f58)
                    (iVar4,"HTTP/1.0 200 ok\r\nContent-type: text/html\r\n\r\n");
          (*(code *)PTR_BIO_puts_006a6f58)(iVar4,"<HTML><BODY BGCOLOR=\"#ffffff\">\n");
          (*(code *)PTR_BIO_puts_006a6f58)(iVar4,"<pre>\n");
          (*(code *)PTR_BIO_puts_006a6f58)(iVar4,"\n");
          if (0 < local_argc) {
            iVar12 = 0;
            do {
              iVar14 = iVar12 * 4;
              iVar12 = iVar12 + 1;
              (*(code *)PTR_BIO_puts_006a6f58)(iVar4,*(undefined4 *)(local_argv + iVar14));
              (*(code *)PTR_BIO_write_006a6e14)(iVar4,&DAT_0063eb84,1);
            } while (iVar12 < local_argc);
          }
          (*(code *)PTR_BIO_puts_006a6f58)(iVar4,"\n");
          iVar12 = (*(code *)PTR_SSL_ctrl_006a7788)(iVar13,0x4c,0,0);
          if (iVar12 == 0) {
            pcVar7 = " NOT";
          }
          else {
            pcVar7 = "";
          }
          (*(code *)PTR_BIO_printf_006a6e38)(iVar4,"Secure Renegotiation IS%s supported\n",pcVar7);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar4,"Ciphers supported in s_server binary\n");
          uVar6 = (*(code *)PTR_SSL_get_ciphers_006a7860)(iVar13);
          uVar9 = (*(code *)PTR_sk_num_006a6e2c)(uVar6);
          if (0 < (int)uVar9) {
            uVar5 = (*(code *)PTR_sk_value_006a6e24)(uVar6,0);
            uVar15 = (*(code *)PTR_SSL_CIPHER_get_version_006a7864)(uVar5);
            uVar5 = (*(code *)PTR_SSL_CIPHER_get_name_006a77c0)(uVar5);
            (*(code *)PTR_BIO_printf_006a6e38)(iVar4,"%-11s:%-25s",uVar15,uVar5);
            uVar27 = 1;
            while (uVar9 != uVar27) {
              uVar30 = uVar27 + 1;
              uVar5 = (*(code *)PTR_sk_value_006a6e24)(uVar6,uVar27);
              uVar15 = (*(code *)PTR_SSL_CIPHER_get_version_006a7864)(uVar5);
              uVar5 = (*(code *)PTR_SSL_CIPHER_get_name_006a77c0)(uVar5);
              (*(code *)PTR_BIO_printf_006a6e38)(iVar4,"%-11s:%-25s",uVar15,uVar5);
              uVar27 = uVar30;
              if ((uVar30 & 1) == 0) {
                if (uVar9 == uVar30) break;
                (*(code *)PTR_BIO_puts_006a6f58)(iVar4,"\n");
              }
            }
          }
          (*(code *)PTR_BIO_puts_006a6f58)(iVar4,"\n");
          pcVar7 = (char *)(*(code *)PTR_SSL_get_shared_ciphers_006a77b8)(iVar13,iVar3,0x4000);
          if (pcVar7 != (char *)0x0) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (iVar4,"---\nCiphers common between both SSL end points:\n");
            cVar17 = *pcVar7;
            if (cVar17 != '\0') {
              iVar14 = 0;
              iVar12 = 0;
              do {
                if (cVar17 == ':') {
                  iVar12 = iVar12 + 1;
                  (*(code *)PTR_BIO_write_006a6e14)(iVar4,&DAT_0063b240,0x1a - iVar14);
                  if (iVar12 == (iVar12 / 3) * 3) {
                    puVar8 = (undefined4 *)0x63b2e4;
                  }
                  else {
                    puVar8 = &DAT_0063eb84;
                  }
                  iVar14 = 0;
                  (*(code *)PTR_BIO_write_006a6e14)(iVar4,puVar8,1);
                }
                else {
                  (*(code *)PTR_BIO_write_006a6e14)(iVar4,pcVar7,1);
                  iVar14 = iVar14 + 1;
                }
                pcVar7 = pcVar7 + 1;
                cVar17 = *pcVar7;
              } while (cVar17 != '\0');
            }
            (*(code *)PTR_BIO_puts_006a6f58)(iVar4,"\n");
          }
          iVar12 = (*(code *)PTR_SSL_cache_hit_006a77cc)(iVar13);
          if (iVar12 == 0) {
            pcVar7 = "---\nNew, ";
          }
          else {
            pcVar7 = "---\nReused, ";
          }
          (*(code *)PTR_BIO_printf_006a6e38)(iVar4,pcVar7);
          uVar6 = (*(code *)PTR_SSL_get_current_cipher_006a77bc)(iVar13);
          uVar5 = (*(code *)PTR_SSL_CIPHER_get_version_006a7864)(uVar6);
          uVar6 = (*(code *)PTR_SSL_CIPHER_get_name_006a77c0)(uVar6);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar4,"%s, Cipher is %s\n",uVar5,uVar6);
          uVar6 = (*(code *)PTR_SSL_get_session_006a77ac)(iVar13);
          (*(code *)PTR_SSL_SESSION_print_006a7870)(iVar4,uVar6);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar4,&DAT_0063b270);
          uVar6 = (*(code *)PTR_SSL_get_SSL_CTX_006a7768)(iVar13);
          print_stats(iVar4,uVar6);
          (*(code *)PTR_BIO_printf_006a6e38)(iVar4,&DAT_0063b270);
          iVar12 = (*(code *)PTR_SSL_get_peer_certificate_006a77b4)(iVar13);
          if (iVar12 == 0) {
            (*(code *)PTR_BIO_puts_006a6f58)(iVar4,"no client certificate available\n");
          }
          else {
            (*(code *)PTR_BIO_printf_006a6e38)(iVar4,"Client certificate\n");
            (*(code *)PTR_X509_print_006a70c0)(iVar4,iVar12);
            (*(code *)PTR_PEM_write_bio_X509_006a6f20)(iVar4,iVar12);
          }
          (*(code *)PTR_BIO_puts_006a6f58)(iVar4,"</BODY></HTML>\r\n\r\n");
          goto LAB_00444e2c;
        }
      }
      goto LAB_0044455c;
    }
    pcVar7 = s_ACCEPT_0063b138;
    (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out);
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar3);
    iVar3 = 1;
  }
LAB_00444590:
  if (iStack_218c == *(int *)puVar11) {
    return iVar3;
  }
  iVar3 = iStack_218c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar4 = piVar23[2];
  if (*piVar23 == 0) {
    if (iVar4 == 0) {
      iVar3 = (*(code *)PTR_SSL_get_srp_username_006a7878)();
      *piVar23 = iVar3;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,"SRP username = \"%s\"\n",iVar3);
      return -1;
    }
  }
  else if (iVar4 == 0) {
    iVar3 = 2;
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,"User %s doesn\'t exist\n");
    goto LAB_004455d4;
  }
  iVar3 = (*(code *)PTR_SSL_set_srp_server_param_006a7874)
                    (iVar3,*(undefined4 *)(iVar4 + 0x10),*(undefined4 *)(iVar4 + 0xc),
                     *(undefined4 *)(iVar4 + 4),*(undefined4 *)(iVar4 + 8),
                     *(undefined4 *)(iVar4 + 0x14));
  if (iVar3 < 0) {
    iVar3 = 2;
    *(undefined4 *)pcVar7 = 0x50;
  }
  else {
    iVar3 = 0;
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,
               "SRP parameters set: username = \"%s\" info=\"%s\" \n",*piVar23,
               *(undefined4 *)(piVar23[2] + 0x14));
  }
LAB_004455d4:
  (*(code *)PTR_SRP_user_pwd_free_006a77a4)(piVar23[2]);
  piVar23[2] = 0;
  *piVar23 = 0;
  return iVar3;
code_r0x00443880:
  pcVar31 = *(code **)(puStack_2148 + -0x75dc);
  if ((int)param_1 < 1) goto LAB_00443648;
LAB_00443888:
  uVar6 = (**(code **)(puStack_2148 + -0x5404))(*puVar26);
  iVar3 = (**(code **)(puStack_2148 + -0x5340))(uVar6);
  uVar27 = auStack_2114[iVar3];
  uVar9 = (**(code **)(puStack_2148 + -0x5404))(*puVar26);
  uVar27 = 1 << (uVar9 & 0x1f) & uVar27;
  iVar3 = (**(code **)(puStack_2148 + -0x5340))(pcStack_2064);
  if ((uStack_2134 & auStack_2114[iVar3]) == 0) {
    if (uVar27 == 0) goto switchD_0044411c_caseD_4;
    iVar3 = *(int *)(puStack_2128 + -0x5ecc);
joined_r0x00443aa4:
    if (iVar3 == 0) {
      unaff_s4 = (char *)raw_read_stdin(pcVar7,0x4000);
LAB_00443ac4:
      param_1 = &_gp_1;
      if (s_quiet == 0) {
        if (((int)unaff_s4 < 1) || (cVar17 = *pcVar7, cVar17 == 'Q')) {
LAB_004442d0:
          param_1 = &_gp_1;
          (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,"DONE\n");
          (**(code **)(puStack_2148 + -0x5484))(pcStack_2064,0);
          (**(code **)(puStack_2148 + -0x5494))(pcStack_2064);
          (**(code **)(puStack_2148 + -0x7fa8))
                    (**(undefined4 **)(puStack_2148 + -0x7fa4),"shutdown accept socket\n");
          if (accept_socket < 0) {
            iStack_2180 = -0xb;
          }
          else {
            (**(code **)(puStack_2148 + -0x5484))(accept_socket,2);
            iStack_2180 = -0xb;
            (**(code **)(puStack_2148 + -0x5494))(accept_socket);
          }
          goto LAB_00443694;
        }
        if (cVar17 == 'q') {
          (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,"DONE\n");
          iVar3 = (**(code **)(puStack_2148 + -0x75f4))(unaff_s1);
          if (iVar3 != 0xfeff) {
            iStack_2180 = 1;
            (**(code **)(puStack_2148 + -0x5484))(pcStack_2064,0);
            (**(code **)(puStack_2148 + -0x5494))(pcStack_2064);
            goto LAB_00443694;
          }
          goto LAB_00443690;
        }
        if (cVar17 == 'B') {
          if ((pcVar7[1] == '\n') || (pcVar7[1] == '\r')) {
            param_1 = &_gp_1;
            (**(code **)(puStack_2148 + -0x7fa8))
                      (**(undefined4 **)(puStack_2148 + -0x7fa4),"HEARTBEATING\n");
            puVar8 = (undefined4 *)0x0;
            (**(code **)(puStack_2148 + -0x7658))(unaff_s1,0x55,0,0);
            goto switchD_0044411c_caseD_4;
          }
        }
        else if (cVar17 == 'r') {
          if ((pcVar7[1] == '\n') || (pcVar7[1] == '\r')) {
            pcVar31 = *(code **)(puStack_2148 + -0x7598);
LAB_004441cc:
            param_1 = &_gp_1;
            (*pcVar31)(unaff_s1);
            puVar8 = (undefined4 *)(**(code **)(puStack_2148 + -0x7594))(unaff_s1);
            (**(code **)(puStack_2148 + -0x541c))(1,"SSL_do_handshake -> %d\n");
            goto switchD_0044411c_caseD_4;
          }
        }
        else if (cVar17 == 'R') {
          if ((pcVar7[1] == '\n') || (pcVar7[1] == '\r')) {
            (**(code **)(puStack_2148 + -0x759c))(unaff_s1,5,0);
            pcVar31 = *(code **)(puStack_2148 + -0x7598);
            goto LAB_004441cc;
          }
        }
        else {
          if (cVar17 == 'P') {
            uVar6 = (**(code **)(puStack_2148 + -0x75c4))(unaff_s1);
            (**(code **)(puStack_2148 + -0x7fcc))(uVar6,"Lets print some clear text\n",0x1b);
            cVar17 = *pcVar7;
          }
          uVar6 = bio_s_out;
          if (cVar17 == 'S') {
            uVar5 = (**(code **)(puStack_2148 + -0x7678))(unaff_s1);
            print_stats(uVar6,uVar5);
          }
        }
      }
    }
    else {
      unaff_s4 = (char *)raw_read_stdin(pcVar7,0x2000);
      if (0 < (int)unaff_s4) {
        iVar3 = 0;
        pcVar19 = pcVar7;
        do {
          cVar17 = *pcVar19;
          pcVar19 = pcVar19 + 1;
          iVar3 = iVar3 + (uint)(cVar17 == '\n');
        } while (pcVar7 + (int)unaff_s4 != pcVar19);
        puVar11 = (undefined *)((int)unaff_s4 + -1);
        pcVar24 = pcVar7 + iVar3;
        pcVar19 = pcVar7 + (int)puVar11;
        do {
          while( true ) {
            puVar8 = (undefined4 *)(int)*pcVar19;
            pcVar24[(int)puVar11] = *pcVar19;
            if (*pcVar19 != '\n') break;
            iVar3 = iVar3 + -1;
            unaff_s4 = (char *)((int)unaff_s4 + 1);
            pcVar24 = pcVar7 + iVar3;
            pcVar19 = pcVar19 + -1;
            pcVar20 = pcVar24 + (int)puVar11;
            puVar11 = puVar11 + -1;
            *pcVar20 = '\r';
            if (puVar11 == (undefined *)0xffffffff) goto LAB_004439c0;
          }
          puVar11 = puVar11 + -1;
          pcVar19 = pcVar19 + -1;
        } while (puVar11 != (undefined *)0xffffffff);
LAB_004439c0:
        if (iVar3 != 0) {
          iVar3 = (**(code **)(puStack_2148 + -0x54a4))
                            ("lf_num == 0",pcStack_2124 + -0x5050,0x87e,"sv_body");
          return iVar3;
        }
        goto LAB_00443ac4;
      }
      if (s_quiet == 0) goto LAB_004442d0;
    }
    param_1 = &_gp_1;
    iStack_213c = 0;
    do {
      pcVar31 = *(code **)(puStack_2148 + -0x75c0);
      unaff_s5 = pcVar7 + iStack_213c;
      while( true ) {
        puVar8 = (undefined4 *)unaff_s4;
        iVar3 = (*pcVar31)(unaff_s1,unaff_s5);
        iVar4 = (**(code **)(puStack_2148 + -0x7640))(unaff_s1,iVar3);
        if (iVar4 != 4) break;
        (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,"LOOKUP renego during write\n");
        (**(code **)(puStack_2148 + -0x763c))(srp_callback_parm._8_4_);
        srp_callback_parm._8_4_ =
             (**(code **)(puStack_2148 + -0x7638))(srp_callback_parm._4_4_,srp_callback_parm._0_4_);
        if (srp_callback_parm._8_4_ == 0) {
          (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,pcStack_2140);
          pcVar31 = *(code **)(puStack_2148 + -0x75c0);
        }
        else {
          (**(code **)(puStack_2148 + -0x7fa8))
                    (bio_s_out,"LOOKUP done %s\n",*(undefined4 *)(srp_callback_parm._8_4_ + 0x14));
          pcVar31 = *(code **)(puStack_2148 + -0x75c0);
        }
      }
      uVar6 = (**(code **)(puStack_2148 + -0x7640))(unaff_s1,iVar3);
      switch(uVar6) {
      case 1:
      case 5:
        goto switchD_00443c88_caseD_1;
      case 2:
      case 3:
      case 4:
        (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,"Write BLOCK\n");
        break;
      case 6:
        goto switchD_00443c88_caseD_6;
      }
      if (0 < iVar3) {
        unaff_s4 = (char *)((int)unaff_s4 - iVar3);
        iStack_213c = iStack_213c + iVar3;
      }
    } while (0 < (int)unaff_s4);
    pcVar31 = *(code **)(puStack_2148 + -0x75d8);
    if (iStack_2138 == 0) goto switchD_0044411c_caseD_4;
  }
  else {
    iStack_2138 = 1;
    if (uVar27 != 0) {
      iVar3 = *(int *)(puStack_2128 + -0x5ecc);
      goto joined_r0x00443aa4;
    }
LAB_0044365c:
    pcVar31 = *(code **)(puStack_2148 + -0x75d8);
  }
  iVar3 = (*pcVar31)(unaff_s1);
  if (iVar3 == 3) {
    param_1 = &_gp_1;
    unaff_s4 = "LOOKUP renego during read\n";
LAB_004439f8:
    while( true ) {
      puVar8 = (undefined4 *)&DAT_00004000;
      uVar6 = (**(code **)(puStack_2148 + -0x75c8))(unaff_s1,pcVar7);
      iVar3 = (**(code **)(puStack_2148 + -0x7640))(unaff_s1,uVar6);
      if (iVar3 != 4) break;
      (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,"LOOKUP renego during read\n");
      (**(code **)(puStack_2148 + -0x763c))(srp_callback_parm._8_4_);
      srp_callback_parm._8_4_ =
           (**(code **)(puStack_2148 + -0x7638))(srp_callback_parm._4_4_,srp_callback_parm._0_4_);
      if (srp_callback_parm._8_4_ == 0) {
        (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,pcStack_2140);
      }
      else {
        (**(code **)(puStack_2148 + -0x7fa8))
                  (bio_s_out,"LOOKUP done %s\n",*(undefined4 *)(srp_callback_parm._8_4_ + 0x14));
      }
    }
    uVar5 = (**(code **)(puStack_2148 + -0x7640))(unaff_s1,uVar6);
    switch(uVar5) {
    case 0:
      goto switchD_0044411c_caseD_0;
    case 1:
    case 5:
      goto switchD_00443c88_caseD_1;
    case 2:
    case 3:
      (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,"Read BLOCK\n");
    default:
      goto switchD_0044411c_caseD_4;
    case 6:
      goto switchD_00443c88_caseD_6;
    }
  }
  iVar3 = init_ssl_connection(unaff_s1);
  if (iVar3 < 0) {
    iStack_2180 = 0;
    goto LAB_00443694;
  }
  pcVar31 = *(code **)(puStack_2148 + -0x75dc);
  if (iVar3 != 0) goto LAB_00443648;
LAB_00443690:
  iStack_2180 = 1;
  goto LAB_00443694;
switchD_00443c88_caseD_6:
  param_1 = &_gp_1;
  iStack_2180 = 1;
  (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,"DONE\n");
  goto LAB_00443694;
switchD_00443c88_caseD_1:
  param_1 = &_gp_1;
  iStack_2180 = 1;
  (**(code **)(puStack_2148 + -0x7fa8))(bio_s_out,"ERROR\n");
  (**(code **)(puStack_2148 + -0x7fa0))(**(undefined4 **)(puStack_2148 + -0x7fa4));
  goto LAB_00443694;
switchD_0044411c_caseD_0:
  raw_write_stdout(pcVar7,uVar6);
  iVar3 = (**(code **)(puStack_2148 + -0x75dc))(unaff_s1);
  if (iVar3 == 0) goto code_r0x004442ac;
  goto LAB_004439f8;
code_r0x004442ac:
  pcVar31 = *(code **)(puStack_2148 + -0x75dc);
  goto LAB_00443648;
code_r0x00444b5c:
  bVar1 = *(byte *)(iVar3 + 5);
  puVar28 = (undefined *)(iVar3 + 5);
  if (bVar1 == 0) {
LAB_0044525c:
    (*(code *)PTR_BIO_puts_006a6f58)(iVar4,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
    (*(code *)PTR_BIO_printf_006a6e38)(iVar4,"\'%s\' is an invalid file name\r\n",puVar28);
  }
  else {
    uVar9 = 1;
    puVar21 = puVar28;
    puVar22 = puVar28;
    if (bVar1 != 0x20) {
      do {
        if (uVar9 == 1) {
          bVar18 = bVar1 ^ 0x2f;
          if (bVar1 == 0x2e) {
            bVar18 = puVar21[1];
            if (bVar18 == 0) goto LAB_0044525c;
            puVar22 = puVar21 + 1;
            if (bVar18 == 0x20) goto LAB_004451cc;
            if (bVar18 == 0x2e) {
              bVar18 = puVar21[2];
              if (bVar18 == 0) goto LAB_0044525c;
              puVar22 = puVar21 + 2;
              if (bVar18 == 0x20) goto LAB_004453bc;
              if (bVar18 == 0x2f) {
                if (puVar21[3] == '\0') goto LAB_0044525c;
                puVar22 = puVar21 + 3;
                if (puVar21[3] == ' ') goto LAB_004453bc;
                pcVar7 = puVar21 + 4;
                puVar21 = puVar21 + 4;
                if (*pcVar7 == '\0') goto LAB_0044525c;
                if (*pcVar7 != ' ') {
                  uVar9 = 0xffffffff;
                  goto LAB_00444b98;
                }
                uVar9 = 0xffffffff;
                break;
              }
            }
            puVar21 = puVar22;
            bVar18 = bVar18 ^ 0x2f;
          }
LAB_00444ed0:
          uVar9 = (uint)(bVar18 == 0);
        }
        else {
          bVar18 = bVar1 ^ 0x2f;
          if (uVar9 == 0) goto LAB_00444ed0;
        }
LAB_00444b98:
        bVar1 = puVar21[1];
        puVar21 = puVar21 + 1;
        if (bVar1 == 0) goto LAB_0044525c;
      } while (bVar1 != 0x20);
      puVar22 = puVar21;
      if (uVar9 == 0xffffffff) {
LAB_004453bc:
        *puVar22 = 0;
        (*(code *)puVar2)(iVar4,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
        (*(code *)PTR_BIO_printf_006a6e38)(iVar4,"\'%s\' contains \'..\' reference\r\n",puVar28);
        goto LAB_00444e2c;
      }
    }
LAB_004451cc:
    *puVar22 = 0;
    if (*(char *)(iVar3 + 5) == '/') {
      (*(code *)PTR_BIO_puts_006a6f58)(iVar4,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
      (*(code *)PTR_BIO_printf_006a6e38)(iVar4,"\'%s\' is an invalid path\r\n",puVar28);
    }
    else {
      iVar12 = app_isdir(puVar28);
      if (iVar12 < 1) {
        iVar12 = (*(code *)PTR_BIO_new_file_006a6eac)(puVar28,"r");
        if (iVar12 == 0) {
          (*(code *)PTR_BIO_puts_006a6f58)
                    (iVar4,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
          (*(code *)PTR_BIO_printf_006a6e38)(iVar4,"Error opening \'%s\'\r\n",puVar28);
          (*(code *)PTR_ERR_print_errors_006a6e40)(iVar4);
        }
        else {
          if (s_quiet == 0) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)PTR_bio_err_006a6e3c,"FILE:%s\n",puVar28);
          }
          if (www == 2) {
            iVar14 = (*(code *)PTR_strlen_006a9a24)(puVar28);
            if (iVar14 < 6) {
              if (iVar14 == 5) goto LAB_004454d0;
LAB_00445514:
              (*(code *)PTR_BIO_puts_006a6f58)
                        (iVar4,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
            }
            else {
              iVar29 = (*(code *)PTR_strcmp_006a9b18)(puVar28 + iVar14 + -5,".html");
              if (iVar29 != 0) {
LAB_004454d0:
                iVar29 = (*(code *)PTR_strcmp_006a9b18)(puVar28 + iVar14 + -4,&DAT_0063b360);
                if ((iVar29 != 0) &&
                   (iVar14 = (*(code *)PTR_strcmp_006a9b18)(puVar28 + iVar14 + -4,&DAT_0063b368),
                   iVar14 != 0)) goto LAB_00445514;
              }
              (*(code *)PTR_BIO_puts_006a6f58)
                        (iVar4,"HTTP/1.0 200 ok\r\nContent-type: text/html\r\n\r\n");
            }
          }
          while (iVar14 = (*(code *)PTR_BIO_read_006a74c0)(iVar12,iVar3,0x4000), 0 < iVar14) {
            iVar29 = 0;
            do {
              iVar16 = (*(code *)PTR_BIO_write_006a6e14)(iVar4,iVar3 + iVar29,iVar14 - iVar29);
              if (iVar16 < 1) {
                iVar16 = (*(code *)PTR_BIO_test_flags_006a7868)(iVar4,8);
                if (iVar16 == 0) goto LAB_00445364;
                (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out,"rwrite W BLOCK\n");
              }
              else {
                iVar29 = iVar29 + iVar16;
              }
            } while (iVar29 < iVar14);
          }
LAB_00445364:
          (*(code *)PTR_BIO_free_006a6e70)(iVar12);
        }
      }
      else {
        (*(code *)PTR_BIO_puts_006a6f58)
                  (iVar4,"HTTP/1.0 200 ok\r\nContent-type: text/plain\r\n\r\n");
        (*(code *)PTR_BIO_printf_006a6e38)(iVar4,"\'%s\' is a directory\r\n",puVar28);
      }
    }
  }
LAB_00444e2c:
  do {
    piVar23 = (int *)0x0;
    iVar12 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar4,0xb,0,0);
    if (0 < iVar12) break;
    iVar12 = (*(code *)PTR_BIO_test_flags_006a7868)(iVar4,8);
  } while (iVar12 != 0);
LAB_00444e4c:
  (*(code *)PTR_SSL_set_shutdown_006a780c)(iVar13,3);
LAB_0044455c:
  pcVar7 = s_ACCEPT_0063b138;
  (*(code *)PTR_BIO_printf_006a6e38)(bio_s_out);
  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar3);
  (*(code *)PTR_BIO_free_all_006a6e74)(iVar4);
  iVar3 = 1;
  goto LAB_00444590;
}

