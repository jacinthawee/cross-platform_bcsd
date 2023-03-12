
undefined4 aes_xts_init_key(int param_1,uchar *param_2,undefined4 *param_3,int param_4)

{
  AES_KEY *key;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((param_3 != (undefined4 *)0x0) || (param_2 != (uchar *)0x0)) {
    key = *(AES_KEY **)(param_1 + 0x60);
    if (param_2 != (uchar *)0x0) {
      key[2].rd_key[4] = 0;
      if (param_4 == 0) {
        AES_set_decrypt_key(param_2,*(int *)(param_1 + 0x58) << 2,key);
        key[2].rd_key[2] = (uint)AES_decrypt;
      }
      else {
        AES_set_encrypt_key(param_2,*(int *)(param_1 + 0x58) << 2,key);
        key[2].rd_key[2] = (uint)AES_encrypt;
      }
      AES_set_encrypt_key(param_2 + *(int *)(param_1 + 0x58) / 2,*(int *)(param_1 + 0x58) * 4,
                          key + 1);
      key[2].rd_key[3] = (uint)AES_encrypt;
      key[2].rd_key[0] = (uint)key;
    }
    if (param_3 != (undefined4 *)0x0) {
      key[2].rd_key[1] = (uint)(key + 1);
      uVar1 = param_3[3];
      uVar2 = param_3[1];
      uVar3 = param_3[2];
      *(undefined4 *)(param_1 + 0x20) = *param_3;
      *(undefined4 *)(param_1 + 0x2c) = uVar1;
      *(undefined4 *)(param_1 + 0x24) = uVar2;
      *(undefined4 *)(param_1 + 0x28) = uVar3;
      return 1;
    }
  }
  return 1;
}

