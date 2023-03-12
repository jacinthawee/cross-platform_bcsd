
int SSL_use_PrivateKey_file(SSL *ssl,char *file,int type)

{
  BIO_METHOD *type_00;
  BIO *bp;
  long lVar1;
  EVP_PKEY *pkey;
  int iVar2;
  int iVar3;
  int line;
  
  type_00 = BIO_s_file();
  bp = BIO_new(type_00);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,0xcb,7,"ssl_rsa.c",0x143);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    line = 0x149;
    iVar3 = 2;
  }
  else {
    if (type == 1) {
      pkey = PEM_read_bio_PrivateKey
                       (bp,(EVP_PKEY **)0x0,*(undefined1 **)(ssl->psk_server_callback + 0x6c),
                        *(void **)(ssl->psk_server_callback + 0x70));
      iVar3 = 9;
    }
    else {
      if (type != 2) {
        line = 0x159;
        iVar3 = 0x7c;
        goto LAB_080cbea8;
      }
      pkey = d2i_PrivateKey_bio(bp,(EVP_PKEY **)0x0);
      iVar3 = 0xd;
    }
    if (pkey != (EVP_PKEY *)0x0) {
      iVar3 = ssl_cert_inst(&ssl->cert);
      if (iVar3 == 0) {
        iVar2 = 0;
        ERR_put_error(0x14,0xc9,0x41,"ssl_rsa.c",0x132);
      }
      else {
        iVar2 = ssl_set_pkey();
      }
      EVP_PKEY_free(pkey);
      goto LAB_080cbeb9;
    }
    line = 0x15e;
  }
LAB_080cbea8:
  iVar2 = 0;
  ERR_put_error(0x14,0xcb,iVar3,"ssl_rsa.c",line);
LAB_080cbeb9:
  BIO_free(bp);
  return iVar2;
}

