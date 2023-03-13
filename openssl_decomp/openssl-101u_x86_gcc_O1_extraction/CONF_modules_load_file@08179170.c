
int CONF_modules_load_file(char *filename,char *appname,ulong flags)

{
  CONF *conf;
  int iVar1;
  ulong uVar2;
  char *pcVar3;
  size_t sVar4;
  char *src;
  
  conf = NCONF_new((CONF_METHOD *)0x0);
  if (conf == (CONF *)0x0) {
    iVar1 = 0;
    pcVar3 = (char *)0x0;
LAB_081791ba:
    if (filename != (char *)0x0) goto LAB_081791c2;
  }
  else {
    pcVar3 = filename;
    if (filename != (char *)0x0) {
LAB_08179191:
      iVar1 = NCONF_load(conf,pcVar3,(long *)0x0);
      if (iVar1 < 1) {
        iVar1 = 0;
        if ((flags & 0x10) != 0) {
          uVar2 = ERR_peek_last_error();
          if ((uVar2 & 0xfff) == 0x72) {
            ERR_clear_error();
            iVar1 = 1;
          }
        }
      }
      else {
        iVar1 = CONF_modules_load(conf,appname,flags);
      }
      goto LAB_081791ba;
    }
    pcVar3 = getenv("OPENSSL_CONF");
    if (pcVar3 == (char *)0x0) {
      pcVar3 = X509_get_default_cert_area();
      sVar4 = strlen(pcVar3);
      sVar4 = sVar4 + 0xd;
      pcVar3 = (char *)CRYPTO_malloc(sVar4,"conf_mod.c",0x21b);
      if (pcVar3 == (char *)0x0) goto LAB_0817923a;
      src = X509_get_default_cert_area();
      BUF_strlcpy(pcVar3,src,sVar4);
      BUF_strlcat(pcVar3,"/",sVar4);
      BUF_strlcat(pcVar3,"openssl.cnf",sVar4);
      goto LAB_08179191;
    }
    pcVar3 = BUF_strdup(pcVar3);
    if (pcVar3 != (char *)0x0) goto LAB_08179191;
LAB_0817923a:
    pcVar3 = (char *)0x0;
    iVar1 = 0;
  }
  CRYPTO_free(pcVar3);
LAB_081791c2:
  NCONF_free(conf);
  return iVar1;
}

