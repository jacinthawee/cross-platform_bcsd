
int * OPENSSL_DIR_read(int **param_1,char *param_2)

{
  DIR **__ptr;
  int iVar1;
  int *piVar2;
  dirent *pdVar3;
  DIR **ppDVar4;
  DIR *pDVar5;
  
  if ((param_1 == (int **)0x0) || (param_2 == (char *)0x0)) {
    piVar2 = __errno_location();
    *piVar2 = 0x16;
    return (int *)0x0;
  }
  piVar2 = __errno_location();
  *piVar2 = 0;
  if ((DIR **)*param_1 == (DIR **)0x0) {
    ppDVar4 = (DIR **)calloc(0x1008,1);
    *param_1 = (int *)ppDVar4;
    if (ppDVar4 == (DIR **)0x0) {
      *piVar2 = 0xc;
      return (int *)0x0;
    }
    pDVar5 = opendir(param_2);
    __ptr = (DIR **)*param_1;
    *ppDVar4 = pDVar5;
    pDVar5 = *__ptr;
    if (pDVar5 == (DIR *)0x0) {
      iVar1 = *piVar2;
      free(__ptr);
      *param_1 = (int *)0x0;
      *piVar2 = iVar1;
      return (int *)0x0;
    }
  }
  else {
    pDVar5 = (DIR *)**param_1;
  }
  pdVar3 = readdir(pDVar5);
  if (pdVar3 == (dirent *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    strncpy((char *)(*param_1 + 1),pdVar3->d_name,0x1000);
    *(undefined *)(*param_1 + 0x401) = 0;
    piVar2 = *param_1 + 1;
  }
  return piVar2;
}

