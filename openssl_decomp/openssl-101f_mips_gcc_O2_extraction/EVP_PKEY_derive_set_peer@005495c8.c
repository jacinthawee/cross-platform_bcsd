
int EVP_PKEY_derive_set_peer(EVP_PKEY_CTX *ctx,EVP_PKEY *peer)

{
  int iVar1;
  int iVar2;
  
  if ((((ctx == (EVP_PKEY_CTX *)0x0) || (iVar1 = *(int *)ctx, iVar1 == 0)) ||
      ((*(int *)(iVar1 + 0x60) == 0 &&
       ((*(int *)(iVar1 + 0x50) == 0 && (*(int *)(iVar1 + 0x58) == 0)))))) ||
     (*(code **)(iVar1 + 100) == (code *)0x0)) {
    ERR_put_error(6,0x9b,0x96,"pmeth_fn.c",0x123);
    iVar1 = -2;
  }
  else {
    iVar2 = *(int *)(ctx + 0x10);
    if (((iVar2 == 0x400) || (iVar2 == 0x100)) || (iVar2 == 0x200)) {
      iVar1 = (**(code **)(iVar1 + 100))(ctx,2,0,peer);
      if (iVar1 < 1) {
        return iVar1;
      }
      if (iVar1 == 2) {
        return 1;
      }
      if (*(int **)(ctx + 8) == (int *)0x0) {
        iVar2 = 0x9a;
        iVar1 = 0x137;
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
            (*(code *)PTR_CRYPTO_add_lock_006a9080)(&peer->references,1,10,"pmeth_fn.c",0x15b);
            return 1;
          }
          *(undefined4 *)(ctx + 0xc) = 0;
          return iVar1;
        }
        iVar2 = 0x99;
        iVar1 = 0x14b;
      }
      else {
        iVar2 = 0x65;
        iVar1 = 0x13e;
      }
    }
    else {
      iVar2 = 0x97;
      iVar1 = 0x129;
    }
    ERR_put_error(6,0x9b,iVar2,"pmeth_fn.c",iVar1);
    iVar1 = -1;
  }
  return iVar1;
}

