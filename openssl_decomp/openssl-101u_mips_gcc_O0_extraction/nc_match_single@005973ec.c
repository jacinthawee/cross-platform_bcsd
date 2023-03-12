
undefined4 nc_match_single(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  int *piVar7;
  int *piVar8;
  
  iVar2 = *param_2;
  if (iVar2 == 2) {
    pcVar4 = (char *)((int *)param_2[1])[2];
    cVar1 = *pcVar4;
    if (cVar1 == '\0') {
      return 0;
    }
    iVar3 = *(int *)param_2[1];
    iVar2 = **(int **)(param_1 + 4);
    if (((iVar3 < iVar2) && (cVar1 != '.')) &&
       (*(char *)((*(int **)(param_1 + 4))[2] + (iVar2 - iVar3) + -1) != '.')) {
      return 0x2f;
    }
    iVar2 = (*(code *)PTR_strcasecmp_006a9a18)(pcVar4);
  }
  else if (iVar2 < 3) {
    if (iVar2 != 1) {
      return 0x33;
    }
    piVar7 = (int *)param_2[1];
    piVar8 = *(int **)(param_1 + 4);
    pcVar6 = (char *)piVar7[2];
    iVar3 = piVar8[2];
    pcVar4 = (char *)(*(code *)PTR_strchr_006a9a28)(pcVar6,0x40);
    iVar2 = (*(code *)PTR_strchr_006a9a28)(iVar3,0x40);
    if (iVar2 == 0) {
      return 0x35;
    }
    if (pcVar4 == (char *)0x0) {
      if (*pcVar6 == '.') {
        iVar2 = *piVar8;
        iVar5 = *piVar7;
        if (iVar2 <= iVar5) {
          return 0x2f;
        }
        iVar2 = (*(code *)PTR_strcasecmp_006a9a18)(pcVar6,iVar3 + (iVar2 - iVar5));
        goto joined_r0x00597760;
      }
    }
    else {
      if (pcVar6 != pcVar4) {
        if ((int)pcVar4 - (int)pcVar6 != iVar2 - iVar3) {
          return 0x2f;
        }
        iVar3 = (*(code *)PTR_strncmp_006a9970)(pcVar6,iVar3);
        if (iVar3 != 0) {
          return 0x2f;
        }
      }
      pcVar6 = pcVar4 + 1;
    }
    iVar2 = (*(code *)PTR_strcasecmp_006a9a18)(pcVar6,iVar2 + 1);
  }
  else {
    if (iVar2 != 4) {
      if (iVar2 != 6) {
        return 0x33;
      }
      iVar2 = (*(code *)PTR_strchr_006a9a28)(*(undefined4 *)(*(int *)(param_1 + 4) + 8),0x3a);
      if (((iVar2 != 0) && (*(char *)(iVar2 + 1) == '/')) && (*(char *)(iVar2 + 2) == '/')) {
        iVar2 = iVar2 + 3;
        iVar3 = (*(code *)PTR_strchr_006a9a28)(iVar2,0x3a);
        if ((iVar3 == 0) && (iVar3 = (*(code *)PTR_strchr_006a9a28)(iVar2,0x2f), iVar3 == 0)) {
          iVar3 = (*(code *)PTR_strlen_006a9a24)(iVar2);
        }
        else {
          iVar3 = iVar3 - iVar2;
        }
        if (iVar3 != 0) {
          pcVar4 = (char *)((int *)param_2[1])[2];
          iVar5 = *(int *)param_2[1];
          if (*pcVar4 == '.') {
            if (iVar3 <= iVar5) {
              return 0x2f;
            }
            iVar2 = (*(code *)PTR_strncasecmp_006a99d4)(iVar2 + (iVar3 - iVar5));
          }
          else {
            if (iVar5 != iVar3) {
              return 0x2f;
            }
            iVar2 = (*(code *)PTR_strncasecmp_006a99d4)(iVar2,pcVar4,iVar3);
          }
          goto joined_r0x00597760;
        }
      }
      return 0x35;
    }
    iVar3 = *(int *)(param_1 + 4);
    iVar2 = param_2[1];
    if ((*(int *)(iVar3 + 4) != 0) &&
       (iVar5 = (*(code *)PTR_i2d_X509_NAME_006a76ec)(iVar3,0), iVar5 < 0)) {
      return 0x11;
    }
    if ((*(int *)(iVar2 + 4) != 0) &&
       (iVar5 = (*(code *)PTR_i2d_X509_NAME_006a76ec)(iVar2,0), iVar5 < 0)) {
      return 0x11;
    }
    if (*(int *)(iVar3 + 0x10) < *(int *)(iVar2 + 0x10)) {
      return 0x2f;
    }
    iVar2 = (*(code *)PTR_memcmp_006a9ad0)
                      (*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar3 + 0xc));
  }
joined_r0x00597760:
  if (iVar2 != 0) {
    return 0x2f;
  }
  return 0;
}

