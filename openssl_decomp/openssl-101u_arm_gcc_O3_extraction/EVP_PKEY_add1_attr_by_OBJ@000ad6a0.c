
int EVP_PKEY_add1_attr_by_OBJ(EVP_PKEY *key,ASN1_OBJECT *obj,int type,uchar *bytes,int len)

{
  stack_st_X509_ATTRIBUTE *psVar1;
  
  psVar1 = X509at_add1_attr_by_OBJ(&key->attributes,obj,type,bytes,len);
  if (psVar1 != (stack_st_X509_ATTRIBUTE *)0x0) {
    psVar1 = (stack_st_X509_ATTRIBUTE *)0x1;
  }
  return (int)psVar1;
}
