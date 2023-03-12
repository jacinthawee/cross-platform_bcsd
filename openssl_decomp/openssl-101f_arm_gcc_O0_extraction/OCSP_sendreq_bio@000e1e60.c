
OCSP_RESPONSE * OCSP_sendreq_bio(BIO *b,char *path,OCSP_REQUEST *req)

{
  OCSP_REQ_CTX *rctx;
  int iVar1;
  int iVar2;
  OCSP_RESPONSE *local_1c [2];
  
  local_1c[0] = (OCSP_RESPONSE *)0x0;
  rctx = OCSP_sendreq_new(b,path,req,-1);
  do {
    iVar2 = OCSP_sendreq_nbio(local_1c,rctx);
    if (iVar2 != -1) break;
    iVar1 = BIO_test_flags(b,8);
  } while (iVar1 != 0);
  if (*(BIO **)(rctx + 0x10) != (BIO *)0x0) {
    BIO_free(*(BIO **)(rctx + 0x10));
  }
  if (*(void **)(rctx + 4) != (void *)0x0) {
    CRYPTO_free(*(void **)(rctx + 4));
  }
  CRYPTO_free(rctx);
  if (iVar2 != 0) {
    return local_1c[0];
  }
  return (OCSP_RESPONSE *)0x0;
}

