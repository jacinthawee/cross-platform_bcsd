
int BIO_vprintf(BIO *bio,char *format,va_list args)

{
  int iVar1;
  int local_830;
  undefined *local_82c;
  undefined4 local_828;
  void *local_824;
  undefined auStack_820 [4];
  undefined auStack_81c [2048];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_824 = (void *)0x0;
  local_828 = 0x800;
  local_82c = auStack_81c;
  CRYPTO_push_info_("doapr()","b_print.c",0x32a);
  iVar1 = _dopr(&local_82c,&local_824,&local_828,&local_830,auStack_820,format,args);
  if (iVar1 == 0) {
    CRYPTO_free(local_824);
    iVar1 = -1;
  }
  else {
    if (local_824 == (void *)0x0) {
      iVar1 = BIO_write(bio,auStack_81c,local_830);
    }
    else {
      iVar1 = BIO_write(bio,local_824,local_830);
      CRYPTO_free(local_824);
    }
    CRYPTO_pop_info();
  }
  if (local_1c == __stack_chk_guard) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

