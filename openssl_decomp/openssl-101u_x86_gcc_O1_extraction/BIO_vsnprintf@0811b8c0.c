
int BIO_vsnprintf(char *buf,size_t n,char *format,va_list args)

{
  int iVar1;
  int in_GS_OFFSET;
  int local_18;
  int local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = _dopr(&local_18,&local_14,format,args);
  if ((iVar1 == 0) || (local_14 != 0)) {
    iVar1 = -1;
  }
  else {
    iVar1 = -1;
    if (-1 < local_18) {
      iVar1 = local_18;
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}
