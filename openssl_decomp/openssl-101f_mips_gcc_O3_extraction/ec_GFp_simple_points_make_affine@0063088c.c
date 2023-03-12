
undefined4 ec_GFp_simple_points_make_affine(int *param_1,uint param_2,int *param_3,int param_4)

{
  undefined4 *puVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  int iVar17;
  int local_48;
  int local_40;
  int *local_3c;
  int local_38;
  
  if (param_2 == 0) {
    return 1;
  }
  if (param_4 == 0) {
    param_4 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if (param_4 == 0) {
      return 0;
    }
    (*(code *)PTR_BN_CTX_start_006a9644)(param_4);
    local_38 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    local_48 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    local_40 = param_4;
    if ((local_38 == 0) || (local_48 == 0)) {
      (*(code *)PTR_BN_CTX_end_006a9654)(param_4);
      goto LAB_00630d3c;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a9644)(param_4);
    local_38 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    local_48 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
    if ((local_38 == 0) || (local_48 == 0)) {
      (*(code *)PTR_BN_CTX_end_006a9654)(param_4);
      return 0;
    }
    local_40 = 0;
  }
  uVar13 = 1;
  if (param_2 < 2) {
    puVar3 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(8,"ecp_smpl.c",0x4c1);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = 0;
      uVar14 = 2;
      iVar17 = 0;
      uVar13 = 1;
      goto LAB_006309a8;
    }
  }
  else {
    do {
      uVar5 = uVar13;
      uVar13 = uVar5 << 1;
    } while (uVar5 << 1 < param_2);
    uVar14 = uVar5 << 2;
    puVar3 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uVar5 << 4,"ecp_smpl.c",0x4c1);
    if (puVar3 != (undefined4 *)0x0) {
      uVar13 = uVar14 >> 1;
      iVar17 = uVar13 - 1;
      *puVar3 = 0;
      if (iVar17 != 0) {
        (*(code *)PTR_memset_006aab00)(puVar3 + 1,0,uVar13 * 4 + -4);
      }
LAB_006309a8:
      piVar11 = puVar3 + uVar13;
      piVar4 = param_3;
      piVar8 = piVar11;
      do {
        iVar7 = *piVar4;
        piVar4 = piVar4 + 1;
        *piVar8 = iVar7 + 0x2c;
        piVar8 = piVar8 + 1;
      } while (piVar4 != param_3 + param_2);
      uVar5 = param_2 + uVar13;
      if (uVar5 < uVar14) {
        (*(code *)PTR_memset_006aab00)(puVar3 + uVar5,0,(uVar14 - uVar5) * 4);
      }
      piVar8 = piVar11 + uVar13;
      piVar4 = piVar11;
      iVar7 = iVar17;
      while (iVar7 != 0) {
        iVar7 = iVar7 + -1;
        piVar4 = piVar4 + -1;
        iVar6 = (*(code *)PTR_BN_new_006a82b4)();
        *piVar4 = iVar6;
        if (iVar6 == 0) goto LAB_00630ac8;
        iVar10 = piVar8[-2];
        if (iVar10 != 0) {
          iVar12 = piVar8[-1];
          iVar9 = iVar10;
          if (((iVar12 == 0) || (*(int *)(iVar12 + 4) == 0)) ||
             (iVar9 = iVar12, *(int *)(iVar10 + 4) == 0)) {
            iVar6 = (*(code *)PTR_BN_copy_006a9570)(iVar6,iVar9);
          }
          else {
            iVar6 = (**(code **)(*param_1 + 0x84))(param_1,iVar6,iVar10,iVar12,param_4);
          }
          if (iVar6 == 0) goto LAB_00630ac8;
        }
        piVar8 = piVar8 + -2;
      }
      iVar7 = puVar3[1];
      if ((*(int *)(iVar7 + 4) == 0) ||
         (iVar7 = (*(code *)PTR_BN_mod_inverse_006a9714)(iVar7,iVar7,param_1 + 0x12,param_4),
         iVar7 != 0)) {
        if ((*(code **)(*param_1 + 0x90) == (code *)0x0) ||
           ((iVar7 = (**(code **)(*param_1 + 0x90))(param_1,puVar3[1],puVar3[1],param_4), iVar7 != 0
            && (iVar7 = (**(code **)(*param_1 + 0x90))(param_1,puVar3[1],puVar3[1],param_4),
               iVar7 != 0)))) {
          uVar13 = 2;
          puVar1 = puVar3;
          if (2 < uVar5) {
            do {
              puVar16 = puVar1 + 2;
              iVar7 = puVar1[3];
              if ((iVar7 == 0) || (*(int *)(iVar7 + 4) == 0)) {
                iVar7 = (*(code *)PTR_BN_copy_006a9570)(*puVar16,puVar3[uVar13 >> 1]);
                if (iVar7 == 0) goto LAB_00630ac8;
              }
              else {
                iVar7 = (**(code **)(*param_1 + 0x84))
                                  (param_1,local_38,puVar3[uVar13 >> 1],iVar7,param_4);
                if (((iVar7 == 0) ||
                    (iVar7 = (**(code **)(*param_1 + 0x84))
                                       (param_1,local_48,puVar3[uVar13 >> 1],*puVar16,param_4),
                    iVar7 == 0)) ||
                   (iVar7 = (*(code *)PTR_BN_copy_006a9570)(*puVar16,local_38), iVar7 == 0))
                goto LAB_00630ac8;
                iVar7 = (*(code *)PTR_BN_copy_006a9570)(puVar1[3],local_48);
                if (iVar7 == 0) {
                  uVar15 = 0;
                  goto LAB_00630acc;
                }
              }
              uVar13 = uVar13 + 2;
              puVar1 = puVar16;
            } while (uVar13 < uVar5);
          }
          uVar13 = 0;
          local_3c = param_3;
          do {
            iVar7 = *local_3c;
            if (*(int *)(iVar7 + 0x30) != 0) {
              iVar10 = iVar7 + 0x2c;
              iVar6 = (**(code **)(*param_1 + 0x88))(param_1,local_48,iVar10,param_4);
              if ((iVar6 == 0) ||
                 (iVar6 = (**(code **)(*param_1 + 0x84))
                                    (param_1,iVar7 + 4,iVar7 + 4,local_48,param_4), iVar6 == 0))
              goto LAB_00630ac8;
              iVar6 = (**(code **)(*param_1 + 0x84))(param_1,local_48,local_48,iVar10,param_4);
              if ((iVar6 == 0) ||
                 (iVar6 = (**(code **)(*param_1 + 0x84))
                                    (param_1,iVar7 + 0x18,iVar7 + 0x18,local_48,param_4), iVar6 == 0
                 )) goto LAB_00630ac8;
              if (*(code **)(*param_1 + 0x98) == (code *)0x0) {
                iVar6 = (*(code *)PTR_BN_set_word_006a8820)(iVar10,1,param_4);
                if (iVar6 == 0) goto LAB_00630ac8;
                *(undefined4 *)(iVar7 + 0x40) = 1;
              }
              else {
                iVar6 = (**(code **)(*param_1 + 0x98))(param_1,iVar10);
                if (iVar6 == 0) goto LAB_00630ac8;
                *(undefined4 *)(iVar7 + 0x40) = 1;
              }
            }
            uVar13 = uVar13 + 1;
            local_3c = local_3c + 1;
          } while (param_2 != uVar13);
          uVar15 = 1;
        }
        else {
LAB_00630ac8:
          uVar15 = 0;
        }
      }
      else {
        uVar15 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x89,3,"ecp_smpl.c",0x4fa);
      }
LAB_00630acc:
      (*(code *)PTR_BN_CTX_end_006a9654)(param_4);
      pcVar2 = (code *)PTR_BN_CTX_free_006a8a40;
      while( true ) {
        if (local_40 != 0) {
          (*pcVar2)(local_40);
        }
        if (iVar17 == 0) break;
        local_40 = piVar11[-1];
        iVar17 = iVar17 + -1;
        piVar11 = piVar11 + -1;
        pcVar2 = (code *)PTR_BN_clear_free_006a9130;
      }
      (*(code *)PTR_CRYPTO_free_006a7f88)(puVar3);
      return uVar15;
    }
  }
  (*(code *)PTR_BN_CTX_end_006a9654)(param_4);
  if (local_40 == 0) {
    return 0;
  }
LAB_00630d3c:
  (*(code *)PTR_BN_CTX_free_006a8a40)(local_40);
  return 0;
}

