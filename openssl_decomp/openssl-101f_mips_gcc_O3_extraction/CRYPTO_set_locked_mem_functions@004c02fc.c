
int CRYPTO_set_locked_mem_functions(m *m,free_func *free_func)

{
  int iVar1;
  
  iVar1 = allow_customize;
  if (((allow_customize != 0) && (iVar1 = 0, m != (m *)0x0)) && (free_func != (free_func *)0x0)) {
    malloc_locked_func = m;
    malloc_locked_ex_func = default_malloc_locked_ex;
    free_locked_func = free_func;
    return 1;
  }
  return iVar1;
}

