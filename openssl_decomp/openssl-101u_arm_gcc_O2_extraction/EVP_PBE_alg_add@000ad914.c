
int EVP_PBE_alg_add(int nid,EVP_CIPHER *cipher,EVP_MD *md,undefined1 *keygen)

{
  _STACK *st;
  undefined4 *data;
  int iVar1;
  int iVar2;
  
  iVar2 = -1;
  if (cipher != (EVP_CIPHER *)0x0) {
    iVar2 = EVP_CIPHER_nid(cipher);
  }
  iVar1 = -1;
  if (md != (EVP_MD *)0x0) {
    iVar1 = EVP_MD_type(md);
  }
  if (pbe_algs == (_STACK *)0x0) {
    pbe_algs = sk_new(pbe_cmp + 1);
    if (pbe_algs == (_STACK *)0x0) goto LAB_000ad98c;
  }
  data = (undefined4 *)CRYPTO_malloc(0x14,"evp_pbe.c",0xee);
  if (data != (undefined4 *)0x0) {
    data[1] = nid;
    data[2] = iVar2;
    data[3] = iVar1;
    data[4] = keygen;
    st = pbe_algs;
    *data = 0;
    sk_push(st,data);
    return 1;
  }
LAB_000ad98c:
  ERR_put_error(6,0xa0,0x41,"evp_pbe.c",0xfb);
  return 0;
}

