
void CRYPTO_get_mem_functions(m *m,r *r,f *f)

{
  undefined *puVar1;
  
  if (m != (m *)0x0) {
    puVar1 = malloc_func;
    if (malloc_ex_func != 0x69b49) {
      puVar1 = (undefined *)0x0;
    }
    *(undefined **)m = puVar1;
  }
  if (r != (r *)0x0) {
    puVar1 = realloc_func;
    if (realloc_ex_func != 0x69b55) {
      puVar1 = (undefined *)0x0;
    }
    *(undefined **)r = puVar1;
  }
  if (f != (f *)0x0) {
    *(undefined **)f = free_func;
  }
  return;
}

