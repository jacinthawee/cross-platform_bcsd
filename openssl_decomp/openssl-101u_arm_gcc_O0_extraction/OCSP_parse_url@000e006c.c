
int OCSP_parse_url(char *url,char **phost,char **pport,char **ppath,int *pssl)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *str;
  char *__s;
  
  *phost = (char *)0x0;
  *pport = (char *)0x0;
  *ppath = (char *)0x0;
  pcVar1 = BUF_strdup(url);
  if (pcVar1 == (char *)0x0) {
    ERR_put_error(0x27,0x72,0x41,"ocsp_lib.c",0x109);
    goto LAB_000e00e8;
  }
  pcVar2 = strchr(pcVar1,0x3a);
  if (pcVar2 == (char *)0x0) {
LAB_000e00ca:
    ERR_put_error(0x27,0x72,0x79,"ocsp_lib.c",0x10d);
  }
  else {
    *pcVar2 = '\0';
    iVar3 = strcmp(pcVar1,"http");
    if (iVar3 != 0) {
      iVar3 = strcmp(pcVar1,"https");
      if (iVar3 == 0) {
        str = "443";
        *pssl = 1;
        if (pcVar2[1] == '/') goto LAB_000e011c;
      }
      goto LAB_000e00ca;
    }
    str = "80";
    *pssl = 0;
    if (pcVar2[1] != '/') goto LAB_000e00ca;
LAB_000e011c:
    if (pcVar2[2] != '/') goto LAB_000e00ca;
    __s = pcVar2 + 3;
    pcVar4 = strchr(__s,0x2f);
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
      pcVar4 = __s;
      if (pcVar2[3] == '[') {
        __s = pcVar2 + 4;
        pcVar2 = strchr(__s,0x5d);
        if (pcVar2 == (char *)0x0) goto LAB_000e00ca;
        *pcVar2 = '\0';
        pcVar4 = pcVar2 + 1;
      }
      pcVar2 = strchr(pcVar4,0x3a);
      if (pcVar2 != (char *)0x0) {
        str = pcVar2 + 1;
        *pcVar2 = '\0';
      }
      pcVar2 = BUF_strdup(str);
      *pport = pcVar2;
      if (pcVar2 != (char *)0x0) {
        pcVar2 = BUF_strdup(__s);
        *phost = pcVar2;
        if (pcVar2 != (char *)0x0) {
          CRYPTO_free(pcVar1);
          return 1;
        }
      }
    }
    ERR_put_error(0x27,0x72,0x41,"ocsp_lib.c",0x109);
  }
  CRYPTO_free(pcVar1);
LAB_000e00e8:
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

