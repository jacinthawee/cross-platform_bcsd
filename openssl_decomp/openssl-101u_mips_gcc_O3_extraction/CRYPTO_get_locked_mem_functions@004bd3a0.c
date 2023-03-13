
void CRYPTO_get_locked_mem_functions(m *m,f *f)

{
  if (m != (m *)0x0) {
    if ((code *)malloc_locked_ex_func == default_malloc_locked_ex) {
      *(undefined **)m = malloc_locked_func;
    }
    else {
      *(undefined4 *)m = 0;
    }
  }
  if (f != (f *)0x0) {
    *(undefined **)f = free_locked_func;
  }
  return;
}

