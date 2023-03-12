
RSA * PEM_read_RSAPrivateKey(FILE *fp,RSA **x,undefined1 *cb,void *u)

{
  EVP_PKEY *pEVar1;
  RSA *pRVar2;
  
  pEVar1 = PEM_read_PrivateKey(fp,(EVP_PKEY **)0x0,cb,u);
  if (pEVar1 != (EVP_PKEY *)0x0) {
    pRVar2 = (RSA *)(*(code *)PTR_EVP_PKEY_get1_RSA_006a86e8)(pEVar1);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(pEVar1);
    if (pRVar2 != (RSA *)0x0) {
      if (x != (RSA **)0x0) {
        (*(code *)PTR_RSA_free_006a86f0)(*x);
        *x = pRVar2;
        return pRVar2;
      }
      return pRVar2;
    }
  }
  return (RSA *)0x0;
}

