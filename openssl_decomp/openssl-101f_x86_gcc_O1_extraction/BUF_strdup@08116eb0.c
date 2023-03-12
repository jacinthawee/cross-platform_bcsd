
char * BUF_strdup(char *str)

{
  uint num;
  size_t sVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (str == (char *)0x0) {
    pcVar2 = (char *)0x0;
  }
  else {
    sVar1 = strlen(str);
    num = sVar1 + 1;
    pcVar2 = (char *)CRYPTO_malloc(num,"buf_str.c",0x4b);
    if (pcVar2 == (char *)0x0) {
      ERR_put_error(7,0x68,0x41,"buf_str.c",0x4e);
      pcVar2 = (char *)0x0;
    }
    else {
      pcVar5 = pcVar2;
      if (num < 2) {
        if (num == 0) {
          return pcVar2;
        }
      }
      else {
        cVar3 = *str;
        if (cVar3 != '\0') {
          do {
            pcVar4 = pcVar5 + 1;
            str = str + 1;
            *pcVar5 = cVar3;
            pcVar5 = pcVar2 + sVar1;
            if (pcVar4 == pcVar2 + sVar1) break;
            cVar3 = *str;
            pcVar5 = pcVar4;
          } while (cVar3 != '\0');
        }
      }
      *pcVar5 = '\0';
    }
  }
  return pcVar2;
}

