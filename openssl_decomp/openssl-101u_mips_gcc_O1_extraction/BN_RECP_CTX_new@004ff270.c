
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BN_RECP_CTX * BN_RECP_CTX_new(void)

{
  BN_RECP_CTX *pBVar1;
  undefined4 in_a3;
  
  pBVar1 = (BN_RECP_CTX *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x34,"bn_recp.c",0x4c,in_a3,&_gp);
  if (pBVar1 != (BN_RECP_CTX *)0x0) {
    BN_init((BIGNUM *)pBVar1);
    BN_init(&pBVar1->Nr);
    pBVar1->num_bits = 0;
    pBVar1->shift = 0;
    pBVar1->flags = 1;
  }
  return pBVar1;
}

