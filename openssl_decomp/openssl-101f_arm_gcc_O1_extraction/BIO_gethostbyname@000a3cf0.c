
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

hostent * BIO_gethostbyname(char *__name)

{
  hostent *phVar1;
  
  phVar1 = (hostent *)(*(code *)PTR_gethostbyname_0018a1d4)();
  return phVar1;
}

