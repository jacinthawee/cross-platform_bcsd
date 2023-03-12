
void bn_mul_recursive(ulong *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                     ulong *param_7)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint *puVar14;
  int iVar15;
  int iVar16;
  ulong *puVar17;
  ulong *local_40;
  
  if (param_4 == 8) {
    if ((param_5 == 0) && (param_6 == 0)) {
      bn_mul_comba8();
      return;
    }
LAB_004f5be4:
    bn_mul_normal(param_1,param_2,param_4 + param_5,param_3,param_4 + param_6);
    if (-1 < param_5 + param_6) {
      return;
    }
                    /* WARNING: Could not recover jumptable at 0x004f5fb4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_memset_006a99f4)
              (param_1 + param_4 + param_4 + param_5 + param_6,0,(param_5 + param_6) * -4);
    return;
  }
  iVar15 = param_4 >> 1;
  if (param_4 < 0x10) goto LAB_004f5be4;
  iVar12 = -param_5;
  iVar13 = iVar15 + param_5;
  iVar3 = param_2 + iVar15 * 4;
  iVar4 = bn_cmp_part_words(param_2,iVar3,iVar13,iVar12);
  iVar10 = param_3 + iVar15 * 4;
  iVar16 = iVar15 + param_6;
  iVar5 = bn_cmp_part_words(iVar10,param_3,iVar16,param_6);
  switch(iVar4 * 3 + iVar5) {
  case 2:
    bn_sub_part_words(param_7,param_2,iVar3,iVar13,iVar12);
    iVar12 = param_3;
    iVar4 = iVar10;
    iVar5 = -param_6;
LAB_004f5edc:
    bn_sub_part_words(param_7 + iVar15,iVar12,iVar4,iVar16,iVar5);
    bVar1 = false;
    bVar2 = true;
    goto joined_r0x004f5c48;
  case 4:
    bn_sub_part_words(param_7,param_2,iVar3,iVar13,iVar12);
    iVar4 = iVar10;
    iVar5 = param_3;
    iVar12 = param_6;
    break;
  default:
    bVar1 = false;
    bVar2 = false;
    goto joined_r0x004f5c48;
  case -4:
    bn_sub_part_words(param_7,iVar3,param_2,iVar13,param_5);
    iVar12 = -param_6;
    iVar4 = param_3;
    iVar5 = iVar10;
    break;
  case -3:
  case -1:
  case 0:
  case 1:
  case 3:
    bVar1 = true;
    bVar2 = false;
    goto joined_r0x004f5c48;
  case -2:
    bn_sub_part_words(param_7,iVar3,param_2,iVar13,param_5);
    iVar12 = iVar10;
    iVar4 = param_3;
    iVar5 = param_6;
    goto LAB_004f5edc;
  }
  bn_sub_part_words(param_7 + iVar15,iVar4,iVar5,iVar16,iVar12);
  bVar1 = false;
  bVar2 = false;
joined_r0x004f5c48:
  if (((iVar15 == 8) && (param_5 == 0)) && (param_6 == 0)) {
    if (bVar1) {
      (*(code *)PTR_memset_006a99f4)(param_7 + param_4,0,0x40);
    }
    else {
      bn_mul_comba8(param_7 + param_4,param_7,param_7 + 8);
    }
    bn_mul_comba8(param_1,param_2,param_3);
    bn_mul_comba8(param_1 + param_4,iVar3,iVar10);
  }
  else {
    puVar17 = param_7 + param_4 * 2;
    if (bVar1) {
      (*(code *)PTR_memset_006a99f4)(param_7 + param_4,0,param_4 * 4);
    }
    else {
      bn_mul_recursive_constprop_0(param_7 + param_4,param_7,param_7 + iVar15,iVar15,puVar17);
    }
    bn_mul_recursive_constprop_0(param_1,param_2,param_3,iVar15,puVar17);
    bn_mul_recursive(param_1 + param_4,iVar3,iVar10,iVar15,param_5,param_6,puVar17);
  }
  local_40 = param_1 + param_4;
  puVar17 = param_7 + param_4;
  uVar6 = bn_add_words(param_7,param_1,local_40,param_4);
  if (bVar2) {
    uVar7 = bn_sub_words(puVar17,param_7,puVar17,param_4);
    uVar7 = -uVar7;
  }
  else {
    uVar7 = bn_add_words(puVar17,puVar17,param_7,param_4);
  }
  uVar8 = bn_add_words(param_1 + iVar15,param_1 + iVar15,puVar17,param_4);
  uVar9 = uVar8 + uVar6 + uVar7;
  if (uVar9 != 0) {
    puVar14 = param_1 + param_4 + iVar15;
    uVar11 = *puVar14;
    *puVar14 = uVar9 + uVar11;
    if (uVar9 + uVar11 < uVar9) {
      do {
        uVar9 = puVar14[1] + 1;
        puVar14[1] = uVar9;
        if (uVar9 != 0) {
          return;
        }
        puVar14 = puVar14 + 2;
        uVar9 = *puVar14;
        *puVar14 = uVar9 + 1;
      } while (uVar9 + 1 == 0);
    }
  }
  return;
}

