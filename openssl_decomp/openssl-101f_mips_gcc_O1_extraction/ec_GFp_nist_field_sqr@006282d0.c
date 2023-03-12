
bool ec_GFp_nist_field_sqr(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xc9,0x86,"ecp_nist.c",0xca);
  }
  else if (param_4 == 0) {
    iVar1 = (*(code *)PTR_BN_CTX_new_006a8a38)(param_1,param_3);
    if (iVar1 != 0) {
      bVar3 = false;
      iVar2 = (*(code *)PTR_BN_sqr_006a964c)(param_2,param_3,iVar1);
      if (iVar2 != 0) {
        iVar2 = (**(code **)(param_1 + 0xa8))(param_2,param_2,param_1 + 0x48,iVar1);
        bVar3 = iVar2 != 0;
      }
      (*(code *)PTR_BN_CTX_free_006a8a40)(iVar1);
      return bVar3;
    }
  }
  else {
    iVar1 = (*(code *)PTR_BN_sqr_006a964c)(param_2,param_3,param_4);
    if (iVar1 != 0) {
      iVar1 = (**(code **)(param_1 + 0xa8))(param_2,param_2,param_1 + 0x48,param_4);
      return iVar1 != 0;
    }
  }
  return false;
}

