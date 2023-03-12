
int PKCS7_ISSUER_AND_SERIAL_digest(PKCS7_ISSUER_AND_SERIAL *data,EVP_MD *type,uchar *md,uint *len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ASN1_item_digest_006aa0d8)
                    (PTR_PKCS7_ISSUER_AND_SERIAL_it_006aa0e0,type,data,md,len);
  return iVar1;
}

