
CMS_ContentInfo * CMS_encrypt(stack_st_X509 *certs,BIO *in,EVP_CIPHER *cipher,uint flags)

{
  CMS_ContentInfo *cms;
  X509 *recip;
  CMS_RecipientInfo *pCVar1;
  int iVar2;
  BIO *out;
  int iVar3;
  
  cms = CMS_EnvelopedData_create(cipher);
  if (cms == (CMS_ContentInfo *)0x0) {
    ERR_put_error(0x2e,0x77,0x41,"cms_smime.c",0x25a);
    return (CMS_ContentInfo *)0x0;
  }
  iVar3 = 0;
  do {
    iVar2 = sk_num(&certs->stack);
    if (iVar2 <= iVar3) {
      if ((flags & 0x40) == 0) {
        CMS_set_detached(cms,0);
      }
      if ((flags & 0x5000) != 0) {
        return cms;
      }
      out = CMS_dataInit(cms,(BIO *)0x0);
      if (out == (BIO *)0x0) {
        ERR_put_error(0x2e,0x7f,0x41,"cms_smime.c",0x2ff);
      }
      else {
        SMIME_crlf_copy(in,out,flags);
        BIO_ctrl(out,0xb,0,(void *)0x0);
        iVar3 = CMS_dataFinal(cms,out);
        if (iVar3 != 0) {
          BIO_free_all(out);
          return cms;
        }
        ERR_put_error(0x2e,0x7f,0x67,"cms_smime.c",0x30a);
        BIO_free_all(out);
      }
      goto LAB_000e6862;
    }
    recip = (X509 *)sk_value(&certs->stack,iVar3);
    pCVar1 = CMS_add1_recipient_cert(cms,recip,flags);
    iVar3 = iVar3 + 1;
  } while (pCVar1 != (CMS_RecipientInfo *)0x0);
  ERR_put_error(0x2e,0x77,0x89,"cms_smime.c",0x24b);
LAB_000e6862:
  CMS_ContentInfo_free(cms);
  return (CMS_ContentInfo *)0x0;
}

