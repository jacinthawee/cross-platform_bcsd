
int SSL_CTX_use_certificate_chain_file(SSL_CTX *ctx,char *file)

{
  BIO_METHOD *type;
  BIO *bp;
  long lVar1;
  X509 *a;
  int iVar2;
  ulong uVar3;
  X509 *a_00;
  
  ERR_clear_error();
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,0xdc,7,"ssl_rsa.c",0x2cc);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    ERR_put_error(0x14,0xdc,2,"ssl_rsa.c",0x2d2);
  }
  else {
    a = PEM_read_bio_X509_AUX
                  (bp,(X509 **)0x0,ctx->default_passwd_callback,
                   ctx->default_passwd_callback_userdata);
    if (a != (X509 *)0x0) {
      iVar2 = ssl_cert_inst(&ctx->cert);
      if (iVar2 == 0) {
        iVar2 = 0;
        ERR_put_error(0x14,0xab,0x41,"ssl_rsa.c",0x184);
        ERR_peek_error();
      }
      else {
        iVar2 = ssl_set_cert();
        uVar3 = ERR_peek_error();
        if ((iVar2 == 0) || (uVar3 != 0)) {
LAB_080ccec0:
          iVar2 = 0;
        }
        else {
          if ((_STACK *)ctx->extra_certs != (_STACK *)0x0) {
            sk_pop_free((_STACK *)ctx->extra_certs,X509_free);
            ctx->extra_certs = (stack_st_X509 *)0x0;
          }
          do {
            a_00 = PEM_read_bio_X509(bp,(X509 **)0x0,ctx->default_passwd_callback,
                                     ctx->default_passwd_callback_userdata);
            if (a_00 == (X509 *)0x0) {
              uVar3 = ERR_peek_last_error();
              if ((uVar3 >> 0x18 != 9) || ((uVar3 & 0xfff) != 0x6c)) goto LAB_080ccec0;
              ERR_clear_error();
              goto LAB_080ccf25;
            }
            lVar1 = SSL_CTX_ctrl(ctx,0xe,0,a_00);
          } while (lVar1 != 0);
          iVar2 = 0;
          X509_free(a_00);
        }
      }
LAB_080ccf25:
      X509_free(a);
      goto LAB_080ccee8;
    }
    ERR_put_error(0x14,0xdc,9,"ssl_rsa.c",0x2da);
  }
  iVar2 = 0;
LAB_080ccee8:
  BIO_free(bp);
  return iVar2;
}

