
int X509_pubkey_digest(X509 *data,EVP_MD *type,uchar *md,uint *len)

{
  ASN1_BIT_STRING *pAVar1;
  int iVar2;
  
  pAVar1 = X509_get0_pubkey_bitstr(data);
  if (pAVar1 != (ASN1_BIT_STRING *)0x0) {
    iVar2 = (*(code *)PTR_EVP_Digest_006a8b04)(pAVar1->data,pAVar1->length,md,len,type,0);
    return iVar2;
  }
  return 0;
}

