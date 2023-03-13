
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
    iVar4 = 700;
LAB_08102f98:
    ERR_put_error(0x10,0x9d,0x73,"ec_asn1.c",iVar4);
    return (EC_GROUP *)0x0;
  }
  ppiVar1 = *(int ***)(param_1 + 8);
  if (((ppiVar1 == (int **)0x0) || (piVar5 = *ppiVar1, piVar5 == (int *)0x0)) ||
     (((uchar *)piVar5[2] == (uchar *)0x0 || ((ppiVar1[1] == (int *)0x0 || (ppiVar1[1][2] == 0))))))
  {
    iVar4 = 0x2c4;
    goto LAB_08102f98;
  }
  a = BN_bin2bn((uchar *)piVar5[2],*piVar5,(BIGNUM *)0x0);
  if (a == (BIGNUM *)0x0) {
    ERR_put_error(0x10,0x9d,3,"ec_asn1.c",0x2c9);
    return (EC_GROUP *)0x0;
  }
  piVar5 = *(int **)(*(int *)(param_1 + 8) + 4);
  b = BN_bin2bn((uchar *)piVar5[2],*piVar5,(BIGNUM *)0x0);
  if (b == (BIGNUM *)0x0) {
    ERR_put_error(0x10,0x9d,3,"ec_asn1.c",0x2ce);
LAB_08102fee:
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
              iVar4 = 0x2f2;
              goto LAB_0810309f;
            }
            iVar4 = ASN1_INTEGER_get((ASN1_INTEGER *)piVar5[2]);
            if ((iVar4 < *piVar5) && (0 < iVar4)) {
              iVar6 = BN_set_bit(local_28,*piVar5);
              if (iVar6 != 0) {
LAB_081031fd:
                iVar4 = BN_set_bit(local_28,iVar4);
                if ((iVar4 != 0) && (iVar4 = BN_set_bit(local_28,0), iVar4 != 0)) {
                  group = (EC_GROUP *)EC_GROUP_new_curve_GF2m(local_28,a,b,0);
                  goto LAB_08103247;
                }
              }
            }
            else {
              ERR_put_error(0x10,0x9d,0x89,"ec_asn1.c",0x2fa);
            }
          }
          else if (iVar4 == 0x2ab) {
            piVar3 = (int *)piVar5[2];
            if (piVar3 == (int *)0x0) {
              iVar4 = 0x30a;
              goto LAB_0810309f;
            }
            if ((((piVar3[2] < *piVar5) && (piVar3[1] < piVar3[2])) && (0 < *piVar3)) &&
               (*piVar3 < piVar3[1])) {
              iVar4 = BN_set_bit(local_28,*piVar5);
              if (((iVar4 != 0) && (iVar4 = BN_set_bit(local_28,*piVar3), iVar4 != 0)) &&
                 (iVar4 = BN_set_bit(local_28,piVar3[1]), iVar4 != 0)) {
                iVar4 = piVar3[2];
                goto LAB_081031fd;
              }
            }
            else {
              ERR_put_error(0x10,0x9d,0x84,"ec_asn1.c",0x312);
            }
          }
          else if (iVar4 == 0x2a9) {
            ERR_put_error(0x10,0x9d,0x7e,"ec_asn1.c",0x322);
          }
          else {
            iVar4 = 0x326;
LAB_0810309f:
            ERR_put_error(0x10,0x9d,0x73,"ec_asn1.c",iVar4);
          }
          goto LAB_08102f6d;
        }
        ERR_put_error(0x10,0x9d,0x41,"ec_asn1.c",0x2e7);
      }
      else {
        ERR_put_error(0x10,0x9d,0x8f,"ec_asn1.c",0x2e2);
      }
      goto LAB_08102fee;
    }
    if (iVar4 != 0x196) {
      ERR_put_error(0x10,0x9d,0x67,"ec_asn1.c",0x349);
      goto LAB_08102fee;
    }
    ai = *(ASN1_INTEGER **)(*(int *)(param_1 + 4) + 4);
    if (ai == (ASN1_INTEGER *)0x0) {
      ERR_put_error(0x10,0x9d,0x73,"ec_asn1.c",0x332);
      goto LAB_08102fee;
    }
    local_28 = ASN1_INTEGER_to_BN(ai,(BIGNUM *)0x0);
    if (local_28 == (BIGNUM *)0x0) {
      ERR_put_error(0x10,0x9d,0xd,"ec_asn1.c",0x337);
      goto LAB_08102fee;
    }
    if ((local_28->neg == 0) && (local_28->top != 0)) {
      local_24 = BN_num_bits(local_28);
      if (0x295 < local_24) {
        ERR_put_error(0x10,0x9d,0x8f,"ec_asn1.c",0x342);
        goto LAB_08102f6d;
      }
      group = EC_GROUP_new_curve_GFp(local_28,a,b,(BN_CTX *)0x0);
LAB_08103247:
      if (group == (EC_GROUP *)0x0) {
        p = (EC_POINT *)0x0;
        ERR_put_error(0x10,0x9d,0x10,"ec_asn1.c",0x34e);
      }
      else {
        piVar5 = *(int **)(*(int *)(param_1 + 8) + 8);
        if (piVar5 == (int *)0x0) {
LAB_081032ce:
          if (((*(int *)(param_1 + 0x10) == 0) || (*(int *)(param_1 + 0xc) == 0)) ||
             (*(int *)(*(int *)(param_1 + 0xc) + 8) == 0)) {
            iVar6 = 0x360;
            iVar4 = 0x73;
            goto LAB_081034e4;
          }
          p = EC_POINT_new(group);
          if (p != (EC_POINT *)0x0) {
            EC_GROUP_set_point_conversion_form
                      (group,**(byte **)(*(int *)(param_1 + 0xc) + 8) & 0xfffffffe);
            iVar4 = EC_POINT_oct2point(group,p,(uchar *)(*(size_t **)(param_1 + 0xc))[2],
                                       **(size_t **)(param_1 + 0xc),(BN_CTX *)0x0);
            if (iVar4 == 0) {
              iVar4 = 0x36e;
              cofactor = b;
LAB_08103350:
              ERR_put_error(0x10,0x9d,0x10,"ec_asn1.c",iVar4);
              b = cofactor;
            }
            else {
              a = ASN1_INTEGER_to_BN(*(ASN1_INTEGER **)(param_1 + 0x10),a);
              if (a == (BIGNUM *)0x0) {
                iVar4 = 0x374;
LAB_081035fd:
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
                        iVar4 = 0x387;
                        b = cofactor;
                        goto LAB_081035fd;
                      }
                    }
                    iVar4 = EC_GROUP_set_generator(group,p,a,cofactor);
                    b = cofactor;
                    if (iVar4 != 0) goto LAB_08102f78;
                    iVar4 = 0x38c;
                    goto LAB_08103350;
                  }
                  iVar4 = 0x37c;
                }
                else {
                  iVar4 = 0x378;
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
          __dest = CRYPTO_malloc(*piVar5,"ec_asn1.c",0x356);
          *(void **)(group + 0x3c) = __dest;
          if (__dest != (void *)0x0) {
            psVar2 = *(size_t **)(*(int *)(param_1 + 8) + 8);
            memcpy(__dest,(void *)psVar2[2],*psVar2);
            *(undefined4 *)(group + 0x40) = **(undefined4 **)(*(int *)(param_1 + 8) + 8);
            goto LAB_081032ce;
          }
          iVar6 = 0x357;
          iVar4 = 0x41;
LAB_081034e4:
          p = (EC_POINT *)0x0;
          ERR_put_error(0x10,0x9d,iVar4,"ec_asn1.c",iVar6);
        }
        EC_GROUP_clear_free(group);
        group = (EC_GROUP *)0x0;
      }
    }
    else {
      ERR_put_error(0x10,0x9d,0x67,"ec_asn1.c",0x33c);
LAB_08102f6d:
      p = (EC_POINT *)0x0;
      group = (EC_GROUP *)0x0;
    }
LAB_08102f78:
    BN_free(local_28);
    if (a == (BIGNUM *)0x0) goto LAB_08103004;
  }
  BN_free(a);
LAB_08103004:
  if (b != (BIGNUM *)0x0) {
    BN_free(b);
  }
  if (p != (EC_POINT *)0x0) {
    EC_POINT_free(p);
    return group;
  }
  return group;
}

