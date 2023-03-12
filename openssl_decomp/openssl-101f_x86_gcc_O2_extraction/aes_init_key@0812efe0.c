
undefined4 aes_init_key(int *param_1,uchar *param_2,undefined4 param_3,int param_4)

{
  AES_KEY *key;
  int iVar1;
  code *pcVar2;
  uint uVar3;
  
  key = (AES_KEY *)param_1[0x18];
  uVar3 = *(uint *)(*param_1 + 0x10) & 0xf0007;
  if ((uVar3 - 1 < 2) && (param_4 == 0)) {
    iVar1 = AES_set_decrypt_key(param_2,param_1[0x16] << 3,key);
    key[1].rd_key[0] = (uint)AES_decrypt;
  }
  else {
    iVar1 = AES_set_encrypt_key(param_2,param_1[0x16] << 3,key);
    key[1].rd_key[0] = (uint)AES_encrypt;
  }
  pcVar2 = AES_cbc_encrypt;
  if (uVar3 != 2) {
    pcVar2 = (code *)0x0;
  }
  key[1].rd_key[1] = (uint)pcVar2;
  if (-1 < iVar1) {
    return 1;
  }
  ERR_put_error(6,0x85,0x8f,"e_aes.c",0x237);
  return 0;
}

