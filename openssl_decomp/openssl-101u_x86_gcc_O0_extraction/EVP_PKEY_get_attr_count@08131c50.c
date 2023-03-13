
int EVP_PKEY_get_attr_count(EVP_PKEY *key)

{
  int iVar1;
  
  iVar1 = X509at_get_attr_count((_STACK *)key->attributes);
  return iVar1;
}

