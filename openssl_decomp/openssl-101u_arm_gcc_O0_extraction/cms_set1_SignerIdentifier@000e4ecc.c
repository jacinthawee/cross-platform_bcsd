
undefined4 cms_set1_SignerIdentifier(int *param_1,X509 *param_2,int param_3)

{
  ASN1_STRING *pAVar1;
  X509_NAME **xn;
  X509_NAME *name;
  int iVar2;
  ASN1_INTEGER *str;
  
  if (param_3 == 0) {
    xn = (X509_NAME **)ASN1_item_new((ASN1_ITEM *)CMS_IssuerAndSerialNumber_it);
    param_1[1] = (int)xn;
    if (xn == (X509_NAME **)0x0) goto LAB_000e4f32;
    name = X509_get_issuer_name(param_2);
    iVar2 = X509_NAME_set(xn,name);
    if (iVar2 == 0) goto LAB_000e4f32;
    pAVar1 = *(ASN1_STRING **)(param_1[1] + 4);
    str = X509_get_serialNumber(param_2);
    pAVar1 = (ASN1_STRING *)ASN1_STRING_copy(pAVar1,str);
  }
  else {
    if (param_3 != 1) {
      ERR_put_error(0x2e,0x92,0x96,"cms_sd.c",0xe0);
      return 0;
    }
    if (param_2->skid == (ASN1_STRING *)0x0) {
      ERR_put_error(0x2e,0x92,0xa0,"cms_sd.c",0xd7);
      return 0;
    }
    pAVar1 = ASN1_STRING_dup(param_2->skid);
    param_1[1] = (int)pAVar1;
  }
  if (pAVar1 != (ASN1_STRING *)0x0) {
    *param_1 = param_3;
    return 1;
  }
LAB_000e4f32:
  ERR_put_error(0x2e,0x92,0x41,"cms_sd.c",0xe9);
  return 0;
}

