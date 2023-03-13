
undefined4 rotate_index(char *param_1,char *param_2,char *param_3)

{
  size_t sVar1;
  size_t sVar2;
  size_t sVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int in_GS_OFFSET;
  char local_520 [256];
  char local_420 [256];
  char local_320 [256];
  char local_220 [256];
  char local_120 [256];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  sVar1 = strlen(param_1);
  sVar2 = strlen(param_3);
  sVar3 = strlen(param_2);
  iVar4 = sVar1 + sVar2;
  if ((int)(sVar1 + sVar2) < (int)(sVar1 + sVar3)) {
    iVar4 = sVar1 + sVar3;
  }
  if (0xf9 < iVar4) {
    BIO_printf(bio_err,"file name too long\n");
    uVar5 = 0;
    goto LAB_0807cd1e;
  }
  BIO_snprintf(local_120,0x100,"%s.attr",param_1);
  BIO_snprintf(local_320,0x100,"%s.attr.%s",param_1,param_2);
  BIO_snprintf(local_520,0x100,"%s.%s",param_1,param_2);
  BIO_snprintf(local_420,0x100,"%s.%s",param_1,param_3);
  BIO_snprintf(local_220,0x100,"%s.attr.%s",param_1,param_3);
  iVar4 = rename(param_1,local_420);
  if (iVar4 < 0) {
    piVar6 = __errno_location();
    if ((*piVar6 != 2) && (*piVar6 != 0x14)) {
      BIO_printf(bio_err,"unable to rename %s to %s\n",param_1,local_420);
      perror("reason");
      uVar5 = 0;
      goto LAB_0807cd1e;
    }
  }
  iVar4 = rename(local_520,param_1);
  if (iVar4 < 0) {
    BIO_printf(bio_err,"unable to rename %s to %s\n",local_520,param_1);
    perror("reason");
  }
  else {
    iVar4 = rename(local_120,local_220);
    if (iVar4 < 0) {
      piVar6 = __errno_location();
      if ((*piVar6 == 0x14) || (*piVar6 == 2)) goto LAB_0807ccfb;
      BIO_printf(bio_err,"unable to rename %s to %s\n",local_120,local_220);
      perror("reason");
    }
    else {
LAB_0807ccfb:
      iVar4 = rename(local_320,local_120);
      uVar5 = 1;
      if (-1 < iVar4) goto LAB_0807cd1e;
      BIO_printf(bio_err,"unable to rename %s to %s\n",local_320,local_120);
      perror("reason");
      rename(local_220,local_120);
    }
    rename(param_1,local_520);
  }
  rename(local_420,param_1);
  uVar5 = 0;
LAB_0807cd1e:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

