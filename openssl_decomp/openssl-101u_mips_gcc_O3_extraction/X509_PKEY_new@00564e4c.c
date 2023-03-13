
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_PKEY * X509_PKEY_new(void)

{
  undefined *puVar1;
  X509_PKEY *pXVar2;
  X509_ALGOR *pXVar3;
  ASN1_STRING *pAVar4;
  
  pXVar2 = (X509_PKEY *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x34,"x_pkey.c",0x6d);
  if (pXVar2 == (X509_PKEY *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xad,0x41,"x_pkey.c",0x6d);
  }
  else {
    pXVar2->version = 0;
    pXVar3 = X509_ALGOR_new();
    pXVar2->enc_algor = pXVar3;
    if (pXVar3 != (X509_ALGOR *)0x0) {
      pAVar4 = ASN1_STRING_type_new(4);
      pXVar2->enc_pkey = pAVar4;
      puVar1 = PTR_memset_006a99f4;
      if (pAVar4 != (ASN1_STRING *)0x0) {
        pXVar2->dec_pkey = (EVP_PKEY *)0x0;
        pXVar2->key_length = 0;
        pXVar2->key_data = (char *)0x0;
        pXVar2->key_free = 0;
        (pXVar2->cipher).cipher = (EVP_CIPHER *)0x0;
        (*(code *)puVar1)((pXVar2->cipher).iv,0,0x10);
        pXVar2->references = 1;
        return pXVar2;
      }
    }
  }
  return (X509_PKEY *)0x0;
}

