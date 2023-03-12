
int i2d_CMS_ContentInfo(CMS_ContentInfo *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005b5de0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a979c)(a,out,PTR_CMS_ContentInfo_it_006aa3dc);
  return iVar1;
}

