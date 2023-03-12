
bool dsa_priv_print(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  
  iVar5 = *(int *)(param_2 + 0x14);
  iVar7 = *(int *)(iVar5 + 0x1c);
  iVar8 = *(int *)(iVar5 + 0x18);
  if (*(int *)(iVar5 + 0xc) == 0) {
    uVar4 = 0;
  }
  else {
    iVar1 = (*(code *)PTR_BN_num_bits_006a82f4)();
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    uVar4 = iVar2 >> 3;
  }
  if (*(int *)(iVar5 + 0x10) != 0) {
    iVar1 = (*(code *)PTR_BN_num_bits_006a82f4)();
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (uVar4 < (uint)(iVar2 >> 3)) {
      uVar4 = iVar2 >> 3;
    }
  }
  if (*(int *)(iVar5 + 0x14) != 0) {
    iVar1 = (*(code *)PTR_BN_num_bits_006a82f4)();
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (uVar4 < (uint)(iVar2 >> 3)) {
      uVar4 = iVar2 >> 3;
    }
  }
  if (iVar7 != 0) {
    iVar1 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar7);
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (uVar4 < (uint)(iVar2 >> 3)) {
      uVar4 = iVar2 >> 3;
    }
  }
  if (iVar8 != 0) {
    iVar1 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar8);
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (uVar4 < (uint)(iVar2 >> 3)) {
      uVar4 = iVar2 >> 3;
    }
  }
  iVar2 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar4 + 10,"dsa_ameth.c",0x1ce);
  if (iVar2 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(10,0x68,0x41,"dsa_ameth.c",0x1d1);
    return false;
  }
  if (iVar7 == 0) {
LAB_005fe734:
    iVar7 = (*(code *)PTR_ASN1_bn_print_006a97dc)(param_1,"priv:",iVar7,iVar2,param_3);
    if ((((iVar7 != 0) &&
         (iVar7 = (*(code *)PTR_ASN1_bn_print_006a97dc)(param_1,"pub: ",iVar8,iVar2,param_3),
         iVar7 != 0)) &&
        (iVar7 = (*(code *)PTR_ASN1_bn_print_006a97dc)
                           (param_1,"P:   ",*(undefined4 *)(iVar5 + 0xc),iVar2,param_3), iVar7 != 0)
        ) && (iVar7 = (*(code *)PTR_ASN1_bn_print_006a97dc)
                                (param_1,"Q:   ",*(undefined4 *)(iVar5 + 0x10),iVar2,param_3),
             iVar7 != 0)) {
      iVar5 = (*(code *)PTR_ASN1_bn_print_006a97dc)
                        (param_1,"G:   ",*(undefined4 *)(iVar5 + 0x14),iVar2,param_3);
      bVar6 = iVar5 != 0;
      goto LAB_005fe6c4;
    }
  }
  else {
    iVar1 = (*(code *)PTR_BIO_indent_006a97d0)(param_1,param_3,0x80);
    if (iVar1 != 0) {
      uVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(iVar5 + 0xc));
      iVar1 = (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%s: (%d bit)\n","Private-Key",uVar3);
      if (0 < iVar1) goto LAB_005fe734;
    }
  }
  bVar6 = false;
LAB_005fe6c4:
  (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
  return bVar6;
}

