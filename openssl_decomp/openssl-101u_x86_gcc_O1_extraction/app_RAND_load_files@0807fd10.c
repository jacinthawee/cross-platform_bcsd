
int app_RAND_load_files(char *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    cVar1 = *param_1;
    pcVar2 = param_1;
    while ((cVar1 != '\0' && (cVar1 != ':'))) {
      pcVar2 = pcVar2 + 1;
      cVar1 = *pcVar2;
    }
    *pcVar2 = '\0';
    if (*param_1 == '\0') break;
    iVar3 = RAND_egd(param_1);
    if (iVar3 < 1) {
      iVar3 = RAND_load_file(param_1,-1);
    }
    iVar4 = iVar4 + iVar3;
    param_1 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (0x200 < iVar4) {
    seeded = 1;
  }
  return iVar4;
}

