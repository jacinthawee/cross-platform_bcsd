
undefined4 gost2001_do_verify(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  
  iVar1 = (*(code *)PTR_BN_CTX_new_006a794c)();
  iVar2 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(param_4);
  if (iVar1 == 0) {
    ERR_GOST_error(0x6a,0x44,"gost2001.c",0x112);
    return 0;
  }
  if (iVar2 == 0) {
    uVar14 = 0x112;
LAB_00613774:
    iVar12 = 0;
    ERR_GOST_error(0x6a,0x44,"gost2001.c",uVar14);
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a8528)(iVar1);
    iVar3 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar1);
    iVar4 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar1);
    iVar5 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar1);
    iVar6 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar1);
    iVar7 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar1);
    iVar8 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar1);
    iVar9 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar1);
    iVar10 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar1);
    if ((((iVar3 == 0) || (iVar4 == 0)) || (iVar5 == 0)) ||
       (((iVar6 == 0 || (iVar7 == 0)) || ((iVar8 == 0 || ((iVar9 == 0 || (iVar10 == 0)))))))) {
      iVar12 = 0;
      ERR_GOST_error(0x6a,0x41,"gost2001.c",0x120);
    }
    else {
      iVar11 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(param_4);
      if ((iVar11 == 0) ||
         (iVar12 = (*(code *)PTR_EC_GROUP_get_order_006a71ec)(iVar2,iVar3,iVar1), iVar12 == 0)) {
        uVar14 = 0x126;
        goto LAB_00613774;
      }
      if ((((*(int *)(param_3[1] + 4) == 0) || (*(int *)(*param_3 + 4) == 0)) ||
          (iVar12 = (*(code *)PTR_BN_cmp_006a7960)(param_3[1],iVar3), 0 < iVar12)) ||
         (iVar12 = (*(code *)PTR_BN_cmp_006a7960)(*param_3,iVar3), 0 < iVar12)) {
        iVar12 = 0;
        ERR_GOST_error(0x6a,0x7f,"gost2001.c",0x12d);
        goto LAB_006136dc;
      }
      iVar12 = (*(code *)PTR_hashsum2bn_006a9850)(param_1);
      if ((iVar12 == 0) ||
         (iVar13 = (*(code *)PTR_BN_div_006a855c)(0,iVar4,iVar12,iVar3,iVar1), iVar13 == 0)) {
        uVar14 = 0x134;
      }
      else if ((*(int *)(iVar4 + 4) == 0) &&
              (iVar13 = (*(code *)PTR_BN_set_word_006a7730)(iVar4,1), iVar13 == 0)) {
        uVar14 = 0x13e;
      }
      else {
        iVar4 = (*(code *)PTR_BN_mod_inverse_006a85f0)(iVar10,iVar4,iVar3,iVar1);
        if ((((iVar4 != 0) &&
             (iVar10 = (*(code *)PTR_BN_mod_mul_006a8574)(iVar5,param_3[1],iVar4,iVar3,iVar1),
             iVar10 != 0)) &&
            (iVar10 = (*(code *)PTR_BN_sub_006a85a8)(iVar7,iVar3,*param_3), iVar10 != 0)) &&
           (iVar4 = (*(code *)PTR_BN_mod_mul_006a8574)(iVar6,iVar7,iVar4,iVar3,iVar1), iVar4 != 0))
        {
          iVar4 = (*(code *)PTR_EC_POINT_new_006a7fc0)(iVar2);
          if (iVar4 == 0) {
            ERR_GOST_error(0x6a,0x41,"gost2001.c",0x153);
            goto LAB_006136dc;
          }
          iVar5 = (*(code *)PTR_EC_POINT_mul_006a8648)(iVar2,iVar4,iVar5,iVar11,iVar6,iVar1);
          if (iVar5 == 0) {
            uVar15 = 0x157;
LAB_00613888:
            uVar14 = 0;
            ERR_GOST_error(0x6a,0x10,"gost2001.c",uVar15);
          }
          else {
            iVar2 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a8698)
                              (iVar2,iVar4,iVar8,0,iVar1);
            if (iVar2 == 0) {
              uVar15 = 0x15b;
              goto LAB_00613888;
            }
            iVar2 = (*(code *)PTR_BN_div_006a855c)(0,iVar9,iVar8,iVar3,iVar1);
            if (iVar2 == 0) {
              uVar14 = 0;
              ERR_GOST_error(0x6a,0x44,"gost2001.c",0x15f);
            }
            else {
              iVar2 = (*(code *)PTR_BN_cmp_006a7960)(iVar9,*param_3);
              if (iVar2 == 0) {
                uVar14 = 1;
              }
              else {
                uVar14 = 0;
                ERR_GOST_error(0x6a,0x7e,"gost2001.c",0x16a);
              }
            }
          }
          (*(code *)PTR_EC_POINT_free_006a7fac)(iVar4);
          goto LAB_006136e0;
        }
        uVar14 = 0x146;
      }
      ERR_GOST_error(0x6a,0x44,"gost2001.c",uVar14);
    }
  }
LAB_006136dc:
  uVar14 = 0;
LAB_006136e0:
  (*(code *)PTR_BN_CTX_end_006a8530)(iVar1);
  (*(code *)PTR_BN_CTX_free_006a7954)(iVar1);
  if (iVar12 != 0) {
    (*(code *)PTR_BN_free_006a701c)(iVar12);
  }
  return uVar14;
}

