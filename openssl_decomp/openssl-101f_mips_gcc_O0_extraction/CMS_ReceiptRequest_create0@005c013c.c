
int * CMS_ReceiptRequest_create0
                (int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  piVar1 = (int *)(*(code *)PTR_ASN1_item_new_006a9778)(PTR_CMS_ReceiptRequest_it_006aa4f8);
  if (piVar1 == (int *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x9f,0x41,s_cms_ess_c_00672aac,0x82);
  }
  else {
    if (param_1 == 0) {
      iVar3 = (*(code *)PTR_ASN1_STRING_set_006a8e0c)(*piVar1,0,0x20);
      if (iVar3 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x9f,0x41,s_cms_ess_c_00672aac,0x82);
LAB_005c0240:
        (*(code *)PTR_ASN1_item_free_006a977c)(piVar1,PTR_CMS_ReceiptRequest_it_006aa4f8);
        return (int *)0x0;
      }
      iVar3 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(*(undefined4 *)(*piVar1 + 8),0x20);
      if (iVar3 < 1) goto LAB_005c0240;
    }
    else {
      (*(code *)PTR_ASN1_STRING_set0_006aa260)(*piVar1,param_1,param_2);
    }
    (*(code *)PTR_sk_pop_free_006a8158)(piVar1[2],PTR_GENERAL_NAMES_free_006a84a0);
    piVar1[2] = param_5;
    puVar2 = (undefined4 *)piVar1[1];
    if (param_4 == 0) {
      puVar2[1] = param_3;
      *puVar2 = 0;
      return piVar1;
    }
    puVar2[1] = param_4;
    *puVar2 = 1;
  }
  return piVar1;
}

