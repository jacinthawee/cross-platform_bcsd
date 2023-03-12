
/* WARNING: Type propagation algorithm not settling */

int ec_GFp_simple_add(int *param_1,EC_POINT *param_2,EC_POINT *param_3,EC_POINT *param_4,
                     BN_CTX *param_5)

{
  int iVar1;
  BN_CTX *c;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  BIGNUM *a_03;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  code *pcVar4;
  code *pcVar5;
  
  if (param_3 == param_4) {
    iVar1 = EC_POINT_dbl((EC_GROUP *)param_1,param_2,param_3,param_5);
    return iVar1;
  }
  iVar1 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_3);
  if (iVar1 != 0) {
    iVar1 = EC_POINT_copy(param_2,param_4);
    return iVar1;
  }
  c = (BN_CTX *)EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_4);
  if (c != (BN_CTX *)0x0) {
    iVar1 = EC_POINT_copy(param_2,param_3);
    return iVar1;
  }
  pcVar5 = *(code **)(*param_1 + 0x84);
  pcVar4 = *(code **)(*param_1 + 0x88);
  if ((param_5 == (BN_CTX *)0x0) && (param_5 = BN_CTX_new(), c = param_5, param_5 == (BN_CTX *)0x0))
  {
    return 0;
  }
  BN_CTX_start(param_5);
  a = BN_CTX_get(param_5);
  a_00 = BN_CTX_get(param_5);
  a_01 = BN_CTX_get(param_5);
  a_02 = BN_CTX_get(param_5);
  a_03 = BN_CTX_get(param_5);
  r = BN_CTX_get(param_5);
  r_00 = BN_CTX_get(param_5);
  if (r_00 == (BIGNUM *)0x0) {
LAB_001237ee:
    iVar1 = 0;
  }
  else {
    if (*(int *)(param_4 + 0x40) == 0) {
      iVar1 = (*pcVar4)(param_1,a,param_4 + 0x2c,param_5);
      if ((((iVar1 != 0) && (iVar1 = (*pcVar5)(param_1,a_00,param_3 + 4,a,param_5), iVar1 != 0)) &&
          (iVar1 = (*pcVar5)(param_1,a,a,param_4 + 0x2c,param_5), iVar1 != 0)) &&
         (iVar1 = (*pcVar5)(param_1,a_01,param_3 + 0x18,a,param_5), iVar1 != 0)) goto LAB_00123746;
      goto LAB_001237ee;
    }
    pBVar2 = BN_copy(a_00,(BIGNUM *)(param_3 + 4));
    if ((pBVar2 == (BIGNUM *)0x0) ||
       (pBVar2 = BN_copy(a_01,(BIGNUM *)(param_3 + 0x18)), pBVar2 == (BIGNUM *)0x0))
    goto LAB_001237ee;
LAB_00123746:
    if (*(int *)(param_3 + 0x40) == 0) {
      iVar1 = (*pcVar4)(param_1,a,param_3 + 0x2c,param_5);
      if (((iVar1 != 0) && (iVar1 = (*pcVar5)(param_1,a_02,param_4 + 4,a,param_5), iVar1 != 0)) &&
         ((iVar1 = (*pcVar5)(param_1,a,a,param_3 + 0x2c,param_5), iVar1 != 0 &&
          (iVar1 = (*pcVar5)(param_1,a_03,param_4 + 0x18,a,param_5), iVar1 != 0))))
      goto LAB_00123766;
      goto LAB_001237ee;
    }
    pBVar2 = BN_copy(a_02,(BIGNUM *)(param_4 + 4));
    if ((pBVar2 == (BIGNUM *)0x0) ||
       (pBVar2 = BN_copy(a_03,(BIGNUM *)(param_4 + 0x18)), pBVar2 == (BIGNUM *)0x0))
    goto LAB_001237ee;
LAB_00123766:
    pBVar2 = (BIGNUM *)(param_1 + 0x12);
    iVar1 = BN_mod_sub_quick(r,a_00,a_02,pBVar2);
    if ((iVar1 == 0) || (iVar1 = BN_mod_sub_quick(r_00,a_01,a_03,pBVar2), iVar1 == 0))
    goto LAB_001237ee;
    if (r->top != 0) {
      iVar1 = BN_mod_add_quick(a_00,a_00,a_02,pBVar2);
      if ((iVar1 == 0) || (iVar1 = BN_mod_add_quick(a_01,a_01,a_03,pBVar2), iVar1 == 0))
      goto LAB_001237ee;
      if (*(int *)(param_3 + 0x40) == 0) {
        if (*(int *)(param_4 + 0x40) == 0) {
          pBVar3 = (BIGNUM *)(*pcVar5)(param_1,a,param_3 + 0x2c,param_4 + 0x2c,param_5);
        }
        else {
          pBVar3 = BN_copy(a,(BIGNUM *)(param_3 + 0x2c));
        }
joined_r0x00123a0c:
        if (pBVar3 == (BIGNUM *)0x0) goto LAB_001237ee;
        pBVar3 = (BIGNUM *)(*pcVar5)(param_1,param_2 + 0x2c,a,r,param_5);
      }
      else {
        if (*(int *)(param_4 + 0x40) == 0) {
          pBVar3 = BN_copy(a,(BIGNUM *)(param_4 + 0x2c));
          goto joined_r0x00123a0c;
        }
        pBVar3 = BN_copy((BIGNUM *)(param_2 + 0x2c),r);
      }
      if (pBVar3 != (BIGNUM *)0x0) {
        *(undefined4 *)(param_2 + 0x40) = 0;
        iVar1 = (*pcVar4)(param_1,a,r_00,param_5);
        if (((iVar1 != 0) && (iVar1 = (*pcVar4)(param_1,a_03,r,param_5), iVar1 != 0)) &&
           (iVar1 = (*pcVar5)(param_1,a_02,a_00,a_03,param_5), iVar1 != 0)) {
          iVar1 = BN_mod_sub_quick((BIGNUM *)(param_2 + 4),a,a_02,pBVar2);
          if (((((iVar1 != 0) &&
                (iVar1 = BN_mod_lshift1_quick(a,(BIGNUM *)(param_2 + 4),pBVar2), iVar1 != 0)) &&
               ((iVar1 = BN_mod_sub_quick(a,a_02,a,pBVar2), iVar1 != 0 &&
                ((iVar1 = (*pcVar5)(param_1,a,a,r_00,param_5), iVar1 != 0 &&
                 (iVar1 = (*pcVar5)(param_1,r,a_03,r,param_5), iVar1 != 0)))))) &&
              (iVar1 = (*pcVar5)(param_1,a_00,a_01,r,param_5), iVar1 != 0)) &&
             ((iVar1 = BN_mod_sub_quick(a,a,a_00,pBVar2), iVar1 != 0 &&
              (((a->top < 1 || (-1 < (int)(*a->d << 0x1f))) ||
               (iVar1 = BN_add(a,a,pBVar2), iVar1 != 0)))))) {
            iVar1 = BN_rshift1((BIGNUM *)(param_2 + 0x18),a);
            if (iVar1 != 0) {
              iVar1 = 1;
            }
            goto LAB_001237f0;
          }
        }
      }
      goto LAB_001237ee;
    }
    if (r_00->top == 0) {
      BN_CTX_end(param_5);
      iVar1 = EC_POINT_dbl((EC_GROUP *)param_1,param_2,param_3,param_5);
      goto joined_r0x001237fa;
    }
    BN_set_word((BIGNUM *)(param_2 + 0x2c),0);
    iVar1 = 1;
    *(undefined4 *)(param_2 + 0x40) = 0;
  }
LAB_001237f0:
  BN_CTX_end(param_5);
joined_r0x001237fa:
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
    return iVar1;
  }
  return iVar1;
}

