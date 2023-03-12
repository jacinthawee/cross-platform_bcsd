
char * hex_to_string(uchar *buffer,long len)

{
  byte bVar1;
  char *pcVar2;
  char *pcVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  if (buffer == (uchar *)0x0) {
    return (char *)0x0;
  }
  if (len == 0) {
    return (char *)0x0;
  }
  pcVar2 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(len * 3 + 1,"v3_utl.c",0x172);
  if (pcVar2 == (char *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x6f,0x41,"v3_utl.c",0x173);
    pcVar2 = (char *)0x0;
  }
  else {
    pcVar3 = pcVar2;
    if (0 < len) {
      pbVar4 = buffer;
      do {
        pbVar5 = pbVar4 + 1;
        *pcVar3 = "0123456789ABCDEF"[*pbVar4 >> 4];
        bVar1 = *pbVar4;
        pcVar3[2] = ':';
        pcVar3[1] = "0123456789ABCDEF"[bVar1 & 0xf];
        pcVar3 = pcVar3 + 3;
        pbVar4 = pbVar5;
      } while (pbVar5 != buffer + len);
      pcVar3 = pcVar2 + len * 3;
    }
    pcVar3[-1] = '\0';
  }
  return pcVar2;
}

