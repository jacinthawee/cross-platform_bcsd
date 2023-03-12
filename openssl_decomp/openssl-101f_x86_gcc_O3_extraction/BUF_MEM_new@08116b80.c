
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BUF_MEM * BUF_MEM_new(void)

{
  BUF_MEM *pBVar1;
  
  pBVar1 = (BUF_MEM *)CRYPTO_malloc(0xc,"buffer.c",0x48);
  if (pBVar1 == (BUF_MEM *)0x0) {
    ERR_put_error(7,0x65,0x41,"buffer.c",0x4b);
    pBVar1 = (BUF_MEM *)0x0;
  }
  else {
    pBVar1->length = 0;
    pBVar1->max = 0;
    pBVar1->data = (char *)0x0;
  }
  return pBVar1;
}
