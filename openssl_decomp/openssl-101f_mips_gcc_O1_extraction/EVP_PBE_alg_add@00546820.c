
int EVP_PBE_alg_add(int nid,EVP_CIPHER *cipher,EVP_MD *md,undefined1 *keygen)

{
  _STACK *st;
  int iVar1;
  int iVar2;
  undefined4 *data;
  
  if (cipher == (EVP_CIPHER *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = EVP_CIPHER_type(cipher);
  }
  if (md == (EVP_MD *)0x0) {
    iVar2 = -1;
  }
  else {
    iVar2 = EVP_MD_type(md);
  }
  if (pbe_algs == (_STACK *)0x0) {
    pbe_algs = sk_new(pbe_cmp);
  }
  data = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x14,"evp_pbe.c",0xf1);
  st = pbe_algs;
  if (data == (undefined4 *)0x0) {
    ERR_put_error(6,0xa0,0x41,"evp_pbe.c",0xf3);
    return 0;
  }
  data[1] = nid;
  data[2] = iVar1;
  data[3] = iVar2;
  data[4] = keygen;
  *data = 0;
  sk_push(st,data);
  return 1;
}

