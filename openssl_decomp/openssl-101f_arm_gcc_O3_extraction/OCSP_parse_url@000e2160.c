
int OCSP_parse_url(char *url,char **phost,char **pport,char **ppath,int *pssl)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  
  *phost = (char *)0x0;
  *pport = (char *)0x0;
  *ppath = (char *)0x0;
  pcVar1 = BUF_strdup(url);
  if (pcVar1 == (char *)0x0) {
    ERR_put_error(0x27,0x72,0x41,"ocsp_lib.c",0xfa);
    goto LAB_000e21d2;
  }
  pcVar2 = strchr(pcVar1,0x3a);
  if (pcVar2 == (char *)0x0) {
LAB_000e21b6:
    ERR_put_error(0x27,0x72,0x79,"ocsp_lib.c",0xfe);
  }
  else {
    *pcVar2 = '\0';
    iVar3 = strcmp(pcVar1,"http");
    if (iVar3 == 0) {
      *pssl = 0;
      if (pcVar2[1] == '/') goto LAB_000e21fe;
      goto LAB_000e21b6;
    }
    iVar3 = strcmp(pcVar1,"https");
    if ((iVar3 != 0) || (*pssl = 1, pcVar2[1] != '/')) goto LAB_000e21b6;
LAB_000e21fe:
    if (pcVar2[2] != '/') goto LAB_000e21b6;
    pcVar2 = pcVar2 + 3;
    pcVar4 = strchr(pcVar2,0x2f);
    if (pcVar4 == (char *)0x0) {
      pcVar4 = BUF_strdup("/");
      *ppath = pcVar4;
    }
    else {
      pcVar5 = BUF_strdup(pcVar4);
      *ppath = pcVar5;
      *pcVar4 = '\0';
      pcVar4 = *ppath;
    }
    if (pcVar4 != (char *)0x0) {
      pcVar4 = strchr(pcVar2,0x3a);
      if (pcVar4 == (char *)0x0) {
        pcVar4 = "80";
        if (*pssl != 0) {
          pcVar4 = "443";
        }
      }
      else {
        *pcVar4 = '\0';
        pcVar4 = pcVar4 + 1;
      }
      pcVar4 = BUF_strdup(pcVar4);
      *pport = pcVar4;
      if (pcVar4 != (char *)0x0) {
        pcVar2 = BUF_strdup(pcVar2);
        *phost = pcVar2;
        if (pcVar2 != (char *)0x0) {
          CRYPTO_free(pcVar1);
          return 1;
        }
      }
    }
    ERR_put_error(0x27,0x72,0x41,"ocsp_lib.c",0xfa);
  }
  CRYPTO_free(pcVar1);
LAB_000e21d2:
  if (*ppath != (char *)0x0) {
    CRYPTO_free(*ppath);
  }
  if (*pport != (char *)0x0) {
    CRYPTO_free(*pport);
  }
  pcVar1 = *phost;
  if (pcVar1 != (char *)0x0) {
    CRYPTO_free(pcVar1);
    pcVar1 = (char *)0x0;
  }
  return (int)pcVar1;
}

