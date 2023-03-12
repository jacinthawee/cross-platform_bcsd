
size_t BUF_strlcat(char *dst,char *src,size_t siz)

{
  char cVar1;
  size_t sVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  if (siz != 0) {
    do {
      if (*dst == '\0') {
        pcVar4 = src;
        if (siz < 2) {
          iVar5 = 0;
        }
        else {
          cVar1 = *src;
          pcVar3 = dst;
          if (cVar1 != '\0') goto LAB_08117100;
          iVar5 = 0;
        }
        goto LAB_0811711c;
      }
      iVar6 = iVar6 + 1;
      dst = dst + 1;
      siz = siz - 1;
    } while (siz != 0);
  }
  goto LAB_0811712a;
  while (cVar1 = *pcVar4, pcVar3 = dst, cVar1 != '\0') {
LAB_08117100:
    pcVar4 = pcVar4 + 1;
    siz = siz - 1;
    dst = pcVar3 + 1;
    *pcVar3 = cVar1;
    iVar5 = (int)pcVar4 - (int)src;
    if (siz == 1) break;
  }
LAB_0811711c:
  *dst = '\0';
  iVar6 = iVar6 + iVar5;
  src = pcVar4;
LAB_0811712a:
  sVar2 = strlen(src);
  return sVar2 + iVar6;
}

