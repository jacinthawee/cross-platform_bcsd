
int EVP_PKEY_get_attr_by_NID(EVP_PKEY *key,int nid,int lastpos)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00542fa8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509at_get_attr_by_NID_006a8c54)(key->attributes);
  return iVar1;
}
