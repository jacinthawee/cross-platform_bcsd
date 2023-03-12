
undefined4 aes_cbc_cipher(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x60);
  if (*(code **)(iVar1 + 0xf8) != (code *)0x0) {
    (**(code **)(iVar1 + 0xf8))
              (param_3,param_2,param_4,iVar1,param_1 + 0x20,*(undefined4 *)(param_1 + 8));
    return 1;
  }
  (*(code *)PTR_CRYPTO_cbc128_encrypt_006a9600)
            (param_3,param_2,param_4,iVar1,param_1 + 0x20,*(undefined4 *)(iVar1 + 0xf4),&_gp);
  return 1;
}

