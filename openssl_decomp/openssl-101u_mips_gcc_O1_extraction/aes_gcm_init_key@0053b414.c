
undefined4 aes_gcm_init_key(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x60);
  if (param_3 == 0) {
    if (param_2 == 0) {
      return 1;
    }
    (*(code *)PTR_AES_set_encrypt_key_006a79ec)(param_2,*(int *)(param_1 + 0x58) << 3,iVar1);
    (*(code *)PTR_CRYPTO_gcm128_init_006a8a38)(iVar1 + 0x100,iVar1,PTR_AES_encrypt_006a7ac0);
    *(undefined4 *)(iVar1 + 0x28c) = 0;
    if ((*(int *)(iVar1 + 0xf8) == 0) || (param_3 = *(int *)(iVar1 + 0x278), param_3 == 0))
    goto LAB_0053b4a0;
  }
  else {
    if (param_2 == 0) {
      if (*(int *)(iVar1 + 0xf4) == 0) {
        (*(code *)PTR_memcpy_006a9aec)
                  (*(undefined4 *)(iVar1 + 0x278),param_3,*(undefined4 *)(iVar1 + 0x27c));
      }
      else {
        (*(code *)PTR_CRYPTO_gcm128_setiv_006a7ac4)
                  (iVar1 + 0x100,param_3,*(undefined4 *)(iVar1 + 0x27c));
      }
      *(undefined4 *)(iVar1 + 0xf8) = 1;
      *(undefined4 *)(iVar1 + 0x284) = 0;
      return 1;
    }
    (*(code *)PTR_AES_set_encrypt_key_006a79ec)(param_2,*(int *)(param_1 + 0x58) << 3,iVar1);
    (*(code *)PTR_CRYPTO_gcm128_init_006a8a38)(iVar1 + 0x100,iVar1,PTR_AES_encrypt_006a7ac0);
    *(undefined4 *)(iVar1 + 0x28c) = 0;
  }
  (*(code *)PTR_CRYPTO_gcm128_setiv_006a7ac4)(iVar1 + 0x100,param_3,*(undefined4 *)(iVar1 + 0x27c));
  *(undefined4 *)(iVar1 + 0xf8) = 1;
LAB_0053b4a0:
  *(undefined4 *)(iVar1 + 0xf4) = 1;
  return 1;
}

