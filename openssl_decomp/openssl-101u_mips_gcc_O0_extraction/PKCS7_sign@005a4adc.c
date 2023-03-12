
PKCS7 * PKCS7_sign(X509 *signcert,EVP_PKEY *pkey,stack_st_X509 *certs,BIO *data,int flags)

{
  PKCS7 *p7;
  int iVar1;
  PKCS7_SIGNER_INFO *pPVar2;
  X509 *x509;
  int iVar3;
  BIO *bio;
  
  p7 = PKCS7_new();
  if (p7 == (PKCS7 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x74,0x41,"pk7_smime.c",0x4c);
    return (PKCS7 *)0x0;
  }
  iVar1 = PKCS7_set_type(p7,0x16);
  if ((iVar1 != 0) && (iVar1 = PKCS7_content_new(p7,0x15), iVar1 != 0)) {
    if ((pkey == (EVP_PKEY *)0x0) ||
       (pPVar2 = PKCS7_sign_add_signer(p7,signcert,pkey,(EVP_MD *)0x0,flags),
       pPVar2 != (PKCS7_SIGNER_INFO *)0x0)) {
      if ((flags & 2U) == 0) {
        iVar1 = 0;
        do {
          iVar3 = (*(code *)PTR_sk_num_006a6e2c)(certs);
          if (iVar3 <= iVar1) goto LAB_005a4be8;
          x509 = (X509 *)(*(code *)PTR_sk_value_006a6e24)(certs,iVar1);
          iVar3 = PKCS7_add_certificate(p7,x509);
          iVar1 = iVar1 + 1;
        } while (iVar3 != 0);
      }
      else {
LAB_005a4be8:
        if ((flags & 0x40U) != 0) {
          PKCS7_ctrl(p7,1,1,(char *)0x0);
        }
        if ((flags & 0x5000U) != 0) {
          return p7;
        }
        bio = PKCS7_dataInit(p7,(BIO *)0x0);
        if (bio == (BIO *)0x0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x86,0x41,"pk7_smime.c",0x75);
        }
        else {
          (*(code *)PTR_SMIME_crlf_copy_006a9170)(data,bio,flags);
          (*(code *)PTR_BIO_ctrl_006a6e18)(bio,0xb,0,0);
          iVar1 = PKCS7_dataFinal(p7,bio);
          if (iVar1 != 0) {
            (*(code *)PTR_BIO_free_all_006a6e74)(bio);
            return p7;
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x86,0x91,"pk7_smime.c",0x7e);
          (*(code *)PTR_BIO_free_all_006a6e74)(bio);
        }
      }
    }
    else {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x74,0x99,"pk7_smime.c",0x57);
    }
  }
  PKCS7_free(p7);
  return (PKCS7 *)0x0;
}

