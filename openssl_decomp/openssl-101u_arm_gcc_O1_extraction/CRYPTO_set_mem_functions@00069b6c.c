
int CRYPTO_set_mem_functions(m *m,r *r,f *f)

{
  OPENSSL_init();
  if (((allow_customize != 0) && (r != (r *)0x0 && m != (m *)0x0)) && (f != (f *)0x0)) {
    malloc_func = m;
    realloc_func = r;
    free_func = f;
    malloc_locked_func = m;
    free_locked_func = f;
    malloc_ex_func = 0x69b49;
    realloc_ex_func = 0x69b55;
    malloc_locked_ex_func = 0x69b61;
    return 1;
  }
  return 0;
}

