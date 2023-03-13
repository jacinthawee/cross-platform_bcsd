
bool ec_GF2m_simple_group_get_curve(int param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4)

{
  BIGNUM *pBVar1;
  bool bVar2;
  
  if ((param_2 != (BIGNUM *)0x0) &&
     (pBVar1 = BN_copy(param_2,(BIGNUM *)(param_1 + 0x48)), pBVar1 == (BIGNUM *)0x0)) {
    return false;
  }
  if ((param_3 != (BIGNUM *)0x0) &&
     (pBVar1 = BN_copy(param_3,(BIGNUM *)(param_1 + 0x74)), pBVar1 == (BIGNUM *)0x0)) {
    return false;
  }
  bVar2 = true;
  if (param_4 != (BIGNUM *)0x0) {
    pBVar1 = BN_copy(param_4,(BIGNUM *)(param_1 + 0x88));
    bVar2 = pBVar1 != (BIGNUM *)0x0;
  }
  return bVar2;
}

