
int DSO_set_filename(DSO *dso,char *filename)

{
  size_t sVar1;
  char *dst;
  int reason;
  int line;
  
  if ((dso == (DSO *)0x0) || (filename == (char *)0x0)) {
    line = 0x15c;
    reason = 0x43;
  }
  else if (dso->loaded_filename == (char *)0x0) {
    sVar1 = strlen(filename);
    dst = (char *)CRYPTO_malloc(sVar1 + 1,"dso_lib.c",0x164);
    if (dst != (char *)0x0) {
      sVar1 = strlen(filename);
      BUF_strlcpy(dst,filename,sVar1 + 1);
      if (dso->filename != (char *)0x0) {
        CRYPTO_free(dso->filename);
      }
      dso->filename = dst;
      return 1;
    }
    line = 0x166;
    reason = 0x41;
  }
  else {
    line = 0x160;
    reason = 0x6e;
  }
  ERR_put_error(0x25,0x81,reason,"dso_lib.c",line);
  return 0;
}

