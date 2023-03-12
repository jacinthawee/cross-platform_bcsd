
uint aes_xts_cipher(int param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x60);
  if (*(int *)(iVar4 + 0x1e8) == 0) {
    return 0;
  }
  uVar1 = *(uint *)(iVar4 + 0x1ec);
  uVar2 = uVar1;
  if (uVar1 != 0) {
    uVar2 = (uint)(param_3 == 0 || param_2 == 0);
    if (param_3 == 0 || param_2 == 0) {
      uVar2 = 0;
    }
    else if (0xf < param_4) {
      if (*(code **)(iVar4 + 0x1f8) == (code *)0x0) {
        uVar3 = CRYPTO_xts128_encrypt
                          (iVar4 + 0x1e8,param_1 + 0x20,param_3,param_2,param_4,
                           *(undefined4 *)(param_1 + 8));
        uVar2 = count_leading_zeroes(uVar3);
        uVar2 = uVar2 >> 5;
      }
      else {
        (**(code **)(iVar4 + 0x1f8))
                  (param_3,param_2,param_4,*(int *)(iVar4 + 0x1e8),uVar1,param_1 + 0x20);
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}

