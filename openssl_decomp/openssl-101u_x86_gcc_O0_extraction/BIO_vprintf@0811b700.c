
int BIO_vprintf(BIO *bio,char *format,va_list args)

{
  int iVar1;
  int in_GS_OFFSET;
  int local_834;
  undefined *local_830;
  undefined4 local_82c;
  void *local_828;
  undefined local_824 [4];
  undefined local_820 [2048];
  int local_20;
  
  local_82c = 0x800;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_828 = (void *)0x0;
  local_830 = local_820;
  CRYPTO_push_info_("doapr()","b_print.c",0x32a);
  iVar1 = _dopr(&local_834,local_824,format,args);
  if (iVar1 == 0) {
    CRYPTO_free(local_828);
    iVar1 = -1;
  }
  else {
    if (local_828 == (void *)0x0) {
      iVar1 = BIO_write(bio,local_820,local_834);
    }
    else {
      iVar1 = BIO_write(bio,local_828,local_834);
      CRYPTO_free(local_828);
    }
    CRYPTO_pop_info();
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

