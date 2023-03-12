
int BIO_socket_nbio(int fd,int mode)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int local_14 [2];
  
  local_14[0] = mode;
  iVar1 = ioctl(fd,0x5421,local_14);
  if (-1 < iVar1) {
    uVar2 = count_leading_zeroes(iVar1);
    return uVar2 >> 5;
  }
  piVar3 = __errno_location();
  ERR_put_error(2,5,*piVar3,"b_sock.c",0x244);
  uVar2 = count_leading_zeroes(iVar1);
  return uVar2 >> 5;
}

