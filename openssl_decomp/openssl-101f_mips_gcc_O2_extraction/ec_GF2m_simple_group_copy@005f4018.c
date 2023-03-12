
undefined4 ec_GF2m_simple_group_copy(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar1 = (*(code *)PTR_BN_copy_006a9570)(param_1 + 0x48,param_2 + 0x48);
  if (iVar1 != 0) {
    iVar1 = param_1 + 0x74;
    iVar2 = (*(code *)PTR_BN_copy_006a9570)(iVar1,param_2 + 0x74);
    if (iVar2 != 0) {
      iVar2 = param_1 + 0x88;
      iVar3 = (*(code *)PTR_BN_copy_006a9570)(iVar2,param_2 + 0x88);
      if (iVar3 != 0) {
        iVar4 = *(int *)(param_2 + 0x5c);
        *(int *)(param_1 + 0x5c) = iVar4;
        iVar3 = iVar4 + 0x1f;
        if (iVar4 + 0x1f < 0) {
          iVar3 = iVar4 + 0x3e;
        }
        *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_2 + 0x60);
        *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_2 + 100);
        *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_2 + 0x68);
        *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_2 + 0x6c);
        *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_2 + 0x70);
        if (*(int *)(param_1 + 0x7c) < iVar3 >> 5) {
          iVar1 = (*(code *)PTR_bn_expand2_006a9680)(iVar1);
        }
        if (iVar1 != 0) {
          iVar1 = *(int *)(param_1 + 0x5c) + 0x1f;
          if (iVar1 < 0) {
            iVar1 = *(int *)(param_1 + 0x5c) + 0x3e;
          }
          if (*(int *)(param_1 + 0x90) < iVar1 >> 5) {
            iVar2 = (*(code *)PTR_bn_expand2_006a9680)(iVar2);
          }
          if (iVar2 != 0) {
            iVar1 = *(int *)(param_1 + 0x78);
            if (iVar1 < *(int *)(param_1 + 0x7c)) {
              puVar5 = (undefined4 *)(*(int *)(param_1 + 0x74) + iVar1 * 4);
              do {
                *puVar5 = 0;
                iVar1 = iVar1 + 1;
                puVar5 = puVar5 + 1;
              } while (iVar1 < *(int *)(param_1 + 0x7c));
            }
            iVar1 = *(int *)(param_1 + 0x8c);
            if (iVar1 < *(int *)(param_1 + 0x90)) {
              puVar5 = (undefined4 *)(*(int *)(param_1 + 0x88) + iVar1 * 4);
              do {
                *puVar5 = 0;
                iVar1 = iVar1 + 1;
                puVar5 = puVar5 + 1;
              } while (iVar1 < *(int *)(param_1 + 0x90));
            }
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

