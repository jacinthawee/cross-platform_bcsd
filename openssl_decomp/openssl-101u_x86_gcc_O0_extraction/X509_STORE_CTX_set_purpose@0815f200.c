
int X509_STORE_CTX_set_purpose(X509_STORE_CTX *ctx,int purpose)

{
  int iVar1;
  X509_PURPOSE *pXVar2;
  int iVar3;
  X509_VERIFY_PARAM *pXVar4;
  
  if (purpose == 0) {
    return 1;
  }
  iVar1 = X509_PURPOSE_get_by_id(purpose);
  if (iVar1 == -1) {
    iVar1 = 0x819;
LAB_0815f298:
    iVar3 = 0x79;
LAB_0815f29f:
    ERR_put_error(0xb,0x86,iVar3,"x509_vfy.c",iVar1);
    return 0;
  }
  pXVar2 = X509_PURPOSE_get0(iVar1);
  iVar1 = pXVar2->trust;
  if (iVar1 == -1) {
    iVar1 = X509_PURPOSE_get_by_id(0);
    if (iVar1 == -1) {
      iVar1 = 0x821;
      goto LAB_0815f298;
    }
    pXVar2 = X509_PURPOSE_get0(iVar1);
    iVar1 = pXVar2->trust;
  }
  if (iVar1 == 0) {
    pXVar4 = ctx->param;
    if (pXVar4->purpose != 0) {
      return 1;
    }
  }
  else {
    iVar3 = X509_TRUST_get_by_id(iVar1);
    if (iVar3 == -1) {
      iVar1 = 0x82e;
      iVar3 = 0x78;
      goto LAB_0815f29f;
    }
    pXVar4 = ctx->param;
    if (pXVar4->purpose != 0) goto LAB_0815f266;
  }
  pXVar4->purpose = purpose;
  if (iVar1 == 0) {
    return 1;
  }
LAB_0815f266:
  if (pXVar4->trust == 0) {
    pXVar4->trust = iVar1;
    return 1;
  }
  return 1;
}

