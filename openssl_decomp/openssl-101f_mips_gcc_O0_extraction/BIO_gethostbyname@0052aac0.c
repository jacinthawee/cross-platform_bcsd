
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

hostent * BIO_gethostbyname(char *__name)

{
  hostent *phVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0052aacc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  phVar1 = (hostent *)(*(code *)PTR_gethostbyname_006aaa70)();
  return phVar1;
}

