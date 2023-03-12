
CMS_ContentInfo * SMIME_read_CMS(BIO *bio,BIO **bcont)

{
  CMS_ContentInfo *pCVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005b82a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pCVar1 = (CMS_ContentInfo *)
           (*(code *)PTR_SMIME_read_ASN1_006aa2e0)(bio,bcont,PTR_CMS_ContentInfo_it_006aa3dc);
  return pCVar1;
}

