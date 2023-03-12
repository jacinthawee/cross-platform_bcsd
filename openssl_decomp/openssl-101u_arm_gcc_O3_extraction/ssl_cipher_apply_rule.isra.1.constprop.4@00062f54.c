
void ssl_cipher_apply_rule_isra_1_constprop_4(uint param_1,int **param_2,int **param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  
  piVar4 = *param_3;
  piVar1 = *param_2;
  piVar6 = piVar4;
  if ((piVar4 != (int *)0x0) && (piVar1 != (int *)0x0)) {
    piVar2 = piVar1;
    if (param_1 == 0) {
      do {
        piVar3 = (int *)piVar2[3];
        if ((piVar2[1] != 0) && (piVar2 != piVar6)) {
          iVar5 = piVar2[4];
          if (piVar2 == piVar1) {
            piVar1 = piVar3;
          }
          piVar7 = piVar3;
          if (iVar5 != 0) {
            *(int **)(iVar5 + 0xc) = piVar3;
            piVar7 = (int *)piVar2[3];
          }
          if (piVar7 != (int *)0x0) {
            piVar7[4] = iVar5;
          }
          piVar6[3] = (int)piVar2;
          piVar2[4] = (int)piVar6;
          piVar2[3] = 0;
          piVar6 = piVar2;
        }
      } while ((piVar4 != piVar2) && (piVar2 = piVar3, piVar3 != (int *)0x0));
    }
    else {
      do {
        piVar3 = (int *)piVar2[3];
        if ((((param_1 & *(uint *)(*piVar2 + 0xc)) != 0) && (piVar2[1] != 0)) && (piVar2 != piVar6))
        {
          iVar5 = piVar2[4];
          if (piVar2 == piVar1) {
            piVar1 = piVar3;
          }
          piVar7 = piVar3;
          if (iVar5 != 0) {
            *(int **)(iVar5 + 0xc) = piVar3;
            piVar7 = (int *)piVar2[3];
          }
          if (piVar7 != (int *)0x0) {
            piVar7[4] = iVar5;
          }
          piVar6[3] = (int)piVar2;
          piVar2[4] = (int)piVar6;
          piVar2[3] = 0;
          piVar6 = piVar2;
        }
      } while ((piVar4 != piVar2) && (piVar2 = piVar3, piVar3 != (int *)0x0));
    }
  }
  *param_2 = piVar1;
  *param_3 = piVar6;
  return;
}

