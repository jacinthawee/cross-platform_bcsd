
void CRYPTO_get_mem_ex_functions(m *m,r *r,f *f)

{
  int iVar1;
  
  if (m != (m *)0x0) {
    iVar1 = malloc_ex_func;
    if (malloc_ex_func == 0x69b49) {
      iVar1 = 0;
    }
    *(int *)m = iVar1;
  }
  if (r != (r *)0x0) {
    iVar1 = realloc_ex_func;
    if (realloc_ex_func == 0x69b55) {
      iVar1 = 0;
    }
    *(int *)r = iVar1;
  }
  if (f != (f *)0x0) {
    *(undefined **)f = free_func;
  }
  return;
}

