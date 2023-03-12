
EC_POINT * EC_POINT_hex2point(EC_GROUP *param_1,char *param_2,EC_POINT *param_3,BN_CTX *param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uchar *to;
  int *piVar4;
  int **ppiVar5;
  BIGNUM *pBVar6;
  BIGNUM *a;
  BIGNUM *a_00;
  undefined4 uVar7;
  int iVar8;
  EC_POINT *group;
  undefined4 *puVar9;
  int iVar10;
  BIGNUM *cofactor;
  undefined4 uVar11;
  size_t len;
  EC_POINT *p;
  int *piVar12;
  code *pcVar13;
  BIGNUM *local_28;
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_28 = (BIGNUM *)0x0;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = BN_hex2bn(&local_28,param_2);
  pBVar6 = local_28;
  if (iVar2 == 0) {
    param_3 = (EC_POINT *)0x0;
  }
  else {
    iVar3 = BN_num_bits(local_28);
    iVar2 = iVar3 + 7;
    if (iVar3 + 7 < 0) {
      iVar2 = iVar3 + 0xe;
    }
    len = iVar2 >> 3;
    if ((len == 0) ||
       (to = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(len,"ec_print.c",0x5f),
       to == (uchar *)0x0)) {
LAB_00505d94:
      param_3 = (EC_POINT *)0x0;
    }
    else {
      iVar2 = BN_bn2bin(pBVar6,to);
      if (iVar2 == 0) {
LAB_00505d84:
        (*(code *)PTR_CRYPTO_free_006a6e88)(to);
        goto LAB_00505d94;
      }
      if (param_3 == (EC_POINT *)0x0) {
        param_3 = EC_POINT_new(param_1);
        if ((param_3 != (EC_POINT *)0x0) &&
           (iVar2 = EC_POINT_oct2point(param_1,param_3,to,len,param_4), iVar2 == 0)) {
          EC_POINT_clear_free(param_3);
          goto LAB_00505d84;
        }
      }
      else {
        iVar2 = EC_POINT_oct2point(param_1,param_3,to,len,param_4);
        if (iVar2 == 0) goto LAB_00505d84;
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)(to);
    }
    BN_clear_free(local_28);
  }
  if (local_24 == *(int *)puVar1) {
    return param_3;
  }
  iVar2 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  piVar4 = *(int **)(iVar2 + 4);
  if (((piVar4 == (int *)0x0) || (*piVar4 == 0)) || (piVar4[1] == 0)) {
    uVar11 = 0x73;
    uVar7 = 700;
LAB_00505f88:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9d,uVar11,"ec_asn1.c",uVar7);
    return (EC_POINT *)0x0;
  }
  ppiVar5 = *(int ***)(iVar2 + 8);
  if (((ppiVar5 == (int **)0x0) || (piVar4 = *ppiVar5, piVar4 == (int *)0x0)) ||
     (((uchar *)piVar4[2] == (uchar *)0x0 || ((ppiVar5[1] == (int *)0x0 || (ppiVar5[1][2] == 0))))))
  {
    uVar11 = 0x73;
    uVar7 = 0x2c4;
    goto LAB_00505f88;
  }
  pBVar6 = BN_bin2bn((uchar *)piVar4[2],*piVar4,(BIGNUM *)0x0);
  if (pBVar6 == (BIGNUM *)0x0) {
    uVar11 = 3;
    uVar7 = 0x2c9;
    goto LAB_00505f88;
  }
  piVar4 = *(int **)(*(int *)(iVar2 + 8) + 4);
  a = BN_bin2bn((uchar *)piVar4[2],*piVar4,(BIGNUM *)0x0);
  if (a == (BIGNUM *)0x0) {
    uVar11 = 3;
    uVar7 = 0x2ce;
    goto LAB_00505ff0;
  }
  iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(**(undefined4 **)(iVar2 + 4));
  if (iVar3 == 0x197) {
    piVar4 = *(int **)(*(int *)(iVar2 + 4) + 4);
    iVar3 = *piVar4;
    if (0x295 < iVar3) {
      uVar11 = 0x8f;
      uVar7 = 0x2e2;
      goto LAB_00505ff0;
    }
    a_00 = BN_new();
    if (a_00 == (BIGNUM *)0x0) {
      uVar11 = 0x41;
      uVar7 = 0x2e7;
      goto LAB_00505ff0;
    }
    iVar10 = (*(code *)PTR_OBJ_obj2nid_006a712c)(piVar4[1]);
    if (iVar10 == 0x2aa) {
      if (piVar4[2] == 0) {
        uVar11 = 0x73;
        uVar7 = 0x2f2;
        goto LAB_00505ef4;
      }
      iVar10 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)();
      if ((*piVar4 <= iVar10) || (iVar10 < 1)) {
        uVar11 = 0x89;
        uVar7 = 0x2fa;
        goto LAB_00505ef4;
      }
      iVar8 = BN_set_bit(a_00,*piVar4);
      if (iVar8 != 0) {
        iVar10 = BN_set_bit(a_00,iVar10);
joined_r0x00506398:
        if ((iVar10 != 0) &&
           (iVar10 = BN_set_bit(a_00,0), pcVar13 = (code *)PTR_EC_GROUP_new_curve_GF2m_006a8630,
           iVar10 != 0)) goto LAB_00506190;
      }
    }
    else {
      if (iVar10 == 0x2ab) {
        piVar12 = (int *)piVar4[2];
        if (piVar12 == (int *)0x0) {
          uVar11 = 0x73;
          uVar7 = 0x30a;
        }
        else {
          if ((((piVar12[2] < *piVar4) && (piVar12[1] < piVar12[2])) && (*piVar12 < piVar12[1])) &&
             (0 < *piVar12)) {
            iVar10 = BN_set_bit(a_00,*piVar4);
            if (((iVar10 != 0) && (iVar10 = BN_set_bit(a_00,*piVar12), iVar10 != 0)) &&
               (iVar10 = BN_set_bit(a_00,piVar12[1]), iVar10 != 0)) {
              iVar10 = BN_set_bit(a_00,piVar12[2]);
              goto joined_r0x00506398;
            }
            goto LAB_00505f08;
          }
          uVar11 = 0x84;
          uVar7 = 0x312;
        }
      }
      else if (iVar10 == 0x2a9) {
        uVar11 = 0x7e;
        uVar7 = 0x322;
      }
      else {
        uVar11 = 0x73;
        uVar7 = 0x326;
      }
LAB_00505ef4:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9d,uVar11,"ec_asn1.c",uVar7);
    }
