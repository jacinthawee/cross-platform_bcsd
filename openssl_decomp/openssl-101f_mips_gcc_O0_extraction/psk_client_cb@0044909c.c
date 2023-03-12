
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
  int iVar9;
  int iVar10;
  undefined *puVar11;
  undefined4 *puVar12;
  int iVar13;
  char cVar15;
  uint uVar14;
  char *pcVar16;
  char *pcVar17;
  int unaff_s5;
  undefined *puVar18;
  undefined4 uStack_2074;
  undefined4 uStack_2070;
  undefined auStack_206c [8192];
  char *pcStack_6c;
  char *pcStack_68;
  undefined1 *puStack_64;
  undefined *puStack_60;
  char *pcStack_5c;
  char *pcStack_58;
  int iStack_54;
  undefined1 *puStack_50;
  int local_28;
  int local_24;
  
  puStack_60 = PTR___stack_chk_guard_006aabf0;
  local_28 = 0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_54 = unaff_s5;
  if (c_debug != 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(bio_c_out,"psk_client_cb\n");
    iStack_54 = param_2;
    if (param_2 == 0) {
      if (c_debug != 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (bio_c_out,"NULL received PSK identity hint, continuing anyway\n");
      }
    }
    else if (c_debug != 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(bio_c_out,"Received PSK identity hint \'%s\'\n",param_2);
    }
  }
  pcVar17 = "%s";
  pcVar16 = param_4;
  pcVar4 = (char *)(*(code *)PTR_BIO_snprintf_006a8060)(param_3,param_4,"%s",psk_identity);
  pcStack_68 = param_4;
  if (((int)pcVar4 < 0) ||
     (pcStack_68 = (char *)(uint)(param_4 < pcVar4), (char *)(uint)(param_4 < pcVar4) != (char *)0x0
     )) {
LAB_004491c0:
    if (c_debug != 0) {
      pcVar16 = "Error in PSK client callback\n";
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
      pcVar4 = (char *)0x0;
      goto LAB_004491d0;
    }
  }
  else {
    if (c_debug != 0) {
      pcVar17 = param_3;
      (*(code *)PTR_BIO_printf_006a7f38)
                (bio_c_out,"created identity \'%s\' len=%d\n",param_3,pcVar4);
    }
    pcStack_68 = PTR_psk_key_006a8a54;
    iVar5 = (*(code *)PTR_BN_hex2bn_006a81f0)(&local_28,*(undefined4 *)PTR_psk_key_006a8a54);
    if (iVar5 != 0) {
      iVar6 = (*(code *)PTR_BN_num_bits_006a82f4)(local_28);
      iVar5 = iVar6 + 7;
      if (iVar6 + 7 < 0) {
        iVar5 = iVar6 + 0xe;
      }
      if (param_6 < (char *)(iVar5 >> 3)) {
        pcStack_68 = *(char **)PTR_bio_err_006a7f3c;
        iVar6 = (*(code *)PTR_BN_num_bits_006a82f4)(local_28);
        iVar5 = iVar6 + 7;
        if (iVar6 + 7 < 0) {
          iVar5 = iVar6 + 0xe;
        }
        pcVar16 = "psk buffer of callback is too small (%d) for key (%d)\n";
        (*(code *)PTR_BIO_printf_006a7f38)
                  (pcStack_68,"psk buffer of callback is too small (%d) for key (%d)\n",param_6,
                   iVar5 >> 3);
        (*(code *)PTR_BN_free_006a811c)(local_28);
        pcVar4 = (char *)0x0;
        pcVar17 = param_6;
        goto LAB_004491d0;
      }
      pcVar16 = param_5;
      pcVar4 = (char *)(*(code *)PTR_BN_bn2bin_006a8300)();
      (*(code *)PTR_BN_free_006a811c)(local_28);
      pcStack_68 = pcVar4;
      if (pcVar4 != (char *)0x0) {
        if (c_debug != 0) {
          pcVar16 = "created PSK len=%d\n";
          pcVar17 = pcVar4;
          (*(code *)PTR_BIO_printf_006a7f38)(bio_c_out);
        }
        goto LAB_004491d0;
      }
      goto LAB_004491c0;
    }
    pcVar17 = *(char **)pcStack_68;
    pcVar16 = "Could not convert PSK key \'%s\' to BIGNUM\n";
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c);
    if (local_28 != 0) {
      (*(code *)PTR_BN_free_006a811c)();
    }
  }
  pcVar4 = (char *)0x0;
