
uint ec_GFp_simple_point2oct
               (int param_1,undefined4 param_2,uint param_3,char *param_4,uint param_5,int param_6)

{
  char cVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint **ppuVar6;
  char cVar8;
  int iVar7;
  char *pcVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  
  if (param_3 == 2) {
    iVar4 = (*(code *)PTR_EC_POINT_is_at_infinity_006a9770)();
    if (iVar4 != 0) {
LAB_005f9788:
      if (param_4 != (char *)0x0) {
        if (param_5 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x68,100,"ecp_oct.c",0xdf);
          return 0;
        }
        *param_4 = '\0';
      }
      return 1;
    }
    iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(param_1 + 0x48);
    iVar4 = iVar5 + 7;
    if (iVar5 + 7 < 0) {
      iVar4 = iVar5 + 0xe;
    }
    uVar14 = iVar4 >> 3;
    uVar13 = uVar14;
  }
  else {
    if ((param_3 & 0xfffffffd) != 4) {
      uVar10 = 0x68;
      uVar3 = 0xd4;
      goto LAB_005f9730;
    }
    iVar4 = (*(code *)PTR_EC_POINT_is_at_infinity_006a9770)();
    if (iVar4 != 0) goto LAB_005f9788;
    iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(param_1 + 0x48);
    iVar4 = iVar5 + 7;
    if (iVar5 + 7 < 0) {
      iVar4 = iVar5 + 0xe;
    }
    uVar14 = iVar4 >> 3;
    uVar13 = uVar14 * 2;
  }
  uVar13 = uVar13 + 1;
  if (param_4 == (char *)0x0) {
    return uVar13;
  }
  if (param_5 < uVar13) {
    uVar10 = 100;
    uVar3 = 0xf1;
LAB_005f9730:
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x68,uVar10,"ecp_oct.c",uVar3);
    return 0;
  }
  iVar4 = 0;
  if ((param_6 == 0) && (iVar4 = (*(code *)PTR_BN_CTX_new_006a8a38)(), param_6 = iVar4, iVar4 == 0))
  {
    return 0;
  }
  (*(code *)PTR_BN_CTX_start_006a9644)(param_6);
  uVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(param_6);
  ppuVar6 = (uint **)(*(code *)PTR_BN_CTX_get_006a9648)(param_6);
  if ((ppuVar6 == (uint **)0x0) ||
     (iVar5 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a97bc)
                        (param_1,param_2,uVar3,ppuVar6,param_6), puVar2 = PTR_BN_num_bits_006a82f4,
     iVar5 == 0)) goto LAB_005f9888;
  cVar1 = (char)param_3;
  if (((param_3 & 0xfffffffb) != 2) ||
     ((cVar8 = cVar1, 0 < (int)ppuVar6[1] && (cVar8 = cVar1 + '\x01', (**ppuVar6 & 1) == 0)))) {
    cVar8 = cVar1;
  }
  *param_4 = cVar8;
  iVar7 = (*(code *)puVar2)(uVar3);
  iVar5 = iVar7 + 7;
  if (iVar7 + 7 < 0) {
    iVar5 = iVar7 + 0xe;
  }
  uVar11 = uVar14 - (iVar5 >> 3);
  if (uVar14 < uVar11) {
    uVar3 = 0x10e;
  }
  else {
    iVar5 = 1;
    if (uVar11 != 0) {
      iVar5 = uVar11 + 1;
      (*(code *)PTR_memset_006aab00)(param_4 + 1,0);
    }
    iVar7 = (*(code *)PTR_BN_bn2bin_006a8300)(uVar3,param_4 + iVar5);
    uVar11 = iVar7 + iVar5;
    if (uVar11 == uVar14 + 1) {
      if ((param_3 & 0xfffffffd) == 4) {
        iVar7 = (*(code *)PTR_BN_num_bits_006a82f4)(ppuVar6);
        iVar5 = iVar7 + 7;
        if (iVar7 + 7 < 0) {
          iVar5 = iVar7 + 0xe;
        }
        uVar12 = uVar14 - (iVar5 >> 3);
        if (uVar14 < uVar12) {
          uVar3 = 0x123;
          goto LAB_005f9a14;
        }
        if (uVar12 != 0) {
          pcVar9 = param_4 + uVar11;
          uVar11 = uVar11 + uVar12;
          (*(code *)PTR_memset_006aab00)(pcVar9,0);
        }
        iVar5 = (*(code *)PTR_BN_bn2bin_006a8300)(ppuVar6,param_4 + uVar11);
        uVar11 = uVar11 + iVar5;
      }
      if (uVar11 == uVar13) {
        (*(code *)PTR_BN_CTX_end_006a9654)(param_6);
        if (iVar4 == 0) {
          return uVar11;
        }
        (*(code *)PTR_BN_CTX_free_006a8a40)(iVar4);
        return uVar11;
      }
      uVar3 = 0x131;
    }
    else {
      uVar3 = 0x11a;
    }
  }
LAB_005f9a14:
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x68,0x44,"ecp_oct.c",uVar3);
LAB_005f9888:
  (*(code *)PTR_BN_CTX_end_006a9654)(param_6);
  if (iVar4 == 0) {
    return 0;
  }
  (*(code *)PTR_BN_CTX_free_006a8a40)(iVar4);
  return 0;
}

