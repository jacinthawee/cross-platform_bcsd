
undefined4 gost_imit_init_cpa(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  *(undefined4 *)(iVar1 + 0x1020) = 0;
  *(undefined4 *)(iVar1 + 0x1024) = 0;
  *(undefined4 *)(iVar1 + 0x1028) = 0;
  *(undefined4 *)(iVar1 + 0x102c) = 0;
  *(undefined4 *)(iVar1 + 0x1030) = 0;
  *(undefined4 *)(iVar1 + 0x1038) = 0;
  *(undefined4 *)(iVar1 + 0x1034) = 1;
  gost_init(iVar1,Gost28147_CryptoProParamSetA);
  return 1;
}

