
int CMS_SignerInfo_cert_cmp(CMS_SignerInfo *si,X509 *cert)

{
  int *piVar1;
  int iVar2;
  X509_NAME *b;
  ASN1_INTEGER *y;
  
  piVar1 = *(int **)(si + 4);
  if (*piVar1 == 0) {
    b = X509_get_issuer_name(cert);
    iVar2 = X509_NAME_cmp(*(X509_NAME **)piVar1[1],b);
    if (iVar2 != 0) {
      return iVar2;
    }
    y = X509_get_serialNumber(cert);
    iVar2 = ASN1_INTEGER_cmp(*(ASN1_INTEGER **)(piVar1[1] + 4),y);
    return iVar2;
  }
  if (*piVar1 == 1) {
    X509_check_purpose(cert,-1,-1);
    if (cert->skid != (ASN1_STRING *)0x0) {
      iVar2 = ASN1_OCTET_STRING_cmp((ASN1_STRING *)piVar1[1],cert->skid);
      return iVar2;
    }
  }
  return -1;
}

