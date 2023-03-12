
int dtls1_listen(SSL *param_1,undefined4 param_2)

{
  int iVar1;
  BIO *pBVar2;
  
  SSL_ctrl(param_1,0x20,0x2000,(void *)0x0);
  param_1->d1->mtu = 1;
  iVar1 = SSL_accept(param_1);
  if (0 < iVar1) {
    pBVar2 = SSL_get_rbio(param_1);
    (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar2,0x2e,0,param_2);
    iVar1 = 1;
  }
  return iVar1;
}

