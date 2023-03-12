
PKCS7 * PKCS7_encrypt(stack_st_X509 *certs,BIO *in,EVP_CIPHER *cipher,int flags)

{
  PKCS7 *p7;
  int iVar1;
  X509 *x509;
  PKCS7_RECIP_INFO *pPVar2;
  int iVar3;
  undefined4 uVar4;
  BIO *bio;
  undefined4 uVar5;
  
  p7 = PKCS7_new();
  if (p7 == (PKCS7 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x73,0x41,"pk7_smime.c",0x1e5);
  }
  else {
    iVar1 = PKCS7_set_type(p7,0x17);
    if (iVar1 != 0) {
      iVar1 = PKCS7_set_cipher(p7,cipher);
      if (iVar1 == 0) {
        uVar5 = 0x79;
        uVar4 = 0x1ec;
      }
      else {
        iVar1 = 0;
        do {
          iVar3 = (*(code *)PTR_sk_num_006a6e2c)(certs);
          if (iVar3 <= iVar1) {
            if ((flags & 0x1000U) != 0) {
              return p7;
            }
            bio = PKCS7_dataInit(p7,(BIO *)0x0);
            if (bio == (BIO *)0x0) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x86,0x41,"pk7_smime.c",0x75);
            }
            else {
              (*(code *)PTR_SMIME_crlf_copy_006a9170)(in,bio,flags);
              (*(code *)PTR_BIO_ctrl_006a6e18)(bio,0xb,0,0);
              iVar1 = PKCS7_dataFinal(p7,bio);
              if (iVar1 != 0) {
                (*(code *)PTR_BIO_free_all_006a6e74)(bio);
                return p7;
              }
              (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x86,0x91,"pk7_smime.c",0x7e);
              (*(code *)PTR_BIO_free_all_006a6e74)(bio);
            }
            goto LAB_005a5b10;
          }
          x509 = (X509 *)(*(code *)PTR_sk_value_006a6e24)(certs,iVar1);
          pPVar2 = PKCS7_add_recipient(p7,x509);
          iVar1 = iVar1 + 1;
        } while (pPVar2 != (PKCS7_RECIP_INFO *)0x0);
        uVar5 = 0x78;
        uVar4 = 499;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x73,uVar5,"pk7_smime.c",uVar4);
    }
LAB_005a5b10:
    (*(code *)PTR_BIO_free_all_006a6e74)(0);
    PKCS7_free(p7);
  }
  return (PKCS7 *)0x0;
}

