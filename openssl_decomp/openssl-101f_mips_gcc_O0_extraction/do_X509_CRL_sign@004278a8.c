
uint do_X509_CRL_sign(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 local_40;
  undefined4 auStack_3c [6];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_3c);
  local_40 = 0;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_3c);
  uVar6 = 0;
  puVar5 = &local_40;
  iVar2 = (*(code *)PTR_EVP_DigestSignInit_006a7f20)(auStack_3c,puVar5,param_4,0,param_3);
  if (iVar2 == 0) {
LAB_00427a2c:
    uVar7 = 0;
  }
  else {
    for (iVar2 = 0; iVar3 = (*(code *)PTR_sk_num_006a7f2c)(param_5), iVar2 < iVar3;
        iVar2 = iVar2 + 1) {
      uVar4 = (*(code *)PTR_sk_value_006a7f24)(param_5,iVar2);
      iVar3 = (*(code *)PTR_pkey_ctrl_string_006a7f28)(local_40,uVar4);
      if (iVar3 < 1) {
        puVar5 = (undefined4 *)0x634730;
        (*(code *)PTR_BIO_printf_006a7f38)(param_1,"parameter error \"%s\"\n",uVar4);
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
        goto LAB_00427a2c;
      }
    }
    puVar5 = auStack_3c;
    iVar2 = (*(code *)PTR_X509_CRL_sign_ctx_006a80b8)(param_2,auStack_3c);
    uVar7 = (uint)(0 < iVar2);
  }
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_3c);
  if (local_24 == *(int *)puVar1) {
    return uVar7;
  }
  iVar2 = local_24;
  uVar7 = (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (iVar2 != 0) {
    uVar4 = (*(code *)PTR_EVP_MD_type_006a84cc)();
    uVar4 = (*(code *)PTR_OBJ_nid2ln_006a821c)(uVar4);
    uVar7 = (*(code *)PTR_strcmp_006aac20)(puVar5,uVar4);
    if (uVar7 == 0) {
      uVar7 = (*(code *)PTR_EVP_MD_flags_006a85c4)(iVar2);
      uVar7 = uVar7 & 2;
      if (uVar7 == 0) {
        iVar3 = (*(code *)PTR_strchr_006aab34)(uVar4,0x20);
        if (iVar3 != 0) {
          uVar4 = (*(code *)PTR_EVP_MD_type_006a84cc)(iVar2);
          uVar4 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar4);
        }
                    /* WARNING: Could not recover jumptable at 0x00427b44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar7 = (*(code *)PTR_BIO_printf_006a7f38)
                          (uVar6,"-%-14s to use the %s message digest algorithm\n",uVar4,uVar4);
        return uVar7;
      }
    }
  }
  return uVar7;
}

