
int ssl_read(int param_1,void *param_2,int param_3)

{
  int ret_code;
  int iVar1;
  undefined4 uVar2;
  SSL *pSVar3;
  SSL *ssl;
  SSL **ppSVar4;
  
  if (param_2 == (void *)0x0) {
    return 0;
  }
  ppSVar4 = *(SSL ***)(param_1 + 0x20);
  ssl = *ppSVar4;
  (*(code *)PTR_BIO_clear_flags_006a8138)(param_1,0xf);
  ret_code = SSL_read(ssl,param_2,param_3);
  iVar1 = SSL_get_error(ssl,ret_code);
  switch(iVar1) {
  case 0:
    if (0 < ret_code) {
      if (ppSVar4[2] != (SSL *)0x0) {
        pSVar3 = (SSL *)((int)&ppSVar4[3]->version + ret_code);
        if (ppSVar4[2] < pSVar3) {
          ppSVar4[3] = (SSL *)0x0;
          ppSVar4[1] = (SSL *)((int)&ppSVar4[1]->version + 1);
          SSL_renegotiate(ssl);
          uVar2 = 0;
          goto LAB_004b9c98;
        }
        ppSVar4[3] = pSVar3;
      }
      if ((ppSVar4[4] != (SSL *)0x0) &&
         (pSVar3 = (SSL *)(*(code *)PTR_time_006a9adc)(0),
         (SSL *)((int)&ppSVar4[4]->version + (int)&ppSVar4[5]->version) < pSVar3)) {
        ppSVar4[5] = pSVar3;
        ppSVar4[1] = (SSL *)((int)&ppSVar4[1]->version + 1);
        SSL_renegotiate(ssl);
        uVar2 = 0;
        goto LAB_004b9c98;
      }
    }
    break;
  case 2:
    (*(code *)PTR_BIO_set_flags_006a7570)(param_1,9);
    *(undefined4 *)(param_1 + 0x18) = 0;
    return ret_code;
  case 3:
    (*(code *)PTR_BIO_set_flags_006a7570)(param_1,10);
    *(undefined4 *)(param_1 + 0x18) = 0;
    return ret_code;
  case 4:
    (*(code *)PTR_BIO_set_flags_006a7570)(param_1,0xc);
    *(undefined4 *)(param_1 + 0x18) = 1;
    return ret_code;
  case 7:
    (*(code *)PTR_BIO_set_flags_006a7570)(param_1,0xc);
    *(undefined4 *)(param_1 + 0x18) = 2;
    return ret_code;
  case 8:
    (*(code *)PTR_BIO_set_flags_006a7570)(param_1,0xc);
    uVar2 = 3;
LAB_004b9c98:
    *(undefined4 *)(param_1 + 0x18) = uVar2;
    return ret_code;
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  return ret_code;
}

