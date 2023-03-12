
char * hex_to_string(uchar *buffer,long len)

{
  byte bVar1;
  char *pcVar2;
  byte *pbVar3;
  byte *pbVar4;
  char *pcVar5;
  
  if (len == 0 || buffer == (uchar *)0x0) {
    pcVar2 = (char *)0x0;
  }
  else {
    pcVar2 = (char *)CRYPTO_malloc(len * 3 + 1,"v3_utl.c",0x172);
    if (pcVar2 == (char *)0x0) {
      ERR_put_error(0x22,0x6f,0x41,"v3_utl.c",0x173);
    }
    else {
      pcVar5 = pcVar2;
      if (0 < len) {
        pbVar3 = buffer;
        do {
          *pcVar5 = "0123456789ABCDEF"[*pbVar3 >> 4];
          pbVar4 = pbVar3 + 1;
          bVar1 = *pbVar3;
          pcVar5[2] = ':';
          pcVar5[1] = "0123456789ABCDEF"[bVar1 & 0xf];
          pbVar3 = pbVar4;
          pcVar5 = pcVar5 + 3;
        } while (pbVar4 != buffer + len);
        pcVar5 = pcVar2 + len * 3;
      }
      pcVar5[-1] = '\0';
    }
  }
  return pcVar2;
}

