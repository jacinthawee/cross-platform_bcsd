
uchar * OPENSSL_asc2uni(char *asc,int asclen,uchar **uni,int *unilen)

{
  uchar *puVar1;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (asclen == -1) {
    asclen = (*(code *)PTR_strlen_006a9a24)();
  }
  iVar5 = (asclen + 1) * 2;
  puVar1 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar5,"p12_utl.c",0x4a);
  if (puVar1 == (uchar *)0x0) {
    puVar1 = (uchar *)0x0;
  }
  else {
    if (0 < iVar5 + -2) {
      iVar3 = 0;
      puVar2 = puVar1;
      do {
        iVar4 = iVar3 >> 1;
        *puVar2 = '\0';
        iVar3 = iVar3 + 2;
        puVar2[1] = asc[iVar4];
        puVar2 = puVar2 + 2;
      } while (iVar3 < iVar5 + -2);
    }
    puVar1[iVar5 + -2] = '\0';
    puVar1[iVar5 + -1] = '\0';
    if (unilen != (int *)0x0) {
      *unilen = iVar5;
    }
    if (uni != (uchar **)0x0) {
      *uni = puVar1;
    }
  }
  return puVar1;
}

