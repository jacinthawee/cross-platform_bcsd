
undefined4 aes_gcm_init_key(int param_1,uchar *param_2,void *param_3)

{
  AES_KEY *key;
  
  if ((param_3 == (void *)0x0) && (param_2 == (uchar *)0x0)) {
    return 1;
  }
  key = *(AES_KEY **)(param_1 + 0x60);
  if (param_2 != (uchar *)0x0) {
    AES_set_encrypt_key(param_2,*(int *)(param_1 + 0x58) << 3,key);
    CRYPTO_gcm128_init(key[1].rd_key + 2,key,AES_encrypt);
    key[2].rd_key[0x28] = 0;
    if ((param_3 != (void *)0x0) ||
       ((key[1].rd_key[1] != 0 && (param_3 = (void *)key[2].rd_key[0x23], param_3 != (void *)0x0))))
    {
      CRYPTO_gcm128_setiv(key[1].rd_key + 2,param_3,key[2].rd_key[0x24]);
      key[1].rd_key[1] = 1;
    }
    key[1].rd_key[0] = 1;
    return 1;
  }
  if (key[1].rd_key[0] == 0) {
    memcpy((void *)key[2].rd_key[0x23],param_3,key[2].rd_key[0x24]);
  }
  else {
    CRYPTO_gcm128_setiv(key[1].rd_key + 2,param_3,key[2].rd_key[0x24]);
  }
  key[1].rd_key[1] = 1;
  key[2].rd_key[0x26] = 0;
  return 1;
}

