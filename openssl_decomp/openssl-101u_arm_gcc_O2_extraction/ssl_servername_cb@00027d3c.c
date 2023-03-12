
char * ssl_servername_cb(SSL *param_1,undefined4 param_2,char **param_3,undefined4 param_4)

{
  char *__s1;
  int iVar1;
  
  __s1 = (char *)SSL_get_servername(param_1,0,param_3,param_4,param_4);
  if (__s1 == (char *)0x0) {
    if (*param_3 == (char *)0x0) {
      return (char *)0x3;
    }
  }
  else {
    if ((BIO *)param_3[1] != (BIO *)0x0) {
      BIO_printf((BIO *)param_3[1],"Hostname in TLS extension: \"%s\"\n",__s1);
    }
    if (*param_3 == (char *)0x0) {
      return (char *)0x3;
    }
    iVar1 = strcasecmp(__s1,*param_3);
    if (iVar1 != 0) {
      return param_3[2];
    }
    if (ctx2 != (SSL_CTX *)0x0) {
      BIO_printf((BIO *)param_3[1],"Switching server context.\n");
      SSL_set_SSL_CTX(param_1,ctx2);
      return (char *)0x0;
    }
  }
  return (char *)0x0;
}

