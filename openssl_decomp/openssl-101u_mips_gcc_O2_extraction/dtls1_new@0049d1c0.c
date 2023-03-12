
undefined4 dtls1_new(int param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = ssl3_new();
  if ((iVar2 != 0) &&
     (iVar2 = (*(code *)PTR_CRYPTO_malloc_006a7008)(0x2ec,"d1_lib.c",0x67), iVar2 != 0)) {
    (*(code *)PTR_memset_006a99f4)(iVar2,0,0x2ec);
    uVar3 = (*(code *)PTR_pqueue_new_006a8284)();
    puVar1 = PTR_pqueue_new_006a8284;
    *(undefined4 *)(iVar2 + 0x238) = uVar3;
    uVar3 = (*(code *)puVar1)();
    puVar1 = PTR_pqueue_new_006a8284;
    *(undefined4 *)(iVar2 + 0x240) = uVar3;
    uVar3 = (*(code *)puVar1)();
    puVar1 = PTR_pqueue_new_006a8284;
    *(undefined4 *)(iVar2 + 0x244) = uVar3;
    uVar3 = (*(code *)puVar1)();
    puVar1 = PTR_pqueue_new_006a8284;
    *(undefined4 *)(iVar2 + 0x248) = uVar3;
    iVar4 = (*(code *)puVar1)();
    iVar5 = *(int *)(param_1 + 0x24);
    *(int *)(iVar2 + 0x250) = iVar4;
    if (iVar5 != 0) {
      *(undefined4 *)(iVar2 + 0x204) = 0x100;
    }
    *(undefined4 *)(iVar2 + 600) = 0;
    *(undefined4 *)(iVar2 + 0x25c) = 0;
    if (*(int *)(iVar2 + 0x238) != 0) {
      if ((((*(int *)(iVar2 + 0x240) != 0) && (*(int *)(iVar2 + 0x244) != 0)) &&
          (*(int *)(iVar2 + 0x248) != 0)) && (iVar4 != 0)) {
        *(int *)(param_1 + 0x5c) = iVar2;
        (**(code **)(*(int *)(param_1 + 8) + 8))(param_1);
        return 1;
      }
      (*(code *)PTR_pqueue_free_006a8288)();
    }
    if (*(int *)(iVar2 + 0x240) != 0) {
      (*(code *)PTR_pqueue_free_006a8288)();
    }
    if (*(int *)(iVar2 + 0x244) != 0) {
      (*(code *)PTR_pqueue_free_006a8288)();
    }
    if (*(int *)(iVar2 + 0x248) != 0) {
      (*(code *)PTR_pqueue_free_006a8288)();
    }
    if (*(int *)(iVar2 + 0x250) != 0) {
      (*(code *)PTR_pqueue_free_006a8288)();
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar2);
  }
  return 0;
}

