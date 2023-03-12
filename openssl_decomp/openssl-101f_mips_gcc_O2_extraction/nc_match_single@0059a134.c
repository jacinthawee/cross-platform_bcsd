
undefined4 nc_match_single(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  int *piVar6;
  int *piVar7;
  
  iVar1 = *param_2;
  if (iVar1 == 2) {
    pcVar3 = (char *)((int *)param_2[1])[2];
    if (*pcVar3 == '\0') {
      return 0;
    }
    iVar2 = *(int *)param_2[1];
    iVar1 = **(int **)(param_1 + 4);
    if ((iVar2 < iVar1) && (*(char *)((*(int **)(param_1 + 4))[2] + (iVar1 - iVar2) + -1) != '.')) {
      return 0x2f;
    }
    iVar1 = (*(code *)PTR_strcasecmp_006aab24)(pcVar3);
  }
  else if (iVar1 < 3) {
    if (iVar1 != 1) {
      return 0x33;
    }
    piVar6 = (int *)param_2[1];
    piVar7 = *(int **)(param_1 + 4);
    pcVar5 = (char *)piVar6[2];
    iVar2 = piVar7[2];
    pcVar3 = (char *)(*(code *)PTR_strchr_006aab34)(pcVar5,0x40);
    iVar1 = (*(code *)PTR_strchr_006aab34)(iVar2,0x40);
    if (iVar1 == 0) {
      return 0x35;
    }
    if (pcVar3 == (char *)0x0) {
      if (*pcVar5 == '.') {
        iVar1 = *piVar7;
        iVar4 = *piVar6;
        if (iVar1 <= iVar4) {
          return 0x2f;
        }
        iVar1 = (*(code *)PTR_strcasecmp_006aab24)(pcVar5,iVar2 + (iVar1 - iVar4));
        goto joined_r0x0059a4a4;
      }
    }
    else {
      if (pcVar5 != pcVar3) {
        if ((int)pcVar3 - (int)pcVar5 != iVar1 - iVar2) {
          return 0x2f;
        }
        iVar2 = (*(code *)PTR_strncmp_006aaa7c)(pcVar5,iVar2);
        if (iVar2 != 0) {
          return 0x2f;
        }
      }
      pcVar5 = pcVar3 + 1;
    }
    iVar1 = (*(code *)PTR_strcasecmp_006aab24)(pcVar5,iVar1 + 1);
  }
  else {
    if (iVar1 != 4) {
      if (iVar1 != 6) {
        return 0x33;
      }
      iVar1 = (*(code *)PTR_strchr_006aab34)(*(undefined4 *)(*(int *)(param_1 + 4) + 8),0x3a);
      if (((iVar1 != 0) && (*(char *)(iVar1 + 1) == '/')) && (*(char *)(iVar1 + 2) == '/')) {
        iVar1 = iVar1 + 3;
        iVar2 = (*(code *)PTR_strchr_006aab34)(iVar1,0x3a);
        if ((iVar2 == 0) && (iVar2 = (*(code *)PTR_strchr_006aab34)(iVar1,0x2f), iVar2 == 0)) {
          iVar2 = (*(code *)PTR_strlen_006aab30)(iVar1);
        }
        else {
          iVar2 = iVar2 - iVar1;
        }
        if (iVar2 != 0) {
          pcVar3 = (char *)((int *)param_2[1])[2];
          iVar4 = *(int *)param_2[1];
          if (*pcVar3 == '.') {
            if (iVar2 <= iVar4) {
              return 0x2f;
            }
            iVar1 = (*(code *)PTR_strncasecmp_006aaae0)(iVar1 + (iVar2 - iVar4));
          }
          else {
            if (iVar4 != iVar2) {
              return 0x2f;
            }
            iVar1 = (*(code *)PTR_strncasecmp_006aaae0)(iVar1,pcVar3,iVar2);
          }
          goto joined_r0x0059a4a4;
        }
      }
      return 0x35;
    }
    iVar2 = *(int *)(param_1 + 4);
    iVar1 = param_2[1];
    if ((*(int *)(iVar2 + 4) != 0) &&
       (iVar4 = (*(code *)PTR_i2d_X509_NAME_006a87d8)(iVar2,0), iVar4 < 0)) {
      return 0x11;
    }
    if ((*(int *)(iVar1 + 4) != 0) &&
       (iVar4 = (*(code *)PTR_i2d_X509_NAME_006a87d8)(iVar1,0), iVar4 < 0)) {
      return 0x11;
    }
    if (*(int *)(iVar2 + 0x10) < *(int *)(iVar1 + 0x10)) {
      return 0x2f;
    }
    iVar1 = (*(code *)PTR_memcmp_006aabd8)
                      (*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar2 + 0xc));
  }
joined_r0x0059a4a4:
  if (iVar1 != 0) {
    return 0x2f;
  }
  return 0;
}

