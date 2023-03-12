
int SSL_use_RSAPrivateKey_file(SSL *ssl,char *file,int type)

{
  BIO_METHOD *type_00;
  BIO *bp;
  long lVar1;
  RSA *r;
  EVP_PKEY *pkey;
  int iVar2;
  int iVar3;
  int iVar4;
  
  type_00 = BIO_s_file();
  bp = BIO_new(type_00);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,0xce,7,"ssl_rsa.c",0xee);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    iVar4 = 0xf4;
    iVar3 = 2;
  }
  else {
    if (type == 2) {
      r = d2i_RSAPrivateKey_bio(bp,(RSA **)0x0);
      iVar3 = 0xd;
    }
    else {
      if (type != 1) {
        iVar4 = 0x104;
        iVar3 = 0x7c;
        goto LAB_080cb9ac;
      }
      r = PEM_read_bio_RSAPrivateKey
                    (bp,(RSA **)0x0,*(undefined1 **)(ssl->psk_server_callback + 0x6c),
                     *(void **)(ssl->psk_server_callback + 0x70));
      iVar3 = 9;
    }
    if (r != (RSA *)0x0) {
      iVar3 = ssl_cert_inst(&ssl->cert);
      if (iVar3 == 0) {
        iVar4 = 0xa4;
        iVar3 = 0x41;
LAB_080cbaef:
        iVar2 = 0;
        ERR_put_error(0x14,0xcc,iVar3,"ssl_rsa.c",iVar4);
      }
      else {
        pkey = EVP_PKEY_new();
        if (pkey == (EVP_PKEY *)0x0) {
          iVar4 = 0xa9;
          iVar3 = 6;
          goto LAB_080cbaef;
        }
        RSA_up_ref(r);
        EVP_PKEY_assign(pkey,6,r);
        iVar2 = ssl_set_pkey();
        EVP_PKEY_free(pkey);
      }
      RSA_free(r);
      goto LAB_080cb9bd;
    }
    iVar4 = 0x109;
  }
LAB_080cb9ac:
  iVar2 = 0;
  ERR_put_error(0x14,0xce,iVar3,"ssl_rsa.c",iVar4);
LAB_080cb9bd:
  BIO_free(bp);
  return iVar2;
}

