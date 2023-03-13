
int X509_STORE_CTX_purpose_inherit(X509_STORE_CTX *ctx,int def_purpose,int purpose,int trust)

{
  int iVar1;
  X509_PURPOSE *pXVar2;
  X509_VERIFY_PARAM *pXVar3;
  int line;
  
  if ((purpose == 0) && (purpose = def_purpose, def_purpose == 0)) {
    if (trust == 0) {
      return 1;
    }
    iVar1 = X509_TRUST_get_by_id(trust);
    if (iVar1 != -1) {
      pXVar3 = ctx->param;
      goto LAB_0815f3ec;
    }
LAB_0815f4b8:
    line = 0x82e;
    iVar1 = 0x78;
LAB_0815f477:
    ERR_put_error(0xb,0x86,iVar1,"x509_vfy.c",line);
    return 0;
  }
  iVar1 = X509_PURPOSE_get_by_id(purpose);
  if (iVar1 == -1) {
    line = 0x819;
    iVar1 = 0x79;
    goto LAB_0815f477;
  }
  pXVar2 = X509_PURPOSE_get0(iVar1);
  if (pXVar2->trust == -1) {
    iVar1 = X509_PURPOSE_get_by_id(def_purpose);
    if (iVar1 == -1) {
      line = 0x821;
      iVar1 = 0x79;
      goto LAB_0815f477;
    }
    pXVar2 = X509_PURPOSE_get0(iVar1);
  }
  if ((trust == 0) && (trust = pXVar2->trust, trust == 0)) {
    pXVar3 = ctx->param;
    if (pXVar3->purpose != 0) {
      return 1;
    }
  }
  else {
    iVar1 = X509_TRUST_get_by_id(trust);
    if (iVar1 == -1) goto LAB_0815f4b8;
    pXVar3 = ctx->param;
    if (pXVar3->purpose != 0) goto LAB_0815f3ec;
  }
  pXVar3->purpose = purpose;
  if (trust == 0) {
    return 1;
  }
LAB_0815f3ec:
  if (pXVar3->trust == 0) {
    pXVar3->trust = trust;
  }
  return 1;
}

