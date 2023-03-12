
uint ec_GFp_simple_is_on_curve(int *param_1,EC_POINT *param_2,BN_CTX *param_3)

{
  BIGNUM *r;
  BIGNUM *b;
  BIGNUM *a;
  BIGNUM *pBVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  BIGNUM *m;
  code *pcVar5;
  EC_POINT *pEVar6;
  BN_CTX *local_3c;
  
  local_3c = (BN_CTX *)EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_2);
  if (local_3c != (BN_CTX *)0x0) {
    return 1;
  }
  pcVar4 = *(code **)(*param_1 + 0x84);
  pcVar5 = *(code **)(*param_1 + 0x88);
  if ((param_3 == (BN_CTX *)0x0) &&
     (param_3 = BN_CTX_new(), local_3c = param_3, param_3 == (BN_CTX *)0x0)) {
    return 0xffffffff;
  }
  BN_CTX_start(param_3);
  r = BN_CTX_get(param_3);
  b = BN_CTX_get(param_3);
  a = BN_CTX_get(param_3);
  pBVar1 = BN_CTX_get(param_3);
  if (pBVar1 != (BIGNUM *)0x0) {
    pEVar6 = param_2 + 4;
    iVar2 = (*pcVar5)(param_1,r,pEVar6,param_3);
    if (iVar2 != 0) {
      m = (BIGNUM *)(param_1 + 0x12);
      if (*(int *)(param_2 + 0x40) == 0) {
        iVar2 = (*pcVar5)(param_1,b,param_2 + 0x2c,param_3);
        if (((iVar2 != 0) && (iVar2 = (*pcVar5)(param_1,a,b,param_3), iVar2 != 0)) &&
           (iVar2 = (*pcVar4)(param_1,pBVar1,a,b,param_3), iVar2 != 0)) {
          if (param_1[0x27] == 0) {
            iVar2 = (*pcVar4)(param_1,b,a,param_1 + 0x1d,param_3);
            if (iVar2 != 0) {
              iVar2 = BN_mod_add_quick(r,r,b,m);
              goto joined_r0x00123c2c;
            }
          }
          else {
            iVar2 = BN_mod_lshift1_quick(b,a,m);
            if ((iVar2 != 0) && (iVar2 = BN_mod_add_quick(b,b,a,m), iVar2 != 0)) {
              iVar2 = BN_mod_sub_quick(r,r,b,m);
joined_r0x00123c2c:
              if (((iVar2 != 0) && (iVar2 = (*pcVar4)(param_1,r,r,pEVar6,param_3), iVar2 != 0)) &&
                 (iVar2 = (*pcVar4)(param_1,b,param_1 + 0x22,pBVar1,param_3), iVar2 != 0)) {
                iVar2 = BN_mod_add_quick(r,r,b,m);
                goto joined_r0x00123be4;
              }
            }
          }
        }
      }
      else {
        iVar2 = BN_mod_add_quick(r,r,(BIGNUM *)(param_1 + 0x1d),m);
        if ((iVar2 != 0) && (iVar2 = (*pcVar4)(param_1,r,r,pEVar6,param_3), iVar2 != 0)) {
          iVar2 = BN_mod_add_quick(r,r,(BIGNUM *)(param_1 + 0x22),m);
joined_r0x00123be4:
          if ((iVar2 != 0) && (iVar2 = (*pcVar5)(param_1,b,param_2 + 0x18,param_3), iVar2 != 0)) {
            iVar2 = BN_ucmp(b,r);
            uVar3 = count_leading_zeroes(iVar2);
            uVar3 = uVar3 >> 5;
            goto LAB_00123af4;
          }
        }
      }
    }
  }
  uVar3 = 0xffffffff;
LAB_00123af4:
  BN_CTX_end(param_3);
  if (local_3c != (BN_CTX *)0x0) {
    BN_CTX_free(local_3c);
  }
  return uVar3;
}

