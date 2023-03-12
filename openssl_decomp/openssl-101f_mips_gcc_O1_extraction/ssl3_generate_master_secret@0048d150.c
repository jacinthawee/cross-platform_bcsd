
int ssl3_generate_master_secret(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int local_88;
  undefined auStack_84 [24];
  undefined auStack_6c [64];
  uint local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar5 = 0;
  local_2c = *(uint *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_84);
  puVar3 = (undefined4 *)salt_15941;
  while( true ) {
    (*(code *)PTR_EVP_DigestInit_ex_006a8670)
              (auStack_84,*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x90),0);
    uVar4 = *puVar3;
    uVar2 = (*(code *)PTR_strlen_006aab30)(uVar4);
    (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_84,uVar4,uVar2);
    (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_84,param_3,param_4);
    (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_84,*(int *)(param_1 + 0x58) + 0xc0,0x20);
    (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_84,*(int *)(param_1 + 0x58) + 0xa0,0x20);
    (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_84,auStack_6c,&local_88);
    (*(code *)PTR_EVP_DigestInit_ex_006a8670)
              (auStack_84,*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x8c),0);
    (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_84,param_3,param_4);
    (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_84,auStack_6c,local_88);
    (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_84,param_2,&local_88);
    iVar5 = iVar5 + local_88;
    if (puVar3 + 1 == (undefined4 *)cipher_aliases) break;
    param_2 = param_2 + local_88;
    puVar3 = puVar3 + 1;
  }
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_84);
  if (local_2c == *(uint *)puVar1) {
    return iVar5;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (local_2c < 0x74) {
    return (int)(char)CSWTCH_67[local_2c];
  }
  return -1;
}

