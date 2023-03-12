
int app_RAND_load_files(char *param_1)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  cVar1 = *param_1;
  do {
    pcVar3 = param_1;
    if (cVar1 == '\0') {
      *param_1 = '\0';
      cVar1 = *param_1;
      bVar2 = true;
    }
    else {
      if (cVar1 == ':') {
        bVar2 = false;
      }
      else {
        do {
          pcVar3 = pcVar3 + 1;
          bVar2 = true;
          if (*pcVar3 == '\0') break;
          bVar2 = false;
        } while (*pcVar3 != ':');
      }
      *pcVar3 = '\0';
      cVar1 = *param_1;
    }
    if (cVar1 == '\0') {
LAB_00460920:
      if (0x200 < iVar5) {
        seeded = 1;
      }
      return iVar5;
    }
    iVar4 = (*(code *)PTR_RAND_egd_006a8d54)(param_1);
    if (iVar4 < 1) {
      iVar4 = (*(code *)PTR_RAND_load_file_006a8d58)(param_1,0xffffffff);
    }
    iVar5 = iVar5 + iVar4;
    if (bVar2) goto LAB_00460920;
    cVar1 = pcVar3[1];
    param_1 = pcVar3 + 1;
  } while( true );
}

