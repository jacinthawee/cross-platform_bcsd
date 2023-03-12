
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int int_err_get_next_lib(void)

{
  int iVar1;
  
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,1,"err.c",0x227);
  iVar1 = int_err_library_number;
  int_err_library_number = int_err_library_number + 1;
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,1,"err.c",0x229);
  return iVar1;
}

