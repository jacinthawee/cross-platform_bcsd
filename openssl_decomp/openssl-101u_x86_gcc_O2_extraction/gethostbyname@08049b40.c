
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

hostent * gethostbyname(char *__name)

{
  hostent *phVar1;
  
  phVar1 = (hostent *)(*(code *)PTR_gethostbyname_082f11b8)();
  return phVar1;
}

