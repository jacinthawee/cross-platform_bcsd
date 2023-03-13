
int * CMS_ReceiptRequest_create0
                (int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  piVar1 = (int *)(*(code *)PTR_ASN1_item_new_006a8654)(PTR_CMS_ReceiptRequest_it_006a93ec);
  if (piVar1 == (int *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x9f,0x41,s_cms_ess_c_006721bc,0x80);
  }
  else {
    if (param_1 == 0) {
      iVar3 = (*(code *)PTR_ASN1_STRING_set_006a7d1c)(*piVar1,0,0x20);
      if (iVar3 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x9f,0x41,s_cms_ess_c_006721bc,0x80);
LAB_005bd9b0:
        (*(code *)PTR_ASN1_item_free_006a8658)(piVar1,PTR_CMS_ReceiptRequest_it_006a93ec);
        return (int *)0x0;
      }
      iVar3 = (*(code *)PTR_RAND_bytes_006a7574)(*(undefined4 *)(*piVar1 + 8),0x20);
      if (iVar3 < 1) goto LAB_005bd9b0;
    }
    else {
      (*(code *)PTR_ASN1_STRING_set0_006a9144)(*piVar1,param_1,param_2);
    }
    (*(code *)PTR_sk_pop_free_006a7058)(piVar1[2],PTR_GENERAL_NAMES_free_006a73a0);
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

