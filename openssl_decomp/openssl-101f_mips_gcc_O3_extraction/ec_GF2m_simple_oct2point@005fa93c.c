
undefined4
ec_GF2m_simple_oct2point(int *param_1,undefined4 param_2,byte *param_3,int param_4,int param_5)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  code *pcVar9;
  int iVar10;
  uint local_34;
  uint **local_30;
  
  if (param_4 == 0) {
    uVar5 = 100;
    uVar2 = 0x135;
    goto LAB_005fa9b4;
  }
  bVar1 = *param_3;
  uVar8 = bVar1 & 0xfe;
  uVar7 = bVar1 & 1;
  if ((bVar1 & 0xfe) == 0) {
    if ((bVar1 & 1) == 0) {
      if (param_4 == 1) {
                    /* WARNING: Could not recover jumptable at 0x005fab98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (*(code *)PTR_EC_POINT_set_to_infinity_006a972c)();
        return uVar2;
      }
      uVar5 = 0x66;
      uVar2 = 0x14c;
      goto LAB_005fa9b4;
    }
LAB_005fabd8:
    uVar5 = 0x66;
    uVar2 = 0x144;
LAB_005fa9b4:
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xa0,uVar5,"ec2_oct.c",uVar2);
    return 0;
  }
  if (uVar8 == 2) {
    iVar3 = (*(code *)PTR_EC_GROUP_get_degree_006a8bcc)();
    iVar10 = iVar3 + 7;
    if (iVar3 + 7 < 0) {
      iVar10 = iVar3 + 0xe;
    }
    iVar10 = iVar10 >> 3;
    iVar3 = iVar10;
  }
  else {
    if (uVar8 == 4) {
      if ((bVar1 & 1) != 0) goto LAB_005fabd8;
    }
    else if (uVar8 != 6) {
      uVar5 = 0x66;
      uVar2 = 0x13f;
      goto LAB_005fa9b4;
    }
    iVar3 = (*(code *)PTR_EC_GROUP_get_degree_006a8bcc)(param_1);
    iVar10 = iVar3 + 7;
    if (iVar3 + 7 < 0) {
      iVar10 = iVar3 + 0xe;
    }
    iVar10 = iVar10 >> 3;
    iVar3 = iVar10 * 2;
  }
  if (iVar3 + 1 != param_4) {
    uVar5 = 0x66;
    uVar2 = 0x158;
    goto LAB_005fa9b4;
  }
  if (param_5 == 0) {
    param_5 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if (param_5 == 0) {
      return 0;
    }
    (*(code *)PTR_BN_CTX_start_006a9644)(param_5);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    local_34 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    local_30 = (uint **)(*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    if ((local_30 == (uint **)0x0) ||
       (iVar4 = (*(code *)PTR_BN_bin2bn_006a89f0)(param_3 + 1,iVar10,uVar2), iVar3 = param_5,
       iVar4 == 0)) {
      uVar2 = 0;
      (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
      goto LAB_005fab2c;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a9644)(param_5);
    uVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    local_34 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    local_30 = (uint **)(*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    if ((local_30 == (uint **)0x0) ||
       (iVar3 = (*(code *)PTR_BN_bin2bn_006a89f0)(param_3 + 1,iVar10,uVar2), iVar3 == 0)) {
      (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
      return 0;
    }
    iVar3 = 0;
  }
  iVar4 = (*(code *)PTR_BN_ucmp_006a9678)(uVar2,param_1 + 0x12);
  if (iVar4 < 0) {
    uVar6 = uVar7;
    pcVar9 = (code *)PTR_EC_POINT_set_compressed_coordinates_GF2m_006aa814;
    if (uVar8 != 2) {
      iVar10 = (*(code *)PTR_BN_bin2bn_006a89f0)(param_3 + iVar10 + 1,iVar10,local_34);
      if (iVar10 == 0) goto LAB_005fab14;
      iVar10 = (*(code *)PTR_BN_ucmp_006a9678)(local_34,param_1 + 0x12);
      if (-1 < iVar10) {
        uVar2 = 0x179;
        goto LAB_005fab00;
      }
      uVar6 = local_34;
      pcVar9 = (code *)PTR_EC_POINT_set_affine_coordinates_GF2m_006a97b4;
      if (uVar8 == 6) {
        iVar10 = (**(code **)(*param_1 + 0x8c))(param_1,local_30,local_34,uVar2,param_5);
        if (iVar10 == 0) goto LAB_005fab14;
        uVar8 = 0;
        if (0 < (int)local_30[1]) {
          uVar8 = **local_30 & 1;
        }
        pcVar9 = (code *)PTR_EC_POINT_set_affine_coordinates_GF2m_006a97b4;
        if (uVar8 != uVar7) {
          uVar2 = 0x181;
          goto LAB_005fab00;
        }
      }
    }
    iVar10 = (*pcVar9)(param_1,param_2,uVar2,uVar6,param_5);
    if (iVar10 == 0) goto LAB_005fab14;
    iVar10 = (*(code *)PTR_EC_POINT_is_on_curve_006a9768)(param_1,param_2,param_5);
    if (iVar10 == 0) {
      uVar2 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xa0,0x6b,"ec2_oct.c",0x18b);
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0x16c;
LAB_005fab00:
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xa0,0x66,"ec2_oct.c",uVar2);
LAB_005fab14:
    uVar2 = 0;
  }
  (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
  param_5 = iVar3;
  if (iVar3 == 0) {
    return uVar2;
  }
LAB_005fab2c:
  (*(code *)PTR_BN_CTX_free_006a8a40)(param_5);
  return uVar2;
}

