
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
    uVar4 = 0x2f8;
LAB_005082d8:
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9d,uVar8,"ec_asn1.c",uVar4);
    return (EC_GROUP *)0x0;
  }
  ppiVar2 = *(int ***)(param_1 + 8);
  if (((ppiVar2 == (int **)0x0) || (piVar1 = *ppiVar2, piVar1 == (int *)0x0)) ||
     (((uchar *)piVar1[2] == (uchar *)0x0 || ((ppiVar2[1] == (int *)0x0 || (ppiVar2[1][2] == 0))))))
  {
    uVar8 = 0x73;
    uVar4 = 0x301;
    goto LAB_005082d8;
  }
  a = BN_bin2bn((uchar *)piVar1[2],*piVar1,(BIGNUM *)0x0);
  if (a == (BIGNUM *)0x0) {
    uVar8 = 3;
    uVar4 = 0x307;
    goto LAB_005082d8;
  }
  piVar1 = *(int **)(*(int *)(param_1 + 8) + 4);
  a_00 = BN_bin2bn((uchar *)piVar1[2],*piVar1,(BIGNUM *)0x0);
  if (a_00 == (BIGNUM *)0x0) {
    uVar8 = 3;
    uVar4 = 0x30d;
    goto LAB_00508340;
  }
  iVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(**(undefined4 **)(param_1 + 4));
  if (iVar3 == 0x197) {
    piVar1 = *(int **)(*(int *)(param_1 + 4) + 4);
    iVar3 = *piVar1;
    if (0x295 < iVar3) {
      uVar8 = 0x8f;
      uVar4 = 0x322;
      goto LAB_00508340;
    }
    a_01 = BN_new();
    if (a_01 == (BIGNUM *)0x0) {
      uVar8 = 0x41;
      uVar4 = 0x328;
      goto LAB_00508340;
    }
    iVar7 = (*(code *)PTR_OBJ_obj2nid_006a822c)(piVar1[1]);
    if (iVar7 == 0x2aa) {
      if (piVar1[2] == 0) {
        uVar8 = 0x73;
        uVar4 = 0x335;
        goto LAB_00508244;
      }
      iVar7 = (*(code *)PTR_ASN1_INTEGER_get_006a831c)();
      if ((*piVar1 <= iVar7) || (iVar7 < 1)) {
        uVar8 = 0x89;
        uVar4 = 0x33d;
        goto LAB_00508244;
      }
      iVar5 = BN_set_bit(a_01,*piVar1);
      if (iVar5 != 0) {
        iVar7 = BN_set_bit(a_01,iVar7);
joined_r0x005086e8:
        if ((iVar7 != 0) &&
           (iVar7 = BN_set_bit(a_01,0), pcVar10 = (code *)PTR_EC_GROUP_new_curve_GF2m_006a9754,
           iVar7 != 0)) goto LAB_005084e0;
      }
    }
    else {
      if (iVar7 == 0x2ab) {
        piVar9 = (int *)piVar1[2];
        if (piVar9 == (int *)0x0) {
          uVar8 = 0x73;
          uVar4 = 0x350;
        }
        else {
          if ((((piVar9[2] < *piVar1) && (piVar9[1] < piVar9[2])) && (*piVar9 < piVar9[1])) &&
             (0 < *piVar9)) {
            iVar7 = BN_set_bit(a_01,*piVar1);
            if (((iVar7 != 0) && (iVar7 = BN_set_bit(a_01,*piVar9), iVar7 != 0)) &&
               (iVar7 = BN_set_bit(a_01,piVar9[1]), iVar7 != 0)) {
              iVar7 = BN_set_bit(a_01,piVar9[2]);
              goto joined_r0x005086e8;
            }
            goto LAB_00508258;
          }
          uVar8 = 0x84;
          uVar4 = 0x356;
        }
      }
      else if (iVar7 == 0x2a9) {
        uVar8 = 0x7e;
        uVar4 = 0x363;
      }
      else {
        uVar8 = 0x73;
        uVar4 = 0x368;
      }
LAB_00508244:
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9d,uVar8,"ec_asn1.c",uVar4);
    }
LAB_00508258:
    p = (EC_POINT *)0x0;
    group = (EC_GROUP *)0x0;
