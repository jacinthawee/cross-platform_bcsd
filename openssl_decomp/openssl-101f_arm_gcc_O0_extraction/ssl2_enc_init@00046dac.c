
undefined4 ssl2_enc_init(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  EVP_CIPHER_CTX *a;
  undefined4 uVar3;
  EVP_CIPHER_CTX *a_00;
  EVP_CIPHER *local_20;
  undefined4 local_1c;
  
  iVar1 = ssl_cipher_get_evp(*(undefined4 *)(param_1 + 0xc0),&local_20,&local_1c,0,0,0);
  if (iVar1 == 0) {
    ssl2_return_error(param_1,1);
    ERR_put_error(0x14,0x7c,0xce,"s2_enc.c",0x4a);
    return 0;
  }
  ssl_replace_hash(param_1 + 0x84,local_1c);
  ssl_replace_hash(param_1 + 0x90,local_1c);
  a = *(EVP_CIPHER_CTX **)(param_1 + 0x80);
  if (a == (EVP_CIPHER_CTX *)0x0) {
    a = (EVP_CIPHER_CTX *)CRYPTO_malloc(0x8c,"s2_enc.c",0x52);
    *(EVP_CIPHER_CTX **)(param_1 + 0x80) = a;
    if (a != (EVP_CIPHER_CTX *)0x0) goto LAB_00046dee;
LAB_00046f4a:
    uVar3 = 0;
    ERR_put_error(0x14,0x7c,0x41,"s2_enc.c",0x72);
  }
  else {
LAB_00046dee:
    EVP_CIPHER_CTX_init(a);
    a_00 = *(EVP_CIPHER_CTX **)(param_1 + 0x8c);
    if (a_00 == (EVP_CIPHER_CTX *)0x0) {
      a_00 = (EVP_CIPHER_CTX *)CRYPTO_malloc(0x8c,"s2_enc.c",0x5c);
      *(EVP_CIPHER_CTX **)(param_1 + 0x8c) = a_00;
      if (a_00 == (EVP_CIPHER_CTX *)0x0) goto LAB_00046f4a;
    }
    EVP_CIPHER_CTX_init(a_00);
    iVar1 = local_20->key_len;
    *(int *)(*(int *)(param_1 + 0x54) + 0x9c) = iVar1 * 2;
    if ((uint)(iVar1 * 2) < 0x31) {
      iVar2 = ssl2_generate_key_material(param_1);
      if (iVar2 < 1) {
        return 0;
      }
    }
    else {
      OpenSSLDie("s2_enc.c",100,"s->s2->key_material_length <= sizeof s->s2->key_material");
      iVar2 = ssl2_generate_key_material(param_1);
      if (iVar2 < 1) {
        return 0;
      }
    }
    if (8 < local_20->iv_len) {
      OpenSSLDie("s2_enc.c",0x69,"c->iv_len <= (int)sizeof(s->session->key_arg)");
    }
    if (param_2 == 0) {
      EVP_EncryptInit_ex(a_00,local_20,(ENGINE *)0x0,(uchar *)(*(int *)(param_1 + 0x54) + 0xa0),
                         (uchar *)(*(int *)(param_1 + 0xc0) + 8));
      EVP_DecryptInit_ex(a,local_20,(ENGINE *)0x0,(uchar *)(*(int *)(param_1 + 0x54) + iVar1 + 0xa0)
                         ,(uchar *)(*(int *)(param_1 + 0xc0) + 8));
      iVar2 = *(int *)(param_1 + 0x54);
      *(int *)(iVar2 + 0x5c) = iVar2 + iVar1 + 0xa0;
    }
    else {
      EVP_EncryptInit_ex(a_00,local_20,(ENGINE *)0x0,
                         (uchar *)(*(int *)(param_1 + 0x54) + iVar1 + 0xa0),
                         (uchar *)(*(int *)(param_1 + 0xc0) + 8));
      EVP_DecryptInit_ex(a,local_20,(ENGINE *)0x0,(uchar *)(*(int *)(param_1 + 0x54) + 0xa0),
                         (uchar *)(*(int *)(param_1 + 0xc0) + 8));
      iVar2 = *(int *)(param_1 + 0x54);
      *(int *)(iVar2 + 0x5c) = iVar2 + 0xa0;
      param_2 = iVar1;
    }
    uVar3 = 1;
    *(int *)(iVar2 + 0x60) = param_2 + 0xa0 + iVar2;
  }
  return uVar3;
}

