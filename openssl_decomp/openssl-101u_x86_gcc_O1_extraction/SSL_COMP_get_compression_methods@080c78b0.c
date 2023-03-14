
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

stack_st_SSL_COMP * SSL_COMP_get_compression_methods(void)

{
  char *pcVar1;
  int in_EAX;
  undefined4 *ptr;
  COMP_METHOD *pCVar2;
  
  CRYPTO_lock(in_EAX,5,&DAT_00000010,(int)"ssl_ciph.c");
  if (ssl_comp_methods != (_STACK *)0x0) {
    CRYPTO_lock(in_EAX,6,&DAT_00000010,(int)"ssl_ciph.c");
    return (stack_st_SSL_COMP *)ssl_comp_methods;
  }
  CRYPTO_lock(in_EAX,6,&DAT_00000010,(int)"ssl_ciph.c");
  CRYPTO_lock(in_EAX,9,&DAT_00000010,(int)"ssl_ciph.c");
  if (ssl_comp_methods == (_STACK *)0x0) {
    CRYPTO_mem_ctrl(3);
    ssl_comp_methods = sk_new(sk_comp_cmp);
    if (ssl_comp_methods != (_STACK *)0x0) {
      ptr = (undefined4 *)CRYPTO_malloc(0xc,"ssl_ciph.c",0x1d3);
      if (ptr != (undefined4 *)0x0) {
        pCVar2 = COMP_zlib();
        ptr[2] = pCVar2;
        if ((pCVar2 == (COMP_METHOD *)0x0) || (pCVar2->type != 0)) {
          pcVar1 = pCVar2->name;
          *ptr = 1;
          ptr[1] = pcVar1;
          sk_push(ssl_comp_methods,ptr);
        }
        else {
          CRYPTO_free(ptr);
        }
      }
      sk_sort(ssl_comp_methods);
    }
    in_EAX = CRYPTO_mem_ctrl(2);
  }
  CRYPTO_lock(in_EAX,10,&DAT_00000010,(int)"ssl_ciph.c");
  return (stack_st_SSL_COMP *)ssl_comp_methods;
}
