
int CMS_unsigned_get_attr_count(CMS_SignerInfo *si)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00611e3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509at_get_attr_count_006a9d6c)(*(undefined4 *)(si + 0x18));
  return iVar1;
}

