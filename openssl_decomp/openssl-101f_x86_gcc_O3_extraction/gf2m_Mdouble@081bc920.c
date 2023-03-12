
bool __regparm3 gf2m_Mdouble(int *param_1_00,undefined4 param_2,undefined4 param_3,BN_CTX *param_1)

{
  BIGNUM *pBVar1;
  int iVar2;
  bool bVar3;
  
  BN_CTX_start(param_1);
  pBVar1 = BN_CTX_get(param_1);
  if (pBVar1 != (BIGNUM *)0x0) {
    iVar2 = (**(code **)(*param_1_00 + 0x88))(param_1_00,param_2,param_2,param_1);
    if (iVar2 != 0) {
      iVar2 = (**(code **)(*param_1_00 + 0x88))(param_1_00,pBVar1,param_3,param_1);
      if (iVar2 != 0) {
        iVar2 = (**(code **)(*param_1_00 + 0x84))(param_1_00,param_3,param_2,pBVar1,param_1);
        if (iVar2 != 0) {
          iVar2 = (**(code **)(*param_1_00 + 0x88))(param_1_00,param_2,param_2,param_1);
          if (iVar2 != 0) {
            iVar2 = (**(code **)(*param_1_00 + 0x88))(param_1_00,pBVar1,pBVar1,param_1);
            if (iVar2 != 0) {
              iVar2 = (**(code **)(*param_1_00 + 0x84))
                                (param_1_00,pBVar1,param_1_00 + 0x22,pBVar1,param_1);
              if (iVar2 != 0) {
                iVar2 = BN_GF2m_add(param_2,param_2,pBVar1);
                bVar3 = iVar2 != 0;
                goto LAB_081bc95f;
              }
            }
          }
        }
      }
    }
  }
  bVar3 = false;
LAB_081bc95f:
  BN_CTX_end(param_1);
  return bVar3;
}

