
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void X509_PURPOSE_cleanup(void)

{
  undefined4 *ptr;
  
  sk_pop_free(xptable,xptable_free + 1);
  ptr = (undefined4 *)&xstandard;
  do {
    if ((ptr != (undefined4 *)0x0) && ((int)(ptr[2] << 0x1f) < 0)) {
      if ((int)(ptr[2] << 0x1e) < 0) {
        CRYPTO_free((void *)ptr[4]);
        CRYPTO_free((void *)ptr[5]);
      }
      CRYPTO_free(ptr);
    }
    ptr = ptr + 7;
  } while (ptr != &CONF_str_functs);
  xptable = (_STACK *)0x0;
  return;
}

