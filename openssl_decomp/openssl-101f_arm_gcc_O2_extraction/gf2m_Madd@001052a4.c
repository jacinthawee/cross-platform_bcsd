
int gf2m_Madd(int *param_1,BIGNUM *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
             undefined4 param_6,BN_CTX *param_7)

{
  BIGNUM *a;
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  int iVar3;
  
  BN_CTX_start(param_7);
  a = BN_CTX_get(param_7);
  pBVar1 = BN_CTX_get(param_7);
  if (((((pBVar1 == (BIGNUM *)0x0) || (pBVar2 = BN_copy(a,param_2), pBVar2 == (BIGNUM *)0x0)) ||
       (iVar3 = (**(code **)(*param_1 + 0x84))(param_1,param_3,param_3,param_6,param_7), iVar3 == 0)
       ) || ((iVar3 = (**(code **)(*param_1 + 0x84))(param_1,param_4,param_4,param_5,param_7),
             iVar3 == 0 ||
             (iVar3 = (**(code **)(*param_1 + 0x84))(param_1,pBVar1,param_3,param_4,param_7),
             iVar3 == 0)))) ||
     ((iVar3 = BN_GF2m_add(param_4,param_4,param_3), iVar3 == 0 ||
      ((iVar3 = (**(code **)(*param_1 + 0x88))(param_1,param_4,param_4,param_7), iVar3 == 0 ||
       (iVar3 = (**(code **)(*param_1 + 0x84))(param_1,param_3,param_4,a,param_7), iVar3 == 0))))))
  {
    iVar3 = 0;
  }
  else {
    iVar3 = BN_GF2m_add(param_3,param_3,pBVar1);
    if (iVar3 != 0) {
      iVar3 = 1;
    }
  }
  BN_CTX_end(param_7);
  return iVar3;
}

