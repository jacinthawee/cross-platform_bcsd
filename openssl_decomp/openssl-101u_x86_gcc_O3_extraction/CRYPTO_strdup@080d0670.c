
char * CRYPTO_strdup(char *str,char *file,int line)

{
  int iVar1;
  size_t sVar2;
  char *__dest;
  
  sVar2 = strlen(str);
  iVar1 = sVar2 + 1;
  if (iVar1 < 1) {
LAB_080d0748:
    __dest = (char *)0x0;
  }
  else {
    if (allow_customize != 0) {
      allow_customize = 0;
    }
    if (malloc_debug_func != (code *)0x0) {
      if (allow_customize_debug != 0) {
        allow_customize_debug = 0;
      }
      (*malloc_debug_func)(0,iVar1,file,line,0);
    }
    __dest = (char *)(*(code *)malloc_ex_func)(iVar1,file,line);
    if (malloc_debug_func != (code *)0x0) {
      (*malloc_debug_func)(__dest,iVar1,file,line,1);
    }
    if ((__dest == (char *)0x0) || (iVar1 < 0x801)) {
      if (__dest == (char *)0x0) goto LAB_080d0748;
    }
    else {
      *__dest = cleanse_ctr;
    }
    strcpy(__dest,str);
  }
  return __dest;
}

