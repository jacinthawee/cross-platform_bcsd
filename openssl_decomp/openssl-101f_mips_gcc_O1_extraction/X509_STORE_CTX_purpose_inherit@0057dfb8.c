
int X509_STORE_CTX_purpose_inherit(X509_STORE_CTX *ctx,int def_purpose,int purpose,int trust)

{
  int iVar1;
  X509_PURPOSE *pXVar2;
  X509_VERIFY_PARAM *pXVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if ((purpose == 0) && (purpose = def_purpose, def_purpose == 0)) {
    if (trust != 0) {
      iVar1 = X509_TRUST_get_by_id(trust);
      if (iVar1 == -1) {
LAB_0057e148:
        uVar5 = 0x78;
        uVar4 = 0x7ba;
        goto LAB_0057e100;
      }
      pXVar3 = ctx->param;
LAB_0057e08c:
      if (pXVar3->trust == 0) {
        pXVar3->trust = trust;
      }
    }
LAB_0057e004:
    iVar1 = 1;
  }
  else {
    iVar1 = X509_PURPOSE_get_by_id(purpose);
    if (iVar1 == -1) {
      uVar5 = 0x79;
      uVar4 = 0x7a2;
    }
    else {
      pXVar2 = X509_PURPOSE_get0(iVar1);
      if (pXVar2->trust != -1) {
        if (trust == 0) {
          trust = pXVar2->trust;
LAB_0057e06c:
          if (trust != 0) goto LAB_0057e0c0;
          pXVar3 = ctx->param;
          if (pXVar3->purpose != 0) goto LAB_0057e004;
        }
        else {
LAB_0057e0c0:
          iVar1 = X509_TRUST_get_by_id(trust);
          if (iVar1 == -1) goto LAB_0057e148;
          pXVar3 = ctx->param;
          if (pXVar3->purpose != 0) goto LAB_0057e08c;
        }
        pXVar3->purpose = purpose;
        if (trust != 0) goto LAB_0057e08c;
        goto LAB_0057e004;
      }
      iVar1 = X509_PURPOSE_get_by_id(def_purpose);
      if (iVar1 != -1) {
        pXVar2 = X509_PURPOSE_get0(iVar1);
        if (trust == 0) {
          trust = pXVar2->trust;
          goto LAB_0057e06c;
        }
        goto LAB_0057e0c0;
      }
      uVar5 = 0x79;
      uVar4 = 0x7ac;
    }
LAB_0057e100:
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x86,uVar5,"x509_vfy.c",uVar4);
    iVar1 = 0;
  }
  return iVar1;
}

