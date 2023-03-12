
uint crl_extension_match(X509_CRL *param_1,X509_CRL *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  ASN1_OCTET_STRING *b;
  X509_EXTENSION *pXVar3;
  ASN1_OCTET_STRING *a;
  uint uVar4;
  uint uVar5;
  
  iVar1 = X509_CRL_get_ext_by_NID(param_1,param_3,-1);
  if (iVar1 < 0) {
    a = (ASN1_STRING *)0x0;
  }
  else {
    iVar2 = X509_CRL_get_ext_by_NID(param_1,param_3,iVar1);
    if (iVar2 != -1) {
      return 0;
    }
    pXVar3 = X509_CRL_get_ext(param_1,iVar1);
    a = X509_EXTENSION_get_data(pXVar3);
  }
  iVar1 = X509_CRL_get_ext_by_NID(param_2,param_3,-1);
  if (iVar1 < 0) {
    uVar4 = 1;
    b = (ASN1_STRING *)0x0;
  }
  else {
    iVar2 = X509_CRL_get_ext_by_NID(param_2,param_3,iVar1);
    if (iVar2 != -1) {
      return 0;
    }
    pXVar3 = X509_CRL_get_ext(param_2,iVar1);
    b = X509_EXTENSION_get_data(pXVar3);
    uVar4 = count_leading_zeroes(b);
    uVar4 = uVar4 >> 5;
  }
  uVar5 = count_leading_zeroes(a);
  if ((uVar4 & uVar5 >> 5) == 0) {
    if ((uVar4 | uVar5 >> 5) != 0) {
      return 0;
    }
    iVar1 = ASN1_OCTET_STRING_cmp(a,b);
    uVar4 = count_leading_zeroes(iVar1);
    return uVar4 >> 5;
  }
  return 1;
}

