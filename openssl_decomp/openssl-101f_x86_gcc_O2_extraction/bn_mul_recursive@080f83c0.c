
void bn_mul_recursive(ulong *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                     ulong *param_7)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  int iVar12;
  uint *puVar13;
  ulong *puVar14;
  undefined4 *puVar15;
  uint uVar16;
  bool bVar17;
  byte bVar18;
  int iVar19;
  ulong *local_4c;
  
  bVar18 = 0;
  bVar17 = param_5 == 0;
  if ((param_4 == 8) && (bVar17)) {
    if (param_6 == 0) {
      bn_mul_comba8();
      return;
    }
LAB_080f840e:
    bn_mul_normal(param_1,param_2,param_4 + param_5,param_3,param_4 + param_6);
    if (-1 < param_5 + param_6) {
      return;
    }
    memset(param_1 + param_4 + param_4 + param_5 + param_6,0,(param_5 + param_6) * -4);
    return;
  }
  if (param_4 < 0x10) goto LAB_080f840e;
  iVar4 = param_4 >> 1;
  iVar12 = -param_5;
  iVar19 = iVar4 + param_5;
  iVar1 = iVar4 + param_6;
  iVar5 = iVar4 * 4 + param_2;
  iVar6 = bn_cmp_part_words(param_2,iVar5,iVar19,iVar12);
  iVar7 = iVar4 * 4 + param_3;
  iVar8 = bn_cmp_part_words(iVar7,param_3,iVar1,param_6);
  switch(iVar8 + 4 + iVar6 * 3) {
  case 0:
    bn_sub_part_words(param_7,iVar5,param_2,iVar19,param_5);
    iVar8 = -param_6;
    iVar19 = param_3;
    iVar6 = iVar7;
    break;
  case 1:
  case 3:
  case 4:
  case 5:
  case 7:
    if ((!bVar17 || iVar4 != 8) || (param_6 != 0)) {
      local_4c = param_7 + param_4 * 2;
      memset(param_7 + param_4,0,param_4 * 4);
      bVar3 = false;
      goto LAB_080f85f8;
    }
    puVar14 = param_7 + param_4;
    *puVar14 = 0;
    puVar14[0xf] = 0;
    puVar15 = (undefined4 *)((uint)(puVar14 + 1) & 0xfffffffc);
    for (uVar16 = (uint)((int)puVar14 +
                        (0x40 - (int)(undefined4 *)((uint)(puVar14 + 1) & 0xfffffffc))) >> 2;
        uVar16 != 0; uVar16 = uVar16 - 1) {
      *puVar15 = 0;
      puVar15 = puVar15 + (uint)bVar18 * -2 + 1;
    }
    bVar3 = false;
    goto LAB_080f8510;
  case 2:
    bn_sub_part_words(param_7,iVar5,param_2,iVar19,param_5);
    iVar19 = iVar7;
    iVar6 = param_3;
    iVar8 = param_6;
    goto LAB_080f858a;
  case 6:
    bn_sub_part_words(param_7,param_2,iVar5,iVar19,iVar12);
    iVar19 = param_3;
    iVar6 = iVar7;
    iVar8 = -param_6;
LAB_080f858a:
    bn_sub_part_words(param_7 + iVar4,iVar19,iVar6,iVar1,iVar8);
    bVar3 = true;
    goto LAB_080f85b0;
  case 8:
    bn_sub_part_words(param_7,param_2,iVar5,iVar19,iVar12);
    iVar19 = iVar7;
    iVar6 = param_3;
    iVar8 = param_6;
    break;
  default:
    bVar3 = false;
    goto LAB_080f85b0;
  }
  bn_sub_part_words(param_7 + iVar4,iVar19,iVar6,iVar1,iVar8);
  bVar3 = false;
LAB_080f85b0:
  if ((bVar17 && iVar4 == 8) && (param_6 == 0)) {
    bn_mul_comba8(param_7 + param_4,param_7,param_7 + iVar4);
LAB_080f8510:
    bn_mul_comba8(param_1,param_2,param_3);
    bn_mul_comba8(param_1 + param_4,iVar5,iVar7);
  }
  else {
    local_4c = param_7 + param_4 * 2;
    bn_mul_recursive_constprop_0(iVar4,local_4c);
LAB_080f85f8:
    bn_mul_recursive_constprop_0(iVar4,local_4c);
    bn_mul_recursive(param_1 + param_4,iVar5,iVar7,iVar4,param_5,param_6,local_4c);
  }
  puVar14 = param_7 + param_4;
  uVar9 = bn_add_words(param_7,param_1,param_1 + param_4,param_4);
  if (bVar3) {
    uVar10 = bn_sub_words(puVar14,param_7,puVar14,param_4);
    uVar10 = -uVar10;
  }
  else {
    uVar10 = bn_add_words(puVar14,puVar14,param_7,param_4);
  }
  uVar11 = bn_add_words(param_1 + iVar4,param_1 + iVar4,puVar14,param_4);
  uVar16 = uVar9 + uVar10 + uVar11;
  if (uVar16 != 0) {
    puVar13 = param_1 + param_4 + iVar4;
    uVar2 = *puVar13;
    *puVar13 = uVar2 + uVar16;
    if (uVar2 + uVar16 < uVar16) {
      do {
        puVar13 = puVar13 + 1;
        *puVar13 = *puVar13 + 1;
      } while (*puVar13 == 0);
      return;
    }
  }
  return;
}

