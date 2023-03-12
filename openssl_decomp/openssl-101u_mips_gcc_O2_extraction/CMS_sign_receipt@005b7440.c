
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
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0xa3,0xae,"cms_smime.c",0x1e1);
    return (CMS_ContentInfo *)0x0;
  }
  flags_00 = flags & 0xffffeffe | 0x40c0;
  cms = CMS_sign((X509 *)0x0,(EVP_PKEY *)0x0,certs,(BIO *)0x0,flags_00);
  if (cms != (CMS_ContentInfo *)0x0) {
    oid = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(0xcc);
    iVar2 = CMS_set1_eContentType(cms,oid);
    if (iVar2 != 0) {
      pCVar3 = CMS_add1_signer(cms,signcert,pkey,(EVP_MD *)0x0,flags_00);
      if (pCVar3 == (CMS_SignerInfo *)0x0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0xa3,99,"cms_smime.c",0x1f1);
      }
      else {
        pAVar4 = (ASN1_OCTET_STRING *)cms_encode_Receipt(si);
        if ((pAVar4 != (ASN1_OCTET_STRING *)0x0) &&
           (iVar2 = (*(code *)PTR_BIO_new_mem_buf_006a9148)(pAVar4->data,pAVar4->length), iVar2 != 0
           )) {
          iVar5 = cms_msgSigDigest_add1(pCVar3,si);
          if (iVar5 != 0) {
            bio = CMS_dataInit(cms,(BIO *)0x0);
            if (bio == (BIO *)0x0) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x7f,0x68,"cms_smime.c",0x2cd);
              (*(code *)PTR_BIO_free_006a6e70)(iVar2);
              goto LAB_005b74dc;
            }
            (*(code *)PTR_SMIME_crlf_copy_006a9170)(iVar2,bio,flags_00);
            (*(code *)PTR_BIO_ctrl_006a6e18)(bio,0xb,0,0);
            iVar5 = CMS_dataFinal(cms,bio);
            if (iVar5 != 0) {
              (*(code *)PTR_BIO_free_all_006a6e74)(bio);
              ppAVar6 = CMS_get0_content(cms);
              puVar1 = PTR_BIO_free_006a6e70;
              *ppAVar6 = pAVar4;
              (*(code *)puVar1)(iVar2);
              return cms;
            }
            (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x7f,0x67,"cms_smime.c",0x2d6);
            (*(code *)PTR_BIO_free_all_006a6e74)(bio);
          }
          (*(code *)PTR_BIO_free_006a6e70)(iVar2);
        }
      }
    }
  }
LAB_005b74dc:
  CMS_ContentInfo_free(cms);
  return (CMS_ContentInfo *)0x0;
}

