
uint dsa_sig_print(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_28;
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_3 == (undefined4 *)0x0) {
    iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"\n");
    uVar5 = (uint)(0 < iVar4);
    goto LAB_005fe42c;
  }
  local_28 = param_3[2];
  piVar2 = (int *)(*(code *)PTR_d2i_DSA_SIG_006aa854)(0,&local_28,*param_3);
  if (piVar2 == (int *)0x0) {
    uVar5 = (*(code *)PTR_X509_signature_dump_006aa830)(param_1,param_3,param_4);
    goto LAB_005fe42c;
  }
  if (*piVar2 == 0) {
    uVar5 = 0;
  }
  else {
    iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)();
    iVar4 = iVar3 + 7;
    if (iVar3 + 7 < 0) {
      iVar4 = iVar3 + 0xe;
    }
    uVar5 = iVar4 >> 3;
  }
  if (piVar2[1] != 0) {
    iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)();
    iVar4 = iVar3 + 7;
    if (iVar3 + 7 < 0) {
      iVar4 = iVar3 + 0xe;
    }
    if (uVar5 < (uint)(iVar4 >> 3)) {
      uVar5 = iVar4 >> 3;
    }
  }
  iVar4 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar5 + 10,"dsa_ameth.c",0x237);
  if (iVar4 == 0) {
    uVar5 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(10,0x7d,0x41,"dsa_ameth.c",0x23a);
  }
  else {
    iVar3 = (*(code *)PTR_BIO_write_006a7f14)(param_1,"\n",1);
    if (iVar3 == 1) {
      iVar3 = (*(code *)PTR_ASN1_bn_print_006a97dc)(param_1,"r:   ",*piVar2,iVar4,param_4);
      if (iVar3 == 0) goto LAB_005fe404;
      iVar3 = (*(code *)PTR_ASN1_bn_print_006a97dc)(param_1,"s:   ",piVar2[1],iVar4,param_4);
      uVar5 = (uint)(iVar3 != 0);
    }
    else {
LAB_005fe404:
      uVar5 = 0;
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar4);
  }
  (*(code *)PTR_DSA_SIG_free_006a987c)(piVar2);
LAB_005fe42c:
  if (local_24 == *(int *)puVar1) {
    return uVar5;
  }
  iVar4 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x005fe53c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(*(int *)(iVar4 + 0x14) + 0xc));
  return uVar5;
}
