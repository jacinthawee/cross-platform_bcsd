
void dtls1_clear_received_buffer(int param_1)

{
  int iVar1;
  
  while (iVar1 = (*(code *)PTR_pqueue_pop_006a827c)
                           (*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x244)), iVar1 != 0) {
    dtls1_hm_fragment_free(*(undefined4 *)(iVar1 + 8));
    (*(code *)PTR_pitem_free_006a8278)(iVar1);
  }
  return;
}

