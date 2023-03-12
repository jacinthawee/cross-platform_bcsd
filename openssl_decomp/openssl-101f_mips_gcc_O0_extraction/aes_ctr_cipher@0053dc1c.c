
undefined4 aes_ctr_cipher(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar2 = *(int *)(param_1 + 0x60);
  iVar9 = *(int *)(param_1 + 0x50);
  iVar8 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (*(int *)(iVar2 + 0xf8) == 0) {
    (*(code *)PTR_CRYPTO_ctr128_encrypt_006a9b34)(param_3);
  }
  else {
    (*(code *)PTR_CRYPTO_ctr128_encrypt_ctr32_006a9b30)();
  }
  iVar3 = *(int *)puVar1;
  *(int *)(param_1 + 0x50) = iVar9;
  if (iVar8 == iVar3) {
    return 1;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar3 = *(int *)(iVar8 + 0x60);
  if (param_4 == (undefined4 *)0x0) {
    if (iVar9 == 0) {
      return 1;
    }
  }
  else if (iVar9 == 0) goto LAB_0053dda4;
  iVar6 = *(int *)(iVar8 + 0x58);
  *(undefined4 *)(iVar3 + 0x1f8) = 0;
  puVar1 = PTR_AES_encrypt_006a8b90;
  if (iVar2 == 0) {
    (*(code *)PTR_AES_set_decrypt_key_006a9b38)(iVar9,iVar6 << 2);
    *(undefined **)(iVar3 + 0x1f0) = PTR_AES_decrypt_006a95f8;
  }
  else {
    (*(code *)PTR_AES_set_encrypt_key_006a8adc)(iVar9,iVar6 << 2,iVar3);
    *(undefined **)(iVar3 + 0x1f0) = puVar1;
  }
  (*(code *)PTR_AES_set_encrypt_key_006a8adc)
            (iVar9 + *(int *)(iVar8 + 0x58) / 2,*(int *)(iVar8 + 0x58) << 2,iVar3 + 0xf4);
  *(undefined **)(iVar3 + 500) = puVar1;
  *(int *)(iVar3 + 0x1e8) = iVar3;
  if (param_4 == (undefined4 *)0x0) {
    return 1;
  }
LAB_0053dda4:
  *(int *)(iVar3 + 0x1ec) = iVar3 + 0xf4;
  uVar7 = param_4[1];
  uVar5 = param_4[2];
  uVar4 = param_4[3];
  *(undefined4 *)(iVar8 + 0x20) = *param_4;
  *(undefined4 *)(iVar8 + 0x24) = uVar7;
  *(undefined4 *)(iVar8 + 0x28) = uVar5;
  *(undefined4 *)(iVar8 + 0x2c) = uVar4;
  return 1;
}

