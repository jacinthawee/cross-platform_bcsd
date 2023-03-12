
int __regparm3 int_err_get_next_lib(int param_1)

{
  int iVar1;
  
  CRYPTO_lock(param_1,9,(char *)0x1,(int)"err.c");
  iVar1 = int_err_library_number;
  int_err_library_number = int_err_library_number + 1;
  CRYPTO_lock(int_err_library_number,10,(char *)0x1,(int)"err.c");
  return iVar1;
}

