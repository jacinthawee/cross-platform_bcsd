
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CRYPTO_EX_DATA_IMPL * CRYPTO_get_ex_data_implementation(void)

{
  if (impl != (CRYPTO_EX_DATA_IMPL *)0x0) {
    return impl;
  }
  CRYPTO_lock(9,2,"ex_data.c",0xcb);
  if (impl == (CRYPTO_EX_DATA_IMPL *)0x0) {
    impl = (CRYPTO_EX_DATA_IMPL *)PTR_impl_default_0006dd8c;
  }
  CRYPTO_lock(10,2,"ex_data.c",0xce);
  return impl;
}

