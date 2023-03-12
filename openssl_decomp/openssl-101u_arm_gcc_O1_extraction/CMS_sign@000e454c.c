
CMS_ContentInfo * CMS_sign(X509 *signcert,EVP_PKEY *pkey,stack_st_X509 *certs,BIO *data,uint flags)

{
  CMS_ContentInfo *cms;
  int iVar1;
  CMS_SignerInfo *pCVar2;
  X509 *cert;
  int iVar3;
  BIO *out;
  
  cms = CMS_ContentInfo_new();
  if (cms == (CMS_ContentInfo *)0x0) {
    ERR_put_error(0x2e,0x94,0x41,"cms_smime.c",0x1cb);
    return (CMS_ContentInfo *)0x0;
  }
  iVar1 = CMS_SignedData_init(cms);
  if (iVar1 != 0) {
    if ((pkey != (EVP_PKEY *)0x0) &&
       (pCVar2 = CMS_add1_signer(cms,signcert,pkey,(EVP_MD *)0x0,flags),
       pCVar2 == (CMS_SignerInfo *)0x0)) {
      ERR_put_error(0x2e,0x94,99,"cms_smime.c",0x1b7);
      goto LAB_000e4604;
    }
    iVar1 = 0;
    do {
      iVar3 = sk_num(&certs->stack);
      if (iVar3 <= iVar1) {
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
          SMIME_crlf_copy(data,out,flags);
          BIO_ctrl(out,0xb,0,(void *)0x0);
          iVar1 = CMS_dataFinal(cms,out);
          if (iVar1 != 0) {
            BIO_free_all(out);
            return cms;
          }
          ERR_put_error(0x2e,0x7f,0x67,"cms_smime.c",0x2d6);
          BIO_free_all(out);
        }
        goto LAB_000e4604;
      }
      cert = (X509 *)sk_value(&certs->stack,iVar1);
      iVar3 = CMS_add1_cert(cms,cert);
      iVar1 = iVar1 + 1;
    } while (iVar3 != 0);
  }
  ERR_put_error(0x2e,0x94,0x41,"cms_smime.c",0x1cb);
LAB_000e4604:
  CMS_ContentInfo_free(cms);
  return (CMS_ContentInfo *)0x0;
}

