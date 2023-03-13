
bool rsa_pub_cmp(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = BN_cmp(*(BIGNUM **)(*(int *)(param_2 + 0x14) + 0x10),
                 *(BIGNUM **)(*(int *)(param_1 + 0x14) + 0x10));
  bVar2 = false;
  if (iVar1 == 0) {
    iVar1 = BN_cmp(*(BIGNUM **)(*(int *)(param_2 + 0x14) + 0x14),
                   *(BIGNUM **)(*(int *)(param_1 + 0x14) + 0x14));
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}

