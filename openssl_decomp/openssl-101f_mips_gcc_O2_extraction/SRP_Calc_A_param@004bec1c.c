
int SRP_Calc_A_param(int param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined auStack_44 [48];
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(param_1 + 0x1a8));
  if (*(int *)(param_1 + 0x1cc) <= iVar2) {
    if (*(int *)(param_1 + 0x19c) == 0) {
      iVar2 = (*(code *)PTR_SRP_check_known_gN_param_006a8a34)
                        (*(undefined4 *)(param_1 + 0x1ac),*(undefined4 *)(param_1 + 0x1a8));
      if (iVar2 == 0) goto LAB_004bed34;
    }
    (*(code *)PTR_RAND_bytes_006a8d44)(auStack_44,0x30);
    uVar3 = (*(code *)PTR_BN_bin2bn_006a89f0)(auStack_44,0x30,*(undefined4 *)(param_1 + 0x1bc));
    *(undefined4 *)(param_1 + 0x1bc) = uVar3;
    OPENSSL_cleanse(auStack_44,0x30);
    iVar2 = (*(code *)PTR_SRP_Calc_A_006a958c)
                      (*(undefined4 *)(param_1 + 0x1bc),*(undefined4 *)(param_1 + 0x1a8),
                       *(undefined4 *)(param_1 + 0x1ac));
    *(int *)(param_1 + 0x1b8) = iVar2;
    if (iVar2 != 0) {
      iVar2 = 1;
      if (*(code **)(param_1 + 0x19c) != (code *)0x0) {
        iVar2 = (**(code **)(param_1 + 0x19c))(param_1,*(undefined4 *)(param_1 + 0x194));
      }
      goto LAB_004becfc;
    }
  }
LAB_004bed34:
  iVar2 = -1;
LAB_004becfc:
  if (local_14 == *(int *)puVar1) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (*(int *)(local_14 + 0x1ac) != 0) {
    return *(int *)(local_14 + 0x1ac);
  }
  return *(int *)(*(int *)(local_14 + 0xe4) + 0x17c);
}

