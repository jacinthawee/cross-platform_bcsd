
undefined4 aes_cfb1_cipher(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0x60);
  if ((*(byte *)(param_1 + 0x5d) & 0x20) != 0) {
    CRYPTO_cfb128_1_encrypt
              (param_3,param_2,param_4,iVar1,param_1 + 0x20,param_1 + 0x50,
               *(undefined4 *)(param_1 + 8),*(undefined4 *)(iVar1 + 0xf4));
    return 1;
  }
  uVar2 = param_4;
  if (0xfffffff < param_4) {
    do {
      uVar2 = uVar2 + 0xf0000000;
      CRYPTO_cfb128_1_encrypt
                (param_3,param_2,0x80000000,iVar1,param_1 + 0x20,param_1 + 0x50,
                 *(undefined4 *)(param_1 + 8),*(undefined4 *)(iVar1 + 0xf4));
    } while (0xfffffff < uVar2);
    param_4 = param_4 & 0xfffffff;
  }
  if (param_4 == 0) {
    return 1;
  }
  CRYPTO_cfb128_1_encrypt
            (param_3,param_2,param_4 << 3,iVar1,param_1 + 0x20,param_1 + 0x50,
             *(undefined4 *)(param_1 + 8),*(undefined4 *)(iVar1 + 0xf4));
  return 1;
}

