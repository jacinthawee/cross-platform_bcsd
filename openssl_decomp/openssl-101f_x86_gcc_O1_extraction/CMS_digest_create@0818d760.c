
CMS_ContentInfo * CMS_digest_create(BIO *in,EVP_MD *md,uint flags)

{
  CMS_ContentInfo *cms;
  BIO *out;
  int iVar1;
  CMS_ContentInfo *pCVar2;
  
  if (md == (EVP_MD *)0x0) {
    md = EVP_sha1();
  }
  cms = (CMS_ContentInfo *)cms_DigestedData_create(md);
  if (cms == (CMS_ContentInfo *)0x0) {
    pCVar2 = (CMS_ContentInfo *)0x0;
  }
  else {
    if ((flags & 0x40) == 0) {
      CMS_set_detached(cms,0);
    }
    pCVar2 = cms;
    if ((flags & 0x1000) == 0) {
      out = CMS_dataInit(cms,(BIO *)0x0);
      if (out == (BIO *)0x0) {
        ERR_put_error(0x2e,0x7f,0x41,"cms_smime.c",0x2ff);
      }
      else {
        SMIME_crlf_copy(in,out,flags);
        BIO_ctrl(out,0xb,0,(void *)0x0);
        iVar1 = CMS_dataFinal(cms,out);
        if (iVar1 != 0) {
          BIO_free_all(out);
          return cms;
        }
        ERR_put_error(0x2e,0x7f,0x67,"cms_smime.c",0x30a);
        BIO_free_all(out);
      }
      pCVar2 = (CMS_ContentInfo *)0x0;
      CMS_ContentInfo_free(cms);
    }
  }
  return pCVar2;
}

