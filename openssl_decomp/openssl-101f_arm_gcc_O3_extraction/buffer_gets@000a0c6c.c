
int buffer_gets(BIO *param_1,undefined *param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  
  piVar8 = (int *)param_1->ptr;
  param_3 = param_3 + -1;
  BIO_clear_flags(param_1,0xf);
  iVar9 = 0;
  iVar7 = piVar8[3];
  do {
    while (iVar7 < 1) {
      iVar7 = BIO_read(param_1->next_bio,(void *)piVar8[2],*piVar8);
      if (iVar7 < 1) {
        BIO_copy_next_retry(param_1);
        *param_2 = 0;
        if (iVar7 == 0) {
          return iVar9;
        }
        if (iVar9 < 1) {
          iVar9 = iVar7;
        }
        return iVar9;
      }
      piVar8[3] = iVar7;
      piVar8[4] = 0;
    }
    iVar3 = piVar8[4];
    iVar2 = piVar8[2];
    if (param_3 < 1) {
      iVar2 = 0;
      puVar4 = param_2;
    }
    else {
      puVar4 = param_2 + 1;
      *param_2 = *(undefined *)(iVar2 + iVar3);
      if (*(char *)(iVar2 + iVar3) == '\n') {
        iVar2 = 1;
LAB_000a0ce8:
        iVar9 = iVar9 + iVar2;
        piVar8[3] = piVar8[3] - iVar2;
        piVar8[4] = iVar2 + piVar8[4];
        break;
      }
      puVar5 = puVar4;
      puVar6 = (undefined *)(iVar2 + iVar3);
      while( true ) {
        iVar7 = piVar8[3];
        iVar2 = (int)puVar5 - (int)param_2;
        if ((iVar7 <= iVar2) || (puVar5 == param_2 + param_3)) break;
        puVar4 = puVar5 + 1;
        *puVar5 = puVar6[1];
        pcVar1 = puVar6 + 1;
        puVar5 = puVar4;
        puVar6 = puVar6 + 1;
        if (*pcVar1 == '\n') {
          iVar2 = iVar2 + 1;
          goto LAB_000a0ce8;
        }
      }
      iVar3 = piVar8[4];
      puVar4 = puVar5;
    }
    param_3 = param_3 - iVar2;
    iVar7 = iVar7 - iVar2;
    piVar8[3] = iVar7;
    iVar9 = iVar9 + iVar2;
    piVar8[4] = iVar3 + iVar2;
    param_2 = puVar4;
  } while (param_3 != 0);
  *puVar4 = 0;
  return iVar9;
}

