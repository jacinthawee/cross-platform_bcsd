
int SSL_CTX_use_RSAPrivateKey_file(SSL_CTX *ctx,char *file,int type)

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
    ERR_put_error(0x14,0xb3,7,"ssl_rsa.c",0x230);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    iVar4 = 0x236;
    iVar3 = 2;
  }
  else {
    if (type == 2) {
      r = d2i_RSAPrivateKey_bio(bp,(RSA **)0x0);
      iVar3 = 0xd;
    }
    else {
      if (type != 1) {
        iVar4 = 0x246;
        iVar3 = 0x7c;
        goto LAB_080cc6bc;
      }
      r = PEM_read_bio_RSAPrivateKey
                    (bp,(RSA **)0x0,ctx->default_passwd_callback,
                     ctx->default_passwd_callback_userdata);
      iVar3 = 9;
    }
    if (r != (RSA *)0x0) {
      iVar3 = ssl_cert_inst(&ctx->cert);
      if (iVar3 == 0) {
        iVar4 = 0x215;
        iVar3 = 0x41;
LAB_080cc7f7:
        iVar2 = 0;
        ERR_put_error(0x14,0xb1,iVar3,"ssl_rsa.c",iVar4);
      }
      else {
        pkey = EVP_PKEY_new();
        if (pkey == (EVP_PKEY *)0x0) {
          iVar4 = 0x21a;
          iVar3 = 6;
          goto LAB_080cc7f7;
        }
        RSA_up_ref(r);
        EVP_PKEY_assign(pkey,6,r);
        iVar2 = ssl_set_pkey();
        EVP_PKEY_free(pkey);
      }
      RSA_free(r);
      goto LAB_080cc6cd;
    }
    iVar4 = 0x24b;
  }
LAB_080cc6bc:
  iVar2 = 0;
  ERR_put_error(0x14,0xb3,iVar3,"ssl_rsa.c",iVar4);
LAB_080cc6cd:
  BIO_free(bp);
  return iVar2;
}

