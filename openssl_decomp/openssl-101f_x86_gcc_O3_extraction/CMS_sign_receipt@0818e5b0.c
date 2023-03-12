
CMS_ContentInfo *
CMS_sign_receipt(CMS_SignerInfo *si,X509 *signcert,EVP_PKEY *pkey,stack_st_X509 *certs,uint flags)

{
  CMS_ContentInfo *cms;
  ASN1_OBJECT *oid;
  int iVar1;
  CMS_SignerInfo *pCVar2;
  ASN1_OCTET_STRING *pAVar3;
  BIO *a;
  BIO *out;
  ASN1_OCTET_STRING **ppAVar4;
  uint flags_00;
  
  flags_00 = flags & 0xffffeffe | 0x40c0;
  if ((pkey == (EVP_PKEY *)0x0) || (signcert == (X509 *)0x0)) {
    ERR_put_error(0x2e,0xa3,0xae,"cms_smime.c",0x205);
    return (CMS_ContentInfo *)0x0;
  }
  cms = CMS_sign((X509 *)0x0,(EVP_PKEY *)0x0,certs,(BIO *)0x0,flags_00);
  if (cms != (CMS_ContentInfo *)0x0) {
    oid = OBJ_nid2obj(0xcc);
    iVar1 = CMS_set1_eContentType(cms,oid);
    if (iVar1 != 0) {
      pCVar2 = CMS_add1_signer(cms,signcert,pkey,(EVP_MD *)0x0,flags_00);
      if (pCVar2 == (CMS_SignerInfo *)0x0) {
        ERR_put_error(0x2e,0xa3,99,"cms_smime.c",0x216);
      }
      else {
        pAVar3 = (ASN1_OCTET_STRING *)cms_encode_Receipt(si);
        if ((pAVar3 != (ASN1_OCTET_STRING *)0x0) &&
           (a = BIO_new_mem_buf(pAVar3->data,pAVar3->length), a != (BIO *)0x0)) {
          iVar1 = cms_msgSigDigest_add1(pCVar2,si);
          if (iVar1 != 0) {
            out = CMS_dataInit(cms,(BIO *)0x0);
            if (out == (BIO *)0x0) {
              ERR_put_error(0x2e,0x7f,0x41,"cms_smime.c",0x2ff);
              BIO_free(a);
              goto LAB_0818e618;
            }
            SMIME_crlf_copy(a,out,flags_00);
            BIO_ctrl(out,0xb,0,(void *)0x0);
            iVar1 = CMS_dataFinal(cms,out);
            if (iVar1 != 0) {
              BIO_free_all(out);
              ppAVar4 = CMS_get0_content(cms);
              *ppAVar4 = pAVar3;
              BIO_free(a);
              return cms;
            }
            ERR_put_error(0x2e,0x7f,0x67,"cms_smime.c",0x30a);
            BIO_free_all(out);
          }
          BIO_free(a);
        }
      }
    }
  }
LAB_0818e618:
  CMS_ContentInfo_free(cms);
  return (CMS_ContentInfo *)0x0;
}
