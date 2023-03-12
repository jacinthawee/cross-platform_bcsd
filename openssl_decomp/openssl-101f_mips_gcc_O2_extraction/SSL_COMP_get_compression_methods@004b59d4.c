
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

stack_st_SSL_COMP * SSL_COMP_get_compression_methods(void)

{
  undefined *puVar1;
  stack_st_SSL_COMP *psVar2;
  undefined4 *ptr;
  int *piVar3;
  int iVar4;
  
  CRYPTO_lock(5,0x10,"ssl_ciph.c",0x1bd);
  if (ssl_comp_methods != (stack_st_SSL_COMP *)0x0) {
    CRYPTO_lock(6,0x10,"ssl_ciph.c",0x1e3);
    return ssl_comp_methods;
  }
  CRYPTO_lock(6,0x10,"ssl_ciph.c",0x1c0);
  CRYPTO_lock(9,0x10,"ssl_ciph.c",0x1c1);
  if (ssl_comp_methods == (stack_st_SSL_COMP *)0x0) {
    CRYPTO_mem_ctrl(3);
    ssl_comp_methods = (stack_st_SSL_COMP *)(*(code *)PTR_sk_new_006a91b4)(sk_comp_cmp);
    if (ssl_comp_methods != (stack_st_SSL_COMP *)0x0) {
      ptr = (undefined4 *)CRYPTO_malloc(0xc,"ssl_ciph.c",0x1cc);
      if (ptr != (undefined4 *)0x0) {
        piVar3 = (int *)(*(code *)PTR_COMP_zlib_006a94d4)();
        ptr[2] = piVar3;
        psVar2 = ssl_comp_methods;
        puVar1 = PTR_sk_push_006a80a8;
        if ((piVar3 == (int *)0x0) || (*piVar3 != 0)) {
          iVar4 = piVar3[1];
          *ptr = 1;
          ptr[1] = iVar4;
          (*(code *)puVar1)(psVar2,ptr);
        }
        else {
          CRYPTO_free(ptr);
        }
      }
      (*(code *)PTR_sk_sort_006a94d8)(ssl_comp_methods);
    }
    CRYPTO_mem_ctrl(2);
  }
  CRYPTO_lock(10,0x10,"ssl_ciph.c",0x1e1);
  return ssl_comp_methods;
}
