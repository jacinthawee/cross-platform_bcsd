
undefined4 SRP_Calc_A_param(int param_1)

{
  int iVar1;
  BIGNUM *pBVar2;
  undefined4 uVar3;
  int in_GS_OFFSET;
  uchar local_40 [48];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = RAND_bytes(local_40,0x30);
  if (0 < iVar1) {
    pBVar2 = BN_bin2bn(local_40,0x30,*(BIGNUM **)(param_1 + 0x1bc));
    *(BIGNUM **)(param_1 + 0x1bc) = pBVar2;
    OPENSSL_cleanse(local_40,0x30);
    iVar1 = SRP_Calc_A(*(undefined4 *)(param_1 + 0x1bc),*(undefined4 *)(param_1 + 0x1a8),
                       *(undefined4 *)(param_1 + 0x1ac));
    *(int *)(param_1 + 0x1b8) = iVar1;
    if (iVar1 != 0) {
      uVar3 = 1;
      goto LAB_080cefc5;
    }
  }
  uVar3 = 0xffffffff;
LAB_080cefc5:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

