
size_t BUF_strlcat(char *dst,char *src,size_t siz)

{
  bool bVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char cVar6;
  
  if (siz == 0) {
    pcVar3 = (char *)0x0;
LAB_0051e5a0:
    iVar4 = (*(code *)PTR_strlen_006a9a24)(src);
    return (size_t)(pcVar3 + iVar4);
  }
  if (*dst == '\0') {
    pcVar3 = (char *)0x0;
    bVar1 = siz < 2;
  }
  else {
    pcVar3 = (char *)0x0;
    do {
      siz = siz - 1;
      dst = dst + 1;
      pcVar3 = pcVar3 + 1;
      if (siz == 0) goto LAB_0051e5a0;
      bVar1 = siz < 2;
    } while (*dst != '\0');
  }
  if (bVar1) {
    *dst = '\0';
  }
  else {
    cVar6 = *src;
    if (cVar6 == '\0') {
      *dst = '\0';
    }
    else {
      pcVar2 = src + 1;
      do {
        pcVar5 = pcVar2;
        *dst = cVar6;
        siz = siz - 1;
        dst = dst + 1;
        if (siz == 1) break;
        cVar6 = *pcVar5;
        pcVar2 = pcVar5 + 1;
      } while (cVar6 != '\0');
      pcVar3 = pcVar5 + ((int)pcVar3 - (int)src);
      *dst = '\0';
      src = pcVar5;
    }
  }
  iVar4 = (*(code *)PTR_strlen_006a9a24)(src);
  return (size_t)(pcVar3 + iVar4);
}

