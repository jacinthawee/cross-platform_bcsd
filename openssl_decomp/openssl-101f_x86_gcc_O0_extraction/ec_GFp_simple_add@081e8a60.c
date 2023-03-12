
uint ec_GFp_simple_add(int *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,BN_CTX *param_5)

{
  code *pcVar1;
  code *pcVar2;
  EC_POINT *dst;
  int iVar3;
  BIGNUM *pBVar4;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *pBVar5;
  uint uVar6;
  BIGNUM *pBVar7;
  BIGNUM *pBVar8;
  BIGNUM *pBVar9;
  BIGNUM *pBVar10;
  BN_CTX *local_48;
  
  dst = (EC_POINT *)param_2;
  if (param_3 == param_4) {
    uVar6 = EC_POINT_dbl((EC_GROUP *)param_1,(EC_POINT *)param_2,(EC_POINT *)param_3,param_5);
    return uVar6;
  }
  iVar3 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,(EC_POINT *)param_3);
  if (iVar3 != 0) {
    param_2 = param_4;
    pBVar4 = param_2;
LAB_081e8cbc:
    param_2 = pBVar4;
    uVar6 = EC_POINT_copy(dst,(EC_POINT *)param_2);
    return uVar6;
  }
  iVar3 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,(EC_POINT *)param_4);
  pBVar4 = param_3;
  if (iVar3 != 0) goto LAB_081e8cbc;
  local_48 = (BN_CTX *)0x0;
  pcVar1 = *(code **)(*param_1 + 0x84);
  pcVar2 = *(code **)(*param_1 + 0x88);
  if ((param_5 == (BN_CTX *)0x0) &&
     (param_5 = BN_CTX_new(), local_48 = param_5, param_5 == (BN_CTX *)0x0)) {
    return 0;
  }
  BN_CTX_start(param_5);
  pBVar4 = BN_CTX_get(param_5);
  a = BN_CTX_get(param_5);
  a_00 = BN_CTX_get(param_5);
  a_01 = BN_CTX_get(param_5);
  a_02 = BN_CTX_get(param_5);
  r = BN_CTX_get(param_5);
  r_00 = BN_CTX_get(param_5);
  if (r_00 == (BIGNUM *)0x0) {
LAB_081e8c80:
    uVar6 = 0;
  }
  else {
    if (param_4[3].top == 0) {
      iVar3 = (*pcVar2)(param_1,pBVar4,&param_4[2].top,param_5);
      if ((((iVar3 != 0) && (iVar3 = (*pcVar1)(param_1,a,&param_3->top,pBVar4,param_5), iVar3 != 0))
          && (iVar3 = (*pcVar1)(param_1,pBVar4,pBVar4,&param_4[2].top,param_5), iVar3 != 0)) &&
         (iVar3 = (*pcVar1)(param_1,a_00,&param_3[1].top,pBVar4,param_5), iVar3 != 0))
      goto LAB_081e8b82;
      goto LAB_081e8c80;
    }
    pBVar5 = BN_copy(a,(BIGNUM *)&param_3->top);
    if ((pBVar5 == (BIGNUM *)0x0) ||
       (pBVar5 = BN_copy(a_00,(BIGNUM *)&param_3[1].top), pBVar5 == (BIGNUM *)0x0))
    goto LAB_081e8c80;
LAB_081e8b82:
    if (param_3[3].top == 0) {
      iVar3 = (*pcVar2)(param_1,pBVar4,&param_3[2].top,param_5);
      if (((iVar3 != 0) &&
          (iVar3 = (*pcVar1)(param_1,a_01,&param_4->top,pBVar4,param_5), iVar3 != 0)) &&
         ((iVar3 = (*pcVar1)(param_1,pBVar4,pBVar4,&param_3[2].top,param_5), iVar3 != 0 &&
          (iVar3 = (*pcVar1)(param_1,a_02,&param_4[1].top,pBVar4,param_5), iVar3 != 0))))
      goto LAB_081e8bc3;
      goto LAB_081e8c80;
    }
    pBVar5 = BN_copy(a_01,(BIGNUM *)&param_4->top);
    if ((pBVar5 == (BIGNUM *)0x0) ||
       (pBVar5 = BN_copy(a_02,(BIGNUM *)&param_4[1].top), pBVar5 == (BIGNUM *)0x0))
    goto LAB_081e8c80;
LAB_081e8bc3:
    pBVar5 = (BIGNUM *)(param_1 + 0x12);
    iVar3 = BN_mod_sub_quick(r,a,a_01,pBVar5);
    if ((iVar3 == 0) || (iVar3 = BN_mod_sub_quick(r_00,a_00,a_02,pBVar5), iVar3 == 0))
    goto LAB_081e8c80;
    if (r->top != 0) {
      iVar3 = BN_mod_add_quick(a,a,a_01,pBVar5);
      if ((iVar3 == 0) ||
         (pBVar8 = a_00, pBVar9 = a_02, pBVar10 = pBVar5,
         pBVar7 = (BIGNUM *)BN_mod_add_quick(a_00,a_00,a_02,pBVar5), pBVar7 == (BIGNUM *)0x0))
      goto LAB_081e8c80;
      if (param_3[3].top == 0) {
        if (param_4[3].top != 0) {
          param_3 = param_3 + 2;
          goto LAB_081e8e65;
        }
        pBVar7 = (BIGNUM *)(*pcVar1)(param_1,pBVar4,&param_3[2].top,&param_4[2].top,param_5);
        param_4 = pBVar9;
joined_r0x081e9043:
        if (pBVar7 == (BIGNUM *)0x0) goto LAB_081e8c80;
        pBVar8 = (BIGNUM *)
                 (*pcVar1)(param_1,(EC_POINT *)((int)param_2 + 0x2c),pBVar4,r,param_5,pBVar8,param_4
                           ,pBVar10);
      }
      else {
        if (param_4[3].top == 0) {
          param_3 = param_4 + 2;
          param_4 = pBVar7;
LAB_081e8e65:
          pBVar8 = (BIGNUM *)&param_3->top;
          pBVar10 = param_4;
          pBVar7 = BN_copy(pBVar4,pBVar8);
          goto joined_r0x081e9043;
        }
        pBVar8 = BN_copy((BIGNUM *)((int)param_2 + 0x2c),r);
      }
      if (pBVar8 != (BIGNUM *)0x0) {
        *(undefined4 *)((int)param_2 + 0x40) = 0;
        iVar3 = (*pcVar2)(param_1,pBVar4,r_00,param_5);
        if (((iVar3 != 0) && (iVar3 = (*pcVar2)(param_1,a_02,r,param_5), iVar3 != 0)) &&
           (iVar3 = (*pcVar1)(param_1,a_01,a,a_02,param_5), iVar3 != 0)) {
          iVar3 = BN_mod_sub_quick((BIGNUM *)((int)param_2 + 4),pBVar4,a_01,pBVar5);
          if (((((iVar3 != 0) &&
                (iVar3 = BN_mod_lshift1_quick(pBVar4,(BIGNUM *)((int)param_2 + 4),pBVar5),
                iVar3 != 0)) &&
               ((iVar3 = BN_mod_sub_quick(pBVar4,a_01,pBVar4,pBVar5), iVar3 != 0 &&
                ((iVar3 = (*pcVar1)(param_1,pBVar4,pBVar4,r_00,param_5), iVar3 != 0 &&
                 (iVar3 = (*pcVar1)(param_1,r,a_02,r,param_5), iVar3 != 0)))))) &&
              (iVar3 = (*pcVar1)(param_1,a,a_00,r,param_5), iVar3 != 0)) &&
             ((iVar3 = BN_mod_sub_quick(pBVar4,pBVar4,a,pBVar5), iVar3 != 0 &&
              (((pBVar4->top < 1 || ((*(byte *)pBVar4->d & 1) == 0)) ||
               (iVar3 = BN_add(pBVar4,pBVar4,pBVar5), iVar3 != 0)))))) {
            iVar3 = BN_rshift1((BIGNUM *)((int)param_2 + 0x18),pBVar4);
            uVar6 = (uint)(iVar3 != 0);
            goto LAB_081e8c82;
          }
        }
      }
      goto LAB_081e8c80;
    }
    if (r_00->top == 0) {
      BN_CTX_end(param_5);
      uVar6 = EC_POINT_dbl((EC_GROUP *)param_1,(EC_POINT *)param_2,(EC_POINT *)param_3,param_5);
      goto LAB_081e8c8e;
    }
    uVar6 = 1;
    BN_set_word((BIGNUM *)((int)param_2 + 0x2c),0);
    *(undefined4 *)((int)param_2 + 0x40) = 0;
  }
LAB_081e8c82:
  BN_CTX_end(param_5);
LAB_081e8c8e:
  if (local_48 != (BN_CTX *)0x0) {
    BN_CTX_free(local_48);
  }
  return uVar6;
}

