
CMS_ContentInfo * CMS_sign(X509 *signcert,EVP_PKEY *pkey,stack_st_X509 *certs,BIO *data,uint flags)

{
  CMS_ContentInfo *cms;
  int iVar1;
  undefined4 uVar2;
  CMS_SignerInfo *pCVar3;
  X509 *cert;
  int iVar4;
  BIO *bio;
  undefined4 uVar5;
  
  cms = CMS_ContentInfo_new();
  if (cms == (CMS_ContentInfo *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x94,0x41,"cms_smime.c",0x1ed);
    return (CMS_ContentInfo *)0x0;
  }
  iVar1 = CMS_SignedData_init(cms);
  if (iVar1 != 0) {
    if (pkey != (EVP_PKEY *)0x0) {
      pCVar3 = CMS_add1_signer(cms,signcert,pkey,(EVP_MD *)0x0,flags);
      if (pCVar3 == (CMS_SignerInfo *)0x0) {
        uVar5 = 99;
        uVar2 = 0x1d8;
        goto LAB_005b9b0c;
      }
    }
    iVar1 = 0;
    do {
      iVar4 = (*(code *)PTR_sk_num_006a7f2c)(certs);
      if (iVar4 <= iVar1) {
        if ((flags & 0x40) == 0) {
          CMS_set_detached(cms,0);
        }
        if ((flags & 0x5000) == 0) {
          bio = CMS_dataInit(cms,(BIO *)0x0);
          if (bio == (BIO *)0x0) {
            (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x7f,0x41,"cms_smime.c",0x2ff);
            goto LAB_005b9b20;
          }
          (*(code *)PTR_SMIME_crlf_copy_006aa28c)(data,bio,flags);
          (*(code *)PTR_BIO_ctrl_006a7f18)(bio,0xb,0,0);
          iVar1 = CMS_dataFinal(cms,bio);
          if (iVar1 == 0) {
            (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x7f,0x67,"cms_smime.c",0x30a);
            (*(code *)PTR_BIO_free_all_006a7f74)(bio);
            goto LAB_005b9b20;
          }
          (*(code *)PTR_BIO_free_all_006a7f74)(bio);
        }
        return cms;
      }
      cert = (X509 *)(*(code *)PTR_sk_value_006a7f24)(certs,iVar1);
      iVar4 = CMS_add1_cert(cms,cert);
      iVar1 = iVar1 + 1;
    } while (iVar4 != 0);
  }
  uVar5 = 0x41;
  uVar2 = 0x1ed;
LAB_005b9b0c:
  (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x94,uVar5,"cms_smime.c",uVar2);
LAB_005b9b20:
  CMS_ContentInfo_free(cms);
  return (CMS_ContentInfo *)0x0;
}
