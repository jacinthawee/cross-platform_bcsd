
int CONF_modules_load_file(char *filename,char *appname,ulong flags)

{
  CONF *conf;
  int iVar1;
  uint uVar2;
  char *file;
  undefined4 uVar3;
  
  conf = NCONF_new((CONF_METHOD *)0x0);
  if (conf == (CONF *)0x0) {
    iVar1 = 0;
    file = (char *)0x0;
LAB_005a07b4:
    if (filename != (char *)0x0) goto LAB_005a07bc;
  }
  else {
    file = filename;
    if (filename != (char *)0x0) {
LAB_005a0780:
      iVar1 = NCONF_load(conf,file,(long *)0x0);
      if (iVar1 < 1) {
        if ((flags & 0x10) != 0) {
          uVar2 = (*(code *)PTR_ERR_peek_last_error_006a8508)();
          if ((uVar2 & 0xfff) == 0x72) {
            iVar1 = 1;
            (*(code *)PTR_ERR_clear_error_006a7fe0)();
            goto LAB_005a07b4;
          }
        }
        iVar1 = 0;
      }
      else {
        iVar1 = CONF_modules_load(conf,appname,flags);
      }
      goto LAB_005a07b4;
    }
    iVar1 = (*(code *)PTR_getenv_006aab6c)("OPENSSL_CONF");
    if (iVar1 == 0) {
      uVar3 = (*(code *)PTR_X509_get_default_cert_area_006a8164)();
      iVar1 = (*(code *)PTR_strlen_006aab30)(uVar3);
      iVar1 = iVar1 + 0xd;
      file = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar1,"conf_mod.c",0x231);
      if (file == (char *)0x0) goto LAB_005a086c;
      uVar3 = (*(code *)PTR_X509_get_default_cert_area_006a8164)();
      (*(code *)PTR_BUF_strlcpy_006a8064)(file,uVar3,iVar1);
      (*(code *)PTR_BUF_strlcat_006a8068)(file,&DAT_0063ba98,iVar1);
      (*(code *)PTR_BUF_strlcat_006a8068)(file,"openssl.cnf",iVar1);
      goto LAB_005a0780;
    }
    file = (char *)(*(code *)PTR_BUF_strdup_006a80dc)(iVar1);
    if (file != (char *)0x0) goto LAB_005a0780;
LAB_005a086c:
    file = (char *)0x0;
    iVar1 = 0;
  }
  (*(code *)PTR_CRYPTO_free_006a7f88)(file);
LAB_005a07bc:
  NCONF_free(conf);
  return iVar1;
}

