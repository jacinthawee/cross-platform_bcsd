
int CRYPTO_set_mem_ex_functions(m *m,r *r,f *f)

{
  int iVar1;
  
  iVar1 = allow_customize;
  if (allow_customize != 0) {
    if ((m == (m *)0x0 || r == (r *)0x0) || (f == (f *)0x0)) {
      return 0;
    }
    malloc_func = (undefined *)0x0;
    malloc_ex_func = m;
    realloc_func = (undefined *)0x0;
    free_func = f;
    malloc_locked_func = (undefined *)0x0;
    realloc_ex_func = r;
    malloc_locked_ex_func = m;
    iVar1 = 1;
    free_locked_func = f;
  }
  return iVar1;
}

