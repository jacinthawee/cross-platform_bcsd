
undefined4 rotate_serial(char *param_1,char *param_2,char *param_3)

{
  size_t sVar1;
  size_t sVar2;
  size_t sVar3;
  int iVar4;
  int *piVar5;
  char acStack_518 [256];
  char acStack_418 [1024];
  
  sVar1 = strlen(param_1);
  sVar2 = strlen(param_3);
  sVar3 = strlen(param_2);
  iVar4 = sVar3 + sVar1;
  if ((int)(sVar3 + sVar1) < (int)(sVar2 + sVar1)) {
    iVar4 = sVar2 + sVar1;
  }
  if (iVar4 < 0xff) {
    BIO_snprintf(acStack_518,0x100,"%s.%s",param_1,param_2);
    BIO_snprintf(acStack_418,0x100,"%s.%s",param_1,param_3);
    iVar4 = rename(param_1,acStack_418);
    if (iVar4 < 0) {
      piVar5 = __errno_location();
      if ((*piVar5 != 2) && (*piVar5 != 0x14)) {
        BIO_printf(bio_err,"unable to rename %s to %s\n",param_1,acStack_418);
        perror("reason");
        return 0;
      }
    }
    iVar4 = rename(acStack_518,param_1);
    if (-1 < iVar4) {
      return 1;
    }
    BIO_printf(bio_err,"unable to rename %s to %s\n",acStack_518,param_1);
    perror("reason");
    rename(acStack_418,param_1);
    return 0;
  }
  BIO_printf(bio_err,"file name too long\n");
  return 0;
}

