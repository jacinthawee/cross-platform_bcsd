
int SSL_CTX_use_certificate_chain_file(SSL_CTX *ctx,char *file)

{
  BIO_METHOD *type;
  BIO *bp;
  long lVar1;
  X509 *x;
  int iVar2;
  ulong uVar3;
  int iVar4;
  X509 *a;
  
  ERR_clear_error();
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,0xdc,7,"ssl_rsa.c",0x2aa);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    ERR_put_error(0x14,0xdc,2,"ssl_rsa.c",0x2af);
  }
  else {
    x = PEM_read_bio_X509_AUX
                  (bp,(X509 **)0x0,ctx->default_passwd_callback,
                   ctx->default_passwd_callback_userdata);
    if (x != (X509 *)0x0) {
      iVar2 = SSL_CTX_use_certificate(ctx,x);
      uVar3 = ERR_peek_error();
      if ((uVar3 == 0) && (iVar2 != 0)) {
        if ((_STACK *)ctx->extra_certs != (_STACK *)0x0) {
          sk_pop_free((_STACK *)ctx->extra_certs,X509_free);
          ctx->extra_certs = (stack_st_X509 *)0x0;
        }
        do {
          a = PEM_read_bio_X509(bp,(X509 **)0x0,ctx->default_passwd_callback,
                                ctx->default_passwd_callback_userdata);
          if (a == (X509 *)0x0) {
            uVar3 = ERR_peek_last_error();
            if ((uVar3 >> 0x18 != 9) || ((uVar3 & 0xfff) != 0x6c)) goto LAB_00066782;
            ERR_clear_error();
            iVar4 = iVar2;
            goto LAB_00066784;
          }
          iVar4 = SSL_CTX_ctrl(ctx,0xe,0,a);
        } while (iVar4 != 0);
        X509_free(a);
      }
      else {
LAB_00066782:
        iVar4 = 0;
      }
LAB_00066784:
      X509_free(x);
      goto LAB_0006678a;
    }
    ERR_put_error(0x14,0xdc,9,"ssl_rsa.c",0x2b6);
  }
  iVar4 = 0;
LAB_0006678a:
  BIO_free(bp);
  return iVar4;
}

