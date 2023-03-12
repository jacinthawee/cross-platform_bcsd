
undefined4 * CMS_add1_ReceiptRequest(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  char *pcVar6;
  undefined4 *puVar7;
  undefined4 *local_28;
  int *local_18;
  undefined4 *local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_18 = (int *)0x0;
  local_14 = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  local_28 = (undefined4 *)
             (*(code *)PTR_ASN1_item_i2d_006a8678)
                       (param_2,&local_18,PTR_CMS_ReceiptRequest_it_006a93ec);
  if (-1 < (int)local_28) {
    piVar5 = (int *)&SUB_00000010;
    puVar4 = (undefined4 *)&DAT_000000d4;
    pcVar6 = (char *)local_18;
    iVar2 = (*(code *)PTR_CMS_signed_add1_attr_by_NID_006a9390)(param_1);
    if (iVar2 != 0) {
      puVar7 = (undefined4 *)0x1;
      goto LAB_005bdb04;
    }
  }
  piVar5 = (int *)&DAT_00000041;
  pcVar6 = s_cms_ess_c_006721bc;
  local_28 = (undefined4 *)&DAT_0000009b;
  puVar4 = (undefined4 *)&DAT_0000009e;
  puVar7 = (undefined4 *)0x0;
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e);
LAB_005bdb04:
  if (local_18 != (int *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  if (local_14 == *(undefined4 **)puVar1) {
    return puVar7;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (puVar4 != (undefined4 *)0x0) {
    *puVar4 = *local_14;
  }
  piVar3 = (int *)local_14[1];
  if (*piVar3 == 0) {
    if (piVar5 != (int *)0x0) {
      *piVar5 = piVar3[1];
    }
    if ((int *)pcVar6 != (int *)0x0) {
      *(int *)pcVar6 = 0;
    }
  }
  else {
    if (piVar5 != (int *)0x0) {
      *piVar5 = -1;
    }
    if ((int *)pcVar6 != (int *)0x0) {
      *(int *)pcVar6 = piVar3[1];
    }
  }
  if (local_28 != (undefined4 *)0x0) {
    *local_28 = local_14[2];
  }
  return local_28;
}

