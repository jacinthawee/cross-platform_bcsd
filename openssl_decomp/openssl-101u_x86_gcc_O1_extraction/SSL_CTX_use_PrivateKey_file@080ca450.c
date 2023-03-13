
int SSL_CTX_use_PrivateKey_file(SSL_CTX *ctx,char *file,int type)

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
    ERR_put_error(0x14,0xb0,7,"ssl_rsa.c",0x266);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    line = 0x26b;
    iVar3 = 2;
  }
  else {
    if (type == 1) {
      pkey = PEM_read_bio_PrivateKey
                       (bp,(EVP_PKEY **)0x0,ctx->default_passwd_callback,
                        ctx->default_passwd_callback_userdata);
      iVar3 = 9;
    }
    else {
      if (type != 2) {
        line = 0x277;
        iVar3 = 0x7c;
        goto LAB_080ca4a8;
      }
      pkey = d2i_PrivateKey_bio(bp,(EVP_PKEY **)0x0);
      iVar3 = 0xd;
    }
    if (pkey != (EVP_PKEY *)0x0) {
      iVar3 = ssl_cert_inst(&ctx->cert);
      if (iVar3 == 0) {
        iVar2 = 0;
        ERR_put_error(0x14,0xae,0x41,"ssl_rsa.c",599);
      }
      else {
        iVar2 = ssl_set_pkey();
      }
      EVP_PKEY_free(pkey);
      goto LAB_080ca4b9;
    }
    line = 0x27b;
  }
LAB_080ca4a8:
  iVar2 = 0;
  ERR_put_error(0x14,0xb0,iVar3,"ssl_rsa.c",line);
LAB_080ca4b9:
  BIO_free(bp);
  return iVar2;
}

