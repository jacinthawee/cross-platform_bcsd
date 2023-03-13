
OCSP_RESPONSE * OCSP_sendreq_bio(BIO *b,char *path,OCSP_REQUEST *req)

{
  OCSP_REQ_CTX *rctx;
  int iVar1;
  int iVar2;
  OCSP_RESPONSE *pOVar3;
  int in_GS_OFFSET;
  OCSP_RESPONSE *local_24;
  int local_20;
  
  local_24 = (OCSP_RESPONSE *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  rctx = OCSP_sendreq_new(b,path,req,-1);
  if (rctx != (OCSP_REQ_CTX *)0x0) {
    do {
      iVar2 = OCSP_sendreq_nbio(&local_24,rctx);
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
    pOVar3 = local_24;
    if (iVar2 != 0) goto LAB_08185208;
  }
  pOVar3 = (OCSP_RESPONSE *)0x0;
LAB_08185208:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pOVar3;
}

