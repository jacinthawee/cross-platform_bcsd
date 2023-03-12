
bool dh_cmp_parameters(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = BN_cmp(*(BIGNUM **)(*(int *)(param_1 + 0x14) + 8),
                 *(BIGNUM **)(*(int *)(param_2 + 0x14) + 8));
  bVar2 = false;
  if (iVar1 == 0) {
    iVar1 = BN_cmp(*(BIGNUM **)(*(int *)(param_1 + 0x14) + 0xc),
                   *(BIGNUM **)(*(int *)(param_2 + 0x14) + 0xc));
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}

