
void BN_consttime_swap(int param_1,uint **param_2,uint **param_3,int param_4)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar8;
  uint *puVar7;
  
  uVar4 = 0xffffffff - (param_1 + -1 >> 0x1f);
  uVar1 = ((uint)param_2[1] ^ (uint)param_3[1]) & uVar4;
  param_2[1] = (uint *)((uint)param_2[1] ^ uVar1);
  param_3[1] = (uint *)((uint)param_3[1] ^ uVar1);
  switch(param_4) {
  default:
    if (param_4 < 0xb) goto switchD_004f41e8_caseD_a;
    puVar2 = *param_3;
    puVar3 = *param_2;
    puVar6 = puVar2 + 10;
    puVar8 = puVar3 + 10;
    do {
      puVar7 = puVar6 + 1;
      uVar1 = (*puVar8 ^ *puVar6) & uVar4;
      *puVar8 = *puVar8 ^ uVar1;
      *puVar6 = *puVar6 ^ uVar1;
      puVar6 = puVar7;
      puVar8 = puVar8 + 1;
    } while (puVar2 + param_4 != puVar7);
    uVar1 = puVar3[9];
    break;
  case 1:
    puVar3 = *param_2;
    puVar2 = *param_3;
    goto LAB_004f433c;
  case 2:
    puVar3 = *param_2;
    puVar2 = *param_3;
    goto LAB_004f4318;
  case 3:
    puVar3 = *param_2;
    puVar2 = *param_3;
    goto LAB_004f42f4;
  case 4:
    puVar3 = *param_2;
    puVar2 = *param_3;
    goto LAB_004f42d0;
  case 5:
    puVar3 = *param_2;
    puVar2 = *param_3;
    goto LAB_004f42ac;
  case 6:
    puVar3 = *param_2;
    puVar2 = *param_3;
    goto LAB_004f4288;
  case 7:
    puVar3 = *param_2;
    puVar2 = *param_3;
    goto LAB_004f4264;
  case 8:
    puVar3 = *param_2;
    puVar2 = *param_3;
    goto LAB_004f4240;
  case 9:
    puVar3 = *param_2;
    puVar2 = *param_3;
    goto LAB_004f421c;
  case 10:
switchD_004f41e8_caseD_a:
    puVar3 = *param_2;
    puVar2 = *param_3;
    uVar1 = puVar3[9];
  }
  uVar5 = (uVar1 ^ puVar2[9]) & uVar4;
  puVar3[9] = uVar1 ^ uVar5;
  puVar2[9] = puVar2[9] ^ uVar5;
LAB_004f421c:
  uVar1 = (puVar3[8] ^ puVar2[8]) & uVar4;
  puVar3[8] = puVar3[8] ^ uVar1;
  puVar2[8] = puVar2[8] ^ uVar1;
LAB_004f4240:
  uVar1 = (puVar3[7] ^ puVar2[7]) & uVar4;
  puVar3[7] = puVar3[7] ^ uVar1;
  puVar2[7] = puVar2[7] ^ uVar1;
LAB_004f4264:
  uVar1 = (puVar3[6] ^ puVar2[6]) & uVar4;
  puVar3[6] = puVar3[6] ^ uVar1;
  puVar2[6] = puVar2[6] ^ uVar1;
LAB_004f4288:
  uVar1 = (puVar3[5] ^ puVar2[5]) & uVar4;
  puVar3[5] = puVar3[5] ^ uVar1;
  puVar2[5] = puVar2[5] ^ uVar1;
LAB_004f42ac:
  uVar1 = (puVar3[4] ^ puVar2[4]) & uVar4;
  puVar3[4] = puVar3[4] ^ uVar1;
  puVar2[4] = puVar2[4] ^ uVar1;
LAB_004f42d0:
  uVar1 = (puVar3[3] ^ puVar2[3]) & uVar4;
  puVar3[3] = puVar3[3] ^ uVar1;
  puVar2[3] = puVar2[3] ^ uVar1;
LAB_004f42f4:
  uVar1 = (puVar3[2] ^ puVar2[2]) & uVar4;
  puVar3[2] = puVar3[2] ^ uVar1;
  puVar2[2] = puVar2[2] ^ uVar1;
LAB_004f4318:
  uVar1 = (puVar3[1] ^ puVar2[1]) & uVar4;
  puVar3[1] = puVar3[1] ^ uVar1;
  puVar2[1] = puVar2[1] ^ uVar1;
LAB_004f433c:
  uVar4 = (*puVar3 ^ *puVar2) & uVar4;
  *puVar3 = *puVar3 ^ uVar4;
  *puVar2 = *puVar2 ^ uVar4;
  return;
}

