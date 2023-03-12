
bool TS_ASN1_INTEGER_print_bio(undefined4 param_1,undefined *param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  bool bVar11;
  undefined auStack_dc [128];
  int iStack_5c;
  undefined *puStack_58;
  undefined *puStack_54;
  undefined *puStack_50;
  code *pcStack_4c;
  undefined *local_38;
  undefined auStack_30 [20];
  int local_1c;
  
  puStack_50 = PTR___stack_chk_guard_006aabf0;
  puStack_58 = auStack_30;
  local_38 = &_gp;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_BN_init_006a96a0)(puStack_58);
  puVar7 = puStack_58;
  (**(code **)(local_38 + -0x7dcc))(param_2,puStack_58);
  puVar1 = (undefined *)(**(code **)(local_38 + -0x7dc8))(puStack_58);
  if (puVar1 == (undefined *)0x0) {
    bVar11 = false;
  }
  else {
    puVar7 = &DAT_00667f10;
    iVar2 = (**(code **)(local_38 + -0x7fcc))(param_1,&DAT_00667f10,2);
    if (iVar2 < 1) {
      bVar11 = false;
    }
    else {
      uVar3 = (**(code **)(local_38 + -0x53b0))(puVar1);
      puVar7 = puVar1;
      iVar2 = (**(code **)(local_38 + -0x7fcc))(param_1,puVar1,uVar3);
      bVar11 = 0 < iVar2;
    }
    (**(code **)(local_38 + -0x7f58))(puVar1);
    param_2 = puVar1;
  }
  (**(code **)(local_38 + -0x7dc4))(puStack_58);
  if (local_1c != *(int *)puStack_50) {
    pcStack_4c = TS_OBJ_print_bio;
    iVar2 = local_1c;
    (**(code **)(local_38 + -0x5328))();
    puVar1 = PTR___stack_chk_guard_006aabf0;
    iStack_5c = *(int *)PTR___stack_chk_guard_006aabf0;
    puStack_54 = param_2;
    uVar3 = (*(code *)PTR_OBJ_obj2txt_006a9dbc)(auStack_dc,0x80,puVar7,0);
    (*(code *)PTR_BIO_write_006a7f14)(iVar2,auStack_dc,uVar3);
    pcVar8 = "\n";
    (*(code *)PTR_BIO_write_006a7f14)(iVar2,"\n",1);
    if (iStack_5c == *(int *)puVar1) {
      return true;
    }
    iVar2 = iStack_5c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    (*(code *)PTR_BIO_printf_006a7f38)();
    iVar4 = (*(code *)PTR_X509v3_get_ext_count_006aa060)(pcVar8);
    if (0 < iVar4) {
      iVar10 = 0;
      do {
        while( true ) {
          iVar5 = (*(code *)PTR_X509v3_get_ext_006aa070)(pcVar8,iVar10);
          uVar3 = (*(code *)PTR_X509_EXTENSION_get_object_006a8ca0)(iVar5);
          (*(code *)PTR_i2a_ASN1_OBJECT_006a812c)(iVar2,uVar3);
          iVar6 = (*(code *)PTR_X509_EXTENSION_get_critical_006a9e6c)(iVar5);
          pcVar9 = "critical";
          if (iVar6 == 0) {
            pcVar9 = "";
          }
          iVar10 = iVar10 + 1;
          (*(code *)PTR_BIO_printf_006a7f38)(iVar2,": %s\n",pcVar9);
          iVar6 = (*(code *)PTR_X509V3_EXT_print_006a9e70)(iVar2,iVar5,0,4);
          if (iVar6 != 0) break;
          (*(code *)PTR_BIO_printf_006a7f38)(iVar2,&DAT_00673840,"");
          (*(code *)PTR_ASN1_STRING_print_006a9e74)(iVar2,*(undefined4 *)(iVar5 + 8));
          (*(code *)PTR_BIO_write_006a7f14)(iVar2,"\n",1);
          if (iVar4 == iVar10) {
            return true;
          }
        }
        (*(code *)PTR_BIO_write_006a7f14)(iVar2,"\n",1);
      } while (iVar4 != iVar10);
    }
    return true;
  }
  return bVar11;
}

