
bool BN_GF2m_mod_solve_quad_arr(undefined4 param_1,int *param_2,uint *param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  bool bVar12;
  int local_2c;
  
  if (*param_3 == 0) {
    (*(code *)PTR_BN_set_word_006a7730)(param_1,0);
    return true;
  }
  (*(code *)PTR_BN_CTX_start_006a8528)(param_4);
  piVar1 = (int *)(*(code *)PTR_BN_CTX_get_006a852c)(param_4);
  uVar2 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
  iVar3 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
  if (iVar3 != 0) {
    if (*param_3 == 0) {
      (*(code *)PTR_BN_set_word_006a7730)(piVar1,0);
    }
    else {
      if (param_2 != piVar1) {
        iVar9 = param_2[1];
        if (piVar1[2] < iVar9) {
          iVar9 = (*(code *)PTR_bn_expand2_006a8524)(piVar1);
          if (iVar9 == 0) goto LAB_00626678;
          iVar9 = param_2[1];
        }
        iVar7 = 0;
        if (0 < iVar9) {
          puVar8 = (undefined4 *)*param_2;
          puVar4 = (undefined4 *)*piVar1;
          do {
            iVar7 = iVar7 + 1;
            *puVar4 = *puVar8;
            iVar9 = param_2[1];
            puVar8 = puVar8 + 1;
            puVar4 = puVar4 + 1;
          } while (iVar7 < iVar9);
        }
        piVar1[1] = iVar9;
      }
      iVar9 = BN_GF2m_mod_arr_part_0(piVar1,param_3);
      if (iVar9 == 0) goto LAB_00626678;
    }
    if (piVar1[1] == 0) {
      bVar12 = true;
      (*(code *)PTR_BN_set_word_006a7730)(param_1,0);
      goto LAB_0062667c;
    }
    if ((*param_3 & 1) == 0) {
      uVar11 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
      uVar5 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
      iVar9 = (*(code *)PTR_BN_CTX_get_006a852c)(param_4);
      if (iVar9 != 0) {
        uVar10 = *param_3;
        local_2c = 0x32;
        do {
          iVar7 = (*(code *)PTR_BN_rand_006a85c8)(uVar11,uVar10,0,0);
          if (iVar7 == 0) goto LAB_00626678;
          if (*param_3 == 0) {
            (*(code *)PTR_BN_set_word_006a7730)(uVar11,0);
          }
          else {
            iVar7 = BN_GF2m_mod_arr_part_0(uVar11,param_3);
            if (iVar7 == 0) goto LAB_00626678;
          }
          (*(code *)PTR_BN_set_word_006a7730)(uVar2,0);
          iVar7 = (*(code *)PTR_BN_copy_006a8450)(iVar3,uVar11);
          if (iVar7 == 0) goto LAB_00626678;
          uVar10 = *param_3;
          iVar7 = 1;
          if (1 < (int)uVar10) {
            do {
              iVar6 = BN_GF2m_mod_sqr_arr(uVar2,uVar2,param_3,param_4);
              iVar7 = iVar7 + 1;
              if (iVar6 == 0) {
                bVar12 = false;
                goto LAB_0062667c;
              }
              iVar6 = BN_GF2m_mod_sqr_arr(uVar5,iVar3,param_3,param_4);
              if ((((iVar6 == 0) ||
                   (iVar6 = BN_GF2m_mod_mul_arr(iVar9,uVar5,piVar1,param_3,param_4), iVar6 == 0)) ||
                  (iVar6 = BN_GF2m_add(uVar2,uVar2,iVar9), iVar6 == 0)) ||
                 (iVar6 = BN_GF2m_add(iVar3,uVar5,uVar11), iVar6 == 0)) goto LAB_00626678;
              uVar10 = *param_3;
            } while (iVar7 < (int)uVar10);
          }
          if (*(int *)(iVar3 + 4) != 0) goto LAB_0062696c;
          local_2c = local_2c + -1;
        } while (local_2c != 0);
        uVar11 = 0x71;
        uVar2 = 0x4a6;
LAB_006269c8:
        (*(code *)PTR_ERR_put_error_006a7f34)(3,0x87,uVar11,"bn_gf2m.c",uVar2);
      }
    }
    else {
      iVar9 = (*(code *)PTR_BN_copy_006a8450)(uVar2,piVar1);
      if (iVar9 != 0) {
        iVar9 = 1;
        if (2 < (int)*param_3) {
          do {
            iVar7 = BN_GF2m_mod_sqr_arr(uVar2,uVar2,param_3,param_4);
            iVar9 = iVar9 + 1;
            if (iVar7 == 0) {
              bVar12 = false;
              goto LAB_0062667c;
            }
            iVar7 = BN_GF2m_mod_sqr_arr(uVar2,uVar2,param_3,param_4);
            if ((iVar7 == 0) || (iVar7 = BN_GF2m_add(uVar2,uVar2,piVar1), iVar7 == 0))
            goto LAB_00626678;
          } while (iVar9 <= (int)(*param_3 - 1) / 2);
        }
LAB_0062696c:
        iVar9 = BN_GF2m_mod_sqr_arr(iVar3,uVar2,param_3,param_4);
        if ((iVar9 != 0) && (iVar9 = BN_GF2m_add(iVar3,uVar2,iVar3), iVar9 != 0)) {
          iVar3 = (*(code *)PTR_BN_ucmp_006a7fb4)(iVar3,piVar1);
          if (iVar3 == 0) {
            iVar3 = (*(code *)PTR_BN_copy_006a8450)(param_1,uVar2);
            bVar12 = iVar3 != 0;
            goto LAB_0062667c;
          }
          uVar11 = 0x74;
          uVar2 = 0x4b0;
          goto LAB_006269c8;
        }
      }
    }
  }
LAB_00626678:
  bVar12 = false;
LAB_0062667c:
  (*(code *)PTR_BN_CTX_end_006a8530)(param_4);
  return bVar12;
}

