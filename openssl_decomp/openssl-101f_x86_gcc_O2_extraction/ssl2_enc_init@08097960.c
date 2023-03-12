
int ssl2_enc_init(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uchar *iv;
  EVP_CIPHER_CTX *a;
  EVP_CIPHER_CTX *a_00;
  int in_GS_OFFSET;
  EVP_CIPHER *local_28;
  undefined4 local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = ssl_cipher_get_evp(*(undefined4 *)(param_1 + 0xc0),&local_28,&local_24,0,0,0);
  if (iVar1 == 0) {
    ssl2_return_error(param_1,1);
    ERR_put_error(0x14,0x7c,0xce,"s2_enc.c",0x4a);
    goto LAB_08097aa3;
  }
  ssl_replace_hash(param_1 + 0x84,local_24);
  ssl_replace_hash(param_1 + 0x90,local_24);
  a = *(EVP_CIPHER_CTX **)(param_1 + 0x80);
  if (a == (EVP_CIPHER_CTX *)0x0) {
    a = (EVP_CIPHER_CTX *)CRYPTO_malloc(0x8c,"s2_enc.c",0x52);
    *(EVP_CIPHER_CTX **)(param_1 + 0x80) = a;
    if (a != (EVP_CIPHER_CTX *)0x0) goto LAB_080979d3;
LAB_08097c00:
    ERR_put_error(0x14,0x7c,0x41,"s2_enc.c",0x72);
    iVar1 = 0;
  }
  else {
LAB_080979d3:
    EVP_CIPHER_CTX_init(a);
    a_00 = *(EVP_CIPHER_CTX **)(param_1 + 0x8c);
    if (a_00 == (EVP_CIPHER_CTX *)0x0) {
      a_00 = (EVP_CIPHER_CTX *)CRYPTO_malloc(0x8c,"s2_enc.c",0x5c);
      *(EVP_CIPHER_CTX **)(param_1 + 0x8c) = a_00;
      if (a_00 == (EVP_CIPHER_CTX *)0x0) goto LAB_08097c00;
    }
    EVP_CIPHER_CTX_init(a_00);
    iVar1 = local_28->key_len;
    *(int *)(*(int *)(param_1 + 0x54) + 0x9c) = iVar1 * 2;
    if ((uint)(iVar1 * 2) < 0x31) {
      iVar2 = ssl2_generate_key_material(param_1);
    }
    else {
      OpenSSLDie("s2_enc.c",100,"s->s2->key_material_length <= sizeof s->s2->key_material");
      iVar2 = ssl2_generate_key_material(param_1);
    }
    if (iVar2 < 1) {
      iVar1 = 0;
    }
    else {
      if (8 < local_28->iv_len) {
        OpenSSLDie("s2_enc.c",0x69,"c->iv_len <= (int)sizeof(s->session->key_arg)");
      }
      iv = (uchar *)(*(int *)(param_1 + 0xc0) + 8);
      if (param_2 == 0) {
        EVP_EncryptInit_ex(a_00,local_28,(ENGINE *)0x0,(uchar *)(*(int *)(param_1 + 0x54) + 0xa0),iv
                          );
        EVP_DecryptInit_ex(a,local_28,(ENGINE *)0x0,
                           (uchar *)(*(int *)(param_1 + 0x54) + iVar1 + 0xa0),
                           (uchar *)(*(int *)(param_1 + 0xc0) + 8));
        iVar2 = *(int *)(param_1 + 0x54);
        *(int *)(iVar2 + 0x5c) = iVar1 + 0xa0 + iVar2;
        iVar1 = 0;
      }
      else {
        EVP_EncryptInit_ex(a_00,local_28,(ENGINE *)0x0,
                           (uchar *)(*(int *)(param_1 + 0x54) + 0xa0 + iVar1),iv);
        EVP_DecryptInit_ex(a,local_28,(ENGINE *)0x0,(uchar *)(*(int *)(param_1 + 0x54) + 0xa0),
                           (uchar *)(*(int *)(param_1 + 0xc0) + 8));
        iVar2 = *(int *)(param_1 + 0x54);
        *(int *)(iVar2 + 0x5c) = iVar2 + 0xa0;
      }
      *(int *)(iVar2 + 0x60) = iVar2 + 0xa0 + iVar1;
      iVar1 = 1;
    }
  }
LAB_08097aa3:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

