
int EVP_PKEY_get_attr_by_OBJ(EVP_PKEY *key,ASN1_OBJECT *obj,int lastpos)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00542fbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509at_get_attr_by_OBJ_006a8c58)(key->attributes);
  return iVar1;
}

