
int EVP_CIPHER_CTX_set_key_length(EVP_CIPHER_CTX *x,int keylen)

{
  uint uVar1;
  int iVar2;
  int reason;
  _func_1094 *p_Var3;
  
  uVar1 = x->cipher->flags;
  if ((uVar1 & 0x80) == 0) {
    if (keylen == x->key_len) {
      return 1;
    }
    if ((0 < keylen) && ((uVar1 & 8) != 0)) {
      x->key_len = keylen;
      return 1;
    }
    ERR_put_error(6,0x7a,0x82,"evp_enc.c",0x244);
  }
  else {
    p_Var3 = x->cipher->ctrl;
    if (p_Var3 == (_func_1094 *)0x0) {
      reason = 0x84;
      iVar2 = 0x25a;
    }
    else {
      iVar2 = (*p_Var3)(x,1,keylen,(void *)0x0);
      if (iVar2 != -1) {
        return iVar2;
      }
      reason = 0x85;
      iVar2 = 0x261;
    }
    ERR_put_error(6,0x7c,reason,"evp_enc.c",iVar2);
  }
  return 0;
}

