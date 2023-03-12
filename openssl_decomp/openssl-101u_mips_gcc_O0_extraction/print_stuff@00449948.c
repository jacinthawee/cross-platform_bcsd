
int print_stuff(undefined4 param_1,undefined *param_2,int param_3)

{
  undefined uVar1;
  bool bVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined *puVar8;
  undefined4 *puVar9;
  char cVar13;
  int iVar10;
  int iVar11;
  uint uVar12;
  char *pcVar14;
  char *pcVar15;
  undefined *puVar16;
  code *pcVar17;
  undefined4 uStack_208c;
  char *pcStack_2088;
  int iStack_2084;
  undefined4 uStack_2080;
  undefined *puStack_207c;
  int iStack_2078;
  code *pcStack_2074;
  undefined4 local_2060;
  undefined4 local_205c;
  undefined4 local_2058;
  undefined4 local_2054;
  undefined *local_2050;
  int local_2044;
  char *local_2040;
  char *local_203c;
  undefined4 local_2034;
  undefined4 local_2030;
  undefined auStack_202c [8192];
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_2050 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (param_3 == 0) {
    iVar4 = (*(code *)PTR_SSL_cache_hit_006a77cc)(param_2);
    if (iVar4 == 0) {
      pcVar14 = "---\nNew, ";
    }
    else {
      pcVar14 = "---\nReused, ";
    }
    (**(code **)(local_2050 + -0x7fa8))(param_1,pcVar14);
    uVar5 = (**(code **)(local_2050 + -0x7624))(param_2);
    uVar6 = (**(code **)(local_2050 + -0x757c))(uVar5);
    uVar5 = (**(code **)(local_2050 + -0x7620))(uVar5);
    iStack_2078 = 0;
    (**(code **)(local_2050 + -0x7fa8))(param_1,"%s, Cipher is %s\n",uVar6,uVar5);
  }
  else {
    iVar4 = (*(code *)PTR_SSL_get_peer_cert_chain_006a7978)(param_2);
    if (iVar4 == 0) {
      bVar2 = false;
    }
    else {
      iVar10 = 0;
      (**(code **)(local_2050 + -0x7fa8))(param_1,"---\nCertificate chain\n");
      iVar7 = (**(code **)(local_2050 + -0x7fb4))(iVar4);
      if (0 < iVar7) {
        do {
          uVar5 = (**(code **)(local_2050 + -0x7fbc))(iVar4,iVar10);
          uVar5 = (**(code **)(local_2050 + -0x7ee0))(uVar5);
          (**(code **)(local_2050 + -0x7dd0))(uVar5,auStack_202c,0x2000);
          (**(code **)(local_2050 + -0x7fa8))(param_1,"%2d s:%s\n",iVar10,auStack_202c);
          uVar5 = (**(code **)(local_2050 + -0x7fbc))(iVar4,iVar10);
          uVar5 = (**(code **)(local_2050 + -0x76fc))(uVar5);
          (**(code **)(local_2050 + -0x7dd0))(uVar5,auStack_202c,0x2000);
          (**(code **)(local_2050 + -0x7fa8))(param_1,"   i:%s\n",auStack_202c);
          if (c_showcerts != 0) {
            uVar5 = (**(code **)(local_2050 + -0x7fbc))(iVar4,iVar10);
            (**(code **)(local_2050 + -0x7ec0))(param_1,uVar5);
          }
          iVar10 = iVar10 + 1;
          iVar7 = (**(code **)(local_2050 + -0x7fb4))(iVar4);
        } while (iVar10 < iVar7);
      }
      bVar2 = true;
    }
    (**(code **)(local_2050 + -0x7fa8))(param_1,&DAT_0063b270);
    iStack_2078 = (**(code **)(local_2050 + -0x762c))(param_2);
    if (iStack_2078 == 0) {
      (**(code **)(local_2050 + -0x7fa8))(param_1,"no peer certificate available\n");
    }
    else {
      (**(code **)(local_2050 + -0x7fa8))(param_1,"Server certificate\n");
      if ((c_showcerts == 0) || (pcVar17 = *(code **)(local_2050 + -0x7ee0), !bVar2)) {
        (**(code **)(local_2050 + -0x7ec0))(param_1,iStack_2078);
        pcVar17 = *(code **)(local_2050 + -0x7ee0);
      }
      uVar5 = (*pcVar17)(iStack_2078);
      (**(code **)(local_2050 + -0x7dd0))(uVar5,auStack_202c,0x2000);
      (**(code **)(local_2050 + -0x7fa8))(param_1,"subject=%s\n",auStack_202c);
      uVar5 = (**(code **)(local_2050 + -0x76fc))(iStack_2078);
      (**(code **)(local_2050 + -0x7dd0))(uVar5,auStack_202c,0x2000);
      (**(code **)(local_2050 + -0x7fa8))(param_1,"issuer=%s\n",auStack_202c);
    }
    iVar4 = (**(code **)(local_2050 + -0x7464))(param_2);
    if ((iVar4 == 0) || (iVar7 = (**(code **)(local_2050 + -0x7fb4))(iVar4), iVar7 < 1)) {
      (**(code **)(local_2050 + -0x7fa8))(param_1,"---\nNo client certificate CA names sent\n");
    }
    else {
      (**(code **)(local_2050 + -0x7fa8))(param_1,"---\nAcceptable client certificate CA names\n");
      for (iVar7 = 0; iVar10 = (**(code **)(local_2050 + -0x7fb4))(iVar4), iVar7 < iVar10;
          iVar7 = iVar7 + 1) {
        uVar5 = (**(code **)(local_2050 + -0x7fbc))(iVar4,iVar7);
        (**(code **)(local_2050 + -0x7dd0))(uVar5,auStack_202c,0x2000);
        uVar5 = (**(code **)(local_2050 + -0x53bc))(auStack_202c);
        (**(code **)(local_2050 + -0x7fcc))(param_1,auStack_202c,uVar5);
        (**(code **)(local_2050 + -0x7fcc))(param_1,"\n",1);
      }
    }
    pcVar14 = (char *)(**(code **)(local_2050 + -0x7628))(param_2,auStack_202c,0x2000);
    if (pcVar14 != (char *)0x0) {
      (**(code **)(local_2050 + -0x7fa8))
                (param_1,"---\nCiphers common between both SSL endpoints:\n");
      cVar13 = *pcVar14;
      if (cVar13 == '\0') {
        local_2040 = "-check_ss_sig";
      }
      else {
        iVar4 = 0;
        local_2040 = "-check_ss_sig";
        iVar7 = 0;
        local_203c = "-check_ss_sig";
        local_2044 = 0x51eb851f;
        do {
          while (cVar13 != ':') {
            (**(code **)(local_2050 + -0x7fcc))(param_1,pcVar14,1);
            iVar7 = iVar7 + 1;
            cVar13 = pcVar14[1];
            pcVar14 = pcVar14 + 1;
            if (cVar13 == '\0') goto LAB_0044a1a8;
          }
          iVar4 = iVar4 + 1;
          (**(code **)(local_2050 + -0x7fcc))
                    (param_1,&DAT_0063d1ec,
                     (((int)((longlong)iVar7 * (longlong)local_2044 >> 0x23) - (iVar7 >> 0x1f)) *
                      0x19 - iVar7) + 0xf);
          if (iVar4 == (iVar4 / 3) * 3) {
            pcVar15 = local_2040 + -0x4d1c;
          }
          else {
            pcVar15 = local_203c + -0x147c;
          }
          (**(code **)(local_2050 + -0x7fcc))(param_1,pcVar15,1);
          iVar7 = 0;
          cVar13 = pcVar14[1];
          pcVar14 = pcVar14 + 1;
        } while (cVar13 != '\0');
      }
LAB_0044a1a8:
      (**(code **)(local_2050 + -0x7fcc))(param_1,local_2040 + -0x4d1c,1);
    }
    uVar5 = (**(code **)(local_2050 + -0x75a8))(param_2);
    uVar5 = (**(code **)(local_2050 + -0x7878))(uVar5);
    uVar6 = (**(code **)(local_2050 + -0x75c4))(param_2);
    uVar6 = (**(code **)(local_2050 + -0x7874))(uVar6);
    (**(code **)(local_2050 + -0x7fa8))
              (param_1,"---\nSSL handshake has read %ld bytes and written %ld bytes\n",uVar5,uVar6);
    iVar4 = (**(code **)(local_2050 + -0x7614))(param_2);
    if (iVar4 == 0) {
      pcVar14 = "---\nNew, ";
    }
    else {
      pcVar14 = "---\nReused, ";
    }
    (**(code **)(local_2050 + -0x7fa8))(param_1,pcVar14);
    uVar5 = (**(code **)(local_2050 + -0x7624))(param_2);
    uVar6 = (**(code **)(local_2050 + -0x757c))(uVar5);
    uVar5 = (**(code **)(local_2050 + -0x7620))(uVar5);
    (**(code **)(local_2050 + -0x7fa8))(param_1,"%s, Cipher is %s\n",uVar6,uVar5);
    if (iStack_2078 != 0) {
      uVar5 = (**(code **)(local_2050 + -0x7ed8))(iStack_2078);
      uVar6 = (**(code **)(local_2050 + -0x7dfc))(uVar5);
      (**(code **)(local_2050 + -0x7fa8))(param_1,"Server public key is %d bit\n",uVar6);
      (**(code **)(local_2050 + -0x7f68))(uVar5);
    }
  }
  iVar4 = (**(code **)(local_2050 + -0x7658))(param_2,0x4c,0,0);
  if (iVar4 == 0) {
    pcVar14 = " NOT";
  }
  else {
    pcVar14 = "";
  }
  (**(code **)(local_2050 + -0x7fa8))(param_1,"Secure Renegotiation IS%s supported\n",pcVar14);
  iVar4 = (**(code **)(local_2050 + -0x7474))(param_2);
  iVar7 = (**(code **)(local_2050 + -0x7470))(param_2);
  if (iVar4 == 0) {
    puVar8 = &DAT_006372d8;
  }
  else {
    puVar8 = (undefined *)(**(code **)(local_2050 + -0x746c))(iVar4);
  }
  (**(code **)(local_2050 + -0x7fa8))(param_1,"Compression: %s\n",puVar8);
  if (iVar7 == 0) {
    puVar8 = &DAT_006372d8;
  }
  else {
    puVar8 = (undefined *)(**(code **)(local_2050 + -0x746c))(iVar7);
  }
  (**(code **)(local_2050 + -0x7fa8))(param_1,"Expansion: %s\n",puVar8);
  if (next_proto._8_4_ != -1) {
    (**(code **)(local_2050 + -0x761c))(param_2,&local_2034,&local_2030);
    (**(code **)(local_2050 + -0x7fa8))(param_1,"Next protocol: (%d) ",next_proto._8_4_);
    (**(code **)(local_2050 + -0x7fcc))(param_1,local_2034,local_2030);
    (**(code **)(local_2050 + -0x7fcc))(param_1,"\n",1);
  }
  puVar9 = (undefined4 *)(**(code **)(local_2050 + -0x7618))(param_2);
  if (puVar9 != (undefined4 *)0x0) {
    (**(code **)(local_2050 + -0x7fa8))(param_1,"SRTP Extension negotiated, profile=%s\n",*puVar9);
  }
  uVar5 = (**(code **)(local_2050 + -0x7634))(param_2);
  (**(code **)(local_2050 + -0x7570))(param_1,uVar5);
  if (keymatexportlabel != 0) {
    (**(code **)(local_2050 + -0x7fa8))(param_1,"Keying material exporter:\n");
    (**(code **)(local_2050 + -0x7fa8))(param_1,"    Label: \'%s\'\n",keymatexportlabel);
    (**(code **)(local_2050 + -0x7fa8))(param_1,"    Length: %i bytes\n",keymatexportlen);
    puVar8 = (undefined *)(**(code **)(local_2050 + -0x7dd8))(keymatexportlen,"s_client.c",0x813);
    iVar4 = keymatexportlabel;
    if (puVar8 != (undefined *)0x0) {
      local_2060 = (**(code **)(local_2050 + -0x53bc))(keymatexportlabel);
      local_2054 = 0;
      local_2058 = 0;
      local_205c = 0;
      local_2044 = keymatexportlen;
      iVar4 = (**(code **)(local_2050 + -0x7610))(param_2,puVar8,keymatexportlen,iVar4);
      if (iVar4 == 0) {
        (**(code **)(local_2050 + -0x7fa8))(param_1,"    Error\n");
      }
      else {
        (**(code **)(local_2050 + -0x7fa8))(param_1,"    Keying material: ");
        if (0 < keymatexportlen) {
          iVar4 = 0;
          param_2 = &DAT_00634b80;
          puVar16 = puVar8;
          do {
            uVar1 = *puVar16;
            iVar4 = iVar4 + 1;
            puVar16 = puVar16 + 1;
            (**(code **)(local_2050 + -0x7fa8))(param_1,&DAT_00634b80,uVar1);
          } while (iVar4 < keymatexportlen);
        }
        (**(code **)(local_2050 + -0x7fa8))(param_1,"\n");
      }
      (**(code **)(local_2050 + -0x7f58))(puVar8);
    }
  }
  (**(code **)(local_2050 + -0x7fa8))(param_1,&DAT_0063b270);
  if (iStack_2078 != 0) {
    (**(code **)(local_2050 + -0x7f50))(iStack_2078);
  }
  puVar9 = (undefined4 *)&DAT_0000000b;
  (**(code **)(local_2050 + -0x7fc8))(param_1,0xb,0,0);
  if (local_2c != *(int *)puVar3) {
    pcStack_2074 = ssl_give_srp_client_pwd_cb;
    (**(code **)(local_2050 + -0x5330))();
    puVar3 = PTR___stack_chk_guard_006a9ae8;
    iVar7 = 0x224;
    iStack_2084 = *(int *)PTR___stack_chk_guard_006a9ae8;
    uStack_2080 = param_1;
    puStack_207c = param_2;
    iVar4 = (*(code *)PTR_CRYPTO_malloc_006a7008)(0x401,"s_client.c");
    if (iVar4 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,"Malloc failure\n");
      iVar4 = 0;
    }
    else {
      uStack_208c = *puVar9;
      iVar7 = 0;
      pcStack_2088 = "SRP user";
      iVar10 = password_callback(iVar4,0x400,0,&uStack_208c);
      if (iVar10 < 0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)PTR_bio_err_006a6e3c,"Can\'t read Password\n");
        (*(code *)PTR_CRYPTO_free_006a6e88)(iVar4);
        iVar4 = 0;
      }
      else {
        *(undefined *)(iVar4 + iVar10) = 0;
      }
    }
    if (iStack_2084 != *(int *)puVar3) {
      iVar4 = iStack_2084;
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
      iVar10 = (*(code *)PTR_SSL_get_servername_006a7884)();
      iVar11 = (*(code *)PTR_SSL_get_servername_type_006a7980)(iVar4);
      if (iVar11 == -1) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)PTR_bio_err_006a6e3c,"Can\'t use SSL_get_servername\n");
        return 0;
      }
      iVar4 = (*(code *)PTR_SSL_ctrl_006a7788)(iVar4,8,0,0);
      uVar12 = 0;
      if (iVar4 == 0) {
        uVar12 = (uint)(iVar10 != 0);
      }
      *(uint *)(iVar7 + 4) = uVar12;
      return 0;
    }
    return iVar4;
  }
  return *(int *)puVar3;
}

