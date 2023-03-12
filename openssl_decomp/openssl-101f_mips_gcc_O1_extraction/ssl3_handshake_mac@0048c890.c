
undefined4
ssl3_handshake_mac(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_84;
  uint local_80;
  undefined auStack_7c [24];
  undefined auStack_64 [64];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar3 = *(int *)(param_1 + 0x58);
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (*(int *)(iVar3 + 0x178) != 0) {
    iVar3 = ssl3_digest_cached_records();
    if (iVar3 == 0) goto LAB_0048c988;
    iVar3 = *(int *)(param_1 + 0x58);
  }
  local_80 = 0;
LAB_0048c914:
  if (*(int *)(*(int *)(iVar3 + 0x17c) + local_80 * 4) != 0) {
    uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)();
    iVar3 = (*(code *)PTR_EVP_MD_type_006a84cc)(uVar2);
    if (iVar3 == param_2) {
      iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + local_80 * 4);
      if (iVar3 != 0) {
        (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_7c);
        (*(code *)PTR_EVP_MD_CTX_set_flags_006a8600)(auStack_7c,8);
        (*(code *)PTR_EVP_MD_CTX_copy_ex_006a922c)(auStack_7c,iVar3);
        uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(auStack_7c);
        iVar3 = (*(code *)PTR_EVP_MD_size_006a8f2c)(uVar2);
        if (iVar3 < 0) goto LAB_0048c988;
        if (iVar3 == 0) {
          trap(7);
        }
        iVar3 = (0x30 / iVar3) * iVar3;
        if (param_3 != 0) {
          (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_7c,param_3,param_4);
        }
        (*(code *)PTR_EVP_DigestUpdate_006a8674)
                  (auStack_7c,*(int *)(param_1 + 0xc0) + 0x14,
                   *(undefined4 *)(*(int *)(param_1 + 0xc0) + 0x10));
        (*(code *)PTR_EVP_DigestUpdate_006a8674)
                  (auStack_7c,"666666666666666666666666666666666666666666666666",iVar3);
        (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_7c,auStack_64,&local_80);
        uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(auStack_7c);
        (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_7c,uVar2,0);
        (*(code *)PTR_EVP_DigestUpdate_006a8674)
                  (auStack_7c,*(int *)(param_1 + 0xc0) + 0x14,
                   *(undefined4 *)(*(int *)(param_1 + 0xc0) + 0x10));
        (*(code *)PTR_EVP_DigestUpdate_006a8674)
                  (auStack_7c,
                   "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\666666666666666666666666666666666666666666666666"
                   ,iVar3);
        (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_7c,auStack_64,local_80);
        (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_7c,param_5);
        (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_7c);
        goto LAB_0048c98c;
      }
LAB_0048c960:
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x11d,0x144,"s3_enc.c",0x2a3);
LAB_0048c988:
      local_84 = 0;
LAB_0048c98c:
      if (local_24 == *(int *)puVar1) {
        return local_84;
      }
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      uVar2 = ssl3_handshake_mac();
      return uVar2;
    }
  }
  local_80 = local_80 + 1;
  if (5 < local_80) goto LAB_0048c960;
  iVar3 = *(int *)(param_1 + 0x58);
  goto LAB_0048c914;
}

