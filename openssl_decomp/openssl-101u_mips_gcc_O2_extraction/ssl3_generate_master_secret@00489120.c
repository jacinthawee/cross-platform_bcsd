
int ssl3_generate_master_secret(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  int iVar6;
  int local_88;
  undefined auStack_84 [24];
  undefined auStack_6c [64];
  uint local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar6 = 0;
  local_2c = *(uint *)PTR___stack_chk_guard_006a9ae8;
  puVar5 = salt_15972;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_84);
  do {
    iVar2 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)
                      (auStack_84,*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x90),0);
    if (iVar2 < 1) {
LAB_00489374:
      iVar6 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x184,0x44,"s3_enc.c",0x356);
      break;
    }
    uVar4 = *(undefined4 *)puVar5;
    uVar3 = (*(code *)PTR_strlen_006a9a24)(uVar4);
    iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_84,uVar4,uVar3);
    if (iVar2 < 1) goto LAB_00489374;
    iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_84,param_3,param_4);
    if (iVar2 < 1) goto LAB_00489374;
    iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a7580)
                      (auStack_84,*(int *)(param_1 + 0x58) + 0xc0,0x20);
    if (iVar2 < 1) goto LAB_00489374;
    iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a7580)
                      (auStack_84,*(int *)(param_1 + 0x58) + 0xa0,0x20);
    if (iVar2 < 1) goto LAB_00489374;
    iVar2 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(auStack_84,auStack_6c,&local_88);
    if (iVar2 < 1) goto LAB_00489374;
    iVar2 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)
                      (auStack_84,*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x8c),0);
    if (iVar2 < 1) goto LAB_00489374;
    iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_84,param_3,param_4);
    if (iVar2 < 1) goto LAB_00489374;
    iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_84,auStack_6c,local_88);
    if (iVar2 < 1) goto LAB_00489374;
    iVar2 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(auStack_84,param_2,&local_88);
    if (iVar2 < 1) goto LAB_00489374;
    puVar5 = (undefined1 *)((int)puVar5 + 4);
    param_2 = param_2 + local_88;
    iVar6 = iVar6 + local_88;
  } while (puVar5 != cipher_aliases);
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_84);
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_6c,0x40);
  if (local_2c == *(uint *)puVar1) {
    return iVar6;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (local_2c < 0x74) {
    return (int)(char)CSWTCH_67[local_2c];
  }
  return -1;
}

