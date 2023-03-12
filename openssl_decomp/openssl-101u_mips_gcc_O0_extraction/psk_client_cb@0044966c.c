
char * psk_client_cb(undefined4 param_1,int param_2,char *param_3,char *param_4,char *param_5,
                    char *param_6)

{
  undefined uVar1;
  bool bVar2;
  undefined *puVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined *puVar9;
  undefined4 *puVar10;
  char cVar14;
  int iVar11;
  int iVar12;
  uint uVar13;
  char *pcVar15;
  int unaff_s5;
  undefined *puVar16;
  code *pcVar17;
  undefined4 uStack_20cc;
  char *pcStack_20c8;
  int iStack_20c4;
  int iStack_20c0;
  char *pcStack_20bc;
  int iStack_20b8;
  code *pcStack_20b4;
  undefined4 uStack_20a0;
  undefined4 uStack_209c;
  undefined4 uStack_2098;
  undefined4 uStack_2094;
  undefined *puStack_2090;
  int iStack_2084;
  char *pcStack_2080;
  char *pcStack_207c;
  undefined4 uStack_2074;
  undefined4 uStack_2070;
  undefined auStack_206c [8192];
  char *pcStack_6c;
  char *pcStack_68;
  undefined *puStack_64;
  undefined *puStack_60;
  char *pcStack_5c;
  char *pcStack_58;
  int iStack_54;
  undefined *puStack_50;
  int local_28;
  int local_24;
  
  puStack_60 = PTR___stack_chk_guard_006a9ae8;
  local_28 = 0;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_54 = unaff_s5;
  if (c_debug != 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(bio_c_out,"psk_client_cb\n");
    iStack_54 = param_2;
    if (param_2 == 0) {
      if (c_debug != 0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (bio_c_out,"NULL received PSK identity hint, continuing anyway\n");
      }
    }
    else if (c_debug != 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(bio_c_out,"Received PSK identity hint \'%s\'\n",param_2);
    }
  }
  pcVar15 = "%s";
  pcStack_20bc = param_4;
  pcVar4 = (char *)(*(code *)PTR_BIO_snprintf_006a6f60)(param_3,param_4,"%s",psk_identity);
  pcStack_68 = param_4;
  if (((int)pcVar4 < 0) ||
     (pcStack_68 = (char *)(uint)(param_4 < pcVar4), (char *)(uint)(param_4 < pcVar4) != (char *)0x0
     )) {
LAB_00449790:
    if (c_debug != 0) {
      pcStack_20bc = "Error in PSK client callback\n";
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c);
      pcVar4 = (char *)0x0;
      goto LAB_004497a0;
    }
  }
  else {
    if (c_debug != 0) {
      pcVar15 = param_3;
      (*(code *)PTR_BIO_printf_006a6e38)
                (bio_c_out,"created identity \'%s\' len=%d\n",param_3,pcVar4);
    }
    pcStack_68 = PTR_psk_key_006a7968;
    iVar5 = (*(code *)PTR_BN_hex2bn_006a70f0)(&local_28,*(undefined4 *)PTR_psk_key_006a7968);
    if (iVar5 != 0) {
      iVar6 = (*(code *)PTR_BN_num_bits_006a71f4)(local_28);
      iVar5 = iVar6 + 7;
      if (iVar6 + 7 < 0) {
        iVar5 = iVar6 + 0xe;
      }
      if (param_6 < (char *)(iVar5 >> 3)) {
        pcStack_68 = *(char **)PTR_bio_err_006a6e3c;
        iVar6 = (*(code *)PTR_BN_num_bits_006a71f4)(local_28);
        iVar5 = iVar6 + 7;
        if (iVar6 + 7 < 0) {
          iVar5 = iVar6 + 0xe;
        }
        pcStack_20bc = "psk buffer of callback is too small (%d) for key (%d)\n";
        (*(code *)PTR_BIO_printf_006a6e38)
                  (pcStack_68,"psk buffer of callback is too small (%d) for key (%d)\n",param_6,
                   iVar5 >> 3);
        (*(code *)PTR_BN_free_006a701c)(local_28);
        pcVar4 = (char *)0x0;
        pcVar15 = param_6;
        goto LAB_004497a0;
      }
      pcStack_20bc = param_5;
      pcVar4 = (char *)(*(code *)PTR_BN_bn2bin_006a7200)();
      (*(code *)PTR_BN_free_006a701c)(local_28);
      pcStack_68 = pcVar4;
      if (pcVar4 != (char *)0x0) {
        if (c_debug != 0) {
          pcStack_20bc = "created PSK len=%d\n";
          pcVar15 = pcVar4;
          (*(code *)PTR_BIO_printf_006a6e38)(bio_c_out);
        }
        goto LAB_004497a0;
      }
      goto LAB_00449790;
    }
    pcVar15 = *(char **)pcStack_68;
    pcStack_20bc = "Could not convert PSK key \'%s\' to BIGNUM\n";
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c);
    if (local_28 != 0) {
      (*(code *)PTR_BN_free_006a701c)();
    }
  }
  pcVar4 = (char *)0x0;
