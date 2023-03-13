
undefined4 des_cbc_cipher(int param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  int iVar1;
  uchar *output;
  uint uVar2;
  uchar *input;
  
  if (0x3fffffff < param_4) {
    output = param_2;
    uVar2 = param_4;
    input = param_3;
    do {
      uVar2 = uVar2 + 0xc0000000;
      DES_ncbc_encrypt(input,output,0x40000000,*(DES_key_schedule **)(param_1 + 0x60),
                       (DES_cblock *)(param_1 + 0x20),*(int *)(param_1 + 8));
      output = output + 0x40000000;
      input = input + 0x40000000;
    } while (0x3fffffff < uVar2);
    uVar2 = param_4 + 0xc0000000;
    param_4 = param_4 & 0x3fffffff;
    iVar1 = (uVar2 & 0xc0000000) + 0x40000000;
    param_3 = param_3 + iVar1;
    param_2 = param_2 + iVar1;
  }
  if (param_4 != 0) {
    DES_ncbc_encrypt(param_3,param_2,param_4,*(DES_key_schedule **)(param_1 + 0x60),
                     (DES_cblock *)(param_1 + 0x20),*(int *)(param_1 + 8));
  }
  return 1;
}

