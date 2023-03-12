
void SSL_srp_server_param_with_username(int param_1,undefined4 *param_2)

{
  int iVar1;
  BIGNUM *pBVar2;
  code *pcVar3;
  uchar auStack_4c [48];
  int local_1c;
  
  local_1c = __TMC_END__;
  pcVar3 = *(code **)(param_1 + 0x198);
  *param_2 = 0x73;
  if ((pcVar3 == (code *)0x0) ||
     (iVar1 = (*pcVar3)(param_1,param_2,*(undefined4 *)(param_1 + 0x194)), iVar1 == 0)) {
    iVar1 = *(int *)(param_1 + 0x1a8);
    *param_2 = 0x50;
    if (((iVar1 == 0) ||
        (((*(int *)(param_1 + 0x1ac) == 0 || (*(int *)(param_1 + 0x1b0) == 0)) ||
         (*(int *)(param_1 + 0x1c4) == 0)))) || (iVar1 = RAND_bytes(auStack_4c,0x30), iVar1 < 1)) {
      iVar1 = 2;
    }
    else {
      pBVar2 = BN_bin2bn(auStack_4c,0x30,(BIGNUM *)0x0);
      *(BIGNUM **)(param_1 + 0x1c0) = pBVar2;
      OPENSSL_cleanse(auStack_4c,0x30);
      iVar1 = SRP_Calc_B(*(undefined4 *)(param_1 + 0x1c0),*(undefined4 *)(param_1 + 0x1a8),
                         *(undefined4 *)(param_1 + 0x1ac),*(undefined4 *)(param_1 + 0x1c4));
      *(int *)(param_1 + 0x1b4) = iVar1;
      if (iVar1 == 0) {
        iVar1 = 2;
      }
      else {
        iVar1 = 0;
      }
    }
  }
  if (local_1c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}

