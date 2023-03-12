
CMS_ContentInfo * CMS_encrypt(stack_st_X509 *certs,BIO *in,EVP_CIPHER *cipher,uint flags)

{
  CMS_ContentInfo *cms;
  X509 *recip;
  CMS_RecipientInfo *pCVar1;
  int iVar2;
  BIO *bio;
  int iVar3;
  
  cms = CMS_EnvelopedData_create(cipher);
  if (cms == (CMS_ContentInfo *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x77,0x41,"cms_smime.c",0x233);
    return (CMS_ContentInfo *)0x0;
  }
  iVar3 = 0;
  do {
    iVar2 = (*(code *)PTR_sk_num_006a6e2c)(certs);
    if (iVar2 <= iVar3) {
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
        iVar3 = CMS_dataFinal(cms,bio);
        if (iVar3 != 0) {
          (*(code *)PTR_BIO_free_all_006a6e74)(bio);
          return cms;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x7f,0x67,"cms_smime.c",0x2d6);
        (*(code *)PTR_BIO_free_all_006a6e74)(bio);
      }
      goto LAB_005b780c;
    }
    recip = (X509 *)(*(code *)PTR_sk_value_006a6e24)(certs,iVar3);
    pCVar1 = CMS_add1_recipient_cert(cms,recip,flags);
    iVar3 = iVar3 + 1;
  } while (pCVar1 != (CMS_RecipientInfo *)0x0);
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x77,0x89,"cms_smime.c",0x224);
LAB_005b780c:
  CMS_ContentInfo_free(cms);
  return (CMS_ContentInfo *)0x0;
}

