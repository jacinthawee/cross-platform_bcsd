
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int poll(pollfd *__fds,nfds_t __nfds,int __timeout)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_poll_001890b0)();
  return iVar1;
}
