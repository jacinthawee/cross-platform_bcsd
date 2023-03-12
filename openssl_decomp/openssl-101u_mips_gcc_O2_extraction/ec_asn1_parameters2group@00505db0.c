
EC_GROUP * ec_asn1_parameters2group(int param_1)

{
  int *piVar1;
  int **ppiVar2;
  BIGNUM *a;
  BIGNUM *a_00;
  int iVar3;
  BIGNUM *a_01;
  undefined4 uVar4;
  int iVar5;
  EC_GROUP *group;
  undefined4 *puVar6;
  int iVar7;
  BIGNUM *cofactor;
  undefined4 uVar8;
  EC_POINT *p;
  int *piVar9;
  code *pcVar10;
  
  piVar1 = *(int **)(param_1 + 4);
  if (((piVar1 == (int *)0x0) || (*piVar1 == 0)) || (piVar1[1] == 0)) {
    uVar8 = 0x73;
    uVar4 = 700;
LAB_00505f88:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9d,uVar8,"ec_asn1.c",uVar4);
    return (EC_GROUP *)0x0;
  }
  ppiVar2 = *(int ***)(param_1 + 8);
  if (((ppiVar2 == (int **)0x0) || (piVar1 = *ppiVar2, piVar1 == (int *)0x0)) ||
     (((uchar *)piVar1[2] == (uchar *)0x0 || ((ppiVar2[1] == (int *)0x0 || (ppiVar2[1][2] == 0))))))
  {
    uVar8 = 0x73;
    uVar4 = 0x2c4;
    goto LAB_00505f88;
  }
  a = BN_bin2bn((uchar *)piVar1[2],*piVar1,(BIGNUM *)0x0);
  if (a == (BIGNUM *)0x0) {
    uVar8 = 3;
    uVar4 = 0x2c9;
    goto LAB_00505f88;
  }
  piVar1 = *(int **)(*(int *)(param_1 + 8) + 4);
  a_00 = BN_bin2bn((uchar *)piVar1[2],*piVar1,(BIGNUM *)0x0);
  if (a_00 == (BIGNUM *)0x0) {
    uVar8 = 3;
    uVar4 = 0x2ce;
    goto LAB_00505ff0;
  }
  iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(**(undefined4 **)(param_1 + 4));
  if (iVar3 == 0x197) {
    piVar1 = *(int **)(*(int *)(param_1 + 4) + 4);
    iVar3 = *piVar1;
    if (0x295 < iVar3) {
      uVar8 = 0x8f;
      uVar4 = 0x2e2;
      goto LAB_00505ff0;
    }
    a_01 = BN_new();
    if (a_01 == (BIGNUM *)0x0) {
      uVar8 = 0x41;
      uVar4 = 0x2e7;
      goto LAB_00505ff0;
    }
    iVar7 = (*(code *)PTR_OBJ_obj2nid_006a712c)(piVar1[1]);
    if (iVar7 == 0x2aa) {
      if (piVar1[2] == 0) {
        uVar8 = 0x73;
        uVar4 = 0x2f2;
        goto LAB_00505ef4;
      }
      iVar7 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)();
      if ((*piVar1 <= iVar7) || (iVar7 < 1)) {
        uVar8 = 0x89;
        uVar4 = 0x2fa;
        goto LAB_00505ef4;
      }
      iVar5 = BN_set_bit(a_01,*piVar1);
      if (iVar5 != 0) {
        iVar7 = BN_set_bit(a_01,iVar7);
joined_r0x00506398:
        if ((iVar7 != 0) &&
           (iVar7 = BN_set_bit(a_01,0), pcVar10 = (code *)PTR_EC_GROUP_new_curve_GF2m_006a8630,
           iVar7 != 0)) goto LAB_00506190;
      }
    }
    else {
      if (iVar7 == 0x2ab) {
        piVar9 = (int *)piVar1[2];
        if (piVar9 == (int *)0x0) {
          uVar8 = 0x73;
          uVar4 = 0x30a;
        }
        else {
          if ((((piVar9[2] < *piVar1) && (piVar9[1] < piVar9[2])) && (*piVar9 < piVar9[1])) &&
             (0 < *piVar9)) {
            iVar7 = BN_set_bit(a_01,*piVar1);
            if (((iVar7 != 0) && (iVar7 = BN_set_bit(a_01,*piVar9), iVar7 != 0)) &&
               (iVar7 = BN_set_bit(a_01,piVar9[1]), iVar7 != 0)) {
              iVar7 = BN_set_bit(a_01,piVar9[2]);
              goto joined_r0x00506398;
            }
            goto LAB_00505f08;
          }
          uVar8 = 0x84;
          uVar4 = 0x312;
        }
      }
      else if (iVar7 == 0x2a9) {
        uVar8 = 0x7e;
        uVar4 = 0x322;
      }
      else {
        uVar8 = 0x73;
        uVar4 = 0x326;
      }
LAB_00505ef4:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9d,uVar8,"ec_asn1.c",uVar4);
    }
LAB_00505f08:
    p = (EC_POINT *)0x0;
    group = (EC_GROUP *)0x0;
