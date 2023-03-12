
int EVP_PBE_alg_add_type(int pbe_type,int pbe_nid,int cipher_nid,int md_nid,undefined1 *keygen)

{
  _STACK *st;
  int *data;
  
  if (pbe_algs == (_STACK *)0x0) {
    pbe_algs = sk_new(pbe_cmp);
    if (pbe_algs == (_STACK *)0x0) goto LAB_00543528;
  }
  data = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x14,"evp_pbe.c",0xee);
  st = pbe_algs;
  if (data != (int *)0x0) {
    *data = pbe_type;
    data[1] = pbe_nid;
    data[2] = cipher_nid;
    data[3] = md_nid;
    data[4] = (int)keygen;
    sk_push(st,data);
    return 1;
  }
LAB_00543528:
  ERR_put_error(6,0xa0,0x41,"evp_pbe.c",0xfb);
  return 0;
}

