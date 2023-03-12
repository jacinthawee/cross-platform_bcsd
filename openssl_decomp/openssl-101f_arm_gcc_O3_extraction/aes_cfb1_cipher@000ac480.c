
undefined4 aes_cfb1_cipher(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x60);
  if (*(int *)(param_1 + 0x5c) << 0x12 < 0) {
    uVar2 = *(undefined4 *)(param_1 + 8);
  }
  else {
    if (0xfffffff < param_4) {
      uVar1 = param_4;
      do {
        uVar1 = uVar1 + 0xf0000000;
        CRYPTO_cfb128_1_encrypt
                  (param_3,param_2,0x80000000,iVar3,param_1 + 0x20,param_1 + 0x50,
                   *(undefined4 *)(param_1 + 8),*(undefined4 *)(iVar3 + 0xf4));
      } while (0xfffffff < uVar1);
      param_4 = param_4 & 0xfffffff;
    }
    if (param_4 == 0) {
      return 1;
    }
    param_4 = param_4 << 3;
    uVar2 = *(undefined4 *)(param_1 + 8);
  }
  CRYPTO_cfb128_1_encrypt
            (param_3,param_2,param_4,iVar3,param_1 + 0x20,param_1 + 0x50,uVar2,
             *(undefined4 *)(iVar3 + 0xf4));
  return 1;
}

