
int get_email(X509_NAME *param_1,undefined4 param_2)

{
  X509_NAME_ENTRY *ne;
  ASN1_STRING *pAVar1;
  int iVar2;
  int *piVar3;
  uchar *puVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  iVar5 = -1;
  do {
    do {
      iVar5 = X509_NAME_get_index_by_NID(param_1,0x30,iVar5);
      if (iVar5 < 0) {
        iVar2 = 0;
        iVar5 = (*(code *)PTR_sk_num_006a7f2c)(param_2);
        if (iVar5 < 1) {
          return iVar6;
        }
        goto LAB_0058c2b0;
      }
      ne = X509_NAME_get_entry(param_1,iVar5);
      pAVar1 = X509_NAME_ENTRY_get_data(ne);
    } while (((pAVar1->type != 0x16) || (puVar4 = pAVar1->data, puVar4 == (uchar *)0x0)) ||
            (pAVar1->length == 0));
    if (iVar6 == 0) {
      iVar6 = (*(code *)PTR_sk_new_006a91b4)(sk_strcmp);
      if (iVar6 == 0) {
        return 0;
      }
      puVar4 = pAVar1->data;
    }
    iVar2 = (*(code *)PTR_sk_find_006a906c)(iVar6,puVar4);
  } while ((iVar2 != -1) ||
          ((iVar2 = (*(code *)PTR_BUF_strdup_006a80dc)(pAVar1->data), iVar2 != 0 &&
           (iVar2 = (*(code *)PTR_sk_push_006a80a8)(iVar6,iVar2), iVar2 != 0))));
LAB_0058c23c:
  (*(code *)PTR_sk_pop_free_006a8158)(iVar6,str_free);
  return 0;
LAB_0058c2b0:
  piVar3 = (int *)(*(code *)PTR_sk_value_006a7f24)(param_2,iVar2);
  if ((((*piVar3 == 1) && (piVar3 = (int *)piVar3[1], piVar3[1] == 0x16)) &&
      (iVar5 = piVar3[2], iVar5 != 0)) && (*piVar3 != 0)) {
    if (iVar6 == 0) {
      iVar6 = (*(code *)PTR_sk_new_006a91b4)(sk_strcmp);
      if (iVar6 == 0) {
        return 0;
      }
      iVar5 = piVar3[2];
    }
    iVar5 = (*(code *)PTR_sk_find_006a906c)(iVar6,iVar5);
    if ((iVar5 == -1) &&
       ((iVar5 = (*(code *)PTR_BUF_strdup_006a80dc)(piVar3[2]), iVar5 == 0 ||
        (iVar5 = (*(code *)PTR_sk_push_006a80a8)(iVar6,iVar5), iVar5 == 0)))) goto LAB_0058c23c;
  }
  iVar2 = iVar2 + 1;
  iVar5 = (*(code *)PTR_sk_num_006a7f2c)(param_2);
  if (iVar5 <= iVar2) {
    return iVar6;
  }
  goto LAB_0058c2b0;
}

