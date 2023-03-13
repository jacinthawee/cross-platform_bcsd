
int EVP_PBE_alg_add(int nid,EVP_CIPHER *cipher,EVP_MD *md,undefined1 *keygen)

{
  undefined4 *data;
  int iVar1;
  int iVar2;
  
  iVar1 = -1;
  if (cipher != (EVP_CIPHER *)0x0) {
    iVar1 = EVP_CIPHER_nid(cipher);
  }
  iVar2 = -1;
  if (md != (EVP_MD *)0x0) {
    iVar2 = EVP_MD_type(md);
  }
  if (pbe_algs == (_STACK *)0x0) {
    pbe_algs = sk_new(pbe_cmp);
    if (pbe_algs == (_STACK *)0x0) goto LAB_081321d1;
  }
  data = (undefined4 *)CRYPTO_malloc(0x14,"evp_pbe.c",0xee);
  if (data != (undefined4 *)0x0) {
    data[2] = iVar1;
    data[3] = iVar2;
    *data = 0;
    data[1] = nid;
    data[4] = keygen;
    sk_push(pbe_algs,data);
    return 1;
  }
LAB_081321d1:
  ERR_put_error(6,0xa0,0x41,"evp_pbe.c",0xfb);
  return 0;
}

