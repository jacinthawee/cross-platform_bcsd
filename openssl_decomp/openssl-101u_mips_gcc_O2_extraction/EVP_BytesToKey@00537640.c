
int EVP_BytesToKey(EVP_CIPHER *type,EVP_MD *md,uchar *salt,uchar *data,int datal,int count,
                  uchar *key,uchar *iv)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  uchar *puVar5;
  uchar *buf;
  int iVar6;
  uchar *puVar7;
  int iVar8;
  uchar *local_9c;
  int local_98;
  size_t local_88;
  EVP_MD_CTX EStack_84;
  uchar local_6c [64];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar6 = type->key_len;
  local_9c = iv;
  local_88 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar8 = type->iv_len;
  buf = data;
  if (0x40 < iVar6) {
    iv = (uchar *)0x85;
    (*(code *)PTR_OpenSSLDie_006a7c5c)("evp_key.c",0x85,"nkey <= EVP_MAX_KEY_LENGTH");
  }
  if (0x10 < iVar8) {
    iv = (uchar *)0x86;
    (*(code *)PTR_OpenSSLDie_006a7c5c)("evp_key.c",0x86,"niv <= EVP_MAX_IV_LENGTH");
  }
  if (data != (uchar *)0x0) {
    EVP_MD_CTX_init(&EStack_84);
    local_98 = 0;
    while (((iVar2 = EVP_DigestInit_ex(&EStack_84,md,(ENGINE *)0x0), iVar2 != 0 &&
            ((((local_98 == 0 ||
               (iVar2 = EVP_DigestUpdate(&EStack_84,local_6c,local_88), iVar2 != 0)) &&
              (iVar2 = EVP_DigestUpdate(&EStack_84,data,datal), iVar2 != 0)) &&
             ((salt == (uchar *)0x0 || (iVar2 = EVP_DigestUpdate(&EStack_84,salt,8), iVar2 != 0)))))
            ) && (iVar2 = EVP_DigestFinal_ex(&EStack_84,local_6c,&local_88), iVar2 != 0))) {
      iVar2 = 1;
      if (1 < (uint)count) {
        do {
          iVar3 = EVP_DigestInit_ex(&EStack_84,md,(ENGINE *)0x0);
          if (((iVar3 == 0) || (iVar3 = EVP_DigestUpdate(&EStack_84,local_6c,local_88), iVar3 == 0))
             || (iVar3 = EVP_DigestFinal_ex(&EStack_84,local_6c,&local_88), iVar3 == 0))
          goto LAB_0053780c;
          iVar2 = iVar2 + 1;
        } while (count != iVar2);
      }
      sVar4 = 0;
      puVar5 = local_6c;
      for (; iVar6 != 0; iVar6 = iVar6 + -1) {
        if (local_88 == sVar4) {
          if ((iVar8 != 0) || (iVar6 != 0)) goto LAB_00537968;
          iVar6 = type->key_len;
          goto LAB_00537810;
        }
        puVar7 = key;
        if (key != (uchar *)0x0) {
          puVar7 = key + 1;
          *key = *puVar5;
        }
        sVar4 = sVar4 + 1;
        puVar5 = puVar5 + 1;
        key = puVar7;
      }
      if (iVar8 == 0) {
LAB_00537950:
        iVar6 = type->key_len;
        goto LAB_00537810;
      }
      puVar5 = local_6c + sVar4;
      while (sVar4 != local_88) {
        if (local_9c != (uchar *)0x0) {
          *local_9c = *puVar5;
          local_9c = local_9c + 1;
        }
        iVar8 = iVar8 + -1;
        sVar4 = sVar4 + 1;
        if (iVar8 == 0) goto LAB_00537950;
        puVar5 = puVar5 + 1;
      }
      iVar6 = 0;
LAB_00537968:
      local_98 = local_98 + 1;
    }
LAB_0053780c:
    iVar6 = 0;
LAB_00537810:
    EVP_MD_CTX_cleanup(&EStack_84);
    iv = &DAT_00000040;
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(local_6c);
  }
  if (local_2c == *(int *)puVar1) {
    return iVar6;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (iv != &DAT_00000006) {
    return -1;
  }
  iVar6 = RAND_bytes(buf,8);
  if (iVar6 < 1) {
    return 0;
  }
  (*(code *)PTR_DES_set_odd_parity_006a89b8)(buf);
  return 1;
}

