
undefined4 idea_ecb_cipher(int *param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  uint uVar1;
  uchar *in;
  uchar *puVar2;
  
  uVar1 = *(uint *)(*param_1 + 4);
  if (uVar1 <= param_4) {
    in = param_3;
    do {
      puVar2 = in + uVar1;
      idea_ecb_encrypt(in,param_2,(IDEA_KEY_SCHEDULE *)param_1[0x18]);
      in = puVar2;
      param_2 = param_2 + uVar1;
    } while ((uint)((int)puVar2 - (int)param_3) <= param_4 - uVar1);
  }
  return 1;
}

