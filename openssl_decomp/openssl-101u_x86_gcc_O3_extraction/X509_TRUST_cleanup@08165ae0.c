
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void X509_TRUST_cleanup(void)

{
  undefined1 *ptr;
  
  ptr = trstandard;
  do {
    if (((undefined **)ptr != (undefined **)0x0) && (((uint)*(undefined **)((int)ptr + 4) & 1) != 0)
       ) {
      if (((uint)*(undefined **)((int)ptr + 4) & 2) != 0) {
        CRYPTO_free(*(undefined **)((int)ptr + 0xc));
      }
      CRYPTO_free(ptr);
    }
    ptr = (undefined1 *)((int)ptr + 0x18);
  } while ((undefined **)ptr != &default_trust);
  sk_pop_free(trtable,trtable_free);
  trtable = (_STACK *)0x0;
  return;
}

