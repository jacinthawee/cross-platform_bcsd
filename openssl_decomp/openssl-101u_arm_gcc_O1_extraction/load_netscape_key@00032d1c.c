
EVP_PKEY *
load_netscape_key(BIO *param_1,BIO *param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  BUF_MEM *str;
  EVP_PKEY *pkey;
  int iVar1;
  rsa_st *key;
  uint length;
  uint uVar2;
  uchar *local_2c [2];
  
  str = BUF_MEM_new();
  pkey = EVP_PKEY_new();
  length = (uint)(str == (BUF_MEM *)0x0 || pkey == (EVP_PKEY *)0x0);
  if (str != (BUF_MEM *)0x0 && pkey != (EVP_PKEY *)0x0) {
    do {
      iVar1 = BUF_MEM_grow_clean(str,length + 0x2800);
      if (iVar1 == 0) goto LAB_00032d6c;
      iVar1 = BIO_read(param_2,str->data + length,0x2800);
      length = length + iVar1;
      if (iVar1 == 0) {
        local_2c[0] = (uchar *)str->data;
        uVar2 = count_leading_zeroes(param_5 + -8);
        key = d2i_RSA_NET((RSA **)0x0,local_2c,length,(cb *)0x0,uVar2 >> 5);
        if (key != (rsa_st *)0x0) {
          BUF_MEM_free(str);
          EVP_PKEY_set1_RSA(pkey,key);
          return pkey;
        }
        goto LAB_00032d6c;
      }
    } while (-1 < iVar1);
    BIO_printf(param_1,"Error reading %s %s",param_4,param_3);
  }
LAB_00032d6c:
  BUF_MEM_free(str);
  EVP_PKEY_free(pkey);
  return (EVP_PKEY *)0x0;
}

