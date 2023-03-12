
void bn_mul_recursive_constprop_0
               (ulong *param_1,ulong *param_2,ulong *param_3,int param_4,ulong *param_5)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  uint uVar8;
  uint uVar9;
  ulong *ap;
  uint *puVar10;
  ulong *puVar11;
  ulong *ap_00;
  int num;
  ulong *ap_01;
  int num_00;
  ulong *puVar12;
  code *pcVar13;
  ulong *ap_02;
  ulong *local_48;
  ulong *local_40;
  ulong *local_34;
  ulong *local_2c;
  
  if (param_4 == 8) {
    bn_mul_comba8();
    return;
  }
  if (param_4 < 0x10) {
    bn_mul_normal(param_1,param_2,param_4,param_3);
    return;
  }
  num = param_4 >> 1;
  ap_02 = param_2 + num;
  iVar3 = bn_cmp_part_words(param_2,ap_02,num,0);
  puVar12 = param_3 + num;
  iVar4 = bn_cmp_part_words(puVar12,param_3,num,0);
  switch(iVar3 * 3 + iVar4) {
  case 2:
    bn_sub_part_words(param_5,param_2,ap_02,num,0);
    bn_sub_part_words(param_5 + num,param_3,puVar12,num,0);
    bVar1 = true;
    break;
  case 4:
    bn_sub_part_words(param_5,param_2,ap_02,num,0);
    bn_sub_words(param_5 + num,puVar12,param_3,num);
    bVar1 = false;
    break;
  default:
    bVar1 = false;
    break;
  case -4:
    bn_sub_words(param_5,ap_02,param_2,num);
    bn_sub_part_words(param_5 + num,param_3,puVar12,num,0);
    bVar1 = false;
    break;
  case -3:
  case -1:
  case 0:
  case 1:
  case 3:
    if (num == 8) {
      (*(code *)PTR_memset_006aab00)(param_5 + param_4,0,0x40);
      bVar1 = false;
      goto LAB_004f8024;
    }
    local_48 = param_5 + param_4 * 2;
    (*(code *)PTR_memset_006aab00)(param_5 + param_4,0,param_4 * 4);
    bVar1 = false;
    goto LAB_004f7ccc;
  case -2:
    bn_sub_words(param_5,ap_02,param_2,num);
    bn_sub_words(param_5 + num,puVar12,param_3,num);
    bVar1 = true;
  }
  local_40 = param_5 + num;
  if (num == 8) {
    bn_mul_comba8(param_5 + param_4,param_5,local_40);
LAB_004f8024:
    bn_mul_comba8(param_1,param_2,param_3);
    bn_mul_comba8(param_1 + param_4,ap_02,puVar12);
    goto LAB_004f7d18;
  }
  local_48 = param_5 + param_4 * 2;
  bn_mul_recursive_constprop_0(param_5 + param_4,param_5,local_40,num,local_48);
