
int CMS_signed_get_attr_by_NID(CMS_SignerInfo *si,int nid,int lastpos)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00611d00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_X509at_get_attr_by_NID_006a9d70)(*(undefined4 *)(si + 0xc));
  return iVar1;
}
