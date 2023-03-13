
void PEM_dek_info(char *buf,char *type,int len,char *str)

{
  size_t sVar1;
  char *pcVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  
  iVar5 = len * 2;
  BUF_strlcat(buf,"DEK-Info: ",0x400);
  BUF_strlcat(buf,type,0x400);
  BUF_strlcat(buf,",",0x400);
  sVar1 = strlen(buf);
  if ((int)(sVar1 + iVar5) < 0x400) {
    if (len < 1) {
      iVar5 = 0;
    }
    else {
      pcVar2 = buf + sVar1;
      pbVar3 = (byte *)str;
      do {
        pbVar4 = pbVar3 + 1;
        *pcVar2 = "0123456789ABCDEF"[(char)(*pbVar3 >> 4)];
        pcVar2[1] = "0123456789ABCDEF"[*pbVar3 & 0xf];
        pcVar2 = pcVar2 + 2;
        pbVar3 = pbVar4;
      } while (pbVar4 != (byte *)(str + len));
    }
    buf[sVar1 + iVar5] = '\n';
    buf[sVar1 + iVar5 + 1] = '\0';
  }
  return;
}

