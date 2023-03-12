
int X509_pubkey_digest(X509 *data,EVP_MD *type,uchar *md,uint *len)

{
  ASN1_BIT_STRING *pAVar1;
  int iVar2;
  
  pAVar1 = X509_get0_pubkey_bitstr(data);
  iVar2 = 0;
  if (pAVar1 != (ASN1_BIT_STRING *)0x0) {
    iVar2 = EVP_Digest(pAVar1->data,pAVar1->length,md,len,type,(ENGINE *)0x0);
  }
  return iVar2;
}

