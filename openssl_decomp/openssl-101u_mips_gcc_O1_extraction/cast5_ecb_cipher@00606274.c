
undefined4 cast5_ecb_cipher(int *param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  uchar *in;
  uchar *puVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(*param_1 + 4);
  in = param_3;
  if (uVar2 <= param_4) {
    do {
      puVar1 = in + uVar2;
      CAST_ecb_encrypt(in,param_2,(CAST_KEY *)param_1[0x18],param_1[2]);
      in = puVar1;
      param_2 = param_2 + uVar2;
    } while ((uint)((int)puVar1 - (int)param_3) <= param_4 - uVar2);
  }
  return 1;
}

