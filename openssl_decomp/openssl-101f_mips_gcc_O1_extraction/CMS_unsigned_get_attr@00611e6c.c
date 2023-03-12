
X509_ATTRIBUTE * CMS_unsigned_get_attr(CMS_SignerInfo *si,int loc)

{
  X509_ATTRIBUTE *pXVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00611e78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pXVar1 = (X509_ATTRIBUTE *)(*(code *)PTR_X509at_get_attr_006a9d78)(*(undefined4 *)(si + 0x18));
  return pXVar1;
}

