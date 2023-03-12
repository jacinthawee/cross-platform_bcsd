
dirent * OPENSSL_DIR_read(void **param_1,char *param_2)

{
  int *piVar1;
  dirent *pdVar2;
  void *__s;
  DIR *pDVar3;
  DIR **ppDVar4;
  int iVar5;
  
  if (param_2 == (char *)0x0 || param_1 == (void **)0x0) {
    piVar1 = __errno_location();
    *piVar1 = 0x16;
    return (dirent *)0x0;
  }
  piVar1 = __errno_location();
  ppDVar4 = (DIR **)*param_1;
  *piVar1 = 0;
  if (ppDVar4 == (DIR **)0x0) {
    __s = malloc(0x1008);
    *param_1 = __s;
    if (__s == (void *)0x0) {
      *piVar1 = 0xc;
      return (dirent *)0x0;
    }
    memset(__s,0,0x1008);
    ppDVar4 = (DIR **)*param_1;
    pDVar3 = opendir(param_2);
    *ppDVar4 = pDVar3;
                    /* WARNING: Load size is inaccurate */
    pDVar3 = **param_1;
    if (pDVar3 == (DIR *)0x0) {
      iVar5 = *piVar1;
      free(*param_1);
      *param_1 = (void *)0x0;
      *piVar1 = iVar5;
      return (dirent *)0x0;
    }
  }
  else {
    pDVar3 = *ppDVar4;
  }
  pdVar2 = readdir(pDVar3);
  if (pdVar2 != (dirent *)0x0) {
    strncpy((char *)((int)*param_1 + 4),pdVar2->d_name,0x1000);
    *(undefined *)((int)*param_1 + 0x1004) = 0;
    pdVar2 = (dirent *)((int)*param_1 + 4);
  }
  return pdVar2;
}

