
BIGNUM * ec_GF2m_precompute_mult(EC_GROUP *param_1,BN_CTX *param_2)

{
  EC_GROUP **ptr;
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  uint uVar4;
  EC_GROUP *pEVar5;
  EC_GROUP *num;
  BIGNUM *points;
  int iVar6;
  ulong *point;
  EC_POINT *point_00;
  BIGNUM *r;
  BIGNUM *dst;
  EC_POINT **ptr_00;
  EC_GROUP *pEVar7;
  int *piVar8;
  BN_CTX *pBStack_50;
  int iStack_44;
  EC_GROUP *pEStack_40;
  EC_GROUP *pEStack_3c;
  
  EC_EX_DATA_free_data(param_1 + 0x44,0x8fb7d,0x8fd39,0x8fd8d);
  if (param_1 == (EC_GROUP *)0x0) {
    return (BIGNUM *)0x0;
  }
  ptr = (EC_GROUP **)CRYPTO_malloc(0x1c,"ec_mult.c",0x67);
  if (ptr == (EC_GROUP **)0x0) {
    ERR_put_error(0x10,0xc4,0x41,"ec_mult.c",0x69);
    return (BIGNUM *)0x0;
  }
  *ptr = param_1;
  ptr[2] = (EC_GROUP *)0x0;
  ptr[1] = (EC_GROUP *)&DAT_00000008;
  ptr[4] = (EC_GROUP *)0x0;
  ptr[5] = (EC_GROUP *)0x0;
  ptr[3] = (EC_GROUP *)&DAT_00000004;
  ptr[6] = (EC_GROUP *)0x1;
  pBVar1 = (BIGNUM *)EC_GROUP_get0_generator(param_1);
  if (pBVar1 == (BIGNUM *)0x0) {
    ERR_put_error(0x10,0xbc,0x71,"ec_mult.c",0x2f9);
    if (param_2 == (BN_CTX *)0x0) {
LAB_000908fa:
      pBVar1 = (BIGNUM *)0x0;
      points = pBVar1;
      r = (BIGNUM *)0x0;
      dst = pBVar1;
    }
    else {
      BN_CTX_end(param_2);
      points = pBVar1;
      r = pBVar1;
      dst = pBVar1;
    }
  }
  else {
    if (param_2 == (BN_CTX *)0x0) {
      param_2 = BN_CTX_new();
      pBStack_50 = param_2;
      if (param_2 == (BN_CTX *)0x0) goto LAB_000908fa;
    }
    else {
      pBStack_50 = (BN_CTX *)0x0;
    }
    BN_CTX_start(param_2);
    pBVar2 = BN_CTX_get(param_2);
    pBVar3 = pBVar2;
    points = pBVar2;
    r = pBVar2;
    dst = pBVar2;
    if ((pBVar2 != (BIGNUM *)0x0) &&
       (pBVar3 = (BIGNUM *)EC_GROUP_get_order(param_1,pBVar2,param_2), points = pBVar3, r = pBVar3,
       dst = pBVar3, pBVar3 != (BIGNUM *)0x0)) {
      pBVar3 = (BIGNUM *)pBVar2->top;
      if (pBVar3 == (BIGNUM *)0x0) {
        ERR_put_error(0x10,0xbc,0x72,"ec_mult.c",0x30b);
        points = pBVar3;
        r = pBVar3;
        dst = pBVar3;
      }
      else {
        uVar4 = BN_num_bits(pBVar2);
        if (uVar4 < 800) {
          iStack_44 = 8;
          pEStack_3c = (EC_GROUP *)&DAT_00000004;
        }
        else if (uVar4 < 2000) {
          iStack_44 = 0x10;
          pEStack_3c = (EC_GROUP *)0x5;
        }
        else {
          iStack_44 = 0x20;
          pEStack_3c = (EC_GROUP *)0x6;
        }
        pEVar5 = (EC_GROUP *)(uVar4 + 7 >> 3);
        num = (EC_GROUP *)((int)pEVar5 * iStack_44);
        points = (BIGNUM *)CRYPTO_malloc((int)(num + 1) * 4,"ec_mult.c",0x325);
        if (points == (BIGNUM *)0x0) {
          ERR_put_error(0x10,0xbc,0x41,"ec_mult.c",0x327);
          pBVar3 = points;
          r = points;
          dst = points;
        }
        else {
          *(undefined4 *)((int)points + (int)(num + 1) * 4 + -4) = 0;
          if (num != (EC_GROUP *)0x0) {
            piVar8 = &points[-1].flags;
            pEVar7 = (EC_GROUP *)0x0;
            do {
              pEVar7 = pEVar7 + 1;
              pBVar3 = (BIGNUM *)EC_POINT_new(param_1);
              piVar8 = piVar8 + 1;
              *piVar8 = (int)pBVar3;
              if (pBVar3 == (BIGNUM *)0x0) {
                ERR_put_error(0x10,0xbc,0x41,"ec_mult.c",0x32f);
                r = pBVar3;
                dst = pBVar3;
                goto LAB_000907e6;
              }
            } while (pEVar7 != num);
          }
          r = (BIGNUM *)EC_POINT_new(param_1);
          if ((r == (BIGNUM *)0x0) || (dst = (BIGNUM *)EC_POINT_new(param_1), dst == (BIGNUM *)0x0))
          {
            ERR_put_error(0x10,0xbc,0x41,"ec_mult.c",0x335);
            pBVar3 = (BIGNUM *)0x0;
            dst = (BIGNUM *)0x0;
          }
          else {
            pBVar3 = (BIGNUM *)EC_POINT_copy((EC_POINT *)dst,(EC_POINT *)pBVar1);
            if (pBVar3 != (BIGNUM *)0x0) {
              if (pEVar5 != (EC_GROUP *)0x0) {
                pEStack_40 = (EC_GROUP *)0x0;
                pBVar1 = points;
                do {
                  pBVar3 = (BIGNUM *)EC_POINT_dbl(param_1,(EC_POINT *)r,(EC_POINT *)dst,param_2);
                  if ((pBVar3 == (BIGNUM *)0x0) ||
                     (pBVar3 = (BIGNUM *)EC_POINT_copy((EC_POINT *)pBVar1->d,(EC_POINT *)dst),
                     pBVar3 == (BIGNUM *)0x0)) goto LAB_000907e6;
                  iVar6 = 1;
                  pBVar2 = pBVar1;
                  do {
                    iVar6 = iVar6 + 1;
                    pBVar1 = (BIGNUM *)&pBVar2->dmax;
                    pBVar3 = (BIGNUM *)
                             EC_POINT_add(param_1,(EC_POINT *)pBVar2->top,(EC_POINT *)r,
                                          (EC_POINT *)pBVar2->d,param_2);
                    if (pBVar3 == (BIGNUM *)0x0) goto LAB_000907e6;
                    pBVar2 = (BIGNUM *)&pBVar2->top;
                  } while (iVar6 != iStack_44);
                  if (pEStack_40 < pEVar5 + -1) {
                    pBVar3 = (BIGNUM *)EC_POINT_dbl(param_1,(EC_POINT *)dst,(EC_POINT *)r,param_2);
                    if (pBVar3 == (BIGNUM *)0x0) goto LAB_000907e6;
                    iVar6 = 6;
                    do {
                      pBVar3 = (BIGNUM *)
                               EC_POINT_dbl(param_1,(EC_POINT *)dst,(EC_POINT *)dst,param_2);
                      if (pBVar3 == (BIGNUM *)0x0) goto LAB_000907e6;
                      iVar6 = iVar6 + -1;
                    } while (iVar6 != 0);
                  }
                  pEStack_40 = pEStack_40 + 1;
                } while (pEStack_40 != pEVar5);
              }
              pBVar3 = (BIGNUM *)
                       EC_POINTs_make_affine(param_1,(size_t)num,(EC_POINT **)points,param_2);
              if (pBVar3 != (BIGNUM *)0x0) {
                *ptr = param_1;
                ptr[4] = (EC_GROUP *)points;
                ptr[2] = pEVar5;
                ptr[5] = num;
                ptr[3] = pEStack_3c;
                ptr[1] = (EC_GROUP *)&DAT_00000008;
                pBVar3 = (BIGNUM *)EC_EX_DATA_set_data(param_1 + 0x44,ptr,0x8fb7d,0x8fd39,0x8fd8d);
                points = pBVar3;
                if (pBVar3 != (BIGNUM *)0x0) {
                  ptr = (EC_GROUP **)0x0;
                  pBVar3 = (BIGNUM *)0x1;
                  points = (BIGNUM *)0x0;
                }
              }
            }
          }
        }
      }
    }
LAB_000907e6:
    BN_CTX_end(param_2);
    if (pBStack_50 != (BN_CTX *)0x0) {
      BN_CTX_free(pBStack_50);
    }
    pBVar1 = pBVar3;
    if (ptr == (EC_GROUP **)0x0) goto LAB_00090814;
  }
  iVar6 = CRYPTO_add_lock((int *)(ptr + 6),-1,0x24,"ec_mult.c",0x89);
  if (iVar6 < 1) {
    ptr_00 = (EC_POINT **)ptr[4];
    if (ptr_00 != (EC_POINT **)0x0) {
      point_00 = *ptr_00;
      if (point_00 != (EC_POINT *)0x0) {
        do {
          EC_POINT_free(point_00);
          ptr_00 = ptr_00 + 1;
          point_00 = *ptr_00;
        } while (point_00 != (EC_POINT *)0x0);
        ptr_00 = (EC_POINT **)ptr[4];
      }
      CRYPTO_free(ptr_00);
    }
    CRYPTO_free(ptr);
  }
LAB_00090814:
  if (points != (BIGNUM *)0x0) {
    point = points->d;
    pBVar3 = points;
    while (point != (ulong *)0x0) {
      EC_POINT_free((EC_POINT *)point);
      pBVar3 = (BIGNUM *)&pBVar3->top;
      point = *(ulong **)pBVar3;
    }
    CRYPTO_free(points);
  }
  if (r != (BIGNUM *)0x0) {
    EC_POINT_free((EC_POINT *)r);
  }
  if (dst != (BIGNUM *)0x0) {
    EC_POINT_free((EC_POINT *)dst);
    return pBVar1;
  }
  return pBVar1;
}

