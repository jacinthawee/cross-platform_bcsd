
int X509_NAME_print(BIO *bp,X509_NAME *name,int obase)

{
  char cVar1;
  char *ptr;
  char *pcVar2;
  char *data;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  
  ptr = X509_NAME_oneline(name,(char *)0x0,0);
  pcVar3 = ptr + 1;
  pcVar2 = ptr + 2;
  if (*ptr == '\0') {
    CRYPTO_free(ptr);
    return 1;
  }
  cVar1 = ptr[1];
  if (cVar1 == '/') goto LAB_08146a13;
LAB_081469a8:
  data = pcVar3;
  pcVar5 = pcVar2;
  if (cVar1 != '\0') goto LAB_08146a0b;
  while (pcVar3 = pcVar2, pcVar2 = (char *)BIO_write(bp,data,(int)(pcVar3 + (-1 - (int)data))),
        pcVar3 + (-1 - (int)data) == pcVar2) {
    if (pcVar3[-1] == '\0') {
LAB_081469c9:
      iVar4 = 1;
      goto LAB_081469ce;
    }
    iVar4 = BIO_write(bp,", ",2);
    if (iVar4 != 2) break;
    pcVar5 = pcVar3;
    if (pcVar3[-1] == '\0') goto LAB_081469c9;
LAB_08146a0b:
    do {
      pcVar2 = pcVar5 + 1;
      cVar1 = *pcVar5;
      if (cVar1 != '/') goto LAB_081469a8;
LAB_08146a13:
      pcVar5 = pcVar2;
    } while ((0x19 < (byte)(*pcVar2 + 0xbfU)) ||
            ((data = pcVar3, pcVar2[1] != '=' &&
             ((0x19 < (byte)(pcVar2[1] + 0xbfU) || (pcVar2[2] != '='))))));
  }
  iVar4 = 0;
  ERR_put_error(0xb,0x75,7,"t_x509.c",0x20c);
LAB_081469ce:
  CRYPTO_free(ptr);
  return iVar4;
}

