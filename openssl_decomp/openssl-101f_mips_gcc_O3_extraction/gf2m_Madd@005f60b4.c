
bool gf2m_Madd(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  (*(code *)PTR_BN_CTX_start_006a9644)(param_7);
  uVar1 = (*(code *)PTR_BN_CTX_get_006a9648)(param_7);
  iVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_7);
  if (iVar2 != 0) {
    iVar3 = (*(code *)PTR_BN_copy_006a9570)(uVar1,param_2);
    if (iVar3 != 0) {
      iVar3 = (**(code **)(*param_1 + 0x84))(param_1,param_3,param_3,param_6,param_7);
      if (iVar3 != 0) {
        iVar3 = (**(code **)(*param_1 + 0x84))(param_1,param_4,param_4,param_5,param_7);
        if (iVar3 != 0) {
          iVar3 = (**(code **)(*param_1 + 0x84))(param_1,iVar2,param_3,param_4,param_7);
          if (iVar3 != 0) {
            iVar3 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(param_4,param_4,param_3);
            if (iVar3 != 0) {
              iVar3 = (**(code **)(*param_1 + 0x88))(param_1,param_4,param_4,param_7);
              if (iVar3 != 0) {
                iVar3 = (**(code **)(*param_1 + 0x84))(param_1,param_3,param_4,uVar1,param_7);
                if (iVar3 != 0) {
                  iVar2 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(param_3,param_3,iVar2);
                  bVar4 = iVar2 != 0;
                  goto LAB_005f6178;
                }
              }
            }
          }
        }
      }
    }
  }
  bVar4 = false;
LAB_005f6178:
  (*(code *)PTR_BN_CTX_end_006a9654)(param_7);
  return bVar4;
}

