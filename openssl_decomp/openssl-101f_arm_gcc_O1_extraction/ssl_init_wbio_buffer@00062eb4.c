
undefined4 ssl_init_wbio_buffer(int param_1,int param_2)

{
  long lVar1;
  BIO_METHOD *type;
  BIO *pBVar2;
  BIO *pBVar3;
  
  pBVar3 = *(BIO **)(param_1 + 0x14);
  if (pBVar3 == (BIO *)0x0) {
    type = BIO_f_buffer();
    pBVar3 = BIO_new(type);
    if (pBVar3 == (BIO *)0x0) {
      return 0;
    }
    *(BIO **)(param_1 + 0x14) = pBVar3;
  }
  else if (pBVar3 == *(BIO **)(param_1 + 0x10)) {
    pBVar2 = BIO_pop(pBVar3);
    *(BIO **)(param_1 + 0x10) = pBVar2;
  }
  BIO_ctrl(pBVar3,1,0,(void *)0x0);
  lVar1 = BIO_int_ctrl(pBVar3,0x75,1,0);
  if (lVar1 != 0) {
    if (param_2 == 0) {
      if (*(BIO **)(param_1 + 0x10) == pBVar3) {
        pBVar3 = BIO_pop(pBVar3);
        *(BIO **)(param_1 + 0x10) = pBVar3;
        return 1;
      }
    }
    else if (*(BIO **)(param_1 + 0x10) != pBVar3) {
      pBVar3 = BIO_push(pBVar3,*(BIO **)(param_1 + 0x10));
      *(BIO **)(param_1 + 0x10) = pBVar3;
      return 1;
    }
    return 1;
  }
  ERR_put_error(0x14,0xb8,7,"ssl_lib.c",0xb30);
  return 0;
}

