
void CRYPTO_get_mem_functions(m *m,r *r,f *f)

{
  if (m != (m *)0x0) {
    if ((code *)malloc_ex_func == default_malloc_ex) {
      *(undefined **)m = malloc_func;
    }
    else {
      *(undefined4 *)m = 0;
    }
  }
  if (r != (r *)0x0) {
    if ((code *)realloc_ex_func == default_realloc_ex) {
      *(undefined **)r = realloc_func;
    }
    else {
      *(undefined4 *)r = 0;
    }
  }
  if (f != (f *)0x0) {
    *(undefined **)f = free_func;
  }
  return;
}

