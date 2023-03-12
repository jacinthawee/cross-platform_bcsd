
int SSL_use_PrivateKey_file(SSL *ssl,char *file,int type)

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
    ERR_put_error(0x14,0xcb,7,"ssl_rsa.c",0x143);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    pkey = (EVP_PKEY *)0x0;
    ERR_put_error(0x14,0xcb,2,"ssl_rsa.c",0x149);
  }
  else {
    if (type == 1) {
      pkey = PEM_read_bio_PrivateKey
                       (bp,(EVP_PKEY **)0x0,*(undefined1 **)(ssl->psk_server_callback + 0x6c),
                        *(void **)(ssl->psk_server_callback + 0x70));
      reason = 9;
    }
    else {
      if (type != 2) {
        ERR_put_error(0x14,0xcb,0x7c,"ssl_rsa.c",0x159);
        pkey = (EVP_PKEY *)0x0;
        goto LAB_0006837a;
      }
      pkey = d2i_PrivateKey_bio(bp,(EVP_PKEY **)0x0);
      reason = 0xd;
    }
    if (pkey == (EVP_PKEY *)0x0) {
      ERR_put_error(0x14,0xcb,reason,"ssl_rsa.c",0x15e);
    }
    else {
      pEVar2 = (EVP_PKEY *)ssl_cert_inst(&ssl->cert);
      if (pEVar2 == (EVP_PKEY *)0x0) {
        ERR_put_error(0x14,0xc9,0x41,"ssl_rsa.c",0x132);
      }
      else {
        pEVar2 = (EVP_PKEY *)ssl_set_pkey(ssl->cert,pkey);
      }
      EVP_PKEY_free(pkey);
      pkey = pEVar2;
    }
  }
LAB_0006837a:
  BIO_free(bp);
  return (int)pkey;
}

