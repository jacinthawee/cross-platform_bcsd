
size_t BUF_strlcpy(char *dst,char *src,size_t siz)

{
  char *pcVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  
  pcVar1 = src;
  if (siz < 2) {
    if (siz == 0) {
      iVar4 = 0;
      goto LAB_00520428;
    }
    iVar4 = 0;
  }
  else {
    cVar3 = *src;
    if (cVar3 == '\0') {
      iVar4 = 0;
    }
    else {
      do {
        pcVar1 = pcVar1 + 1;
        *dst = cVar3;
        siz = siz - 1;
        dst = dst + 1;
        iVar4 = (int)pcVar1 - (int)src;
        if (siz == 1) break;
        cVar3 = *pcVar1;
      } while (cVar3 != '\0');
    }
  }
  *dst = '\0';
  src = pcVar1;
LAB_00520428:
  iVar2 = (*(code *)PTR_strlen_006aab30)(src);
  return iVar2 + iVar4;
}

