
int EVP_PKEY_add1_attr_by_txt(EVP_PKEY *key,char *attrname,int type,uchar *bytes,int len)

{
  stack_st_X509_ATTRIBUTE *psVar1;
  
  psVar1 = X509at_add1_attr_by_txt(&key->attributes,attrname,type,bytes,len);
  return (uint)(psVar1 != (stack_st_X509_ATTRIBUTE *)0x0);
}

