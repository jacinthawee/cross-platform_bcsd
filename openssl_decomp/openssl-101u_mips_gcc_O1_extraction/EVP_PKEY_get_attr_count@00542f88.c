
int EVP_PKEY_get_attr_count(EVP_PKEY *key)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00542f94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509at_get_attr_count_006a8c50)(key->attributes);
  return iVar1;
}

