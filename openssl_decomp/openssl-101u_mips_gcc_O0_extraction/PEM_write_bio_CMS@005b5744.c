
int PEM_write_bio_CMS(BIO *bp,CMS_ContentInfo *x)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_PEM_ASN1_write_bio_006a83b0)
                    (PTR_i2d_CMS_ContentInfo_006a9308,&DAT_00671568,bp,x,0,0,0,0,0);
  return iVar1;
}

