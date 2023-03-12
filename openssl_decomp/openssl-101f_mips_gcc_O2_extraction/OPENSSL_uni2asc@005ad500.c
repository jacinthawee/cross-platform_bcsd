
char * OPENSSL_uni2asc(uchar *uni,int unilen)

{
  char *pcVar1;
  int iVar2;
  uchar *puVar3;
  int iVar4;
  undefined4 in_a3;
  int iVar5;
  
  iVar5 = unilen / 2;
  if ((unilen == 0) || (uni[unilen + -1] != '\0')) {
    iVar5 = iVar5 + 1;
  }
  pcVar1 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar5,"p12_utl.c",0x5c,in_a3,&_gp);
  if (pcVar1 == (char *)0x0) {
    pcVar1 = (char *)0x0;
  }
  else {
    if (0 < unilen) {
      puVar3 = uni + 1;
      iVar2 = 0;
      do {
        iVar4 = iVar2 >> 1;
        iVar2 = iVar2 + 2;
        pcVar1[iVar4] = *puVar3;
        puVar3 = puVar3 + 2;
      } while (iVar2 < unilen);
    }
    pcVar1[iVar5 + -1] = '\0';
  }
  return pcVar1;
}

