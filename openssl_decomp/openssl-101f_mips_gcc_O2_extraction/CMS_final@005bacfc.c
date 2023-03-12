
int CMS_final(CMS_ContentInfo *cms,BIO *data,BIO *dcont,uint flags)

{
  BIO *bio;
  int iVar1;
  BIO *pBVar2;
  
  bio = CMS_dataInit(cms,dcont);
  if (bio == (BIO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x7f,0x41,"cms_smime.c",0x2ff);
    return 0;
  }
  (*(code *)PTR_SMIME_crlf_copy_006aa28c)(data,bio,flags);
  (*(code *)PTR_BIO_ctrl_006a7f18)(bio,0xb,0,0);
  iVar1 = CMS_dataFinal(cms,bio);
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x7f,0x67,"cms_smime.c",0x30a);
  }
  if (dcont == (BIO *)0x0) {
    (*(code *)PTR_BIO_free_all_006a7f74)(bio);
  }
  else {
    do {
      pBVar2 = (BIO *)(*(code *)PTR_BIO_pop_006a8ab4)(bio);
      (*(code *)PTR_BIO_free_006a7f70)(bio);
      bio = pBVar2;
    } while (dcont != pBVar2);
  }
  return (uint)(iVar1 != 0);
}
