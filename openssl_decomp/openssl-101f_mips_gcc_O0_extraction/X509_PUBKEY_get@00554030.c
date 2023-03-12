
EVP_PKEY * X509_PUBKEY_get(X509_PUBKEY *key)

{
  undefined *puVar1;
  EVP_PKEY *pkey;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (key != (X509_PUBKEY *)0x0) {
    if (key->pkey != (EVP_PKEY *)0x0) {
      (*(code *)PTR_CRYPTO_add_lock_006a9080)(&key->pkey->references,1,10,"x_pubkey.c",0x8d);
      return key->pkey;
    }
    if (key->public_key != (ASN1_BIT_STRING *)0x0) {
      pkey = EVP_PKEY_new();
      if (pkey != (EVP_PKEY *)0x0) {
        iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(key->algor->algorithm);
        iVar2 = EVP_PKEY_set_type(pkey,iVar2);
        if (iVar2 == 0) {
          uVar4 = 0x6f;
          uVar3 = 0x9b;
        }
        else if (*(code **)(pkey->ameth + 0x14) == (code *)0x0) {
          uVar4 = 0x7c;
          uVar3 = 0xaa;
        }
        else {
          iVar2 = (**(code **)(pkey->ameth + 0x14))(pkey,key);
          if (iVar2 != 0) {
            (*(code *)PTR_CRYPTO_lock_006a926c)(9,10,"x_pubkey.c",0xaf);
            puVar1 = PTR_CRYPTO_lock_006a926c;
            if (key->pkey == (EVP_PKEY *)0x0) {
              key->pkey = pkey;
              (*(code *)puVar1)(10,10,"x_pubkey.c",0xb9);
            }
            else {
              (*(code *)PTR_CRYPTO_lock_006a926c)(10,10,"x_pubkey.c",0xb2);
              EVP_PKEY_free(pkey);
              pkey = key->pkey;
            }
            (*(code *)PTR_CRYPTO_add_lock_006a9080)(&pkey->references,1,10,"x_pubkey.c",0xbb);
            return pkey;
          }
          uVar4 = 0x7d;
          uVar3 = 0xa4;
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x77,uVar4,"x_pubkey.c",uVar3);
        EVP_PKEY_free(pkey);
        return (EVP_PKEY *)0x0;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x77,0x41,"x_pubkey.c",0x95);
    }
  }
  return (EVP_PKEY *)0x0;
}

