
int CMS_signed_get_attr_count(CMS_SignerInfo *si)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00611cec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509at_get_attr_count_006a9d6c)(*(undefined4 *)(si + 0xc));
  return iVar1;
}