LAB_004491d0:
  if (local_24 == *(int *)puStack_60) {
    return pcVar4;
  }
  iVar5 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  pcStack_58 = param_5;
  puStack_64 = &_ITM_registerTMCloneTable;
  puStack_50 = &_ITM_registerTMCloneTable;
  pcStack_6c = *(char **)PTR___stack_chk_guard_006aabf0;
  pcStack_5c = param_3;
  if (pcVar17 == (char *)0x0) {
    iVar6 = (*(code *)PTR_SSL_cache_hit_006a88b8)(pcVar16);
    if (iVar6 == 0) {
      pcVar17 = "---\nNew, ";
    }
    else {
      pcVar17 = "---\nReused, ";
    }
    (*(code *)PTR_BIO_printf_006a7f38)(iVar5,pcVar17);
    uVar7 = (*(code *)PTR_SSL_get_current_cipher_006a88a8)(pcVar16);
    uVar8 = (*(code *)PTR_SSL_CIPHER_get_version_006a8950)(uVar7);
    uVar7 = (*(code *)PTR_SSL_CIPHER_get_name_006a88ac)(uVar7);
    iVar6 = 0;
    (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"%s, Cipher is %s\n",uVar8,uVar7);
  }
  else {
    iVar6 = (*(code *)PTR_SSL_get_peer_cert_chain_006a8a64)(pcVar16);
    if (iVar6 == 0) {
      bVar2 = false;
    }
    else {
      iVar10 = 0;
      (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"---\nCertificate chain\n");
      iVar9 = (*(code *)PTR_sk_num_006a7f2c)(iVar6);
      if (0 < iVar9) {
        do {
          uVar7 = (*(code *)PTR_sk_value_006a7f24)(iVar6,iVar10);
          uVar7 = (*(code *)PTR_X509_get_subject_name_006a8000)(uVar7);
          (*(code *)PTR_X509_NAME_oneline_006a8110)(uVar7,auStack_206c,0x2000);
          (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"%2d s:%s\n",iVar10,auStack_206c);
          uVar7 = (*(code *)PTR_sk_value_006a7f24)(iVar6,iVar10);
          uVar7 = (*(code *)PTR_X509_get_issuer_name_006a87d0)(uVar7);
          (*(code *)PTR_X509_NAME_oneline_006a8110)(uVar7,auStack_206c,0x2000);
          (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"   i:%s\n",auStack_206c);
          if (c_showcerts != 0) {
            uVar7 = (*(code *)PTR_sk_value_006a7f24)(iVar6,iVar10);
            (*(code *)PTR_PEM_write_bio_X509_006a8020)(iVar5,uVar7);
          }
          iVar10 = iVar10 + 1;
          iVar9 = (*(code *)PTR_sk_num_006a7f2c)(iVar6);
        } while (iVar10 < iVar9);
      }
      bVar2 = true;
    }
    (*(code *)PTR_BIO_printf_006a7f38)(iVar5,&DAT_0063ba54);
    iVar6 = (*(code *)PTR_SSL_get_peer_certificate_006a88a0)(pcVar16);
    if (iVar6 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"no peer certificate available\n");
    }
    else {
      (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"Server certificate\n");
      if ((c_showcerts == 0) || (!bVar2)) {
        (*(code *)PTR_PEM_write_bio_X509_006a8020)(iVar5,iVar6);
      }
      uVar7 = (*(code *)PTR_X509_get_subject_name_006a8000)(iVar6);
      (*(code *)PTR_X509_NAME_oneline_006a8110)(uVar7,auStack_206c,0x2000);
      (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"subject=%s\n",auStack_206c);
      uVar7 = (*(code *)PTR_X509_get_issuer_name_006a87d0)(iVar6);
      (*(code *)PTR_X509_NAME_oneline_006a8110)(uVar7,auStack_206c,0x2000);
      (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"issuer=%s\n",auStack_206c);
    }
    iVar9 = (*(code *)PTR_SSL_get_client_CA_list_006a8a68)(pcVar16);
    if ((iVar9 == 0) || (iVar10 = (*(code *)PTR_sk_num_006a7f2c)(iVar9), iVar10 < 1)) {
      (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"---\nNo client certificate CA names sent\n");
    }
    else {
      (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"---\nAcceptable client certificate CA names\n");
      for (iVar10 = 0; iVar13 = (*(code *)PTR_sk_num_006a7f2c)(iVar9), iVar10 < iVar13;
          iVar10 = iVar10 + 1) {
        uVar7 = (*(code *)PTR_sk_value_006a7f24)(iVar9,iVar10);
        (*(code *)PTR_X509_NAME_oneline_006a8110)(uVar7,auStack_206c,0x2000);
        uVar7 = (*(code *)PTR_strlen_006aab30)(auStack_206c);
        (*(code *)PTR_BIO_write_006a7f14)(iVar5,auStack_206c,uVar7);
        (*(code *)PTR_BIO_write_006a7f14)(iVar5,"\n",1);
      }
    }
    pcVar17 = (char *)(*(code *)PTR_SSL_get_shared_ciphers_006a88a4)(pcVar16,auStack_206c,0x2000);
    if (pcVar17 != (char *)0x0) {
      (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"---\nCiphers common between both SSL endpoints:\n");
      cVar15 = *pcVar17;
      if (cVar15 != '\0') {
        iVar9 = 0;
        iVar10 = 0;
        do {
          while (cVar15 != ':') {
            (*(code *)PTR_BIO_write_006a7f14)(iVar5,pcVar17,1);
            iVar10 = iVar10 + 1;
            cVar15 = pcVar17[1];
            pcVar17 = pcVar17 + 1;
            if (cVar15 == '\0') goto LAB_00449bd8;
          }
          iVar9 = iVar9 + 1;
          (*(code *)PTR_BIO_write_006a7f14)
                    (iVar5,&DAT_0063d84c,((iVar10 / 0x19) * 0x19 - iVar10) + 0xf);
          if (iVar9 == (iVar9 / 3) * 3) {
            puVar12 = (undefined4 *)0x63bac8;
          }
          else {
            puVar12 = &DAT_0063f0b8;
          }
          (*(code *)PTR_BIO_write_006a7f14)(iVar5,puVar12,1);
          iVar10 = 0;
          cVar15 = pcVar17[1];
          pcVar17 = pcVar17 + 1;
        } while (cVar15 != '\0');
      }
LAB_00449bd8:
      (*(code *)PTR_BIO_write_006a7f14)(iVar5,"\n",1);
    }
    uVar7 = (*(code *)PTR_SSL_get_rbio_006a8924)(pcVar16);
    uVar7 = (*(code *)PTR_BIO_number_read_006a8654)(uVar7);
    uVar8 = (*(code *)PTR_SSL_get_wbio_006a8908)(pcVar16);
    uVar8 = (*(code *)PTR_BIO_number_written_006a8658)(uVar8);
    (*(code *)PTR_BIO_printf_006a7f38)
              (iVar5,"---\nSSL handshake has read %ld bytes and written %ld bytes\n",uVar7,uVar8);
    iVar9 = (*(code *)PTR_SSL_cache_hit_006a88b8)(pcVar16);
    if (iVar9 == 0) {
      pcVar17 = "---\nNew, ";
    }
    else {
      pcVar17 = "---\nReused, ";
    }
    (*(code *)PTR_BIO_printf_006a7f38)(iVar5,pcVar17);
    uVar7 = (*(code *)PTR_SSL_get_current_cipher_006a88a8)(pcVar16);
    uVar8 = (*(code *)PTR_SSL_CIPHER_get_version_006a8950)(uVar7);
    uVar7 = (*(code *)PTR_SSL_CIPHER_get_name_006a88ac)(uVar7);
    (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"%s, Cipher is %s\n",uVar8,uVar7);
    if (iVar6 != 0) {
      uVar7 = (*(code *)PTR_X509_get_pubkey_006a8008)(iVar6);
      uVar8 = (*(code *)PTR_EVP_PKEY_bits_006a80e4)(uVar7);
      (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"Server public key is %d bit\n",uVar8);
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(uVar7);
    }
  }
  iVar9 = (*(code *)PTR_SSL_ctrl_006a8878)(pcVar16,0x4c,0,0);
  if (iVar9 == 0) {
    pcVar17 = " NOT";
  }
  else {
    pcVar17 = "";
  }
  (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"Secure Renegotiation IS%s supported\n",pcVar17);
  iVar9 = (*(code *)PTR_SSL_get_current_compression_006a8a58)(pcVar16);
  iVar10 = (*(code *)PTR_SSL_get_current_expansion_006a8a5c)(pcVar16);
  if (iVar9 == 0) {
    puVar11 = &DAT_00637b4c;
  }
  else {
    puVar11 = (undefined *)(*(code *)PTR_SSL_COMP_get_name_006a8a60)(iVar9);
  }
  (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"Compression: %s\n",puVar11);
  if (iVar10 == 0) {
    puVar11 = &DAT_00637b4c;
  }
  else {
    puVar11 = (undefined *)(*(code *)PTR_SSL_COMP_get_name_006a8a60)(iVar10);
  }
  (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"Expansion: %s\n",puVar11);
  if (next_proto._8_4_ != -1) {
    (*(code *)PTR_SSL_get0_next_proto_negotiated_006a88b0)(pcVar16,&uStack_2074,&uStack_2070);
    (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"Next protocol: (%d) ",next_proto._8_4_);
    (*(code *)PTR_BIO_write_006a7f14)(iVar5,uStack_2074,uStack_2070);
    (*(code *)PTR_BIO_write_006a7f14)(iVar5,"\n",1);
  }
  puVar12 = (undefined4 *)(*(code *)PTR_SSL_get_selected_srtp_profile_006a88b4)(pcVar16);
  if (puVar12 != (undefined4 *)0x0) {
    (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"SRTP Extension negotiated, profile=%s\n",*puVar12);
  }
  uVar7 = (*(code *)PTR_SSL_get_session_006a8898)(pcVar16);
  (*(code *)PTR_SSL_SESSION_print_006a8958)(iVar5,uVar7);
  if (keymatexportlabel != 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"Keying material exporter:\n");
    (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"    Label: \'%s\'\n",keymatexportlabel);
    (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"    Length: %i bytes\n",keymatexportlen);
    puVar11 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(keymatexportlen,"s_client.c",0x82e)
    ;
    iVar9 = keymatexportlabel;
    if (puVar11 != (undefined *)0x0) {
      uVar7 = (*(code *)PTR_strlen_006aab30)(keymatexportlabel);
      iVar9 = (*(code *)PTR_SSL_export_keying_material_006a88bc)
                        (pcVar16,puVar11,keymatexportlen,iVar9,uVar7,0,0,0);
      if (iVar9 == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"    Error\n");
      }
      else {
        (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"    Keying material: ");
        if (0 < keymatexportlen) {
          iVar9 = 0;
          puVar18 = puVar11;
          do {
            uVar1 = *puVar18;
            iVar9 = iVar9 + 1;
            puVar18 = puVar18 + 1;
            (*(code *)PTR_BIO_printf_006a7f38)(iVar5,&DAT_00635448,uVar1);
          } while (iVar9 < keymatexportlen);
        }
        (*(code *)PTR_BIO_printf_006a7f38)(iVar5,"\n");
      }
      (*(code *)PTR_CRYPTO_free_006a7f88)(puVar11);
    }
  }
  (*(code *)PTR_BIO_printf_006a7f38)(iVar5,&DAT_0063ba54);
  if (iVar6 != 0) {
    (*(code *)PTR_X509_free_006a7f90)(iVar6);
  }
  iVar6 = 0;
  (*(code *)PTR_BIO_ctrl_006a7f18)(iVar5,0xb,0,0);
  if (pcStack_6c != *(char **)puVar3) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    iVar9 = (*(code *)PTR_SSL_get_servername_006a896c)();
    iVar10 = (*(code *)PTR_SSL_get_servername_type_006a8a6c)(iVar5);
    if (iVar10 == -1) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,"Can\'t use SSL_get_servername\n");
      return (char *)0x0;
    }
    iVar5 = (*(code *)PTR_SSL_ctrl_006a8878)(iVar5,8,0,0);
    uVar14 = 0;
    if (iVar5 == 0) {
      uVar14 = (uint)(iVar9 != 0);
    }
    *(uint *)(iVar6 + 4) = uVar14;
    return (char *)0x0;
  }
  return *(char **)puVar3;
}

