
int buffer_gets(BIO *param_1,char *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int local_24;
  
  piVar1 = (int *)param_1->ptr;
  param_3 = param_3 + -1;
  BIO_clear_flags(param_1,0xf);
  iVar2 = piVar1[3];
  local_24 = 0;
  do {
    while (iVar2 < 1) {
      iVar2 = BIO_read(param_1->next_bio,(void *)piVar1[2],*piVar1);
      if (iVar2 < 1) {
        BIO_copy_next_retry(param_1);
        *param_2 = '\0';
        if ((iVar2 != 0) && (local_24 < 1)) {
          return iVar2;
        }
        return local_24;
      }
      piVar1[3] = iVar2;
      piVar1[4] = 0;
    }
    iVar7 = piVar1[4];
    if (param_3 < 1) {
      iVar5 = 0;
      pcVar4 = param_2;
    }
    else {
      pcVar6 = (char *)(iVar7 + piVar1[2]);
      pcVar4 = param_2 + 1;
      *param_2 = *pcVar6;
      if (*pcVar6 == '\n') {
        iVar7 = 1;
LAB_08119d13:
        local_24 = local_24 + iVar7;
        piVar1[3] = piVar1[3] - iVar7;
        piVar1[4] = piVar1[4] + iVar7;
        break;
      }
      pcVar3 = pcVar4;
      iVar5 = 0;
      while( true ) {
        iVar7 = iVar5;
        iVar5 = iVar7 + 1;
        iVar2 = piVar1[3];
        if ((param_3 <= iVar5) || (iVar2 <= iVar5)) break;
        pcVar4 = pcVar3 + 1;
        *pcVar3 = pcVar6[iVar5];
        pcVar3 = pcVar4;
        if (pcVar6[iVar5] == '\n') {
          iVar7 = iVar7 + 2;
          goto LAB_08119d13;
        }
      }
      iVar7 = piVar1[4];
      pcVar4 = pcVar3;
    }
    iVar2 = iVar2 - iVar5;
    local_24 = local_24 + iVar5;
    param_3 = param_3 - iVar5;
    piVar1[3] = iVar2;
    piVar1[4] = iVar7 + iVar5;
    param_2 = pcVar4;
  } while (param_3 != 0);
  *pcVar4 = '\0';
  return local_24;
}

