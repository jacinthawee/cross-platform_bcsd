
int EC_GROUP_get_cofactor(EC_GROUP *group,BIGNUM *cofactor,BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  
  pBVar1 = BN_copy(cofactor,(BIGNUM *)(group + 0x1c));
  if (pBVar1 != (BIGNUM *)0x0) {
    return (uint)(*(int *)(group + 0x20) != 0);
  }
  return 0;
}

