
X509_ATTRIBUTE * EVP_PKEY_delete_attr(EVP_PKEY *key,int loc)

{
  X509_ATTRIBUTE *pXVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00546294. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pXVar1 = (X509_ATTRIBUTE *)(*(code *)PTR_X509at_delete_attr_006a9d7c)(key->attributes);
  return pXVar1;
}
