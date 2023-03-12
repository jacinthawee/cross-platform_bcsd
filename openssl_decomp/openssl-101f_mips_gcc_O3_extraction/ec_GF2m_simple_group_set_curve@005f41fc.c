
undefined4
ec_GF2m_simple_group_set_curve(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar1 = (*(code *)PTR_BN_copy_006a9570)(param_1 + 0x48);
  if (iVar1 != 0) {
    iVar1 = param_1 + 0x5c;
    uVar2 = (*(code *)PTR_BN_GF2m_poly2arr_006aa7a0)(param_1 + 0x48,iVar1,6);
    if ((uVar2 & 0xfffffffd) == 4) {
      iVar5 = param_1 + 0x74;
      iVar3 = (*(code *)PTR_BN_GF2m_mod_arr_006aa7a4)(iVar5,param_3,iVar1);
      if (iVar3 != 0) {
        iVar3 = *(int *)(param_1 + 0x5c) + 0x1f;
        if (iVar3 < 0) {
          iVar3 = *(int *)(param_1 + 0x5c) + 0x3e;
        }
        if (*(int *)(param_1 + 0x7c) < iVar3 >> 5) {
          iVar3 = (*(code *)PTR_bn_expand2_006a9680)(iVar5);
          if (iVar3 == 0) {
            return 0;
          }
        }
        else if (iVar5 == 0) {
          return 0;
        }
        iVar3 = *(int *)(param_1 + 0x78);
        if (iVar3 < *(int *)(param_1 + 0x7c)) {
          puVar4 = (undefined4 *)(*(int *)(param_1 + 0x74) + iVar3 * 4);
          do {
            *puVar4 = 0;
            iVar3 = iVar3 + 1;
            puVar4 = puVar4 + 1;
          } while (iVar3 < *(int *)(param_1 + 0x7c));
        }
        iVar1 = (*(code *)PTR_BN_GF2m_mod_arr_006aa7a4)(param_1 + 0x88,param_4,iVar1);
        if (iVar1 != 0) {
          iVar3 = *(int *)(param_1 + 0x90);
          iVar1 = *(int *)(param_1 + 0x5c) + 0x1f;
          if (iVar1 < 0) {
            iVar1 = *(int *)(param_1 + 0x5c) + 0x3e;
          }
          if (iVar3 < iVar1 >> 5) {
            iVar1 = (*(code *)PTR_bn_expand2_006a9680)(param_1 + 0x88);
            if (iVar1 == 0) {
              return 0;
            }
            iVar3 = *(int *)(param_1 + 0x90);
          }
          iVar1 = *(int *)(param_1 + 0x8c);
          if (iVar3 <= iVar1) {
            return 1;
          }
          puVar4 = (undefined4 *)(*(int *)(param_1 + 0x88) + iVar1 * 4);
          do {
            *puVar4 = 0;
            iVar1 = iVar1 + 1;
            puVar4 = puVar4 + 1;
          } while (iVar1 < *(int *)(param_1 + 0x90));
          return 1;
        }
      }
    }
    else {
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xc3,0x83,"ec2_smpl.c",0xcf);
    }
  }
  return 0;
}

