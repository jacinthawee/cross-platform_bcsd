
int EVP_BytesToKey(EVP_CIPHER *type,EVP_MD *md,uchar *salt,uchar *data,int datal,int count,
                  uchar *key,uchar *iv)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  uchar *puVar5;
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
  uVar1 = type->key_len;
  local_90 = type->iv_len;
  local_88 = key;
  if (0x40 < (int)uVar1) {
    OpenSSLDie("evp_key.c",0x7e,"nkey <= EVP_MAX_KEY_LENGTH");
  }
  if (0x10 < (int)local_90) {
    OpenSSLDie("evp_key.c",0x7f,"niv <= EVP_MAX_IV_LENGTH");
  }
  if (data != (uchar *)0x0) {
    EVP_MD_CTX_init(&local_78);
    local_8c = 0;
    local_94 = uVar1;
LAB_0812bca9:
    do {
      uVar1 = EVP_DigestInit_ex(&local_78,md,(ENGINE *)0x0);
      if (uVar1 == 0) break;
      if (((((local_8c != 0) && (iVar2 = EVP_DigestUpdate(&local_78,local_60,local_7c), iVar2 == 0))
           || (iVar2 = EVP_DigestUpdate(&local_78,data,datal), iVar2 == 0)) ||
          ((salt != (uchar *)0x0 && (iVar2 = EVP_DigestUpdate(&local_78,salt,8), iVar2 == 0)))) ||
         (iVar2 = EVP_DigestFinal_ex(&local_78,local_60,&local_7c), iVar2 == 0)) {
LAB_0812bd9e:
        uVar1 = 0;
        goto LAB_0812bda0;
      }
      iVar2 = 1;
      if (1 < (uint)count) {
        do {
          iVar3 = EVP_DigestInit_ex(&local_78,md,(ENGINE *)0x0);
          if (((iVar3 == 0) || (iVar3 = EVP_DigestUpdate(&local_78,local_60,local_7c), iVar3 == 0))
             || (iVar3 = EVP_DigestFinal_ex(&local_78,local_60,&local_7c), iVar3 == 0))
          goto LAB_0812bd9e;
          iVar2 = iVar2 + 1;
        } while (iVar2 != count);
      }
      sVar4 = 0;
      if (local_94 != 0) {
        sVar4 = 0;
        puVar5 = local_88;
        do {
          local_88 = puVar5;
          if (local_7c == sVar4) goto LAB_0812bec9;
          if (puVar5 != (uchar *)0x0) {
            local_88 = puVar5 + 1;
            *puVar5 = local_60[sVar4];
          }
          sVar4 = sVar4 + 1;
          local_94 = local_94 - 1;
          puVar5 = local_88;
        } while (local_94 != 0);
      }
      if (local_90 == 0) goto LAB_0812be70;
      if (local_7c == sVar4) {
        local_8c = local_8c + 1;
        local_94 = 0;
        goto LAB_0812bca9;
      }
      do {
        puVar5 = local_84;
        if (local_84 != (uchar *)0x0) {
          puVar5 = local_84 + 1;
          *local_84 = local_60[sVar4];
        }
        sVar4 = sVar4 + 1;
        local_90 = local_90 - 1;
        if (local_90 == 0) goto LAB_0812be70;
        local_84 = puVar5;
      } while (local_7c != sVar4);
      local_94 = 0;
LAB_0812bec9:
      local_8c = local_8c + 1;
      if ((local_90 | local_94) == 0) goto LAB_0812be70;
    } while( true );
  }
LAB_0812bdb8:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_0812be70:
  uVar1 = type->key_len;
LAB_0812bda0:
  EVP_MD_CTX_cleanup(&local_78);
  OPENSSL_cleanse(local_60,0x40);
  goto LAB_0812bdb8;
}

