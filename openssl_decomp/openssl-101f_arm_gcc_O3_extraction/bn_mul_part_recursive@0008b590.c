
void bn_mul_part_recursive
               (ulong *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
               ulong *param_7)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  int iVar8;
  ulong *puVar9;
  int iVar10;
  int iVar11;
  ulong *bp;
  int iVar12;
  ulong *local_40;
  
  if (param_4 < 8) {
    bn_mul_normal(param_1,param_2,param_4 + param_5,param_3);
    return;
  }
  iVar12 = param_4 - param_5;
  iVar8 = param_2 + param_4 * 4;
  iVar11 = param_6 - param_4;
  iVar10 = param_4 * 4 + param_3;
  iVar2 = bn_cmp_part_words(param_2,iVar8,param_5,iVar12);
  iVar3 = bn_cmp_part_words(iVar10,param_3,param_6,iVar11);
  switch(iVar3 + iVar2 * 3) {
  case 3:
  case 4:
    bn_sub_part_words(param_7,param_2,iVar8,param_5,iVar12);
    bn_sub_part_words(param_7 + param_4,iVar10,param_3,param_6,iVar11);
    bVar1 = false;
    break;
  default:
    bVar1 = false;
    break;
  case -4:
    bVar1 = false;
    bn_sub_part_words(param_7,iVar8,param_2,param_5,param_5 - param_4);
    bn_sub_part_words(param_7 + param_4,param_3,iVar10,param_6,param_4 - param_6);
    if (param_4 != 8) goto LAB_0008b64c;
    goto LAB_0008b766;
  case -3:
  case -2:
    bn_sub_part_words(param_7,iVar8,param_2,param_5,param_5 - param_4);
    bn_sub_part_words(param_7 + param_4,iVar10,param_3,param_6,iVar11);
    bVar1 = true;
    break;
  case -1:
  case 0:
  case 1:
  case 2:
    bn_sub_part_words(param_7,param_2,iVar8,param_5,iVar12);
    bVar1 = true;
    bn_sub_part_words(param_7 + param_4,param_3,iVar10,param_6,param_4 - param_6);
  }
  if (param_4 == 8) {
LAB_0008b766:
    local_40 = param_7 + 0x10;
    bp = param_1 + 0x10;
    bn_mul_comba8(local_40,param_7,param_7 + param_4);
    bn_mul_comba8(param_1,param_2,param_3);
    bn_mul_normal(bp,iVar8,param_5,iVar10,param_6);
    memset(param_1 + param_5 + param_4 * 2 + param_6,0,((param_4 * 2 - param_5) - param_6) * 4);
  }
  else {
LAB_0008b64c:
    iVar3 = param_4 * 2;
    local_40 = param_7 + param_4 * 2;
    puVar9 = param_7 + param_4 * 4;
    bn_mul_recursive_constprop_0(local_40,param_7,param_7 + param_4,param_4,puVar9);
    iVar2 = param_4 >> 1;
    bn_mul_recursive_constprop_0(param_1,param_2,param_3,param_4,puVar9);
    if (param_6 < param_5) {
      iVar11 = param_5 - iVar2;
    }
    else {
      iVar11 = param_6 - iVar2;
    }
    bp = param_1 + param_4 * 2;
    if (iVar11 == 0) {
      bn_mul_recursive(bp,iVar8,iVar10,iVar2,param_5 - iVar2,param_6 - iVar2,puVar9);
      iVar3 = iVar3 + iVar2 * 2;
      memset(param_1 + iVar3,0,(iVar3 + iVar2 * -4) * 4);
    }
    else if (iVar11 < 1) {
      memset(bp,0,param_4 * 8);
      iVar3 = param_5;
      if (param_5 < 0x10) {
        iVar3 = param_6;
      }
      if (iVar3 < 0x10) {
        bn_mul_normal(bp,iVar8,param_5,iVar10,param_6);
      }
      else {
        do {
          iVar2 = iVar2 / 2;
          iVar3 = param_6;
          if (param_6 <= iVar2) {
            iVar3 = param_5;
          }
          if (iVar2 < iVar3) {
            bn_mul_part_recursive(bp,iVar8,iVar10,iVar2,param_5 - iVar2,param_6 - iVar2,puVar9);
            goto LAB_0008b6d0;
          }
        } while (iVar2 != param_6 && iVar2 != param_5);
        bn_mul_recursive(bp,iVar8,iVar10,iVar2,param_5 - iVar2,param_6 - iVar2,puVar9);
      }
    }
    else {
      bn_mul_part_recursive(bp,iVar8,iVar10,iVar2,param_5 - iVar2,param_6 - iVar2,puVar9);
      memset(param_1 + param_5 + iVar3 + param_6,0,((iVar3 - param_5) - param_6) * 4);
    }
  }
LAB_0008b6d0:
  iVar2 = param_4 * 2;
  uVar4 = bn_add_words(param_7,param_1,bp,iVar2);
  if (bVar1) {
    uVar5 = bn_sub_words(local_40,param_7,local_40,iVar2);
    uVar5 = -uVar5;
  }
  else {
    uVar5 = bn_add_words(local_40,local_40,param_7,iVar2);
  }
  uVar6 = bn_add_words(param_1 + param_4,param_1 + param_4,local_40,iVar2);
  uVar7 = uVar6 + uVar4 + uVar5;
  if (uVar7 != 0) {
    uVar4 = param_1[param_4 * 3];
    puVar9 = param_1 + param_4 * 3;
    param_1[param_4 * 3] = uVar4 + uVar7;
    if (uVar4 + uVar7 < uVar7) {
      do {
        uVar4 = puVar9[1];
        puVar9 = puVar9 + 1;
        *puVar9 = uVar4 + 1;
      } while (uVar4 + 1 == 0);
    }
  }
  return;
}

