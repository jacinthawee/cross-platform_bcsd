
char * dlfcn_name_converter(DSO *param_1,char *param_2)

{
  size_t sVar1;
  char *pcVar2;
  uint uVar3;
  int num;
  char *pcVar4;
  
  sVar1 = strlen(param_2);
  pcVar2 = strchr(param_2,0x2f);
  if (pcVar2 == (char *)0x0) {
    uVar3 = DSO_flags(param_1);
    num = sVar1 + 4;
    if ((uVar3 & 2) == 0) {
      num = sVar1 + 7;
    }
    pcVar2 = (char *)CRYPTO_malloc(num,"dso_dlfcn.c",0x182);
    if (pcVar2 != (char *)0x0) {
      uVar3 = DSO_flags(param_1);
      if ((uVar3 & 2) == 0) {
        pcVar4 = "lib%s.so";
      }
      else {
        pcVar4 = "%s.so";
      }
      __sprintf_chk(pcVar2,1,0xffffffff,pcVar4,param_2);
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

