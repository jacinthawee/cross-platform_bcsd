
int X509_CRL_digest(X509_CRL *data,EVP_MD *type,uchar *md,uint *len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ASN1_item_digest_006a8fc0)(PTR_X509_CRL_it_006a8fa4,type,data,md,len);
  return iVar1;
}

