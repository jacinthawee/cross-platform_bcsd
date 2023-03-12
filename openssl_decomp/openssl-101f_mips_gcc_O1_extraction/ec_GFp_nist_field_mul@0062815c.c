
bool ec_GFp_nist_field_mul(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  if ((((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) || (param_4 == 0)) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,200,0x43,"ecp_nist.c",0xb0);
  }
  else if (param_5 == 0) {
    iVar1 = (*(code *)PTR_BN_CTX_new_006a8a38)(param_1,param_3,param_4);
    if (iVar1 != 0) {
      bVar3 = false;
      iVar2 = (*(code *)PTR_BN_mul_006a9658)(param_2,param_3,param_4,iVar1);
      if (iVar2 != 0) {
        iVar2 = (**(code **)(param_1 + 0xa8))(param_2,param_2,param_1 + 0x48,iVar1);
        bVar3 = iVar2 != 0;
      }
      (*(code *)PTR_BN_CTX_free_006a8a40)(iVar1);
      return bVar3;
    }
  }
  else {
    iVar1 = (*(code *)PTR_BN_mul_006a9658)(param_2,param_3,param_4,param_5);
    if (iVar1 != 0) {
      iVar1 = (**(code **)(param_1 + 0xa8))(param_2,param_2,param_1 + 0x48,param_5);
      return iVar1 != 0;
    }
  }
  return false;
}

