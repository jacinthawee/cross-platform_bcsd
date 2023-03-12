
/* WARNING: Restarted to delay deadcode elimination for space: ram */

EVP_PKEY_ASN1_METHOD * EVP_PKEY_asn1_find_str(ENGINE **pe,char *str,int len)

{
  undefined *puVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  ENGINE *local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (len == -1) {
    len = (*(code *)PTR_strlen_006a9a24)(str);
  }
  if (pe != (ENGINE **)0x0) {
    pEVar2 = (EVP_PKEY_ASN1_METHOD *)
             (*(code *)PTR_ENGINE_pkey_asn1_find_str_006a8dbc)(&local_30,str,len);
    if (pEVar2 != (EVP_PKEY_ASN1_METHOD *)0x0) {
      iVar3 = (*(code *)PTR_ENGINE_init_006a7d78)(local_30);
      if (iVar3 == 0) {
        pEVar2 = (EVP_PKEY_ASN1_METHOD *)0x0;
      }
      (*(code *)PTR_ENGINE_free_006a6e84)(local_30);
      *pe = local_30;
      goto LAB_00562e08;
    }
    *pe = (ENGINE *)0x0;
  }
  iVar3 = 0;
  puVar5 = standard_methods;
  if (app_methods == 0) goto LAB_00562ec4;
  while (iVar4 = (*(code *)PTR_sk_num_006a6e2c)(), iVar3 < iVar4 + 0xb) {
    while( true ) {
      if (iVar3 < 0xb) {
        pEVar2 = *(EVP_PKEY_ASN1_METHOD **)puVar5;
      }
      else {
        pEVar2 = (EVP_PKEY_ASN1_METHOD *)(*(code *)PTR_sk_value_006a6e24)(app_methods,iVar3 + -0xb);
      }
      if ((*(uint *)(pEVar2 + 8) & 1) == 0) {
        uVar6 = *(undefined4 *)(pEVar2 + 0xc);
        iVar4 = (*(code *)PTR_strlen_006a9a24)(uVar6);
        if ((len == iVar4) &&
           (iVar4 = (*(code *)PTR_strncasecmp_006a99d4)(uVar6,str,len), iVar4 == 0))
        goto LAB_00562e08;
      }
      puVar5 = (undefined1 *)((int)puVar5 + 4);
      iVar3 = iVar3 + 1;
      if (app_methods != 0) break;
LAB_00562ec4:
      if (10 < iVar3) goto LAB_00562ed4;
    }
  }
LAB_00562ed4:
  pEVar2 = (EVP_PKEY_ASN1_METHOD *)0x0;
LAB_00562e08:
  if (local_2c == *(int *)puVar1) {
    return pEVar2;
  }
  iVar3 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (((app_methods != 0) ||
      (app_methods = (*(code *)PTR_sk_new_006a806c)(ameth_cmp), app_methods != 0)) &&
     (iVar3 = (*(code *)PTR_sk_push_006a6fa8)(app_methods,iVar3), iVar3 != 0)) {
    (*(code *)PTR_sk_sort_006a83bc)(app_methods);
    return (EVP_PKEY_ASN1_METHOD *)0x1;
  }
  return (EVP_PKEY_ASN1_METHOD *)0x0;
}

