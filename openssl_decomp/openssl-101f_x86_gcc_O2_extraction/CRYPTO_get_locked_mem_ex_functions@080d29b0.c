
void CRYPTO_get_locked_mem_ex_functions(m *m,f *f)

{
  undefined *puVar1;
  
  if (m != (m *)0x0) {
    puVar1 = malloc_locked_ex_func;
    if ((code *)malloc_locked_ex_func == default_malloc_locked_ex) {
      puVar1 = (undefined *)0x0;
    }
    *(undefined **)m = puVar1;
  }
  if (f != (f *)0x0) {
    *(undefined **)f = free_locked_func;
  }
  return;
}

