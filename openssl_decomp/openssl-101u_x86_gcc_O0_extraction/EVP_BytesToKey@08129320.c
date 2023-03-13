
int EVP_BytesToKey(EVP_CIPHER *type,EVP_MD *md,uchar *salt,uchar *data,int datal,int count,
                  uchar *key,uchar *iv)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  uchar *puVar4;
  int in_GS_OFFSET;
  uint local_94;
  uint local_90;
  int local_8c;
  uchar *local_88;
  uchar *local_84;
  size_t local_7c;
  EVP_MD_CTX local_78;
  uchar local_60 [64];
  int local_20;
  
  local_7c = 0;
  local_84 = iv;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_94 = type->key_len;
  local_90 = type->iv_len;
  local_88 = key;
  if (0x40 < (int)local_94) {
    OpenSSLDie("evp_key.c",0x85,"nkey <= EVP_MAX_KEY_LENGTH");
  }
  if (0x10 < (int)local_90) {
    OpenSSLDie("evp_key.c",0x86,"niv <= EVP_MAX_IV_LENGTH");
  }
  if (data != (uchar *)0x0) {
    EVP_MD_CTX_init(&local_78);
    local_8c = 0;
LAB_081293c9:
    do {
      iVar1 = EVP_DigestInit_ex(&local_78,md,(ENGINE *)0x0);
      if (((iVar1 == 0) ||
          ((((local_8c != 0 && (iVar1 = EVP_DigestUpdate(&local_78,local_60,local_7c), iVar1 == 0))
            || (iVar1 = EVP_DigestUpdate(&local_78,data,datal), iVar1 == 0)) ||
           ((salt != (uchar *)0x0 && (iVar1 = EVP_DigestUpdate(&local_78,salt,8), iVar1 == 0))))))
         || (iVar1 = EVP_DigestFinal_ex(&local_78,local_60,&local_7c), iVar1 == 0)) {
LAB_081294be:
        local_94 = 0;
        goto LAB_081294c0;
      }
      iVar1 = 1;
      if (1 < (uint)count) {
        do {
          iVar2 = EVP_DigestInit_ex(&local_78,md,(ENGINE *)0x0);
          if (((iVar2 == 0) || (iVar2 = EVP_DigestUpdate(&local_78,local_60,local_7c), iVar2 == 0))
             || (iVar2 = EVP_DigestFinal_ex(&local_78,local_60,&local_7c), iVar2 == 0))
          goto LAB_081294be;
          iVar1 = iVar1 + 1;
        } while (iVar1 != count);
      }
      sVar3 = 0;
      if (local_94 != 0) {
        sVar3 = 0;
        puVar4 = local_88;
        do {
          local_88 = puVar4;
          if (local_7c == sVar3) goto LAB_081295e9;
          if (puVar4 != (uchar *)0x0) {
            local_88 = puVar4 + 1;
            *puVar4 = local_60[sVar3];
          }
          sVar3 = sVar3 + 1;
          local_94 = local_94 - 1;
          puVar4 = local_88;
        } while (local_94 != 0);
      }
      if (local_90 == 0) goto LAB_08129590;
      if (local_7c == sVar3) {
        local_8c = local_8c + 1;
        local_94 = 0;
        goto LAB_081293c9;
      }
      do {
        puVar4 = local_84;
        if (local_84 != (uchar *)0x0) {
          puVar4 = local_84 + 1;
          *local_84 = local_60[sVar3];
        }
        sVar3 = sVar3 + 1;
        local_90 = local_90 - 1;
        if (local_90 == 0) goto LAB_08129590;
        local_84 = puVar4;
      } while (local_7c != sVar3);
      local_94 = 0;
LAB_081295e9:
      local_8c = local_8c + 1;
      if ((local_90 | local_94) == 0) goto LAB_08129590;
    } while( true );
  }
LAB_081294d8:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_94;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_08129590:
  local_94 = type->key_len;
LAB_081294c0:
  EVP_MD_CTX_cleanup(&local_78);
  OPENSSL_cleanse(local_60,0x40);
  goto LAB_081294d8;
}

