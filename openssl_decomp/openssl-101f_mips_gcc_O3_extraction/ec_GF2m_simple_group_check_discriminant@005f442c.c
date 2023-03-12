
bool ec_GF2m_simple_group_check_discriminant(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  
  if (param_2 == 0) {
    param_2 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    iVar4 = param_2;
    if (param_2 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x9f,0x41,"ec2_smpl.c",0x115);
      return false;
    }
  }
  else {
    iVar4 = 0;
  }
  (*(code *)PTR_BN_CTX_start_006a9644)(param_2);
  iVar1 = (*(code *)PTR_BN_CTX_get_006a9648)(param_2);
  if ((iVar1 == 0) ||
     (iVar2 = (*(code *)PTR_BN_GF2m_mod_arr_006aa7a4)(iVar1,param_1 + 0x88,param_1 + 0x5c),
     iVar2 == 0)) {
    bVar3 = false;
  }
  else {
    bVar3 = *(int *)(iVar1 + 4) != 0;
  }
  (*(code *)PTR_BN_CTX_end_006a9654)(param_2);
  if (iVar4 != 0) {
    (*(code *)PTR_BN_CTX_free_006a8a40)(iVar4);
  }
  return bVar3;
}

