
uint rsa_pub_decode(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined *puVar8;
  int iVar9;
  undefined auStack_1c [4];
  undefined4 local_18;
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  puVar3 = &local_18;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar8 = auStack_1c;
  uVar2 = (*(code *)PTR_X509_PUBKEY_get0_param_006a98cc)(0,auStack_1c,puVar3,0,param_2);
  if (uVar2 != 0) {
    puVar3 = (undefined4 *)(*(code *)PTR_d2i_RSAPublicKey_006a9f78)(0,auStack_1c,local_18);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)&SUB_00000004;
      puVar8 = &DAT_0000008b;
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x8b,4,"rsa_ameth.c",0x5e);
      uVar2 = 0;
    }
    else {
      puVar8 = &DAT_00000006;
      (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_1);
      uVar2 = 1;
    }
  }
  if (local_14 == *(int *)puVar1) {
    return uVar2;
  }
  iVar7 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar9 = *(int *)(puVar8 + 0x14);
  if (*(int *)(iVar9 + 0x10) == 0) {
    uVar2 = 0;
  }
  else {
    iVar4 = (*(code *)PTR_BN_num_bits_006a82f4)();
    iVar5 = iVar4 + 7;
    if (iVar4 + 7 < 0) {
      iVar5 = iVar4 + 0xe;
    }
    uVar2 = iVar5 >> 3;
  }
  if (*(int *)(iVar9 + 0x14) != 0) {
    iVar4 = (*(code *)PTR_BN_num_bits_006a82f4)();
    iVar5 = iVar4 + 7;
    if (iVar4 + 7 < 0) {
      iVar5 = iVar4 + 0xe;
    }
    if (uVar2 < (uint)(iVar5 >> 3)) {
      uVar2 = iVar5 >> 3;
    }
  }
  iVar5 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar2 + 10,"rsa_ameth.c",0xcc);
  if (iVar5 != 0) {
    if (*(int *)(iVar9 + 0x10) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = (*(code *)PTR_BN_num_bits_006a82f4)();
    }
    iVar4 = (*(code *)PTR_BIO_indent_006a97d0)(iVar7,puVar3,0x80);
    if (((iVar4 == 0) ||
        (iVar4 = (*(code *)PTR_BIO_printf_006a7f38)(iVar7,"Public-Key: (%d bit)\n",uVar6), iVar4 < 1
        )) || (iVar4 = (*(code *)PTR_ASN1_bn_print_006a97dc)
                                 (iVar7,"Modulus:",*(undefined4 *)(iVar9 + 0x10),iVar5,puVar3),
              iVar4 == 0)) {
      uVar2 = 0;
    }
    else {
      iVar7 = (*(code *)PTR_ASN1_bn_print_006a97dc)
                        (iVar7,"Exponent:",*(undefined4 *)(iVar9 + 0x14),iVar5,puVar3);
      uVar2 = (uint)(iVar7 != 0);
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar5);
    return uVar2;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(4,0x92,0x41,"rsa_ameth.c",0xcf);
  return 0;
}

