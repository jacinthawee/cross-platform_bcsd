
void update_buflen(BIGNUM *param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 != (BIGNUM *)0x0) {
    uVar3 = *param_2;
    iVar1 = BN_num_bits(param_1);
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (uVar3 < (uint)(iVar2 >> 3)) {
      *param_2 = iVar2 >> 3;
    }
    return;
  }
  return;
}

