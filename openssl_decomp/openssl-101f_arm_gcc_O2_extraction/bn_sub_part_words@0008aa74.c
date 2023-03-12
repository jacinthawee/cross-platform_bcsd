
ulong bn_sub_part_words(ulong *param_1,ulong *param_2,ulong *param_3,int param_4,int param_5)

{
  ulong *puVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  ulong *puVar5;
  
  uVar2 = bn_sub_words(param_1,param_2,param_3,param_4);
  if (param_5 != 0) {
    if (param_5 < 0) {
      param_3 = param_3 + param_4;
      puVar5 = param_1 + param_4;
      do {
        iVar4 = *param_3 + uVar2;
        if (*param_3 != 0) {
          uVar2 = 1;
        }
        *puVar5 = -iVar4;
        if (param_5 + 1 < 0 == SCARRY4(param_5,1)) {
          return uVar2;
        }
        iVar4 = uVar2 + param_3[1];
        if (param_3[1] != 0) {
          uVar2 = 1;
        }
        puVar5[1] = -iVar4;
        if (param_5 == -2) {
          return uVar2;
        }
        iVar4 = uVar2 + param_3[2];
        if (param_3[2] != 0) {
          uVar2 = 1;
        }
        puVar5[2] = -iVar4;
        if (param_5 == -3) {
          return uVar2;
        }
        puVar1 = param_3 + 3;
        param_3 = param_3 + 4;
        iVar4 = uVar2 + *puVar1;
        if (*puVar1 != 0) {
          uVar2 = 1;
        }
        param_5 = param_5 + 4;
        puVar5[3] = -iVar4;
        puVar5 = puVar5 + 4;
      } while (param_5 != 0);
    }
    else {
      param_2 = param_2 + param_4;
      puVar5 = param_1 + param_4;
      do {
        if (uVar2 == 0) {
          *puVar5 = *param_2;
          if (param_5 == 1) {
            return 0;
          }
          do {
            puVar5[1] = param_2[1];
            if (param_5 == 2) {
              return 0;
            }
            puVar5[2] = param_2[2];
            if (param_5 == 3) {
              return 0;
            }
            param_5 = param_5 + -4;
            puVar5[3] = param_2[3];
            if (param_5 == 0) {
              return 0;
            }
            param_2 = param_2 + 4;
            puVar5 = puVar5 + 4;
            *puVar5 = *param_2;
          } while (1 < param_5);
          return 0;
        }
        uVar3 = *param_2 - uVar2;
        if (*param_2 != 0) {
          uVar2 = 0;
        }
        *puVar5 = uVar3;
        if (param_5 == 1) {
          return uVar2;
        }
        uVar3 = param_2[1] - uVar2;
        if (param_2[1] != 0) {
          uVar2 = 0;
        }
        puVar5[1] = uVar3;
        if (param_5 == 2) {
          return uVar2;
        }
        uVar3 = param_2[2] - uVar2;
        if (param_2[2] != 0) {
          uVar2 = 0;
        }
        puVar5[2] = uVar3;
        if (param_5 == 3) {
          return uVar2;
        }
        puVar1 = param_2 + 3;
        param_2 = param_2 + 4;
        uVar3 = *puVar1 - uVar2;
        if (*puVar1 != 0) {
          uVar2 = 0;
        }
        param_5 = param_5 + -4;
        puVar5[3] = uVar3;
        puVar5 = puVar5 + 4;
      } while (param_5 != 0);
    }
  }
  return uVar2;
}

