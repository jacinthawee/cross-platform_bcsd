
CMS_ContentInfo *
CMS_EncryptedData_encrypt(BIO *in,EVP_CIPHER *cipher,uchar *key,size_t keylen,uint flags)

{
  CMS_ContentInfo *cms;
  int iVar1;
  BIO *bio;
  
  if (cipher == (EVP_CIPHER *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x7a,0x7e,"cms_smime.c",0xf4);
    return (CMS_ContentInfo *)0x0;
  }
  cms = CMS_ContentInfo_new();
  if ((cms != (CMS_ContentInfo *)0x0) &&
     (iVar1 = CMS_EncryptedData_set1_key(cms,cipher,key,keylen), iVar1 != 0)) {
    if ((flags & 0x40) == 0) {
      CMS_set_detached(cms,0);
    }
    if ((flags & 0x5000) != 0) {
      return cms;
    }
    bio = CMS_dataInit(cms,(BIO *)0x0);
    if (bio == (BIO *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x7f,0x68,"cms_smime.c",0x2cd);
    }
    else {
      (*(code *)PTR_SMIME_crlf_copy_006a9170)(in,bio,flags);
      (*(code *)PTR_BIO_ctrl_006a6e18)(bio,0xb,0,0);
      iVar1 = CMS_dataFinal(cms,bio);
      if (iVar1 != 0) {
        (*(code *)PTR_BIO_free_all_006a6e74)(bio);
        return cms;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x7f,0x67,"cms_smime.c",0x2d6);
      (*(code *)PTR_BIO_free_all_006a6e74)(bio);
    }
    CMS_ContentInfo_free(cms);
  }
  return (CMS_ContentInfo *)0x0;
}

