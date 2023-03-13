
undefined4
ec_GF2m_montgomery_point_multiply_part_0
          (int *param_1,int param_2,int *param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint local_48;
  int local_34;
  int local_30;
  
  (*(code *)PTR_BN_CTX_start_006a8528)(param_5);
  iVar1 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
  iVar2 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
  if (iVar2 != 0) {
    iVar7 = param_1[0x13];
    iVar11 = param_2 + 4;
    iVar10 = param_2 + 0x18;
    if (*(int *)(iVar1 + 8) < iVar7) {
      (*(code *)PTR_bn_expand2_006a8524)(iVar1);
      iVar7 = param_1[0x13];
    }
    if (*(int *)(iVar2 + 8) < iVar7) {
      (*(code *)PTR_bn_expand2_006a8524)(iVar2);
      iVar7 = param_1[0x13];
    }
    if (*(int *)(param_2 + 0xc) < iVar7) {
      (*(code *)PTR_bn_expand2_006a8524)(iVar11);
      iVar7 = param_1[0x13];
    }
    if (*(int *)(param_2 + 0x20) < iVar7) {
      (*(code *)PTR_bn_expand2_006a8524)(iVar10);
    }
    iVar9 = param_4 + 4;
    iVar7 = (*(code *)PTR_BN_GF2m_mod_arr_006a9698)(iVar1,iVar9,param_1 + 0x17);
    if ((((iVar7 != 0) && (iVar7 = (*(code *)PTR_BN_set_word_006a7730)(iVar2,1), iVar7 != 0)) &&
        (iVar7 = (**(code **)(*param_1 + 0x88))(param_1,iVar10,iVar1,param_5), iVar7 != 0)) &&
       (iVar7 = (**(code **)(*param_1 + 0x88))(param_1,iVar11,iVar10,param_5), iVar7 != 0)) {
      iVar7 = (*(code *)PTR_BN_GF2m_add_006a96a8)(iVar11,iVar11,param_1 + 0x22);
      if (iVar7 != 0) {
        iVar7 = *param_3;
        local_34 = param_3[1] + -1;
        uVar6 = *(uint *)(iVar7 + local_34 * 4);
        uVar3 = 0x80000000;
        if ((int)uVar6 < 0) {
          local_48 = 0x40000000;
        }
        else {
          do {
            local_48 = uVar3;
            uVar3 = local_48 >> 1;
          } while ((uVar6 & uVar3) == 0);
          local_48 = local_48 >> 2;
          if (local_48 == 0) {
            local_34 = param_3[1] + -2;
            local_48 = 0x80000000;
          }
        }
        local_30 = local_34 << 2;
        if (-1 < local_34) {
          while( true ) {
            uVar3 = *(uint *)(iVar7 + local_30);
            do {
              uVar6 = uVar3 & local_48;
              (*(code *)PTR_BN_consttime_swap_006a96b0)(uVar6,iVar1,iVar11,param_1[0x13]);
              (*(code *)PTR_BN_consttime_swap_006a96b0)(uVar6,iVar2,iVar10,param_1[0x13]);
              (*(code *)PTR_BN_CTX_start_006a8528)(param_5);
              uVar8 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
              iVar7 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
              if (((((iVar7 == 0) ||
                    (iVar4 = (*(code *)PTR_BN_copy_006a8450)(uVar8,iVar9), iVar4 == 0)) ||
                   ((iVar4 = (**(code **)(*param_1 + 0x84))(param_1,iVar11,iVar11,iVar2,param_5),
                    iVar4 == 0 ||
                    ((iVar4 = (**(code **)(*param_1 + 0x84))(param_1,iVar10,iVar10,iVar1,param_5),
                     iVar4 == 0 ||
                     (iVar4 = (**(code **)(*param_1 + 0x84))(param_1,iVar7,iVar11,iVar10,param_5),
                     iVar4 == 0)))))) ||
                  (iVar4 = (*(code *)PTR_BN_GF2m_add_006a96a8)(iVar10,iVar10,iVar11), iVar4 == 0))
                 || (((iVar4 = (**(code **)(*param_1 + 0x88))(param_1,iVar10,iVar10,param_5),
                      iVar4 == 0 ||
                      (iVar4 = (**(code **)(*param_1 + 0x84))(param_1,iVar11,iVar10,uVar8,param_5),
                      iVar4 == 0)) ||
                     (iVar7 = (*(code *)PTR_BN_GF2m_add_006a96a8)(iVar11,iVar11,iVar7), iVar7 == 0))
                    )) goto LAB_005f41cc;
              (*(code *)PTR_BN_CTX_end_006a8530)(param_5);
              (*(code *)PTR_BN_CTX_start_006a8528)(param_5);
              iVar7 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
              if ((((iVar7 == 0) ||
                   (iVar4 = (**(code **)(*param_1 + 0x88))(param_1,iVar1,iVar1,param_5), iVar4 == 0)
                   ) || ((iVar4 = (**(code **)(*param_1 + 0x88))(param_1,iVar7,iVar2,param_5),
                         iVar4 == 0 ||
                         ((iVar4 = (**(code **)(*param_1 + 0x84))(param_1,iVar2,iVar1,iVar7,param_5)
                          , iVar4 == 0 ||
                          (iVar4 = (**(code **)(*param_1 + 0x88))(param_1,iVar1,iVar1,param_5),
                          iVar4 == 0)))))) ||
                 ((iVar4 = (**(code **)(*param_1 + 0x88))(param_1,iVar7,iVar7,param_5), iVar4 == 0
                  || ((iVar4 = (**(code **)(*param_1 + 0x84))
                                         (param_1,iVar7,param_1 + 0x22,iVar7,param_5), iVar4 == 0 ||
                      (iVar7 = (*(code *)PTR_BN_GF2m_add_006a96a8)(iVar1,iVar1,iVar7), iVar7 == 0)))
                  ))) goto LAB_005f41cc;
              local_48 = local_48 >> 1;
              (*(code *)PTR_BN_CTX_end_006a8530)(param_5);
              (*(code *)PTR_BN_consttime_swap_006a96b0)(uVar6,iVar1,iVar11,param_1[0x13]);
              (*(code *)PTR_BN_consttime_swap_006a96b0)(uVar6,iVar2,iVar10,param_1[0x13]);
            } while (local_48 != 0);
            local_30 = local_30 + -4;
            local_34 = local_34 + -1;
            if (local_34 == -1) break;
            iVar7 = *param_3;
            local_48 = 0x80000000;
          }
        }
        param_4 = param_4 + 0x18;
        if (*(int *)(iVar2 + 4) == 0) {
          (*(code *)PTR_BN_set_word_006a7730)(iVar11,0);
          (*(code *)PTR_BN_set_word_006a7730)(iVar10,0);
          iVar1 = (*(code *)PTR_EC_POINT_set_to_infinity_006a860c)(param_1,param_2);
          if (iVar1 != 0) goto LAB_005f4568;
        }
        else {
          if (*(int *)(param_2 + 0x1c) == 0) {
            iVar1 = (*(code *)PTR_BN_copy_006a8450)(iVar11,iVar9);
            if ((iVar1 == 0) ||
               (iVar1 = (*(code *)PTR_BN_GF2m_add_006a96a8)(iVar10,iVar9,param_4), iVar1 == 0))
            goto LAB_005f3fd0;
          }
          else {
            (*(code *)PTR_BN_CTX_start_006a8528)(param_5);
            uVar8 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
            uVar5 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
            iVar7 = (*(code *)PTR_BN_CTX_get_006a852c)(param_5);
            if ((((((iVar7 == 0) ||
                   (iVar4 = (*(code *)PTR_BN_set_word_006a7730)(iVar7,1), iVar4 == 0)) ||
                  (iVar4 = (**(code **)(*param_1 + 0x84))(param_1,uVar8,iVar2,iVar10,param_5),
                  iVar4 == 0)) ||
                 (((iVar4 = (**(code **)(*param_1 + 0x84))(param_1,iVar2,iVar2,iVar9,param_5),
                   iVar4 == 0 ||
                   (iVar4 = (*(code *)PTR_BN_GF2m_add_006a96a8)(iVar2,iVar2,iVar1), iVar4 == 0)) ||
                  ((iVar4 = (**(code **)(*param_1 + 0x84))(param_1,iVar10,iVar10,iVar9,param_5),
                   iVar4 == 0 ||
                   ((iVar4 = (**(code **)(*param_1 + 0x84))(param_1,iVar1,iVar10,iVar1,param_5),
                    iVar4 == 0 ||
                    (iVar4 = (*(code *)PTR_BN_GF2m_add_006a96a8)(iVar10,iVar10,iVar11), iVar4 == 0))
                   )))))) ||
                ((iVar2 = (**(code **)(*param_1 + 0x84))(param_1,iVar10,iVar10,iVar2,param_5),
                 iVar2 == 0 ||
                 (((((iVar2 = (**(code **)(*param_1 + 0x88))(param_1,uVar5,iVar9,param_5),
                     iVar2 == 0 ||
                     (iVar2 = (*(code *)PTR_BN_GF2m_add_006a96a8)(uVar5,uVar5,param_4), iVar2 == 0))
                    || (iVar2 = (**(code **)(*param_1 + 0x84))(param_1,uVar5,uVar5,uVar8,param_5),
                       iVar2 == 0)) ||
                   ((iVar2 = (*(code *)PTR_BN_GF2m_add_006a96a8)(uVar5,uVar5,iVar10), iVar2 == 0 ||
                    (iVar2 = (**(code **)(*param_1 + 0x84))(param_1,uVar8,uVar8,iVar9,param_5),
                    iVar2 == 0)))) ||
                  ((iVar2 = (**(code **)(*param_1 + 0x8c))(param_1,uVar8,iVar7,uVar8,param_5),
                   iVar2 == 0 ||
                   ((iVar2 = (**(code **)(*param_1 + 0x84))(param_1,uVar5,uVar8,uVar5,param_5),
                    iVar2 == 0 ||
                    (iVar1 = (**(code **)(*param_1 + 0x84))(param_1,iVar11,iVar1,uVar8,param_5),
                    iVar1 == 0)))))))))) ||
               ((iVar1 = (*(code *)PTR_BN_GF2m_add_006a96a8)(iVar10,iVar11,iVar9), iVar1 == 0 ||
                ((iVar1 = (**(code **)(*param_1 + 0x84))(param_1,iVar10,iVar10,uVar5,param_5),
                 iVar1 == 0 ||
                 (iVar1 = (*(code *)PTR_BN_GF2m_add_006a96a8)(iVar10,iVar10,param_4), iVar1 == 0))))
               )) {
LAB_005f41cc:
              uVar8 = 0;
              (*(code *)PTR_BN_CTX_end_006a8530)(param_5);
              goto LAB_005f3fd4;
            }
            (*(code *)PTR_BN_CTX_end_006a8530)(param_5);
          }
          iVar1 = (*(code *)PTR_BN_set_word_006a7730)(param_2 + 0x2c,1);
          if (iVar1 != 0) {
            *(undefined4 *)(param_2 + 0x40) = 1;
LAB_005f4568:
            uVar8 = 1;
            (*(code *)PTR_BN_set_negative_006a85c4)(iVar11,0);
            (*(code *)PTR_BN_set_negative_006a85c4)(iVar10,0);
            goto LAB_005f3fd4;
          }
        }
      }
    }
  }
LAB_005f3fd0:
  uVar8 = 0;
LAB_005f3fd4:
  (*(code *)PTR_BN_CTX_end_006a8530)(param_5);
  return uVar8;
}

