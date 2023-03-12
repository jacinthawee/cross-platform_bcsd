
void BN_consttime_swap(int param_1,uint **param_2,uint **param_3,int param_4)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  
  uVar1 = -param_1 >> 0x1f;
  uVar6 = ((uint)param_3[1] ^ (uint)param_2[1]) & uVar1;
  param_2[1] = (uint *)((uint)param_2[1] ^ uVar6);
  param_3[1] = (uint *)(uVar6 ^ (uint)param_3[1]);
  switch(param_4) {
  case 1:
    puVar2 = *param_2;
    puVar3 = *param_3;
    goto LAB_00088a3e;
  case 2:
    puVar2 = *param_2;
    puVar3 = *param_3;
    goto LAB_00088a2c;
  case 3:
    puVar2 = *param_2;
    puVar3 = *param_3;
    goto LAB_00088a1a;
  case 4:
    puVar2 = *param_2;
    puVar3 = *param_3;
    goto LAB_00088a08;
  case 5:
    puVar2 = *param_2;
    puVar3 = *param_3;
    goto LAB_000889f6;
  case 6:
    puVar2 = *param_2;
    puVar3 = *param_3;
    goto LAB_000889e4;
  case 7:
    puVar2 = *param_2;
    puVar3 = *param_3;
    goto LAB_000889d2;
  case 8:
    puVar2 = *param_2;
    puVar3 = *param_3;
    goto LAB_000889c0;
  case 9:
    puVar2 = *param_2;
    puVar3 = *param_3;
    goto LAB_000889ae;
  case 10:
    puVar2 = *param_2;
    puVar3 = *param_3;
    break;
  default:
    puVar2 = *param_2;
    if (param_4 < 0xb) {
      puVar3 = *param_3;
    }
    else {
      puVar3 = *param_3;
      iVar7 = 10;
      puVar4 = puVar3;
      puVar5 = puVar2;
      do {
        iVar7 = iVar7 + 1;
        uVar6 = (puVar5[10] ^ puVar4[10]) & uVar1;
        puVar5[10] = uVar6 ^ puVar5[10];
        puVar4[10] = puVar4[10] ^ uVar6;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      } while (iVar7 != param_4);
    }
  }
  uVar6 = (puVar3[9] ^ puVar2[9]) & uVar1;
  puVar2[9] = puVar2[9] ^ uVar6;
  puVar3[9] = uVar6 ^ puVar3[9];
LAB_000889ae:
  uVar6 = (puVar3[8] ^ puVar2[8]) & uVar1;
  puVar2[8] = puVar2[8] ^ uVar6;
  puVar3[8] = uVar6 ^ puVar3[8];
LAB_000889c0:
  uVar6 = (puVar3[7] ^ puVar2[7]) & uVar1;
  puVar2[7] = puVar2[7] ^ uVar6;
  puVar3[7] = uVar6 ^ puVar3[7];
LAB_000889d2:
  uVar6 = (puVar3[6] ^ puVar2[6]) & uVar1;
  puVar2[6] = puVar2[6] ^ uVar6;
  puVar3[6] = uVar6 ^ puVar3[6];
LAB_000889e4:
  uVar6 = (puVar3[5] ^ puVar2[5]) & uVar1;
  puVar2[5] = puVar2[5] ^ uVar6;
  puVar3[5] = uVar6 ^ puVar3[5];
LAB_000889f6:
  uVar6 = (puVar3[4] ^ puVar2[4]) & uVar1;
  puVar2[4] = puVar2[4] ^ uVar6;
  puVar3[4] = uVar6 ^ puVar3[4];
LAB_00088a08:
  uVar6 = (puVar3[3] ^ puVar2[3]) & uVar1;
  puVar2[3] = puVar2[3] ^ uVar6;
  puVar3[3] = uVar6 ^ puVar3[3];
LAB_00088a1a:
  uVar6 = (puVar3[2] ^ puVar2[2]) & uVar1;
  puVar2[2] = puVar2[2] ^ uVar6;
  puVar3[2] = uVar6 ^ puVar3[2];
LAB_00088a2c:
  uVar6 = (puVar3[1] ^ puVar2[1]) & uVar1;
  puVar2[1] = puVar2[1] ^ uVar6;
  puVar3[1] = uVar6 ^ puVar3[1];
LAB_00088a3e:
  uVar1 = uVar1 & (*puVar3 ^ *puVar2);
  *puVar2 = *puVar2 ^ uVar1;
  *puVar3 = uVar1 ^ *puVar3;
  return;
}

