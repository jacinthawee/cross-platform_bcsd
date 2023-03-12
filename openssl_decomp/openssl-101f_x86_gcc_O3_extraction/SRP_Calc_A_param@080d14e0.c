
undefined4 SRP_Calc_A_param(int param_1)

{
  int iVar1;
  BIGNUM *pBVar2;
  undefined4 uVar3;
  int in_GS_OFFSET;
  uchar local_40 [48];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = BN_num_bits(*(BIGNUM **)(param_1 + 0x1a8));
  if ((*(int *)(param_1 + 0x1cc) <= iVar1) &&
     ((*(int *)(param_1 + 0x19c) != 0 ||
      (iVar1 = SRP_check_known_gN_param
                         (*(undefined4 *)(param_1 + 0x1ac),*(undefined4 *)(param_1 + 0x1a8)),
      iVar1 != 0)))) {
    RAND_bytes(local_40,0x30);
    pBVar2 = BN_bin2bn(local_40,0x30,*(BIGNUM **)(param_1 + 0x1bc));
    *(BIGNUM **)(param_1 + 0x1bc) = pBVar2;
    OPENSSL_cleanse(local_40,0x30);
    iVar1 = SRP_Calc_A(*(undefined4 *)(param_1 + 0x1bc),*(undefined4 *)(param_1 + 0x1a8),
                       *(undefined4 *)(param_1 + 0x1ac));
    *(int *)(param_1 + 0x1b8) = iVar1;
    if (iVar1 != 0) {
      uVar3 = 1;
      if (*(code **)(param_1 + 0x19c) != (code *)0x0) {
        uVar3 = (**(code **)(param_1 + 0x19c))(param_1,*(undefined4 *)(param_1 + 0x194));
      }
      goto LAB_080d1592;
    }
  }
  uVar3 = 0xffffffff;
LAB_080d1592:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}

