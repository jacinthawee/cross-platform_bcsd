
uchar * OPENSSL_asc2uni(char *asc,int asclen,uchar **uni,int *unilen)

{
  int iVar1;
  uchar *puVar2;
  int iVar3;
  
  if (asclen == -1) {
    asclen = strlen(asc);
  }
  iVar1 = asclen * 2;
  puVar2 = (uchar *)CRYPTO_malloc(iVar1 + 2,"p12_utl.c",0x4a);
  if (puVar2 == (uchar *)0x0) {
    puVar2 = (uchar *)0x0;
  }
  else {
    iVar3 = 0;
    if (0 < iVar1) {
      do {
        puVar2[iVar3] = '\0';
        puVar2[iVar3 + 1] = asc[iVar3 >> 1];
        iVar3 = iVar3 + 2;
      } while (iVar3 < iVar1);
    }
    puVar2[iVar1] = '\0';
    puVar2[iVar1 + 1] = '\0';
    if (unilen != (int *)0x0) {
      *unilen = iVar1 + 2;
    }
    if (uni != (uchar **)0x0) {
      *uni = puVar2;
    }
  }
  return puVar2;
}

