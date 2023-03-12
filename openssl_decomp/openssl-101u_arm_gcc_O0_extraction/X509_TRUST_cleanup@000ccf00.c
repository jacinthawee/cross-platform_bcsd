
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void X509_TRUST_cleanup(void)

{
  undefined *ptr;
  undefined *puVar1;
  
  puVar1 = PTR_trstandard_000ccf44 + 0xc0;
  ptr = PTR_trstandard_000ccf44;
  do {
    if ((ptr != (undefined *)0x0) && (*(int *)(ptr + 4) << 0x1f < 0)) {
      if (*(int *)(ptr + 4) << 0x1e < 0) {
        CRYPTO_free(*(void **)(ptr + 0xc));
      }
      CRYPTO_free(ptr);
    }
    ptr = ptr + 0x18;
  } while (ptr != puVar1);
  sk_pop_free(trtable,trtable_free + 1);
  trtable = (_STACK *)0x0;
  return;
}

