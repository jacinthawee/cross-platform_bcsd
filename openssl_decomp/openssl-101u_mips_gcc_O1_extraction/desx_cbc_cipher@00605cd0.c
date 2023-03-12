
undefined4 desx_cbc_cipher(int param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  int iVar1;
  DES_key_schedule *pDVar2;
  uchar *output;
  uchar *input;
  uint uVar3;
  
  if (0x3fffffff < param_4) {
    output = param_2;
    input = param_3;
    uVar3 = param_4;
    do {
      pDVar2 = *(DES_key_schedule **)(param_1 + 0x60);
      uVar3 = uVar3 + 0xc0000000;
      DES_xcbc_encrypt(input,output,0x40000000,pDVar2,(DES_cblock *)(param_1 + 0x20),
                       (const_DES_cblock *)(pDVar2 + 1),(const_DES_cblock *)(pDVar2[1].ks + 1),
                       *(int *)(param_1 + 8));
      input = input + 0x40000000;
      output = output + 0x40000000;
    } while (0x3fffffff < uVar3);
    uVar3 = param_4 + 0xc0000000;
    param_4 = param_4 & 0x3fffffff;
    iVar1 = ((uVar3 >> 0x1e) + 1) * 0x40000000;
    param_3 = param_3 + iVar1;
    param_2 = param_2 + iVar1;
  }
  if (param_4 != 0) {
    pDVar2 = *(DES_key_schedule **)(param_1 + 0x60);
    DES_xcbc_encrypt(param_3,param_2,param_4,pDVar2,(DES_cblock *)(param_1 + 0x20),
                     (const_DES_cblock *)(pDVar2 + 1),(const_DES_cblock *)(pDVar2[1].ks + 1),
                     *(int *)(param_1 + 8));
  }
  return 1;
}

