
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 surewarehk_ctrl(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2 == 1) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_sureware.c",0x19a);
    if (logstream != 0) {
      (*(code *)PTR_BIO_free_006a6e70)();
      logstream = 0;
    }
    iVar2 = (*(code *)PTR_CRYPTO_add_lock_006a805c)(param_4 + 0x2c,1,0x15,"e_sureware.c",0x19f);
    iVar1 = param_4;
    if (iVar2 < 2) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,100,100,"e_sureware.c",0x1a3);
      iVar1 = logstream;
    }
    logstream = iVar1;
    uVar3 = 0x1a5;
  }
  else {
    if (param_2 != 0x65) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,100,0x77,"e_sureware.c",0x1b7);
      return 0;
    }
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_sureware.c",0x1af);
    uVar3 = 0x1b1;
    threadsafe = 0;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"e_sureware.c",uVar3);
  return 1;
}

