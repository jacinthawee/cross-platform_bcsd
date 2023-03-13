
int X509_STORE_CTX_set_purpose(X509_STORE_CTX *ctx,int purpose)

{
  int iVar1;
  X509_PURPOSE *pXVar2;
  int iVar3;
  X509_VERIFY_PARAM *pXVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if (purpose == 0) {
    return 1;
  }
  iVar1 = X509_PURPOSE_get_by_id(purpose);
  if (iVar1 == -1) {
    uVar6 = 0x79;
    uVar5 = 0x819;
LAB_0057afe8:
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x86,uVar6,"x509_vfy.c",uVar5);
    iVar1 = 0;
  }
  else {
    pXVar2 = X509_PURPOSE_get0(iVar1);
    iVar1 = pXVar2->trust;
    if (iVar1 == -1) {
      iVar1 = X509_PURPOSE_get_by_id(0);
      if (iVar1 == -1) {
        uVar6 = 0x79;
        uVar5 = 0x821;
        goto LAB_0057afe8;
      }
      pXVar2 = X509_PURPOSE_get0(iVar1);
      iVar1 = pXVar2->trust;
    }
    if (iVar1 == 0) {
      pXVar4 = ctx->param;
      if (pXVar4->purpose != 0) {
        return 1;
      }
LAB_0057afac:
      pXVar4->purpose = purpose;
      if (iVar1 == 0) {
        return 1;
      }
    }
    else {
      iVar3 = X509_TRUST_get_by_id(iVar1);
      if (iVar3 == -1) {
        uVar6 = 0x78;
        uVar5 = 0x82e;
        goto LAB_0057afe8;
      }
      pXVar4 = ctx->param;
      if (pXVar4->purpose == 0) goto LAB_0057afac;
    }
    if (pXVar4->trust != 0) {
      return 1;
    }
    pXVar4->trust = iVar1;
    iVar1 = 1;
  }
  return iVar1;
}

