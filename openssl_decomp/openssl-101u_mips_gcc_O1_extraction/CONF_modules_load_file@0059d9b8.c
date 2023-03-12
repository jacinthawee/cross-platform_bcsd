
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
LAB_0059da44:
    if (filename != (char *)0x0) goto LAB_0059da4c;
  }
  else {
    file = filename;
    if (filename != (char *)0x0) {
LAB_0059da10:
      iVar1 = NCONF_load(conf,file,(long *)0x0);
      if (iVar1 < 1) {
        if ((flags & 0x10) != 0) {
          uVar2 = (*(code *)PTR_ERR_peek_last_error_006a7408)();
          if ((uVar2 & 0xfff) == 0x72) {
            iVar1 = 1;
            (*(code *)PTR_ERR_clear_error_006a6ee0)();
            goto LAB_0059da44;
          }
        }
        iVar1 = 0;
      }
      else {
        iVar1 = CONF_modules_load(conf,appname,flags);
      }
      goto LAB_0059da44;
    }
    iVar1 = (*(code *)PTR_getenv_006a9a60)("OPENSSL_CONF");
    if (iVar1 == 0) {
      uVar3 = (*(code *)PTR_X509_get_default_cert_area_006a7064)();
      iVar1 = (*(code *)PTR_strlen_006a9a24)(uVar3);
      iVar1 = iVar1 + 0xd;
      file = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar1,"conf_mod.c",0x21b);
      if (file == (char *)0x0) goto LAB_0059dafc;
      uVar3 = (*(code *)PTR_X509_get_default_cert_area_006a7064)();
      (*(code *)PTR_BUF_strlcpy_006a6f64)(file,uVar3,iVar1);
      (*(code *)PTR_BUF_strlcat_006a6f68)(file,&DAT_0063b2b4,iVar1);
      (*(code *)PTR_BUF_strlcat_006a6f68)(file,"openssl.cnf",iVar1);
      goto LAB_0059da10;
    }
    file = (char *)(*(code *)PTR_BUF_strdup_006a6fdc)(iVar1);
    if (file != (char *)0x0) goto LAB_0059da10;
LAB_0059dafc:
    file = (char *)0x0;
    iVar1 = 0;
  }
  (*(code *)PTR_CRYPTO_free_006a6e88)(file);
LAB_0059da4c:
  NCONF_free(conf);
  return iVar1;
}

