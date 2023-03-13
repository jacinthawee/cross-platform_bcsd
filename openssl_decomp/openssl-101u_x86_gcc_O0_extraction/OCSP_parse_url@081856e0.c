
int OCSP_parse_url(char *url,char **phost,char **pport,char **ppath,int *pssl)

{
  char *__s;
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  byte bVar8;
  char *local_20;
  
  bVar8 = 0;
  *phost = (char *)0x0;
  *pport = (char *)0x0;
  *ppath = (char *)0x0;
  __s = BUF_strdup(url);
  if (__s == (char *)0x0) {
    ERR_put_error(0x27,0x72,0x41,"ocsp_lib.c",0x109);
    goto LAB_08185797;
  }
  pcVar1 = strchr(__s,0x3a);
  bVar7 = pcVar1 == (char *)0x0;
  if (bVar7) {
LAB_08185770:
    ERR_put_error(0x27,0x72,0x79,"ocsp_lib.c",0x10d);
  }
  else {
    *pcVar1 = '\0';
    iVar4 = 5;
    pcVar5 = __s;
    pcVar6 = "http";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar7 = *pcVar5 == *pcVar6;
      pcVar5 = pcVar5 + (uint)bVar8 * -2 + 1;
      pcVar6 = pcVar6 + (uint)bVar8 * -2 + 1;
    } while (bVar7);
    if (!bVar7) {
      iVar4 = 6;
      pcVar5 = __s;
      pcVar6 = "https";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar7 = *pcVar5 == *pcVar6;
        pcVar5 = pcVar5 + (uint)bVar8 * -2 + 1;
        pcVar6 = pcVar6 + (uint)bVar8 * -2 + 1;
      } while (bVar7);
      if (bVar7) {
        pcVar5 = "443";
        *pssl = 1;
        if (pcVar1[1] == '/') goto LAB_08185801;
      }
      goto LAB_08185770;
    }
    pcVar5 = "80";
    *pssl = 0;
    if (pcVar1[1] != '/') goto LAB_08185770;
LAB_08185801:
    if (pcVar1[2] != '/') goto LAB_08185770;
    pcVar6 = pcVar1 + 3;
    pcVar2 = strchr(pcVar6,0x2f);
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
      local_20 = pcVar6;
      if (pcVar1[3] == '[') {
        pcVar6 = pcVar1 + 4;
        local_20 = strchr(pcVar6,0x5d);
        if (local_20 == (char *)0x0) goto LAB_08185770;
        *local_20 = '\0';
        local_20 = local_20 + 1;
      }
      pcVar1 = strchr(local_20,0x3a);
      if (pcVar1 != (char *)0x0) {
        pcVar5 = pcVar1 + 1;
        *pcVar1 = '\0';
      }
      pcVar1 = BUF_strdup(pcVar5);
      *pport = pcVar1;
      if (pcVar1 != (char *)0x0) {
        pcVar1 = BUF_strdup(pcVar6);
        *phost = pcVar1;
        if (pcVar1 != (char *)0x0) {
          CRYPTO_free(__s);
          return 1;
        }
      }
    }
    ERR_put_error(0x27,0x72,0x41,"ocsp_lib.c",0x109);
  }
  CRYPTO_free(__s);
LAB_08185797:
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

