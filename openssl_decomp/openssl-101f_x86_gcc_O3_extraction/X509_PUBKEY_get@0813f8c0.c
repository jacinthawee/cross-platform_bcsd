
EVP_PKEY * X509_PUBKEY_get(X509_PUBKEY *key)

{
  EVP_PKEY *pkey;
  int iVar1;
  
  if (key != (X509_PUBKEY *)0x0) {
    if (key->pkey != (EVP_PKEY *)0x0) {
      CRYPTO_add_lock(&key->pkey->references,1,10,"x_pubkey.c",0x8d);
      return key->pkey;
    }
    if (key->public_key != (ASN1_BIT_STRING *)0x0) {
      pkey = EVP_PKEY_new();
      if (pkey != (EVP_PKEY *)0x0) {
        iVar1 = OBJ_obj2nid(key->algor->algorithm);
        iVar1 = EVP_PKEY_set_type(pkey,iVar1);
        if (iVar1 == 0) {
          ERR_put_error(0xb,0x77,0x6f,"x_pubkey.c",0x9b);
        }
        else if (*(code **)(pkey->ameth + 0x14) == (code *)0x0) {
          ERR_put_error(0xb,0x77,0x7c,"x_pubkey.c",0xaa);
        }
        else {
          iVar1 = (**(code **)(pkey->ameth + 0x14))(pkey,key);
          if (iVar1 != 0) {
            CRYPTO_lock(iVar1,9,(char *)0xa,(int)"x_pubkey.c");
            if (key->pkey == (EVP_PKEY *)0x0) {
              key->pkey = pkey;
              CRYPTO_lock(0,10,(char *)0xa,(int)"x_pubkey.c");
            }
            else {
              CRYPTO_lock((int)key->pkey,10,(char *)0xa,(int)"x_pubkey.c");
              EVP_PKEY_free(pkey);
              pkey = key->pkey;
            }
            CRYPTO_add_lock(&pkey->references,1,10,"x_pubkey.c",0xbb);
            return pkey;
          }
          ERR_put_error(0xb,0x77,0x7d,"x_pubkey.c",0xa4);
        }
        EVP_PKEY_free(pkey);
        return (EVP_PKEY *)0x0;
      }
      ERR_put_error(0xb,0x77,0x41,"x_pubkey.c",0x95);
    }
  }
  return (EVP_PKEY *)0x0;
}

