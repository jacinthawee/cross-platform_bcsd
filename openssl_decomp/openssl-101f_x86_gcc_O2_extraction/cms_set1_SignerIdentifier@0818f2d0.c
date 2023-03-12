
undefined4 cms_set1_SignerIdentifier(int *param_1,X509 *param_2,int param_3)

{
  ASN1_STRING *pAVar1;
  ASN1_VALUE *pAVar2;
  X509_NAME *name;
  ASN1_INTEGER *str;
  int iVar3;
  int line;
  
  if (param_3 == 0) {
    pAVar2 = ASN1_item_new((ASN1_ITEM *)CMS_IssuerAndSerialNumber_it);
    param_1[1] = (int)pAVar2;
    if (pAVar2 != (ASN1_VALUE *)0x0) {
      name = X509_get_issuer_name(param_2);
      iVar3 = X509_NAME_set((X509_NAME **)param_1[1],name);
      if (iVar3 != 0) {
        str = X509_get_serialNumber(param_2);
        pAVar1 = (ASN1_STRING *)ASN1_STRING_copy(*(ASN1_STRING **)(param_1[1] + 4),str);
        goto joined_r0x0818f3af;
      }
    }
  }
  else {
    if (param_3 != 1) {
      line = 0xf1;
      iVar3 = 0x96;
      goto LAB_0818f32a;
    }
    if (param_2->skid == (ASN1_STRING *)0x0) {
      line = 0xe8;
      iVar3 = 0xa0;
      goto LAB_0818f32a;
    }
    pAVar1 = ASN1_STRING_dup(param_2->skid);
    param_1[1] = (int)pAVar1;
joined_r0x0818f3af:
    if (pAVar1 != (ASN1_STRING *)0x0) {
      *param_1 = param_3;
      return 1;
    }
  }
  line = 0xfa;
  iVar3 = 0x41;
LAB_0818f32a:
  ERR_put_error(0x2e,0x92,iVar3,"cms_sd.c",line);
  return 0;
}

