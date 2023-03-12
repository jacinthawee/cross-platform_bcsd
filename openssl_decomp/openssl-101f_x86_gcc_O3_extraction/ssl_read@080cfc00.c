
int ssl_read(BIO *param_1,void *param_2,int param_3)

{
  SSL **ppSVar1;
  SSL *ssl;
  int ret_code;
  int iVar2;
  SSL *pSVar3;
  
  if (param_2 == (void *)0x0) {
    return 0;
  }
  ppSVar1 = (SSL **)param_1->ptr;
  ssl = *ppSVar1;
  BIO_clear_flags(param_1,0xf);
  ret_code = SSL_read(ssl,param_2,param_3);
  iVar2 = SSL_get_error(ssl,ret_code);
  switch(iVar2) {
  case 0:
    if (0 < ret_code) {
      if (ppSVar1[2] == (SSL *)0x0) {
LAB_080cfc93:
        if ((ppSVar1[4] == (SSL *)0x0) ||
           (pSVar3 = (SSL *)time((time_t *)0x0),
           pSVar3 <= (SSL *)((int)&ppSVar1[5]->version + (int)&ppSVar1[4]->version)))
        goto switchD_080cfc47_caseD_1;
        ppSVar1[5] = pSVar3;
      }
      else {
        pSVar3 = (SSL *)((int)&ppSVar1[3]->version + ret_code);
        if (pSVar3 <= ppSVar1[2]) {
          ppSVar1[3] = pSVar3;
          goto LAB_080cfc93;
        }
        ppSVar1[3] = (SSL *)0x0;
      }
      ppSVar1[1] = (SSL *)((int)&ppSVar1[1]->version + 1);
      SSL_renegotiate(ssl);
      iVar2 = 0;
      break;
    }
  default:
switchD_080cfc47_caseD_1:
    iVar2 = 0;
    break;
  case 2:
    BIO_set_flags(param_1,9);
    iVar2 = 0;
    break;
  case 3:
    BIO_set_flags(param_1,10);
    iVar2 = 0;
    break;
  case 4:
    BIO_set_flags(param_1,0xc);
    iVar2 = 1;
    break;
  case 7:
    BIO_set_flags(param_1,0xc);
    iVar2 = 2;
    break;
  case 8:
    BIO_set_flags(param_1,0xc);
    iVar2 = 3;
  }
  param_1->retry_reason = iVar2;
  return ret_code;
}

