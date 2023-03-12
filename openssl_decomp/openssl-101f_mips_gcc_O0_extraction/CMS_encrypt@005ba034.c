
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
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x77,0x41,"cms_smime.c",0x25a);
    return (CMS_ContentInfo *)0x0;
  }
  iVar3 = 0;
  do {
    iVar2 = (*(code *)PTR_sk_num_006a7f2c)(certs);
    if (iVar2 <= iVar3) {
      if ((flags & 0x40) == 0) {
        CMS_set_detached(cms,0);
      }
      if ((flags & 0x5000) != 0) {
        return cms;
      }
      bio = CMS_dataInit(cms,(BIO *)0x0);
      if (bio == (BIO *)0x0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x7f,0x41,"cms_smime.c",0x2ff);
      }
      else {
        (*(code *)PTR_SMIME_crlf_copy_006aa28c)(in,bio,flags);
        (*(code *)PTR_BIO_ctrl_006a7f18)(bio,0xb,0,0);
        iVar3 = CMS_dataFinal(cms,bio);
        if (iVar3 != 0) {
          (*(code *)PTR_BIO_free_all_006a7f74)(bio);
          return cms;
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x7f,0x67,"cms_smime.c",0x30a);
        (*(code *)PTR_BIO_free_all_006a7f74)(bio);
      }
      goto LAB_005ba138;
    }
    recip = (X509 *)(*(code *)PTR_sk_value_006a7f24)(certs,iVar3);
    pCVar1 = CMS_add1_recipient_cert(cms,recip,flags);
    iVar3 = iVar3 + 1;
  } while (pCVar1 != (CMS_RecipientInfo *)0x0);
  (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x77,0x89,"cms_smime.c",0x24b);
LAB_005ba138:
  CMS_ContentInfo_free(cms);
  return (CMS_ContentInfo *)0x0;
}

