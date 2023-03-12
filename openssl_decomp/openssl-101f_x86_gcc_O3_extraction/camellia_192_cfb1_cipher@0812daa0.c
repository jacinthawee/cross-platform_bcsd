
undefined4 camellia_192_cfb1_cipher(int param_1,uchar *param_2,uchar *param_3,size_t param_4)

{
  size_t length;
  uint uVar1;
  uchar *puVar2;
  
  uVar1 = 0x8000000;
  if (param_4 < 0x8000000) {
    uVar1 = param_4;
  }
  if (param_4 != 0) {
    do {
      length = param_4 * 8;
      if ((*(byte *)(param_1 + 0x5d) & 0x20) != 0) {
        length = param_4;
      }
      param_4 = param_4 - uVar1;
      puVar2 = param_2 + uVar1;
      Camellia_cfb1_encrypt
                (param_3,param_2,length,*(CAMELLIA_KEY **)(param_1 + 0x60),(uchar *)(param_1 + 0x20)
                 ,(int *)(param_1 + 0x50),*(int *)(param_1 + 8));
      param_3 = param_3 + uVar1;
      if (param_4 < uVar1) {
        uVar1 = param_4;
      }
    } while ((param_4 != 0) && (param_2 = puVar2, uVar1 <= param_4));
  }
  return 1;
}

