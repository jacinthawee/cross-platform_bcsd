
BIO * BIO_new_buffer_ssl_connect(SSL_CTX *ctx)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  SSL *s;
  BIO *pBVar5;
  
  uVar1 = (*(code *)PTR_BIO_f_buffer_006a7854)();
  iVar2 = (*(code *)PTR_BIO_new_006a6ea4)(uVar1);
  if (iVar2 != 0) {
    uVar1 = (*(code *)PTR_BIO_s_connect_006a7af4)();
    iVar3 = (*(code *)PTR_BIO_new_006a6ea4)(uVar1);
    if (iVar3 != 0) {
      iVar4 = (*(code *)PTR_BIO_new_006a6ea4)(methods_sslp);
      if (iVar4 != 0) {
        s = SSL_new(ctx);
        if (s == (SSL *)0x0) {
          (*(code *)PTR_BIO_free_006a6e70)(iVar4);
        }
        else {
          SSL_set_connect_state(s);
          (*(code *)PTR_BIO_ctrl_006a6e18)(iVar4,0x6d,1,s);
          iVar4 = (*(code *)PTR_BIO_push_006a74c4)(iVar4,iVar3);
          if (iVar4 != 0) {
            pBVar5 = (BIO *)(*(code *)PTR_BIO_push_006a74c4)(iVar2,iVar4);
            if (pBVar5 == (BIO *)0x0) {
              (*(code *)PTR_BIO_free_006a6e70)(iVar2);
              (*(code *)PTR_BIO_free_006a6e70)(iVar4);
              pBVar5 = (BIO *)0x0;
            }
            return pBVar5;
          }
        }
      }
      (*(code *)PTR_BIO_free_006a6e70)(iVar3);
    }
    (*(code *)PTR_BIO_free_006a6e70)(iVar2);
  }
  return (BIO *)0x0;
}

