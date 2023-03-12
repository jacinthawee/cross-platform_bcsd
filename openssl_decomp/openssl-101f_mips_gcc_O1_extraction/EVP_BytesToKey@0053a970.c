
int EVP_BytesToKey(EVP_CIPHER *type,EVP_MD *md,uchar *salt,uchar *data,int datal,int count,
                  uchar *key,uchar *iv)

{
  undefined *puVar1;
  int iVar2;
  size_t sVar3;
  uchar *puVar4;
  uchar *buf;
  int iVar5;
  int iVar6;
  uchar *puVar7;
  int iVar8;
  uchar *local_9c;
  int local_98;
  size_t local_88;
  EVP_MD_CTX EStack_84;
  uchar local_6c [64];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar5 = type->key_len;
  local_9c = iv;
  local_88 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar8 = type->iv_len;
  buf = data;
  if (0x40 < iVar5) {
    iv = (uchar *)0x7e;
    (*(code *)PTR_OpenSSLDie_006a8d4c)("evp_key.c",0x7e,"nkey <= EVP_MAX_KEY_LENGTH");
  }
  if (0x10 < iVar8) {
    iv = (uchar *)0x7f;
    (*(code *)PTR_OpenSSLDie_006a8d4c)("evp_key.c",0x7f,"niv <= EVP_MAX_IV_LENGTH");
  }
  if (data != (uchar *)0x0) {
    EVP_MD_CTX_init(&EStack_84);
    local_98 = 0;
    iVar6 = iVar5;
    while (iv = (uchar *)md, iVar5 = EVP_DigestInit_ex(&EStack_84,md,(ENGINE *)0x0), iVar5 != 0) {
      if (((((local_98 != 0) && (iVar5 = EVP_DigestUpdate(&EStack_84,local_6c,local_88), iVar5 == 0)
            ) || (iVar5 = EVP_DigestUpdate(&EStack_84,data,datal), iVar5 == 0)) ||
          ((salt != (uchar *)0x0 && (iVar5 = EVP_DigestUpdate(&EStack_84,salt,8), iVar5 == 0)))) ||
         (iVar5 = EVP_DigestFinal_ex(&EStack_84,local_6c,&local_88), iVar5 == 0)) {
LAB_0053ab3c:
        iVar5 = 0;
LAB_0053ab40:
        EVP_MD_CTX_cleanup(&EStack_84);
        iv = &DAT_00000040;
        (*(code *)PTR_OPENSSL_cleanse_006a8174)(local_6c);
        break;
      }
      iVar5 = 1;
      if (1 < (uint)count) {
        do {
          iVar2 = EVP_DigestInit_ex(&EStack_84,md,(ENGINE *)0x0);
          if (((iVar2 == 0) || (iVar2 = EVP_DigestUpdate(&EStack_84,local_6c,local_88), iVar2 == 0))
             || (iVar2 = EVP_DigestFinal_ex(&EStack_84,local_6c,&local_88), iVar2 == 0))
          goto LAB_0053ab3c;
          iVar5 = iVar5 + 1;
        } while (count != iVar5);
      }
      sVar3 = 0;
      puVar4 = local_6c;
      for (; iVar6 != 0; iVar6 = iVar6 + -1) {
        if (local_88 == sVar3) {
          if ((iVar8 != 0) || (iVar6 != 0)) goto LAB_0053ac98;
          iVar5 = type->key_len;
          goto LAB_0053ab40;
        }
        puVar7 = key;
        if (key != (uchar *)0x0) {
          puVar7 = key + 1;
          *key = *puVar4;
        }
        sVar3 = sVar3 + 1;
        puVar4 = puVar4 + 1;
        key = puVar7;
      }
      if (iVar8 == 0) {
LAB_0053ac80:
        iVar5 = type->key_len;
        goto LAB_0053ab40;
      }
      puVar4 = local_6c + sVar3;
      while (sVar3 != local_88) {
        if (local_9c != (uchar *)0x0) {
          *local_9c = *puVar4;
          local_9c = local_9c + 1;
        }
        iVar8 = iVar8 + -1;
        sVar3 = sVar3 + 1;
        if (iVar8 == 0) goto LAB_0053ac80;
        puVar4 = puVar4 + 1;
      }
      iVar6 = 0;
LAB_0053ac98:
      local_98 = local_98 + 1;
    }
  }
  if (local_2c == *(int *)puVar1) {
    return iVar5;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if ((EVP_MD *)iv != (EVP_MD *)&DAT_00000006) {
    return -1;
  }
  iVar8 = RAND_bytes(buf,8);
  if (iVar8 < 1) {
    return 0;
  }
  (*(code *)PTR_DES_set_odd_parity_006a9ad8)(buf);
  return 1;
}

