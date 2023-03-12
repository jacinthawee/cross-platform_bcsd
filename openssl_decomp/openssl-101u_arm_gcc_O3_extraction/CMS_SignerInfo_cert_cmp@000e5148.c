
int CMS_SignerInfo_cert_cmp(CMS_SignerInfo *si,X509 *cert)

{
  int iVar1;
  X509_NAME *b;
  ASN1_INTEGER *y;
  int *piVar2;
  ASN1_INTEGER *x;
  X509_NAME *a;
  
  piVar2 = *(int **)(si + 4);
  if (*piVar2 == 0) {
    a = *(X509_NAME **)piVar2[1];
    b = X509_get_issuer_name(cert);
    iVar1 = X509_NAME_cmp(a,b);
    if (iVar1 != 0) {
      return iVar1;
    }
    x = *(ASN1_INTEGER **)(piVar2[1] + 4);
    y = X509_get_serialNumber(cert);
    iVar1 = ASN1_INTEGER_cmp(x,y);
    return iVar1;
  }
  if (*piVar2 == 1) {
    X509_check_purpose(cert,-1,-1);
    if (cert->skid != (ASN1_STRING *)0x0) {
      iVar1 = ASN1_OCTET_STRING_cmp((ASN1_STRING *)piVar2[1],cert->skid);
      return iVar1;
    }
  }
  return -1;
}

