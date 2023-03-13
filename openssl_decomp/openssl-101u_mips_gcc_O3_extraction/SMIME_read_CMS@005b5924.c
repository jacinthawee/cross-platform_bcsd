
CMS_ContentInfo * SMIME_read_CMS(BIO *bio,BIO **bcont)

{
  CMS_ContentInfo *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005b5930. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = (CMS_ContentInfo *)
           (*(code *)PTR_SMIME_read_ASN1_006a91c4)(bio,bcont,PTR_CMS_ContentInfo_it_006a92d0);
  return pCVar1;
}

