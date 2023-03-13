
int ec_GF2m_simple_invert(EC_GROUP *param_1,EC_POINT *param_2,BN_CTX *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = EC_POINT_is_at_infinity(param_1,param_2);
  iVar2 = 1;
  if ((iVar1 == 0) && (*(int *)(param_2 + 0x1c) != 0)) {
    iVar2 = EC_POINT_make_affine(param_1,param_2,param_3);
    if (iVar2 != 0) {
      iVar1 = BN_GF2m_add();
      return iVar1;
    }
  }
  return iVar2;
}

