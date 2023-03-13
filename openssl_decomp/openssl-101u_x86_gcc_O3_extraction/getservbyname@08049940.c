
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

servent * getservbyname(char *__name,char *__proto)

{
  servent *psVar1;
  
  psVar1 = (servent *)(*(code *)PTR_getservbyname_082f1138)();
  return psVar1;
}

