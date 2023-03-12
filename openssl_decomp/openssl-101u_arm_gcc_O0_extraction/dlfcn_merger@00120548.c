
char * dlfcn_merger(undefined4 param_1,char *param_2,char *param_3)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  char *__dest;
  uint uVar4;
  
  uVar4 = count_leading_zeroes(param_3);
  if (param_2 == (char *)0x0 && param_3 == (char *)0x0) {
    ERR_put_error(0x25,0x82,0x43,"dso_dlfcn.c",0x124);
    return (char *)0x0;
  }
  if (uVar4 >> 5 == 0) {
    if (param_2 == (char *)0x0) {
      sVar1 = strlen(param_3);
      __dest = (char *)CRYPTO_malloc(sVar1 + 1,"dso_dlfcn.c",0x137);
      iVar3 = 0x139;
      if (__dest != (char *)0x0) {
        strcpy(__dest,param_3);
        return __dest;
      }
      goto LAB_00120646;
    }
    if (*param_2 != '/') {
      sVar1 = strlen(param_3);
      sVar2 = strlen(param_2);
      iVar3 = sVar2 + sVar1;
      if ((sVar1 != 0) && (param_3[sVar1 - 1] == '/')) {
        sVar1 = sVar1 - 1;
        iVar3 = iVar3 + -1;
      }
      __dest = (char *)CRYPTO_malloc(iVar3 + 2,"dso_dlfcn.c",0x14e);
      if (__dest != (char *)0x0) {
        strcpy(__dest,param_3);
        __dest[sVar1] = '/';
        strcpy(__dest + sVar1 + 1,param_2);
        return __dest;
      }
      iVar3 = 0x150;
      goto LAB_00120646;
    }
  }
  sVar1 = strlen(param_2);
  __dest = (char *)CRYPTO_malloc(sVar1 + 1,"dso_dlfcn.c",300);
  iVar3 = 0x12e;
  if (__dest != (char *)0x0) {
    strcpy(__dest,param_2);
    return __dest;
  }
LAB_00120646:
  ERR_put_error(0x25,0x82,0x41,"dso_dlfcn.c",iVar3);
  return __dest;
}

