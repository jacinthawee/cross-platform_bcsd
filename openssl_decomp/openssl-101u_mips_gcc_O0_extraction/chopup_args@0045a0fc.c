
undefined4 chopup_args(int *param_1,char *param_2,int *param_3,int *param_4)

{
  char *pcVar1;
  char cVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  *param_3 = 0;
  *param_4 = 0;
  puVar3 = PTR_CRYPTO_malloc_006a7008;
  iVar8 = param_1[1];
  if (iVar8 == 0) {
    param_1[1] = 0x14;
    iVar7 = (*(code *)puVar3)(0x50,"apps.c",0x185);
    *param_1 = iVar7;
    if (iVar7 == 0) {
      return 0;
    }
    iVar8 = param_1[1];
  }
  else {
    iVar7 = *param_1;
  }
  iVar4 = 0;
  if (0 < iVar8) {
    do {
      iVar5 = iVar4 * 4;
      iVar4 = iVar4 + 1;
      *(undefined4 *)(iVar7 + iVar5) = 0;
      iVar7 = *param_1;
    } while (iVar4 != iVar8);
  }
  iVar8 = (int)*param_2;
  if (iVar8 == 0) {
    iVar4 = 0;
  }
  else {
    iVar5 = 0;
    iVar4 = 0;
LAB_0045a1a0:
    do {
      if ((iVar8 != 0x20) && (1 < (iVar8 - 9U & 0xff))) {
        iVar8 = param_1[1] + 0x14;
        if (param_1[1] <= iVar4) {
          iVar7 = (*(code *)PTR_CRYPTO_realloc_006a7b58)(iVar7,iVar8 * 4,"apps.c",0x19c);
          if (iVar7 == 0) {
            return 0;
          }
          *param_1 = iVar7;
          param_1[1] = iVar8;
          iVar6 = iVar5;
          if (iVar4 < iVar8) {
            while( true ) {
              *(undefined4 *)(iVar7 + iVar6) = 0;
              if (iVar6 + 4 == iVar8 * 4) break;
              iVar7 = *param_1;
              iVar6 = iVar6 + 4;
            }
            iVar7 = *param_1;
          }
        }
        *(char **)(iVar7 + iVar5) = param_2;
        iVar8 = (int)*param_2;
        iVar4 = iVar4 + 1;
        if ((iVar8 == 0x27) || (iVar8 == 0x22)) {
          *(int *)(*param_1 + iVar5) = *(int *)(*param_1 + iVar5) + 1;
          pcVar1 = param_2 + 1;
          param_2 = param_2 + 1;
          cVar2 = *pcVar1;
          while ((cVar2 != 0 && (iVar8 != cVar2))) {
            param_2 = param_2 + 1;
            cVar2 = *param_2;
          }
          cVar2 = param_2[1];
          *param_2 = '\0';
LAB_0045a2dc:
          iVar8 = (int)cVar2;
          param_2 = param_2 + 1;
          if (iVar8 != 0) {
            iVar5 = iVar5 + 4;
            iVar7 = *param_1;
            goto LAB_0045a1a0;
          }
        }
        else if (iVar8 != 0) {
          if (iVar8 == 0x20) {
LAB_0045a2f0:
            cVar2 = param_2[1];
          }
          else {
            if (1 < (iVar8 - 9U & 0xff)) {
              do {
                param_2 = param_2 + 1;
                iVar8 = (int)*param_2;
                if (iVar8 == 0) goto LAB_0045a23c;
              } while ((iVar8 != 0x20) && (1 < (iVar8 - 9U & 0xff)));
              goto LAB_0045a2f0;
            }
            cVar2 = param_2[1];
          }
          *param_2 = '\0';
          goto LAB_0045a2dc;
        }
LAB_0045a23c:
        iVar7 = *param_1;
        break;
      }
      param_2 = param_2 + 1;
      iVar8 = (int)*param_2;
    } while (iVar8 != 0);
  }
  *param_3 = iVar4;
  *param_4 = iVar7;
  return 1;
}

