
int gf2m_Mdouble(int *param_1,undefined4 param_2,undefined4 param_3,BN_CTX *param_4)

{
  BIGNUM *pBVar1;
  int iVar2;
  
  BN_CTX_start(param_4);
  pBVar1 = BN_CTX_get(param_4);
  if ((((pBVar1 == (BIGNUM *)0x0) ||
       (iVar2 = (**(code **)(*param_1 + 0x88))(param_1,param_2,param_2,param_4), iVar2 == 0)) ||
      (iVar2 = (**(code **)(*param_1 + 0x88))(param_1,pBVar1,param_3,param_4), iVar2 == 0)) ||
     (((iVar2 = (**(code **)(*param_1 + 0x84))(param_1,param_3,param_2,pBVar1,param_4), iVar2 == 0
       || (iVar2 = (**(code **)(*param_1 + 0x88))(param_1,param_2,param_2,param_4), iVar2 == 0)) ||
      ((iVar2 = (**(code **)(*param_1 + 0x88))(param_1,pBVar1,pBVar1,param_4), iVar2 == 0 ||
       (iVar2 = (**(code **)(*param_1 + 0x84))(param_1,pBVar1,param_1 + 0x22,pBVar1,param_4),
       iVar2 == 0)))))) {
    iVar2 = 0;
  }
  else {
    iVar2 = BN_GF2m_add(param_2,param_2,pBVar1);
    if (iVar2 != 0) {
      iVar2 = 1;
    }
  }
  BN_CTX_end(param_4);
  return iVar2;
}

