
bool ec_GF2m_simple_group_check_discriminant(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  
  if (param_2 == 0) {
    param_2 = (*(code *)PTR_BN_CTX_new_006a794c)();
    iVar4 = param_2;
    if (param_2 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9f,0x41,"ec2_smpl.c",300);
      return false;
    }
  }
  else {
    iVar4 = 0;
  }
  (*(code *)PTR_BN_CTX_start_006a8528)(param_2);
  iVar1 = (*(code *)PTR_BN_CTX_get_006a852c)(param_2);
  if ((iVar1 == 0) ||
     (iVar2 = (*(code *)PTR_BN_GF2m_mod_arr_006a9698)(iVar1,param_1 + 0x88,param_1 + 0x5c),
     iVar2 == 0)) {
    bVar3 = false;
  }
  else {
    bVar3 = *(int *)(iVar1 + 4) != 0;
  }
  (*(code *)PTR_BN_CTX_end_006a8530)(param_2);
  if (iVar4 != 0) {
    (*(code *)PTR_BN_CTX_free_006a7954)(iVar4);
  }
  return bVar3;
}

