
int DSO_set_filename(DSO *dso,char *filename)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  if ((dso == (DSO *)0x0) || (filename == (char *)0x0)) {
    uVar4 = 0x43;
    uVar1 = 0x173;
  }
  else {
    if (dso->loaded_filename == (char *)0x0) {
      iVar2 = (*(code *)PTR_strlen_006aab30)(filename);
      pcVar3 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar2 + 1,"dso_lib.c",0x17c);
      if (pcVar3 == (char *)0x0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x25,0x81,0x41,"dso_lib.c",0x17f);
        return 0;
      }
      iVar2 = (*(code *)PTR_strlen_006aab30)(filename);
      (*(code *)PTR_BUF_strlcpy_006a8064)(pcVar3,filename,iVar2 + 1);
      if (dso->filename != (char *)0x0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      dso->filename = pcVar3;
      return 1;
    }
    uVar4 = 0x6e;
    uVar1 = 0x178;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x25,0x81,uVar4,"dso_lib.c",uVar1);
  return 0;
}

