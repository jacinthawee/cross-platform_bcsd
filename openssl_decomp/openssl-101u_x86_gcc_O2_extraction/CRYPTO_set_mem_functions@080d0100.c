
int CRYPTO_set_mem_functions(m *m,r *r,f *f)

{
  int iVar1;
  
  OPENSSL_init();
  iVar1 = allow_customize;
  if (allow_customize != 0) {
    if ((m == (m *)0x0 || r == (r *)0x0) || (f == (f *)0x0)) {
      iVar1 = 0;
    }
    else {
      malloc_func = m;
      malloc_ex_func = default_malloc_ex;
      realloc_ex_func = default_realloc_ex;
      free_func = f;
      malloc_locked_func = m;
      realloc_func = r;
      malloc_locked_ex_func = default_malloc_locked_ex;
      iVar1 = 1;
      free_locked_func = f;
    }
  }
  return iVar1;
}

