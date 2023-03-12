
undefined4 aes_ccm_init_key(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x60);
  if (param_3 == 0) {
    if (param_2 != 0) {
      (*(code *)PTR_AES_set_encrypt_key_006a79ec)(param_2,*(int *)(param_1 + 0x58) << 3,iVar1);
      (*(code *)PTR_CRYPTO_ccm128_init_006a8a5c)
                (iVar1 + 0x110,*(undefined4 *)(iVar1 + 0x108),*(undefined4 *)(iVar1 + 0x104),iVar1,
                 PTR_AES_encrypt_006a7ac0);
      *(undefined4 *)(iVar1 + 0xf4) = 1;
      *(undefined4 *)(iVar1 + 0x140) = 0;
      return 1;
    }
  }
  else {
    if (param_2 != 0) {
      (*(code *)PTR_AES_set_encrypt_key_006a79ec)(param_2,*(int *)(param_1 + 0x58) << 3,iVar1);
      (*(code *)PTR_CRYPTO_ccm128_init_006a8a5c)
                (iVar1 + 0x110,*(undefined4 *)(iVar1 + 0x108),*(undefined4 *)(iVar1 + 0x104),iVar1,
                 PTR_AES_encrypt_006a7ac0);
      *(undefined4 *)(iVar1 + 0x140) = 0;
      *(undefined4 *)(iVar1 + 0xf4) = 1;
    }
    (*(code *)PTR_memcpy_006a9aec)(param_1 + 0x20,param_3,0xf - *(int *)(iVar1 + 0x104));
    *(undefined4 *)(iVar1 + 0xf8) = 1;
  }
  return 1;
}

