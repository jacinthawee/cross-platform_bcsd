
int EVP_PKEY_add1_attr_by_NID(EVP_PKEY *key,int nid,int type,uchar *bytes,int len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_X509at_add1_attr_by_NID_006a8c6c)(&key->attributes);
  return (uint)(iVar1 != 0);
}

