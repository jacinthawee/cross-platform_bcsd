
int * gost2001_do_sign(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int local_3c;
  int *local_2c;
  
  iVar2 = (*(code *)PTR_hashsum2bn_006a9850)();
  iVar3 = (*(code *)PTR_BN_CTX_new_006a794c)();
  if (iVar3 == 0) {
    ERR_GOST_error(0x69,0x41,"gost2001.c",0x8a);
    if (iVar2 == 0) {
      return (int *)0x0;
    }
    local_2c = (int *)0x0;
  }
  else {
    if (iVar2 == 0) {
      ERR_GOST_error(0x69,0x41,"gost2001.c",0x8a);
      (*(code *)PTR_BN_CTX_end_006a8530)(iVar3);
      (*(code *)PTR_BN_CTX_free_006a7954)(iVar3);
      return (int *)0x0;
    }
    (*(code *)PTR_BN_CTX_start_006a8528)(iVar3);
    if (param_2 != 0x20) {
      (*(code *)PTR_OpenSSLDie_006a7c5c)("gost2001.c",0x8e,"dlen == 32");
    }
    local_2c = (int *)(*(code *)PTR_DSA_SIG_new_006a875c)();
    if (local_2c == (int *)0x0) {
      ERR_GOST_error(0x69,0x76,"gost2001.c",0x91);
    }
    else {
      iVar4 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(param_3);
      if (iVar4 == 0) {
        uVar11 = 0x96;
      }
      else {
        iVar5 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar3);
        if ((iVar5 == 0) ||
           (iVar6 = (*(code *)PTR_EC_GROUP_get_order_006a71ec)(iVar4,iVar5,iVar3), iVar6 == 0)) {
          uVar11 = 0x9b;
        }
        else {
          iVar6 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(param_3);
          if (iVar6 == 0) {
            uVar11 = 0xa0;
          }
          else {
            iVar7 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar3);
            if ((iVar7 != 0) &&
               (iVar8 = (*(code *)PTR_BN_div_006a855c)(0,iVar7,iVar2,iVar5,iVar3), iVar8 != 0)) {
              if (*(int *)(iVar7 + 4) == 0) {
                (*(code *)PTR_BN_set_word_006a7730)(iVar7,1);
              }
              iVar8 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar3);
              iVar9 = (*(code *)PTR_EC_POINT_new_006a7fc0)(iVar4);
              if ((iVar8 == 0) || (iVar15 = 0, iVar9 == 0)) {
                piVar12 = (int *)0x0;
                ERR_GOST_error(0x69,0x41,"gost2001.c",0xb5);
                (*(code *)PTR_BN_CTX_end_006a8530)(iVar3);
                (*(code *)PTR_BN_CTX_free_006a7954)(iVar3);
                if (iVar9 != 0) goto LAB_006130b4;
              }
              else {
                local_3c = 0;
                iVar14 = 0;
                iVar16 = 0;
                iVar13 = 0;
                do {
                  do {
                    iVar10 = (*(code *)PTR_BN_rand_range_006a868c)(iVar8,iVar5);
                    if (iVar10 == 0) {
                      piVar12 = (int *)0x0;
                      ERR_GOST_error(0x69,0x7d,"gost2001.c",0xbc);
                      goto LAB_00613094;
                    }
                    iVar10 = (*(code *)PTR_EC_POINT_mul_006a8648)(iVar4,iVar9,iVar8,0,0,iVar3);
                    if (iVar10 == 0) {
                      uVar11 = 0xc0;
LAB_00613294:
                      piVar12 = (int *)0x0;
                      ERR_GOST_error(0x69,0x10,"gost2001.c",uVar11);
                      goto LAB_00613094;
                    }
                    if (iVar14 == 0) {
                      iVar14 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar3);
                      iVar10 = iVar14;
                      if (iVar13 != 0) goto joined_r0x00613068;
                      iVar13 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar3);
                      if (iVar14 == 0) {
LAB_00613074:
                        uVar11 = 200;
                      }
                      else {
                        if (iVar13 != 0) goto LAB_00612f18;
                        uVar11 = 200;
                      }
                      goto LAB_00613078;
                    }
                    if (iVar13 == 0) {
                      iVar13 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar3);
                      iVar10 = iVar13;
joined_r0x00613068:
                      if (iVar10 == 0) goto LAB_00613074;
                    }
LAB_00612f18:
                    iVar10 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a8698)
                                       (iVar4,iVar9,iVar14,0,iVar3);
                    if (iVar10 == 0) {
                      uVar11 = 0xcc;
                      goto LAB_00613294;
                    }
                    iVar10 = (*(code *)PTR_BN_nnmod_006a8548)(iVar13,iVar14,iVar5,iVar3);
                    if (iVar10 == 0) {
                      uVar11 = 0xd1;
LAB_00613238:
                      piVar12 = (int *)0x0;
                      ERR_GOST_error(0x69,0x44,"gost2001.c",uVar11);
                      goto LAB_00613094;
                    }
                  } while (*(int *)(iVar13 + 4) == 0);
                  if (iVar15 == 0) {
                    iVar15 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar3);
                  }
                  if (local_3c == 0) {
                    local_3c = (*(code *)PTR_BN_CTX_get_006a852c)(iVar3);
                  }
                  if (iVar16 == 0) {
                    iVar16 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar3);
                  }
                  if (((iVar15 == 0) || (local_3c == 0)) || (iVar16 == 0)) {
                    uVar11 = 0xde;
                    goto LAB_00613078;
                  }
                  iVar10 = (*(code *)PTR_BN_mod_mul_006a8574)(iVar15,iVar6,iVar13,iVar5,iVar3);
                  if (((iVar10 == 0) ||
                      (iVar10 = (*(code *)PTR_BN_mod_mul_006a8574)(local_3c,iVar8,iVar7,iVar5,iVar3)
                      , iVar10 == 0)) ||
                     (iVar10 = (*(code *)PTR_BN_mod_add_006a9510)
                                         (iVar16,iVar15,local_3c,iVar5,iVar3), iVar10 == 0)) {
                    uVar11 = 0xe5;
                    goto LAB_00613238;
                  }
                } while (*(int *)(iVar16 + 4) == 0);
                iVar4 = (*(code *)PTR_BN_dup_006a8218)(iVar16);
                puVar1 = PTR_BN_dup_006a8218;
                local_2c[1] = iVar4;
                iVar4 = (*(code *)puVar1)(iVar13);
                *local_2c = iVar4;
                if ((local_2c[1] == 0) || (piVar12 = local_2c, iVar4 == 0)) {
                  uVar11 = 0xee;
LAB_00613078:
                  piVar12 = (int *)0x0;
                  ERR_GOST_error(0x69,0x41,"gost2001.c",uVar11);
                }
LAB_00613094:
                (*(code *)PTR_BN_CTX_end_006a8530)(iVar3);
                (*(code *)PTR_BN_CTX_free_006a7954)(iVar3);
LAB_006130b4:
                (*(code *)PTR_EC_POINT_free_006a7fac)(iVar9);
              }
              (*(code *)PTR_BN_free_006a701c)(iVar2);
              if (piVar12 != (int *)0x0) {
                return piVar12;
              }
              goto LAB_006130dc;
            }
            uVar11 = 0xa5;
          }
        }
      }
      ERR_GOST_error(0x69,0x44,"gost2001.c",uVar11);
    }
    (*(code *)PTR_BN_CTX_end_006a8530)(iVar3);
    (*(code *)PTR_BN_CTX_free_006a7954)(iVar3);
  }
  piVar12 = (int *)0x0;
  (*(code *)PTR_BN_free_006a701c)(iVar2);
LAB_006130dc:
  if (local_2c == (int *)0x0) {
    return (int *)0x0;
  }
  (*(code *)PTR_DSA_SIG_free_006a8758)(local_2c);
  return piVar12;
}

