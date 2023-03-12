
undefined4 gost_digest_init(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  (*(code *)PTR_memset_006aab00)(iVar1,0,0x70);
  (*(code *)PTR_gost_init_006aa6d4)(iVar1 + 0x70,PTR_GostR3411_94_CryptoProParamSet_006aa6d8);
  *(int *)(iVar1 + 8) = iVar1 + 0x70;
  return 1;
}

