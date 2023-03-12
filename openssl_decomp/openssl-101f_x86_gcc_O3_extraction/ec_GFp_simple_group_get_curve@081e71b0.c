
bool ec_GFp_simple_group_get_curve
               (int *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,BN_CTX *param_5)

{
  BIGNUM *pBVar1;
  int iVar2;
  BN_CTX *c;
  bool bVar3;
  
  if ((param_2 != (BIGNUM *)0x0) &&
     (pBVar1 = BN_copy(param_2,(BIGNUM *)(param_1 + 0x12)), pBVar1 == (BIGNUM *)0x0)) {
    return false;
  }
  if ((param_3 == (BIGNUM *)0x0) && (param_4 == (BIGNUM *)0x0)) {
    return true;
  }
  if (*(int *)(*param_1 + 0x94) == 0) {
    if ((param_3 != (BIGNUM *)0x0) &&
       (pBVar1 = BN_copy(param_3,(BIGNUM *)(param_1 + 0x1d)), pBVar1 == (BIGNUM *)0x0)) {
      return false;
    }
    if (param_4 == (BIGNUM *)0x0) {
      return true;
    }
    pBVar1 = BN_copy(param_4,(BIGNUM *)(param_1 + 0x22));
    return pBVar1 != (BIGNUM *)0x0;
  }
  c = (BN_CTX *)0x0;
  if ((param_5 == (BN_CTX *)0x0) && (c = BN_CTX_new(), param_5 = c, c == (BN_CTX *)0x0)) {
    return false;
  }
  if (param_3 != (BIGNUM *)0x0) {
    bVar3 = false;
    iVar2 = (**(code **)(*param_1 + 0x94))(param_1,param_3,param_1 + 0x1d,param_5);
    if (iVar2 == 0) goto LAB_081e723d;
  }
  bVar3 = true;
  if (param_4 != (BIGNUM *)0x0) {
    iVar2 = (**(code **)(*param_1 + 0x94))(param_1,param_4,param_1 + 0x22,param_5);
    bVar3 = iVar2 != 0;
  }
LAB_081e723d:
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
    return bVar3;
  }
  return bVar3;
}

