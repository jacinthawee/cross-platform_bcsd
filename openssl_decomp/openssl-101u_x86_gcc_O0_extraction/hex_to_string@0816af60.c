
char * hex_to_string(uchar *buffer,long len)

{
  byte *pbVar1;
  char *pcVar2;
  char *pcVar3;
  byte *pbVar4;
  
  if ((buffer != (uchar *)0x0) && (len != 0)) {
    pcVar2 = (char *)CRYPTO_malloc(len * 3 + 1,"v3_utl.c",0x19f);
    if (pcVar2 == (char *)0x0) {
      ERR_put_error(0x22,0x6f,0x41,"v3_utl.c",0x1a0);
      pcVar2 = (char *)0x0;
    }
    else {
      pbVar1 = buffer + len;
      pcVar3 = pcVar2;
      if (0 < len) {
        do {
          pbVar4 = buffer + 1;
          *pcVar3 = "0123456789ABCDEF"[*buffer >> 4];
          pcVar3[1] = "0123456789ABCDEF"[*buffer & 0xf];
          pcVar3[2] = ':';
          pcVar3 = pcVar3 + 3;
          buffer = pbVar4;
        } while (pbVar4 != pbVar1);
        pcVar3 = pcVar2 + len * 3;
      }
      pcVar3[-1] = '\0';
    }
    return pcVar2;
  }
  return (char *)0x0;
}

