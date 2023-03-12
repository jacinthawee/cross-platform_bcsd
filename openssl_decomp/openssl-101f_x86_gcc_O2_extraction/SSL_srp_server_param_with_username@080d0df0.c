
int SSL_srp_server_param_with_username(int param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  BIGNUM *pBVar3;
  int iVar4;
  int in_GS_OFFSET;
  uchar local_40 [48];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar1 = *(code **)(param_1 + 0x198);
  *param_2 = 0x73;
  if ((pcVar1 == (code *)0x0) ||
     (iVar2 = (*pcVar1)(param_1,param_2,*(undefined4 *)(param_1 + 0x194)), iVar2 == 0)) {
    iVar2 = *(int *)(param_1 + 0x1a8);
    *param_2 = 0x50;
    if ((iVar2 != 0) &&
       (((*(int *)(param_1 + 0x1ac) != 0 && (*(int *)(param_1 + 0x1b0) != 0)) &&
        (*(int *)(param_1 + 0x1c4) != 0)))) {
      iVar2 = RAND_bytes(local_40,0x30);
      if (0 < iVar2) {
        pBVar3 = BN_bin2bn(local_40,0x30,(BIGNUM *)0x0);
        *(BIGNUM **)(param_1 + 0x1c0) = pBVar3;
        OPENSSL_cleanse(local_40,0x30);
        iVar4 = SRP_Calc_B(*(undefined4 *)(param_1 + 0x1c0),*(undefined4 *)(param_1 + 0x1a8),
                           *(undefined4 *)(param_1 + 0x1ac),*(undefined4 *)(param_1 + 0x1c4));
        *(int *)(param_1 + 0x1b4) = iVar4;
        iVar2 = 0;
        if (iVar4 != 0) goto LAB_080d0ed0;
      }
    }
    iVar2 = 2;
  }
LAB_080d0ed0:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

