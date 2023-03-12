
void dtls1_clear_queues(int param_1)

{
  int iVar1;
  int iVar2;
  
  while (iVar1 = (*(code *)PTR_pqueue_pop_006a827c)
                           (*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x238)), iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 8);
    if (*(int *)(iVar2 + 8) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(*(int *)(iVar2 + 8));
      iVar2 = *(int *)(iVar1 + 8);
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar2);
    (*(code *)PTR_pitem_free_006a8278)(iVar1);
  }
  while (iVar1 = (*(code *)PTR_pqueue_pop_006a827c)
                           (*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x240)), iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 8);
    if (*(int *)(iVar2 + 8) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(*(int *)(iVar2 + 8));
      iVar2 = *(int *)(iVar1 + 8);
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar2);
    (*(code *)PTR_pitem_free_006a8278)(iVar1);
  }
  while (iVar1 = (*(code *)PTR_pqueue_pop_006a827c)
                           (*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x250)), iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 8);
    if (*(int *)(iVar2 + 8) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(*(int *)(iVar2 + 8));
      iVar2 = *(int *)(iVar1 + 8);
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar2);
    (*(code *)PTR_pitem_free_006a8278)(iVar1);
  }
  while (iVar1 = (*(code *)PTR_pqueue_pop_006a827c)
                           (*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x244)), iVar1 != 0) {
    dtls1_hm_fragment_free(*(undefined4 *)(iVar1 + 8));
    (*(code *)PTR_pitem_free_006a8278)(iVar1);
  }
  iVar1 = (*(code *)PTR_pqueue_pop_006a827c)(*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x248));
  while (iVar1 != 0) {
    dtls1_hm_fragment_free(*(undefined4 *)(iVar1 + 8));
    (*(code *)PTR_pitem_free_006a8278)(iVar1);
    iVar1 = (*(code *)PTR_pqueue_pop_006a827c)(*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x248));
  }
  return;
}

