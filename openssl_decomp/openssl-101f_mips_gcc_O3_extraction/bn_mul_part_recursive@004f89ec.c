
void bn_mul_part_recursive
               (ulong *param_1,int param_2,int param_3,int param_4,uint param_5,uint param_6,
               ulong *param_7)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulong *puVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  int iVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  ulong *rp;
  ulong *local_3c;
  
  if (param_4 < 8) {
    bn_mul_normal(param_1,param_2,param_4 + param_5,param_3);
    return;
  }
  iVar14 = param_4 - param_5;
  iVar2 = param_2 + param_4 * 4;
  iVar3 = bn_cmp_part_words(param_2,iVar2,param_5,iVar14);
  iVar9 = param_3 + param_4 * 4;
  iVar13 = param_6 - param_4;
  iVar4 = bn_cmp_part_words(iVar9,param_3,param_6,iVar13);
  switch(iVar3 * 3 + iVar4) {
  case 3:
  case 4:
    bn_sub_part_words(param_7,param_2,iVar2,param_5,iVar14);
    bn_sub_part_words(param_7 + param_4,iVar9,param_3,param_6,iVar13);
    bVar1 = false;
    break;
  default:
    bVar1 = false;
    break;
  case -4:
    bn_sub_part_words(param_7,iVar2,param_2,param_5,param_5 - param_4);
    bn_sub_part_words(param_7 + param_4,param_3,iVar9,param_6,param_4 - param_6);
    bVar1 = false;
    if (param_4 != 8) goto LAB_004f8b80;
    goto LAB_004f8dc8;
  case -3:
  case -2:
    bn_sub_part_words(param_7,iVar2,param_2,param_5,param_5 - param_4);
    iVar3 = iVar9;
    iVar4 = param_3;
    goto LAB_004f8b5c;
  case -1:
  case 0:
  case 1:
  case 2:
    bn_sub_part_words(param_7,param_2,iVar2,param_5,iVar14);
    iVar13 = param_4 - param_6;
    iVar3 = param_3;
    iVar4 = iVar9;
LAB_004f8b5c:
    bn_sub_part_words(param_7 + param_4,iVar3,iVar4,param_6,iVar13);
    bVar1 = true;
  }
  if (param_4 == 8) {
LAB_004f8dc8:
    rp = param_7 + 0x10;
    bn_mul_comba8(rp,param_7,param_7 + param_4);
    local_3c = param_1 + 0x10;
    bn_mul_comba8(param_1,param_2,param_3);
    bn_mul_normal(local_3c,iVar2,param_5,iVar9,param_6);
  }
  else {
LAB_004f8b80:
    puVar5 = param_7 + param_4 * 4;
    rp = param_7 + param_4 * 2;
    bn_mul_recursive_constprop_0(rp,param_7,param_7 + param_4,param_4,puVar5);
    uVar12 = param_4 >> 1;
    bn_mul_recursive_constprop_0(param_1,param_2,param_3,param_4,puVar5);
    if ((int)param_6 < (int)param_5) {
      iVar3 = param_5 - uVar12;
    }
    else {
      iVar3 = param_6 - uVar12;
    }
    if (iVar3 == 0) {
      local_3c = param_1 + param_4 * 2;
      bn_mul_recursive(local_3c,iVar2,iVar9,uVar12,param_5 - uVar12,param_6 - uVar12,puVar5);
      (*(code *)PTR_memset_006aab00)
                (param_1 + param_4 * 2 + uVar12 * 2,0,(param_4 * 2 + uVar12 * -2) * 4);
      goto LAB_004f8c58;
    }
    if (iVar3 < 1) {
      local_3c = param_1 + param_4 * 2;
      (*(code *)PTR_memset_006aab00)(local_3c,0,param_4 * 8);
      uVar10 = uVar12 >> 0x1f;
      if (((int)param_5 < 0x10) && (uVar10 = uVar12 >> 0x1f, (int)param_6 < 0x10)) {
        bn_mul_normal(local_3c,iVar2,param_5,iVar9,param_6);
      }
      else {
        do {
          uVar12 = (int)(uVar10 + uVar12) >> 1;
          if (((int)uVar12 < (int)param_5) || ((int)uVar12 < (int)param_6)) {
            bn_mul_part_recursive
                      (local_3c,iVar2,iVar9,uVar12,param_5 - uVar12,param_6 - uVar12,puVar5);
            goto LAB_004f8c58;
          }
        } while ((param_5 != uVar12) && (uVar10 = uVar12 >> 0x1f, param_6 != uVar12));
        bn_mul_recursive(local_3c,iVar2,iVar9,uVar12,param_5 - uVar12,param_6 - uVar12,puVar5);
      }
      goto LAB_004f8c58;
    }
    local_3c = param_1 + param_4 * 2;
    bn_mul_part_recursive(local_3c,iVar2,iVar9,uVar12,param_5 - uVar12,param_6 - uVar12,puVar5);
  }
  (*(code *)PTR_memset_006aab00)
            (param_1 + param_4 * 2 + param_5 + param_6,0,((param_4 * 2 - param_5) - param_6) * 4);
LAB_004f8c58:
  iVar2 = param_4 * 2;
  uVar6 = bn_add_words(param_7,param_1,local_3c,iVar2);
  if (bVar1) {
    uVar7 = bn_sub_words(rp,param_7,rp,iVar2);
    uVar7 = -uVar7;
  }
  else {
    uVar7 = bn_add_words(rp,rp,param_7,iVar2);
  }
  uVar8 = bn_add_words(param_1 + param_4,param_1 + param_4,rp,iVar2);
  uVar12 = uVar8 + uVar6 + uVar7;
  if (uVar12 != 0) {
    puVar11 = param_1 + param_4 * 3;
    uVar10 = *puVar11;
    *puVar11 = uVar12 + uVar10;
    if (uVar12 + uVar10 < uVar12) {
      do {
        puVar11 = puVar11 + 1;
        uVar12 = *puVar11;
        *puVar11 = uVar12 + 1;
      } while (uVar12 + 1 == 0);
    }
  }
  return;
}

