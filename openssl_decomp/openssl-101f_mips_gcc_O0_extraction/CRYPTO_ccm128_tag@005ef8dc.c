
uint CRYPTO_ccm128_tag(byte *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = (((uint)*param_1 << 0x1a) >> 0x1d) * 2 + 2;
  if (param_3 < uVar1) {
    return 0;
  }
  (*(code *)PTR_memcpy_006aabf4)(param_2,param_1 + 0x10,uVar1,param_4,&_gp);
  return uVar1;
}

