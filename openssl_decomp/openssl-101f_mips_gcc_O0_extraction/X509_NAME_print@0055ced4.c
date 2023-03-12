
int X509_NAME_print(BIO *bp,X509_NAME *name,int obase)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  
  pcVar1 = X509_NAME_oneline(name,(char *)0x0,0);
  if (*pcVar1 == '\0') {
    (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar1);
    return 1;
  }
  pcVar5 = pcVar1 + 2;
  cVar2 = pcVar1[1];
  pcVar3 = pcVar1 + 1;
  if (cVar2 == '/') goto LAB_0055cffc;
LAB_0055cf50:
  pcVar4 = pcVar3;
  pcVar7 = pcVar5;
  if (cVar2 != '\0') goto LAB_0055cff0;
  while (pcVar3 = pcVar5,
        pcVar5 = (char *)(*(code *)PTR_BIO_write_006a7f14)(bp,pcVar4,pcVar3 + (-1 - (int)pcVar4)),
        pcVar3 + (-1 - (int)pcVar4) == pcVar5) {
    if (pcVar3[-1] == '\0') {
LAB_0055cf88:
      iVar6 = 1;
      goto LAB_0055cf8c;
    }
    iVar6 = (*(code *)PTR_BIO_write_006a7f14)(bp,", ",2);
    if (iVar6 != 2) break;
    pcVar7 = pcVar3;
    if (pcVar3[-1] == '\0') goto LAB_0055cf88;
LAB_0055cff0:
    do {
      pcVar5 = pcVar7 + 1;
      cVar2 = *pcVar7;
      if (cVar2 != '/') goto LAB_0055cf50;
LAB_0055cffc:
      pcVar7 = pcVar5;
    } while ((0x19 < (byte)(*pcVar5 + 0xbfU)) ||
            ((pcVar4 = pcVar3, pcVar5[1] != 0x3d &&
             ((0x19 < ((int)pcVar5[1] - 0x41U & 0xff) || (pcVar5[2] != '='))))));
  }
  iVar6 = 0;
  (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x75,7,"t_x509.c",0x20c);
LAB_0055cf8c:
  (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar1);
  return iVar6;
}

