
undefined4
ec_GFp_simple_oct2point(int param_1,undefined4 param_2,byte *param_3,int param_4,int param_5)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint **ppuVar5;
  undefined4 uVar6;
  uint **ppuVar7;
  uint **ppuVar8;
  uint uVar9;
  int iVar10;
  code *pcVar11;
  undefined4 local_30;
  uint **local_2c;
  
  if (param_4 == 0) {
    uVar6 = 100;
    uVar2 = 0x152;
    goto LAB_005f7d28;
  }
  bVar1 = *param_3;
  uVar9 = bVar1 & 0xfe;
  ppuVar8 = (uint **)(bVar1 & 1);
  if ((bVar1 & 0xfe) == 0) {
    if ((bVar1 & 1) == 0) {
      if (param_4 == 1) {
                    /* WARNING: Could not recover jumptable at 0x005f7ef4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (*(code *)PTR_EC_POINT_set_to_infinity_006a860c)();
        return uVar2;
      }
      uVar6 = 0x66;
      uVar2 = 0x165;
      goto LAB_005f7d28;
    }
LAB_005f7f3c:
    uVar6 = 0x66;
    uVar2 = 0x15f;
LAB_005f7d28:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x67,uVar6,"ecp_oct.c",uVar2);
    return 0;
  }
  if (uVar9 == 2) {
    iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(param_1 + 0x48);
    iVar10 = iVar3 + 7;
    if (iVar3 + 7 < 0) {
      iVar10 = iVar3 + 0xe;
    }
    iVar10 = iVar10 >> 3;
    iVar3 = iVar10;
  }
  else {
    if (uVar9 == 4) {
      if ((bVar1 & 1) != 0) goto LAB_005f7f3c;
    }
    else if (uVar9 != 6) {
      uVar6 = 0x66;
      uVar2 = 0x15b;
      goto LAB_005f7d28;
    }
    iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(param_1 + 0x48);
    iVar10 = iVar3 + 7;
    if (iVar3 + 7 < 0) {
      iVar10 = iVar3 + 0xe;
    }
    iVar10 = iVar10 >> 3;
    iVar3 = iVar10 * 2;
  }
  if (iVar3 + 1 != param_4) {
    uVar6 = 0x66;
    uVar2 = 0x172;
    goto LAB_005f7d28;
  }
  if (param_5 == 0) {
    iVar3 = (*(code *)PTR_BN_CTX_new_006a794c)();
    if (iVar3 == 0) {
      return 0;
    }
    (*(code *)PTR_BN_CTX_start_006a8528)(iVar3);
    local_30 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar3);
    local_2c = (uint **)(*(code *)PTR_BN_CTX_get_006a852c)(iVar3);
    if ((local_2c == (uint **)0x0) ||
       (iVar4 = (*(code *)PTR_BN_bin2bn_006a7904)(param_3 + 1,iVar10,local_30), param_5 = iVar3,
       iVar4 == 0)) {
      uVar2 = 0;
      (*(code *)PTR_BN_CTX_end_006a8530)(iVar3);
      goto LAB_005f7e88;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a8528)(param_5);
    local_30 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    local_2c = (uint **)(*(code *)PTR_BN_CTX_get_006a852c)(param_5);
    if ((local_2c == (uint **)0x0) ||
       (iVar3 = (*(code *)PTR_BN_bin2bn_006a7904)(param_3 + 1,iVar10,local_30), iVar3 == 0)) {
      (*(code *)PTR_BN_CTX_end_006a8530)(param_5);
      return 0;
    }
    iVar3 = 0;
  }
  iVar4 = (*(code *)PTR_BN_ucmp_006a7fb4)(local_30,param_1 + 0x48);
  if (-1 < iVar4) {
    uVar2 = 0x185;
    goto LAB_005f7e5c;
  }
  ppuVar7 = ppuVar8;
  pcVar11 = (code *)PTR_EC_POINT_set_compressed_coordinates_GFp_006a9700;
  if (uVar9 == 2) goto LAB_005f8048;
  iVar10 = (*(code *)PTR_BN_bin2bn_006a7904)(param_3 + iVar10 + 1,iVar10,local_2c);
  if (iVar10 == 0) {
LAB_005f7e70:
    uVar2 = 0;
  }
  else {
    iVar10 = (*(code *)PTR_BN_ucmp_006a7fb4)(local_2c,param_1 + 0x48);
    if (-1 < iVar10) {
      uVar2 = 0x191;
LAB_005f7e5c:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x67,0x66,"ecp_oct.c",uVar2);
      goto LAB_005f7e70;
    }
    ppuVar7 = local_2c;
    pcVar11 = (code *)PTR_EC_POINT_set_affine_coordinates_GFp_006a8634;
    if (uVar9 == 6) {
      ppuVar5 = (uint **)0x0;
      if (0 < (int)local_2c[1]) {
        ppuVar5 = (uint **)(**local_2c & 1);
      }
      if (ppuVar5 != ppuVar8) {
        uVar2 = 0x196;
        goto LAB_005f7e5c;
      }
    }
LAB_005f8048:
    iVar10 = (*pcVar11)(param_1,param_2,local_30,ppuVar7,param_5);
    if (iVar10 == 0) goto LAB_005f7e70;
    iVar10 = (*(code *)PTR_EC_POINT_is_on_curve_006a8644)(param_1,param_2,param_5);
    if (iVar10 < 1) {
      uVar2 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x67,0x6b,"ecp_oct.c",0x1a1);
    }
    else {
      uVar2 = 1;
    }
  }
  (*(code *)PTR_BN_CTX_end_006a8530)(param_5);
  if (iVar3 == 0) {
    return uVar2;
  }
LAB_005f7e88:
  (*(code *)PTR_BN_CTX_free_006a7954)(iVar3);
  return uVar2;
}

