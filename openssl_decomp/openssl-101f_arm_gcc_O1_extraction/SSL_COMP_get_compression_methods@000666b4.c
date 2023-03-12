
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

stack_st_SSL_COMP * SSL_COMP_get_compression_methods(void)

{
  _STACK *st;
  undefined4 *ptr;
  COMP_METHOD *pCVar1;
  char *pcVar2;
  
  CRYPTO_lock(5,0x10,"ssl_ciph.c",0x1bd);
  if (ssl_comp_methods == (_STACK *)0x0) {
    CRYPTO_lock(6,0x10,"ssl_ciph.c",0x1c0);
    CRYPTO_lock(9,0x10,"ssl_ciph.c",0x1c1);
    if (ssl_comp_methods == (_STACK *)0x0) {
      CRYPTO_mem_ctrl(3);
      ssl_comp_methods = sk_new(sk_comp_cmp + 1);
      if (ssl_comp_methods != (_STACK *)0x0) {
        ptr = (undefined4 *)CRYPTO_malloc(0xc,"ssl_ciph.c",0x1cc);
        if (ptr != (undefined4 *)0x0) {
          pCVar1 = COMP_zlib();
          ptr[2] = pCVar1;
          if ((pCVar1 == (COMP_METHOD *)0x0) || (pCVar1->type != 0)) {
            pcVar2 = pCVar1->name;
            *ptr = 1;
            st = ssl_comp_methods;
            ptr[1] = pcVar2;
            sk_push(st,ptr);
          }
          else {
            CRYPTO_free(ptr);
          }
        }
        sk_sort(ssl_comp_methods);
      }
      CRYPTO_mem_ctrl(2);
    }
    CRYPTO_lock(10,0x10,"ssl_ciph.c",0x1e1);
  }
  else {
    CRYPTO_lock(6,0x10,"ssl_ciph.c",0x1e3);
  }
  return (stack_st_SSL_COMP *)ssl_comp_methods;
}

