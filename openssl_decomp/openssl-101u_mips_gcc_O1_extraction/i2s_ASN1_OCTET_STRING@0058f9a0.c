
char * i2s_ASN1_OCTET_STRING(X509V3_EXT_METHOD *method,ASN1_OCTET_STRING *ia5)

{
  byte bVar1;
  char *pcVar2;
  char *pcVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  iVar5 = ia5->length;
  pbVar4 = ia5->data;
  if (pbVar4 == (byte *)0x0) {
    return (char *)0x0;
  }
  if (iVar5 == 0) {
    return (char *)0x0;
  }
  pcVar2 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar5 * 3 + 1,"v3_utl.c",0x19f);
  if (pcVar2 == (char *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x6f,0x41,"v3_utl.c",0x1a0);
    pcVar2 = (char *)0x0;
  }
  else {
    pcVar3 = pcVar2;
    if (0 < iVar5) {
      pbVar6 = pbVar4;
      do {
        pbVar7 = pbVar6 + 1;
        *pcVar3 = "0123456789ABCDEF"[*pbVar6 >> 4];
        bVar1 = *pbVar6;
        pcVar3[2] = ':';
        pcVar3[1] = "0123456789ABCDEF"[bVar1 & 0xf];
        pcVar3 = pcVar3 + 3;
        pbVar6 = pbVar7;
      } while (pbVar7 != pbVar4 + iVar5);
      pcVar3 = pcVar2 + iVar5 * 3;
    }
    pcVar3[-1] = '\0';
  }
  return pcVar2;
}

