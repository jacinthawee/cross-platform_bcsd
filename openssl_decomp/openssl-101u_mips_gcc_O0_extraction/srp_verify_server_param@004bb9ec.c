
undefined4 srp_verify_server_param(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)PTR_BN_ucmp_006a7fb4)
                    (*(undefined4 *)(param_1 + 0x1ac),*(undefined4 *)(param_1 + 0x1a8));
  if (((-1 < iVar1) ||
      (iVar1 = (*(code *)PTR_BN_ucmp_006a7fb4)
                         (*(undefined4 *)(param_1 + 0x1b4),*(undefined4 *)(param_1 + 0x1a8)),
      -1 < iVar1)) || (*(int *)(*(int *)(param_1 + 0x1b4) + 4) == 0)) {
    *param_2 = 0x2f;
    return 0;
  }
  iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)(param_1 + 0x1a8));
  if (iVar1 < *(int *)(param_1 + 0x1cc)) {
LAB_004bbad0:
    uVar2 = 0;
    *param_2 = 0x47;
  }
  else {
    if (*(code **)(param_1 + 0x19c) == (code *)0x0) {
      iVar1 = (*(code *)PTR_SRP_check_known_gN_param_006a7948)
                        (*(undefined4 *)(param_1 + 0x1ac),*(undefined4 *)(param_1 + 0x1a8));
      if (iVar1 == 0) goto LAB_004bbad0;
    }
    else {
      iVar1 = (**(code **)(param_1 + 0x19c))(param_1,*(undefined4 *)(param_1 + 0x194));
      if (iVar1 < 1) goto LAB_004bbad0;
    }
    uVar2 = 1;
  }
  return uVar2;
}

