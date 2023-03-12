
char * BUF_strndup(char *str,size_t siz)

{
  char *pcVar1;
  char *pcVar2;
  char cVar4;
  uint uVar5;
  char *pcVar3;
  
  if (str == (char *)0x0) {
    return (char *)0x0;
  }
  uVar5 = siz + 1;
  pcVar1 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uVar5,"buf_str.c",0x4b);
  if (pcVar1 == (char *)0x0) {
    ERR_put_error(7,0x68,0x41,"buf_str.c",0x4e);
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar3 = pcVar1;
    if (uVar5 < 2) {
      if (uVar5 == 0) {
        return pcVar1;
      }
    }
    else {
      cVar4 = *str;
      if (cVar4 != '\0') {
        do {
          pcVar2 = pcVar3 + 1;
          *pcVar3 = cVar4;
          str = str + 1;
          pcVar3 = pcVar1 + siz;
          if (pcVar2 == pcVar1 + siz) break;
          cVar4 = *str;
          pcVar3 = pcVar2;
        } while (cVar4 != '\0');
      }
    }
    *pcVar3 = '\0';
  }
  return pcVar1;
}

