
EC_KEY * PEM_read_bio_ECPrivateKey(BIO *bp,EC_KEY **x,undefined1 *cb,void *u)

{
  EVP_PKEY *pEVar1;
  EC_KEY *pEVar2;
  
  pEVar1 = PEM_read_bio_PrivateKey(bp,(EVP_PKEY **)0x0,cb,u);
  if (pEVar1 != (EVP_PKEY *)0x0) {
    pEVar2 = (EC_KEY *)(*(code *)PTR_EVP_PKEY_get1_EC_KEY_006a9e00)(pEVar1);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(pEVar1);
    if (pEVar2 != (EC_KEY *)0x0) {
      if (x != (EC_KEY **)0x0) {
        (*(code *)PTR_EC_KEY_free_006a82d8)(*x);
        *x = pEVar2;
        return pEVar2;
      }
      return pEVar2;
    }
  }
  return (EC_KEY *)0x0;
}

