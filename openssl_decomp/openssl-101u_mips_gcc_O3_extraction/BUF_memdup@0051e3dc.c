
void * BUF_memdup(void *data,size_t siz)

{
  int iVar1;
  void *pvVar2;
  
  if ((data != (void *)0x0) && (siz < 0x7fffffff)) {
    iVar1 = (*(code *)PTR_CRYPTO_malloc_006a7008)(siz,"buf_str.c",100);
    if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0051e45c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pvVar2 = (void *)(*(code *)PTR_memcpy_006a9aec)(iVar1,data,siz);
      return pvVar2;
    }
    ERR_put_error(7,0x67,0x41,"buf_str.c",0x66);
    return (void *)0x0;
  }
  return (void *)0x0;
}

