
int BIO_sock_error(int sock)

{
  int iVar1;
  int iVar2;
  int in_GS_OFFSET;
  int local_18;
  socklen_t local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = 4;
  iVar1 = getsockopt(sock,1,4,&local_18,&local_14);
  iVar2 = 1;
  if (-1 < iVar1) {
    iVar2 = local_18;
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

