
int SSL_CTX_use_PrivateKey_file(SSL_CTX *ctx,char *file,int type)

{
  BIO_METHOD *type_00;
  BIO *bp;
  long lVar1;
  EVP_PKEY *pkey;
  EVP_PKEY *pEVar2;
  int reason;
  
  type_00 = BIO_s_file();
  bp = BIO_new(type_00);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,0xb0,7,"ssl_rsa.c",0x282);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    pkey = (EVP_PKEY *)0x0;
    ERR_put_error(0x14,0xb0,2,"ssl_rsa.c",0x288);
  }
  else {
    if (type == 1) {
      pkey = PEM_read_bio_PrivateKey
                       (bp,(EVP_PKEY **)0x0,ctx->default_passwd_callback,
                        ctx->default_passwd_callback_userdata);
      reason = 9;
    }
    else {
      if (type != 2) {
        ERR_put_error(0x14,0xb0,0x7c,"ssl_rsa.c",0x298);
        pkey = (EVP_PKEY *)0x0;
        goto LAB_00068b76;
      }
      pkey = d2i_PrivateKey_bio(bp,(EVP_PKEY **)0x0);
      reason = 0xd;
    }
    if (pkey == (EVP_PKEY *)0x0) {
      ERR_put_error(0x14,0xb0,reason,"ssl_rsa.c",0x29d);
    }
    else {
      pEVar2 = (EVP_PKEY *)ssl_cert_inst(&ctx->cert);
      if (pEVar2 == (EVP_PKEY *)0x0) {
        ERR_put_error(0x14,0xae,0x41,"ssl_rsa.c",0x272);
      }
      else {
        pEVar2 = (EVP_PKEY *)ssl_set_pkey(ctx->cert,pkey);
      }
      EVP_PKEY_free(pkey);
      pkey = pEVar2;
    }
  }
LAB_00068b76:
  BIO_free(bp);
  return (int)pkey;
}

