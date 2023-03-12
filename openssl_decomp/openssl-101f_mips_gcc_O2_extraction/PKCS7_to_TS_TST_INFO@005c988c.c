
undefined4 PKCS7_to_TS_TST_INFO(int param_1)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 local_18;
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)(param_1 + 0x10));
  if (iVar2 == 0x16) {
    iVar2 = (*(code *)PTR_PKCS7_ctrl_006aa268)(param_1,2,0,0);
    if (iVar2 == 0) {
      iVar8 = *(int *)(*(int *)(param_1 + 0x14) + 0x14);
      iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)(iVar8 + 0x10));
      if (iVar2 == 0xcf) {
        piVar3 = *(int **)(iVar8 + 0x14);
        puVar9 = &local_18;
        if (*piVar3 == 4) {
          puVar4 = (undefined4 *)piVar3[1];
          local_18 = puVar4[2];
          uVar5 = (*(code *)PTR_ASN1_item_d2i_006a9798)(0,puVar9,*puVar4,TS_TST_INFO_it);
          goto LAB_005c9950;
        }
        uVar7 = 0x85;
        uVar5 = 0x139;
      }
      else {
        uVar7 = 0x84;
        uVar5 = 0x131;
      }
    }
    else {
      uVar7 = 0x86;
      uVar5 = 0x128;
    }
  }
  else {
    uVar7 = 0x84;
    uVar5 = 0x121;
  }
  puVar9 = (undefined4 *)&DAT_00000094;
  (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x94,uVar7,"ts_asn1.c",uVar5);
  uVar5 = 0;
LAB_005c9950:
  if (local_14 == *(int *)puVar1) {
    return uVar5;
  }
  iVar2 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar9 = (undefined4 *)*puVar9;
  if (iVar2 != 1) {
    if (iVar2 == 3) {
      if (puVar9[2] != 0) {
        (*(code *)PTR_ASN1_item_free_006a977c)(puVar9[2],TS_TST_INFO_it);
        return 1;
      }
    }
    else if (iVar2 == 5) {
      uVar6 = (*(code *)PTR_ASN1_INTEGER_get_006a831c)(*(undefined4 *)*puVar9);
      iVar2 = puVar9[1];
      if (iVar2 == 0) {
        if (1 < uVar6) {
          return 1;
        }
        uVar7 = 0x82;
        uVar5 = 0xc9;
      }
      else if (1 < uVar6) {
        uVar7 = 0x83;
        uVar5 = 0xbe;
      }
      else {
        if (puVar9[2] != 0) {
          (*(code *)PTR_ASN1_item_free_006a977c)(puVar9[2],TS_TST_INFO_it);
          iVar2 = puVar9[1];
        }
        iVar2 = PKCS7_to_TS_TST_INFO(iVar2);
        puVar9[2] = iVar2;
        if (iVar2 != 0) {
          return 1;
        }
        uVar7 = 0x81;
        uVar5 = 0xc5;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x96,uVar7,"ts_asn1.c",uVar5);
      return 0;
    }
    return 1;
  }
  puVar9[2] = 0;
  return 1;
}

