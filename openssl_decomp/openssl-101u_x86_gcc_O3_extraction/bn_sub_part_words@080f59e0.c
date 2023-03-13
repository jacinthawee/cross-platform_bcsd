
ulong bn_sub_part_words(ulong *param_1,ulong *param_2,ulong *param_3,int param_4,int param_5)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar2 = bn_sub_words(param_1,param_2,param_3,param_4);
  if (param_5 != 0) {
    param_1 = param_1 + param_4;
    if (-1 < param_5) {
      param_2 = param_2 + param_4;
      do {
        if (uVar2 == 0) {
LAB_080f5aa6:
          *param_1 = *param_2;
          while (((param_5 != 1 && (param_1[1] = param_2[1], param_5 != 2)) &&
                 (param_1[2] = param_2[2], param_5 != 3))) {
            param_5 = param_5 + -4;
            param_1[3] = param_2[3];
            if (param_5 == 0) {
              return 0;
            }
            param_2 = param_2 + 4;
            param_1 = param_1 + 4;
            *param_1 = *param_2;
          }
          return 0;
        }
        uVar3 = *param_2 - uVar2;
        if (*param_2 != 0) {
          uVar2 = 0;
        }
        *param_1 = uVar3;
        if (param_5 == 1) {
          return uVar2;
        }
        uVar3 = param_2[1] - uVar2;
        if (param_2[1] != 0) {
          uVar2 = 0;
        }
        param_1[1] = uVar3;
        if (param_5 == 2) {
          return uVar2;
        }
        uVar3 = param_2[2] - uVar2;
        if (param_2[2] != 0) {
          uVar2 = 0;
        }
        param_1[2] = uVar3;
        if (param_5 == 3) {
          return uVar2;
        }
        uVar3 = param_2[3];
        param_1[3] = uVar3 - uVar2;
        if (uVar3 != 0) {
          param_5 = param_5 + -4;
          if (param_5 == 0) {
            return 0;
          }
          param_2 = param_2 + 4;
          param_1 = param_1 + 4;
          goto LAB_080f5aa6;
        }
        param_5 = param_5 + -4;
        if (param_5 == 0) {
          return uVar2;
        }
        param_2 = param_2 + 4;
        param_1 = param_1 + 4;
      } while( true );
    }
    param_3 = param_3 + param_4;
    while( true ) {
      iVar1 = uVar2 + *param_3;
      if (*param_3 != 0) {
        uVar2 = 1;
      }
      *param_1 = -iVar1;
      if (param_5 == -1) break;
      iVar1 = uVar2 + param_3[1];
      if (param_3[1] != 0) {
        uVar2 = 1;
      }
      param_1[1] = -iVar1;
      if (param_5 == -2) {
        return uVar2;
      }
      iVar1 = uVar2 + param_3[2];
      if (param_3[2] != 0) {
        uVar2 = 1;
      }
      param_1[2] = -iVar1;
      if (param_5 == -3) {
        return uVar2;
      }
      iVar1 = uVar2 + param_3[3];
      if (param_3[3] != 0) {
        uVar2 = 1;
      }
      param_5 = param_5 + 4;
      param_1[3] = -iVar1;
      if (param_5 == 0) {
        return uVar2;
      }
      param_3 = param_3 + 4;
      param_1 = param_1 + 4;
    }
  }
  return uVar2;
}

