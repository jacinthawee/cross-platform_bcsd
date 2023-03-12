
int SSL_srp_server_param_with_username
              (int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  code *pcVar7;
  undefined auStack_44 [48];
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pcVar7 = *(code **)(param_1 + 0x198);
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  *param_2 = 0x73;
  puVar6 = param_2;
  if (pcVar7 != (code *)0x0) {
    param_3 = *(undefined4 *)(param_1 + 0x194);
    iVar2 = (*pcVar7)(param_1,param_2,param_3);
    if (iVar2 != 0) goto LAB_004bb2e0;
  }
  iVar2 = *(int *)(param_1 + 0x1a8);
  *param_2 = 0x50;
  if (iVar2 != 0) {
    iVar2 = 2;
    if ((*(int *)(param_1 + 0x1ac) == 0) || (iVar2 = 2, *(int *)(param_1 + 0x1b0) == 0))
    goto LAB_004bb2e0;
    if (*(int *)(param_1 + 0x1c4) != 0) {
      puVar6 = (undefined4 *)&DAT_00000030;
      iVar2 = (*(code *)PTR_RAND_bytes_006a7574)(auStack_44,0x30);
      if (0 < iVar2) {
        uVar3 = (*(code *)PTR_BN_bin2bn_006a7904)(auStack_44,0x30,0);
        *(undefined4 *)(param_1 + 0x1c0) = uVar3;
        OPENSSL_cleanse(auStack_44,0x30);
        param_4 = *(undefined4 *)(param_1 + 0x1c4);
        param_3 = *(undefined4 *)(param_1 + 0x1ac);
        puVar6 = *(undefined4 **)(param_1 + 0x1a8);
        iVar2 = (*(code *)PTR_SRP_Calc_B_006a8448)
                          (*(undefined4 *)(param_1 + 0x1c0),puVar6,param_3,param_4);
        *(int *)(param_1 + 0x1b4) = iVar2;
        if (iVar2 != 0) {
          iVar2 = 0;
          goto LAB_004bb2e0;
        }
      }
    }
  }
  iVar2 = 2;
LAB_004bb2e0:
  if (local_14 == *(int *)puVar1) {
    return iVar2;
  }
  iVar2 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar4 = (*(code *)PTR_SRP_get_default_gN_006a7f2c)(param_4);
  if (iVar4 == 0) {
    iVar2 = -1;
  }
  else {
    uVar3 = (*(code *)PTR_BN_dup_006a8218)(*(undefined4 *)(iVar4 + 8));
    puVar1 = PTR_BN_dup_006a8218;
    uVar5 = *(undefined4 *)(iVar4 + 4);
    *(undefined4 *)(iVar2 + 0x1a8) = uVar3;
    uVar3 = (*(code *)puVar1)(uVar5);
    *(undefined4 *)(iVar2 + 0x1ac) = uVar3;
    if (*(int *)(iVar2 + 0x1c4) != 0) {
      (*(code *)PTR_BN_clear_free_006a7fa8)();
      *(undefined4 *)(iVar2 + 0x1c4) = 0;
    }
    if (*(int *)(iVar2 + 0x1b0) != 0) {
      (*(code *)PTR_BN_clear_free_006a7fa8)();
      *(undefined4 *)(iVar2 + 0x1b0) = 0;
    }
    iVar4 = (*(code *)PTR_SRP_create_verifier_BN_006a844c)
                      (puVar6,param_3,iVar2 + 0x1b0,iVar2 + 0x1c4,*(undefined4 *)(iVar4 + 8),
                       *(undefined4 *)(iVar4 + 4));
    iVar2 = -1;
    if (iVar4 != 0) {
      iVar2 = 1;
    }
  }
  return iVar2;
}

