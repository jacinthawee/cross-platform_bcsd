
bool dh_pub_cmp(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = BN_cmp(*(BIGNUM **)(*(int *)(param_1 + 0x14) + 8),
                 *(BIGNUM **)(*(int *)(param_2 + 0x14) + 8));
  if (iVar1 == 0) {
    iVar1 = BN_cmp(*(BIGNUM **)(*(int *)(param_1 + 0x14) + 0xc),
                   *(BIGNUM **)(*(int *)(param_2 + 0x14) + 0xc));
    if (iVar1 == 0) {
      iVar1 = BN_cmp(*(BIGNUM **)(*(int *)(param_2 + 0x14) + 0x14),
                     *(BIGNUM **)(*(int *)(param_1 + 0x14) + 0x14));
      return iVar1 == 0;
    }
  }
  return false;
}

