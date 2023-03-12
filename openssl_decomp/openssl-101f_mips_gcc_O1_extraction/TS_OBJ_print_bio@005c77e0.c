
undefined4 TS_OBJ_print_bio(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  undefined auStack_94 [128];
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar2 = (*(code *)PTR_OBJ_obj2txt_006a9dbc)(auStack_94,0x80,param_2,0);
  (*(code *)PTR_BIO_write_006a7f14)(param_1,auStack_94,uVar2);
  pcVar7 = "\n";
  (*(code *)PTR_BIO_write_006a7f14)(param_1,"\n",1);
  if (local_14 == *(int *)puVar1) {
    return 1;
  }
  iVar6 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  (*(code *)PTR_BIO_printf_006a7f38)();
  iVar3 = (*(code *)PTR_X509v3_get_ext_count_006aa060)(pcVar7);
  if (0 < iVar3) {
    iVar9 = 0;
    do {
      while( true ) {
        iVar4 = (*(code *)PTR_X509v3_get_ext_006aa070)(pcVar7,iVar9);
        uVar2 = (*(code *)PTR_X509_EXTENSION_get_object_006a8ca0)(iVar4);
        (*(code *)PTR_i2a_ASN1_OBJECT_006a812c)(iVar6,uVar2);
        iVar5 = (*(code *)PTR_X509_EXTENSION_get_critical_006a9e6c)(iVar4);
        pcVar8 = "critical";
        if (iVar5 == 0) {
          pcVar8 = "";
        }
        iVar9 = iVar9 + 1;
        (*(code *)PTR_BIO_printf_006a7f38)(iVar6,": %s\n",pcVar8);
        iVar5 = (*(code *)PTR_X509V3_EXT_print_006a9e70)(iVar6,iVar4,0,4);
        if (iVar5 != 0) break;
        (*(code *)PTR_BIO_printf_006a7f38)(iVar6,&DAT_00673860,"");
        (*(code *)PTR_ASN1_STRING_print_006a9e74)(iVar6,*(undefined4 *)(iVar4 + 8));
        (*(code *)PTR_BIO_write_006a7f14)(iVar6,"\n",1);
        if (iVar3 == iVar9) {
          return 1;
        }
      }
      (*(code *)PTR_BIO_write_006a7f14)(iVar6,"\n",1);
    } while (iVar3 != iVar9);
  }
  return 1;
}

