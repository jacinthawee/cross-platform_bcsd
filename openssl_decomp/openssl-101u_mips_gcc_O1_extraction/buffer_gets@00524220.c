
int buffer_gets(BIO *param_1,char *param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  
  param_3 = param_3 + -1;
  iVar9 = 0;
  piVar8 = (int *)param_1->ptr;
  BIO_clear_flags(param_1,0xf);
  iVar2 = piVar8[3];
  do {
    while (iVar2 < 1) {
      iVar2 = BIO_read(param_1->next_bio,(void *)piVar8[2],*piVar8);
      if (iVar2 < 1) {
        BIO_copy_next_retry(param_1);
        *param_2 = '\0';
        if (iVar2 == 0) {
          return iVar9;
        }
        if (0 < iVar9) {
          return iVar9;
        }
        return iVar2;
      }
      piVar8[3] = iVar2;
      piVar8[4] = 0;
    }
    iVar5 = piVar8[4];
    if (param_3 < 1) {
      iVar7 = 0;
      pcVar3 = param_2;
    }
    else {
      pcVar6 = (char *)(piVar8[2] + iVar5);
      *param_2 = *pcVar6;
      pcVar3 = param_2 + 1;
      if (*pcVar6 == '\n') {
        iVar7 = 1;
LAB_00524340:
        iVar9 = iVar9 + iVar7;
        piVar8[3] = piVar8[3] - iVar7;
        piVar8[4] = piVar8[4] + iVar7;
        break;
      }
      pcVar4 = pcVar3;
      while( true ) {
        iVar2 = piVar8[3];
        iVar7 = (int)pcVar4 - (int)param_2;
        if (iVar2 <= iVar7) break;
        pcVar3 = pcVar4 + 1;
        if (param_2 + param_3 == pcVar4) {
          iVar5 = piVar8[4];
          pcVar3 = param_2 + param_3;
          goto LAB_005242e8;
        }
        pcVar1 = pcVar6 + 1;
        pcVar6 = pcVar6 + 1;
        *pcVar4 = *pcVar1;
        iVar7 = iVar7 + 1;
        pcVar4 = pcVar3;
        if (*pcVar6 == '\n') goto LAB_00524340;
      }
      iVar5 = piVar8[4];
      pcVar3 = pcVar4;
    }
LAB_005242e8:
    iVar2 = iVar2 - iVar7;
    param_3 = param_3 - iVar7;
    iVar9 = iVar9 + iVar7;
    piVar8[3] = iVar2;
    piVar8[4] = iVar7 + iVar5;
    param_2 = pcVar3;
  } while (param_3 != 0);
  *pcVar3 = '\0';
  return iVar9;
}

