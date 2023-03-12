
int SSL_COMP_add_compression_method(int id,COMP_METHOD *cm)

{
  int *data;
  int iVar1;
  
  if ((cm == (COMP_METHOD *)0x0) || (cm->type == 0)) {
    return 1;
  }
  if (id - 0xc1U < 0x3f) {
    CRYPTO_mem_ctrl(3);
    data = (int *)CRYPTO_malloc(0xc,"ssl_ciph.c",0x75a);
    *data = id;
    data[2] = (int)cm;
    load_builtin_compressions();
    if (ssl_comp_methods == (_STACK *)0x0) {
LAB_0006488a:
      CRYPTO_free(data);
      CRYPTO_mem_ctrl(2);
      ERR_put_error(0x14,0xa5,0x41,"ssl_ciph.c",0x768);
      return 1;
    }
    iVar1 = sk_find(ssl_comp_methods,data);
    if (iVar1 < 0) {
      if ((ssl_comp_methods == (_STACK *)0x0) ||
         (iVar1 = sk_push(ssl_comp_methods,data), iVar1 == 0)) goto LAB_0006488a;
      CRYPTO_mem_ctrl(2);
      iVar1 = 0;
    }
    else {
      CRYPTO_free(data);
      CRYPTO_mem_ctrl(2);
      ERR_put_error(0x14,0xa5,0x135,"ssl_ciph.c",0x762);
      iVar1 = 1;
    }
  }
  else {
    ERR_put_error(0x14,0xa5,0x133,"ssl_ciph.c",0x755);
    iVar1 = 0;
  }
  return iVar1;
}

