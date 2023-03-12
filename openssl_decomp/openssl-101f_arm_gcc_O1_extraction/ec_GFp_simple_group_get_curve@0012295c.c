
BIGNUM * ec_GFp_simple_group_get_curve
                   (int *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,BN_CTX *param_5)

{
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BN_CTX *c;
  
  pBVar2 = param_4;
  if ((param_2 != (BIGNUM *)0x0) &&
     (pBVar1 = BN_copy(param_2,(BIGNUM *)(param_1 + 0x12)), pBVar1 == (BIGNUM *)0x0)) {
    return (BIGNUM *)0x0;
  }
  pBVar1 = param_3;
  if (param_3 != (BIGNUM *)0x0) {
    pBVar1 = (BIGNUM *)0x1;
  }
  pBVar3 = param_4;
  if (param_4 != (BIGNUM *)0x0) {
    pBVar3 = (BIGNUM *)0x1;
  }
  if (((uint)pBVar1 | (uint)pBVar3) != 0) {
    if (*(int *)(*param_1 + 0x94) != 0) {
      c = (BN_CTX *)0x0;
      if ((param_5 == (BN_CTX *)0x0) && (c = BN_CTX_new(), param_5 = c, c == (BN_CTX *)0x0)) {
        return (BIGNUM *)0x0;
      }
      if ((pBVar1 == (BIGNUM *)0x0) ||
         (pBVar2 = (BIGNUM *)
                   (**(code **)(*param_1 + 0x94))(param_1,param_3,param_1 + 0x1d,param_5,pBVar2),
         pBVar2 != (BIGNUM *)0x0)) {
        if (pBVar3 == (BIGNUM *)0x0) {
          pBVar2 = (BIGNUM *)0x1;
        }
        else {
          pBVar2 = (BIGNUM *)(**(code **)(*param_1 + 0x94))(param_1,param_4,param_1 + 0x22,param_5);
          if (pBVar2 != (BIGNUM *)0x0) {
            pBVar2 = (BIGNUM *)0x1;
          }
        }
      }
      if (c != (BN_CTX *)0x0) {
        BN_CTX_free(c);
        return pBVar2;
      }
      return pBVar2;
    }
    if ((pBVar1 != (BIGNUM *)0x0) &&
       (pBVar2 = BN_copy(param_3,(BIGNUM *)(param_1 + 0x1d)), pBVar2 == (BIGNUM *)0x0)) {
      return (BIGNUM *)0x0;
    }
    if (pBVar3 != (BIGNUM *)0x0) {
      pBVar2 = BN_copy(param_4,(BIGNUM *)(param_1 + 0x22));
      if (pBVar2 != (BIGNUM *)0x0) {
        pBVar2 = (BIGNUM *)0x1;
      }
      return pBVar2;
    }
  }
  return (BIGNUM *)0x1;
}

