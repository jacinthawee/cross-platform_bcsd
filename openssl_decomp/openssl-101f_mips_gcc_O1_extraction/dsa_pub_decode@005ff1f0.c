
undefined4 dsa_pub_decode(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined auStack_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 *local_24;
  undefined4 local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_X509_PUBKEY_get0_param_006a98cc)(0,auStack_34,&local_2c,&local_20,param_2);
  if (iVar2 != 0) {
    (*(code *)PTR_X509_ALGOR_get0_006a98c4)(0,&local_28,&local_24,local_20);
    if (local_28 == 0x10) {
      local_30 = local_24[2];
      iVar2 = (*(code *)PTR_d2i_DSAparams_006a863c)(0,&local_30,*local_24);
      if (iVar2 != 0) {
LAB_005ff2f8:
        iVar5 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(0,auStack_34,local_2c);
        if (iVar5 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(10,0x75,0x68,"dsa_ameth.c",0x73);
        }
        else {
          iVar4 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a8114)(iVar5,0);
          *(int *)(iVar2 + 0x18) = iVar4;
          if (iVar4 != 0) {
            (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar5);
            (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_1,0x74,iVar2);
            uVar3 = 1;
            goto LAB_005ff254;
          }
          (*(code *)PTR_ERR_put_error_006a9030)(10,0x75,0x6c,"dsa_ameth.c",0x79);
          (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar5);
        }
        (*(code *)PTR_DSA_free_006a862c)(iVar2);
        uVar3 = 0;
        goto LAB_005ff254;
      }
      uVar6 = 0x68;
      uVar3 = 0x5e;
    }
    else if ((local_28 == 5) || (local_28 == -1)) {
      iVar2 = (*(code *)PTR_DSA_new_006a8624)();
      if (iVar2 != 0) goto LAB_005ff2f8;
      uVar6 = 0x41;
      uVar3 = 0x67;
    }
    else {
      uVar6 = 0x69;
      uVar3 = 0x6d;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(10,0x75,uVar6,"dsa_ameth.c",uVar3);
  }
  uVar3 = 0;
LAB_005ff254:
  if (local_1c == *(int *)puVar1) {
    return uVar3;
  }
  iVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar5 = (*(code *)PTR_d2i_DSAPrivateKey_006a9f3c)(0);
  if (iVar5 != 0) {
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(iVar2,0x74,iVar5);
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(10,0x7a,10,"dsa_ameth.c",0x215);
  return 0;
}

