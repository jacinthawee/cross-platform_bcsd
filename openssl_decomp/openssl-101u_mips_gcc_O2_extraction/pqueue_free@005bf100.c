
void pqueue_free(pqueue pq)

{
  if (pq != (pqueue)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005bf110. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    return;
  }
  return;
}

