
undefined4 dh_copy_parameters(int param_1,int param_2)

{
  BIGNUM *pBVar1;
  int iVar2;
  
  pBVar1 = BN_dup(*(BIGNUM **)(*(int *)(param_2 + 0x14) + 8));
  if (pBVar1 != (BIGNUM *)0x0) {
    iVar2 = *(int *)(param_1 + 0x14);
    if (*(BIGNUM **)(iVar2 + 8) != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)(iVar2 + 8));
      iVar2 = *(int *)(param_1 + 0x14);
    }
    *(BIGNUM **)(iVar2 + 8) = pBVar1;
    pBVar1 = BN_dup(*(BIGNUM **)(*(int *)(param_2 + 0x14) + 0xc));
    if (pBVar1 != (BIGNUM *)0x0) {
      iVar2 = *(int *)(param_1 + 0x14);
      if (*(BIGNUM **)(iVar2 + 0xc) != (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(iVar2 + 0xc));
        iVar2 = *(int *)(param_1 + 0x14);
      }
      *(BIGNUM **)(iVar2 + 0xc) = pBVar1;
      return 1;
    }
  }
  return 0;
}
