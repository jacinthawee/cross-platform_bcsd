
uint ec_GF2m_simple_mul(int *param_1,undefined4 param_2,int param_3,uint param_4,int *param_5,
                       int *param_6,int param_7)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint local_34;
  
  if (param_7 == 0) {
    param_7 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if (param_7 == 0) {
      return 0;
    }
    iVar7 = param_7;
    if (param_3 == 0) goto LAB_005f6a64;
LAB_005f6988:
    if (param_4 < 2) {
LAB_005f6a6c:
      if ((param_4 != 0) ||
         (iVar2 = (*(code *)PTR_EC_GROUP_have_precompute_mult_006aa7bc)(param_1), iVar2 == 0)) {
        iVar2 = (*(code *)PTR_EC_POINT_new_006a9140)(param_1);
        if (iVar2 != 0) {
          iVar3 = (*(code *)PTR_EC_POINT_new_006a9140)(param_1);
          if (iVar3 != 0) {
            iVar4 = (*(code *)PTR_EC_POINT_set_to_infinity_006a972c)(param_1,iVar3);
            if (iVar4 == 0) {
LAB_005f6ba0:
              uVar1 = 0;
LAB_005f6ba4:
              (*(code *)PTR_EC_POINT_free_006a9134)(iVar2);
            }
            else {
              if (param_3 == 0) {
LAB_005f6bf8:
                if (param_4 == 0) {
LAB_005f6d44:
                  iVar4 = (*(code *)PTR_EC_POINT_copy_006a9144)(param_2,iVar3);
                  uVar1 = (uint)(iVar4 != 0);
                  goto LAB_005f6ba4;
                }
                iVar5 = *param_5;
                iVar4 = *param_6;
                if (iVar2 != iVar5) {
                  local_34 = 0;
                  do {
                    param_5 = param_5 + 1;
                    if (((iVar4 == 0) || (*(int *)(iVar4 + 4) == 0)) ||
                       ((iVar5 == 0 ||
                        (iVar6 = (*(code *)PTR_EC_POINT_is_at_infinity_006a9770)(param_1,iVar5),
                        iVar6 != 0)))) {
                      iVar4 = (*(code *)PTR_EC_POINT_set_to_infinity_006a972c)(param_1,iVar2);
                    }
                    else {
                      if (*(int *)(iVar5 + 0x40) == 0) goto LAB_005f6b18;
                      iVar4 = ec_GF2m_montgomery_point_multiply_part_0
                                        (param_1,iVar2,iVar4,iVar5,param_7);
                    }
                    if ((iVar4 == 0) ||
                       (((*(int *)(*param_6 + 0xc) != 0 &&
                         (iVar4 = (**(code **)(*param_1 + 0x60))(param_1,iVar2,param_7), iVar4 == 0)
                         ) || (iVar4 = (**(code **)(*param_1 + 0x58))
                                                 (param_1,iVar3,iVar3,iVar2,param_7), iVar4 == 0))))
                    goto LAB_005f6ba0;
                    local_34 = local_34 + 1;
                    if (param_4 == local_34) goto LAB_005f6d44;
                    iVar5 = *param_5;
                    param_6 = param_6 + 1;
                    iVar4 = *param_6;
                  } while (iVar2 != iVar5);
                }
LAB_005f6cfc:
                (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xd0,0x70,"ec2_mult.c",0xe2);
              }
              else {
                iVar4 = param_1[1];
                if (iVar2 == iVar4) goto LAB_005f6cfc;
                if (((*(int *)(param_3 + 4) == 0) || (iVar4 == 0)) ||
                   (iVar5 = (*(code *)PTR_EC_POINT_is_at_infinity_006a9770)(param_1,iVar4),
                   iVar5 != 0)) {
                  iVar4 = (*(code *)PTR_EC_POINT_set_to_infinity_006a972c)(param_1,iVar2);
LAB_005f6b48:
                  if (((iVar4 == 0) ||
                      ((*(int *)(param_3 + 0xc) != 0 &&
                       (iVar4 = (**(code **)(*param_1 + 0x60))(param_1,iVar2,param_7), iVar4 == 0)))
                      ) || (iVar4 = (**(code **)(*param_1 + 0x58))
                                              (param_1,iVar3,iVar3,iVar2,param_7), iVar4 == 0))
                  goto LAB_005f6ba0;
                  goto LAB_005f6bf8;
                }
                if (*(int *)(iVar4 + 0x40) != 0) {
                  iVar4 = ec_GF2m_montgomery_point_multiply_part_0
                                    (param_1,iVar2,param_3,iVar4,param_7);
                  goto LAB_005f6b48;
                }
              }
LAB_005f6b18:
              uVar1 = 0;
              (*(code *)PTR_EC_POINT_free_006a9134)(iVar2);
            }
            (*(code *)PTR_EC_POINT_free_006a9134)(iVar3);
            goto LAB_005f69c8;
          }
          (*(code *)PTR_EC_POINT_free_006a9134)(iVar2);
        }
        uVar1 = 0;
        goto LAB_005f69c8;
      }
    }
  }
  else {
    iVar7 = 0;
    if (param_3 != 0) goto LAB_005f6988;
LAB_005f6a64:
    if (param_4 < 3) goto LAB_005f6a6c;
  }
  uVar1 = (*(code *)PTR_ec_wNAF_mul_006a9718)
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7);
LAB_005f69c8:
  if (iVar7 != 0) {
    (*(code *)PTR_BN_CTX_free_006a8a40)(iVar7);
    return uVar1;
  }
  return uVar1;
}
