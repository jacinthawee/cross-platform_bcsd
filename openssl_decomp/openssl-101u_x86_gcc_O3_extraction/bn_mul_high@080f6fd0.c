
void bn_mul_high(uint *param_1,ulong *param_2,ulong *param_3,ulong *param_4,int param_5,
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
  ulong *puVar12;
  int num;
  ulong *puVar13;
  uint uVar14;
  uint uVar15;
  uint *local_2c;
  ulong *local_28;
  
  num = param_5 / 2;
  puVar11 = param_2 + num;
  iVar2 = bn_cmp_words(param_2,puVar11,num);
  puVar13 = param_3 + num;
  iVar3 = bn_cmp_words(puVar13,param_3,num);
  iVar3 = iVar3 + iVar2 * 3;
  if (iVar3 == -2) {
    bn_sub_words(param_1,puVar11,param_2,num);
    bn_sub_words(param_1 + num,puVar13,param_3,num);
    bVar1 = true;
    goto joined_r0x080f707c;
  }
  if (iVar3 < -1) {
    if (iVar3 == -4) {
      bn_sub_words(param_1,puVar11,param_2,num);
      bn_sub_words(param_1 + num,param_3,puVar13,num);
      bVar1 = false;
      goto joined_r0x080f707c;
    }
  }
  else {
    if (iVar3 == 2) {
      bn_sub_words(param_1,param_2,puVar11,num);
      bn_sub_words(param_1 + num,param_3,puVar13,num);
      bVar1 = true;
      goto joined_r0x080f707c;
    }
    if (iVar3 == 4) {
      bn_sub_words(param_1,param_2,puVar11,num);
      bn_sub_words(param_1 + num,puVar13,param_3,num);
      bVar1 = false;
      goto joined_r0x080f707c;
    }
  }
  bVar1 = false;
joined_r0x080f707c:
  if (num == 8) {
    local_2c = param_1 + 8;
    bn_mul_comba8(param_6,param_1,local_2c);
    bn_mul_comba8(param_1,puVar11,puVar13);
  }
  else {
    bn_mul_recursive_constprop_0(num,param_6 + param_5);
    bn_mul_recursive_constprop_0(num,param_6 + param_5);
  }
  puVar13 = param_6 + param_5;
  local_2c = param_1 + num;
  iVar2 = param_5 + num;
  puVar11 = param_1;
  if (param_4 != (ulong *)0x0) {
    bn_add_words(param_6 + iVar2,param_1,param_4,num);
    puVar11 = param_6 + iVar2;
  }
  local_28 = param_6 + iVar2;
  if (bVar1) {
    bn_sub_words(puVar13,puVar11,param_6,num);
  }
  else {
    bn_add_words(puVar13,puVar11,param_6,num);
  }
  if (param_4 == (ulong *)0x0) {
    if (0 < num) {
      puVar11 = puVar13;
      do {
        puVar12 = puVar11 + 1;
        puVar11[iVar2 - param_5] = -*puVar11;
        puVar11 = puVar12;
      } while (puVar12 != param_6 + param_5 + num);
    }
    uVar4 = 0;
    puVar11 = local_28;
  }
  else {
    bn_sub_words(local_28,param_4 + num,puVar13,num);
    uVar4 = bn_add_words(puVar13,local_28,param_4,num);
    puVar11 = puVar13;
  }
  uVar5 = bn_add_words(puVar13,puVar11,param_1,num);
  if (bVar1) {
    uVar6 = bn_sub_words(puVar13,puVar13,param_6,num);
    uVar6 = -uVar6;
    uVar7 = bn_add_words(param_1,param_1,local_28,num);
    uVar8 = bn_add_words(param_1,param_1,local_2c,num);
    uVar9 = bn_sub_words(param_1,param_1,param_6 + num,num);
    uVar14 = (uVar7 + uVar8) - uVar9;
  }
  else {
    uVar6 = bn_add_words(puVar13,puVar13,param_6,num);
    uVar7 = bn_add_words(param_1,param_1,local_28,num);
    uVar8 = bn_add_words(param_1,param_1,local_2c,num);
    uVar9 = bn_add_words(param_1,param_1,param_6 + num,num);
    uVar14 = uVar7 + uVar8 + uVar9;
  }
  uVar15 = uVar4 + uVar5 + uVar6;
  if (uVar15 != 0) {
    if ((int)uVar15 < 1) {
      uVar15 = -uVar15;
      do {
        uVar10 = *param_1;
        *param_1 = uVar10 - uVar15;
        param_1 = param_1 + 1;
        bVar1 = uVar10 < uVar15;
        uVar15 = (uint)(uVar10 < uVar15);
      } while (bVar1);
    }
    else {
      do {
        uVar10 = *param_1 + uVar15;
        *param_1 = uVar10;
        param_1 = param_1 + 1;
        bVar1 = uVar10 < uVar15;
        uVar15 = (uint)(uVar10 < uVar15);
      } while (bVar1);
    }
  }
  if (uVar14 != 0) {
    if ((int)uVar14 < 1) {
      uVar14 = -uVar14;
      do {
        uVar15 = *local_2c;
        *local_2c = uVar15 - uVar14;
        local_2c = local_2c + 1;
        bVar1 = uVar15 < uVar14;
        uVar14 = (uint)(uVar15 < uVar14);
      } while (bVar1);
      return;
    }
    do {
      uVar15 = *local_2c + uVar14;
      *local_2c = uVar15;
      local_2c = local_2c + 1;
      bVar1 = uVar15 < uVar14;
      uVar14 = (uint)(uVar15 < uVar14);
    } while (bVar1);
  }
  return;
}

