
int SSL_use_certificate_file(SSL *ssl,char *file,int type)

{
  BIO_METHOD *type_00;
  BIO *bp;
  long lVar1;
  X509 *a;
  int iVar2;
  
  type_00 = BIO_s_file();
  bp = BIO_new(type_00);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,200,7,"ssl_rsa.c",0x5f);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    ERR_put_error(0x14,200,2,"ssl_rsa.c",0x65);
  }
  else {
    if (type == 2) {
      a = d2i_X509_bio(bp,(X509 **)0x0);
      iVar2 = 0xd;
    }
    else {
      if (type != 1) {
        ERR_put_error(0x14,200,0x7c,"ssl_rsa.c",0x74);
        goto LAB_00067e52;
      }
      a = PEM_read_bio_X509(bp,(X509 **)0x0,*(undefined1 **)(ssl->psk_server_callback + 0x6c),
                            *(void **)(ssl->psk_server_callback + 0x70));
      iVar2 = 9;
    }
    if (a != (X509 *)0x0) {
      iVar2 = ssl_cert_inst(&ssl->cert);
      if (iVar2 == 0) {
        ERR_put_error(0x14,0xc6,0x41,"ssl_rsa.c",0x4e);
      }
      else {
        iVar2 = ssl_set_cert(ssl->cert,a);
      }
      X509_free(a);
      goto LAB_00067e54;
    }
    ERR_put_error(0x14,200,iVar2,"ssl_rsa.c",0x7a);
  }
LAB_00067e52:
  iVar2 = 0;
LAB_00067e54:
  BIO_free(bp);
  return iVar2;
}

