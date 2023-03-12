
int OCSP_parse_url(char *url,char **phost,char **pport,char **ppath,int *pssl)

{
  char *__s;
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  bool bVar5;
  byte bVar6;
  
  bVar6 = 0;
  *phost = (char *)0x0;
  *pport = (char *)0x0;
  *ppath = (char *)0x0;
  __s = BUF_strdup(url);
  if (__s == (char *)0x0) {
    ERR_put_error(0x27,0x72,0x41,"ocsp_lib.c",0xfa);
    goto LAB_08187287;
  }
  pcVar1 = strchr(__s,0x3a);
  bVar5 = pcVar1 == (char *)0x0;
  if (bVar5) {
LAB_08187260:
    ERR_put_error(0x27,0x72,0x79,"ocsp_lib.c",0xfe);
  }
  else {
    *pcVar1 = '\0';
    iVar4 = 5;
    pcVar2 = __s;
    pcVar3 = "http";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar5 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + (uint)bVar6 * -2 + 1;
      pcVar3 = pcVar3 + (uint)bVar6 * -2 + 1;
    } while (bVar5);
    if (!bVar5) {
      iVar4 = 6;
      pcVar2 = __s;
      pcVar3 = "https";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar5 = *pcVar2 == *pcVar3;
        pcVar2 = pcVar2 + (uint)bVar6 * -2 + 1;
        pcVar3 = pcVar3 + (uint)bVar6 * -2 + 1;
      } while (bVar5);
      if ((bVar5) && (*pssl = 1, pcVar1[1] == '/')) goto LAB_081872ec;
      goto LAB_08187260;
    }
    *pssl = 0;
    if (pcVar1[1] != '/') goto LAB_08187260;
LAB_081872ec:
    if (pcVar1[2] != '/') goto LAB_08187260;
    pcVar1 = pcVar1 + 3;
    pcVar2 = strchr(pcVar1,0x2f);
    if (pcVar2 == (char *)0x0) {
      pcVar2 = BUF_strdup("/");
      *ppath = pcVar2;
    }
    else {
      pcVar3 = BUF_strdup(pcVar2);
      *ppath = pcVar3;
      *pcVar2 = '\0';
      pcVar2 = *ppath;
    }
    if (pcVar2 != (char *)0x0) {
      pcVar2 = strchr(pcVar1,0x3a);
      if (pcVar2 == (char *)0x0) {
        pcVar2 = "80";
        if (*pssl != 0) {
          pcVar2 = "443";
        }
      }
      else {
        *pcVar2 = '\0';
        pcVar2 = pcVar2 + 1;
      }
      pcVar2 = BUF_strdup(pcVar2);
      *pport = pcVar2;
      if (pcVar2 != (char *)0x0) {
        pcVar1 = BUF_strdup(pcVar1);
        *phost = pcVar1;
        if (pcVar1 != (char *)0x0) {
          CRYPTO_free(__s);
          return 1;
        }
      }
    }
    ERR_put_error(0x27,0x72,0x41,"ocsp_lib.c",0xfa);
  }
  CRYPTO_free(__s);
LAB_08187287:
  if (*ppath != (char *)0x0) {
    CRYPTO_free(*ppath);
  }
  if (*pport != (char *)0x0) {
    CRYPTO_free(*pport);
  }
  if (*phost != (char *)0x0) {
    CRYPTO_free(*phost);
  }
  return 0;
}

