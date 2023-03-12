
bool gf2m_Mdouble(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  (*(code *)PTR_BN_CTX_start_006a9644)(param_4);
  iVar1 = (*(code *)PTR_BN_CTX_get_006a9648)(param_4);
  if (iVar1 != 0) {
    iVar2 = (**(code **)(*param_1 + 0x88))(param_1,param_2,param_2,param_4);
    if (iVar2 != 0) {
      iVar2 = (**(code **)(*param_1 + 0x88))(param_1,iVar1,param_3,param_4);
      if (iVar2 != 0) {
        iVar2 = (**(code **)(*param_1 + 0x84))(param_1,param_3,param_2,iVar1,param_4);
        if (iVar2 != 0) {
          iVar2 = (**(code **)(*param_1 + 0x88))(param_1,param_2,param_2,param_4);
          if (iVar2 != 0) {
            iVar2 = (**(code **)(*param_1 + 0x88))(param_1,iVar1,iVar1,param_4);
            if (iVar2 != 0) {
              iVar2 = (**(code **)(*param_1 + 0x84))(param_1,iVar1,param_1 + 0x22,iVar1,param_4);
              if (iVar2 != 0) {
                iVar1 = (*(code *)PTR_BN_GF2m_add_006aa7b4)(param_2,param_2,iVar1);
                bVar3 = iVar1 != 0;
                goto LAB_005f5fa8;
              }
            }
          }
        }
      }
    }
  }
  bVar3 = false;
LAB_005f5fa8:
  (*(code *)PTR_BN_CTX_end_006a9654)(param_4);
  return bVar3;
}

