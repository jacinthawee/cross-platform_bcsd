
char * CRYPTO_strdup(char *str,char *file,int line)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = (*(code *)PTR_strlen_006a9a24)();
  iVar1 = iVar1 + 1;
  if (0 < iVar1) {
    if (allow_customize != 0) {
      allow_customize = 0;
    }
    if (malloc_debug_func != (code *)0x0) {
      if (allow_customize_debug != 0) {
        allow_customize_debug = 0;
      }
      (*malloc_debug_func)(0,iVar1,file,line,0);
    }
    pcVar2 = (char *)(*(code *)malloc_ex_func)(iVar1,file,line);
    if (malloc_debug_func != (code *)0x0) {
      (*malloc_debug_func)(pcVar2,iVar1,file,line,1);
    }
    if (pcVar2 != (char *)0x0) {
      if (0x800 < iVar1) {
        *pcVar2 = *PTR_cleanse_ctr_006a847c;
      }
      (*(code *)PTR_strcpy_006a9a6c)(pcVar2,str);
      return pcVar2;
    }
  }
  return (char *)0x0;
}

