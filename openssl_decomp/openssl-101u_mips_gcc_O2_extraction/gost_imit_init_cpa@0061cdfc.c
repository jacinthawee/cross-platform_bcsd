
undefined4 gost_imit_init_cpa(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_Gost28147_CryptoProParamSetA_006a98a0;
  iVar2 = *(int *)(param_1 + 0xc);
  *(undefined4 *)(iVar2 + 0x1034) = 1;
  *(undefined *)(iVar2 + 0x1020) = 0;
  *(undefined *)(iVar2 + 0x1021) = 0;
  *(undefined *)(iVar2 + 0x1022) = 0;
  *(undefined *)(iVar2 + 0x1023) = 0;
  *(undefined *)(iVar2 + 0x1024) = 0;
  *(undefined *)(iVar2 + 0x1025) = 0;
  *(undefined *)(iVar2 + 0x1026) = 0;
  *(undefined *)(iVar2 + 0x1027) = 0;
  *(undefined *)(iVar2 + 0x1028) = 0;
  *(undefined *)(iVar2 + 0x1029) = 0;
  *(undefined *)(iVar2 + 0x102a) = 0;
  *(undefined *)(iVar2 + 0x102b) = 0;
  *(undefined *)(iVar2 + 0x102c) = 0;
  *(undefined *)(iVar2 + 0x102d) = 0;
  *(undefined *)(iVar2 + 0x102e) = 0;
  *(undefined *)(iVar2 + 0x102f) = 0;
  *(undefined4 *)(iVar2 + 0x1030) = 0;
  *(undefined4 *)(iVar2 + 0x1038) = 0;
  gost_init(iVar2,puVar1,param_3,param_4,&_gp);
  return 1;
}

