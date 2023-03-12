
BIO * BIO_new_ssl_connect(SSL_CTX *ctx)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  SSL *s;
  BIO *pBVar4;
  
  uVar1 = (*(code *)PTR_BIO_s_connect_006a7af4)();
  iVar2 = (*(code *)PTR_BIO_new_006a6ea4)(uVar1);
  if (iVar2 == 0) {
    return (BIO *)0x0;
  }
  iVar3 = (*(code *)PTR_BIO_new_006a6ea4)(methods_sslp);
  if (iVar3 != 0) {
    s = SSL_new(ctx);
    if (s == (SSL *)0x0) {
      (*(code *)PTR_BIO_free_006a6e70)(iVar3);
    }
    else {
      SSL_set_connect_state(s);
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar3,0x6d,1,s);
      pBVar4 = (BIO *)(*(code *)PTR_BIO_push_006a74c4)(iVar3,iVar2);
      if (pBVar4 != (BIO *)0x0) {
        return pBVar4;
      }
    }
  }
  (*(code *)PTR_BIO_free_006a6e70)(iVar2);
  return (BIO *)0x0;
}

