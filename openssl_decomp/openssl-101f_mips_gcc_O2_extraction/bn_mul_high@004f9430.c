
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
  ulong *puVar16;
  
  num = param_5 / 2;
  puVar15 = param_2 + num;
  iVar2 = bn_cmp_words(param_2,puVar15,num);
  puVar16 = param_3 + num;
  iVar3 = bn_cmp_words(puVar16,param_3,num);
  iVar3 = iVar2 * 3 + iVar3;
  if (iVar3 == -2) {
    bn_sub_words(param_1,puVar15,param_2,num);
    puVar11 = puVar16;
LAB_004f9780:
    bn_sub_words(param_1 + num,puVar11,param_3,num);
    bVar1 = true;
    if (num == 8) goto LAB_004f97a4;
LAB_004f954c:
    bn_mul_recursive_constprop_0(param_6,param_1,param_1 + num,num,param_6 + param_5);
    bn_mul_recursive_constprop_0(param_1,puVar15,puVar16,num,param_6 + param_5);
    if (param_4 != (ulong *)0x0) goto LAB_004f9598;
LAB_004f97f0:
    puVar15 = param_6 + param_5 + num;
    puVar16 = param_1;
    if (bVar1) goto LAB_004f95c8;
  }
  else {
    if (iVar3 < -1) {
      if (iVar3 == -4) {
        bn_sub_words(param_1,puVar15,param_2,num);
        bn_sub_words(param_1 + num,param_3,puVar16,num);
      }
    }
    else {
      if (iVar3 == 2) {
        bn_sub_words(param_1,param_2,puVar15,num);
        puVar11 = param_3;
        param_3 = puVar16;
        goto LAB_004f9780;
      }
      if (iVar3 == 4) {
        bn_sub_words(param_1,param_2,puVar15,num);
        bn_sub_words(param_1 + num,puVar16,param_3,num);
      }
    }
    bVar1 = false;
    if (num != 8) goto LAB_004f954c;
LAB_004f97a4:
    bn_mul_comba8(param_6,param_1,param_1 + num);
    bn_mul_comba8(param_1,puVar15,puVar16);
    if (param_4 == (ulong *)0x0) goto LAB_004f97f0;
LAB_004f9598:
    puVar15 = param_6 + param_5 + num;
    bn_add_words(puVar15,param_1,param_4,num);
    puVar16 = puVar15;
    if (bVar1) {
LAB_004f95c8:
      bn_sub_words(param_6 + param_5,puVar16,param_6,num);
      goto joined_r0x004f981c;
    }
  }
  bn_add_words(param_6 + param_5,puVar16,param_6,num);
joined_r0x004f981c:
  puVar16 = param_6 + param_5;
  if (param_4 == (ulong *)0x0) {
    if (0 < num) {
      puVar11 = puVar16;
      puVar13 = puVar15;
      do {
        uVar4 = *puVar11;
        puVar11 = puVar11 + 1;
        *puVar13 = -uVar4;
        puVar13 = puVar13 + 1;
      } while (puVar11 != param_6 + param_5 + num);
    }
    uVar4 = 0;
    puVar11 = puVar15;
  }
  else {
    bn_sub_words(puVar15,param_4 + num,puVar16,num);
    uVar4 = bn_add_words(puVar16,puVar15,param_4,num);
    puVar11 = puVar16;
  }
  puVar13 = param_1 + num;
  uVar5 = bn_add_words(puVar16,puVar11,param_1,num);
  if (bVar1) {
    uVar6 = bn_sub_words(puVar16,puVar16,param_6,num);
    uVar6 = -uVar6;
    uVar7 = bn_add_words(param_1,param_1,puVar15,num);
    uVar8 = bn_add_words(param_1,param_1,puVar13,num);
    uVar9 = bn_sub_words(param_1,param_1,param_6 + num,num);
    uVar10 = (uVar8 + uVar7) - uVar9;
  }
  else {
    uVar6 = bn_add_words(puVar16,puVar16,param_6,num);
    uVar7 = bn_add_words(param_1,param_1,puVar15,num);
    uVar8 = bn_add_words(param_1,param_1,puVar13,num);
    uVar9 = bn_add_words(param_1,param_1,param_6 + num,num);
    uVar10 = uVar9 + uVar8 + uVar7;
  }
  uVar14 = uVar5 + uVar4 + uVar6;
  if (uVar14 != 0) {
    if ((int)uVar14 < 1) {
      uVar14 = -uVar14;
      do {
        uVar4 = *param_1 - uVar14;
        uVar14 = (uint)(*param_1 < uVar14);
        *param_1 = uVar4;
        param_1 = param_1 + 1;
      } while (uVar14 != 0);
    }
    else {
      do {
        uVar12 = uVar14 + *param_1;
        uVar14 = (uint)(uVar12 < uVar14);
        *param_1 = uVar12;
        param_1 = param_1 + 1;
      } while (uVar14 != 0);
    }
  }
  if (uVar10 != 0) {
    if ((int)uVar10 < 1) {
      uVar10 = -uVar10;
      do {
        uVar14 = *puVar13 - uVar10;
        uVar10 = (uint)(*puVar13 < uVar10);
        *puVar13 = uVar14;
        puVar13 = puVar13 + 1;
      } while (uVar10 != 0);
      return;
    }
    do {
      uVar14 = uVar10 + *puVar13;
      uVar10 = (uint)(uVar14 < uVar10);
      *puVar13 = uVar14;
      puVar13 = puVar13 + 1;
    } while (uVar10 != 0);
  }
  return;
}

