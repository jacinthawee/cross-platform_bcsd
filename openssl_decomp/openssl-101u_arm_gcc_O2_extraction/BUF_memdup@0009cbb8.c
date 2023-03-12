
void * BUF_memdup(void *data,size_t siz)

{
  void *pvVar1;
  
  if (data != (void *)0x0 && siz < 0x7fffffff) {
    pvVar1 = CRYPTO_malloc(siz,"buf_str.c",100);
    if (pvVar1 != (void *)0x0) {
      pvVar1 = (void *)(*(code *)PTR_memcpy_00189054)(pvVar1,data,siz);
      return pvVar1;
    }
    ERR_put_error(7,0x67,0x41,"buf_str.c",0x66);
  }
  return (void *)0x0;
}

