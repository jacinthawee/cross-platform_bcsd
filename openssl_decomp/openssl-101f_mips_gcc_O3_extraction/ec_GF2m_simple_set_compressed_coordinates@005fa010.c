
bool ec_GF2m_simple_set_compressed_coordinates
               (int *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint **ppuVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  bool bVar7;
  uint uVar8;
  undefined4 local_2c;
  
  (*(code *)PTR_ERR_clear_error_006a7fe0)();
  if (param_5 == 0) {
    param_5 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if (param_5 == 0) {
      return false;
    }
    (*(code *)PTR_BN_CTX_start_006a9644)(param_5);
    uVar1 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    iVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    local_2c = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    ppuVar3 = (uint **)(*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    if ((ppuVar3 == (uint **)0x0) ||
       (iVar5 = (*(code *)PTR_BN_GF2m_mod_arr_006aa7a4)(iVar2,param_3,param_1 + 0x17),
       iVar4 = param_5, iVar5 == 0)) {
      bVar7 = false;
      (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
      goto LAB_005fa158;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a9644)(param_5);
    uVar1 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    iVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    local_2c = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    ppuVar3 = (uint **)(*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    if ((ppuVar3 == (uint **)0x0) ||
       (iVar4 = (*(code *)PTR_BN_GF2m_mod_arr_006aa7a4)(iVar2,param_3,param_1 + 0x17), iVar4 == 0))
    {
      (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
      return false;
    }
    iVar4 = 0;
  }
  if (*(int *)(iVar2 + 4) == 0) {
    iVar5 = (*(code *)PTR_BN_GF2m_mod_sqrt_arr_006aa80c)(local_2c,param_1 + 0x22,param_1 + 0x17);
    if (iVar5 != 0) {
LAB_005fa120:
      iVar2 = (*(code *)PTR_EC_POINT_set_affine_coordinates_GF2m_006a97b4)
                        (param_1,param_2,iVar2,local_2c,param_5);
      bVar7 = iVar2 != 0;
      goto LAB_005fa144;
    }
LAB_005fa1f8:
    bVar7 = false;
  }
  else {
    iVar5 = (**(code **)(*param_1 + 0x88))(param_1,uVar1,iVar2,param_5);
    if ((((iVar5 == 0) ||
         (iVar5 = (**(code **)(*param_1 + 0x8c))(param_1,uVar1,param_1 + 0x22,uVar1,param_5),
         iVar5 == 0)) ||
        (iVar5 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(uVar1,param_1 + 0x1d,uVar1), iVar5 == 0)) ||
       (iVar5 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(uVar1,iVar2,uVar1), iVar5 == 0))
    goto LAB_005fa1f8;
    iVar5 = (*(code *)PTR_BN_GF2m_mod_solve_quad_arr_006aa810)(ppuVar3,uVar1,param_1 + 0x17,param_5)
    ;
    if (iVar5 == 0) {
      uVar8 = (*(code *)PTR_ERR_peek_last_error_006a8508)();
      if ((uVar8 >> 0x18 == 3) && ((uVar8 & 0xfff) == 0x74)) {
        (*(code *)PTR_ERR_clear_error_006a7fe0)();
        uVar6 = 0x6e;
        uVar1 = 0x87;
      }
      else {
        uVar6 = 3;
        uVar1 = 0x8a;
      }
      bVar7 = false;
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xa4,uVar6,"ec2_oct.c",uVar1);
    }
    else {
      uVar8 = 0;
      if (0 < (int)ppuVar3[1]) {
        uVar8 = **ppuVar3 & 1;
      }
      iVar5 = (**(code **)(*param_1 + 0x84))(param_1,local_2c,iVar2,ppuVar3,param_5);
      if (iVar5 == 0) goto LAB_005fa1f8;
      if ((uVar8 == (param_4 != 0)) ||
         (iVar5 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(local_2c,local_2c,iVar2), iVar5 != 0))
      goto LAB_005fa120;
      bVar7 = false;
    }
  }
LAB_005fa144:
  (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
  param_5 = iVar4;
  if (iVar4 == 0) {
    return bVar7;
  }
LAB_005fa158:
  (*(code *)PTR_BN_CTX_free_006a8a40)(param_5);
  return bVar7;
}

