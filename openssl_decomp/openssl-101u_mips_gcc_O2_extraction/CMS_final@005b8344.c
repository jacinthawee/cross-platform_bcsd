
int CMS_final(CMS_ContentInfo *cms,BIO *data,BIO *dcont,uint flags)

{
  BIO *bio;
  int iVar1;
  BIO *pBVar2;
  uint uVar3;
  
  bio = CMS_dataInit(cms,dcont);
  if (bio == (BIO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x7f,0x68,"cms_smime.c",0x2cd);
    return 0;
  }
  (*(code *)PTR_SMIME_crlf_copy_006a9170)(data,bio,flags);
  (*(code *)PTR_BIO_ctrl_006a6e18)(bio,0xb,0,0);
  iVar1 = CMS_dataFinal(cms,bio);
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x7f,0x67,"cms_smime.c",0x2d6);
  }
  uVar3 = (uint)(iVar1 != 0);
  if (dcont == (BIO *)0x0) {
    (*(code *)PTR_BIO_free_all_006a6e74)(bio);
  }
  else {
    do {
      pBVar2 = (BIO *)(*(code *)PTR_BIO_pop_006a79c8)(bio);
      (*(code *)PTR_BIO_free_006a6e70)(bio);
      if (pBVar2 == (BIO *)0x0) {
        return uVar3;
      }
      bio = pBVar2;
    } while (dcont != pBVar2);
  }
  return uVar3;
}

