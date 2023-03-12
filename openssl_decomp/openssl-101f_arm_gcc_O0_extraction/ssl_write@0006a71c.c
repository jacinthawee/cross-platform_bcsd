
int ssl_write(BIO *param_1,void *param_2,int param_3)

{
  int ret_code;
  int iVar1;
  SSL *pSVar2;
  SSL *ssl;
  SSL **ppSVar3;
  
  if (param_2 == (void *)0x0) {
    return 0;
  }
  ppSVar3 = (SSL **)param_1->ptr;
  ssl = *ppSVar3;
  BIO_clear_flags(param_1,0xf);
  ret_code = SSL_write(ssl,param_2,param_3);
  iVar1 = SSL_get_error(ssl,ret_code);
  switch(iVar1) {
  case 0:
    if (0 < ret_code) {
      if (ppSVar3[2] != (SSL *)0x0) {
        pSVar2 = (SSL *)((int)&ppSVar3[3]->version + ret_code);
        if (ppSVar3[2] < pSVar2) {
          iVar1 = 0;
          ppSVar3[3] = (SSL *)0x0;
          ppSVar3[1] = (SSL *)((int)&ppSVar3[1]->version + 1);
          SSL_renegotiate(ssl);
          goto LAB_0006a766;
        }
        ppSVar3[3] = pSVar2;
      }
      if ((ppSVar3[4] != (SSL *)0x0) &&
         (pSVar2 = (SSL *)time((time_t *)0x0),
         (SSL *)((int)&ppSVar3[4]->version + (int)&ppSVar3[5]->version) < pSVar2)) {
        ppSVar3[5] = pSVar2;
        ppSVar3[1] = (SSL *)((int)&ppSVar3[1]->version + 1);
        SSL_renegotiate(ssl);
        iVar1 = 0;
        goto LAB_0006a766;
      }
    }
    break;
  case 2:
    BIO_set_flags(param_1,9);
    param_1->retry_reason = 0;
    return ret_code;
  case 3:
    BIO_set_flags(param_1,10);
    param_1->retry_reason = 0;
    return ret_code;
  case 4:
    BIO_set_flags(param_1,0xc);
    param_1->retry_reason = 1;
    return ret_code;
  case 7:
    BIO_set_flags(param_1,0xc);
    iVar1 = 2;
LAB_0006a766:
    param_1->retry_reason = iVar1;
    return ret_code;
  }
  param_1->retry_reason = 0;
  return ret_code;
}

