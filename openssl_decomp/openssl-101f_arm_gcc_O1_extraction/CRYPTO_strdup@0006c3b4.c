
char * CRYPTO_strdup(char *str,char *file,int line)

{
  size_t sVar1;
  char *__dest;
  int iVar2;
  
  sVar1 = strlen(str);
  iVar2 = sVar1 + 1;
  if (iVar2 < 1) {
    __dest = (char *)0x0;
  }
  else {
    allow_customize = 0;
    if (malloc_debug_func != (code *)0x0) {
      allow_customize_debug = 0;
      (*malloc_debug_func)(0,iVar2,file,line,0);
    }
    __dest = (char *)(*malloc_ex_func)(iVar2,file,line);
    if (malloc_debug_func != (code *)0x0) {
      (*malloc_debug_func)(__dest,iVar2,file,line,1);
    }
  }
  strcpy(__dest,str);
  return __dest;
}

