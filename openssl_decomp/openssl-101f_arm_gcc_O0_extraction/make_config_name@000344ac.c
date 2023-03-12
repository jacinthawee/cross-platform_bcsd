
char * make_config_name(void)

{
  char *__s;
  size_t sVar1;
  char *dst;
  
  __s = X509_get_default_cert_area();
  sVar1 = strlen(__s);
  sVar1 = sVar1 + 0xd;
  dst = (char *)CRYPTO_malloc(sVar1,"apps.c",0x608);
  BUF_strlcpy(dst,__s,sVar1);
  BUF_strlcat(dst,"/",sVar1);
  BUF_strlcat(dst,"openssl.cnf",sVar1);
  return dst;
}

