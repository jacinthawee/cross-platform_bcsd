
undefined4 pkey_ec_copy(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(8,"ec_pmeth.c",0x50);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  *piVar1 = 0;
  piVar1[1] = 0;
  *(int **)(param_1 + 0x14) = piVar1;
  piVar3 = *(int **)(param_2 + 0x14);
  if (*piVar3 != 0) {
    iVar2 = (*(code *)PTR_EC_GROUP_dup_006a86a0)();
    *piVar1 = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
  }
  piVar1[1] = piVar3[1];
  return 1;
}