LAB_00505f10:
    BN_free(a_01);
    if (a == (BIGNUM *)0x0) goto LAB_00505f24;
  }
  else {
    if (iVar3 == 0x196) {
      iVar3 = *(int *)(*(int *)(param_1 + 4) + 4);
      if (iVar3 == 0) {
        uVar8 = 0x73;
        uVar4 = 0x332;
      }
      else {
        a_01 = (BIGNUM *)(*(code *)PTR_ASN1_INTEGER_to_BN_006a7014)(iVar3,0);
        if (a_01 != (BIGNUM *)0x0) {
          if ((a_01->neg != 0) || (a_01->top == 0)) {
            uVar8 = 0x67;
            uVar4 = 0x33c;
            goto LAB_00505ef4;
          }
          iVar3 = BN_num_bits(a_01);
          pcVar10 = (code *)PTR_EC_GROUP_new_curve_GFp_006a8638;
          if (0x295 < iVar3) {
            uVar8 = 0x8f;
            uVar4 = 0x342;
            goto LAB_00505ef4;
          }
LAB_00506190:
          group = (EC_GROUP *)(*pcVar10)(a_01,a,a_00,0);
          if (group == (EC_GROUP *)0x0) {
            p = (EC_POINT *)0x0;
            (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9d,0x10,"ec_asn1.c",0x34e);
          }
          else {
            puVar6 = *(undefined4 **)(*(int *)(param_1 + 8) + 8);
            if (puVar6 == (undefined4 *)0x0) {
LAB_00506234:
              if (((*(int *)(param_1 + 0x10) == 0) || (*(int *)(param_1 + 0xc) == 0)) ||
                 (*(int *)(*(int *)(param_1 + 0xc) + 8) == 0)) {
                p = (EC_POINT *)0x0;
                (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9d,0x73,"ec_asn1.c",0x360);
              }
              else {
                p = EC_POINT_new(group);
                if (p != (EC_POINT *)0x0) {
                  EC_GROUP_set_point_conversion_form
                            (group,**(byte **)(*(int *)(param_1 + 0xc) + 8) & 0xfe);
                  iVar7 = EC_POINT_oct2point(group,p,(uchar *)(*(size_t **)(param_1 + 0xc))[2],
                                             **(size_t **)(param_1 + 0xc),(BN_CTX *)0x0);
                  if (iVar7 == 0) {
                    uVar8 = 0x10;
                    uVar4 = 0x36e;
                  }
                  else {
                    a = (BIGNUM *)
                        (*(code *)PTR_ASN1_INTEGER_to_BN_006a7014)
                                  (*(undefined4 *)(param_1 + 0x10),a);
                    if (a == (BIGNUM *)0x0) {
                      uVar8 = 0xd;
                      uVar4 = 0x374;
                    }
                    else if ((a->neg == 0) && (a->top != 0)) {
                      iVar7 = BN_num_bits(a);
                      if (iVar3 + 1 < iVar7) {
                        uVar8 = 0x7a;
                        uVar4 = 0x37c;
                      }
                      else {
                        if (*(int *)(param_1 + 0x14) == 0) {
                          cofactor = (BIGNUM *)0x0;
                          BN_free(a_00);
                        }
                        else {
                          cofactor = (BIGNUM *)
                                     (*(code *)PTR_ASN1_INTEGER_to_BN_006a7014)
                                               (*(int *)(param_1 + 0x14),a_00);
                          if (cofactor == (BIGNUM *)0x0) {
                            uVar8 = 0xd;
                            uVar4 = 0x387;
                            a_00 = cofactor;
                            goto LAB_005062c8;
                          }
                        }
                        iVar3 = EC_GROUP_set_generator(group,p,a,cofactor);
                        a_00 = cofactor;
                        if (iVar3 != 0) goto LAB_00505f10;
                        uVar8 = 0x10;
                        uVar4 = 0x38c;
                      }
                    }
                    else {
                      uVar8 = 0x7a;
                      uVar4 = 0x378;
                    }
                  }
LAB_005062c8:
                  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9d,uVar8,"ec_asn1.c",uVar4);
                }
              }
            }
            else {
              if (*(int *)(group + 0x3c) != 0) {
                (*(code *)PTR_CRYPTO_free_006a6e88)();
                puVar6 = *(undefined4 **)(*(int *)(param_1 + 8) + 8);
              }
              iVar7 = (*(code *)PTR_CRYPTO_malloc_006a7008)(*puVar6,"ec_asn1.c",0x356);
              *(int *)(group + 0x3c) = iVar7;
              if (iVar7 != 0) {
                puVar6 = *(undefined4 **)(*(int *)(param_1 + 8) + 8);
                (*(code *)PTR_memcpy_006a9aec)(iVar7,puVar6[2],*puVar6);
                *(undefined4 *)(group + 0x40) = **(undefined4 **)(*(int *)(param_1 + 8) + 8);
                goto LAB_00506234;
              }
              p = (EC_POINT *)0x0;
              (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9d,0x41,"ec_asn1.c",0x357);
            }
            EC_GROUP_clear_free(group);
            group = (EC_GROUP *)0x0;
          }
          goto LAB_00505f10;
        }
        uVar8 = 0xd;
        uVar4 = 0x337;
      }
    }
    else {
      uVar8 = 0x67;
      uVar4 = 0x349;
    }
LAB_00505ff0:
    p = (EC_POINT *)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9d,uVar8,"ec_asn1.c",uVar4);
    group = (EC_GROUP *)0x0;
  }
  BN_free(a);
LAB_00505f24:
  if (a_00 != (BIGNUM *)0x0) {
    BN_free(a_00);
  }
  if (p == (EC_POINT *)0x0) {
    return group;
  }
  EC_POINT_free(p);
  return group;
}

