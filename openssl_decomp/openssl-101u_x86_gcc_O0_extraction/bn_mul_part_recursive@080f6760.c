
void bn_mul_part_recursive
               (ulong *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
               ulong *param_7)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  size_t __n;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  int iVar10;
  int iVar11;
  ulong *puVar12;
  uint *puVar13;
  uint uVar14;
  ulong *local_3c;
  int local_34;
  ulong *local_30;
  
  if (param_4 < 8) {
    bn_mul_normal();
    return;
  }
  iVar10 = param_4 - param_5;
  iVar3 = param_4 * 4 + param_2;
  iVar4 = bn_cmp_part_words(param_2,iVar3,param_5,iVar10);
  iVar11 = param_6 - param_4;
  iVar5 = param_4 * 4 + param_3;
  iVar6 = bn_cmp_part_words(iVar5,param_3,param_6,iVar11);
  switch(iVar6 + 4 + iVar4 * 3) {
  case 0:
    bn_sub_part_words(param_7,iVar3,param_2,param_5,param_5 - param_4);
    iVar11 = param_4 - param_6;
    iVar4 = param_3;
    iVar6 = iVar5;
    break;
  case 1:
  case 2:
    bn_sub_part_words(param_7,iVar3,param_2,param_5,param_5 - param_4);
    iVar4 = iVar5;
    iVar6 = param_3;
    goto LAB_080f6854;
  case 3:
  case 4:
  case 5:
  case 6:
    bn_sub_part_words(param_7,param_2,iVar3,param_5,iVar10);
    iVar11 = param_4 - param_6;
    iVar4 = param_3;
    iVar6 = iVar5;
LAB_080f6854:
    bn_sub_part_words(param_7 + param_4,iVar4,iVar6,param_6,iVar11);
    bVar2 = true;
    goto joined_r0x080f6877;
  case 7:
  case 8:
    bn_sub_part_words(param_7,param_2,iVar3,param_5,iVar10);
    iVar4 = iVar5;
    iVar6 = param_3;
    break;
  default:
    bVar2 = false;
    goto joined_r0x080f6877;
  }
  bn_sub_part_words(param_7 + param_4,iVar4,iVar6,param_6,iVar11);
  bVar2 = false;
joined_r0x080f6877:
  if (param_4 == 8) {
    local_30 = param_7 + 0x10;
    bn_mul_comba8(local_30,param_7,param_7 + 8);
    bn_mul_comba8(param_1,param_2,param_3);
    local_3c = param_1 + 0x10;
    bn_mul_normal(local_3c,iVar3,param_5,iVar5,param_6);
    __n = ((0x10 - param_5) - param_6) * 4;
    puVar12 = param_1 + param_5 + 0x10 + param_6;
  }
  else {
    puVar12 = param_7 + param_4 * 4;
    local_30 = param_7 + param_4 * 2;
    bn_mul_recursive_constprop_0(param_4,puVar12);
    iVar11 = param_4 >> 1;
    bn_mul_recursive_constprop_0(param_4,puVar12);
    iVar6 = param_5 - iVar11;
    iVar10 = param_6 - iVar11;
    iVar4 = iVar6;
    if (param_5 <= param_6) {
      iVar4 = iVar10;
    }
    if (iVar4 == 0) {
      local_3c = param_1 + param_4 * 2;
      bn_mul_recursive(local_3c,iVar3,iVar5,iVar11,iVar6,iVar10,puVar12);
      __n = (param_4 * 2 + iVar11 * -2) * 4;
      puVar12 = param_1 + iVar11 * 2 + param_4 * 2;
    }
    else {
      if (iVar4 < 1) {
        local_3c = param_1 + param_4 * 2;
        memset(local_3c,0,param_4 * 8);
        if ((param_5 < 0x10) && (param_6 < 0x10)) {
          bn_mul_normal(local_3c,iVar3,param_5,iVar5,param_6);
        }
        else {
          do {
            iVar11 = iVar11 / 2;
            if ((iVar11 < param_5) || (iVar11 < param_6)) {
              bn_mul_part_recursive
                        (local_3c,iVar3,iVar5,iVar11,param_5 - iVar11,param_6 - iVar11,puVar12);
              goto LAB_080f693a;
            }
          } while ((param_5 != iVar11) && (param_6 != iVar11));
          bn_mul_recursive(local_3c,iVar3,iVar5,iVar11,param_5 - iVar11,param_6 - iVar11,puVar12);
        }
        goto LAB_080f693a;
      }
      local_3c = param_1 + param_4 * 2;
      bn_mul_part_recursive(local_3c,iVar3,iVar5,iVar11,iVar6,iVar10,puVar12);
      __n = ((param_4 * 2 - param_5) - param_6) * 4;
      puVar12 = param_1 + param_5 + param_4 * 2 + param_6;
    }
  }
  memset(puVar12,0,__n);
LAB_080f693a:
  local_34 = param_4 * 2;
  uVar7 = bn_add_words(param_7,param_1,local_3c,local_34);
  if (bVar2) {
    uVar8 = bn_sub_words(local_30,param_7,local_30,local_34);
    uVar8 = -uVar8;
  }
  else {
    uVar8 = bn_add_words(local_30,local_30,param_7,local_34);
  }
  uVar9 = bn_add_words(param_1 + param_4,param_1 + param_4,local_30,local_34);
  uVar14 = uVar7 + uVar8 + uVar9;
  if (uVar14 != 0) {
    puVar13 = param_1 + param_4 * 3;
    uVar1 = *puVar13;
    *puVar13 = uVar1 + uVar14;
    if (uVar1 + uVar14 < uVar14) {
      do {
        puVar13 = puVar13 + 1;
        *puVar13 = *puVar13 + 1;
      } while (*puVar13 == 0);
    }
  }
  return;
}

