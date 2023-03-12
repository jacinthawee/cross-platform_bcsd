
char * BUF_strndup(char *str,size_t siz)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  uint num;
  char *pcVar4;
  
  pcVar1 = str;
  if (str != (char *)0x0) {
    num = siz + 1;
    pcVar1 = (char *)CRYPTO_malloc(num,"buf_str.c",0x4b);
    if (pcVar1 == (char *)0x0) {
      ERR_put_error(7,0x68,0x41,"buf_str.c",0x4e);
    }
    else {
      pcVar3 = pcVar1;
      if (num < 2) {
LAB_0009e3c4:
        if (num == 0) {
          return pcVar1;
        }
      }
      else {
        cVar2 = *str;
        if (cVar2 != '\0') {
          pcVar4 = pcVar1;
          do {
            pcVar3 = pcVar4 + 1;
            *pcVar4 = cVar2;
            num = num - 1;
            if (pcVar3 == pcVar1 + siz) goto LAB_0009e3c4;
            str = str + 1;
            cVar2 = *str;
            pcVar4 = pcVar3;
          } while (cVar2 != '\0');
        }
      }
      *pcVar3 = '\0';
    }
  }
  return pcVar1;
}

