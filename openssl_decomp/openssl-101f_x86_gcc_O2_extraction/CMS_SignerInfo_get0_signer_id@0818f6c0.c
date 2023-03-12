
int CMS_SignerInfo_get0_signer_id
              (CMS_SignerInfo *si,ASN1_OCTET_STRING **keyid,X509_NAME **issuer,ASN1_INTEGER **sno)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(si + 4);
  iVar2 = *piVar1;
  if (iVar2 == 0) {
    if (issuer != (X509_NAME **)0x0) {
      *issuer = *(X509_NAME **)piVar1[1];
    }
    if (sno != (ASN1_INTEGER **)0x0) {
      *sno = *(ASN1_INTEGER **)(piVar1[1] + 4);
    }
  }
  else {
    if (iVar2 != 1) {
      return 0;
    }
    if (keyid != (ASN1_OCTET_STRING **)0x0) {
      *keyid = (ASN1_OCTET_STRING *)piVar1[1];
      return iVar2;
    }
  }
  return 1;
}

