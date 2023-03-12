
void bn_mul_recursive_constprop_0
               (ulong *param_1,ulong *param_2,ulong *param_3,int param_4,ulong *param_5)

{
  int num;
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  int iVar10;
  ulong *ap;
  ulong *ap_00;
  ulong *puVar11;
  ulong *ap_01;
  ulong *rp;
  ulong *puVar12;
  ulong *ap_02;
  ulong *local_48;
  
  if (param_4 == 8) {
    bn_mul_comba8();
    return;
  }
  if (param_4 < 0x10) {
    bn_mul_normal(param_1,param_2,param_4,param_3);
    return;
  }
  num = param_4 >> 1;
  puVar11 = param_2 + num;
  ap_01 = param_3 + num;
  iVar4 = bn_cmp_part_words(param_2,puVar11,num,0);
  iVar5 = bn_cmp_part_words(ap_01,param_3,num,0);
  switch(iVar5 + iVar4 * 3) {
  case 2:
    bn_sub_part_words(param_5,param_2,puVar11,num,0);
    bn_sub_part_words(param_5 + num,param_3,ap_01,num,0);
    bVar3 = true;
    break;
  case 4:
    bVar3 = false;
    bn_sub_part_words(param_5,param_2,puVar11,num,0);
LAB_0008af88:
    bn_sub_words(param_5 + num,ap_01,param_3,num);
    break;
  default:
    if (num != 8) {
      bVar1 = false;
      bVar3 = false;
      goto LAB_0008af0a;
    }
    bVar3 = false;
    goto LAB_0008ae68;
  case -4:
    bn_sub_words(param_5,puVar11,param_2,num);
    bVar3 = false;
    bn_sub_part_words(param_5 + num,param_3,ap_01,num,0);
    break;
  case -3:
  case -1:
  case 0:
  case 1:
  case 3:
    if (num == 8) {
      bVar3 = false;
      memset(param_5 + param_4,0,0x40);
      goto LAB_0008ae84;
    }
    bVar1 = true;
    bVar3 = false;
    goto LAB_0008af0a;
  case -2:
    bVar3 = true;
    bn_sub_words(param_5,puVar11,param_2,num);
    goto LAB_0008af88;
  }
  if (num == 8) {
LAB_0008ae68:
    bn_mul_comba8(param_5 + param_4,param_5,param_5 + num);
LAB_0008ae84:
    bn_mul_comba8(param_1,param_2,param_3);
    bn_mul_comba8(param_1 + param_4,puVar11,ap_01);
    goto LAB_0008ae9e;
  }
  bVar1 = false;
LAB_0008af0a:
  rp = param_5 + param_4 * 2;
  if (bVar1) {
    memset(param_5 + param_4,0,param_4 * 4);
  }
  else {
    bn_mul_recursive_constprop_0(param_5 + param_4,param_5,param_5 + num,num,rp);
  }
  ap_02 = param_1 + param_4;
  bn_mul_recursive_constprop_0(param_1,param_2,param_3,num,rp);
  if (num < 0x10) {
    bn_mul_normal(ap_02,puVar11,num,ap_01,num);
    goto LAB_0008ae9e;
  }
  iVar4 = param_4 >> 2;
  ap = puVar11 + iVar4;
  ap_00 = ap_01 + iVar4;
  iVar5 = bn_cmp_part_words(puVar11,ap,iVar4,0);
  iVar10 = bn_cmp_part_words(ap_00,ap_01,iVar4,0);
  switch(iVar10 + iVar5 * 3) {
  case 2:
    bn_sub_part_words(rp,puVar11,ap,iVar4,0);
    bn_sub_part_words(rp + iVar4,ap_01,ap_00,iVar4,0);
    bVar1 = true;
    break;
  case 4:
    bVar1 = false;
    bn_sub_part_words(rp,puVar11,ap,iVar4,0);
LAB_0008b208:
    bn_sub_words(rp + iVar4,ap_00,ap_01,iVar4);
    break;
  default:
    if (iVar4 != 8) {
      bVar2 = false;
      bVar1 = false;
      goto LAB_0008b0c6;
    }
    bVar1 = false;
    goto LAB_0008b24e;
  case -4:
    bn_sub_words(rp,ap,puVar11,iVar4);
    bVar1 = false;
    bn_sub_part_words(rp + iVar4,ap_01,ap_00,iVar4,0);
    break;
  case -3:
  case -1:
  case 0:
  case 1:
  case 3:
    if (iVar4 == 8) {
      bVar1 = false;
      memset(rp + num,0,0x40);
      goto LAB_0008b25c;
    }
    bVar2 = true;
    bVar1 = false;
    goto LAB_0008b0c6;
  case -2:
    bVar1 = true;
    bn_sub_words(rp,ap,puVar11,iVar4);
    goto LAB_0008b208;
  }
  if (iVar4 == 8) {
LAB_0008b24e:
    bn_mul_comba8(rp + num,rp,rp + iVar4);
LAB_0008b25c:
    bn_mul_comba8(ap_02,puVar11,ap_01);
    bn_mul_comba8(ap_02 + num,ap,ap_00);
  }
  else {
    bVar2 = false;
LAB_0008b0c6:
    puVar12 = rp + num * 2;
    if (bVar2) {
      memset(rp + num,0,num * 4);
    }
    else {
      bn_mul_recursive_constprop_0(rp + num,rp,rp + iVar4,iVar4,puVar12);
    }
    bn_mul_recursive_constprop_0(ap_02,puVar11,ap_01,iVar4,puVar12);
    bn_mul_recursive_constprop_0(ap_02 + num,ap,ap_00,iVar4,puVar12);
  }
  puVar11 = rp + num;
  uVar6 = bn_add_words(rp,ap_02,ap_02 + num,num);
  if (bVar1) {
    uVar7 = bn_sub_words(puVar11,rp,puVar11,num);
    uVar7 = -uVar7;
  }
  else {
    uVar7 = bn_add_words(puVar11,puVar11,rp,num);
  }
  uVar8 = bn_add_words(ap_02 + iVar4,ap_02 + iVar4,puVar11,num);
  uVar9 = uVar8 + uVar6 + uVar7;
  if (uVar9 != 0) {
    iVar4 = num + iVar4;
    puVar11 = ap_02 + iVar4;
    uVar6 = ap_02[iVar4];
    ap_02[iVar4] = uVar6 + uVar9;
    if (uVar6 + uVar9 < uVar9) {
      do {
        uVar6 = puVar11[1];
        puVar11 = puVar11 + 1;
        *puVar11 = uVar6 + 1;
      } while (uVar6 + 1 == 0);
    }
  }
LAB_0008ae9e:
  local_48 = param_1 + param_4;
  puVar11 = param_5 + param_4;
  uVar6 = bn_add_words(param_5,param_1,local_48,param_4);
  if (bVar3) {
    uVar7 = bn_sub_words(puVar11,param_5,puVar11,param_4);
    uVar7 = -uVar7;
  }
  else {
    uVar7 = bn_add_words(puVar11,puVar11,param_5,param_4);
  }
  uVar8 = bn_add_words(param_1 + num,param_1 + num,puVar11,param_4);
  uVar9 = uVar8 + uVar6 + uVar7;
  if (uVar9 != 0) {
    param_4 = param_4 + num;
    uVar6 = param_1[param_4];
    puVar11 = param_1 + param_4;
    param_1[param_4] = uVar6 + uVar9;
    if (uVar6 + uVar9 < uVar9) {
      do {
        uVar6 = puVar11[1];
        puVar11 = puVar11 + 1;
        *puVar11 = uVar6 + 1;
      } while (uVar6 + 1 == 0);
    }
  }
  return;
}

