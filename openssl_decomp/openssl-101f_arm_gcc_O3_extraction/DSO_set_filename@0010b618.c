
int DSO_set_filename(DSO *dso,char *filename)

{
  size_t sVar1;
  char *dst;
  
  if (filename == (char *)0x0 || dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x81,0x43,"dso_lib.c",0x173);
    return 0;
  }
  dst = (char *)0x0;
  if (dso->loaded_filename == (char *)0x0) {
    sVar1 = strlen(filename);
    dst = (char *)CRYPTO_malloc(sVar1 + 1,"dso_lib.c",0x17c);
    if (dst != (char *)0x0) {
      sVar1 = strlen(filename);
      BUF_strlcpy(dst,filename,sVar1 + 1);
      if (dso->filename != (char *)0x0) {
        CRYPTO_free(dso->filename);
      }
      dso->filename = dst;
      return 1;
    }
    ERR_put_error(0x25,0x81,0x41,"dso_lib.c",0x17f);
  }
  else {
    ERR_put_error(0x25,0x81,0x6e,"dso_lib.c",0x178);
  }
  return (int)dst;
}

