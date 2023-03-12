
undefined4 read_lebn(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  
  iVar1 = *param_1;
  puVar2 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(param_2,FUN_0066ce4c,0x60);
  if (puVar2 != (undefined *)0x0) {
    if (param_2 != 0) {
      puVar3 = puVar2;
      puVar5 = (undefined *)(iVar1 + param_2 + -1);
      do {
        puVar4 = puVar3 + 1;
        *puVar3 = *puVar5;
        puVar3 = puVar4;
        puVar5 = puVar5 + -1;
      } while (puVar4 != puVar2 + param_2);
    }
    iVar1 = (*(code *)PTR_BN_bin2bn_006a89f0)(puVar2,param_2,0);
    puVar3 = PTR_CRYPTO_free_006a7f88;
    *param_3 = iVar1;
    (*(code *)puVar3)(puVar2);
    if (*param_3 != 0) {
      *param_1 = *param_1 + param_2;
      return 1;
    }
  }
  return 0;
}

