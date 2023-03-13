
EVP_PKEY * b2i_PVK_bio(BIO *in,undefined1 *cb,void *u)

{
  size_t len;
  int iVar1;
  void *data;
  size_t sVar2;
  EVP_PKEY *pEVar3;
  int in_GS_OFFSET;
  int line;
  int local_38 [3];
  int local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = BIO_read(in,local_38,0x18);
  if (iVar1 == 0x18) {
    if (local_38[0] == -0x4f4a0ee2) {
      if ((local_24 < 0x19001) && (local_28 < 0x2801)) {
        if ((local_2c == 0) || (local_28 != 0)) {
          len = local_28 + local_24;
          data = CRYPTO_malloc(len,"pvkfmt.c",0x30a);
          if (data != (void *)0x0) {
            sVar2 = BIO_read(in,data,len);
            if (len == sVar2) {
              pEVar3 = (EVP_PKEY *)do_PVK_body_isra_3(cb,u);
            }
            else {
              pEVar3 = (EVP_PKEY *)0x0;
              ERR_put_error(9,0x80,0x7c,"pvkfmt.c",0x311);
            }
            OPENSSL_cleanse(data,len);
            CRYPTO_free(data);
            goto LAB_0815ac98;
          }
          line = 0x30c;
          iVar1 = 0x41;
          goto LAB_0815acc7;
        }
        ERR_put_error(9,0x88,0x79,"pvkfmt.c",0x296);
      }
    }
    else {
      ERR_put_error(9,0x88,0x74,"pvkfmt.c",0x285);
    }
  }
  else {
    line = 0x302;
    iVar1 = 0x7c;
LAB_0815acc7:
    ERR_put_error(9,0x80,iVar1,"pvkfmt.c",line);
  }
  pEVar3 = (EVP_PKEY *)0x0;
LAB_0815ac98:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pEVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

