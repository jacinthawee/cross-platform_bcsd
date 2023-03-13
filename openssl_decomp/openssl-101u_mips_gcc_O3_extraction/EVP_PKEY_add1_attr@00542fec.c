
int EVP_PKEY_add1_attr(EVP_PKEY *key,X509_ATTRIBUTE *attr)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_X509at_add1_attr_006a8c64)(&key->attributes);
  return (uint)(iVar1 != 0);
}

