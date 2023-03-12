
int __regparm3 nc_match(int *param_1,_STACK **param_2)

{
  int iVar1;
  int **ppiVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = 0;
  do {
    iVar1 = sk_num(*param_2);
    if (iVar1 <= iVar3) {
      iVar3 = 0;
      if (iVar4 == 1) {
        return 0x2f;
      }
      do {
        iVar4 = sk_num(param_2[1]);
        if (iVar4 <= iVar3) {
          return 0;
        }
        ppiVar2 = (int **)sk_value(param_2[1],iVar3);
        if (*param_1 == **ppiVar2) {
          if ((ppiVar2[1] != (int *)0x0) || (ppiVar2[2] != (int *)0x0)) {
            return 0x31;
          }
          iVar4 = nc_match_single();
          if (iVar4 == 0) {
            return 0x30;
          }
          if (iVar4 != 0x2f) {
            return iVar4;
          }
        }
        iVar3 = iVar3 + 1;
      } while( true );
    }
    ppiVar2 = (int **)sk_value(*param_2,iVar3);
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
        iVar1 = nc_match_single();
        if (iVar1 != 0) {
          if (iVar1 != 0x2f) {
            return iVar1;
          }
          goto LAB_08176388;
        }
      }
      iVar4 = 2;
    }
LAB_08176388:
    iVar3 = iVar3 + 1;
  } while( true );
}

