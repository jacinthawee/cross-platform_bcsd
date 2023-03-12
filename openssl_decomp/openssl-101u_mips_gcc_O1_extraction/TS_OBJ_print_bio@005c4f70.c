
undefined4 TS_OBJ_print_bio(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  undefined auStack_94 [128];
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_OBJ_obj2txt_006a8c9c)(auStack_94,0x80,param_2,0);
  pcVar7 = "%s\n";
  (*(code *)PTR_BIO_printf_006a6e38)(param_1,"%s\n",auStack_94);
  if (local_14 == *(int *)puVar1) {
    return 1;
  }
  iVar6 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  (*(code *)PTR_BIO_printf_006a6e38)();
  iVar2 = (*(code *)PTR_X509v3_get_ext_count_006a8f44)(pcVar7);
  if (0 < iVar2) {
    iVar9 = 0;
    do {
      while( true ) {
        iVar3 = (*(code *)PTR_X509v3_get_ext_006a8f54)(pcVar7,iVar9);
        uVar4 = (*(code *)PTR_X509_EXTENSION_get_object_006a7bb4)(iVar3);
        (*(code *)PTR_i2a_ASN1_OBJECT_006a702c)(iVar6,uVar4);
        iVar5 = (*(code *)PTR_X509_EXTENSION_get_critical_006a8d4c)(iVar3);
        pcVar8 = "critical";
        if (iVar5 == 0) {
          pcVar8 = "";
        }
        iVar9 = iVar9 + 1;
        (*(code *)PTR_BIO_printf_006a6e38)(iVar6,": %s\n",pcVar8);
        iVar5 = (*(code *)PTR_X509V3_EXT_print_006a8d50)(iVar6,iVar3,0,4);
        if (iVar5 != 0) break;
        (*(code *)PTR_BIO_printf_006a6e38)(iVar6,&DAT_00672f50,"");
        (*(code *)PTR_ASN1_STRING_print_006a8d54)(iVar6,*(undefined4 *)(iVar3 + 8));
        (*(code *)PTR_BIO_write_006a6e14)(iVar6,"\n",1);
        if (iVar2 == iVar9) {
          return 1;
        }
      }
      (*(code *)PTR_BIO_write_006a6e14)(iVar6,"\n",1);
    } while (iVar2 != iVar9);
  }
  return 1;
}

