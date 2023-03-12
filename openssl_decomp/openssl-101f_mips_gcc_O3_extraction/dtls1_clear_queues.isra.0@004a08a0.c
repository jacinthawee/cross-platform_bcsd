
void dtls1_clear_queues_isra_0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  while (iVar1 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*param_1 + 0x238)), iVar1 != 0)
  {
    iVar2 = *(int *)(iVar1 + 8);
    if (*(int *)(iVar2 + 8) != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)(*(int *)(iVar2 + 8));
      iVar2 = *(int *)(iVar1 + 8);
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
    (*(code *)PTR_pitem_free_006a939c)(iVar1);
  }
  while (iVar1 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*param_1 + 0x240)), iVar1 != 0)
  {
    iVar2 = *(int *)(iVar1 + 8);
    if (*(int *)(iVar2 + 8) != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)(*(int *)(iVar2 + 8));
      iVar2 = *(int *)(iVar1 + 8);
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
    (*(code *)PTR_pitem_free_006a939c)(iVar1);
  }
  while (iVar1 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*param_1 + 0x244)), iVar1 != 0)
  {
    iVar2 = *(int *)(iVar1 + 8);
    (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(iVar2 + 0x2c));
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
    (*(code *)PTR_pitem_free_006a939c)(iVar1);
  }
  iVar1 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*param_1 + 0x248));
  if (iVar1 == 0) goto LAB_004a0aa8;
  do {
    iVar2 = *(int *)(iVar1 + 8);
    (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(iVar2 + 0x2c));
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
    (*(code *)PTR_pitem_free_006a939c)(iVar1);
    iVar1 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*param_1 + 0x248));
  } while (iVar1 != 0);
  iVar1 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*param_1 + 0x250));
  while (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 8);
    (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(iVar2 + 0x2c));
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
    (*(code *)PTR_pitem_free_006a939c)(iVar1);
LAB_004a0aa8:
    iVar1 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*param_1 + 0x250));
  }
  return;
}

