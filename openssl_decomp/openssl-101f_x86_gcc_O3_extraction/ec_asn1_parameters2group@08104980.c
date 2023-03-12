
EC_GROUP * __regparm3 ec_asn1_parameters2group(int param_1)

{
  int **ppiVar1;
  ASN1_INTEGER *ai;
  size_t *psVar2;
  int *piVar3;
  BIGNUM *a;
  BIGNUM *b;
  int iVar4;
  int *piVar5;
  void *__dest;
  EC_GROUP *group;
  BIGNUM *cofactor;
  EC_POINT *p;
  int iVar6;
  BIGNUM *local_28;
  int local_24;
  
  piVar5 = *(int **)(param_1 + 4);
  if (((piVar5 == (int *)0x0) || (*piVar5 == 0)) || (piVar5[1] == 0)) {
    iVar4 = 0x2f8;
LAB_08104ae8:
    ERR_put_error(0x10,0x9d,0x73,"ec_asn1.c",iVar4);
    return (EC_GROUP *)0x0;
  }
  ppiVar1 = *(int ***)(param_1 + 8);
  if (((ppiVar1 == (int **)0x0) || (piVar5 = *ppiVar1, piVar5 == (int *)0x0)) ||
     (((uchar *)piVar5[2] == (uchar *)0x0 || ((ppiVar1[1] == (int *)0x0 || (ppiVar1[1][2] == 0))))))
  {
    iVar4 = 0x301;
    goto LAB_08104ae8;
  }
  a = BN_bin2bn((uchar *)piVar5[2],*piVar5,(BIGNUM *)0x0);
  if (a == (BIGNUM *)0x0) {
    ERR_put_error(0x10,0x9d,3,"ec_asn1.c",0x307);
    return (EC_GROUP *)0x0;
  }
  piVar5 = *(int **)(*(int *)(param_1 + 8) + 4);
  b = BN_bin2bn((uchar *)piVar5[2],*piVar5,(BIGNUM *)0x0);
  if (b == (BIGNUM *)0x0) {
    ERR_put_error(0x10,0x9d,3,"ec_asn1.c",0x30d);
LAB_08104b3e:
    group = (EC_GROUP *)0x0;
    p = (EC_POINT *)0x0;
  }
  else {
    iVar4 = OBJ_obj2nid(**(ASN1_OBJECT ***)(param_1 + 4));
    if (iVar4 == 0x197) {
      piVar5 = *(int **)(*(int *)(param_1 + 4) + 4);
      local_24 = *piVar5;
      if (local_24 < 0x296) {
        local_28 = BN_new();
        if (local_28 != (BIGNUM *)0x0) {
          iVar4 = OBJ_obj2nid((ASN1_OBJECT *)piVar5[1]);
          if (iVar4 == 0x2aa) {
            if ((ASN1_INTEGER *)piVar5[2] == (ASN1_INTEGER *)0x0) {
              iVar4 = 0x335;
              goto LAB_08104bef;
            }
            iVar4 = ASN1_INTEGER_get((ASN1_INTEGER *)piVar5[2]);
            if ((iVar4 < *piVar5) && (0 < iVar4)) {
              iVar6 = BN_set_bit(local_28,*piVar5);
              if (iVar6 != 0) {
LAB_08104d4d:
                iVar4 = BN_set_bit(local_28,iVar4);
                if ((iVar4 != 0) && (iVar4 = BN_set_bit(local_28,0), iVar4 != 0)) {
                  group = (EC_GROUP *)EC_GROUP_new_curve_GF2m(local_28,a,b,0);
                  goto LAB_08104d97;
                }
              }
            }
            else {
              ERR_put_error(0x10,0x9d,0x89,"ec_asn1.c",0x33d);
            }
          }
          else if (iVar4 == 0x2ab) {
            piVar3 = (int *)piVar5[2];
            if (piVar3 == (int *)0x0) {
              iVar4 = 0x350;
              goto LAB_08104bef;
            }
            if ((((piVar3[2] < *piVar5) && (piVar3[1] < piVar3[2])) && (0 < *piVar3)) &&
               (*piVar3 < piVar3[1])) {
              iVar4 = BN_set_bit(local_28,*piVar5);
              if (((iVar4 != 0) && (iVar4 = BN_set_bit(local_28,*piVar3), iVar4 != 0)) &&
                 (iVar4 = BN_set_bit(local_28,piVar3[1]), iVar4 != 0)) {
                iVar4 = piVar3[2];
                goto LAB_08104d4d;
              }
            }
            else {
              ERR_put_error(0x10,0x9d,0x84,"ec_asn1.c",0x356);
            }
          }
          else if (iVar4 == 0x2a9) {
            ERR_put_error(0x10,0x9d,0x7e,"ec_asn1.c",0x363);
          }
          else {
            iVar4 = 0x368;
LAB_08104bef:
            ERR_put_error(0x10,0x9d,0x73,"ec_asn1.c",iVar4);
          }
          goto LAB_08104abd;
        }
        ERR_put_error(0x10,0x9d,0x41,"ec_asn1.c",0x328);
      }
      else {
        ERR_put_error(0x10,0x9d,0x8f,"ec_asn1.c",0x322);
      }
      goto LAB_08104b3e;
    }
    if (iVar4 != 0x196) {
      ERR_put_error(0x10,0x9d,0x67,"ec_asn1.c",0x392);
      goto LAB_08104b3e;
    }
    ai = *(ASN1_INTEGER **)(*(int *)(param_1 + 4) + 4);
    if (ai == (ASN1_INTEGER *)0x0) {
      ERR_put_error(0x10,0x9d,0x73,"ec_asn1.c",0x376);
      goto LAB_08104b3e;
    }
    local_28 = ASN1_INTEGER_to_BN(ai,(BIGNUM *)0x0);
    if (local_28 == (BIGNUM *)0x0) {
      ERR_put_error(0x10,0x9d,0xd,"ec_asn1.c",0x37c);
      goto LAB_08104b3e;
    }
    if ((local_28->neg == 0) && (local_28->top != 0)) {
      local_24 = BN_num_bits(local_28);
      if (0x295 < local_24) {
        ERR_put_error(0x10,0x9d,0x8f,"ec_asn1.c",0x389);
        goto LAB_08104abd;
      }
      group = EC_GROUP_new_curve_GFp(local_28,a,b,(BN_CTX *)0x0);
LAB_08104d97:
      if (group == (EC_GROUP *)0x0) {
        p = (EC_POINT *)0x0;
        ERR_put_error(0x10,0x9d,0x10,"ec_asn1.c",0x398);
      }
      else {
        piVar5 = *(int **)(*(int *)(param_1 + 8) + 8);
        if (piVar5 == (int *)0x0) {
LAB_08104e1e:
          if (((*(int *)(param_1 + 0x10) == 0) || (*(int *)(param_1 + 0xc) == 0)) ||
             (*(int *)(*(int *)(param_1 + 0xc) + 8) == 0)) {
            iVar6 = 0x3ae;
            iVar4 = 0x73;
            goto LAB_08105034;
          }
          p = EC_POINT_new(group);
          if (p != (EC_POINT *)0x0) {
            EC_GROUP_set_point_conversion_form
                      (group,**(byte **)(*(int *)(param_1 + 0xc) + 8) & 0xfffffffe);
            iVar4 = EC_POINT_oct2point(group,p,(uchar *)(*(size_t **)(param_1 + 0xc))[2],
                                       **(size_t **)(param_1 + 0xc),(BN_CTX *)0x0);
            if (iVar4 == 0) {
              iVar4 = 0x3bc;
              cofactor = b;
LAB_08104ea0:
              ERR_put_error(0x10,0x9d,0x10,"ec_asn1.c",iVar4);
              b = cofactor;
            }
            else {
              a = ASN1_INTEGER_to_BN(*(ASN1_INTEGER **)(param_1 + 0x10),a);
              if (a == (BIGNUM *)0x0) {
                iVar4 = 0x3c3;
LAB_0810514d:
                ERR_put_error(0x10,0x9d,0xd,"ec_asn1.c",iVar4);
              }
              else {
                if ((a->neg == 0) && (a->top != 0)) {
                  iVar4 = BN_num_bits(a);
                  if (iVar4 <= local_24 + 1) {
                    if (*(ASN1_INTEGER **)(param_1 + 0x14) == (ASN1_INTEGER *)0x0) {
                      cofactor = (BIGNUM *)0x0;
                      BN_free(b);
                    }
                    else {
                      cofactor = ASN1_INTEGER_to_BN(*(ASN1_INTEGER **)(param_1 + 0x14),b);
                      if (cofactor == (BIGNUM *)0x0) {
                        iVar4 = 0x3dd;
                        b = cofactor;
                        goto LAB_0810514d;
                      }
                    }
                    iVar4 = EC_GROUP_set_generator(group,p,a,cofactor);
                    b = cofactor;
                    if (iVar4 != 0) goto LAB_08104ac8;
                    iVar4 = 0x3e3;
                    goto LAB_08104ea0;
                  }
                  iVar4 = 0x3cd;
                }
                else {
                  iVar4 = 0x3c8;
                }
                ERR_put_error(0x10,0x9d,0x7a,"ec_asn1.c",iVar4);
              }
            }
          }
        }
        else {
          if (*(void **)(group + 0x3c) != (void *)0x0) {
            CRYPTO_free(*(void **)(group + 0x3c));
            piVar5 = *(int **)(*(int *)(param_1 + 8) + 8);
          }
          __dest = CRYPTO_malloc(*piVar5,"ec_asn1.c",0x3a1);
          *(void **)(group + 0x3c) = __dest;
          if (__dest != (void *)0x0) {
            psVar2 = *(size_t **)(*(int *)(param_1 + 8) + 8);
            memcpy(__dest,(void *)psVar2[2],*psVar2);
            *(undefined4 *)(group + 0x40) = **(undefined4 **)(*(int *)(param_1 + 8) + 8);
            goto LAB_08104e1e;
          }
          iVar6 = 0x3a4;
          iVar4 = 0x41;
LAB_08105034:
          p = (EC_POINT *)0x0;
          ERR_put_error(0x10,0x9d,iVar4,"ec_asn1.c",iVar6);
        }
        EC_GROUP_clear_free(group);
        group = (EC_GROUP *)0x0;
      }
    }
    else {
      ERR_put_error(0x10,0x9d,0x67,"ec_asn1.c",0x382);
LAB_08104abd:
      p = (EC_POINT *)0x0;
      group = (EC_GROUP *)0x0;
    }
LAB_08104ac8:
    BN_free(local_28);
    if (a == (BIGNUM *)0x0) goto LAB_08104b54;
  }
  BN_free(a);
LAB_08104b54:
  if (b != (BIGNUM *)0x0) {
    BN_free(b);
  }
  if (p != (EC_POINT *)0x0) {
    EC_POINT_free(p);
    return group;
  }
  return group;
}

