
undefined4 copy_extensions(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {
    return 1;
  }
  iVar6 = 0;
  uVar1 = (*(code *)PTR_X509_REQ_get_extensions_006a8c9c)(param_2);
  iVar2 = (*(code *)PTR_sk_num_006a7f2c)(uVar1);
  if (0 < iVar2) {
    do {
      uVar3 = (*(code *)PTR_sk_value_006a7f24)(uVar1,iVar6);
      uVar4 = (*(code *)PTR_X509_EXTENSION_get_object_006a8ca0)(uVar3);
      iVar2 = (*(code *)PTR_X509_get_ext_by_OBJ_006a8ca4)(param_1,uVar4,0xffffffff);
      if (iVar2 == -1) {
LAB_0045b1a8:
        iVar2 = (*(code *)PTR_X509_add_ext_006a8cac)(param_1,uVar3,0xffffffff);
        if (iVar2 == 0) {
          uVar3 = 0;
          goto LAB_0045b1ec;
        }
      }
      else if (param_3 != 1) {
        do {
          uVar5 = (*(code *)PTR_X509_get_ext_006a8ca8)(param_1,iVar2);
          (*(code *)PTR_X509_delete_ext_006a87cc)(param_1,iVar2);
          (*(code *)PTR_X509_EXTENSION_free_006a8268)(uVar5);
          iVar2 = (*(code *)PTR_X509_get_ext_by_OBJ_006a8ca4)(param_1,uVar4,0xffffffff);
        } while (iVar2 != -1);
        goto LAB_0045b1a8;
      }
      iVar6 = iVar6 + 1;
      iVar2 = (*(code *)PTR_sk_num_006a7f2c)(uVar1);
    } while (iVar6 < iVar2);
  }
  uVar3 = 1;
LAB_0045b1ec:
  (*(code *)PTR_sk_pop_free_006a8158)(uVar1,PTR_X509_EXTENSION_free_006a8268);
  return uVar3;
}

