
char * DSO_convert_filename(DSO *dso,char *filename)

{
  char *pcVar1;
  size_t sVar2;
  DSO_NAME_CONVERTER_FUNC pDVar3;
  int reason;
  int line;
  
  if (dso == (DSO *)0x0) {
    line = 0x186;
    reason = 0x43;
  }
  else if ((filename == (char *)0x0) && (filename = dso->filename, filename == (char *)0x0)) {
    line = 0x18c;
    reason = 0x6f;
  }
  else {
    if (((*(byte *)&dso->flags & 1) == 0) &&
       (((pDVar3 = dso->name_converter, pDVar3 != (DSO_NAME_CONVERTER_FUNC)0x0 ||
         (pDVar3 = dso->meth->dso_name_converter, pDVar3 != (DSO_NAME_CONVERTER_FUNC)0x0)) &&
        (pcVar1 = (*pDVar3)(dso,filename), pcVar1 != (char *)0x0)))) {
      return pcVar1;
    }
    sVar2 = strlen(filename);
    pcVar1 = (char *)CRYPTO_malloc(sVar2 + 1,"dso_lib.c",0x196);
    if (pcVar1 != (char *)0x0) {
      sVar2 = strlen(filename);
      BUF_strlcpy(pcVar1,filename,sVar2 + 1);
      return pcVar1;
    }
    line = 0x198;
    reason = 0x41;
  }
  ERR_put_error(0x25,0x7e,reason,"dso_lib.c",line);
  return (char *)0x0;
}

