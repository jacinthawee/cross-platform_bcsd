
undefined4
ssl3_handshake_mac(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_84;
  uint local_80;
  undefined auStack_7c [24];
  undefined auStack_64 [64];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar4 = *(int *)(param_1 + 0x58);
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (*(int *)(iVar4 + 0x178) != 0) {
    iVar4 = ssl3_digest_cached_records();
    if (iVar4 == 0) goto LAB_0048888c;
    iVar4 = *(int *)(param_1 + 0x58);
  }
  local_80 = 0;
LAB_00488818:
  if (*(int *)(*(int *)(iVar4 + 0x17c) + local_80 * 4) != 0) {
    uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)();
    iVar4 = (*(code *)PTR_EVP_MD_type_006a73cc)(uVar2);
    if (iVar4 == param_2) {
      iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + local_80 * 4);
      if (iVar4 != 0) {
        (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_7c);
        (*(code *)PTR_EVP_MD_CTX_set_flags_006a7504)(auStack_7c,8);
        (*(code *)PTR_EVP_MD_CTX_copy_ex_006a8104)(auStack_7c,iVar4);
        uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(auStack_7c);
        iVar4 = (*(code *)PTR_EVP_MD_size_006a7e3c)(uVar2);
        if (iVar4 < 0) goto LAB_0048888c;
        if (param_3 == 0) {
LAB_00488964:
          iVar3 = (*(code *)PTR_EVP_DigestUpdate_006a7580)
                            (auStack_7c,*(int *)(param_1 + 0xc0) + 0x14,
                             *(undefined4 *)(*(int *)(param_1 + 0xc0) + 0x10));
          if (iVar3 < 1) goto LAB_00488a7c;
          if (iVar4 == 0) {
            trap(7);
          }
          iVar4 = (0x30 / iVar4) * iVar4;
          iVar3 = (*(code *)PTR_EVP_DigestUpdate_006a7580)
                            (auStack_7c,"666666666666666666666666666666666666666666666666",iVar4);
          if (iVar3 < 1) goto LAB_00488a7c;
          iVar3 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(auStack_7c,auStack_64,&local_80);
          if (iVar3 < 1) goto LAB_00488a7c;
          uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(auStack_7c);
          iVar3 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)(auStack_7c,uVar2,0);
          if (iVar3 < 1) goto LAB_00488a7c;
          iVar3 = (*(code *)PTR_EVP_DigestUpdate_006a7580)
                            (auStack_7c,*(int *)(param_1 + 0xc0) + 0x14,
                             *(undefined4 *)(*(int *)(param_1 + 0xc0) + 0x10));
          if (iVar3 < 1) goto LAB_00488a7c;
          iVar4 = (*(code *)PTR_EVP_DigestUpdate_006a7580)
                            (auStack_7c,
                             "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\666666666666666666666666666666666666666666666666"
                             ,iVar4);
          if (iVar4 < 1) goto LAB_00488a7c;
          iVar4 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_7c,auStack_64,local_80);
          if (iVar4 < 1) goto LAB_00488a7c;
          iVar4 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(auStack_7c,param_5);
          if (iVar4 < 1) goto LAB_00488a7c;
        }
        else {
          iVar3 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_7c,param_3,param_4);
          if (0 < iVar3) goto LAB_00488964;
LAB_00488a7c:
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x11d,0x44,"s3_enc.c",0x2b7);
          local_84 = 0;
        }
        (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_7c);
        goto LAB_00488890;
      }
LAB_00488864:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x11d,0x144,"s3_enc.c",0x2a0);
LAB_0048888c:
      local_84 = 0;
LAB_00488890:
      if (local_24 == *(int *)puVar1) {
        return local_84;
      }
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
      uVar2 = ssl3_handshake_mac();
      return uVar2;
    }
  }
  local_80 = local_80 + 1;
  if (5 < local_80) goto LAB_00488864;
  iVar4 = *(int *)(param_1 + 0x58);
  goto LAB_00488818;
}

