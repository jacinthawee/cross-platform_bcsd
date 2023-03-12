
int SSL_use_RSAPrivateKey_file(SSL *ssl,char *file,int type)

{
  BIO_METHOD *type_00;
  BIO *bp;
  long lVar1;
  RSA *r;
  RSA *pkey;
  RSA *pRVar2;
  int reason;
  
  type_00 = BIO_s_file();
  bp = BIO_new(type_00);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,0xce,7,"ssl_rsa.c",0xee);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    r = (RSA *)0x0;
    ERR_put_error(0x14,0xce,2,"ssl_rsa.c",0xf4);
  }
  else {
    if (type == 2) {
      r = d2i_RSAPrivateKey_bio(bp,(RSA **)0x0);
      reason = 0xd;
    }
    else {
      if (type != 1) {
        ERR_put_error(0x14,0xce,0x7c,"ssl_rsa.c",0x104);
        r = (RSA *)0x0;
        goto LAB_00068062;
      }
      r = PEM_read_bio_RSAPrivateKey
                    (bp,(RSA **)0x0,*(undefined1 **)(ssl->psk_server_callback + 0x6c),
                     *(void **)(ssl->psk_server_callback + 0x70));
      reason = 9;
    }
    if (r == (RSA *)0x0) {
      ERR_put_error(0x14,0xce,reason,"ssl_rsa.c",0x109);
    }
    else {
      pkey = (RSA *)ssl_cert_inst(&ssl->cert);
      if (pkey == (RSA *)0x0) {
        ERR_put_error(0x14,0xcc,0x41,"ssl_rsa.c",0xa4);
      }
      else {
        pkey = (RSA *)EVP_PKEY_new();
        if (pkey == (RSA *)0x0) {
          ERR_put_error(0x14,0xcc,6,"ssl_rsa.c",0xa9);
        }
        else {
          RSA_up_ref(r);
          EVP_PKEY_assign((EVP_PKEY *)pkey,6,r);
          pRVar2 = (RSA *)ssl_set_pkey(ssl->cert,pkey);
          EVP_PKEY_free((EVP_PKEY *)pkey);
          pkey = pRVar2;
        }
      }
      RSA_free(r);
      r = pkey;
    }
  }
LAB_00068062:
  BIO_free(bp);
  return (int)r;
}

