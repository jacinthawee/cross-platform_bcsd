
undefined4
ec_GF2m_montgomery_point_multiply_part_0
          (int *param_1,int param_2,int *param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  int local_30;
  int local_2c;
  
  (*(code *)PTR_BN_CTX_start_006a9644)(param_5);
  iVar1 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
  iVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
  if (iVar2 != 0) {
    iVar12 = param_4 + 4;
    iVar3 = (*(code *)PTR_BN_GF2m_mod_arr_006aa7a4)(iVar1,iVar12,param_1 + 0x17);
    if ((iVar3 != 0) && (iVar3 = (*(code *)PTR_BN_set_word_006a8820)(iVar2,1), iVar3 != 0)) {
      iVar13 = param_2 + 0x18;
      iVar3 = (**(code **)(*param_1 + 0x88))(param_1,iVar13,iVar1,param_5);
      if (iVar3 != 0) {
        iVar7 = param_2 + 4;
        iVar3 = (**(code **)(*param_1 + 0x88))(param_1,iVar7,iVar13,param_5);
        if ((iVar3 != 0) &&
           (iVar3 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(iVar7,iVar7,param_1 + 0x22), iVar3 != 0)) {
          iVar3 = *param_3;
          local_30 = param_3[1] + -1;
          uVar8 = *(uint *)(iVar3 + local_30 * 4);
          uVar9 = 0x40000000;
          if (-1 < (int)uVar8) {
            uVar10 = 0x80000000;
            do {
              uVar9 = uVar10;
              uVar10 = uVar9 >> 1;
            } while ((uVar8 & uVar10) == 0);
            uVar9 = uVar9 >> 2;
            if (uVar9 == 0) {
              uVar9 = 0x80000000;
              local_30 = param_3[1] + -2;
            }
          }
          local_2c = local_30 << 2;
          if (-1 < local_30) {
            while( true ) {
              uVar8 = *(uint *)(iVar3 + local_2c);
              do {
                uVar10 = uVar8 & uVar9;
                uVar9 = uVar9 >> 1;
                if (uVar10 == 0) {
                  iVar4 = gf2m_Madd(param_1,iVar12,iVar7,iVar13,iVar1,iVar2,param_5);
                  iVar3 = iVar2;
                  iVar6 = iVar1;
                }
                else {
                  iVar4 = gf2m_Madd(param_1,iVar12,iVar1,iVar2,iVar7,iVar13,param_5);
                  iVar3 = iVar13;
                  iVar6 = iVar7;
                }
                if ((iVar4 == 0) || (iVar3 = gf2m_Mdouble(param_1,iVar6,iVar3,param_5), iVar3 == 0))
                goto LAB_005f6330;
              } while (uVar9 != 0);
              local_2c = local_2c + -4;
              local_30 = local_30 + -1;
              if (local_30 == -1) break;
              iVar3 = *param_3;
              uVar9 = 0x80000000;
            }
          }
          param_4 = param_4 + 0x18;
          if (*(int *)(iVar2 + 4) == 0) {
            (*(code *)PTR_BN_set_word_006a8820)(iVar7,0);
            (*(code *)PTR_BN_set_word_006a8820)(iVar13,0);
            iVar1 = (*(code *)PTR_EC_POINT_set_to_infinity_006a972c)(param_1,param_2);
            if (iVar1 != 0) {
LAB_005f65a8:
              uVar11 = 1;
              (*(code *)PTR_BN_set_negative_006a96e8)(iVar7,0);
              (*(code *)PTR_BN_set_negative_006a96e8)(iVar13,0);
              goto LAB_005f6334;
            }
          }
          else if (*(int *)(param_2 + 0x1c) == 0) {
            iVar1 = (*(code *)PTR_BN_copy_006a9570)(iVar7,iVar12);
            if ((iVar1 != 0) &&
               (iVar1 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(iVar13,iVar12,param_4), iVar1 != 0)) {
LAB_005f6584:
              iVar1 = (*(code *)PTR_BN_set_word_006a8820)(param_2 + 0x2c,1);
              if (iVar1 != 0) {
                *(undefined4 *)(param_2 + 0x40) = 1;
                goto LAB_005f65a8;
              }
            }
          }
          else {
            (*(code *)PTR_BN_CTX_start_006a9644)(param_5);
            uVar11 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
            uVar5 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
            iVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(param_5);
            if (((((((iVar3 != 0) &&
                    (iVar6 = (*(code *)PTR_BN_set_word_006a8820)(iVar3,1), iVar6 != 0)) &&
                   (iVar6 = (**(code **)(*param_1 + 0x84))(param_1,uVar11,iVar2,iVar13,param_5),
                   iVar6 != 0)) &&
                  ((iVar6 = (**(code **)(*param_1 + 0x84))(param_1,iVar2,iVar2,iVar12,param_5),
                   iVar6 != 0 &&
                   (iVar6 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(iVar2,iVar2,iVar1), iVar6 != 0))))
                 && (((iVar6 = (**(code **)(*param_1 + 0x84))(param_1,iVar13,iVar13,iVar12,param_5),
                      iVar6 != 0 &&
                      ((iVar6 = (**(code **)(*param_1 + 0x84))(param_1,iVar1,iVar13,iVar1,param_5),
                       iVar6 != 0 &&
                       (iVar6 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(iVar13,iVar13,iVar7), iVar6 != 0
                       )))) && (iVar2 = (**(code **)(*param_1 + 0x84))
                                                  (param_1,iVar13,iVar13,iVar2,param_5), iVar2 != 0)
                     ))) &&
                ((((iVar2 = (**(code **)(*param_1 + 0x88))(param_1,uVar5,iVar12,param_5), iVar2 != 0
                   && (iVar2 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(uVar5,uVar5,param_4), iVar2 != 0)
                   ) && (iVar2 = (**(code **)(*param_1 + 0x84))(param_1,uVar5,uVar5,uVar11,param_5),
                        iVar2 != 0)) &&
                 (((iVar2 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(uVar5,uVar5,iVar13), iVar2 != 0 &&
                   (iVar2 = (**(code **)(*param_1 + 0x84))(param_1,uVar11,uVar11,iVar12,param_5),
                   iVar2 != 0)) &&
                  ((iVar2 = (**(code **)(*param_1 + 0x8c))(param_1,uVar11,iVar3,uVar11,param_5),
                   iVar2 != 0 &&
                   ((iVar2 = (**(code **)(*param_1 + 0x84))(param_1,uVar5,uVar11,uVar5,param_5),
                    iVar2 != 0 &&
                    (iVar1 = (**(code **)(*param_1 + 0x84))(param_1,iVar7,iVar1,uVar11,param_5),
                    iVar1 != 0)))))))))) &&
               ((iVar1 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(iVar13,iVar7,iVar12), iVar1 != 0 &&
                ((iVar1 = (**(code **)(*param_1 + 0x84))(param_1,iVar13,iVar13,uVar5,param_5),
                 iVar1 != 0 &&
                 (iVar1 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(iVar13,iVar13,param_4), iVar1 != 0))))
               )) {
              (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
              goto LAB_005f6584;
            }
            (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
          }
        }
      }
    }
  }
LAB_005f6330:
  uVar11 = 0;
LAB_005f6334:
  (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
  return uVar11;
}

