
char * BUF_strdup(char *str)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char cVar5;
  uint uVar6;
  char *pcVar4;
  
  if (str == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = (*(code *)PTR_strlen_006aab30)();
  uVar6 = iVar1 + 1;
  pcVar2 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uVar6,"buf_str.c",0x4b);
  if (pcVar2 == (char *)0x0) {
    ERR_put_error(7,0x68,0x41,"buf_str.c",0x4e);
    pcVar2 = (char *)0x0;
  }
  else {
    pcVar4 = pcVar2;
    if (uVar6 < 2) {
      if (uVar6 == 0) {
        return pcVar2;
      }
    }
    else {
      cVar5 = *str;
      if (cVar5 != '\0') {
        do {
          pcVar3 = pcVar4 + 1;
          *pcVar4 = cVar5;
          str = str + 1;
          pcVar4 = pcVar2 + iVar1;
          if (pcVar3 == pcVar2 + iVar1) break;
          cVar5 = *str;
          pcVar4 = pcVar3;
        } while (cVar5 != '\0');
      }
    }
    *pcVar4 = '\0';
  }
  return pcVar2;
}

