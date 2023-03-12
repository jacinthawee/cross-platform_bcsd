
int dtls1_min_mtu(SSL *param_1)

{
  BIO *pBVar1;
  int iVar2;
  
  pBVar1 = SSL_get_wbio(param_1);
  iVar2 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar1,0x31,0,0);
  return 0x100 - iVar2;
}

