
int * OPENSSL_DIR_read(int **param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  
  if ((param_1 == (int **)0x0) || (param_2 == 0)) {
    puVar1 = (undefined4 *)(*(code *)PTR___errno_location_006a99e8)();
    *puVar1 = 0x16;
    return (int *)0x0;
  }
  puVar1 = (undefined4 *)(*(code *)PTR___errno_location_006a99e8)();
  piVar2 = *param_1;
  *puVar1 = 0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)(*(code *)PTR_calloc_006a9934)(0x1008,1);
    *param_1 = piVar2;
    if (piVar2 == (int *)0x0) {
      *puVar1 = 0xc;
      return (int *)0x0;
    }
    iVar4 = (*(code *)PTR_opendir_006a9944)(param_2);
    piVar3 = *param_1;
    *piVar2 = iVar4;
    iVar4 = *piVar3;
    if (iVar4 == 0) {
      uVar5 = *puVar1;
      (*(code *)PTR_free_006a9af0)(piVar3);
      *param_1 = (int *)0x0;
      *puVar1 = uVar5;
      return (int *)0x0;
    }
  }
  else {
    iVar4 = *piVar2;
  }
  iVar4 = (*(code *)PTR_readdir_006a99b4)(iVar4);
  if (iVar4 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    (*(code *)PTR_strncpy_006a99e0)(*param_1 + 1,iVar4 + 0xb,0x1000);
    *(undefined *)(*param_1 + 0x401) = 0;
    piVar2 = *param_1 + 1;
  }
  return piVar2;
}

