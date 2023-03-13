
void BN_consttime_swap(int param_1,uint **param_2,uint **param_3,int param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0xffffffff - (param_1 + -1 >> 0x1f);
  uVar3 = ((uint)param_3[1] ^ (uint)param_2[1]) & uVar5;
  param_2[1] = (uint *)((uint)param_2[1] ^ uVar3);
  param_3[1] = (uint *)((uint)param_3[1] ^ uVar3);
  puVar1 = *param_2;
  puVar2 = *param_3;
  switch(param_4) {
  default:
    if (10 < param_4) {
      iVar4 = 10;
      do {
        uVar3 = (puVar2[iVar4] ^ puVar1[iVar4]) & uVar5;
        puVar1[iVar4] = puVar1[iVar4] ^ uVar3;
        puVar2[iVar4] = puVar2[iVar4] ^ uVar3;
        iVar4 = iVar4 + 1;
      } while (param_4 != iVar4);
    }
  case 10:
    uVar3 = (puVar2[9] ^ puVar1[9]) & uVar5;
    puVar1[9] = puVar1[9] ^ uVar3;
    puVar2[9] = puVar2[9] ^ uVar3;
  case 9:
    uVar3 = (puVar2[8] ^ puVar1[8]) & uVar5;
    puVar1[8] = puVar1[8] ^ uVar3;
    puVar2[8] = puVar2[8] ^ uVar3;
  case 8:
    uVar3 = (puVar2[7] ^ puVar1[7]) & uVar5;
    puVar1[7] = puVar1[7] ^ uVar3;
    puVar2[7] = puVar2[7] ^ uVar3;
  case 7:
    uVar3 = (puVar2[6] ^ puVar1[6]) & uVar5;
    puVar1[6] = puVar1[6] ^ uVar3;
    puVar2[6] = puVar2[6] ^ uVar3;
  case 6:
    uVar3 = (puVar2[5] ^ puVar1[5]) & uVar5;
    puVar1[5] = puVar1[5] ^ uVar3;
    puVar2[5] = puVar2[5] ^ uVar3;
  case 5:
    uVar3 = (puVar2[4] ^ puVar1[4]) & uVar5;
    puVar1[4] = puVar1[4] ^ uVar3;
    puVar2[4] = puVar2[4] ^ uVar3;
  case 4:
    uVar3 = (puVar2[3] ^ puVar1[3]) & uVar5;
    puVar1[3] = puVar1[3] ^ uVar3;
    puVar2[3] = puVar2[3] ^ uVar3;
  case 3:
    uVar3 = (puVar2[2] ^ puVar1[2]) & uVar5;
    puVar1[2] = puVar1[2] ^ uVar3;
    puVar2[2] = puVar2[2] ^ uVar3;
  case 2:
    uVar3 = (puVar2[1] ^ puVar1[1]) & uVar5;
    puVar1[1] = puVar1[1] ^ uVar3;
    puVar2[1] = puVar2[1] ^ uVar3;
  case 1:
    uVar5 = uVar5 & (*puVar2 ^ *puVar1);
    *puVar1 = *puVar1 ^ uVar5;
    *puVar2 = *puVar2 ^ uVar5;
    return;
  }
}

