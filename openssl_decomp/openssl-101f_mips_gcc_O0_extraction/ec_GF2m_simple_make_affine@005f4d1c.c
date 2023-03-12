
bool ec_GF2m_simple_make_affine(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  if ((*(int *)(param_2 + 0x40) == 0) &&
     (iVar1 = (*(code *)PTR_EC_POINT_is_at_infinity_006a9770)(), iVar1 == 0)) {
    if (param_3 == 0) {
      param_3 = (*(code *)PTR_BN_CTX_new_006a8a38)();
      if (param_3 == 0) {
        return false;
      }
      (*(code *)PTR_BN_CTX_start_006a9644)(param_3);
      uVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_3);
      iVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(param_3);
      iVar1 = param_3;
      if (iVar3 == 0) {
        bVar5 = false;
        (*(code *)PTR_BN_CTX_end_006a9654)(param_3);
        goto LAB_005f4e24;
      }
    }
    else {
      (*(code *)PTR_BN_CTX_start_006a9644)(param_3);
      uVar2 = (*(code *)PTR_BN_CTX_get_006a9648)(param_3);
      iVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(param_3);
      if (iVar3 == 0) {
        (*(code *)PTR_BN_CTX_end_006a9654)(param_3);
        return false;
      }
      iVar1 = 0;
    }
    iVar4 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GF2m_006a97b8)
                      (param_1,param_2,uVar2,iVar3,param_3);
    if (((iVar4 == 0) || (iVar4 = (*(code *)PTR_BN_copy_006a9570)(param_2 + 4,uVar2), iVar4 == 0))
       || (iVar3 = (*(code *)PTR_BN_copy_006a9570)(param_2 + 0x18,iVar3), iVar3 == 0)) {
      bVar5 = false;
    }
    else {
      iVar3 = (*(code *)PTR_BN_set_word_006a8820)(param_2 + 0x2c,1);
      bVar5 = iVar3 != 0;
    }
    (*(code *)PTR_BN_CTX_end_006a9654)(param_3);
    param_3 = iVar1;
    if (iVar1 != 0) {
LAB_005f4e24:
      (*(code *)PTR_BN_CTX_free_006a8a40)(param_3);
      return bVar5;
    }
  }
  else {
    bVar5 = true;
  }
  return bVar5;
}

