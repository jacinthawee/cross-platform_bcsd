
int i2d_CMS_ContentInfo(CMS_ContentInfo *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005b3470. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a8678)(a,out,PTR_CMS_ContentInfo_it_006a92d0);
  return iVar1;
}

