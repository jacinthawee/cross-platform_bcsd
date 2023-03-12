
int pkey_ec_derive(int param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 8) != 0) && (*(int *)(param_1 + 0xc) != 0)) {
    if (param_2 == 0) {
      uVar1 = (*(code *)PTR_EC_KEY_get0_group_006a7690)
                        (*(undefined4 *)(*(int *)(param_1 + 8) + 0x14));
      iVar3 = (*(code *)PTR_EC_GROUP_get_degree_006a7ae0)(uVar1);
      iVar2 = iVar3 + 7;
      if (iVar3 + 7 < 0) {
        iVar2 = iVar3 + 0xe;
      }
      *param_3 = iVar2 >> 3;
    }
    else {
      uVar1 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)
                        (*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x14));
      iVar2 = (*(code *)PTR_ECDH_compute_key_006a7ae8)
                        (param_2,*param_3,uVar1,*(undefined4 *)(*(int *)(param_1 + 8) + 0x14),0);
      if (iVar2 < 0) {
        return iVar2;
      }
      *param_3 = iVar2;
    }
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xd9,0x8c,"ec_pmeth.c",0xac);
  return 0;
}

