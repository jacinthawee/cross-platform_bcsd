
EVP_PKEY * b2i_PVK_bio(BIO *in,undefined1 *cb,void *u)

{
  int iVar1;
  EVP_PKEY *data;
  size_t sVar2;
  size_t len;
  EVP_PKEY *pEVar3;
  uint uVar4;
  uint uVar5;
  byte local_48;
  byte local_47;
  byte local_46;
  byte local_45;
  byte local_3c;
  byte local_3b;
  byte local_3a;
  byte local_39;
  byte local_38;
  byte local_37;
  byte local_36;
  byte local_35;
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  iVar1 = BIO_read(in,&local_48,0x18);
  if (iVar1 == 0x18) {
    if (((uint)local_46 << 0x10 | (uint)local_47 << 8 | (uint)local_48 | (uint)local_45 << 0x18) ==
        0xb0b5f11e) {
      uVar4 = (uint)local_32 << 0x10 | (uint)local_33 << 8 | (uint)local_34 | (uint)local_31 << 0x18
      ;
      if ((uVar4 < 0x19001) &&
         (uVar5 = (uint)local_36 << 0x10 | (uint)local_37 << 8 | (uint)local_38 |
                  (uint)local_35 << 0x18, uVar5 < 0x2801)) {
        if ((((uint)local_3c | (uint)local_3a << 0x10 | (uint)local_3b << 8 | (uint)local_39 << 0x18
             ) == 0) || (uVar5 != 0)) {
          len = uVar4 + uVar5;
          data = (EVP_PKEY *)CRYPTO_malloc(len,"pvkfmt.c",0x30a);
          if (data == (EVP_PKEY *)0x0) {
            ERR_put_error(9,0x80,0x41,"pvkfmt.c",0x30c);
          }
          else {
            sVar2 = BIO_read(in,data,len);
            if (sVar2 == len) {
              pEVar3 = (EVP_PKEY *)do_PVK_body_isra_4(data,uVar5,uVar4,cb,u);
            }
            else {
              pEVar3 = (EVP_PKEY *)0x0;
              ERR_put_error(9,0x80,0x7c,"pvkfmt.c",0x311);
            }
            OPENSSL_cleanse(data,len);
            CRYPTO_free(data);
            data = pEVar3;
          }
          goto LAB_000c6304;
        }
        ERR_put_error(9,0x88,0x79,"pvkfmt.c",0x296);
      }
    }
    else {
      ERR_put_error(9,0x88,0x74,"pvkfmt.c",0x285);
    }
    data = (EVP_PKEY *)0x0;
  }
  else {
    ERR_put_error(9,0x80,0x7c,"pvkfmt.c",0x302);
    data = (EVP_PKEY *)0x0;
  }
LAB_000c6304:
  if (local_2c == __stack_chk_guard) {
    return data;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

