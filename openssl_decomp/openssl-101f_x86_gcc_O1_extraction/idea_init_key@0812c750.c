
undefined4 idea_init_key(EVP_CIPHER_CTX *param_1,uchar *param_2,undefined4 param_3,int param_4)

{
  ulong uVar1;
  int in_GS_OFFSET;
  IDEA_KEY_SCHEDULE local_e8;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_4 == 0) {
    uVar1 = EVP_CIPHER_CTX_flags(param_1);
    if ((uVar1 & 0xf0007) != 4) {
      uVar1 = EVP_CIPHER_CTX_flags(param_1);
      if ((uVar1 & 0xf0007) != 3) {
        idea_set_encrypt_key(param_2,&local_e8);
        idea_set_decrypt_key(&local_e8,(IDEA_KEY_SCHEDULE *)param_1->cipher_data);
        OPENSSL_cleanse(&local_e8,0xd8);
        goto LAB_0812c790;
      }
    }
  }
  idea_set_encrypt_key(param_2,(IDEA_KEY_SCHEDULE *)param_1->cipher_data);
LAB_0812c790:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