LAB_004f7ccc:
  bn_mul_recursive_constprop_0(param_1,param_2,param_3,num,local_48);
  ap_01 = param_1 + param_4;
  if (num < 0x10) {
    bn_mul_normal(ap_01,ap_02,num,puVar12,num);
    goto LAB_004f7d18;
  }
  num_00 = param_4 >> 2;
  ap_00 = ap_02 + num_00;
  iVar3 = bn_cmp_part_words(ap_02,ap_00,num_00,0);
  ap = puVar12 + num_00;
  iVar4 = bn_cmp_part_words(ap,puVar12,num_00,0);
  switch(iVar3 * 3 + iVar4) {
  case 2:
    bn_sub_part_words(local_48,ap_02,ap_00,num_00,0);
    bn_sub_part_words(local_48 + num_00,puVar12,ap,num_00,0);
    bVar2 = true;
    break;
  case 4:
    bn_sub_part_words(local_48,ap_02,ap_00,num_00,0);
    bn_sub_words(local_48 + num_00,ap,puVar12,num_00);
    bVar2 = false;
    break;
  default:
    bVar2 = false;
    break;
  case -4:
    bn_sub_words(local_48,ap_00,ap_02,num_00);
    bn_sub_part_words(local_48 + num_00,puVar12,ap,num_00,0);
    bVar2 = false;
    break;
  case -3:
  case -1:
  case 0:
  case 1:
  case 3:
    if (num_00 == 4) {
      (*(code *)PTR_memset_006aab00)(local_48 + num,0,0x20);
      bVar2 = false;
      goto LAB_004f8398;
    }
    if (num_00 == 8) {
      (*(code *)PTR_memset_006aab00)(local_48 + num,0,0x40);
      bVar2 = false;
      goto LAB_004f8420;
    }
    local_2c = local_48 + num * 2;
    (*(code *)PTR_memset_006aab00)(local_48 + num,0,num * 4);
    bVar2 = false;
    goto LAB_004f80a4;
  case -2:
    bn_sub_words(local_48,ap_00,ap_02,num_00);
    bn_sub_words(local_48 + num_00,ap,puVar12,num_00);
    bVar2 = true;
  }
  puVar11 = local_48 + num_00;
  if (num_00 == 4) {
    bn_mul_comba4(local_48 + num,local_48,puVar11);
LAB_004f8398:
    bn_mul_comba4(ap_01,ap_02,puVar12);
    pcVar13 = (code *)PTR_bn_mul_comba4_006a96bc;
LAB_004f83bc:
    (*pcVar13)(ap_01 + num,ap_00,ap);
  }
  else {
    if (num_00 == 8) {
      bn_mul_comba8(local_48 + num,local_48,puVar11,8);
LAB_004f8420:
      bn_mul_comba8(ap_01,ap_02,puVar12);
      pcVar13 = (code *)PTR_bn_mul_comba8_006a96b8;
      goto LAB_004f83bc;
    }
    local_2c = local_48 + num * 2;
    bn_mul_recursive_constprop_0(local_48 + num,local_48,puVar11,num_00,local_2c);
LAB_004f80a4:
    bn_mul_recursive_constprop_0(ap_01,ap_02,puVar12,num_00,local_2c);
    bn_mul_recursive_constprop_0(ap_01 + num,ap_00,ap,num_00,local_2c);
  }
  local_40 = local_48 + num;
  local_34 = ap_01 + num;
  uVar5 = bn_add_words(local_48,ap_01,local_34,num);
  if (bVar2) {
    uVar6 = bn_sub_words(local_40,local_48,local_40,num);
    uVar6 = -uVar6;
  }
  else {
    uVar6 = bn_add_words(local_40,local_40,local_48,num);
  }
  uVar7 = bn_add_words(ap_01 + num_00,ap_01 + num_00,local_40,num);
  uVar8 = uVar7 + uVar5 + uVar6;
  if (uVar8 != 0) {
    puVar10 = ap_01 + num + num_00;
    uVar9 = *puVar10;
    *puVar10 = uVar8 + uVar9;
    if (uVar8 + uVar9 < uVar8) {
      do {
        puVar10 = puVar10 + 1;
        uVar8 = *puVar10;
        *puVar10 = uVar8 + 1;
      } while (uVar8 + 1 == 0);
    }
  }
LAB_004f7d18:
  puVar12 = param_5 + param_4;
  uVar5 = bn_add_words(param_5,param_1,param_1 + param_4,param_4);
  if (bVar1) {
    uVar6 = bn_sub_words(puVar12,param_5,puVar12,param_4);
    uVar6 = -uVar6;
  }
  else {
    uVar6 = bn_add_words(puVar12,puVar12,param_5,param_4);
  }
  uVar7 = bn_add_words(param_1 + num,param_1 + num,puVar12,param_4);
  uVar8 = uVar7 + uVar5 + uVar6;
  if (uVar8 != 0) {
    puVar10 = param_1 + param_4 + num;
    uVar9 = *puVar10;
    *puVar10 = uVar8 + uVar9;
    if (uVar8 + uVar9 < uVar8) {
      do {
        puVar10 = puVar10 + 1;
        uVar8 = *puVar10;
        *puVar10 = uVar8 + 1;
      } while (uVar8 + 1 == 0);
    }
  }
  return;
}

