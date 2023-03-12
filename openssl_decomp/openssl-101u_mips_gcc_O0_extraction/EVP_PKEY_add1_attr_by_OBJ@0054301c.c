
int EVP_PKEY_add1_attr_by_OBJ(EVP_PKEY *key,ASN1_OBJECT *obj,int type,uchar *bytes,int len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_X509at_add1_attr_by_OBJ_006a8c68)(&key->attributes);
  return (uint)(iVar1 != 0);
}

