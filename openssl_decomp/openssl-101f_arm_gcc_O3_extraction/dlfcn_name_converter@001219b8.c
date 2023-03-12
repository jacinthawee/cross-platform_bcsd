
char * dlfcn_name_converter(DSO *param_1,char *param_2)

{
  size_t sVar1;
  char *pcVar2;
  int iVar3;
  undefined *puVar4;
  
  sVar1 = strlen(param_2);
  pcVar2 = strchr(param_2,0x2f);
  if (pcVar2 == (char *)0x0) {
    iVar3 = DSO_flags(param_1);
    if (iVar3 << 0x1e < 0) {
      iVar3 = sVar1 + 4;
    }
    else {
      iVar3 = sVar1 + 7;
    }
    pcVar2 = (char *)CRYPTO_malloc(iVar3,"dso_dlfcn.c",0x182);
    if (pcVar2 != (char *)0x0) {
      iVar3 = DSO_flags(param_1);
      if (iVar3 << 0x1e < 0) {
        puVar4 = &UNK_001793fc;
      }
      else {
        puVar4 = &UNK_001793f0;
      }
      __sprintf_chk(pcVar2,1,0xffffffff,puVar4,param_2);
      return pcVar2;
    }
  }
  else {
    pcVar2 = (char *)CRYPTO_malloc(sVar1 + 1,"dso_dlfcn.c",0x182);
    if (pcVar2 != (char *)0x0) {
      strcpy(pcVar2,param_2);
      return pcVar2;
    }
  }
  ERR_put_error(0x25,0x7b,0x6d,"dso_dlfcn.c",0x186);
  return (char *)0x0;
}

