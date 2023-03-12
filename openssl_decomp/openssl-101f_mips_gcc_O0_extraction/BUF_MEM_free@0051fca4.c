
void BUF_MEM_free(BUF_MEM *a)

{
  if (a != (BUF_MEM *)0x0) {
    if (a->data != (char *)0x0) {
      (*(code *)PTR_memset_006aab00)(a->data,0,a->max);
      (*(code *)PTR_CRYPTO_free_006a7f88)(a->data);
    }
                    /* WARNING: Could not recover jumptable at 0x0051fd00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a7f88)(a);
    return;
  }
  return;
}

