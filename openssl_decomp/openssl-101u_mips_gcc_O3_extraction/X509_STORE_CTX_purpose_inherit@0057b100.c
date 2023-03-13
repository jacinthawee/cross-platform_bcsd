
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
LAB_0057b290:
        uVar5 = 0x78;
        uVar4 = 0x82e;
        goto LAB_0057b248;
      }
      pXVar3 = ctx->param;
LAB_0057b1d4:
      if (pXVar3->trust == 0) {
        pXVar3->trust = trust;
      }
    }
LAB_0057b14c:
    iVar1 = 1;
  }
  else {
    iVar1 = X509_PURPOSE_get_by_id(purpose);
    if (iVar1 == -1) {
      uVar5 = 0x79;
      uVar4 = 0x819;
    }
    else {
      pXVar2 = X509_PURPOSE_get0(iVar1);
      if (pXVar2->trust != -1) {
        if (trust == 0) {
          trust = pXVar2->trust;
LAB_0057b1b4:
          if (trust != 0) goto LAB_0057b208;
          pXVar3 = ctx->param;
          if (pXVar3->purpose != 0) goto LAB_0057b14c;
        }
        else {
LAB_0057b208:
          iVar1 = X509_TRUST_get_by_id(trust);
          if (iVar1 == -1) goto LAB_0057b290;
          pXVar3 = ctx->param;
          if (pXVar3->purpose != 0) goto LAB_0057b1d4;
        }
        pXVar3->purpose = purpose;
        if (trust != 0) goto LAB_0057b1d4;
        goto LAB_0057b14c;
      }
      iVar1 = X509_PURPOSE_get_by_id(def_purpose);
      if (iVar1 != -1) {
        pXVar2 = X509_PURPOSE_get0(iVar1);
        if (trust == 0) {
          trust = pXVar2->trust;
          goto LAB_0057b1b4;
        }
        goto LAB_0057b208;
      }
      uVar5 = 0x79;
      uVar4 = 0x821;
    }
LAB_0057b248:
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x86,uVar5,"x509_vfy.c",uVar4);
    iVar1 = 0;
  }
  return iVar1;
}

