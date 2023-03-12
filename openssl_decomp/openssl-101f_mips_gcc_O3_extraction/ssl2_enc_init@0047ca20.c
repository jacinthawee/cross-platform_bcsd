
int ssl2_enc_init(int param_1,int param_2)

{
  char *pcVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  char *local_2c;
  char *local_28;
  int local_24;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar3 = (*(code *)PTR_ssl_cipher_get_evp_006a9038)
                    (*(undefined4 *)(param_1 + 0xc0),&local_2c,&local_28,0,0,0);
  if (iVar3 == 0) {
    ssl2_return_error(param_1,1);
    local_2c = (char *)0x7c;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x7c,0xce,"s2_enc.c",0x4a);
    goto LAB_0047cba0;
  }
  (*(code *)PTR_ssl_replace_hash_006a90a8)(param_1 + 0x84,local_28);
  (*(code *)PTR_ssl_replace_hash_006a90a8)(param_1 + 0x90);
  iVar3 = *(int *)(param_1 + 0x80);
  if (iVar3 == 0) {
    local_28 = "s2_enc.c";
    iVar3 = (*(code *)PTR_CRYPTO_malloc_006a8108)(0x8c,"s2_enc.c",0x52);
    *(int *)(param_1 + 0x80) = iVar3;
    if (iVar3 != 0) goto LAB_0047cabc;
LAB_0047cd38:
    local_2c = (char *)0x7c;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x7c,0x41,"s2_enc.c",0x72);
    iVar3 = 0;
  }
  else {
LAB_0047cabc:
    (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(iVar3);
    iVar8 = *(int *)(param_1 + 0x8c);
    if (iVar8 == 0) {
      local_28 = "s2_enc.c";
      iVar8 = (*(code *)PTR_CRYPTO_malloc_006a8108)(0x8c,"s2_enc.c",0x5c);
      *(int *)(param_1 + 0x8c) = iVar8;
      if (iVar8 == 0) goto LAB_0047cd38;
    }
    (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(iVar8);
    iVar7 = *(int *)(local_2c + 8);
    *(int *)(*(int *)(param_1 + 0x54) + 0x9c) = iVar7 << 1;
    if ((uint)(iVar7 << 1) < 0x31) {
      iVar4 = ssl2_generate_key_material(param_1);
      pcVar6 = local_28;
      pcVar1 = local_2c;
    }
    else {
      pcVar6 = (char *)0x64;
      (*(code *)PTR_OpenSSLDie_006a8d4c)
                ("s2_enc.c",100,"s->s2->key_material_length <= sizeof s->s2->key_material");
      iVar4 = ssl2_generate_key_material(param_1);
      pcVar1 = local_2c;
    }
    local_2c = pcVar6;
    if (iVar4 < 1) {
      iVar3 = 0;
    }
    else {
      local_2c = pcVar1;
      if (8 < *(int *)(pcVar1 + 0xc)) {
        (*(code *)PTR_OpenSSLDie_006a8d4c)
                  ("s2_enc.c",0x69,"c->iv_len <= (int)sizeof(s->session->key_arg)");
      }
      if (param_2 == 0) {
        iVar4 = iVar7 + 0xa0;
        iVar7 = 0;
        (*(code *)PTR_EVP_EncryptInit_ex_006a8b84)
                  (iVar8,local_2c,0,*(int *)(param_1 + 0x54) + 0xa0,*(int *)(param_1 + 0xc0) + 8);
        (*(code *)PTR_EVP_DecryptInit_ex_006a8b54)
                  (iVar3,local_2c,0,*(int *)(param_1 + 0x54) + iVar4,*(int *)(param_1 + 0xc0) + 8);
        iVar8 = *(int *)(param_1 + 0x54);
        *(int *)(iVar8 + 0x5c) = iVar8 + iVar4;
      }
      else {
        (*(code *)PTR_EVP_EncryptInit_ex_006a8b84)
                  (iVar8,local_2c,0,*(int *)(param_1 + 0x54) + iVar7 + 0xa0,
                   *(int *)(param_1 + 0xc0) + 8);
        (*(code *)PTR_EVP_DecryptInit_ex_006a8b54)
                  (iVar3,local_2c,0,*(int *)(param_1 + 0x54) + 0xa0,*(int *)(param_1 + 0xc0) + 8);
        iVar8 = *(int *)(param_1 + 0x54);
        *(int *)(iVar8 + 0x5c) = iVar8 + 0xa0;
      }
      iVar3 = 1;
      *(int *)(iVar8 + 0x60) = iVar8 + iVar7 + 0xa0;
    }
  }
LAB_0047cba0:
  if (local_24 == *(int *)puVar2) {
    return iVar3;
  }
  iVar3 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar8 = *(int *)(iVar3 + 0x54);
  if (local_2c == (char *)0x0) {
    piVar5 = *(int **)(iVar3 + 0x80);
    iVar3 = *(int *)(iVar8 + 0x40);
  }
  else {
    piVar5 = *(int **)(iVar3 + 0x8c);
    iVar3 = *(int *)(iVar8 + 0x48);
  }
  if (piVar5 == (int *)0x0) {
    return iVar8;
  }
  if (*(int *)(*piVar5 + 4) != 8) {
                    /* WARNING: Could not recover jumptable at 0x0047cda4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar3 = (*(code *)PTR_EVP_Cipher_006a90b0)(piVar5,*(undefined4 *)(iVar8 + 0x58));
    return iVar3;
  }
                    /* WARNING: Could not recover jumptable at 0x0047cdd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar3 = (*(code *)PTR_EVP_Cipher_006a90b0)
                    (piVar5,*(undefined4 *)(iVar8 + 0x58),*(undefined4 *)(iVar8 + 0x58),
                     iVar3 + 7U & 0xfffffff8);
  return iVar3;
}

