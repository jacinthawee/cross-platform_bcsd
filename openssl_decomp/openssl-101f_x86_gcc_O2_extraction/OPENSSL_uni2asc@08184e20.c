
char * OPENSSL_uni2asc(uchar *uni,int unilen)

{
  int num;
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  num = unilen / 2;
  if ((unilen == 0) || (uni[unilen + -1] != '\0')) {
    num = num + 1;
  }
  pcVar1 = (char *)CRYPTO_malloc(num,"p12_utl.c",0x5c);
  if (pcVar1 == (char *)0x0) {
    pcVar1 = (char *)0x0;
  }
  else {
    iVar2 = 0;
    if (0 < unilen) {
      do {
        iVar3 = iVar2 + 2;
        pcVar1[iVar2 >> 1] = uni[iVar2 + 1];
        iVar2 = iVar3;
      } while (iVar3 < unilen);
    }
    pcVar1[num + -1] = '\0';
  }
  return pcVar1;
}
