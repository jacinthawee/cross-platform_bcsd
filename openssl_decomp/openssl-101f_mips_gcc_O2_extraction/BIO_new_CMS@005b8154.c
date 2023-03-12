
BIO * BIO_new_CMS(BIO *out,CMS_ContentInfo *cms)

{
  BIO *pBVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005b8160. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pBVar1 = (BIO *)(*(code *)PTR_BIO_new_NDEF_006aa418)(out,cms,PTR_CMS_ContentInfo_it_006aa3dc);
  return pBVar1;
}

