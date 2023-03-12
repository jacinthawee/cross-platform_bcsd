
undefined4 add_attribute(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_1;
  if (iVar2 == 0) {
    iVar2 = (*(code *)PTR_sk_new_null_006a6fa4)();
    *param_1 = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
  }
  else {
    for (iVar3 = 0; iVar2 = (*(code *)PTR_sk_num_006a6e2c)(iVar2), iVar3 < iVar2; iVar3 = iVar3 + 1)
    {
      puVar1 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(*param_1,iVar3);
      iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar1);
      if (iVar2 == param_2) {
        (*(code *)PTR_X509_ATTRIBUTE_free_006a8ae4)(puVar1);
        iVar2 = (*(code *)PTR_X509_ATTRIBUTE_create_006a913c)(param_2,param_3,param_4);
        if (iVar2 == 0) {
          return 0;
        }
        iVar3 = (*(code *)PTR_sk_set_006a8358)(*param_1,iVar3,iVar2);
        if (iVar3 != 0) {
          return 1;
        }
        (*(code *)PTR_X509_ATTRIBUTE_free_006a8ae4)(iVar2);
        return 0;
      }
      iVar2 = *param_1;
    }
  }
  iVar2 = (*(code *)PTR_X509_ATTRIBUTE_create_006a913c)(param_2,param_3,param_4);
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = (*(code *)PTR_sk_push_006a6fa8)(*param_1,iVar2);
  if (iVar3 != 0) {
    return 1;
  }
  (*(code *)PTR_X509_ATTRIBUTE_free_006a8ae4)(iVar2);
  return 0;
}

