
void __regparm3 print_stuff(BIO *param_1,SSL *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  SSL_CIPHER *pSVar3;
  char *pcVar4;
  long lVar5;
  undefined1 *puVar6;
  COMP_METHOD *comp;
  COMP_METHOD *comp_00;
  SRTP_PROTECTION_PROFILE *pSVar7;
  SSL_SESSION *ses;
  void *ptr;
  size_t sVar8;
  _STACK *p_Var9;
  int iVar10;
  X509 *pXVar11;
  X509_NAME *pXVar12;
  uint uVar13;
  undefined *data;
  BIO *pBVar14;
  ulong uVar15;
  ulong uVar16;
  EVP_PKEY *pkey;
  uint *puVar17;
  uint *puVar18;
  int in_GS_OFFSET;
  bool bVar19;
  char *pcVar20;
  uint uVar21;
  X509 *local_2038;
  int local_2034;
  uchar *local_2028;
  uint local_2024;
  uint local_2020 [2048];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_3 == 0) {
    iVar2 = SSL_cache_hit(param_2);
    if (iVar2 == 0) {
      pcVar20 = "---\nNew, ";
    }
    else {
      pcVar20 = "---\nReused, ";
    }
    BIO_printf(param_1,pcVar20);
    pSVar3 = SSL_get_current_cipher(param_2);
    pcVar20 = SSL_CIPHER_get_name(pSVar3);
    pcVar4 = SSL_CIPHER_get_version(pSVar3);
    BIO_printf(param_1,"%s, Cipher is %s\n",pcVar4,pcVar20);
    local_2038 = (X509 *)0x0;
    goto LAB_0806d0b0;
  }
  p_Var9 = (_STACK *)SSL_get_peer_cert_chain(param_2);
  if (p_Var9 == (_STACK *)0x0) {
    BIO_printf(param_1,"---\n");
    local_2038 = SSL_get_peer_certificate(param_2);
    if (local_2038 != (X509 *)0x0) {
      BIO_printf(param_1,"Server certificate\n");
LAB_0806d7e4:
      PEM_write_bio_X509(param_1,local_2038);
      goto LAB_0806d48a;
    }
LAB_0806d800:
    BIO_printf(param_1,"no peer certificate available\n");
    local_2038 = (X509 *)0x0;
  }
  else {
    BIO_printf(param_1,"---\nCertificate chain\n");
    for (iVar2 = 0; iVar10 = sk_num(p_Var9), iVar2 < iVar10; iVar2 = iVar2 + 1) {
      pXVar11 = (X509 *)sk_value(p_Var9,iVar2);
      pXVar12 = X509_get_subject_name(pXVar11);
      X509_NAME_oneline(pXVar12,(char *)local_2020,0x2000);
      BIO_printf(param_1,"%2d s:%s\n",iVar2,local_2020);
      pXVar11 = (X509 *)sk_value(p_Var9,iVar2);
      pXVar12 = X509_get_issuer_name(pXVar11);
      X509_NAME_oneline(pXVar12,(char *)local_2020,0x2000);
      BIO_printf(param_1,"   i:%s\n",local_2020);
      if (c_showcerts != 0) {
        pXVar11 = (X509 *)sk_value(p_Var9,iVar2);
        PEM_write_bio_X509(param_1,pXVar11);
      }
    }
    BIO_printf(param_1,"---\n");
    local_2038 = SSL_get_peer_certificate(param_2);
    if (local_2038 == (X509 *)0x0) goto LAB_0806d800;
    BIO_printf(param_1,"Server certificate\n");
    if (c_showcerts == 0) goto LAB_0806d7e4;
LAB_0806d48a:
    pXVar12 = X509_get_subject_name(local_2038);
    X509_NAME_oneline(pXVar12,(char *)local_2020,0x2000);
    BIO_printf(param_1,"subject=%s\n",local_2020);
    pXVar12 = X509_get_issuer_name(local_2038);
    X509_NAME_oneline(pXVar12,(char *)local_2020,0x2000);
    BIO_printf(param_1,"issuer=%s\n",local_2020);
  }
  p_Var9 = (_STACK *)SSL_get_client_CA_list(param_2);
  if ((p_Var9 == (_STACK *)0x0) || (iVar2 = sk_num(p_Var9), iVar2 < 1)) {
    BIO_printf(param_1,"---\nNo client certificate CA names sent\n");
  }
  else {
    BIO_printf(param_1,"---\nAcceptable client certificate CA names\n");
    for (iVar2 = 0; iVar10 = sk_num(p_Var9), iVar2 < iVar10; iVar2 = iVar2 + 1) {
      pXVar12 = (X509_NAME *)sk_value(p_Var9,iVar2);
      X509_NAME_oneline(pXVar12,(char *)local_2020,0x2000);
      puVar18 = local_2020;
      do {
        puVar17 = puVar18;
        uVar13 = *puVar17 + 0xfefefeff & ~*puVar17;
        uVar21 = uVar13 & 0x80808080;
        puVar18 = puVar17 + 1;
      } while (uVar21 == 0);
      bVar19 = (uVar13 & 0x8080) == 0;
      if (bVar19) {
        uVar21 = uVar21 >> 0x10;
      }
      if (bVar19) {
        puVar18 = (uint *)((int)puVar17 + 6);
      }
      BIO_write(param_1,local_2020,
                (int)puVar18 + ((-3 - (uint)CARRY1((byte)uVar21,(byte)uVar21)) - (int)local_2020));
      BIO_write(param_1,&DAT_081f11d3,1);
    }
  }
  pcVar20 = SSL_get_shared_ciphers(param_2,(char *)local_2020,0x2000);
  if (pcVar20 != (char *)0x0) {
    iVar2 = 0;
    BIO_printf(param_1,"---\nCiphers common between both SSL endpoints:\n");
    cVar1 = *pcVar20;
    if (cVar1 != '\0') {
      local_2034 = 0;
      do {
        while (cVar1 != ':') {
          iVar2 = iVar2 + 1;
          BIO_write(param_1,pcVar20,1);
          cVar1 = pcVar20[1];
          pcVar20 = pcVar20 + 1;
          if (cVar1 == '\0') goto LAB_0806d6c1;
        }
        BIO_write(param_1,"                ",0xf - iVar2 % 0x19);
        local_2034 = local_2034 + 1;
        data = &DAT_081f84a7;
        if (local_2034 == (local_2034 / 3) * 3) {
          data = &DAT_081f11d3;
        }
        iVar2 = 0;
        BIO_write(param_1,data,1);
        cVar1 = pcVar20[1];
        pcVar20 = pcVar20 + 1;
      } while (cVar1 != '\0');
    }
LAB_0806d6c1:
    BIO_write(param_1,&DAT_081f11d3,1);
  }
  pBVar14 = SSL_get_wbio(param_2);
  uVar15 = BIO_number_written(pBVar14);
  pBVar14 = SSL_get_rbio(param_2);
  uVar16 = BIO_number_read(pBVar14);
  BIO_printf(param_1,"---\nSSL handshake has read %ld bytes and written %ld bytes\n",uVar16,uVar15);
  iVar2 = SSL_cache_hit(param_2);
  pcVar20 = "---\nReused, ";
  if (iVar2 == 0) {
    pcVar20 = "---\nNew, ";
  }
  BIO_printf(param_1,pcVar20);
  pSVar3 = SSL_get_current_cipher(param_2);
  pcVar20 = SSL_CIPHER_get_name(pSVar3);
  pcVar4 = SSL_CIPHER_get_version(pSVar3);
  BIO_printf(param_1,"%s, Cipher is %s\n",pcVar4,pcVar20);
  if (local_2038 != (X509 *)0x0) {
    pkey = X509_get_pubkey(local_2038);
    iVar2 = EVP_PKEY_bits(pkey);
    BIO_printf(param_1,"Server public key is %d bit\n",iVar2);
    EVP_PKEY_free(pkey);
  }
