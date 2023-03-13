
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

hostent * gethostbyaddr(void *__addr,__socklen_t __len,int __type)

{
  hostent *phVar1;
  
  phVar1 = (hostent *)(*(code *)PTR_gethostbyaddr_082f1070)();
  return phVar1;
}

