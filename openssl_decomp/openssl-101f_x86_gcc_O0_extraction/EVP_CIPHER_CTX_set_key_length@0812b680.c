
int EVP_CIPHER_CTX_set_key_length(EVP_CIPHER_CTX *x,int keylen)

{
  uint uVar1;
  _func_1094 *p_Var2;
  int iVar3;
  int line;
  
  uVar1 = x->cipher->flags;
  if ((uVar1 & 0x80) == 0) {
    if (keylen == x->key_len) {
      return 1;
    }
    if ((0 < keylen) && ((uVar1 & 8) != 0)) {
      x->key_len = keylen;
      return 1;
    }
    ERR_put_error(6,0x7a,0x82,"evp_enc.c",0x25e);
  }
  else {
    p_Var2 = x->cipher->ctrl;
    if (p_Var2 == (_func_1094 *)0x0) {
      line = 0x272;
      iVar3 = 0x84;
    }
    else {
      iVar3 = (*p_Var2)(x,1,keylen,(void *)0x0);
      if (iVar3 != -1) {
        return iVar3;
      }
      line = 0x278;
      iVar3 = 0x85;
    }
    ERR_put_error(6,0x7c,iVar3,"evp_enc.c",line);
  }
  return 0;
}

