
int X509_CRL_get0_by_cert(X509_CRL *crl,X509_REVOKED **ret,X509 *x)

{
  code *pcVar1;
  int iVar2;
  X509_NAME *pXVar3;
  ASN1_INTEGER *pAVar4;
  
  pcVar1 = *(code **)(crl->meth + 0xc);
  iVar2 = 0;
  if (pcVar1 != (code *)0x0) {
    pXVar3 = X509_get_issuer_name(x);
    pAVar4 = X509_get_serialNumber(x);
    iVar2 = (*pcVar1)(crl,ret,pAVar4,pXVar3);
  }
  return iVar2;
}

