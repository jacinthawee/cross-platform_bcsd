
bool ec_GFp_simple_group_check_discriminant(int *param_1,BN_CTX *param_2)

{
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *pBVar1;
  int iVar2;
  BN_CTX *c;
  bool bVar3;
  
  c = (BN_CTX *)0x0;
  if ((param_2 == (BN_CTX *)0x0) && (param_2 = BN_CTX_new(), c = param_2, param_2 == (BN_CTX *)0x0))
  {
    ERR_put_error(0x10,0xa5,0x41,"ecp_smpl.c",299);
    return false;
  }
  BN_CTX_start(param_2);
  a = BN_CTX_get(param_2);
  a_00 = BN_CTX_get(param_2);
  r = BN_CTX_get(param_2);
  r_00 = BN_CTX_get(param_2);
  pBVar1 = BN_CTX_get(param_2);
  if (pBVar1 != (BIGNUM *)0x0) {
    if (*(code **)(*param_1 + 0x94) == (code *)0x0) {
      pBVar1 = BN_copy(a,(BIGNUM *)(param_1 + 0x1d));
      if (pBVar1 != (BIGNUM *)0x0) {
        pBVar1 = BN_copy(a_00,(BIGNUM *)(param_1 + 0x22));
        goto joined_r0x081e7800;
      }
    }
    else {
      iVar2 = (**(code **)(*param_1 + 0x94))(param_1,a,param_1 + 0x1d,param_2);
      if (iVar2 != 0) {
        pBVar1 = (BIGNUM *)(**(code **)(*param_1 + 0x94))(param_1,a_00,param_1 + 0x22,param_2);
joined_r0x081e7800:
        if (pBVar1 != (BIGNUM *)0x0) {
          if (a->top == 0) {
            bVar3 = a_00->top != 0;
            goto LAB_081e7726;
          }
          bVar3 = true;
          if (a_00->top == 0) goto LAB_081e7726;
          pBVar1 = (BIGNUM *)(param_1 + 0x12);
          iVar2 = BN_mod_sqr(r,a,pBVar1,param_2);
          if ((((iVar2 != 0) && (iVar2 = BN_mod_mul(r_00,r,a,pBVar1,param_2), iVar2 != 0)) &&
              (iVar2 = BN_lshift(r,r_00,2), iVar2 != 0)) &&
             (((iVar2 = BN_mod_sqr(r_00,a_00,pBVar1,param_2), iVar2 != 0 &&
               (iVar2 = BN_mul_word(r_00,0x1b), iVar2 != 0)) &&
              (iVar2 = BN_mod_add(a,r,r_00,pBVar1,param_2), iVar2 != 0)))) {
            bVar3 = a->top != 0;
            goto LAB_081e7726;
          }
        }
      }
    }
  }
  bVar3 = false;
LAB_081e7726:
  BN_CTX_end(param_2);
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
  }
  return bVar3;
}

