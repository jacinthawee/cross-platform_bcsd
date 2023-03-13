
void dtls1_free(int param_1)

{
  ssl3_free();
  dtls1_clear_queues(param_1);
  (*(code *)PTR_pqueue_free_006a8288)(*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x238));
  (*(code *)PTR_pqueue_free_006a8288)(*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x240));
  (*(code *)PTR_pqueue_free_006a8288)(*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x244));
  (*(code *)PTR_pqueue_free_006a8288)(*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x248));
  (*(code *)PTR_pqueue_free_006a8288)(*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x250));
  (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(param_1 + 0x5c));
  *(undefined4 *)(param_1 + 0x5c) = 0;
  return;
}

