
undefined4 dh_priv_encode(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int reason;
  int local_20;
  int local_1c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_20 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  piVar3 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
  if (piVar3 == (int *)0x0) {
    ERR_put_error(5,0x6f,0x41,"dh_ameth.c",0xf2);
    if (local_20 != 0) goto LAB_00516bc8;
    uVar5 = 0;
    goto LAB_00516b10;
  }
  iVar4 = i2d_DHparams(*(DH **)(param_2 + 0x14),(uchar **)(piVar3 + 2));
  *piVar3 = iVar4;
  puVar1 = PTR_BN_to_ASN1_INTEGER_006a70f4;
  if (iVar4 < 1) {
    reason = 0x41;
    iVar4 = 0xf8;
LAB_00516b54:
    ERR_put_error(5,0x6f,reason,"dh_ameth.c",iVar4);
  }
  else {
    piVar3[1] = 0x10;
    iVar4 = (*(code *)puVar1)(*(undefined4 *)(*(int *)(param_2 + 0x14) + 0x18),0);
    if (iVar4 == 0) {
      reason = 0x6a;
      iVar4 = 0x101;
      goto LAB_00516b54;
    }
    uVar5 = (*(code *)PTR_i2d_ASN1_INTEGER_006a83dc)(iVar4,&local_20);
    (*(code *)PTR_ASN1_STRING_clear_free_006a8794)(iVar4);
    uVar6 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x1c);
    iVar4 = (*(code *)PTR_PKCS8_pkey_set0_006a8798)(param_1,uVar6,0,0x10,piVar3,local_20,uVar5);
    if (iVar4 != 0) {
      uVar5 = 1;
      goto LAB_00516b10;
    }
  }
  if (local_20 != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  (*(code *)PTR_ASN1_STRING_free_006a879c)(piVar3);
  uVar5 = 0;
LAB_00516b10:
  while (local_1c != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00516bc8:
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    uVar5 = 0;
  }
  return uVar5;
}

