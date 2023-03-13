
undefined4 seed_cbc_cipher(int param_1,uchar *param_2,uchar *param_3,size_t param_4)

{
  int iVar1;
  uchar *out;
  uint uVar2;
  uchar *in;
  
  if (0x3fffffff < param_4) {
    out = param_2;
    uVar2 = param_4;
    in = param_3;
    do {
      uVar2 = uVar2 + 0xc0000000;
      SEED_cbc_encrypt(in,out,0x40000000,*(SEED_KEY_SCHEDULE **)(param_1 + 0x60),
                       (uchar *)(param_1 + 0x20),*(int *)(param_1 + 8));
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
    SEED_cbc_encrypt(param_3,param_2,param_4,*(SEED_KEY_SCHEDULE **)(param_1 + 0x60),
                     (uchar *)(param_1 + 0x20),*(int *)(param_1 + 8));
  }
  return 1;
}