LAB_004497a0:
  if (local_24 == *(int *)puStack_60) {
    return pcVar4;
  }
  iStack_20c0 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  pcStack_58 = param_5;
  puStack_64 = &_gp_1;
  puStack_50 = &_gp_1;
  puStack_2090 = &_gp;
  pcStack_6c = *(char **)PTR___stack_chk_guard_006a9ae8;
  pcStack_5c = param_3;
  if (pcVar15 == (char *)0x0) {
    iVar5 = (*(code *)PTR_SSL_cache_hit_006a77cc)(pcStack_20bc);
    if (iVar5 == 0) {
      pcVar15 = "---\nNew, ";
    }
    else {
      pcVar15 = "---\nReused, ";
    }
    (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,pcVar15);
    uVar7 = (**(code **)(puStack_2090 + -0x7624))(pcStack_20bc);
    uVar8 = (**(code **)(puStack_2090 + -0x757c))(uVar7);
    uVar7 = (**(code **)(puStack_2090 + -0x7620))(uVar7);
    iStack_20b8 = 0;
    (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,"%s, Cipher is %s\n",uVar8,uVar7);
  }
  else {
    iVar5 = (*(code *)PTR_SSL_get_peer_cert_chain_006a7978)(pcStack_20bc);
    if (iVar5 == 0) {
      bVar2 = false;
    }
    else {
      iVar11 = 0;
      (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,"---\nCertificate chain\n");
      iVar6 = (**(code **)(puStack_2090 + -0x7fb4))(iVar5);
      if (0 < iVar6) {
        do {
          uVar7 = (**(code **)(puStack_2090 + -0x7fbc))(iVar5,iVar11);
          uVar7 = (**(code **)(puStack_2090 + -0x7ee0))(uVar7);
          (**(code **)(puStack_2090 + -0x7dd0))(uVar7,auStack_206c,0x2000);
          (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,"%2d s:%s\n",iVar11,auStack_206c);
          uVar7 = (**(code **)(puStack_2090 + -0x7fbc))(iVar5,iVar11);
          uVar7 = (**(code **)(puStack_2090 + -0x76fc))(uVar7);
          (**(code **)(puStack_2090 + -0x7dd0))(uVar7,auStack_206c,0x2000);
          (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,"   i:%s\n",auStack_206c);
          if (c_showcerts != 0) {
            uVar7 = (**(code **)(puStack_2090 + -0x7fbc))(iVar5,iVar11);
            (**(code **)(puStack_2090 + -0x7ec0))(iStack_20c0,uVar7);
          }
          iVar11 = iVar11 + 1;
          iVar6 = (**(code **)(puStack_2090 + -0x7fb4))(iVar5);
        } while (iVar11 < iVar6);
      }
      bVar2 = true;
    }
    (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,&DAT_0063b270);
    iStack_20b8 = (**(code **)(puStack_2090 + -0x762c))(pcStack_20bc);
    if (iStack_20b8 == 0) {
      (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,"no peer certificate available\n");
    }
    else {
      (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,"Server certificate\n");
      if ((c_showcerts == 0) || (pcVar17 = *(code **)(puStack_2090 + -0x7ee0), !bVar2)) {
        (**(code **)(puStack_2090 + -0x7ec0))(iStack_20c0,iStack_20b8);
        pcVar17 = *(code **)(puStack_2090 + -0x7ee0);
      }
      uVar7 = (*pcVar17)(iStack_20b8);
      (**(code **)(puStack_2090 + -0x7dd0))(uVar7,auStack_206c,0x2000);
      (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,"subject=%s\n",auStack_206c);
      uVar7 = (**(code **)(puStack_2090 + -0x76fc))(iStack_20b8);
      (**(code **)(puStack_2090 + -0x7dd0))(uVar7,auStack_206c,0x2000);
      (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,"issuer=%s\n",auStack_206c);
    }
    iVar5 = (**(code **)(puStack_2090 + -0x7464))(pcStack_20bc);
    if ((iVar5 == 0) || (iVar6 = (**(code **)(puStack_2090 + -0x7fb4))(iVar5), iVar6 < 1)) {
      (**(code **)(puStack_2090 + -0x7fa8))
                (iStack_20c0,"---\nNo client certificate CA names sent\n");
    }
    else {
      (**(code **)(puStack_2090 + -0x7fa8))
                (iStack_20c0,"---\nAcceptable client certificate CA names\n");
      for (iVar6 = 0; iVar11 = (**(code **)(puStack_2090 + -0x7fb4))(iVar5), iVar6 < iVar11;
          iVar6 = iVar6 + 1) {
        uVar7 = (**(code **)(puStack_2090 + -0x7fbc))(iVar5,iVar6);
        (**(code **)(puStack_2090 + -0x7dd0))(uVar7,auStack_206c,0x2000);
        uVar7 = (**(code **)(puStack_2090 + -0x53bc))(auStack_206c);
        (**(code **)(puStack_2090 + -0x7fcc))(iStack_20c0,auStack_206c,uVar7);
        (**(code **)(puStack_2090 + -0x7fcc))(iStack_20c0,"\n",1);
      }
    }
    pcVar15 = (char *)(**(code **)(puStack_2090 + -0x7628))(pcStack_20bc,auStack_206c,0x2000);
    if (pcVar15 != (char *)0x0) {
      (**(code **)(puStack_2090 + -0x7fa8))
                (iStack_20c0,"---\nCiphers common between both SSL endpoints:\n");
      cVar14 = *pcVar15;
      if (cVar14 == '\0') {
        pcStack_2080 = "-check_ss_sig";
      }
      else {
        iVar5 = 0;
        pcStack_2080 = "-check_ss_sig";
        iVar6 = 0;
        pcStack_207c = "-check_ss_sig";
        iStack_2084 = 0x51eb851f;
        do {
          while (cVar14 != ':') {
            (**(code **)(puStack_2090 + -0x7fcc))(iStack_20c0,pcVar15,1);
            iVar6 = iVar6 + 1;
            cVar14 = pcVar15[1];
            pcVar15 = pcVar15 + 1;
            if (cVar14 == '\0') goto LAB_0044a1a8;
          }
          iVar5 = iVar5 + 1;
          (**(code **)(puStack_2090 + -0x7fcc))
                    (iStack_20c0,&DAT_0063d1ec,
                     (((int)((longlong)iVar6 * (longlong)iStack_2084 >> 0x23) - (iVar6 >> 0x1f)) *
                      0x19 - iVar6) + 0xf);
          if (iVar5 == (iVar5 / 3) * 3) {
            pcVar4 = pcStack_2080 + -0x4d1c;
          }
          else {
            pcVar4 = pcStack_207c + -0x147c;
          }
          (**(code **)(puStack_2090 + -0x7fcc))(iStack_20c0,pcVar4,1);
          iVar6 = 0;
          cVar14 = pcVar15[1];
          pcVar15 = pcVar15 + 1;
        } while (cVar14 != '\0');
      }
LAB_0044a1a8:
      (**(code **)(puStack_2090 + -0x7fcc))(iStack_20c0,pcStack_2080 + -0x4d1c,1);
    }
    uVar7 = (**(code **)(puStack_2090 + -0x75a8))(pcStack_20bc);
    uVar7 = (**(code **)(puStack_2090 + -0x7878))(uVar7);
    uVar8 = (**(code **)(puStack_2090 + -0x75c4))(pcStack_20bc);
    uVar8 = (**(code **)(puStack_2090 + -0x7874))(uVar8);
    (**(code **)(puStack_2090 + -0x7fa8))
              (iStack_20c0,"---\nSSL handshake has read %ld bytes and written %ld bytes\n",uVar7,
               uVar8);
    iVar5 = (**(code **)(puStack_2090 + -0x7614))(pcStack_20bc);
    if (iVar5 == 0) {
      pcVar15 = "---\nNew, ";
    }
    else {
      pcVar15 = "---\nReused, ";
    }
    (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,pcVar15);
    uVar7 = (**(code **)(puStack_2090 + -0x7624))(pcStack_20bc);
    uVar8 = (**(code **)(puStack_2090 + -0x757c))(uVar7);
    uVar7 = (**(code **)(puStack_2090 + -0x7620))(uVar7);
    (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,"%s, Cipher is %s\n",uVar8,uVar7);
    if (iStack_20b8 != 0) {
      uVar7 = (**(code **)(puStack_2090 + -0x7ed8))(iStack_20b8);
      uVar8 = (**(code **)(puStack_2090 + -0x7dfc))(uVar7);
      (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,"Server public key is %d bit\n",uVar8);
      (**(code **)(puStack_2090 + -0x7f68))(uVar7);
    }
  }
  iVar5 = (**(code **)(puStack_2090 + -0x7658))(pcStack_20bc,0x4c,0,0);
  if (iVar5 == 0) {
    pcVar15 = " NOT";
  }
  else {
    pcVar15 = "";
  }
  (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,"Secure Renegotiation IS%s supported\n",pcVar15)
  ;
  iVar5 = (**(code **)(puStack_2090 + -0x7474))(pcStack_20bc);
  iVar6 = (**(code **)(puStack_2090 + -0x7470))(pcStack_20bc);
  if (iVar5 == 0) {
    puVar9 = &DAT_006372d8;
  }
  else {
    puVar9 = (undefined *)(**(code **)(puStack_2090 + -0x746c))(iVar5);
  }
  (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,"Compression: %s\n",puVar9);
  if (iVar6 == 0) {
    puVar9 = &DAT_006372d8;
  }
  else {
    puVar9 = (undefined *)(**(code **)(puStack_2090 + -0x746c))(iVar6);
  }
  (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,"Expansion: %s\n",puVar9);
  if (next_proto._8_4_ != -1) {
    (**(code **)(puStack_2090 + -0x761c))(pcStack_20bc,&uStack_2074,&uStack_2070);
    (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,"Next protocol: (%d) ",next_proto._8_4_);
    (**(code **)(puStack_2090 + -0x7fcc))(iStack_20c0,uStack_2074,uStack_2070);
    (**(code **)(puStack_2090 + -0x7fcc))(iStack_20c0,"\n",1);
  }
  puVar10 = (undefined4 *)(**(code **)(puStack_2090 + -0x7618))(pcStack_20bc);
  if (puVar10 != (undefined4 *)0x0) {
    (**(code **)(puStack_2090 + -0x7fa8))
              (iStack_20c0,"SRTP Extension negotiated, profile=%s\n",*puVar10);
  }
  uVar7 = (**(code **)(puStack_2090 + -0x7634))(pcStack_20bc);
  (**(code **)(puStack_2090 + -0x7570))(iStack_20c0,uVar7);
  if (keymatexportlabel != 0) {
    (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,"Keying material exporter:\n");
    (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,"    Label: \'%s\'\n",keymatexportlabel);
    (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,"    Length: %i bytes\n",keymatexportlen);
    puVar9 = (undefined *)(**(code **)(puStack_2090 + -0x7dd8))(keymatexportlen,"s_client.c",0x813);
    iVar5 = keymatexportlabel;
    if (puVar9 != (undefined *)0x0) {
      uStack_20a0 = (**(code **)(puStack_2090 + -0x53bc))(keymatexportlabel);
      uStack_2094 = 0;
      uStack_2098 = 0;
      uStack_209c = 0;
      iStack_2084 = keymatexportlen;
      iVar5 = (**(code **)(puStack_2090 + -0x7610))(pcStack_20bc,puVar9,keymatexportlen,iVar5);
      if (iVar5 == 0) {
        (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,"    Error\n");
      }
      else {
        (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,"    Keying material: ");
        if (0 < keymatexportlen) {
          iVar5 = 0;
          pcStack_20bc = "%02X";
          puVar16 = puVar9;
          do {
            uVar1 = *puVar16;
            iVar5 = iVar5 + 1;
            puVar16 = puVar16 + 1;
            (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,&DAT_00634b80,uVar1);
          } while (iVar5 < keymatexportlen);
        }
        (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,"\n");
      }
      (**(code **)(puStack_2090 + -0x7f58))(puVar9);
    }
  }
  (**(code **)(puStack_2090 + -0x7fa8))(iStack_20c0,&DAT_0063b270);
  if (iStack_20b8 != 0) {
    (**(code **)(puStack_2090 + -0x7f50))(iStack_20b8);
  }
  puVar10 = (undefined4 *)&DAT_0000000b;
  (**(code **)(puStack_2090 + -0x7fc8))(iStack_20c0,0xb,0,0);
  if (pcStack_6c != *(char **)puVar3) {
    pcStack_20b4 = ssl_give_srp_client_pwd_cb;
    (**(code **)(puStack_2090 + -0x5330))();
    puVar3 = PTR___stack_chk_guard_006a9ae8;
    iVar5 = 0x224;
    iStack_20c4 = *(int *)PTR___stack_chk_guard_006a9ae8;
    pcVar15 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x401,"s_client.c");
    if (pcVar15 == (char *)0x0) {
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,"Malloc failure\n");
      pcVar15 = (char *)0x0;
    }
    else {
      uStack_20cc = *puVar10;
      iVar5 = 0;
      pcStack_20c8 = "SRP user";
      iVar6 = password_callback(pcVar15,0x400,0,&uStack_20cc);
      if (iVar6 < 0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)PTR_bio_err_006a6e3c,"Can\'t read Password\n");
        (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar15);
        pcVar15 = (char *)0x0;
      }
      else {
        pcVar15[iVar6] = '\0';
      }
    }
    if (iStack_20c4 != *(int *)puVar3) {
      iVar6 = iStack_20c4;
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
      iVar11 = (*(code *)PTR_SSL_get_servername_006a7884)();
      iVar12 = (*(code *)PTR_SSL_get_servername_type_006a7980)(iVar6);
      if (iVar12 == -1) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)PTR_bio_err_006a6e3c,"Can\'t use SSL_get_servername\n");
        return (char *)0x0;
      }
      iVar6 = (*(code *)PTR_SSL_ctrl_006a7788)(iVar6,8,0,0);
      uVar13 = 0;
      if (iVar6 == 0) {
        uVar13 = (uint)(iVar11 != 0);
      }
      *(uint *)(iVar5 + 4) = uVar13;
      return (char *)0x0;
    }
    return pcVar15;
  }
  return *(char **)puVar3;
}

