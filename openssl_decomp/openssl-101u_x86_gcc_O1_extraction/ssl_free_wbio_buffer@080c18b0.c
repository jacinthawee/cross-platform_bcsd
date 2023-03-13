
void ssl_free_wbio_buffer(int param_1)

{
  BIO *pBVar1;
  
  pBVar1 = *(BIO **)(param_1 + 0x14);
  if (pBVar1 != (BIO *)0x0) {
    if (pBVar1 == *(BIO **)(param_1 + 0x10)) {
      pBVar1 = BIO_pop(pBVar1);
      *(BIO **)(param_1 + 0x10) = pBVar1;
      pBVar1 = *(BIO **)(param_1 + 0x14);
    }
    BIO_free(pBVar1);
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}

