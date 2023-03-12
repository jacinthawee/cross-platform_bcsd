
undefined4 rc2_ofb_cipher(int param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  int iVar1;
  uchar *out;
  uchar *in;
  uint uVar2;
  
  if (0x3fffffff < param_4) {
    out = param_2;
    in = param_3;
    uVar2 = param_4;
    do {
      uVar2 = uVar2 + 0xc0000000;
      RC2_ofb64_encrypt(in,out,0x40000000,(RC2_KEY *)(*(int *)(param_1 + 0x60) + 4),
                        (uchar *)(param_1 + 0x20),(int *)(param_1 + 0x50));
      out = out + 0x40000000;
      in = in + 0x40000000;
    } while (0x3fffffff < uVar2);
    uVar2 = param_4 + 0xc0000000;
    param_4 = param_4 & 0x3fffffff;
    iVar1 = (uVar2 & 0xc0000000) + 0x40000000;
    param_3 = param_3 + iVar1;
    param_2 = param_2 + iVar1;
  }
  if (param_4 != 0) {
    RC2_ofb64_encrypt(param_3,param_2,param_4,(RC2_KEY *)(*(int *)(param_1 + 0x60) + 4),
                      (uchar *)(param_1 + 0x20),(int *)(param_1 + 0x50));
  }
  return 1;
}
