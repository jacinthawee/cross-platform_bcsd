
bool dsa_pub_print(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  int iVar6;
  
  iVar4 = *(int *)(param_2 + 0x14);
  iVar6 = *(int *)(iVar4 + 0x18);
  if (*(int *)(iVar4 + 0xc) == 0) {
    uVar3 = 0;
  }
  else {
    iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)();
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    uVar3 = iVar2 >> 3;
  }
  if (*(int *)(iVar4 + 0x10) != 0) {
    iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)();
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (uVar3 < (uint)(iVar2 >> 3)) {
      uVar3 = iVar2 >> 3;
    }
  }
  if (*(int *)(iVar4 + 0x14) != 0) {
    iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)();
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (uVar3 < (uint)(iVar2 >> 3)) {
      uVar3 = iVar2 >> 3;
    }
  }
  if (iVar6 != 0) {
    iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar6);
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (uVar3 < (uint)(iVar2 >> 3)) {
      uVar3 = iVar2 >> 3;
    }
  }
  iVar2 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar3 + 10,"dsa_ameth.c",0x1be);
  if (iVar2 != 0) {
    iVar1 = (*(code *)PTR_ASN1_bn_print_006a86b8)(param_1,"priv:",0,iVar2,param_3);
    if ((((iVar1 == 0) ||
         (iVar6 = (*(code *)PTR_ASN1_bn_print_006a86b8)(param_1,"pub: ",iVar6,iVar2,param_3),
         iVar6 == 0)) ||
        (iVar6 = (*(code *)PTR_ASN1_bn_print_006a86b8)
                           (param_1,"P:   ",*(undefined4 *)(iVar4 + 0xc),iVar2,param_3), iVar6 == 0)
        ) || (iVar6 = (*(code *)PTR_ASN1_bn_print_006a86b8)
                                (param_1,"Q:   ",*(undefined4 *)(iVar4 + 0x10),iVar2,param_3),
             iVar6 == 0)) {
      bVar5 = false;
    }
    else {
      iVar4 = (*(code *)PTR_ASN1_bn_print_006a86b8)
                        (param_1,"G:   ",*(undefined4 *)(iVar4 + 0x14),iVar2,param_3);
      bVar5 = iVar4 != 0;
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar2);
    return bVar5;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(10,0x68,0x41,"dsa_ameth.c",0x1c0);
  return false;
}

