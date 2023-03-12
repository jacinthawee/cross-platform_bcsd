
undefined4 aes_gcm_init_key(int param_1,uchar *param_2,void *param_3)

{
  AES_KEY *key;
  uint uVar1;
  uint uVar2;
  
  uVar1 = count_leading_zeroes(param_3);
  key = *(AES_KEY **)(param_1 + 0x60);
  if (param_2 == (uchar *)0x0) {
    uVar2 = uVar1 >> 5 & 1;
  }
  else {
    uVar2 = 0;
  }
  if (uVar2 == 0) {
    if (param_2 == (uchar *)0x0) {
      if (key[1].rd_key[0] == 0) {
        memcpy((void *)key[2].rd_key[0x24],param_3,key[2].rd_key[0x25]);
      }
      else {
        CRYPTO_gcm128_setiv(key[1].rd_key + 3,param_3,key[2].rd_key[0x25]);
      }
      key[1].rd_key[1] = 1;
      key[2].rd_key[0x27] = 0;
      return 1;
    }
    AES_set_encrypt_key(param_2,*(int *)(param_1 + 0x58) << 3,key);
    CRYPTO_gcm128_init(key[1].rd_key + 3,key,AES_encrypt);
    key[2].rd_key[0x29] = 0;
    if ((uVar1 >> 5 == 0) ||
       ((key[1].rd_key[1] != 0 && (param_3 = (void *)key[2].rd_key[0x24], param_3 != (void *)0x0))))
    {
      CRYPTO_gcm128_setiv(key[1].rd_key + 3,param_3,key[2].rd_key[0x25]);
      key[1].rd_key[1] = 1;
    }
    key[1].rd_key[0] = 1;
  }
  return 1;
}

