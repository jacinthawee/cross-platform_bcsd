
int X509_NAME_digest(X509_NAME *data,EVP_MD *type,uchar *md,uint *len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ASN1_item_digest_006a8fc0)(PTR_X509_NAME_it_006a8fc4,type,data,md,len);
  return iVar1;
}

