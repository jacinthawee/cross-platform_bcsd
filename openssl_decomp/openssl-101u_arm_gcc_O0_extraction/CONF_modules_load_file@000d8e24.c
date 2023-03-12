
int CONF_modules_load_file(char *filename,char *appname,ulong flags)

{
  CONF *conf;
  int iVar1;
  CONF *pCVar2;
  ulong uVar3;
  char *pcVar4;
  CONF *dst;
  size_t sVar5;
  
  conf = NCONF_new((CONF_METHOD *)0x0);
  pCVar2 = conf;
  dst = conf;
  if (conf != (CONF *)0x0) {
    dst = (CONF *)filename;
    if (filename == (char *)0x0) {
      pcVar4 = getenv("OPENSSL_CONF");
      if (pcVar4 == (char *)0x0) {
        pcVar4 = X509_get_default_cert_area();
        sVar5 = strlen(pcVar4);
        sVar5 = sVar5 + 0xd;
        dst = (CONF *)CRYPTO_malloc(sVar5,"conf_mod.c",0x21b);
        if (dst == (CONF *)0x0) goto LAB_000d8ea0;
        pcVar4 = X509_get_default_cert_area();
        BUF_strlcpy((char *)dst,pcVar4,sVar5);
        BUF_strlcat((char *)dst,"/",sVar5);
        BUF_strlcat((char *)dst,"openssl.cnf",sVar5);
      }
      else {
        dst = (CONF *)BUF_strdup(pcVar4);
        if (dst == (CONF *)0x0) {
LAB_000d8ea0:
          dst = (CONF *)0x0;
          pCVar2 = (CONF *)0x0;
          goto LAB_000d8ea4;
        }
      }
    }
    iVar1 = NCONF_load(conf,(char *)dst,(long *)0x0);
    if (iVar1 < 1) {
      pCVar2 = (CONF *)(flags & 0x10);
      if ((CONF *)(flags & 0x10) != (CONF *)0x0) {
        uVar3 = ERR_peek_last_error();
        if ((uVar3 & 0xfff) == 0x72) {
          ERR_clear_error();
          pCVar2 = (CONF *)0x1;
        }
        else {
          pCVar2 = (CONF *)0x0;
        }
      }
    }
    else {
      pCVar2 = (CONF *)CONF_modules_load(conf,appname,flags);
    }
  }
  if (filename != (char *)0x0) {
    NCONF_free(conf);
    return (int)pCVar2;
  }
LAB_000d8ea4:
  CRYPTO_free(dst);
  NCONF_free(conf);
  return (int)pCVar2;
}

