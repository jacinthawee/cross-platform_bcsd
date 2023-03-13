
undefined4 ssl_init_wbio_buffer(int param_1,int param_2)

{
  long lVar1;
  BIO *pBVar2;
  BIO_METHOD *type;
  BIO *pBVar3;
  
  pBVar2 = *(BIO **)(param_1 + 0x14);
  if (pBVar2 == (BIO *)0x0) {
    type = BIO_f_buffer();
    pBVar2 = BIO_new(type);
    if (pBVar2 == (BIO *)0x0) {
      return 0;
    }
    *(BIO **)(param_1 + 0x14) = pBVar2;
  }
  else if (pBVar2 == *(BIO **)(param_1 + 0x10)) {
    pBVar3 = BIO_pop(pBVar2);
    *(BIO **)(param_1 + 0x10) = pBVar3;
  }
  BIO_ctrl(pBVar2,1,0,(void *)0x0);
  lVar1 = BIO_int_ctrl(pBVar2,0x75,1,0);
  if (lVar1 != 0) {
    if (param_2 == 0) {
      if (pBVar2 == *(BIO **)(param_1 + 0x10)) {
        pBVar2 = BIO_pop(pBVar2);
        *(BIO **)(param_1 + 0x10) = pBVar2;
      }
    }
    else if (pBVar2 != *(BIO **)(param_1 + 0x10)) {
      pBVar2 = BIO_push(pBVar2,*(BIO **)(param_1 + 0x10));
      *(BIO **)(param_1 + 0x10) = pBVar2;
      return 1;
    }
    return 1;
  }
  ERR_put_error(0x14,0xb8,7,"ssl_lib.c",0xb2f);
  return 0;
}

