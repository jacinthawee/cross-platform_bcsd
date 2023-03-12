
void PEM_dek_info(char *buf,char *type,int len,char *str)

{
  int iVar1;
  char *pcVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  
  (*(code *)PTR_BUF_strlcat_006a8068)(buf,"DEK-Info: ",0x400);
  (*(code *)PTR_BUF_strlcat_006a8068)(buf,type,0x400);
  (*(code *)PTR_BUF_strlcat_006a8068)(buf,",",0x400);
  iVar1 = (*(code *)PTR_strlen_006aab30)(buf);
  iVar5 = len * 2;
  if (iVar1 + iVar5 < 0x400) {
    if (len < 1) {
      iVar5 = 0;
    }
    else {
      pcVar2 = buf + iVar1;
      pbVar3 = (byte *)str;
      do {
        pbVar4 = pbVar3 + 1;
        *pcVar2 = "0123456789ABCDEF"[(uint)((int)(char)*pbVar3 << 0x18) >> 0x1c];
        pcVar2[1] = "0123456789ABCDEF"[*pbVar3 & 0xf];
        pcVar2 = pcVar2 + 2;
        pbVar3 = pbVar4;
      } while (pbVar4 != (byte *)(str + len));
    }
    (buf + iVar1 + iVar5)[1] = '\0';
    buf[iVar1 + iVar5] = '\n';
  }
  return;
}

