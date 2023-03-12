
void bn_mul_high(ulong *param_1,ulong *param_2,ulong *param_3,ulong *param_4,int param_5,
                ulong *param_6)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  uint uVar10;
  ulong *puVar11;
  uint uVar12;
  ulong *puVar13;
  int num;
  uint uVar14;
  ulong *puVar15;
  ulong *bp;
  
  num = param_5 / 2;
  puVar15 = param_2 + num;
  puVar13 = param_3 + num;
  iVar2 = bn_cmp_words(param_2,puVar15,num);
  iVar3 = bn_cmp_words(puVar13,param_3,num);
  switch(iVar3 + iVar2 * 3) {
  case 2:
    bn_sub_words(param_1,param_2,puVar15,num);
    bVar1 = true;
    bn_sub_words(param_1 + num,param_3,puVar13,num);
    break;
  case 4:
    bn_sub_words(param_1,param_2,puVar15,num);
    bVar1 = false;
    bn_sub_words(param_1 + num,puVar13,param_3,num);
    break;
  case -4:
    bn_sub_words(param_1,puVar15,param_2,num);
    bVar1 = false;
    bn_sub_words(param_1 + num,param_3,puVar13,num);
    break;
  default:
    bVar1 = false;
    break;
  case -2:
    bn_sub_words(param_1,puVar15,param_2,num);
    bVar1 = true;
    bn_sub_words(param_1 + num,puVar13,param_3,num);
  }
  if (num == 8) {
    bn_mul_comba8(param_6,param_1,param_1 + 8);
    bn_mul_comba8(param_1,puVar15,puVar13);
  }
  else {
    bn_mul_recursive_constprop_0(param_6,param_1,param_1 + num,num,param_6 + param_5);
    bn_mul_recursive_constprop_0(param_1,puVar15,puVar13,num,param_6 + param_5);
  }
  puVar13 = param_6 + param_5;
  if (param_4 == (ulong *)0x0) {
    puVar15 = param_6 + param_5 + num;
    puVar11 = param_1;
  }
  else {
    puVar15 = param_6 + param_5 + num;
    bn_add_words(puVar15,param_1,param_4,num);
    puVar11 = puVar15;
  }
  if (bVar1) {
    bn_sub_words(puVar13,puVar11,param_6,num);
  }
  else {
    bn_add_words(puVar13,puVar11,param_6,num);
  }
  if (param_4 == (ulong *)0x0) {
    if (0 < num) {
      do {
        *(int *)((int)puVar15 + (int)param_4) = -*(int *)((int)puVar13 + (int)param_4);
        param_4 = param_4 + 1;
      } while (num * 4 - (int)param_4 != 0);
    }
    uVar4 = 0;
    puVar11 = puVar15;
  }
  else {
    bn_sub_words(puVar15,param_4 + num,puVar13,num);
    uVar4 = bn_add_words(puVar13,puVar15,param_4,num);
    puVar11 = puVar13;
  }
  bp = param_1 + num;
  uVar5 = bn_add_words(puVar13,puVar11,param_1,num);
  if (bVar1) {
    uVar6 = bn_sub_words(puVar13,puVar13,param_6,num);
    uVar6 = -uVar6;
    uVar7 = bn_add_words(param_1,param_1,puVar15,num);
    uVar8 = bn_add_words(param_1,param_1,bp,num);
    uVar9 = bn_sub_words(param_1,param_1,param_6 + num,num);
    uVar10 = (uVar8 + uVar7) - uVar9;
  }
  else {
    uVar6 = bn_add_words(puVar13,puVar13,param_6,num);
    uVar7 = bn_add_words(param_1,param_1,puVar15,num);
    uVar8 = bn_add_words(param_1,param_1,bp,num);
    uVar9 = bn_add_words(param_1,param_1,param_6 + num,num);
    uVar10 = uVar9 + uVar8 + uVar7;
  }
  uVar14 = uVar4 + uVar5 + uVar6;
  if (uVar14 != 0) {
    if ((int)uVar14 < 1) {
      uVar14 = -uVar14;
      do {
        uVar12 = *param_1;
        *param_1 = uVar12 - uVar14;
        uVar14 = (uint)(uVar12 < uVar14);
        param_1 = param_1 + 1;
      } while (uVar14 != 0);
    }
    else {
      do {
        uVar4 = *param_1;
        *param_1 = uVar4 + uVar14;
        uVar14 = (uint)(uVar4 + uVar14 < uVar14);
        param_1 = param_1 + 1;
      } while (uVar14 != 0);
    }
  }
  if (uVar10 != 0) {
    if ((int)uVar10 < 1) {
      uVar10 = -uVar10;
      do {
        uVar14 = *bp;
        *bp = uVar14 - uVar10;
        uVar10 = (uint)(uVar14 < uVar10);
        bp = bp + 1;
      } while (uVar10 != 0);
      return;
    }
    do {
      uVar14 = *bp;
      *bp = uVar14 + uVar10;
      uVar10 = (uint)(uVar14 + uVar10 < uVar10);
      bp = bp + 1;
    } while (uVar10 != 0);
  }
  return;
}

