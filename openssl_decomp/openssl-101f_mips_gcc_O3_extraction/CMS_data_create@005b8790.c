
CMS_ContentInfo * CMS_data_create(BIO *in,uint flags)

{
  CMS_ContentInfo *cms;
  BIO *bio;
  int iVar1;
  
  cms = (CMS_ContentInfo *)cms_Data_create();
  if (cms == (CMS_ContentInfo *)0x0) {
    cms = (CMS_ContentInfo *)0x0;
  }
  else if ((flags & 0x1000) == 0) {
    bio = CMS_dataInit(cms,(BIO *)0x0);
    if (bio == (BIO *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x7f,0x41,"cms_smime.c",0x2ff);
    }
    else {
      (*(code *)PTR_SMIME_crlf_copy_006aa28c)(in,bio,flags);
      (*(code *)PTR_BIO_ctrl_006a7f18)(bio,0xb,0,0);
      iVar1 = CMS_dataFinal(cms,bio);
      if (iVar1 != 0) {
        (*(code *)PTR_BIO_free_all_006a7f74)(bio);
        return cms;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x7f,0x67,"cms_smime.c",0x30a);
      (*(code *)PTR_BIO_free_all_006a7f74)(bio);
    }
    CMS_ContentInfo_free(cms);
    cms = (CMS_ContentInfo *)0x0;
  }
  return cms;
}

