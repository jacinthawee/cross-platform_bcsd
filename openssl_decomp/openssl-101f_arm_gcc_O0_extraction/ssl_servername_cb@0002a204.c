
undefined4 ssl_servername_cb(SSL *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  iVar1 = SSL_get_servername(param_1,0);
  iVar2 = SSL_get_servername_type(param_1);
  if (iVar2 == -1) {
    BIO_printf(bio_err,"Can\'t use SSL_get_servername\n");
    return 0;
  }
  lVar3 = SSL_ctrl(param_1,8,0,(void *)0x0);
  if (lVar3 == 0) {
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  else {
    iVar1 = 0;
  }
  *(int *)(param_3 + 4) = iVar1;
  return 0;
}

