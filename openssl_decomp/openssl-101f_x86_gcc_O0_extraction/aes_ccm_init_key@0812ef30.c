
undefined4 aes_ccm_init_key(int param_1,uchar *param_2,void *param_3)

{
  AES_KEY *key;
  
  if ((param_3 != (void *)0x0) || (param_2 != (uchar *)0x0)) {
    key = *(AES_KEY **)(param_1 + 0x60);
    if (param_2 != (uchar *)0x0) {
      AES_set_encrypt_key(param_2,*(int *)(param_1 + 0x58) * 8,key);
      CRYPTO_ccm128_init(key[1].rd_key + 6,key[1].rd_key[5],key[1].rd_key[4],key,AES_encrypt);
      key[1].rd_key[0x12] = 0;
      key[1].rd_key[0] = 1;
    }
    if (param_3 != (void *)0x0) {
      memcpy((void *)(param_1 + 0x20),param_3,0xf - key[1].rd_key[4]);
      key[1].rd_key[1] = 1;
      return 1;
    }
  }
  return 1;
}

