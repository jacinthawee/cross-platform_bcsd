
undefined4 ssl2_new(undefined4 *param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = (*(code *)PTR_CRYPTO_malloc_006a8108)(0x120,"s2_lib.c",0x143);
  if (iVar2 == 0) {
    return 0;
  }
  (*(code *)PTR_memset_006aab00)(iVar2,0,0x120);
  iVar3 = (*(code *)PTR_CRYPTO_malloc_006a8108)(0x8001,"s2_lib.c",0x14b);
  *(int *)(iVar2 + 0x30) = iVar3;
  if (iVar3 == 0) {
    if (*(int *)(iVar2 + 0x34) == 0) goto LAB_0047c2e0;
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  else {
    iVar3 = (*(code *)PTR_CRYPTO_malloc_006a8108)(0x8002,"s2_lib.c",0x14f);
    *(int *)(iVar2 + 0x34) = iVar3;
    puVar1 = PTR_memset_006aab00;
    if (iVar3 != 0) {
      uVar4 = *(undefined4 *)(iVar2 + 0x30);
      param_1[0x15] = iVar2;
      (*(code *)puVar1)(iVar2,0,0x120);
      *(int *)(iVar2 + 0x34) = iVar3;
      *(undefined4 *)(iVar2 + 4) = 1;
      *(undefined4 *)(iVar2 + 0x30) = uVar4;
      param_1[0x13] = uVar4;
      *param_1 = 2;
      param_1[0x14] = 0;
      return 1;
    }
  }
  if (*(int *)(iVar2 + 0x30) != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
LAB_0047c2e0:
  (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
  return 0;
}

