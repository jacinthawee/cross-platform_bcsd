
int i2d_CMS_bio(BIO *bp,CMS_ContentInfo *cms)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005b8024. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_bio_006a8810)(PTR_CMS_ContentInfo_it_006aa3dc,bp,cms);
  return iVar1;
}

