
int __regparm1 CRYPTO_set_ex_data_implementation(CRYPTO_EX_DATA_IMPL *i)

{
  bool bVar1;
  int in_stack_00000004;
  
  CRYPTO_lock((int)i,9,(char *)0x2,(int)"ex_data.c");
  bVar1 = impl == 0;
  if (bVar1) {
    impl = in_stack_00000004;
  }
  CRYPTO_lock(impl,10,(char *)0x2,(int)"ex_data.c");
  return (uint)bVar1;
}

