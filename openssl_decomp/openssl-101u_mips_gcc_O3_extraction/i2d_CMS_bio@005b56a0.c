
int i2d_CMS_bio(BIO *bp,CMS_ContentInfo *cms)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005b56b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_bio_006a7720)(PTR_CMS_ContentInfo_it_006a92d0,bp,cms);
  return iVar1;
}

