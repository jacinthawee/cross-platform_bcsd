
void print_stuff(BIO *param_1,SSL *param_2,X509 *param_3)

{
  int iVar1;
  SSL_CIPHER *c;
  char *pcVar2;
  char *pcVar3;
  EVP_PKEY *pkey;
  long lVar4;
  COMP_METHOD *comp;
  COMP_METHOD *comp_00;
  SRTP_PROTECTION_PROFILE *pSVar5;
  SSL_SESSION *ses;
  void *ptr;
  size_t sVar6;
  _STACK *p_Var7;
  int iVar8;
  X509 *pXVar9;
  X509_NAME *pXVar10;
  BIO *pBVar11;
  ulong uVar12;
  ulong uVar13;
  char cVar14;
  uchar *local_2034;
  uint local_2030;
  char acStack_202c [8192];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if (param_3 != (X509 *)0x0) {
    p_Var7 = (_STACK *)SSL_get_peer_cert_chain(param_2);
    if (p_Var7 != (_STACK *)0x0) {
      BIO_printf(param_1,"---\nCertificate chain\n");
      for (iVar1 = 0; iVar8 = sk_num(p_Var7), iVar1 < iVar8; iVar1 = iVar1 + 1) {
        pXVar9 = (X509 *)sk_value(p_Var7,iVar1);
        pXVar10 = X509_get_subject_name(pXVar9);
        X509_NAME_oneline(pXVar10,acStack_202c,0x2000);
        BIO_printf(param_1,"%2d s:%s\n",iVar1,acStack_202c);
        pXVar9 = (X509 *)sk_value(p_Var7,iVar1);
        pXVar10 = X509_get_issuer_name(pXVar9);
        X509_NAME_oneline(pXVar10,acStack_202c,0x2000);
        BIO_printf(param_1,"   i:%s\n",acStack_202c);
        if (c_showcerts != 0) {
          pXVar9 = (X509 *)sk_value(p_Var7,iVar1);
          PEM_write_bio_X509(param_1,pXVar9);
        }
      }
      p_Var7 = (_STACK *)0x1;
    }
    BIO_printf(param_1,"---\n");
    param_3 = SSL_get_peer_certificate(param_2);
    if (param_3 == (X509 *)0x0) {
      BIO_printf(param_1,"no peer certificate available\n");
    }
    else {
      BIO_printf(param_1,"Server certificate\n");
      if ((c_showcerts == 0) || (p_Var7 == (_STACK *)0x0)) {
        PEM_write_bio_X509(param_1,param_3);
      }
      pXVar10 = X509_get_subject_name(param_3);
      X509_NAME_oneline(pXVar10,acStack_202c,0x2000);
      BIO_printf(param_1,"subject=%s\n",acStack_202c);
      pXVar10 = X509_get_issuer_name(param_3);
      X509_NAME_oneline(pXVar10,acStack_202c,0x2000);
      BIO_printf(param_1,"issuer=%s\n",acStack_202c);
    }
    p_Var7 = (_STACK *)SSL_get_client_CA_list(param_2);
    if ((p_Var7 == (_STACK *)0x0) || (iVar1 = sk_num(p_Var7), iVar1 < 1)) {
      BIO_printf(param_1,"---\nNo client certificate CA names sent\n");
    }
    else {
      BIO_printf(param_1,"---\nAcceptable client certificate CA names\n");
      for (iVar1 = 0; iVar8 = sk_num(p_Var7), iVar1 < iVar8; iVar1 = iVar1 + 1) {
        pXVar10 = (X509_NAME *)sk_value(p_Var7,iVar1);
        X509_NAME_oneline(pXVar10,acStack_202c,0x2000);
        sVar6 = strlen(acStack_202c);
        BIO_write(param_1,acStack_202c,sVar6);
        BIO_write(param_1,"\n",1);
      }
    }
    pcVar2 = SSL_get_shared_ciphers(param_2,acStack_202c,0x2000);
    if (pcVar2 != (char *)0x0) {
      BIO_printf(param_1,"---\nCiphers common between both SSL endpoints:\n");
      cVar14 = *pcVar2;
      if (cVar14 != '\0') {
        iVar8 = 0;
        iVar1 = 0;
        do {
          while (cVar14 == ':') {
            iVar8 = iVar8 + 1;
            BIO_write(param_1,&DAT_0012f3f4,((iVar1 / 0x19) * 0x19 - iVar1) + 0xf);
            pcVar3 = "\n";
            if (iVar8 != (iVar8 / 3) * 3) {
              pcVar3 = " ";
            }
            BIO_write(param_1,pcVar3,1);
            pcVar2 = pcVar2 + 1;
            cVar14 = *pcVar2;
            iVar1 = 0;
            if (cVar14 == '\0') goto LAB_0002a556;
          }
          iVar1 = iVar1 + 1;
          BIO_write(param_1,pcVar2,1);
          pcVar2 = pcVar2 + 1;
          cVar14 = *pcVar2;
        } while (cVar14 != '\0');
      }
LAB_0002a556:
      BIO_write(param_1,"\n",1);
    }
    pBVar11 = SSL_get_rbio(param_2);
    uVar12 = BIO_number_read(pBVar11);
    pBVar11 = SSL_get_wbio(param_2);
    uVar13 = BIO_number_written(pBVar11);
    BIO_printf(param_1,"---\nSSL handshake has read %ld bytes and written %ld bytes\n",uVar12,uVar13
              );
  }
  iVar1 = SSL_cache_hit(param_2);
  pcVar2 = "---\nNew, ";
  if (iVar1 != 0) {
    pcVar2 = "---\nReused, ";
  }
  BIO_printf(param_1,pcVar2);
  c = SSL_get_current_cipher(param_2);
  pcVar2 = SSL_CIPHER_get_version(c);
  pcVar3 = SSL_CIPHER_get_name(c);
  BIO_printf(param_1,"%s, Cipher is %s\n",pcVar2,pcVar3);
  if (param_3 != (X509 *)0x0) {
    pkey = X509_get_pubkey(param_3);
    iVar1 = EVP_PKEY_bits(pkey);
    BIO_printf(param_1,"Server public key is %d bit\n",iVar1);
    EVP_PKEY_free(pkey);
  }
  lVar4 = SSL_ctrl(param_2,0x4c,0,(void *)0x0);
  pcVar2 = " NOT";
  if (lVar4 != 0) {
    pcVar2 = "";
  }
  BIO_printf(param_1,"Secure Renegotiation IS%s supported\n",pcVar2);
  comp = SSL_get_current_compression(param_2);
  comp_00 = SSL_get_current_expansion(param_2);
  if (comp == (COMP_METHOD *)0x0) {
    pcVar2 = "NONE";
  }
  else {
    pcVar2 = SSL_COMP_get_name(comp);
  }
  BIO_printf(param_1,"Compression: %s\n",pcVar2);
  if (comp_00 == (COMP_METHOD *)0x0) {
    pcVar2 = "NONE";
  }
  else {
    pcVar2 = SSL_COMP_get_name(comp_00);
  }
  BIO_printf(param_1,"Expansion: %s\n",pcVar2);
  if (next_proto._8_4_ != -1) {
    SSL_get0_next_proto_negotiated(param_2,&local_2034,&local_2030);
    BIO_printf(param_1,"Next protocol: (%d) ",next_proto._8_4_);
    BIO_write(param_1,local_2034,local_2030);
    BIO_write(param_1,"\n",1);
  }
  pSVar5 = SSL_get_selected_srtp_profile(param_2);
  if (pSVar5 != (SRTP_PROTECTION_PROFILE *)0x0) {
    BIO_printf(param_1,"SRTP Extension negotiated, profile=%s\n",pSVar5->name);
  }
  ses = SSL_get_session(param_2);
  SSL_SESSION_print(param_1,ses);
  if (keymatexportlabel != (char *)0x0) {
    BIO_printf(param_1,"Keying material exporter:\n");
    BIO_printf(param_1,"    Label: \'%s\'\n",keymatexportlabel);
    BIO_printf(param_1,"    Length: %i bytes\n",keymatexportlen);
    ptr = CRYPTO_malloc(keymatexportlen,"s_client.c",0x813);
    pcVar2 = keymatexportlabel;
    if (ptr != (void *)0x0) {
      sVar6 = strlen(keymatexportlabel);
      iVar1 = SSL_export_keying_material(param_2,ptr,keymatexportlen,pcVar2,sVar6,0,0,0);
      if (iVar1 == 0) {
        BIO_printf(param_1,"    Error\n");
      }
      else {
        BIO_printf(param_1,"    Keying material: ");
        if (0 < keymatexportlen) {
          iVar1 = 0;
          do {
            BIO_printf(param_1,"%02X",(uint)*(byte *)((int)ptr + iVar1));
            iVar1 = iVar1 + 1;
          } while (iVar1 < keymatexportlen);
        }
        BIO_printf(param_1,"\n");
      }
      CRYPTO_free(ptr);
    }
  }
  BIO_printf(param_1,"---\n");
  if (param_3 != (X509 *)0x0) {
    X509_free(param_3);
  }
  BIO_ctrl(param_1,0xb,0,(void *)0x0);
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

