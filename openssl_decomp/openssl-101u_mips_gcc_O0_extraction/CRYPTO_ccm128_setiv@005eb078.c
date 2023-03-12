
undefined4 CRYPTO_ccm128_setiv(byte *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = PTR_memcpy_006a9aec;
  uVar2 = 0xe - (*param_1 & 7);
  if (uVar2 <= param_3) {
    *(undefined4 *)(param_1 + 8) = 0;
    param_1[0xf] = (byte)param_4;
    param_1[0xd] = (byte)(param_4 >> 0x10);
    param_1[0xc] = (byte)(param_4 >> 0x18);
    param_1[0xe] = (byte)(param_4 >> 8);
    *param_1 = *param_1 & 0xbf;
    (*(code *)puVar1)(param_1 + 1,param_2,uVar2,param_4 >> 8,&_gp);
    return 0;
  }
  return 0xffffffff;
}

