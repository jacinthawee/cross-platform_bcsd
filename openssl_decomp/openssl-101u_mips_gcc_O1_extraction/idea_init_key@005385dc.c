
undefined1 *
idea_init_key(EVP_CIPHER_CTX *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined *puVar1;
  ulong uVar2;
  undefined auStack_ec [216];
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (param_4 == 0) {
    uVar2 = EVP_CIPHER_CTX_flags(param_1);
    if ((uVar2 & 0xf0007) != 4) {
      uVar2 = EVP_CIPHER_CTX_flags(param_1);
      if ((uVar2 & 0xf0007) != 3) {
        (*(code *)PTR_idea_set_encrypt_key_006a79f4)(param_2,auStack_ec);
        (*(code *)PTR_idea_set_decrypt_key_006a89d8)(auStack_ec,param_1->cipher_data);
        (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_ec,0xd8);
        goto LAB_00538628;
      }
    }
  }
  (*(code *)PTR_idea_set_encrypt_key_006a79f4)(param_2,param_1->cipher_data);
LAB_00538628:
  if (local_14 == *(int *)puVar1) {
    return (undefined1 *)0x1;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return idea_cbc;
}

