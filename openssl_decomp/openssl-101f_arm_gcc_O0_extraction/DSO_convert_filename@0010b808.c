
char * DSO_convert_filename(DSO *dso,char *filename)

{
  size_t sVar1;
  DSO_NAME_CONVERTER_FUNC pDVar2;
  
  if (dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x7e,0x43,"dso_lib.c",0x1a3);
  }
  else if ((filename == (char *)0x0) && (filename = dso->filename, (DSO *)filename == (DSO *)0x0)) {
    ERR_put_error(0x25,0x7e,0x6f,"dso_lib.c",0x1aa);
    dso = (DSO *)filename;
  }
  else if ((dso->flags << 0x1f < 0) ||
          (((pDVar2 = dso->name_converter, pDVar2 == (DSO_NAME_CONVERTER_FUNC)0x0 &&
            (pDVar2 = dso->meth->dso_name_converter, pDVar2 == (DSO_NAME_CONVERTER_FUNC)0x0)) ||
           (dso = (DSO *)(*pDVar2)(dso,filename), dso == (DSO *)0x0)))) {
    sVar1 = strlen(filename);
    dso = (DSO *)CRYPTO_malloc(sVar1 + 1,"dso_lib.c",0x1b6);
    if (dso == (DSO *)0x0) {
      ERR_put_error(0x25,0x7e,0x41,"dso_lib.c",0x1ba);
    }
    else {
      sVar1 = strlen(filename);
      BUF_strlcpy((char *)dso,filename,sVar1 + 1);
    }
  }
  return (char *)dso;
}

