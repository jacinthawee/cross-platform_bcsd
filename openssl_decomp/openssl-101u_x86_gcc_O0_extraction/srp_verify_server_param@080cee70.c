
undefined4 srp_verify_server_param(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = BN_ucmp(*(BIGNUM **)(param_1 + 0x1ac),*(BIGNUM **)(param_1 + 0x1a8));
  if (((-1 < iVar1) ||
      (iVar1 = BN_ucmp(*(BIGNUM **)(param_1 + 0x1b4),*(BIGNUM **)(param_1 + 0x1a8)), -1 < iVar1)) ||
     (*(int *)(*(int *)(param_1 + 0x1b4) + 4) == 0)) {
    *param_2 = 0x2f;
    return 0;
  }
  iVar1 = BN_num_bits(*(BIGNUM **)(param_1 + 0x1a8));
  if (iVar1 < *(int *)(param_1 + 0x1cc)) {
LAB_080cef30:
    *param_2 = 0x47;
    uVar2 = 0;
  }
  else {
    if (*(code **)(param_1 + 0x19c) == (code *)0x0) {
      iVar1 = SRP_check_known_gN_param
                        (*(undefined4 *)(param_1 + 0x1ac),*(undefined4 *)(param_1 + 0x1a8));
      if (iVar1 == 0) goto LAB_080cef30;
    }
    else {
      iVar1 = (**(code **)(param_1 + 0x19c))(param_1,*(undefined4 *)(param_1 + 0x194));
      if (iVar1 < 1) goto LAB_080cef30;
    }
    uVar2 = 1;
  }
  return uVar2;
}

