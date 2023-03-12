
int SSL_COMP_add_compression_method(int id,COMP_METHOD *cm)

{
  int *data;
  int iVar1;
  
  if ((cm == (COMP_METHOD *)0x0) || (cm->type == 0)) {
    return 1;
  }
  if (0x3e < id - 0xc1U) {
    ERR_put_error(0x14,0xa5,0x133,"ssl_ciph.c",0x716);
    return 0;
  }
  CRYPTO_mem_ctrl(3);
  data = (int *)CRYPTO_malloc(0xc,"ssl_ciph.c",0x71b);
  data[2] = (int)cm;
  *data = id;
  load_builtin_compressions();
  if (ssl_comp_methods != (_STACK *)0x0) {
    iVar1 = sk_find(ssl_comp_methods,data);
    if (-1 < iVar1) {
      CRYPTO_free(data);
      CRYPTO_mem_ctrl(2);
      ERR_put_error(0x14,0xa5,0x135,"ssl_ciph.c",0x724);
      return 1;
    }
    if ((ssl_comp_methods != (_STACK *)0x0) && (iVar1 = sk_push(ssl_comp_methods,data), iVar1 != 0))
    {
      CRYPTO_mem_ctrl(2);
      return 0;
    }
  }
  CRYPTO_free(data);
  CRYPTO_mem_ctrl(2);
  ERR_put_error(0x14,0xa5,0x41,"ssl_ciph.c",0x72c);
  return 1;
}

