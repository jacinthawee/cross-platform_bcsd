
undefined4 aes_xts_init_key(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 0x60);
  if (param_3 == (undefined4 *)0x0) {
    if (param_2 == 0) {
      return 1;
    }
  }
  else if (param_2 == 0) goto LAB_0053aac8;
  iVar4 = *(int *)(param_1 + 0x58);
  *(undefined4 *)(iVar6 + 0x1f8) = 0;
  puVar1 = PTR_AES_encrypt_006a7ac0;
  if (param_4 == 0) {
    (*(code *)PTR_AES_set_decrypt_key_006a8a1c)(param_2,iVar4 << 2);
    *(undefined **)(iVar6 + 0x1f0) = PTR_AES_decrypt_006a84d8;
  }
  else {
    (*(code *)PTR_AES_set_encrypt_key_006a79ec)(param_2,iVar4 << 2,iVar6);
    *(undefined **)(iVar6 + 0x1f0) = puVar1;
  }
  (*(code *)PTR_AES_set_encrypt_key_006a79ec)
            (param_2 + *(int *)(param_1 + 0x58) / 2,*(int *)(param_1 + 0x58) << 2,iVar6 + 0xf4);
  *(undefined **)(iVar6 + 500) = puVar1;
  *(int *)(iVar6 + 0x1e8) = iVar6;
  if (param_3 == (undefined4 *)0x0) {
    return 1;
  }
LAB_0053aac8:
  *(int *)(iVar6 + 0x1ec) = iVar6 + 0xf4;
  uVar5 = param_3[1];
  uVar3 = param_3[2];
  uVar2 = param_3[3];
  *(undefined4 *)(param_1 + 0x20) = *param_3;
  *(undefined4 *)(param_1 + 0x24) = uVar5;
  *(undefined4 *)(param_1 + 0x28) = uVar3;
  *(undefined4 *)(param_1 + 0x2c) = uVar2;
  return 1;
}

