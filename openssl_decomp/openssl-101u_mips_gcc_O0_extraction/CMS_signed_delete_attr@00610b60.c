
X509_ATTRIBUTE * CMS_signed_delete_attr(CMS_SignerInfo *si,int loc)

{
  X509_ATTRIBUTE *pXVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00610b6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pXVar1 = (X509_ATTRIBUTE *)(*(code *)PTR_X509at_delete_attr_006a8c60)(*(undefined4 *)(si + 0xc));
  return pXVar1;
}
