
bool __regparm3 crl_extension_match(X509_CRL *param_1,X509_CRL *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  ASN1_OCTET_STRING *b;
  X509_EXTENSION *pXVar3;
  ASN1_OCTET_STRING *a;
  bool bVar4;
  
  iVar1 = X509_CRL_get_ext_by_NID(param_1,param_3,-1);
  if (iVar1 < 0) {
    a = (ASN1_STRING *)0x0;
    iVar1 = X509_CRL_get_ext_by_NID(param_2,param_3,-1);
    if (iVar1 < 0) {
      return true;
    }
  }
  else {
    iVar2 = X509_CRL_get_ext_by_NID(param_1,param_3,iVar1);
    if (iVar2 != -1) {
      return false;
    }
    pXVar3 = X509_CRL_get_ext(param_1,iVar1);
    a = X509_EXTENSION_get_data(pXVar3);
    iVar1 = X509_CRL_get_ext_by_NID(param_2,param_3,-1);
    if (iVar1 < 0) {
      bVar4 = a == (ASN1_OCTET_STRING *)0x0;
      goto joined_r0x0815c8aa;
    }
  }
  iVar2 = X509_CRL_get_ext_by_NID(param_2,param_3,iVar1);
  if (iVar2 != -1) {
    return false;
  }
  pXVar3 = X509_CRL_get_ext(param_2,iVar1);
  b = X509_EXTENSION_get_data(pXVar3);
  bVar4 = b == (ASN1_OCTET_STRING *)0x0;
  if (a != (ASN1_STRING *)0x0) {
    if (bVar4) {
      return false;
    }
    iVar1 = ASN1_OCTET_STRING_cmp(a,b);
    return iVar1 == 0;
  }
joined_r0x0815c8aa:
  if (!bVar4) {
    return false;
  }
  return true;
}

