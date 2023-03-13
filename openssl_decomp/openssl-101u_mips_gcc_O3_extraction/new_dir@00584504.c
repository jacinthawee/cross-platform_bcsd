
bool new_dir(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(8,"by_dir.c",0x97);
  if (piVar1 != (int *)0x0) {
    iVar2 = (*(code *)PTR_BUF_MEM_new_006a749c)();
    *piVar1 = iVar2;
    if (iVar2 == 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(piVar1);
    }
    else {
      piVar1[1] = 0;
      *(int **)(param_1 + 0xc) = piVar1;
    }
    return iVar2 != 0;
  }
  return false;
}

