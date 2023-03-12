
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
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_X509_PUBKEY_get0_param_006a87ac)(0,auStack_34,&local_2c,&local_20,param_2);
  if (iVar2 != 0) {
    (*(code *)PTR_X509_ALGOR_get0_006a87a4)(0,&local_28,&local_24,local_20);
    if (local_28 == 0x10) {
      local_30 = local_24[2];
      iVar2 = (*(code *)PTR_d2i_DSAparams_006a7540)(0,&local_30,*local_24);
      if (iVar2 != 0) {
LAB_005fd488:
        iVar5 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(0,auStack_34,local_2c);
        if (iVar5 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(10,0x75,0x68,"dsa_ameth.c",0x6b);
        }
        else {
          iVar4 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a7014)(iVar5,0);
          *(int *)(iVar2 + 0x18) = iVar4;
          if (iVar4 != 0) {
            (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar5);
            (*(code *)PTR_EVP_PKEY_assign_006a83cc)(param_1,0x74,iVar2);
            uVar3 = 1;
            goto LAB_005fd3e4;
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(10,0x75,0x6c,"dsa_ameth.c",0x70);
          (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar5);
        }
        (*(code *)PTR_DSA_free_006a7530)(iVar2);
        uVar3 = 0;
        goto LAB_005fd3e4;
      }
      uVar6 = 0x68;
      uVar3 = 0x5c;
    }
    else if ((local_28 == 5) || (local_28 == -1)) {
      iVar2 = (*(code *)PTR_DSA_new_006a7528)();
      if (iVar2 != 0) goto LAB_005fd488;
      uVar6 = 0x41;
      uVar3 = 0x62;
    }
    else {
      uVar6 = 0x69;
      uVar3 = 0x66;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(10,0x75,uVar6,"dsa_ameth.c",uVar3);
  }
  uVar3 = 0;
LAB_005fd3e4:
  if (local_1c == *(int *)puVar1) {
    return uVar3;
  }
  iVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar5 = (*(code *)PTR_d2i_DSAPrivateKey_006a8e20)(0);
  if (iVar5 != 0) {
    (*(code *)PTR_EVP_PKEY_assign_006a83cc)(iVar2,0x74,iVar5);
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(10,0x7a,10,"dsa_ameth.c",0x205);
  return 0;
}

