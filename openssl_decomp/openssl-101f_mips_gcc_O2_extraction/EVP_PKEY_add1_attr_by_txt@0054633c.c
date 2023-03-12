
int EVP_PKEY_add1_attr_by_txt(EVP_PKEY *key,char *attrname,int type,uchar *bytes,int len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_X509at_add1_attr_by_txt_006a9d8c)(&key->attributes);
  return (uint)(iVar1 != 0);
}

