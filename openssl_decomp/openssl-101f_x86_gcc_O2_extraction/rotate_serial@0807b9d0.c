
undefined4 rotate_serial(char *param_1,char *param_2,char *param_3)

{
  size_t sVar1;
  size_t sVar2;
  size_t sVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int in_GS_OFFSET;
  char local_520 [256];
  char local_420 [1024];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  sVar1 = strlen(param_1);
  sVar2 = strlen(param_3);
  sVar3 = strlen(param_2);
  iVar4 = sVar1 + sVar2;
  if ((int)(sVar1 + sVar2) < (int)(sVar1 + sVar3)) {
    iVar4 = sVar1 + sVar3;
  }
  if (iVar4 < 0xff) {
    BIO_snprintf(local_520,0x100,"%s.%s",param_1,param_2);
    BIO_snprintf(local_420,0x100,"%s.%s",param_1,param_3);
    iVar4 = rename(param_1,local_420);
    if (iVar4 < 0) {
      piVar6 = __errno_location();
      if ((*piVar6 != 2) && (*piVar6 != 0x14)) {
        BIO_printf(bio_err,"unable to rename %s to %s\n",param_1,local_420);
        perror("reason");
        uVar5 = 0;
        goto LAB_0807ba95;
      }
    }
    iVar4 = rename(local_520,param_1);
    uVar5 = 1;
    if (iVar4 < 0) {
      BIO_printf(bio_err,"unable to rename %s to %s\n",local_520,param_1);
      perror("reason");
      rename(local_420,param_1);
      uVar5 = 0;
    }
  }
  else {
    BIO_printf(bio_err,"file name too long\n");
    uVar5 = 0;
  }
LAB_0807ba95:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

