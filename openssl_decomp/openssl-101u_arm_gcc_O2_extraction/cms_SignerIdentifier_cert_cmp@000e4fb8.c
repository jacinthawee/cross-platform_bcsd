
int cms_SignerIdentifier_cert_cmp(int *param_1,X509 *param_2)

{
  int iVar1;
  X509_NAME *b;
  ASN1_INTEGER *y;
  ASN1_INTEGER *x;
  X509_NAME *a;
  
  if (*param_1 == 0) {
    a = *(X509_NAME **)param_1[1];
    b = X509_get_issuer_name(param_2);
    iVar1 = X509_NAME_cmp(a,b);
    if (iVar1 != 0) {
      return iVar1;
    }
    x = *(ASN1_INTEGER **)(param_1[1] + 4);
    y = X509_get_serialNumber(param_2);
    iVar1 = ASN1_INTEGER_cmp(x,y);
    return iVar1;
  }
  if (*param_1 == 1) {
    X509_check_purpose(param_2,-1,-1);
    if (param_2->skid != (ASN1_STRING *)0x0) {
      iVar1 = ASN1_OCTET_STRING_cmp((ASN1_STRING *)param_1[1],param_2->skid);
      return iVar1;
    }
  }
  return -1;
}

