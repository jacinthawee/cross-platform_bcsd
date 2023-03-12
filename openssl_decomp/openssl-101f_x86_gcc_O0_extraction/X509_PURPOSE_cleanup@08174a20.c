
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void X509_PURPOSE_cleanup(void)

{
  undefined1 *ptr;
  
  ptr = xstandard;
  sk_pop_free(xptable,xptable_free);
  do {
    if ((ptr != (undefined *)0x0) && ((*(uint *)(ptr + 8) & 1) != 0)) {
      if ((*(uint *)(ptr + 8) & 2) != 0) {
        CRYPTO_free(*(void **)(ptr + 0x10));
        CRYPTO_free(*(void **)(ptr + 0x14));
      }
      CRYPTO_free(ptr);
    }
    ptr = ptr + 0x1c;
  } while (ptr != &UNK_082f63dc);
  xptable = (_STACK *)0x0;
  return;
}

