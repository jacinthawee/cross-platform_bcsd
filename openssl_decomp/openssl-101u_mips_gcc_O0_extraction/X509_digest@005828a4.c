
int X509_digest(X509 *data,EVP_MD *type,uchar *md,uint *len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ASN1_item_digest_006a8fc0)(PTR_X509_it_006a8f9c,type,data,md,len);
  return iVar1;
}

