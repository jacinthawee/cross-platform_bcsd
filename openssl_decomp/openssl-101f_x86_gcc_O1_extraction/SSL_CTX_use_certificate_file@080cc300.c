
int SSL_CTX_use_certificate_file(SSL_CTX *ctx,char *file,int type)

{
  BIO_METHOD *type_00;
  BIO *bp;
  long lVar1;
  X509 *a;
  int iVar2;
  
  type_00 = BIO_s_file();
  bp = BIO_new(type_00);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,0xad,7,"ssl_rsa.c",0x1d0);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    ERR_put_error(0x14,0xad,2,"ssl_rsa.c",0x1d6);
  }
  else {
    if (type == 2) {
      a = d2i_X509_bio(bp,(X509 **)0x0);
      iVar2 = 0xd;
    }
    else {
      if (type != 1) {
        ERR_put_error(0x14,0xad,0x7c,"ssl_rsa.c",0x1e5);
        goto LAB_080cc367;
      }
      a = PEM_read_bio_X509(bp,(X509 **)0x0,ctx->default_passwd_callback,
                            ctx->default_passwd_callback_userdata);
      iVar2 = 9;
    }
    if (a != (X509 *)0x0) {
      iVar2 = ssl_cert_inst(&ctx->cert);
      if (iVar2 == 0) {
        iVar2 = 0;
        ERR_put_error(0x14,0xab,0x41,"ssl_rsa.c",0x184);
      }
      else {
        iVar2 = ssl_set_cert();
      }
      X509_free(a);
      goto LAB_080cc369;
    }
    ERR_put_error(0x14,0xad,iVar2,"ssl_rsa.c",0x1eb);
  }
LAB_080cc367:
  iVar2 = 0;
LAB_080cc369:
  BIO_free(bp);
  return iVar2;
}
