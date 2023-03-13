
undefined4 idea_cfb64_cipher(int param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  uint uVar1;
  uchar *puVar2;
  uint uVar3;
  
  uVar3 = 0x40000000;
  if (param_4 < 0x40000000) {
    uVar3 = param_4;
  }
  if (param_4 != 0) {
    do {
      uVar1 = param_4 - uVar3;
      puVar2 = param_3 + uVar3;
      idea_cfb64_encrypt(param_3,param_2,param_4,*(IDEA_KEY_SCHEDULE **)(param_1 + 0x60),
                         (uchar *)(param_1 + 0x20),(int *)(param_1 + 0x50),*(int *)(param_1 + 8));
      param_2 = param_2 + uVar3;
      if (uVar1 < uVar3) {
        uVar3 = uVar1;
      }
    } while ((uVar1 != 0) && (param_4 = uVar1, param_3 = puVar2, uVar3 <= uVar1));
  }
  return 1;
}

