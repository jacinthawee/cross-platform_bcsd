
uchar * OPENSSL_asc2uni(char *asc,int asclen,uchar **uni,int *unilen)

{
  uchar *puVar1;
  int iVar2;
  int iVar3;
  int num;
  
  if (asclen == -1) {
    asclen = strlen(asc);
  }
  num = (asclen + 1U) * 2;
  puVar1 = (uchar *)CRYPTO_malloc(num,"p12_utl.c",0x4a);
  if (puVar1 != (uchar *)0x0) {
    if (0 < num + -2) {
      iVar2 = 0;
      do {
        puVar1[iVar2] = '\0';
        iVar3 = iVar2 + 2;
        puVar1[iVar2 + 1] = asc[iVar2 >> 1];
        iVar2 = iVar3;
      } while (iVar3 < num + -2);
    }
    puVar1[num + -2] = '\0';
    puVar1[num + -1] = '\0';
    if (unilen != (int *)0x0) {
      *unilen = num;
    }
    if (uni != (uchar **)0x0) {
      *uni = puVar1;
    }
  }
  return puVar1;
}

