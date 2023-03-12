
int X509_REQ_digest(X509_REQ *data,EVP_MD *type,uchar *md,uint *len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ASN1_item_digest_006aa0d8)(PTR_X509_REQ_it_006aa0c4,type,data,md,len);
  return iVar1;
}

