
char * dlfcn_merger(undefined4 param_1,char *param_2,char *param_3)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  char *pcVar4;
  int reason;
  
  if ((param_2 == (char *)0x0) && (param_3 == (char *)0x0)) {
    iVar3 = 0x124;
    reason = 0x43;
    goto LAB_081e4477;
  }
  if (param_3 == (char *)0x0) {
LAB_081e4420:
    sVar1 = strlen(param_2);
    pcVar4 = (char *)CRYPTO_malloc(sVar1 + 1,"dso_dlfcn.c",300);
    if (pcVar4 != (char *)0x0) {
      strcpy(pcVar4,param_2);
      return pcVar4;
    }
    iVar3 = 0x12e;
  }
  else if (param_2 == (char *)0x0) {
    sVar1 = strlen(param_3);
    pcVar4 = (char *)CRYPTO_malloc(sVar1 + 1,"dso_dlfcn.c",0x137);
    if (pcVar4 != (char *)0x0) {
      strcpy(pcVar4,param_3);
      return pcVar4;
    }
    iVar3 = 0x139;
  }
  else {
    if (*param_2 == '/') goto LAB_081e4420;
    sVar1 = strlen(param_3);
    sVar2 = strlen(param_2);
    iVar3 = sVar2 + sVar1;
    if ((sVar1 != 0) && (param_3[sVar1 - 1] == '/')) {
      sVar1 = sVar1 - 1;
      iVar3 = iVar3 + -1;
    }
    pcVar4 = (char *)CRYPTO_malloc(iVar3 + 2,"dso_dlfcn.c",0x14e);
    if (pcVar4 != (char *)0x0) {
      strcpy(pcVar4,param_3);
      pcVar4[sVar1] = '/';
      strcpy(pcVar4 + sVar1 + 1,param_2);
      return pcVar4;
    }
    iVar3 = 0x150;
  }
  reason = 0x41;
LAB_081e4477:
  ERR_put_error(0x25,0x82,reason,"dso_dlfcn.c",iVar3);
  return (char *)0x0;
}

