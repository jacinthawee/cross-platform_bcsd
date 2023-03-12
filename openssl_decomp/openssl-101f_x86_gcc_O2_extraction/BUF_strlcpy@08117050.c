
size_t BUF_strlcpy(char *dst,char *src,size_t siz)

{
  char *pcVar1;
  size_t sVar2;
  char *pcVar3;
  char cVar4;
  int iVar5;
  
  pcVar3 = src;
  if (siz < 2) {
    iVar5 = 0;
    if (siz == 0) goto LAB_0811708f;
  }
  else {
    cVar4 = *src;
    pcVar1 = dst;
    if (cVar4 == '\0') {
      iVar5 = 0;
    }
    else {
      do {
        pcVar3 = pcVar3 + 1;
        siz = siz - 1;
        dst = pcVar1 + 1;
        *pcVar1 = cVar4;
        iVar5 = (int)pcVar3 - (int)src;
        if (siz == 1) break;
        cVar4 = *pcVar3;
        pcVar1 = dst;
      } while (cVar4 != '\0');
    }
  }
  *dst = '\0';
  src = pcVar3;
LAB_0811708f:
  sVar2 = strlen(src);
  return sVar2 + iVar5;
}

