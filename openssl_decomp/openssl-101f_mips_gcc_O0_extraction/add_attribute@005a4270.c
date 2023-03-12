
undefined4 add_attribute(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_1;
  if (iVar2 == 0) {
    iVar2 = (*(code *)PTR_sk_new_null_006a80a4)();
    *param_1 = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
  }
  else {
    for (iVar3 = 0; iVar2 = (*(code *)PTR_sk_num_006a7f2c)(iVar2), iVar3 < iVar2; iVar3 = iVar3 + 1)
    {
      puVar1 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(*param_1,iVar3);
      iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar1);
      if (iVar2 == param_2) {
        (*(code *)PTR_X509_ATTRIBUTE_free_006a9c00)(puVar1);
        iVar2 = (*(code *)PTR_X509_ATTRIBUTE_create_006aa258)(param_2,param_3,param_4);
        if (iVar2 == 0) {
          return 0;
        }
        iVar3 = (*(code *)PTR_sk_set_006a9478)(*param_1,iVar3,iVar2);
        if (iVar3 != 0) {
          return 1;
        }
        (*(code *)PTR_X509_ATTRIBUTE_free_006a9c00)(iVar2);
        return 0;
      }
      iVar2 = *param_1;
    }
  }
  iVar2 = (*(code *)PTR_X509_ATTRIBUTE_create_006aa258)(param_2,param_3,param_4);
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = (*(code *)PTR_sk_push_006a80a8)(*param_1,iVar2);
  if (iVar3 != 0) {
    return 1;
  }
  (*(code *)PTR_X509_ATTRIBUTE_free_006a9c00)(iVar2);
  return 0;
}

