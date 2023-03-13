
undefined4 ec_GFp_simple_group_copy(int param_1,int param_2)

{
  BIGNUM *pBVar1;
  
  pBVar1 = BN_copy((BIGNUM *)(param_1 + 0x48),(BIGNUM *)(param_2 + 0x48));
  if (pBVar1 != (BIGNUM *)0x0) {
    pBVar1 = BN_copy((BIGNUM *)(param_1 + 0x74),(BIGNUM *)(param_2 + 0x74));
    if (pBVar1 != (BIGNUM *)0x0) {
      pBVar1 = BN_copy((BIGNUM *)(param_1 + 0x88),(BIGNUM *)(param_2 + 0x88));
      if (pBVar1 != (BIGNUM *)0x0) {
        *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_2 + 0x9c);
        return 1;
      }
    }
  }
  return 0;
}

