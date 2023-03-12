
void bn_mul_recursive(ulong *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                     ulong *param_7)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  ulong *puVar13;
  int iVar14;
  uint uVar15;
  
  uVar15 = count_leading_zeroes(param_5);
  if (param_4 == 8 && param_5 == 0) {
    if (param_6 == 0) {
      bn_mul_comba8();
      return;
    }
  }
  else if (0xf < param_4) {
    iVar1 = param_4 >> 1;
    iVar2 = -param_5;
    iVar9 = param_6 + iVar1;
    iVar11 = iVar1 * 4 + param_2;
    iVar14 = iVar1 + param_5;
    iVar10 = param_3 + iVar1 * 4;
    iVar4 = bn_cmp_part_words(param_2,iVar11,iVar14,iVar2);
    iVar5 = bn_cmp_part_words(iVar10,param_3,iVar9,param_6);
    switch(iVar5 + iVar4 * 3) {
    case 2:
      bVar3 = true;
      bn_sub_part_words(param_7,param_2,iVar11,iVar14,iVar2);
      bn_sub_part_words(param_7 + iVar1,param_3,iVar10,iVar9,-param_6);
      bVar12 = false;
      break;
    case 4:
      bn_sub_part_words(param_7,param_2,iVar11,iVar14,iVar2);
      bn_sub_part_words(param_7 + iVar1,iVar10,param_3,iVar9,param_6);
      bVar12 = false;
      bVar3 = false;
      break;
    default:
      bVar12 = false;
      bVar3 = false;
      break;
    case -4:
      bn_sub_part_words(param_7,iVar11,param_2,iVar14,param_5);
      bn_sub_part_words(param_7 + iVar1,param_3,iVar10,iVar9,-param_6);
      bVar12 = false;
      bVar3 = false;
      break;
    case -3:
    case -1:
    case 0:
    case 1:
    case 3:
      bVar12 = true;
      bVar3 = false;
      break;
    case -2:
      bVar3 = true;
      bn_sub_part_words(param_7,iVar11,param_2,iVar14,param_5);
      bn_sub_part_words(param_7 + iVar1,iVar10,param_3,iVar9,param_6);
      bVar12 = false;
    }
    if (iVar1 == 8) {
      uVar15 = uVar15 >> 5 & 1;
    }
    else {
      uVar15 = 0;
    }
    if ((uVar15 == 0) || (param_6 != 0)) {
      puVar13 = param_7 + param_4 * 2;
      if (bVar12) {
        memset(param_7 + param_4,0,param_4 * 4);
      }
      else {
        bn_mul_recursive_constprop_0(param_7 + param_4,param_7,param_7 + iVar1,iVar1,puVar13);
      }
      bn_mul_recursive_constprop_0(param_1,param_2,param_3,iVar1,puVar13);
      bn_mul_recursive(param_1 + param_4,iVar11,iVar10,iVar1,param_5,param_6,puVar13);
    }
    else {
      if (bVar12) {
        memset(param_7 + param_4,0,0x40);
      }
      else {
        bn_mul_comba8(param_7 + param_4,param_7,param_7 + iVar1);
      }
      bn_mul_comba8(param_1,param_2,param_3);
      bn_mul_comba8(param_1 + param_4,iVar11,iVar10);
    }
    puVar13 = param_7 + param_4;
    uVar6 = bn_add_words(param_7,param_1,param_1 + param_4,param_4);
    if (bVar3) {
      uVar7 = bn_sub_words(puVar13,param_7,puVar13,param_4);
      uVar7 = -uVar7;
    }
    else {
      uVar7 = bn_add_words(puVar13,puVar13,param_7,param_4);
    }
    uVar8 = bn_add_words(param_1 + iVar1,param_1 + iVar1,puVar13,param_4);
    uVar15 = uVar8 + uVar6 + uVar7;
    if (uVar15 == 0) {
      return;
    }
    param_4 = param_4 + iVar1;
    uVar6 = param_1[param_4];
    puVar13 = param_1 + param_4;
    param_1[param_4] = uVar6 + uVar15;
    if (uVar15 <= uVar6 + uVar15) {
      return;
    }
    do {
      uVar6 = puVar13[1];
      puVar13 = puVar13 + 1;
      *puVar13 = uVar6 + 1;
    } while (uVar6 + 1 == 0);
    return;
  }
  bn_mul_normal(param_1,param_2,param_4 + param_5,param_3,param_6 + param_4);
  if (-1 < param_5 + param_6) {
    return;
  }
  (*(code *)PTR_memset_0018a15c)
            (param_1 + param_4 + param_5 + param_4 + param_6,0,(param_5 + param_6) * -4);
  return;
}

