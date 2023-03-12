
size_t BUF_strlcpy(char *dst,char *src,size_t siz)

{
  byte *pbVar1;
  size_t sVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  
  pcVar4 = dst;
  if (siz < 2) {
    if (siz == 0) goto LAB_0009cc42;
    sVar2 = 0;
  }
  else {
    uVar5 = (uint)(byte)*src;
    sVar2 = uVar5;
    if (uVar5 != 0) {
      pcVar3 = dst;
      pbVar1 = (byte *)(src + 1);
      do {
        src = (char *)pbVar1;
        siz = siz - 1;
        pcVar4 = pcVar3 + 1;
        *pcVar3 = (char)uVar5;
        sVar2 = (int)pcVar4 - (int)dst;
        if (siz == 1) break;
        uVar5 = (uint)(byte)*src;
        pcVar3 = pcVar4;
        pbVar1 = (byte *)src + 1;
      } while (uVar5 != 0);
    }
  }
  *pcVar4 = '\0';
  siz = sVar2;
LAB_0009cc42:
  sVar2 = strlen(src);
  return sVar2 + siz;
}

