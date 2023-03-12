
int TS_VERIFY_CTX_new(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_CRYPTO_malloc_006a7008)(0x28,"ts_verify_ctx.c",0x43);
  if (iVar1 != 0) {
    (*(code *)PTR_memset_006a99f4)(iVar1,0,0x28);
    return iVar1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x90,0x41,"ts_verify_ctx.c",0x47);
  return 0;
}

