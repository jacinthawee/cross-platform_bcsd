
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CRYPTO_EX_DATA_IMPL * CRYPTO_get_ex_data_implementation(void)

{
  CRYPTO_EX_DATA_IMPL *mode;
  
  if ((CRYPTO_EX_DATA_IMPL *)impl != (CRYPTO_EX_DATA_IMPL *)0x0) {
    return (CRYPTO_EX_DATA_IMPL *)impl;
  }
  CRYPTO_lock(0,9,(char *)0x2,(int)"ex_data.c");
  mode = (CRYPTO_EX_DATA_IMPL *)impl;
  if ((CRYPTO_EX_DATA_IMPL *)impl == (CRYPTO_EX_DATA_IMPL *)0x0) {
    impl = impl_default;
  }
  CRYPTO_lock((int)mode,10,(char *)0x2,(int)"ex_data.c");
  return (CRYPTO_EX_DATA_IMPL *)impl;
}

