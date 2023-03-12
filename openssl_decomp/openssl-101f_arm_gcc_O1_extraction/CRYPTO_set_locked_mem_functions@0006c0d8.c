
int CRYPTO_set_locked_mem_functions(m *m,free_func *free_func)

{
  if ((allow_customize != 0) && (free_func != (free_func *)0x0 && m != (m *)0x0)) {
    malloc_locked_func = m;
    free_locked_func = free_func;
    malloc_locked_ex_func = 0x6c03d;
    return 1;
  }
  return 0;
}

