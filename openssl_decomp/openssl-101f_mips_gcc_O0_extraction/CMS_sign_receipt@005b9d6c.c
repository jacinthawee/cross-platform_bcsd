
CMS_ContentInfo *
CMS_sign_receipt(CMS_SignerInfo *si,X509 *signcert,EVP_PKEY *pkey,stack_st_X509 *certs,uint flags)

{
  undefined *puVar1;
  CMS_ContentInfo *cms;
  ASN1_OBJECT *oid;
  int iVar2;
  CMS_SignerInfo *pCVar3;
  ASN1_OCTET_STRING *pAVar4;
  int iVar5;
  BIO *bio;
  ASN1_OCTET_STRING **ppAVar6;
  uint flags_00;
  
  if ((pkey == (EVP_PKEY *)0x0) || (signcert == (X509 *)0x0)) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0xa3,0xae,"cms_smime.c",0x205);
    return (CMS_ContentInfo *)0x0;
  }
  flags_00 = flags & 0xffffeffe | 0x40c0;
  cms = CMS_sign((X509 *)0x0,(EVP_PKEY *)0x0,certs,(BIO *)0x0,flags_00);
  if (cms != (CMS_ContentInfo *)0x0) {
    oid = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(0xcc);
    iVar2 = CMS_set1_eContentType(cms,oid);
    if (iVar2 != 0) {
      pCVar3 = CMS_add1_signer(cms,signcert,pkey,(EVP_MD *)0x0,flags_00);
      if (pCVar3 == (CMS_SignerInfo *)0x0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0xa3,99,"cms_smime.c",0x216);
      }
      else {
        pAVar4 = (ASN1_OCTET_STRING *)cms_encode_Receipt(si);
        if ((pAVar4 != (ASN1_OCTET_STRING *)0x0) &&
           (iVar2 = (*(code *)PTR_BIO_new_mem_buf_006aa264)(pAVar4->data,pAVar4->length), iVar2 != 0
           )) {
          iVar5 = cms_msgSigDigest_add1(pCVar3,si);
          if (iVar5 != 0) {
            bio = CMS_dataInit(cms,(BIO *)0x0);
            if (bio == (BIO *)0x0) {
              (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x7f,0x41,"cms_smime.c",0x2ff);
              (*(code *)PTR_BIO_free_006a7f70)(iVar2);
              goto LAB_005b9e08;
            }
            (*(code *)PTR_SMIME_crlf_copy_006aa28c)(iVar2,bio,flags_00);
            (*(code *)PTR_BIO_ctrl_006a7f18)(bio,0xb,0,0);
            iVar5 = CMS_dataFinal(cms,bio);
            if (iVar5 != 0) {
              (*(code *)PTR_BIO_free_all_006a7f74)(bio);
              ppAVar6 = CMS_get0_content(cms);
              puVar1 = PTR_BIO_free_006a7f70;
              *ppAVar6 = pAVar4;
              (*(code *)puVar1)(iVar2);
              return cms;
            }
            (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x7f,0x67,"cms_smime.c",0x30a);
            (*(code *)PTR_BIO_free_all_006a7f74)(bio);
          }
          (*(code *)PTR_BIO_free_006a7f70)(iVar2);
        }
      }
    }
  }
LAB_005b9e08:
  CMS_ContentInfo_free(cms);
  return (CMS_ContentInfo *)0x0;
}