LAB_0806d0b0:
  lVar5 = SSL_ctrl(param_2,0x4c,0,(void *)0x0);
  puVar6 = &DAT_081ec74a;
  if (lVar5 == 0) {
    puVar6 = &DAT_081f450a;
  }
  BIO_printf(param_1,"Secure Renegotiation IS%s supported\n",puVar6);
  comp = SSL_get_current_compression(param_2);
  comp_00 = SSL_get_current_expansion(param_2);
  pcVar20 = "NONE";
  if (comp != (COMP_METHOD *)0x0) {
    pcVar20 = SSL_COMP_get_name(comp);
  }
  BIO_printf(param_1,"Compression: %s\n",pcVar20);
  pcVar20 = "NONE";
  if (comp_00 != (COMP_METHOD *)0x0) {
    pcVar20 = SSL_COMP_get_name(comp_00);
  }
  BIO_printf(param_1,"Expansion: %s\n",pcVar20);
  if (next_proto._8_4_ != -1) {
    SSL_get0_next_proto_negotiated(param_2,&local_2028,&local_2024);
    BIO_printf(param_1,"Next protocol: (%d) ",next_proto._8_4_);
    BIO_write(param_1,local_2028,local_2024);
    pcVar20 = (char *)0x1;
    BIO_write(param_1,&DAT_081f11d3,1);
  }
  pSVar7 = SSL_get_selected_srtp_profile(param_2);
  if (pSVar7 != (SRTP_PROTECTION_PROFILE *)0x0) {
    pcVar20 = pSVar7->name;
    BIO_printf(param_1,"SRTP Extension negotiated, profile=%s\n",pcVar20);
  }
  ses = SSL_get_session(param_2);
  SSL_SESSION_print(param_1,ses);
  if (keymatexportlabel != (char *)0x0) {
    BIO_printf(param_1,"Keying material exporter:\n",pcVar20);
    BIO_printf(param_1,"    Label: \'%s\'\n",keymatexportlabel);
    BIO_printf(param_1,"    Length: %i bytes\n",keymatexportlen);
    ptr = CRYPTO_malloc(keymatexportlen,"s_client.c",0x82e);
    pcVar20 = keymatexportlabel;
    if (ptr != (void *)0x0) {
      sVar8 = strlen(keymatexportlabel);
      uVar21 = 0;
      iVar2 = SSL_export_keying_material(param_2,ptr,keymatexportlen,pcVar20,sVar8,0,0,0);
      if (iVar2 == 0) {
        BIO_printf(param_1,"    Error\n");
      }
      else {
        iVar2 = 0;
        BIO_printf(param_1,"    Keying material: ");
        if (0 < keymatexportlen) {
          do {
            uVar21 = (uint)*(byte *)((int)ptr + iVar2);
            iVar2 = iVar2 + 1;
            BIO_printf(param_1,"%02X",uVar21);
          } while (iVar2 < keymatexportlen);
        }
        BIO_printf(param_1,"\n",uVar21);
      }
      CRYPTO_free(ptr);
    }
  }
  BIO_printf(param_1,"---\n");
  if (local_2038 != (X509 *)0x0) {
    X509_free(local_2038);
  }
  BIO_ctrl(param_1,0xb,0,(void *)0x0);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

