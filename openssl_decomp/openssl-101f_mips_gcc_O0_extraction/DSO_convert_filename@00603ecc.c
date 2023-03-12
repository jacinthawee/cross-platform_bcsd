
char * DSO_convert_filename(DSO *dso,char *filename)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  DSO_NAME_CONVERTER_FUNC pDVar5;
  
  if (dso == (DSO *)0x0) {
    uVar4 = 0x43;
    uVar3 = 0x1a3;
  }
  else {
    if ((filename != (char *)0x0) || (filename = dso->filename, filename != (char *)0x0)) {
      if (((dso->flags & 1U) == 0) &&
         (((pDVar5 = dso->name_converter, pDVar5 != (DSO_NAME_CONVERTER_FUNC)0x0 ||
           (pDVar5 = dso->meth->dso_name_converter, pDVar5 != (DSO_NAME_CONVERTER_FUNC)0x0)) &&
          (pcVar1 = (*pDVar5)(dso,filename), pcVar1 != (char *)0x0)))) {
        return pcVar1;
      }
      iVar2 = (*(code *)PTR_strlen_006aab30)(filename);
      pcVar1 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar2 + 1,"dso_lib.c",0x1b6);
      if (pcVar1 != (char *)0x0) {
        iVar2 = (*(code *)PTR_strlen_006aab30)(filename);
        (*(code *)PTR_BUF_strlcpy_006a8064)(pcVar1,filename,iVar2 + 1);
        return pcVar1;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0x25,0x7e,0x41,"dso_lib.c",0x1ba);
      return (char *)0x0;
    }
    uVar4 = 0x6f;
    uVar3 = 0x1aa;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x25,0x7e,uVar4,"dso_lib.c",uVar3);
  return (char *)0x0;
}

