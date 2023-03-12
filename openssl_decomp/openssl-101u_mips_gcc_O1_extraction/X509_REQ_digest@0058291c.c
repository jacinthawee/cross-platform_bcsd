
int X509_REQ_digest(X509_REQ *data,EVP_MD *type,uchar *md,uint *len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ASN1_item_digest_006a8fc0)(PTR_X509_REQ_it_006a8fac,type,data,md,len);
  return iVar1;
}

