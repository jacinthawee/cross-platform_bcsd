
undefined4 aes_cfb8_cipher(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  CRYPTO_cfb128_8_encrypt
            (param_3,param_2,param_4,*(int *)(param_1 + 0x60),param_1 + 0x20,param_1 + 0x50,
             *(undefined4 *)(param_1 + 8),*(undefined4 *)(*(int *)(param_1 + 0x60) + 0xf4));
  return 1;
}

