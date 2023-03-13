
DSA * PEM_read_DSAPrivateKey(FILE *fp,DSA **x,undefined1 *cb,void *u)

{
  EVP_PKEY *pEVar1;
  DSA *pDVar2;
  
  pEVar1 = PEM_read_PrivateKey(fp,(EVP_PKEY **)0x0,cb,u);
  if (pEVar1 != (EVP_PKEY *)0x0) {
    pDVar2 = (DSA *)(*(code *)PTR_EVP_PKEY_get1_DSA_006a7658)(pEVar1);
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(pEVar1);
    if (pDVar2 != (DSA *)0x0) {
      if (x != (DSA **)0x0) {
        (*(code *)PTR_DSA_free_006a7530)(*x);
        *x = pDVar2;
        return pDVar2;
      }
      return pDVar2;
    }
  }
  return (DSA *)0x0;
}

