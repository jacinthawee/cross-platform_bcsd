
int EVP_CIPHER_CTX_set_key_length(EVP_CIPHER_CTX *x,int keylen)

{
  _func_1094 *p_Var1;
  uint uVar2;
  
  uVar2 = x->cipher->flags;
  if ((uVar2 & 0x80) == 0) {
    if (x->key_len == keylen) {
      p_Var1 = (_func_1094 *)0x1;
    }
    else if ((keylen < 1) || (-1 < (int)(uVar2 << 0x1c))) {
      ERR_put_error(6,0x7a,0x82,"evp_enc.c",0x244);
      p_Var1 = (_func_1094 *)0x0;
    }
    else {
      x->key_len = keylen;
      p_Var1 = (_func_1094 *)0x1;
    }
  }
  else {
    p_Var1 = x->cipher->ctrl;
    if (p_Var1 == (_func_1094 *)0x0) {
      ERR_put_error(6,0x7c,0x84,"evp_enc.c",0x25a);
    }
    else {
      p_Var1 = (_func_1094 *)(*p_Var1)(x,1,keylen,(void *)0x0);
      if (p_Var1 == (_func_1094 *)0xffffffff) {
        ERR_put_error(6,0x7c,0x85,"evp_enc.c",0x261);
        p_Var1 = (_func_1094 *)0x0;
      }
    }
  }
  return (int)p_Var1;
}