LAB_00508260:
    BN_free(a_01);
    if (a == (BIGNUM *)0x0) goto LAB_00508274;
  }
  else {
    if (iVar3 == 0x196) {
      iVar3 = *(int *)(*(int *)(param_1 + 4) + 4);
      if (iVar3 == 0) {
        uVar8 = 0x73;
        uVar4 = 0x376;
      }
      else {
        a_01 = (BIGNUM *)(*(code *)PTR_ASN1_INTEGER_to_BN_006a8114)(iVar3,0);
        if (a_01 != (BIGNUM *)0x0) {
          if ((a_01->neg != 0) || (a_01->top == 0)) {
            uVar8 = 0x67;
            uVar4 = 0x382;
            goto LAB_00508244;
          }
          iVar3 = BN_num_bits(a_01);
          pcVar10 = (code *)PTR_EC_GROUP_new_curve_GFp_006a975c;
          if (0x295 < iVar3) {
            uVar8 = 0x8f;
            uVar4 = 0x389;
            goto LAB_00508244;
          }
LAB_005084e0:
          group = (EC_GROUP *)(*pcVar10)(a_01,a,a_00,0);
          if (group == (EC_GROUP *)0x0) {
            p = (EC_POINT *)0x0;
            (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9d,0x10,"ec_asn1.c",0x398);
          }
          else {
            puVar6 = *(undefined4 **)(*(int *)(param_1 + 8) + 8);
            if (puVar6 == (undefined4 *)0x0) {
LAB_00508584:
              if (((*(int *)(param_1 + 0x10) == 0) || (*(int *)(param_1 + 0xc) == 0)) ||
                 (*(int *)(*(int *)(param_1 + 0xc) + 8) == 0)) {
                p = (EC_POINT *)0x0;
                (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9d,0x73,"ec_asn1.c",0x3ae);
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
                    uVar4 = 0x3bc;
                  }
                  else {
                    a = (BIGNUM *)
                        (*(code *)PTR_ASN1_INTEGER_to_BN_006a8114)
                                  (*(undefined4 *)(param_1 + 0x10),a);
                    if (a == (BIGNUM *)0x0) {
                      uVar8 = 0xd;
                      uVar4 = 0x3c3;
                    }
                    else if ((a->neg == 0) && (a->top != 0)) {
                      iVar7 = BN_num_bits(a);
                      if (iVar3 + 1 < iVar7) {
                        uVar8 = 0x7a;
                        uVar4 = 0x3cd;
                      }
                      else {
                        if (*(int *)(param_1 + 0x14) == 0) {
                          cofactor = (BIGNUM *)0x0;
                          BN_free(a_00);
                        }
                        else {
                          cofactor = (BIGNUM *)
                                     (*(code *)PTR_ASN1_INTEGER_to_BN_006a8114)
                                               (*(int *)(param_1 + 0x14),a_00);
                          if (cofactor == (BIGNUM *)0x0) {
                            uVar8 = 0xd;
                            uVar4 = 0x3dd;
                            a_00 = cofactor;
                            goto LAB_00508618;
                          }
                        }
                        iVar3 = EC_GROUP_set_generator(group,p,a,cofactor);
                        a_00 = cofactor;
                        if (iVar3 != 0) goto LAB_00508260;
                        uVar8 = 0x10;
                        uVar4 = 0x3e3;
                      }
                    }
                    else {
                      uVar8 = 0x7a;
                      uVar4 = 0x3c8;
                    }
                  }
LAB_00508618:
                  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9d,uVar8,"ec_asn1.c",uVar4);
                }
              }
            }
            else {
              if (*(int *)(group + 0x3c) != 0) {
                (*(code *)PTR_CRYPTO_free_006a7f88)();
                puVar6 = *(undefined4 **)(*(int *)(param_1 + 8) + 8);
              }
              iVar7 = (*(code *)PTR_CRYPTO_malloc_006a8108)(*puVar6,"ec_asn1.c",0x3a1);
              *(int *)(group + 0x3c) = iVar7;
              if (iVar7 != 0) {
                puVar6 = *(undefined4 **)(*(int *)(param_1 + 8) + 8);
                (*(code *)PTR_memcpy_006aabf4)(iVar7,puVar6[2],*puVar6);
                *(undefined4 *)(group + 0x40) = **(undefined4 **)(*(int *)(param_1 + 8) + 8);
                goto LAB_00508584;
              }
              p = (EC_POINT *)0x0;
              (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9d,0x41,"ec_asn1.c",0x3a4);
            }
            EC_GROUP_clear_free(group);
            group = (EC_GROUP *)0x0;
          }
          goto LAB_00508260;
        }
        uVar8 = 0xd;
        uVar4 = 0x37c;
      }
    }
    else {
      uVar8 = 0x67;
      uVar4 = 0x392;
    }
LAB_00508340:
    p = (EC_POINT *)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9d,uVar8,"ec_asn1.c",uVar4);
    group = (EC_GROUP *)0x0;
  }
  BN_free(a);
LAB_00508274:
  if (a_00 != (BIGNUM *)0x0) {
    BN_free(a_00);
  }
  if (p == (EC_POINT *)0x0) {
    return group;
  }
  EC_POINT_free(p);
  return group;
}