LAB_00505f08:
    p = (EC_POINT *)0x0;
    group = (EC_POINT *)0x0;
LAB_00505f10:
    BN_free(a_00);
    if (pBVar6 == (BIGNUM *)0x0) goto LAB_00505f24;
  }
  else {
    if (iVar3 == 0x196) {
      iVar3 = *(int *)(*(int *)(iVar2 + 4) + 4);
      if (iVar3 == 0) {
        uVar11 = 0x73;
        uVar7 = 0x332;
      }
      else {
        a_00 = (BIGNUM *)(*(code *)PTR_ASN1_INTEGER_to_BN_006a7014)(iVar3,0);
        if (a_00 != (BIGNUM *)0x0) {
          if ((a_00->neg != 0) || (a_00->top == 0)) {
            uVar11 = 0x67;
            uVar7 = 0x33c;
            goto LAB_00505ef4;
          }
          iVar3 = BN_num_bits(a_00);
          pcVar13 = (code *)PTR_EC_GROUP_new_curve_GFp_006a8638;
          if (0x295 < iVar3) {
            uVar11 = 0x8f;
            uVar7 = 0x342;
            goto LAB_00505ef4;
          }
LAB_00506190:
          group = (EC_POINT *)(*pcVar13)(a_00,pBVar6,a,0);
          if (group == (EC_POINT *)0x0) {
            p = (EC_POINT *)0x0;
            (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9d,0x10,"ec_asn1.c",0x34e);
          }
          else {
            puVar9 = *(undefined4 **)(*(int *)(iVar2 + 8) + 8);
            if (puVar9 == (undefined4 *)0x0) {
LAB_00506234:
              if (((*(int *)(iVar2 + 0x10) == 0) || (*(int *)(iVar2 + 0xc) == 0)) ||
                 (*(int *)(*(int *)(iVar2 + 0xc) + 8) == 0)) {
                p = (EC_POINT *)0x0;
                (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9d,0x73,"ec_asn1.c",0x360);
              }
              else {
                p = EC_POINT_new((EC_GROUP *)group);
                if (p != (EC_POINT *)0x0) {
                  EC_GROUP_set_point_conversion_form
                            ((EC_GROUP *)group,**(byte **)(*(int *)(iVar2 + 0xc) + 8) & 0xfe);
                  iVar10 = EC_POINT_oct2point((EC_GROUP *)group,p,
                                              (uchar *)(*(size_t **)(iVar2 + 0xc))[2],
                                              **(size_t **)(iVar2 + 0xc),(BN_CTX *)0x0);
                  if (iVar10 == 0) {
                    uVar11 = 0x10;
                    uVar7 = 0x36e;
                  }
                  else {
                    pBVar6 = (BIGNUM *)
                             (*(code *)PTR_ASN1_INTEGER_to_BN_006a7014)
                                       (*(undefined4 *)(iVar2 + 0x10),pBVar6);
                    if (pBVar6 == (BIGNUM *)0x0) {
                      uVar11 = 0xd;
                      uVar7 = 0x374;
                    }
                    else if ((pBVar6->neg == 0) && (pBVar6->top != 0)) {
                      iVar10 = BN_num_bits(pBVar6);
                      if (iVar3 + 1 < iVar10) {
                        uVar11 = 0x7a;
                        uVar7 = 0x37c;
                      }
                      else {
                        if (*(int *)(iVar2 + 0x14) == 0) {
                          cofactor = (BIGNUM *)0x0;
                          BN_free(a);
                        }
                        else {
                          cofactor = (BIGNUM *)
                                     (*(code *)PTR_ASN1_INTEGER_to_BN_006a7014)
                                               (*(int *)(iVar2 + 0x14),a);
                          if (cofactor == (BIGNUM *)0x0) {
                            uVar11 = 0xd;
                            uVar7 = 0x387;
                            a = cofactor;
                            goto LAB_005062c8;
                          }
                        }
                        iVar2 = EC_GROUP_set_generator((EC_GROUP *)group,p,pBVar6,cofactor);
                        a = cofactor;
                        if (iVar2 != 0) goto LAB_00505f10;
                        uVar11 = 0x10;
                        uVar7 = 0x38c;
                      }
                    }
                    else {
                      uVar11 = 0x7a;
                      uVar7 = 0x378;
                    }
                  }
LAB_005062c8:
                  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9d,uVar11,"ec_asn1.c",uVar7);
                }
              }
            }
            else {
              if (*(int *)((EC_GROUP *)group + 0x3c) != 0) {
                (*(code *)PTR_CRYPTO_free_006a6e88)();
                puVar9 = *(undefined4 **)(*(int *)(iVar2 + 8) + 8);
              }
              iVar10 = (*(code *)PTR_CRYPTO_malloc_006a7008)(*puVar9,"ec_asn1.c",0x356);
              *(int *)((EC_GROUP *)group + 0x3c) = iVar10;
              if (iVar10 != 0) {
                puVar9 = *(undefined4 **)(*(int *)(iVar2 + 8) + 8);
                (*(code *)PTR_memcpy_006a9aec)(iVar10,puVar9[2],*puVar9);
                *(undefined4 *)((EC_GROUP *)group + 0x40) =
                     **(undefined4 **)(*(int *)(iVar2 + 8) + 8);
                goto LAB_00506234;
              }
              p = (EC_POINT *)0x0;
              (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9d,0x41,"ec_asn1.c",0x357);
            }
            EC_GROUP_clear_free((EC_GROUP *)group);
            group = (EC_POINT *)0x0;
          }
          goto LAB_00505f10;
        }
        uVar11 = 0xd;
        uVar7 = 0x337;
      }
    }
    else {
      uVar11 = 0x67;
      uVar7 = 0x349;
    }
LAB_00505ff0:
    p = (EC_POINT *)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9d,uVar11,"ec_asn1.c",uVar7);
    group = (EC_POINT *)0x0;
  }
  BN_free(pBVar6);
LAB_00505f24:
  if (a != (BIGNUM *)0x0) {
    BN_free(a);
  }
  if (p == (EC_POINT *)0x0) {
    return group;
  }
  EC_POINT_free(p);
  return group;
}

