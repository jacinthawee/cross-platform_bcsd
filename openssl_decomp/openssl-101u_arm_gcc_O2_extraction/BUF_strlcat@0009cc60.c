
size_t BUF_strlcat(char *dst,char *src,size_t siz)

{
  byte *pbVar1;
  size_t sVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  size_t sVar6;
  uint uVar7;
  
  sVar6 = siz;
  if (siz == 0) {
LAB_0009cc82:
    sVar2 = strlen(src);
    return sVar2 + sVar6;
  }
  sVar6 = (size_t)(byte)*dst;
  if (sVar6 != 0) {
    sVar6 = 0;
    pcVar4 = dst + 1;
    do {
      dst = pcVar4;
      siz = siz - 1;
      sVar6 = sVar6 + 1;
      if (siz == 0) goto LAB_0009cc82;
      pcVar4 = dst + 1;
    } while (*dst != '\0');
  }
  pcVar4 = dst;
  if (siz < 2) {
    uVar7 = 0;
  }
  else {
    uVar5 = (uint)(byte)*src;
    uVar7 = uVar5;
    if (uVar5 != 0) {
      pcVar3 = dst;
      pbVar1 = (byte *)(src + 1);
      do {
        src = (char *)pbVar1;
        siz = siz - 1;
        pcVar4 = pcVar3 + 1;
        *pcVar3 = (char)uVar5;
        uVar7 = (int)pcVar4 - (int)dst;
        if (siz == 1) break;
        uVar5 = (uint)(byte)*src;
        pcVar3 = pcVar4;
        pbVar1 = (byte *)src + 1;
      } while (uVar5 != 0);
    }
  }
  *pcVar4 = '\0';
  sVar2 = strlen(src);
  return sVar2 + uVar7 + sVar6;
}

