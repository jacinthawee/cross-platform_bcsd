
CMS_ContentInfo *
CMS_EncryptedData_encrypt(BIO *in,EVP_CIPHER *cipher,uchar *key,size_t keylen,uint flags)

{
  CMS_ContentInfo *cms;
  int iVar1;
  BIO *out;
  
  if (cipher == (EVP_CIPHER *)0x0) {
    ERR_put_error(0x2e,0x7a,0x7e,"cms_smime.c",0xf4);
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
    out = CMS_dataInit(cms,(BIO *)0x0);
    if (out == (BIO *)0x0) {
      ERR_put_error(0x2e,0x7f,0x68,"cms_smime.c",0x2cd);
    }
    else {
      SMIME_crlf_copy(in,out,flags);
      BIO_ctrl(out,0xb,0,(void *)0x0);
      iVar1 = CMS_dataFinal(cms,out);
      if (iVar1 != 0) {
        BIO_free_all(out);
        return cms;
      }
      ERR_put_error(0x2e,0x7f,0x67,"cms_smime.c",0x2d6);
      BIO_free_all(out);
    }
    CMS_ContentInfo_free(cms);
  }
  return (CMS_ContentInfo *)0x0;
}

