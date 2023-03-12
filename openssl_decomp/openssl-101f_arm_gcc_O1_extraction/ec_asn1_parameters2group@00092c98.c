
EC_POINT * ec_asn1_parameters2group(int param_1)

{
  BIGNUM *a;
  BIGNUM *b;
  int iVar1;
  ASN1_INTEGER *ai;
  BIGNUM *a_00;
  long n;
  int iVar2;
  EC_POINT *group;
  BIGNUM *pBVar3;
  int *piVar4;
  int **ppiVar5;
  size_t *psVar6;
  EC_POINT *p;
  int *piVar7;
  
  piVar4 = *(int **)(param_1 + 4);
  if (((piVar4 == (int *)0x0) || (*piVar4 == 0)) || (piVar4[1] == 0)) {
    iVar1 = 0x2f8;
LAB_00092d84:
    pBVar3 = (BIGNUM *)0x0;
    ERR_put_error(0x10,0x9d,0x73,"ec_asn1.c",iVar1);
    a = (BIGNUM *)0x0;
  }
  else {
    ppiVar5 = *(int ***)(param_1 + 8);
    if (((ppiVar5 == (int **)0x0) || (piVar4 = *ppiVar5, piVar4 == (int *)0x0)) ||
       (((uchar *)piVar4[2] == (uchar *)0x0 || ((ppiVar5[1] == (int *)0x0 || (ppiVar5[1][2] == 0))))
       )) {
      iVar1 = 0x301;
      goto LAB_00092d84;
    }
    a = BN_bin2bn((uchar *)piVar4[2],*piVar4,(BIGNUM *)0x0);
    if (a == (BIGNUM *)0x0) {
      ERR_put_error(0x10,0x9d,3,"ec_asn1.c",0x307);
      pBVar3 = a;
    }
    else {
      piVar4 = *(int **)(*(int *)(param_1 + 8) + 4);
      b = BN_bin2bn((uchar *)piVar4[2],*piVar4,(BIGNUM *)0x0);
      pBVar3 = b;
      if (b == (BIGNUM *)0x0) {
        ERR_put_error(0x10,0x9d,3,"ec_asn1.c",0x30d);
      }
      else {
        iVar1 = OBJ_obj2nid(**(ASN1_OBJECT ***)(param_1 + 4));
        if (iVar1 == 0x197) {
          piVar4 = *(int **)(*(int *)(param_1 + 4) + 4);
          iVar1 = *piVar4;
          if (iVar1 < 0x296) {
            a_00 = BN_new();
            if (a_00 != (BIGNUM *)0x0) {
              iVar2 = OBJ_obj2nid((ASN1_OBJECT *)piVar4[1]);
              if (iVar2 == 0x2aa) {
                iVar2 = 0x335;
                if ((ASN1_INTEGER *)piVar4[2] == (ASN1_INTEGER *)0x0) goto LAB_00092e0a;
                n = ASN1_INTEGER_get((ASN1_INTEGER *)piVar4[2]);
                if ((n < *piVar4) && (0 < n)) {
                  iVar2 = BN_set_bit(a_00,*piVar4);
                  if (iVar2 != 0) {
                    iVar2 = BN_set_bit(a_00,n);
joined_r0x00092ee6:
                    if ((iVar2 != 0) && (iVar2 = BN_set_bit(a_00,0), iVar2 != 0)) {
                      group = (EC_POINT *)EC_GROUP_new_curve_GF2m(a_00,a,b,0);
                      goto LAB_00092f06;
                    }
                  }
                }
                else {
                  ERR_put_error(0x10,0x9d,0x89,"ec_asn1.c",0x33d);
                }
              }
              else if (iVar2 == 0x2ab) {
                piVar7 = (int *)piVar4[2];
                iVar2 = 0x350;
                if (piVar7 == (int *)0x0) goto LAB_00092e0a;
                if ((((piVar7[2] < *piVar4) && (piVar7[1] < piVar7[2])) && (*piVar7 < piVar7[1])) &&
                   (0 < *piVar7)) {
                  iVar2 = BN_set_bit(a_00,*piVar4);
                  if (((iVar2 != 0) && (iVar2 = BN_set_bit(a_00,*piVar7), iVar2 != 0)) &&
                     (iVar2 = BN_set_bit(a_00,piVar7[1]), iVar2 != 0)) {
                    iVar2 = BN_set_bit(a_00,piVar7[2]);
                    goto joined_r0x00092ee6;
                  }
                }
                else {
                  ERR_put_error(0x10,0x9d,0x84,"ec_asn1.c",0x356);
                }
              }
              else if (iVar2 == 0x2a9) {
                ERR_put_error(0x10,0x9d,0x7e,"ec_asn1.c",0x363);
              }
              else {
                iVar2 = 0x368;
LAB_00092e0a:
                ERR_put_error(0x10,0x9d,0x73,"ec_asn1.c",iVar2);
              }
              goto LAB_00092d48;
            }
            ERR_put_error(0x10,0x9d,0x41,"ec_asn1.c",0x328);
          }
          else {
            ERR_put_error(0x10,0x9d,0x8f,"ec_asn1.c",0x322);
          }
        }
        else if (iVar1 == 0x196) {
          ai = *(ASN1_INTEGER **)(*(int *)(param_1 + 4) + 4);
          if (ai == (ASN1_INTEGER *)0x0) {
            ERR_put_error(0x10,0x9d,0x73,"ec_asn1.c",0x376);
          }
          else {
            a_00 = ASN1_INTEGER_to_BN(ai,(BIGNUM *)0x0);
            if (a_00 != (BIGNUM *)0x0) {
              if ((a_00->neg == 0) && (a_00->top != 0)) {
                iVar1 = BN_num_bits(a_00);
                if (0x295 < iVar1) {
                  ERR_put_error(0x10,0x9d,0x8f,"ec_asn1.c",0x389);
                  goto LAB_00092d48;
                }
                group = (EC_POINT *)EC_GROUP_new_curve_GFp(a_00,a,b,(BN_CTX *)0x0);
LAB_00092f06:
                if (group == (EC_POINT *)0x0) {
                  ERR_put_error(0x10,0x9d,0x10,"ec_asn1.c",0x398);
                  goto LAB_00092d48;
                }
                piVar4 = *(int **)(*(int *)(param_1 + 8) + 8);
                if (piVar4 == (int *)0x0) {
LAB_00092f4e:
                  if (((*(int *)(param_1 + 0x10) == 0) || (*(int *)(param_1 + 0xc) == 0)) ||
                     (*(int *)(*(int *)(param_1 + 0xc) + 8) == 0)) {
                    p = (EC_POINT *)0x0;
                    ERR_put_error(0x10,0x9d,0x73,"ec_asn1.c",0x3ae);
                    goto LAB_00092fb4;
                  }
                  p = EC_POINT_new((EC_GROUP *)group);
                  if (p == (EC_POINT *)0x0) goto LAB_00092fb4;
                  EC_GROUP_set_point_conversion_form
                            ((EC_GROUP *)group,**(byte **)(*(int *)(param_1 + 0xc) + 8) & 0xfe);
                  iVar2 = EC_POINT_oct2point((EC_GROUP *)group,p,
                                             (uchar *)(*(size_t **)(param_1 + 0xc))[2],
                                             **(size_t **)(param_1 + 0xc),(BN_CTX *)0x0);
                  if (iVar2 == 0) {
                    ERR_put_error(0x10,0x9d,0x10,"ec_asn1.c",0x3bc);
                    goto LAB_00092fb4;
                  }
                  a = ASN1_INTEGER_to_BN(*(ASN1_INTEGER **)(param_1 + 0x10),a);
                  if (a == (BIGNUM *)0x0) {
                    iVar1 = 0x3c3;
LAB_0009317a:
                    ERR_put_error(0x10,0x9d,0xd,"ec_asn1.c",iVar1);
                    pBVar3 = b;
                    goto LAB_00092fb4;
                  }
                  if ((a->neg != 0) || (a->top == 0)) {
                    iVar1 = 0x3c8;
LAB_000930e6:
                    ERR_put_error(0x10,0x9d,0x7a,"ec_asn1.c",iVar1);
                    goto LAB_00092fb4;
                  }
                  iVar2 = BN_num_bits(a);
                  if (iVar1 + 1 < iVar2) {
                    iVar1 = 0x3cd;
                    goto LAB_000930e6;
                  }
                  if (*(ASN1_INTEGER **)(param_1 + 0x14) == (ASN1_INTEGER *)0x0) {
                    pBVar3 = (BIGNUM *)0x0;
                    BN_free(b);
                  }
                  else {
                    pBVar3 = ASN1_INTEGER_to_BN(*(ASN1_INTEGER **)(param_1 + 0x14),b);
                    if (pBVar3 == (BIGNUM *)0x0) {
                      iVar1 = 0x3dd;
                      b = pBVar3;
                      goto LAB_0009317a;
                    }
                  }
                  iVar1 = EC_GROUP_set_generator((EC_GROUP *)group,p,a,pBVar3);
                  if (iVar1 == 0) {
                    ERR_put_error(0x10,0x9d,0x10,"ec_asn1.c",0x3e3);
                    goto LAB_00092fb4;
                  }
                }
                else {
                  if (*(void **)((EC_GROUP *)group + 0x3c) != (void *)0x0) {
                    CRYPTO_free(*(void **)((EC_GROUP *)group + 0x3c));
                    piVar4 = *(int **)(*(int *)(param_1 + 8) + 8);
                  }
                  p = (EC_POINT *)CRYPTO_malloc(*piVar4,"ec_asn1.c",0x3a1);
                  *(EC_POINT **)((EC_GROUP *)group + 0x3c) = p;
                  if (p != (EC_POINT *)0x0) {
                    psVar6 = *(size_t **)(*(int *)(param_1 + 8) + 8);
                    memcpy(p,(void *)psVar6[2],*psVar6);
                    *(undefined4 *)((EC_GROUP *)group + 0x40) =
                         **(undefined4 **)(*(int *)(param_1 + 8) + 8);
                    goto LAB_00092f4e;
                  }
                  ERR_put_error(0x10,0x9d,0x41,"ec_asn1.c",0x3a4);
LAB_00092fb4:
                  EC_GROUP_clear_free((EC_GROUP *)group);
                  group = (EC_POINT *)0x0;
                }
              }
              else {
                ERR_put_error(0x10,0x9d,0x67,"ec_asn1.c",0x382);
LAB_00092d48:
                p = (EC_POINT *)0x0;
                group = (EC_POINT *)0x0;
                if (a_00 == (BIGNUM *)0x0) goto LAB_00092d98;
              }
              BN_free(a_00);
              goto LAB_00092d58;
            }
            ERR_put_error(0x10,0x9d,0xd,"ec_asn1.c",0x37c);
          }
        }
        else {
          ERR_put_error(0x10,0x9d,0x67,"ec_asn1.c",0x392);
        }
      }
    }
  }
LAB_00092d98:
  p = (EC_POINT *)0x0;
  group = p;
LAB_00092d58:
  if (a != (BIGNUM *)0x0) {
    BN_free(a);
  }
  if (pBVar3 != (BIGNUM *)0x0) {
    BN_free(pBVar3);
  }
  if (p != (EC_POINT *)0x0) {
    EC_POINT_free(p);
  }
  return group;
}

