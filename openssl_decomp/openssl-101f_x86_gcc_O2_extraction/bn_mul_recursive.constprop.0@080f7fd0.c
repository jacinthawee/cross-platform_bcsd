
void __regparm3
bn_mul_recursive_constprop_0
          (ulong *param_1_00,ulong *param_2_00,ulong *param_3,int param_1,ulong *param_2)

{
  bool bVar1;
  int num;
  int iVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong *ap;
  ulong *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  ulong *puVar10;
  byte bVar11;
  ulong *local_24;
  
  bVar11 = 0;
  if (param_1 == 8) {
    bn_mul_comba8(param_1_00,param_2_00,param_3);
    return;
  }
  if (param_1 < 0x10) {
    bn_mul_normal(param_1_00,param_2_00,param_1,param_3,param_1);
    return;
  }
  num = param_1 >> 1;
  puVar10 = param_2_00 + num;
  iVar2 = bn_cmp_part_words(param_2_00,puVar10,num,0);
  ap = param_3 + num;
  iVar3 = bn_cmp_part_words(ap,param_3,num,0);
  switch(iVar3 + 4 + iVar2 * 3) {
  case 0:
    bn_sub_words(param_2,puVar10,param_2_00,num);
    bn_sub_part_words(param_2 + num,param_3,ap,num,0);
    bVar1 = false;
    break;
  case 1:
  case 3:
  case 4:
  case 5:
  case 7:
    if (num == 8) {
      puVar7 = param_2 + param_1;
      *puVar7 = 0;
      puVar7[0xf] = 0;
      puVar9 = (undefined4 *)((uint)(puVar7 + 1) & 0xfffffffc);
      for (uVar8 = (uint)((int)puVar7 +
                         (0x40 - (int)(undefined4 *)((uint)(puVar7 + 1) & 0xfffffffc))) >> 2;
          uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar9 = 0;
        puVar9 = puVar9 + (uint)bVar11 * -2 + 1;
      }
      bVar1 = false;
      goto LAB_080f80c7;
    }
    local_24 = param_2 + param_1 * 2;
    memset(param_2 + param_1,0,param_1 * 4);
    bVar1 = false;
    goto LAB_080f81eb;
  case 2:
    bn_sub_words(param_2,puVar10,param_2_00,num);
    bn_sub_words(param_2 + num,ap,param_3,num);
    bVar1 = true;
    break;
  case 6:
    bn_sub_part_words(param_2,param_2_00,puVar10,num,0);
    bn_sub_part_words(param_2 + num,param_3,ap,num,0);
    bVar1 = true;
    break;
  case 8:
    bn_sub_part_words(param_2,param_2_00,puVar10,num,0);
    bn_sub_words(param_2 + num,ap,param_3,num);
    bVar1 = false;
    break;
  default:
    bVar1 = false;
  }
  if (num == 8) {
    bn_mul_comba8(param_2 + param_1,param_2,param_2 + num);
LAB_080f80c7:
    bn_mul_comba8(param_1_00,param_2_00,param_3);
    bn_mul_comba8(param_1_00 + param_1,puVar10,ap);
  }
  else {
    local_24 = param_2 + param_1 * 2;
    bn_mul_recursive_constprop_0(num,local_24);
LAB_080f81eb:
    bn_mul_recursive_constprop_0(num,local_24);
    bn_mul_recursive_constprop_0(num,local_24);
  }
  puVar10 = param_2 + param_1;
  uVar4 = bn_add_words(param_2,param_1_00,param_1_00 + param_1,param_1);
  if (bVar1) {
    uVar5 = bn_sub_words(puVar10,param_2,puVar10,param_1);
    uVar5 = -uVar5;
  }
  else {
    uVar5 = bn_add_words(puVar10,puVar10,param_2,param_1);
  }
  uVar6 = bn_add_words(param_1_00 + num,param_1_00 + num,puVar10,param_1);
  uVar8 = uVar4 + uVar5 + uVar6;
  if (uVar8 != 0) {
    param_1_00 = param_1_00 + num + param_1;
    uVar4 = *param_1_00;
    *param_1_00 = uVar4 + uVar8;
    if (uVar4 + uVar8 < uVar8) {
      do {
        param_1_00 = param_1_00 + 1;
        *param_1_00 = *param_1_00 + 1;
      } while (*param_1_00 == 0);
    }
  }
  return;
}

