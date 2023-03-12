
int CRYPTO_set_mem_ex_functions(m *m,r *r,f *f)

{
  f *pfVar1;
  undefined *puVar2;
  
  pfVar1 = allow_customize;
  if (allow_customize != (f *)0x0) {
    puVar2 = (undefined *)(uint)(r == (r *)0x0 || m == (m *)0x0);
    if (r == (r *)0x0 || m == (m *)0x0) {
      pfVar1 = (f *)0x0;
    }
    else {
      pfVar1 = f;
      if (f != (f *)0x0) {
        pfVar1 = (f *)0x1;
        malloc_func = puVar2;
        realloc_func = puVar2;
        malloc_locked_func = puVar2;
        malloc_ex_func = m;
        realloc_ex_func = r;
        free_func = f;
        malloc_locked_ex_func = m;
        free_locked_func = f;
      }
    }
  }
  return (int)pfVar1;
}

