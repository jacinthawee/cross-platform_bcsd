
void CRYPTO_get_mem_functions(m *m,r *r,f *f)

{
  undefined *puVar1;
  
  if (m != (m *)0x0) {
    puVar1 = (undefined *)0x0;
    if ((code *)malloc_ex_func == default_malloc_ex) {
      puVar1 = malloc_func;
    }
    *(undefined **)m = puVar1;
  }
  if (r != (r *)0x0) {
    puVar1 = (undefined *)0x0;
    if ((code *)realloc_ex_func == default_realloc_ex) {
      puVar1 = realloc_func;
    }
    *(undefined **)r = puVar1;
  }
  if (f != (f *)0x0) {
    *(undefined **)f = free_func;
  }
  return;
}

