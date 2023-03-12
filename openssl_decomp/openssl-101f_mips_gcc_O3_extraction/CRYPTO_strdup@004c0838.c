
char * CRYPTO_strdup(char *str,char *file,int line)

{
  int iVar1;
  undefined *puVar2;
  char *pcVar3;
  
  iVar1 = (*(code *)PTR_strlen_006aab30)();
  iVar1 = iVar1 + 1;
  if (0 < iVar1) {
    allow_customize = 0;
    if (malloc_debug_func != (code *)0x0) {
      allow_customize_debug = 0;
      (*malloc_debug_func)(0,iVar1,file,line,0);
    }
    puVar2 = (undefined *)(*(code *)malloc_ex_func)(iVar1,file,line);
    if (malloc_debug_func != (code *)0x0) {
      (*malloc_debug_func)(puVar2,iVar1,file,line,1);
    }
    if (puVar2 != (undefined *)0x0) {
      if (0x800 < iVar1) {
        *puVar2 = *PTR_cleanse_ctr_006a959c;
      }
      goto LAB_004c0918;
    }
  }
  puVar2 = (undefined *)0x0;
LAB_004c0918:
  pcVar3 = (char *)(*(code *)PTR_strcpy_006aab74)(puVar2,str);
  return pcVar3;
}

