
int BIO_socket_ioctl(int fd,long type,void *arg)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (*(code *)PTR_ioctl_006a9a88)();
  if (-1 < iVar1) {
    return iVar1;
  }
  piVar2 = (int *)(*(code *)PTR___errno_location_006a99e8)();
  ERR_put_error(2,5,*piVar2,"b_sock.c",0x22f);
  return iVar1;
}
