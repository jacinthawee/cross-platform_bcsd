
bool crl_extension_match(X509_CRL *param_1,X509_CRL *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  X509_EXTENSION *pXVar3;
  ASN1_OCTET_STRING *pAVar4;
  ASN1_OCTET_STRING *pAVar5;
  
  iVar1 = X509_CRL_get_ext_by_NID(param_1,param_3,-1);
  if (iVar1 < 0) {
    iVar1 = X509_CRL_get_ext_by_NID(param_2,param_3,-1);
    if (iVar1 < 0) {
      return true;
    }
    iVar2 = X509_CRL_get_ext_by_NID(param_2,param_3,iVar1);
    if (iVar2 == -1) {
      pXVar3 = X509_CRL_get_ext(param_2,iVar1);
      pAVar5 = X509_EXTENSION_get_data(pXVar3);
LAB_0057ae1c:
      return pAVar5 == (ASN1_OCTET_STRING *)0x0;
    }
  }
  else {
    iVar2 = X509_CRL_get_ext_by_NID(param_1,param_3,iVar1);
    if (iVar2 == -1) {
      pXVar3 = X509_CRL_get_ext(param_1,iVar1);
      pAVar4 = X509_EXTENSION_get_data(pXVar3);
      iVar1 = X509_CRL_get_ext_by_NID(param_2,param_3,-1);
      if (iVar1 < 0) {
        return pAVar4 == (ASN1_OCTET_STRING *)0x0;
      }
      iVar2 = X509_CRL_get_ext_by_NID(param_2,param_3,iVar1);
      if (iVar2 == -1) {
        pXVar3 = X509_CRL_get_ext(param_2,iVar1);
        pAVar5 = X509_EXTENSION_get_data(pXVar3);
        if (pAVar4 == (ASN1_OCTET_STRING *)0x0) goto LAB_0057ae1c;
        if (pAVar5 != (ASN1_OCTET_STRING *)0x0) {
          iVar1 = (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a9ffc)(pAVar4);
          return iVar1 == 0;
        }
      }
    }
  }
  return false;
}

