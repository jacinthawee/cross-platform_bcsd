
undefined4 aes_cfb1_cipher(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x60);
  if ((*(uint *)(param_1 + 0x5c) & 0x2000) != 0) {
    (*(code *)PTR_CRYPTO_cfb128_1_encrypt_006a8a0c)
              (param_3,param_2,param_4,iVar3,param_1 + 0x20,param_1 + 0x50,
               *(undefined4 *)(param_1 + 8),*(undefined4 *)(iVar3 + 0xf4));
    return 1;
  }
  if (param_4 < 0x10000000) {
    if (param_4 != 0) {
      uVar1 = *(undefined4 *)(iVar3 + 0xf4);
      goto LAB_0053a7fc;
    }
  }
  else {
    uVar2 = param_4;
    do {
      uVar2 = uVar2 + 0xf0000000;
      (*(code *)PTR_CRYPTO_cfb128_1_encrypt_006a8a0c)
                (param_3,param_2,0x80000000,iVar3,param_1 + 0x20,param_1 + 0x50,
                 *(undefined4 *)(param_1 + 8),*(undefined4 *)(iVar3 + 0xf4));
    } while (0xfffffff < uVar2);
    param_4 = param_4 & 0xfffffff;
    if (param_4 != 0) {
      uVar1 = *(undefined4 *)(iVar3 + 0xf4);
LAB_0053a7fc:
      (*(code *)PTR_CRYPTO_cfb128_1_encrypt_006a8a0c)
                (param_3,param_2,param_4 << 3,iVar3,param_1 + 0x20,param_1 + 0x50,
                 *(undefined4 *)(param_1 + 8),uVar1);
      return 1;
    }
  }
  return 1;
}

