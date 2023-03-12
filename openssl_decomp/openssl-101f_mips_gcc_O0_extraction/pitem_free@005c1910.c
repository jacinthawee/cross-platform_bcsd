
void pitem_free(pitem *item)

{
  if (item != (pitem *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005c1920. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    return;
  }
  return;
}

