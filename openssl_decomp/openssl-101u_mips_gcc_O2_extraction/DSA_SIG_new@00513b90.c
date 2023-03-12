
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DSA_SIG * DSA_SIG_new(void)

{
  DSA_SIG *pDVar1;
  undefined4 in_a3;
  
  pDVar1 = (DSA_SIG *)(*(code *)PTR_CRYPTO_malloc_006a7008)(8,"dsa_sign.c",0x5d,in_a3,&_gp);
  if (pDVar1 != (DSA_SIG *)0x0) {
    pDVar1->r = (BIGNUM *)0x0;
    pDVar1->s = (BIGNUM *)0x0;
  }
  return pDVar1;
}

