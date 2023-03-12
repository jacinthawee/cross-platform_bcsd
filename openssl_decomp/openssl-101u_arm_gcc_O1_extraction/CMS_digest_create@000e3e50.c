
CMS_ContentInfo * CMS_digest_create(BIO *in,EVP_MD *md,uint flags)

{
  CMS_ContentInfo *cms;
  BIO *out;
  int iVar1;
  
  if (md == (EVP_MD *)0x0) {
    md = EVP_sha1();
  }
  cms = (CMS_ContentInfo *)cms_DigestedData_create(md);
  if (cms == (CMS_ContentInfo *)0x0) {
    return (CMS_ContentInfo *)0x0;
  }
  if ((flags & 0x40) == 0) {
    CMS_set_detached(cms,0);
  }
  if ((flags & 0x1000) == 0) {
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
    cms = (CMS_ContentInfo *)0x0;
  }
  return cms;
}

