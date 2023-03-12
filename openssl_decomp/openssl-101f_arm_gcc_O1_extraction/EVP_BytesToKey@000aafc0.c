
int EVP_BytesToKey(EVP_CIPHER *type,EVP_MD *md,uchar *salt,uchar *data,int datal,int count,
                  uchar *key,uchar *iv)

{
  int iVar1;
  int iVar2;
  uchar *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int local_90;
  uint local_88;
  EVP_MD_CTX EStack_84;
  uchar local_6c [64];
  int local_2c;
  
  uVar4 = type->key_len;
  local_2c = __TMC_END__;
  local_88 = 0;
  uVar6 = type->iv_len;
  if (0x40 < (int)uVar4) {
    OpenSSLDie("evp_key.c",0x7e,"nkey <= EVP_MAX_KEY_LENGTH");
  }
  if (0x10 < (int)uVar6) {
    OpenSSLDie("evp_key.c",0x7f,"niv <= EVP_MAX_IV_LENGTH");
  }
  if (data != (uchar *)0x0) {
    local_90 = 0;
    EVP_MD_CTX_init(&EStack_84);
    uVar5 = uVar4;
    do {
      uVar4 = EVP_DigestInit_ex(&EStack_84,md,(ENGINE *)0x0);
      if (uVar4 == 0) goto LAB_000ab0ae;
      if (((((local_90 != 0) && (iVar1 = EVP_DigestUpdate(&EStack_84,local_6c,local_88), iVar1 == 0)
            ) || (iVar1 = EVP_DigestUpdate(&EStack_84,data,datal), iVar1 == 0)) ||
          ((salt != (uchar *)0x0 && (iVar1 = EVP_DigestUpdate(&EStack_84,salt,8), iVar1 == 0)))) ||
         (iVar1 = EVP_DigestFinal_ex(&EStack_84,local_6c,&local_88), iVar1 == 0)) {
LAB_000ab098:
        uVar4 = 0;
        goto LAB_000ab09e;
      }
      if (1 < (uint)count) {
        iVar1 = 1;
        do {
          iVar2 = EVP_DigestInit_ex(&EStack_84,md,(ENGINE *)0x0);
          if (((iVar2 == 0) || (iVar2 = EVP_DigestUpdate(&EStack_84,local_6c,local_88), iVar2 == 0))
             || (iVar2 = EVP_DigestFinal_ex(&EStack_84,local_6c,&local_88), iVar2 == 0))
          goto LAB_000ab098;
          iVar1 = iVar1 + 1;
        } while (count != iVar1);
      }
      uVar4 = uVar5;
      if (uVar5 != 0) {
        uVar4 = 0;
        puVar3 = key;
        do {
          key = puVar3;
          if (uVar4 == local_88) break;
          if (puVar3 != (uchar *)0x0) {
            key = puVar3 + 1;
            *puVar3 = local_6c[uVar4];
          }
          uVar5 = uVar5 - 1;
          uVar4 = uVar4 + 1;
          puVar3 = key;
        } while (uVar5 != 0);
      }
      for (; (uVar6 != 0 && (uVar4 != local_88)); uVar4 = uVar4 + 1) {
        puVar3 = iv;
        if (iv != (uchar *)0x0) {
          puVar3 = iv + 1;
          *iv = local_6c[uVar4];
        }
        uVar6 = uVar6 - 1;
        iv = puVar3;
      }
      local_90 = local_90 + 1;
    } while ((uVar6 | uVar5) != 0);
    uVar4 = type->key_len;
LAB_000ab09e:
    EVP_MD_CTX_cleanup(&EStack_84);
    OPENSSL_cleanse(local_6c,0x40);
  }
LAB_000ab0ae:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}

