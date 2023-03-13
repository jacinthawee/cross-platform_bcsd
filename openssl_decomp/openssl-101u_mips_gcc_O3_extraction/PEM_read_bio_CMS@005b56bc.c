
CMS_ContentInfo * PEM_read_bio_CMS(BIO *bp,CMS_ContentInfo **x,undefined1 *cb,void *u)

{
  CMS_ContentInfo *pCVar1;
  
  pCVar1 = (CMS_ContentInfo *)
           (*(code *)PTR_PEM_ASN1_read_bio_006a83a8)
                     (PTR_d2i_CMS_ContentInfo_006a9304,&DAT_00671568,bp,x,cb,u,&_gp);
  return pCVar1;
}

