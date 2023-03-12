
int SRP_Calc_A_param(int param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined auStack_44 [48];
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_RAND_bytes_006a7574)(auStack_44,0x30);
  if (0 < iVar2) {
    uVar3 = (*(code *)PTR_BN_bin2bn_006a7904)(auStack_44,0x30,*(undefined4 *)(param_1 + 0x1bc));
    *(undefined4 *)(param_1 + 0x1bc) = uVar3;
    OPENSSL_cleanse(auStack_44,0x30);
    iVar2 = (*(code *)PTR_SRP_Calc_A_006a846c)
                      (*(undefined4 *)(param_1 + 0x1bc),*(undefined4 *)(param_1 + 0x1a8),
                       *(undefined4 *)(param_1 + 0x1ac));
    *(int *)(param_1 + 0x1b8) = iVar2;
    if (iVar2 != 0) {
      iVar2 = 1;
      goto LAB_004bbb80;
    }
  }
  iVar2 = -1;
LAB_004bbb80:
  if (local_14 == *(int *)puVar1) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (*(int *)(local_14 + 0x1ac) != 0) {
    return *(int *)(local_14 + 0x1ac);
  }
  return *(int *)(*(int *)(local_14 + 0xe4) + 0x17c);
}

