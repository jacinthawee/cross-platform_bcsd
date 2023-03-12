
int v2i_AUTHORITY_INFO_ACCESS(X509V3_EXT_METHOD *param_1,X509V3_CTX *param_2,undefined4 param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  GENERAL_NAME *pGVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  CONF_VALUE CStack_38;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar3 = (*(code *)PTR_sk_new_null_006a6fa4)();
  if (iVar3 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x8b,0x41,"v3_info.c",0x9d);
    iVar3 = 0;
  }
  else {
    for (iVar11 = 0; iVar7 = (*(code *)PTR_sk_num_006a6e2c)(param_3), iVar11 < iVar7;
        iVar11 = iVar11 + 1) {
      iVar7 = (*(code *)PTR_sk_value_006a6e24)(param_3,iVar11);
      piVar4 = (int *)(*(code *)PTR_ASN1_item_new_006a8654)(ACCESS_DESCRIPTION_it);
      if ((piVar4 == (int *)0x0) ||
         (iVar5 = (*(code *)PTR_sk_push_006a6fa8)(iVar3,piVar4), iVar5 == 0)) {
        uVar9 = 0x41;
        uVar8 = 0xa5;
LAB_00595d44:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x8b,uVar9,"v3_info.c",uVar8);
LAB_00595d58:
        (*(code *)PTR_sk_pop_free_006a7058)(iVar3,ACCESS_DESCRIPTION_free);
        iVar3 = 0;
        break;
      }
      iVar10 = *(int *)(iVar7 + 4);
      iVar5 = (*(code *)PTR_strchr_006a9a28)(iVar10,0x3b);
      if (iVar5 == 0) {
        uVar9 = 0x8f;
        uVar8 = 0xab;
        goto LAB_00595d44;
      }
      CStack_38.value = *(char **)(iVar7 + 8);
      CStack_38.name = (char *)(iVar5 + 1);
      iVar5 = iVar5 - iVar10;
      pGVar6 = v2i_GENERAL_NAME_ex((GENERAL_NAME *)piVar4[1],param_1,param_2,&CStack_38,0);
      if (pGVar6 == (GENERAL_NAME *)0x0) goto LAB_00595d58;
      iVar10 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar5 + 1,"v3_info.c",0xb3);
      if (iVar10 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x8b,0x41,"v3_info.c",0xb5);
        goto LAB_00595d58;
      }
      (*(code *)PTR_strncpy_006a99e0)(iVar10,*(undefined4 *)(iVar7 + 4),iVar5);
      puVar1 = PTR_OBJ_txt2obj_006a7000;
      *(undefined *)(iVar10 + iVar5) = 0;
      iVar7 = (*(code *)puVar1)(iVar10,0);
      *piVar4 = iVar7;
      if (iVar7 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x8b,0x77,"v3_info.c",0xbd);
        (*(code *)PTR_ERR_add_error_data_006a813c)(2,"value=",iVar10);
        (*(code *)PTR_CRYPTO_free_006a6e88)(iVar10);
        goto LAB_00595d58;
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar10);
    }
  }
  if (local_2c != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
                    /* WARNING: Could not recover jumptable at 0x00595e94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar3 = (*(code *)PTR_ASN1_item_free_006a8658)();
    return iVar3;
  }
  return iVar3;
}

