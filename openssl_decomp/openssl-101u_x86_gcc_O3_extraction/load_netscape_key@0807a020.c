
EVP_PKEY * __regparm3
load_netscape_key(BIO *param_1_00,BIO *param_2_00,undefined4 param_3,undefined4 param_1,int param_2)

{
  BUF_MEM *str;
  EVP_PKEY *pkey;
  int iVar1;
  rsa_st *key;
  int length;
  int in_GS_OFFSET;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  str = BUF_MEM_new();
  pkey = EVP_PKEY_new();
  if ((str != (BUF_MEM *)0x0) && (pkey != (EVP_PKEY *)0x0)) {
    length = 0;
    do {
      iVar1 = BUF_MEM_grow_clean(str,length + 0x2800);
      if (iVar1 == 0) goto LAB_0807a09a;
      iVar1 = BIO_read(param_2_00,str->data + length,0x2800);
      length = length + iVar1;
      if (iVar1 == 0) {
        local_24 = (uchar *)str->data;
        key = d2i_RSA_NET((RSA **)0x0,&local_24,length,(cb *)0x0,(uint)(param_2 == 8));
        if (key == (rsa_st *)0x0) goto LAB_0807a09a;
        BUF_MEM_free(str);
        EVP_PKEY_set1_RSA(pkey,key);
        goto LAB_0807a0b0;
      }
    } while (-1 < iVar1);
    BIO_printf(param_1_00,"Error reading %s %s",param_1,param_3);
  }
LAB_0807a09a:
  BUF_MEM_free(str);
  EVP_PKEY_free(pkey);
  pkey = (EVP_PKEY *)0x0;
LAB_0807a0b0:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pkey;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

