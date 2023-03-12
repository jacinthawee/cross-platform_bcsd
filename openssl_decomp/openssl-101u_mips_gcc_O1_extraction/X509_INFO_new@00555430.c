
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_INFO * X509_INFO_new(void)

{
  X509_INFO *pXVar1;
  
  pXVar1 = (X509_INFO *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x2c,"x_info.c",0x45);
  if (pXVar1 == (X509_INFO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xaa,0x41,"x_info.c",0x47);
    pXVar1 = (X509_INFO *)0x0;
  }
  else {
    (pXVar1->enc_cipher).cipher = (EVP_CIPHER *)0x0;
    pXVar1->enc_len = 0;
    pXVar1->enc_data = (char *)0x0;
    pXVar1->references = 1;
    pXVar1->x509 = (X509 *)0x0;
    pXVar1->crl = (X509_CRL *)0x0;
    pXVar1->x_pkey = (X509_PKEY *)0x0;
  }
  return pXVar1;
}

