
int print_stuff(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined uVar1;
  bool bVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  undefined4 *puVar10;
  int iVar11;
  char cVar13;
  uint uVar12;
  char *pcVar14;
  undefined *puVar15;
  undefined4 local_2034;
  undefined4 local_2030;
  undefined auStack_202c [8192];
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_3 == 0) {
    iVar4 = (*(code *)PTR_SSL_cache_hit_006a88b8)(param_2);
    if (iVar4 == 0) {
      pcVar14 = "---\nNew, ";
    }
    else {
      pcVar14 = "---\nReused, ";
    }
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,pcVar14);
    uVar5 = (*(code *)PTR_SSL_get_current_cipher_006a88a8)(param_2);
    uVar6 = (*(code *)PTR_SSL_CIPHER_get_version_006a8950)(uVar5);
    uVar5 = (*(code *)PTR_SSL_CIPHER_get_name_006a88ac)(uVar5);
    iVar4 = 0;
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%s, Cipher is %s\n",uVar6,uVar5);
  }
  else {
    iVar4 = (*(code *)PTR_SSL_get_peer_cert_chain_006a8a64)(param_2);
    if (iVar4 == 0) {
      bVar2 = false;
    }
    else {
      iVar8 = 0;
      (*(code *)PTR_BIO_printf_006a7f38)(param_1,"---\nCertificate chain\n");
      iVar7 = (*(code *)PTR_sk_num_006a7f2c)(iVar4);
      if (0 < iVar7) {
        do {
          uVar5 = (*(code *)PTR_sk_value_006a7f24)(iVar4,iVar8);
          uVar5 = (*(code *)PTR_X509_get_subject_name_006a8000)(uVar5);
          (*(code *)PTR_X509_NAME_oneline_006a8110)(uVar5,auStack_202c,0x2000);
          (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%2d s:%s\n",iVar8,auStack_202c);
          uVar5 = (*(code *)PTR_sk_value_006a7f24)(iVar4,iVar8);
          uVar5 = (*(code *)PTR_X509_get_issuer_name_006a87d0)(uVar5);
          (*(code *)PTR_X509_NAME_oneline_006a8110)(uVar5,auStack_202c,0x2000);
          (*(code *)PTR_BIO_printf_006a7f38)(param_1,"   i:%s\n",auStack_202c);
          if (c_showcerts != 0) {
            uVar5 = (*(code *)PTR_sk_value_006a7f24)(iVar4,iVar8);
            (*(code *)PTR_PEM_write_bio_X509_006a8020)(param_1,uVar5);
          }
          iVar8 = iVar8 + 1;
          iVar7 = (*(code *)PTR_sk_num_006a7f2c)(iVar4);
        } while (iVar8 < iVar7);
      }
      bVar2 = true;
    }
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,&DAT_0063ba54);
    iVar4 = (*(code *)PTR_SSL_get_peer_certificate_006a88a0)(param_2);
    if (iVar4 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(param_1,"no peer certificate available\n");
    }
    else {
      (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Server certificate\n");
      if ((c_showcerts == 0) || (!bVar2)) {
        (*(code *)PTR_PEM_write_bio_X509_006a8020)(param_1,iVar4);
      }
      uVar5 = (*(code *)PTR_X509_get_subject_name_006a8000)(iVar4);
      (*(code *)PTR_X509_NAME_oneline_006a8110)(uVar5,auStack_202c,0x2000);
      (*(code *)PTR_BIO_printf_006a7f38)(param_1,"subject=%s\n",auStack_202c);
      uVar5 = (*(code *)PTR_X509_get_issuer_name_006a87d0)(iVar4);
      (*(code *)PTR_X509_NAME_oneline_006a8110)(uVar5,auStack_202c,0x2000);
      (*(code *)PTR_BIO_printf_006a7f38)(param_1,"issuer=%s\n",auStack_202c);
    }
    iVar7 = (*(code *)PTR_SSL_get_client_CA_list_006a8a68)(param_2);
    if ((iVar7 == 0) || (iVar8 = (*(code *)PTR_sk_num_006a7f2c)(iVar7), iVar8 < 1)) {
      (*(code *)PTR_BIO_printf_006a7f38)(param_1,"---\nNo client certificate CA names sent\n");
    }
    else {
      (*(code *)PTR_BIO_printf_006a7f38)(param_1,"---\nAcceptable client certificate CA names\n");
      for (iVar8 = 0; iVar11 = (*(code *)PTR_sk_num_006a7f2c)(iVar7), iVar8 < iVar11;
          iVar8 = iVar8 + 1) {
        uVar5 = (*(code *)PTR_sk_value_006a7f24)(iVar7,iVar8);
        (*(code *)PTR_X509_NAME_oneline_006a8110)(uVar5,auStack_202c,0x2000);
        uVar5 = (*(code *)PTR_strlen_006aab30)(auStack_202c);
        (*(code *)PTR_BIO_write_006a7f14)(param_1,auStack_202c,uVar5);
        (*(code *)PTR_BIO_write_006a7f14)(param_1,"\n",1);
      }
    }
    pcVar14 = (char *)(*(code *)PTR_SSL_get_shared_ciphers_006a88a4)(param_2,auStack_202c,0x2000);
    if (pcVar14 != (char *)0x0) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (param_1,"---\nCiphers common between both SSL endpoints:\n");
      cVar13 = *pcVar14;
      if (cVar13 != '\0') {
        iVar7 = 0;
        iVar8 = 0;
        do {
          while (cVar13 != ':') {
            (*(code *)PTR_BIO_write_006a7f14)(param_1,pcVar14,1);
            iVar8 = iVar8 + 1;
            cVar13 = pcVar14[1];
            pcVar14 = pcVar14 + 1;
            if (cVar13 == '\0') goto LAB_00449bd8;
          }
          iVar7 = iVar7 + 1;
          (*(code *)PTR_BIO_write_006a7f14)
                    (param_1,&DAT_0063d84c,((iVar8 / 0x19) * 0x19 - iVar8) + 0xf);
          if (iVar7 == (iVar7 / 3) * 3) {
            puVar10 = (undefined4 *)0x63bac8;
          }
          else {
            puVar10 = &DAT_0063f0b8;
          }
          (*(code *)PTR_BIO_write_006a7f14)(param_1,puVar10,1);
          iVar8 = 0;
          cVar13 = pcVar14[1];
          pcVar14 = pcVar14 + 1;
        } while (cVar13 != '\0');
      }
LAB_00449bd8:
      (*(code *)PTR_BIO_write_006a7f14)(param_1,"\n",1);
    }
    uVar5 = (*(code *)PTR_SSL_get_rbio_006a8924)(param_2);
    uVar5 = (*(code *)PTR_BIO_number_read_006a8654)(uVar5);
    uVar6 = (*(code *)PTR_SSL_get_wbio_006a8908)(param_2);
    uVar6 = (*(code *)PTR_BIO_number_written_006a8658)(uVar6);
    (*(code *)PTR_BIO_printf_006a7f38)
              (param_1,"---\nSSL handshake has read %ld bytes and written %ld bytes\n",uVar5,uVar6);
    iVar7 = (*(code *)PTR_SSL_cache_hit_006a88b8)(param_2);
    if (iVar7 == 0) {
      pcVar14 = "---\nNew, ";
    }
    else {
      pcVar14 = "---\nReused, ";
    }
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,pcVar14);
    uVar5 = (*(code *)PTR_SSL_get_current_cipher_006a88a8)(param_2);
    uVar6 = (*(code *)PTR_SSL_CIPHER_get_version_006a8950)(uVar5);
    uVar5 = (*(code *)PTR_SSL_CIPHER_get_name_006a88ac)(uVar5);
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%s, Cipher is %s\n",uVar6,uVar5);
    if (iVar4 != 0) {
      uVar5 = (*(code *)PTR_X509_get_pubkey_006a8008)(iVar4);
      uVar6 = (*(code *)PTR_EVP_PKEY_bits_006a80e4)(uVar5);
      (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Server public key is %d bit\n",uVar6);
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(uVar5);
    }
  }
  iVar7 = (*(code *)PTR_SSL_ctrl_006a8878)(param_2,0x4c,0,0);
  if (iVar7 == 0) {
    pcVar14 = " NOT";
  }
  else {
    pcVar14 = "";
  }
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Secure Renegotiation IS%s supported\n",pcVar14);
  iVar7 = (*(code *)PTR_SSL_get_current_compression_006a8a58)(param_2);
  iVar8 = (*(code *)PTR_SSL_get_current_expansion_006a8a5c)(param_2);
  if (iVar7 == 0) {
    puVar9 = &DAT_00637b4c;
  }
  else {
    puVar9 = (undefined *)(*(code *)PTR_SSL_COMP_get_name_006a8a60)(iVar7);
  }
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Compression: %s\n",puVar9);
  if (iVar8 == 0) {
    puVar9 = &DAT_00637b4c;
  }
  else {
    puVar9 = (undefined *)(*(code *)PTR_SSL_COMP_get_name_006a8a60)(iVar8);
  }
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Expansion: %s\n",puVar9);
  if (next_proto._8_4_ != -1) {
    (*(code *)PTR_SSL_get0_next_proto_negotiated_006a88b0)(param_2,&local_2034,&local_2030);
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Next protocol: (%d) ",next_proto._8_4_);
    (*(code *)PTR_BIO_write_006a7f14)(param_1,local_2034,local_2030);
    (*(code *)PTR_BIO_write_006a7f14)(param_1,"\n",1);
  }
  puVar10 = (undefined4 *)(*(code *)PTR_SSL_get_selected_srtp_profile_006a88b4)(param_2);
  if (puVar10 != (undefined4 *)0x0) {
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"SRTP Extension negotiated, profile=%s\n",*puVar10);
  }
  uVar5 = (*(code *)PTR_SSL_get_session_006a8898)(param_2);
  (*(code *)PTR_SSL_SESSION_print_006a8958)(param_1,uVar5);
  if (keymatexportlabel != 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Keying material exporter:\n");
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"    Label: \'%s\'\n",keymatexportlabel);
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"    Length: %i bytes\n",keymatexportlen);
    puVar9 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(keymatexportlen,"s_client.c",0x82e);
    iVar7 = keymatexportlabel;
    if (puVar9 != (undefined *)0x0) {
      uVar5 = (*(code *)PTR_strlen_006aab30)(keymatexportlabel);
      iVar7 = (*(code *)PTR_SSL_export_keying_material_006a88bc)
                        (param_2,puVar9,keymatexportlen,iVar7,uVar5,0,0,0);
      if (iVar7 == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)(param_1,"    Error\n");
      }
      else {
        (*(code *)PTR_BIO_printf_006a7f38)(param_1,"    Keying material: ");
        if (0 < keymatexportlen) {
          iVar7 = 0;
          puVar15 = puVar9;
          do {
            uVar1 = *puVar15;
            iVar7 = iVar7 + 1;
            puVar15 = puVar15 + 1;
            (*(code *)PTR_BIO_printf_006a7f38)(param_1,&DAT_00635448,uVar1);
          } while (iVar7 < keymatexportlen);
        }
        (*(code *)PTR_BIO_printf_006a7f38)(param_1,"\n");
      }
      (*(code *)PTR_CRYPTO_free_006a7f88)(puVar9);
    }
  }
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,&DAT_0063ba54);
  if (iVar4 != 0) {
    (*(code *)PTR_X509_free_006a7f90)(iVar4);
  }
  iVar4 = 0;
  (*(code *)PTR_BIO_ctrl_006a7f18)(param_1,0xb,0,0);
  if (local_2c != *(int *)puVar3) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    iVar7 = (*(code *)PTR_SSL_get_servername_006a896c)();
    iVar8 = (*(code *)PTR_SSL_get_servername_type_006a8a6c)(param_1);
    if (iVar8 == -1) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)PTR_bio_err_006a7f3c,"Can\'t use SSL_get_servername\n");
      return 0;
    }
    iVar8 = (*(code *)PTR_SSL_ctrl_006a8878)(param_1,8,0,0);
    uVar12 = 0;
    if (iVar8 == 0) {
      uVar12 = (uint)(iVar7 != 0);
    }
    *(uint *)(iVar4 + 4) = uVar12;
    return 0;
  }
  return *(int *)puVar3;
}

