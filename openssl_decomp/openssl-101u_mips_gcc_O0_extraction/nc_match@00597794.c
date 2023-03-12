
int nc_match(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int **ppiVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = 0;
  iVar1 = (*(code *)PTR_sk_num_006a6e2c)(*param_2);
  if (0 < iVar1) {
    do {
      ppiVar2 = (int **)(*(code *)PTR_sk_value_006a6e24)(*param_2,iVar3);
      if (*param_1 == **ppiVar2) {
        if (ppiVar2[1] != (int *)0x0) {
          return 0x31;
        }
        if (ppiVar2[2] != (int *)0x0) {
          return 0x31;
        }
        if (iVar4 != 2) {
          if (iVar4 == 0) {
            iVar4 = 1;
          }
          iVar1 = nc_match_single(param_1);
          if (iVar1 != 0) {
            if (iVar1 != 0x2f) {
              return iVar1;
            }
            goto LAB_00597824;
          }
        }
        iVar4 = 2;
      }
LAB_00597824:
      iVar3 = iVar3 + 1;
      iVar1 = (*(code *)PTR_sk_num_006a6e2c)(*param_2);
    } while (iVar3 < iVar1);
  }
  iVar1 = 0;
  if (iVar4 == 1) {
    return 0x2f;
  }
  do {
    do {
      iVar3 = (*(code *)PTR_sk_num_006a6e2c)(param_2[1]);
      if (iVar3 <= iVar1) {
        return 0;
      }
      iVar3 = iVar1 + 1;
      ppiVar2 = (int **)(*(code *)PTR_sk_value_006a6e24)(param_2[1],iVar1);
      iVar1 = iVar3;
    } while (*param_1 != **ppiVar2);
    if ((ppiVar2[1] != (int *)0x0) || (ppiVar2[2] != (int *)0x0)) {
      return 0x31;
    }
    iVar3 = nc_match_single(param_1);
    if (iVar3 == 0) {
      return 0x30;
    }
  } while (iVar3 == 0x2f);
  return iVar3;
}

