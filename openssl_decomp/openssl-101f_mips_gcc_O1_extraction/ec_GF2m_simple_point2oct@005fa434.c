
uint ec_GF2m_simple_point2oct
               (int *param_1,undefined4 param_2,uint param_3,char *param_4,uint param_5,int param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint **ppuVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  code *pcVar13;
  
  if (param_3 == 2) {
    iVar2 = (*(code *)PTR_EC_POINT_is_at_infinity_006a9770)();
    if (iVar2 != 0) {
LAB_005fa500:
      if (param_4 != (char *)0x0) {
        if (param_5 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xa1,100,"ec2_oct.c",0xbd);
          return 0;
        }
        *param_4 = '\0';
      }
      return 1;
    }
    iVar3 = (*(code *)PTR_EC_GROUP_get_degree_006a8bcc)(param_1);
    iVar2 = iVar3 + 7;
    if (iVar3 + 7 < 0) {
      iVar2 = iVar3 + 0xe;
    }
    uVar12 = iVar2 >> 3;
    uVar11 = uVar12;
  }
  else {
    if ((param_3 & 0xfffffffd) != 4) {
      uVar8 = 0x68;
      uVar1 = 0xb2;
      goto LAB_005fa4a8;
    }
    iVar2 = (*(code *)PTR_EC_POINT_is_at_infinity_006a9770)();
    if (iVar2 != 0) goto LAB_005fa500;
    iVar3 = (*(code *)PTR_EC_GROUP_get_degree_006a8bcc)(param_1);
    iVar2 = iVar3 + 7;
    if (iVar3 + 7 < 0) {
      iVar2 = iVar3 + 0xe;
    }
    uVar12 = iVar2 >> 3;
    uVar11 = uVar12 * 2;
  }
  uVar11 = uVar11 + 1;
  if (param_4 == (char *)0x0) {
    return uVar11;
  }
  if (param_5 < uVar11) {
    uVar8 = 100;
    uVar1 = 0xcf;
LAB_005fa4a8:
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xa1,uVar8,"ec2_oct.c",uVar1);
    return 0;
  }
  iVar2 = 0;
  if ((param_6 == 0) && (iVar2 = (*(code *)PTR_BN_CTX_new_006a8a38)(), param_6 = iVar2, iVar2 == 0))
  {
    return 0;
  }
  (*(code *)PTR_BN_CTX_start_006a9644)(param_6);
  iVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(param_6);
  uVar1 = (*(code *)PTR_BN_CTX_get_006a9648)(param_6);
  ppuVar4 = (uint **)(*(code *)PTR_BN_CTX_get_006a9648)(param_6);
  if ((ppuVar4 == (uint **)0x0) ||
     (iVar5 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GF2m_006a97b8)
                        (param_1,param_2,iVar3,uVar1,param_6), iVar5 == 0)) goto LAB_005fa6c4;
  *param_4 = (char)param_3;
  pcVar13 = (code *)PTR_BN_num_bits_006a82f4;
  if ((param_3 != 4) && (*(int *)(iVar3 + 4) != 0)) {
    iVar5 = (**(code **)(*param_1 + 0x8c))(param_1,ppuVar4,uVar1,iVar3,param_6);
    pcVar13 = (code *)PTR_BN_num_bits_006a82f4;
    if (iVar5 == 0) goto LAB_005fa6c4;
    if ((0 < (int)ppuVar4[1]) && ((**ppuVar4 & 1) != 0)) {
      *param_4 = *param_4 + '\x01';
    }
  }
  iVar6 = (*pcVar13)(iVar3);
  iVar5 = iVar6 + 7;
  if (iVar6 + 7 < 0) {
    iVar5 = iVar6 + 0xe;
  }
  uVar9 = uVar12 - (iVar5 >> 3);
  if (uVar12 < uVar9) {
    uVar1 = 0xef;
  }
  else {
    iVar5 = 1;
    if (uVar9 != 0) {
      iVar5 = uVar9 + 1;
      (*(code *)PTR_memset_006aab00)(param_4 + 1,0);
    }
    iVar3 = (*(code *)PTR_BN_bn2bin_006a8300)(iVar3,param_4 + iVar5);
    uVar9 = iVar3 + iVar5;
    if (uVar9 == uVar12 + 1) {
      if ((param_3 & 0xfffffffd) == 4) {
        iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar1);
        iVar3 = iVar5 + 7;
        if (iVar5 + 7 < 0) {
          iVar3 = iVar5 + 0xe;
        }
        uVar10 = uVar12 - (iVar3 >> 3);
        if (uVar12 < uVar10) {
          uVar1 = 0x104;
          goto LAB_005fa6b0;
        }
        if (uVar10 != 0) {
          pcVar7 = param_4 + uVar9;
          uVar9 = uVar9 + uVar10;
          (*(code *)PTR_memset_006aab00)(pcVar7,0);
        }
        iVar3 = (*(code *)PTR_BN_bn2bin_006a8300)(uVar1,param_4 + uVar9);
        uVar9 = uVar9 + iVar3;
      }
      if (uVar9 == uVar11) {
        (*(code *)PTR_BN_CTX_end_006a9654)(param_6);
        if (iVar2 == 0) {
          return uVar9;
        }
        (*(code *)PTR_BN_CTX_free_006a8a40)(iVar2);
        return uVar9;
      }
      uVar1 = 0x112;
    }
    else {
      uVar1 = 0xfb;
    }
  }
LAB_005fa6b0:
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xa1,0x44,"ec2_oct.c",uVar1);
LAB_005fa6c4:
  (*(code *)PTR_BN_CTX_end_006a9654)(param_6);
  if (iVar2 == 0) {
    return 0;
  }
  (*(code *)PTR_BN_CTX_free_006a8a40)(iVar2);
  return 0;
}

