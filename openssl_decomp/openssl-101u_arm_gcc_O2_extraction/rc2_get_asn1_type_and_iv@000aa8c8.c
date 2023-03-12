
void rc2_get_asn1_type_and_iv(EVP_CIPHER_CTX *param_1,ASN1_TYPE *param_2)

{
  ASN1_TYPE *max_len;
  ASN1_TYPE *pAVar1;
  int iVar2;
  int keylen;
  int arg;
  int local_30;
  uchar auStack_2c [16];
  int local_1c;
  
  local_30 = 0;
  local_1c = __stack_chk_guard;
  max_len = param_2;
  if (param_2 != (ASN1_TYPE *)0x0) {
    max_len = (ASN1_TYPE *)EVP_CIPHER_CTX_iv_length(param_1);
    if ((ASN1_TYPE *)&DAT_00000010 < max_len) {
      OpenSSLDie("e_rc2.c",0xb3,"l <= sizeof(iv)");
    }
    pAVar1 = (ASN1_TYPE *)ASN1_TYPE_get_int_octetstring(param_2,&local_30,auStack_2c,(int)max_len);
    if (max_len == pAVar1) {
      if (local_30 == 0x3a) {
        keylen = 0x10;
        arg = 0x80;
      }
      else if (local_30 == 0x78) {
        keylen = 8;
        arg = 0x40;
      }
      else {
        if (local_30 != 0xa0) {
          max_len = (ASN1_TYPE *)0xffffffff;
          ERR_put_error(6,0x6d,0x6c,"e_rc2.c",0xa4);
          goto LAB_000aa930;
        }
        keylen = 5;
        arg = 0x28;
      }
      if (((int)max_len < 1) ||
         (iVar2 = EVP_CipherInit_ex(param_1,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)0x0,auStack_2c,
                                    -1), iVar2 != 0)) {
        EVP_CIPHER_CTX_ctrl(param_1,3,arg,(void *)0x0);
        EVP_CIPHER_CTX_set_key_length(param_1,keylen);
        goto LAB_000aa930;
      }
    }
    max_len = (ASN1_TYPE *)0xffffffff;
  }
LAB_000aa930:
  if (local_1c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(max_len);
  }
  return;
}

