
bool __regparm3
gf2m_Madd(int *param_1_00,BIGNUM *param_2_00,undefined4 param_3_00,undefined4 param_1,
         undefined4 param_2,undefined4 param_3,BN_CTX *param_4)

{
  BIGNUM *a;
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  int iVar3;
  bool bVar4;
  
  BN_CTX_start(param_4);
  a = BN_CTX_get(param_4);
  pBVar1 = BN_CTX_get(param_4);
  if (pBVar1 != (BIGNUM *)0x0) {
    pBVar2 = BN_copy(a,param_2_00);
    if (pBVar2 != (BIGNUM *)0x0) {
      iVar3 = (**(code **)(*param_1_00 + 0x84))(param_1_00,param_3_00,param_3_00,param_3,param_4);
      if (iVar3 != 0) {
        iVar3 = (**(code **)(*param_1_00 + 0x84))(param_1_00,param_1,param_1,param_2,param_4);
        if (iVar3 != 0) {
          iVar3 = (**(code **)(*param_1_00 + 0x84))(param_1_00,pBVar1,param_3_00,param_1,param_4);
          if (iVar3 != 0) {
            iVar3 = BN_GF2m_add(param_1,param_1,param_3_00);
            if (iVar3 != 0) {
              iVar3 = (**(code **)(*param_1_00 + 0x88))(param_1_00,param_1,param_1,param_4);
              if (iVar3 != 0) {
                iVar3 = (**(code **)(*param_1_00 + 0x84))(param_1_00,param_3_00,param_1,a,param_4);
                if (iVar3 != 0) {
                  iVar3 = BN_GF2m_add(param_3_00,param_3_00,pBVar1);
                  bVar4 = iVar3 != 0;
                  goto LAB_081bca7a;
                }
              }
            }
          }
        }
      }
    }
  }
  bVar4 = false;
LAB_081bca7a:
  BN_CTX_end(param_4);
  return bVar4;
}

