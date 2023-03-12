
uint rc2_get_asn1_type_and_iv(EVP_CIPHER_CTX *param_1,ASN1_TYPE *param_2)

{
  uint uVar1;
  int iVar2;
  int arg;
  uint max_len;
  int keylen;
  int in_GS_OFFSET;
  int local_34;
  uchar local_30 [16];
  int local_20;
  
  max_len = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_34 = 0;
  if (param_2 == (ASN1_TYPE *)0x0) goto LAB_0812f98b;
  max_len = EVP_CIPHER_CTX_iv_length(param_1);
  if (0x10 < max_len) {
    OpenSSLDie("e_rc2.c",0xb3,"l <= sizeof(iv)");
  }
  uVar1 = ASN1_TYPE_get_int_octetstring(param_2,&local_34,local_30,max_len);
  if (max_len == uVar1) {
    if (local_34 == 0x3a) {
      keylen = 0x10;
      arg = 0x80;
    }
    else if (local_34 == 0x78) {
      keylen = 8;
      arg = 0x40;
    }
    else {
      keylen = 5;
      arg = 0x28;
      if (local_34 != 0xa0) {
        ERR_put_error(6,0x6d,0x6c,"e_rc2.c",0xa3);
        goto LAB_0812f986;
      }
    }
    if (0 < (int)max_len) {
      iVar2 = EVP_CipherInit_ex(param_1,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)0x0,local_30,-1);
      if (iVar2 == 0) goto LAB_0812f986;
    }
    EVP_CIPHER_CTX_ctrl(param_1,3,arg,(void *)0x0);
    EVP_CIPHER_CTX_set_key_length(param_1,keylen);
  }
  else {
LAB_0812f986:
    max_len = 0xffffffff;
  }
LAB_0812f98b:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return max_len;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

