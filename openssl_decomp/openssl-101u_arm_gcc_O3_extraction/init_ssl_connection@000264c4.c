
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void init_ssl_connection(SSL *param_1)

{
  BIO *pBVar1;
  int iVar2;
  int iVar3;
  SSL_SESSION *x;
  X509 *x_00;
  X509_NAME *pXVar4;
  char *pcVar5;
  SSL_CIPHER *c;
  char *pcVar6;
  SRTP_PROTECTION_PROFILE *pSVar7;
  long lVar8;
  void *ptr;
  size_t sVar9;
  uchar *puStack_2034;
  uint local_2030;
  char acStack_202c [8192];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  iVar2 = SSL_accept(param_1);
  while (iVar2 < 1) {
    while( true ) {
      iVar3 = SSL_get_error(param_1,iVar2);
      if (iVar3 != 4) {
        iVar2 = BIO_sock_should_retry(iVar2);
        if (iVar2 == 0) {
          BIO_printf(bio_err,"ERROR\n");
          lVar8 = SSL_get_verify_result(param_1);
          pBVar1 = bio_err;
          if (lVar8 == 0) {
            ERR_print_errors(bio_err);
          }
          else {
            pcVar5 = X509_verify_cert_error_string(lVar8);
            BIO_printf(pBVar1,"verify error:%s\n",pcVar5);
          }
        }
        else {
          iVar2 = 1;
          BIO_printf(bio_s_out,"DELAY\n");
        }
        goto LAB_00026782;
      }
      BIO_printf(bio_s_out,"LOOKUP during accept %s\n",srp_callback_parm._0_4_);
      SRP_user_pwd_free(srp_callback_parm._8_4_);
      srp_callback_parm._8_4_ =
           SRP_VBASE_get1_by_user(srp_callback_parm._4_4_,srp_callback_parm._0_4_);
      if (srp_callback_parm._8_4_ != 0) break;
      BIO_printf(bio_s_out,"LOOKUP not successful\n");
      iVar2 = SSL_accept(param_1);
      if (0 < iVar2) goto LAB_0002656c;
    }
    BIO_printf(bio_s_out,"LOOKUP done %s\n",*(undefined4 *)(srp_callback_parm._8_4_ + 0x14));
    iVar2 = SSL_accept(param_1);
  }
LAB_0002656c:
  pBVar1 = bio_s_out;
  x = SSL_get_session(param_1);
  PEM_write_bio_SSL_SESSION(pBVar1,x);
  x_00 = SSL_get_peer_certificate(param_1);
  if (x_00 != (X509 *)0x0) {
    BIO_printf(bio_s_out,"Client certificate\n");
    PEM_write_bio_X509(bio_s_out,x_00);
    pXVar4 = X509_get_subject_name(x_00);
    X509_NAME_oneline(pXVar4,acStack_202c,0x2000);
    BIO_printf(bio_s_out,"subject=%s\n",acStack_202c);
    pXVar4 = X509_get_issuer_name(x_00);
    X509_NAME_oneline(pXVar4,acStack_202c,0x2000);
    BIO_printf(bio_s_out,"issuer=%s\n",acStack_202c);
    X509_free(x_00);
  }
  pcVar5 = SSL_get_shared_ciphers(param_1,acStack_202c,0x2000);
  if (pcVar5 != (char *)0x0) {
    BIO_printf(bio_s_out,"Shared ciphers:%s\n",acStack_202c);
  }
  c = SSL_get_current_cipher(param_1);
  pcVar6 = SSL_CIPHER_get_name(c);
  pcVar5 = "(NONE)";
  if (pcVar6 != (char *)0x0) {
    pcVar5 = pcVar6;
  }
  BIO_printf(bio_s_out,"CIPHER is %s\n",pcVar5);
  SSL_get0_next_proto_negotiated(param_1,&puStack_2034,&local_2030);
  if (puStack_2034 != (uchar *)0x0) {
    BIO_printf(bio_s_out,"NEXTPROTO is ");
    BIO_write(bio_s_out,puStack_2034,local_2030);
    BIO_printf(bio_s_out,"\n");
  }
  pSVar7 = SSL_get_selected_srtp_profile(param_1);
  if (pSVar7 != (SRTP_PROTECTION_PROFILE *)0x0) {
    BIO_printf(bio_s_out,"SRTP Extension negotiated, profile=%s\n",pSVar7->name);
  }
  iVar2 = SSL_cache_hit(param_1);
  if (iVar2 != 0) {
    BIO_printf(bio_s_out,"Reused session-id\n");
  }
  lVar8 = SSL_ctrl(param_1,0xd,0,(void *)0x0);
  if (lVar8 << 0x1c < 0) {
    BIO_printf(bio_s_out,"Peer has incorrect TLSv1 block padding\n");
  }
  pBVar1 = bio_s_out;
  lVar8 = SSL_ctrl(param_1,0x4c,0,(void *)0x0);
  pcVar5 = " NOT";
  if (lVar8 != 0) {
    pcVar5 = "";
  }
  BIO_printf(pBVar1,"Secure Renegotiation IS%s supported\n",pcVar5);
  if (keymatexportlabel != (char *)0x0) {
    BIO_printf(bio_s_out,"Keying material exporter:\n");
    BIO_printf(bio_s_out,"    Label: \'%s\'\n",keymatexportlabel);
    BIO_printf(bio_s_out,"    Length: %i bytes\n",keymatexportlen);
    ptr = CRYPTO_malloc(keymatexportlen,"s_server.c",0x9b0);
    pcVar5 = keymatexportlabel;
    if (ptr != (void *)0x0) {
      iVar3 = 0;
      sVar9 = strlen(keymatexportlabel);
      iVar2 = SSL_export_keying_material(param_1,ptr,keymatexportlen,pcVar5,sVar9,0,0,0);
      if (iVar2 == 0) {
        BIO_printf(bio_s_out,"    Error\n");
      }
      else {
        BIO_printf(bio_s_out,"    Keying material: ");
        if (0 < keymatexportlen) {
          do {
            BIO_printf(bio_s_out,"%02X",(uint)*(byte *)((int)ptr + iVar3));
            iVar3 = iVar3 + 1;
          } while (iVar3 < keymatexportlen);
        }
        BIO_printf(bio_s_out,"\n");
      }
      iVar2 = 1;
      CRYPTO_free(ptr);
      goto LAB_00026782;
    }
  }
  iVar2 = 1;
LAB_00026782:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}

