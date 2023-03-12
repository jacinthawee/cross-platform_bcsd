
void dtls1_free(int param_1)

{
  ssl3_free();
  dtls1_clear_queues_isra_0(param_1 + 0x5c);
  (*(code *)PTR_pqueue_free_006a93a8)(*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x238));
  (*(code *)PTR_pqueue_free_006a93a8)(*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x240));
  (*(code *)PTR_pqueue_free_006a93a8)(*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x244));
  (*(code *)PTR_pqueue_free_006a93a8)(*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x248));
  (*(code *)PTR_pqueue_free_006a93a8)(*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x250));
  CRYPTO_free(*(void **)(param_1 + 0x5c));
  *(undefined4 *)(param_1 + 0x5c) = 0;
  return;
}

