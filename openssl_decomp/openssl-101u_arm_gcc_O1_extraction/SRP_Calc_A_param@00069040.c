
void SRP_Calc_A_param(int param_1)

{
  int iVar1;
  BIGNUM *pBVar2;
  undefined4 uVar3;
  uchar auStack_44 [48];
  int local_14;
  
  local_14 = __stack_chk_guard;
  iVar1 = RAND_bytes(auStack_44,0x30);
  if (0 < iVar1) {
    pBVar2 = BN_bin2bn(auStack_44,0x30,*(BIGNUM **)(param_1 + 0x1bc));
    *(BIGNUM **)(param_1 + 0x1bc) = pBVar2;
    OPENSSL_cleanse(auStack_44,0x30);
    iVar1 = SRP_Calc_A(*(undefined4 *)(param_1 + 0x1bc),*(undefined4 *)(param_1 + 0x1a8),
                       *(undefined4 *)(param_1 + 0x1ac));
    *(int *)(param_1 + 0x1b8) = iVar1;
    if (iVar1 != 0) {
      uVar3 = 1;
      goto LAB_0006908e;
    }
  }
  uVar3 = 0xffffffff;
LAB_0006908e:
  if (local_14 == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar3);
}

