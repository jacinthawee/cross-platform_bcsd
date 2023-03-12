
int EVP_CIPHER_CTX_ctrl(EVP_CIPHER_CTX *ctx,int type,int arg,void *ptr)

{
  EVP_CIPHER *pEVar1;
  
  pEVar1 = ctx->cipher;
  if (pEVar1 == (EVP_CIPHER *)0x0) {
    ERR_put_error(6,0x7c,0x83,"evp_enc.c",0x255);
  }
  else {
    pEVar1 = (EVP_CIPHER *)pEVar1->ctrl;
    if (pEVar1 == (EVP_CIPHER *)0x0) {
      ERR_put_error(6,0x7c,0x84,"evp_enc.c",0x25a);
    }
    else {
      pEVar1 = (EVP_CIPHER *)(*(code *)pEVar1)();
      if (pEVar1 == (EVP_CIPHER *)0xffffffff) {
        ERR_put_error(6,0x7c,0x85,"evp_enc.c",0x261);
        return 0;
      }
    }
  }
  return (int)pEVar1;
}

