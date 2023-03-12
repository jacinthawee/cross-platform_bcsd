
char * BUF_strndup(char *str,size_t siz)

{
  uint num;
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  
  if (str == (char *)0x0) {
    pcVar1 = (char *)0x0;
  }
  else {
    num = siz + 1;
    pcVar1 = (char *)CRYPTO_malloc(num,"buf_str.c",0x4b);
    if (pcVar1 == (char *)0x0) {
      ERR_put_error(7,0x68,0x41,"buf_str.c",0x4e);
      pcVar1 = (char *)0x0;
    }
    else {
      pcVar4 = pcVar1;
      if (num < 2) {
        if (num == 0) {
          return pcVar1;
        }
      }
      else {
        cVar2 = *str;
        if (cVar2 != '\0') {
          do {
            pcVar3 = pcVar4 + 1;
            str = str + 1;
            *pcVar4 = cVar2;
            pcVar4 = pcVar1 + siz;
            if (pcVar3 == pcVar1 + siz) break;
            cVar2 = *str;
            pcVar4 = pcVar3;
          } while (cVar2 != '\0');
        }
      }
      *pcVar4 = '\0';
    }
  }
  return pcVar1;
}

