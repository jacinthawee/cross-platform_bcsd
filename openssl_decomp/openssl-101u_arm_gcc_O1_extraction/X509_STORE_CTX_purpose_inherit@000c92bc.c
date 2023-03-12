
int X509_STORE_CTX_purpose_inherit(X509_STORE_CTX *ctx,int def_purpose,int purpose,int trust)

{
  int iVar1;
  X509_PURPOSE *pXVar2;
  int iVar3;
  
  iVar3 = purpose;
  if ((purpose == 0) && (iVar3 = def_purpose, def_purpose == 0)) {
LAB_000c92ec:
    if (trust == 0) goto LAB_000c92ee;
  }
  else {
    iVar1 = X509_PURPOSE_get_by_id(iVar3);
    if (iVar1 == -1) {
      iVar3 = 0x819;
LAB_000c9344:
      ERR_put_error(0xb,0x86,0x79,"x509_vfy.c",iVar3);
      return 0;
    }
    pXVar2 = X509_PURPOSE_get0(iVar1);
    if (pXVar2->trust == -1) {
      iVar1 = X509_PURPOSE_get_by_id(def_purpose);
      if (iVar1 == -1) {
        iVar3 = 0x821;
        goto LAB_000c9344;
      }
      pXVar2 = X509_PURPOSE_get0(iVar1);
    }
    purpose = iVar3;
    if (trust == 0) {
      trust = pXVar2->trust;
      goto LAB_000c92ec;
    }
  }
  iVar3 = X509_TRUST_get_by_id(trust);
  if (iVar3 == -1) {
    ERR_put_error(0xb,0x86,0x78,"x509_vfy.c",0x82e);
    return 0;
  }
LAB_000c92ee:
  if ((purpose != 0) && (ctx->param->purpose == 0)) {
    ctx->param->purpose = purpose;
  }
  if ((trust != 0) && (ctx->param->trust == 0)) {
    ctx->param->trust = trust;
    return 1;
  }
  return 1;
}

