
int BIO_socket_nbio(int fd,int mode)

{
  int iVar1;
  int *piVar2;
  int in_GS_OFFSET;
  int local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = mode;
  iVar1 = ioctl(fd,0x5421,&local_14);
  if (iVar1 < 0) {
    piVar2 = __errno_location();
    ERR_put_error(2,5,*piVar2,"b_sock.c",0x244);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return (uint)(iVar1 == 0);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

