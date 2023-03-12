
CMS_ContentInfo * d2i_CMS_bio(BIO *bp,CMS_ContentInfo **cms)

{
  CMS_ContentInfo *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005b8008. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = (CMS_ContentInfo *)
           (*(code *)PTR_ASN1_item_d2i_bio_006a8c64)(PTR_CMS_ContentInfo_it_006aa3dc,bp,cms);
  return pCVar1;
}

