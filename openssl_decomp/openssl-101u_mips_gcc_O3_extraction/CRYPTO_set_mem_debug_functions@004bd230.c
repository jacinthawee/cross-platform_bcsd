
int CRYPTO_set_mem_debug_functions(m *m,r *r,f *f,so *so,go *go)

{
  if (allow_customize_debug == 0) {
    return 0;
  }
  OPENSSL_init();
  malloc_debug_func = m;
  set_debug_options_func = so;
  realloc_debug_func = r;
  get_debug_options_func = go;
  free_debug_func = f;
  return 1;
}

