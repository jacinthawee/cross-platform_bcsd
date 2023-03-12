
undefined4 dtls1_new(int param_1)

{
  undefined *puVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar2 = ssl3_new();
  if ((iVar2 != 0) && (pvVar3 = CRYPTO_malloc(0x2e8,"d1_lib.c",100), pvVar3 != (void *)0x0)) {
    (*(code *)PTR_memset_006aab00)(pvVar3,0,0x2e8);
    uVar4 = (*(code *)PTR_pqueue_new_006a93a4)();
    puVar1 = PTR_pqueue_new_006a93a4;
    *(undefined4 *)((int)pvVar3 + 0x238) = uVar4;
    uVar4 = (*(code *)puVar1)();
    puVar1 = PTR_pqueue_new_006a93a4;
    *(undefined4 *)((int)pvVar3 + 0x240) = uVar4;
    uVar4 = (*(code *)puVar1)();
    puVar1 = PTR_pqueue_new_006a93a4;
    *(undefined4 *)((int)pvVar3 + 0x244) = uVar4;
    uVar4 = (*(code *)puVar1)();
    puVar1 = PTR_pqueue_new_006a93a4;
    *(undefined4 *)((int)pvVar3 + 0x248) = uVar4;
    iVar2 = (*(code *)puVar1)();
    iVar5 = *(int *)(param_1 + 0x24);
    *(int *)((int)pvVar3 + 0x250) = iVar2;
    if (iVar5 != 0) {
      *(undefined4 *)((int)pvVar3 + 0x204) = 0x100;
    }
    if (*(int *)((int)pvVar3 + 0x238) != 0) {
      if ((((*(int *)((int)pvVar3 + 0x240) != 0) && (*(int *)((int)pvVar3 + 0x244) != 0)) &&
          (*(int *)((int)pvVar3 + 0x248) != 0)) && (iVar2 != 0)) {
        *(void **)(param_1 + 0x5c) = pvVar3;
        (**(code **)(*(int *)(param_1 + 8) + 8))(param_1);
        return 1;
      }
      (*(code *)PTR_pqueue_free_006a93a8)();
    }
    if (*(int *)((int)pvVar3 + 0x240) != 0) {
      (*(code *)PTR_pqueue_free_006a93a8)();
    }
    if (*(int *)((int)pvVar3 + 0x244) != 0) {
      (*(code *)PTR_pqueue_free_006a93a8)();
    }
    if (*(int *)((int)pvVar3 + 0x248) != 0) {
      (*(code *)PTR_pqueue_free_006a93a8)();
    }
    if (*(int *)((int)pvVar3 + 0x250) != 0) {
      (*(code *)PTR_pqueue_free_006a93a8)();
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(pvVar3);
  }
  return 0;
}

