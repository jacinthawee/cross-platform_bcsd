
BIO * BIO_new_ssl_connect(SSL_CTX *ctx)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  SSL *s;
  BIO *pBVar4;
  
  uVar1 = (*(code *)PTR_BIO_s_connect_006a8be0)();
  iVar2 = (*(code *)PTR_BIO_new_006a7fa4)(uVar1);
  if (iVar2 == 0) {
    return (BIO *)0x0;
  }
  iVar3 = (*(code *)PTR_BIO_new_006a7fa4)(methods_sslp);
  if (iVar3 != 0) {
    s = SSL_new(ctx);
    if (s == (SSL *)0x0) {
      (*(code *)PTR_BIO_free_006a7f70)(iVar3);
    }
    else {
      SSL_set_connect_state(s);
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar3,0x6d,1,s);
      pBVar4 = (BIO *)(*(code *)PTR_BIO_push_006a85c0)(iVar3,iVar2);
      if (pBVar4 != (BIO *)0x0) {
        return pBVar4;
      }
    }
  }
  (*(code *)PTR_BIO_free_006a7f70)(iVar2);
  return (BIO *)0x0;
}

