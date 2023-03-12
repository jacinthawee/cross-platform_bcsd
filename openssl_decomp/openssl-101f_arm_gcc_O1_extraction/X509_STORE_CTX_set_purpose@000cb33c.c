
int X509_STORE_CTX_set_purpose(X509_STORE_CTX *ctx,int purpose)

{
  int iVar1;
  X509_PURPOSE *pXVar2;
  int iVar3;
  X509_VERIFY_PARAM *pXVar4;
  
  if (purpose != 0) {
    iVar1 = X509_PURPOSE_get_by_id(purpose);
    if (iVar1 == -1) {
      iVar1 = 0x7a2;
LAB_000cb38c:
      ERR_put_error(0xb,0x86,0x79,"x509_vfy.c",iVar1);
      return 0;
    }
    pXVar2 = X509_PURPOSE_get0(iVar1);
    iVar1 = pXVar2->trust;
    if (iVar1 == -1) {
      iVar1 = X509_PURPOSE_get_by_id(0);
      if (iVar1 == -1) {
        iVar1 = 0x7ac;
        goto LAB_000cb38c;
      }
      pXVar2 = X509_PURPOSE_get0(iVar1);
      iVar1 = pXVar2->trust;
    }
    if ((iVar1 != 0) && (iVar3 = X509_TRUST_get_by_id(iVar1), iVar3 == -1)) {
      ERR_put_error(0xb,0x86,0x78,"x509_vfy.c",0x7ba);
      return 0;
    }
    pXVar4 = ctx->param;
    if (pXVar4->purpose == 0) {
      pXVar4->purpose = purpose;
    }
    if ((iVar1 != 0) && (pXVar4->trust == 0)) {
      pXVar4->trust = iVar1;
      return 1;
    }
  }
  return 1;
}

