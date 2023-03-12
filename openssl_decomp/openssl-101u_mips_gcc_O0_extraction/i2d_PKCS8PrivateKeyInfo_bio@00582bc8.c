
int i2d_PKCS8PrivateKeyInfo_bio(BIO *bp,EVP_PKEY *key)

{
  PKCS8_PRIV_KEY_INFO *a;
  int iVar1;
  
  a = (PKCS8_PRIV_KEY_INFO *)(*(code *)PTR_EVP_PKEY2PKCS8_006a8e9c)(key);
  if (a != (PKCS8_PRIV_KEY_INFO *)0x0) {
    iVar1 = (*(code *)PTR_ASN1_i2d_bio_006a7198)(PTR_i2d_PKCS8_PRIV_KEY_INFO_006a8ea4,bp,a);
    PKCS8_PRIV_KEY_INFO_free(a);
    return iVar1;
  }
  return 0;
}

