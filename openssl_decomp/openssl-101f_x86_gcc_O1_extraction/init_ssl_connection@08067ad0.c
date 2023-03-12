
int __regparm3 init_ssl_connection(SSL *param_1)

{
  int iVar1;
  int iVar2;
  SSL_SESSION *x;
  X509 *x_00;
  X509_NAME *pXVar3;
  char *pcVar4;
  SSL_CIPHER *c;
  SRTP_PROTECTION_PROFILE *pSVar5;
  uint uVar6;
  long lVar7;
  undefined1 *puVar8;
  void *ptr;
  size_t sVar9;
  int in_GS_OFFSET;
  undefined4 uVar10;
  uint *****len;
  uchar *local_2018;
  uint *****local_2014;
  char local_2010 [8192];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = SSL_accept(param_1);
  do {
    if (0 < iVar1) {
      x = SSL_get_session(param_1);
      PEM_write_bio_SSL_SESSION(bio_s_out,x);
      x_00 = SSL_get_peer_certificate(param_1);
      if (x_00 != (X509 *)0x0) {
        BIO_printf(bio_s_out,"Client certificate\n");
        PEM_write_bio_X509(bio_s_out,x_00);
        pXVar3 = X509_get_subject_name(x_00);
        X509_NAME_oneline(pXVar3,local_2010,0x2000);
        BIO_printf(bio_s_out,"subject=%s\n",local_2010);
        pXVar3 = X509_get_issuer_name(x_00);
        X509_NAME_oneline(pXVar3,local_2010,0x2000);
        BIO_printf(bio_s_out,"issuer=%s\n",local_2010);
        X509_free(x_00);
      }
      pcVar4 = SSL_get_shared_ciphers(param_1,local_2010,0x2000);
      if (pcVar4 != (char *)0x0) {
        BIO_printf(bio_s_out,"Shared ciphers:%s\n",local_2010);
      }
      c = SSL_get_current_cipher(param_1);
      pcVar4 = SSL_CIPHER_get_name(c);
      if (pcVar4 == (char *)0x0) {
        pcVar4 = "(NONE)";
      }
      BIO_printf(bio_s_out,"CIPHER is %s\n",pcVar4);
      len = (uint *****)&local_2014;
      SSL_get0_next_proto_negotiated(param_1,&local_2018,(uint *)len);
      if (local_2018 != (uchar *)0x0) {
        BIO_printf(bio_s_out,"NEXTPROTO is ");
        BIO_write(bio_s_out,local_2018,(int)local_2014);
        BIO_printf(bio_s_out,"\n");
        len = local_2014;
      }
      pSVar5 = SSL_get_selected_srtp_profile(param_1);
      if (pSVar5 != (SRTP_PROTECTION_PROFILE *)0x0) {
        len = (uint *****)pSVar5->name;
        BIO_printf(bio_s_out,"SRTP Extension negotiated, profile=%s\n",len);
      }
      iVar1 = SSL_cache_hit(param_1);
      if (iVar1 != 0) {
        BIO_printf(bio_s_out,"Reused session-id\n",len);
      }
      uVar6 = SSL_ctrl(param_1,0xd,0,(void *)0x0);
      if ((uVar6 & 8) != 0) {
        BIO_printf(bio_s_out,"Peer has incorrect TLSv1 block padding\n");
      }
      lVar7 = SSL_ctrl(param_1,0x4c,0,(void *)0x0);
      puVar8 = &DAT_081ec74a;
      if (lVar7 == 0) {
        puVar8 = &DAT_081f450a;
      }
      BIO_printf(bio_s_out,"Secure Renegotiation IS%s supported\n",puVar8);
      if (keymatexportlabel != (char *)0x0) {
        BIO_printf(bio_s_out,"Keying material exporter:\n",puVar8);
        BIO_printf(bio_s_out,"    Label: \'%s\'\n",keymatexportlabel);
        BIO_printf(bio_s_out,"    Length: %i bytes\n",keymatexportlen);
        ptr = CRYPTO_malloc(keymatexportlen,"s_server.c",0x9bc);
        pcVar4 = keymatexportlabel;
        if (ptr != (void *)0x0) {
          sVar9 = strlen(keymatexportlabel);
          uVar6 = 0;
          iVar1 = SSL_export_keying_material(param_1,ptr,keymatexportlen,pcVar4,sVar9,0,0,0);
          if (iVar1 == 0) {
            BIO_printf(bio_s_out,"    Error\n");
          }
          else {
            iVar1 = 0;
            BIO_printf(bio_s_out,"    Keying material: ");
            if (0 < keymatexportlen) {
              do {
                uVar6 = (uint)*(byte *)((int)ptr + iVar1);
                iVar1 = iVar1 + 1;
                BIO_printf(bio_s_out,"%02X",uVar6);
              } while (iVar1 < keymatexportlen);
            }
            BIO_printf(bio_s_out,"\n",uVar6);
          }
          CRYPTO_free(ptr);
        }
      }
      iVar1 = 1;
LAB_08067e58:
      if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
        return iVar1;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    iVar2 = SSL_get_error(param_1,iVar1);
    if (iVar2 != 4) {
      iVar1 = BIO_sock_should_retry(iVar1);
      if (iVar1 == 0) {
        BIO_printf(bio_err,"ERROR\n");
        lVar7 = SSL_get_verify_result(param_1);
        if (lVar7 == 0) {
          ERR_print_errors(bio_err);
        }
        else {
          pcVar4 = X509_verify_cert_error_string(lVar7);
          BIO_printf(bio_err,"verify error:%s\n",pcVar4);
        }
      }
      else {
        iVar1 = 1;
        BIO_printf(bio_s_out,"DELAY\n");
      }
      goto LAB_08067e58;
    }
    uVar10 = srp_callback_parm._0_4_;
    BIO_printf(bio_s_out,"LOOKUP during accept %s\n",srp_callback_parm._0_4_);
    srp_callback_parm._8_4_ = SRP_VBASE_get_by_user(srp_callback_parm._4_4_,srp_callback_parm._0_4_)
    ;
    if (srp_callback_parm._8_4_ == 0) {
      BIO_printf(bio_s_out,"LOOKUP not successful\n",uVar10);
    }
    else {
      BIO_printf(bio_s_out,"LOOKUP done %s\n",*(undefined4 *)(srp_callback_parm._8_4_ + 0x14));
    }
    iVar1 = SSL_accept(param_1);
  } while( true );
}

