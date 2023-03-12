
int EVP_PKEY_derive_set_peer(EVP_PKEY_CTX *ctx,EVP_PKEY *peer)

{
  int iVar1;
  int line;
  
  if ((((ctx == (EVP_PKEY_CTX *)0x0) || (iVar1 = *(int *)ctx, iVar1 == 0)) ||
      ((*(int *)(iVar1 + 0x60) == 0 &&
       ((*(int *)(iVar1 + 0x50) == 0 && (*(int *)(iVar1 + 0x58) == 0)))))) ||
     (*(code **)(iVar1 + 100) == (code *)0x0)) {
    ERR_put_error(6,0x9b,0x96,"pmeth_fn.c",0x123);
    iVar1 = -2;
  }
  else {
    if (((*(int *)(ctx + 0x10) - 0x100U & 0xfffffeff) == 0) || (*(int *)(ctx + 0x10) == 0x400)) {
      iVar1 = (**(code **)(iVar1 + 100))(ctx,2,0,peer);
      if (iVar1 < 1) {
        return iVar1;
      }
      if (iVar1 == 2) {
        return 1;
      }
      if (*(int **)(ctx + 8) == (int *)0x0) {
        line = 0x137;
        iVar1 = 0x9a;
      }
      else if (**(int **)(ctx + 8) == peer->type) {
        iVar1 = EVP_PKEY_missing_parameters(peer);
        if ((iVar1 != 0) ||
           (iVar1 = EVP_PKEY_cmp_parameters(*(EVP_PKEY **)(ctx + 8),peer), iVar1 != 0)) {
          if (*(EVP_PKEY **)(ctx + 0xc) != (EVP_PKEY *)0x0) {
            EVP_PKEY_free(*(EVP_PKEY **)(ctx + 0xc));
          }
          *(EVP_PKEY **)(ctx + 0xc) = peer;
          iVar1 = (**(code **)(*(int *)ctx + 100))(ctx,2,1,peer);
          if (0 < iVar1) {
            CRYPTO_add_lock(&peer->references,1,10,"pmeth_fn.c",0x15b);
            return 1;
          }
          *(undefined4 *)(ctx + 0xc) = 0;
          return iVar1;
        }
        line = 0x14b;
        iVar1 = 0x99;
      }
      else {
        line = 0x13e;
        iVar1 = 0x65;
      }
    }
    else {
      line = 0x129;
      iVar1 = 0x97;
    }
    ERR_put_error(6,0x9b,iVar1,"pmeth_fn.c",line);
    iVar1 = -1;
  }
  return iVar1;
}

