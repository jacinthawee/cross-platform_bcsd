
undefined4 des_ede_ofb_cipher(int param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  DES_key_schedule *pDVar1;
  int iVar2;
  uchar *out;
  uchar *in;
  uint uVar3;
  uchar *local_2c;
  
  local_2c = param_2;
  if (0x3fffffff < param_4) {
    out = param_2;
    in = param_3;
    uVar3 = param_4;
    do {
      pDVar1 = *(DES_key_schedule **)(param_1 + 0x60);
      uVar3 = uVar3 + 0xc0000000;
      DES_ede3_ofb64_encrypt
                (in,out,0x40000000,pDVar1,pDVar1 + 1,pDVar1 + 2,(DES_cblock *)(param_1 + 0x20),
                 (int *)(param_1 + 0x50));
      out = out + 0x40000000;
      in = in + 0x40000000;
    } while (0x3fffffff < uVar3);
    uVar3 = param_4 + 0xc0000000;
    param_4 = param_4 & 0x3fffffff;
    iVar2 = (uVar3 & 0xc0000000) + 0x40000000;
    param_3 = param_3 + iVar2;
    local_2c = param_2 + iVar2;
  }
  if (param_4 != 0) {
    pDVar1 = *(DES_key_schedule **)(param_1 + 0x60);
    DES_ede3_ofb64_encrypt
              (param_3,local_2c,param_4,pDVar1,pDVar1 + 1,pDVar1 + 2,(DES_cblock *)(param_1 + 0x20),
               (int *)(param_1 + 0x50));
  }
  return 1;
}
