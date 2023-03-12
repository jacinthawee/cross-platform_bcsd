
BIGNUM * dsa_pub_encode(X509_PUBKEY *param_1,int param_2)

{
  ulong *puVar1;
  int penclen;
  ASN1_OBJECT *aobj;
  DSA *a;
  BIGNUM *a_00;
  int iVar2;
  uchar *local_1c;
  
  a_00 = *(BIGNUM **)(param_2 + 0x18);
  a = *(DSA **)(param_2 + 0x14);
  local_1c = (uchar *)0x0;
  if ((((a_00 == (BIGNUM *)0x0) || (a_00 = a->p, a_00 == (BIGNUM *)0x0)) ||
      (a_00 = a->q, a_00 == (BIGNUM *)0x0)) || (a_00 = a->g, a_00 == (BIGNUM *)0x0)) {
    iVar2 = -1;
  }
  else {
    a_00 = (BIGNUM *)ASN1_STRING_new();
    puVar1 = (ulong *)i2d_DSAparams(a,(uchar **)&a_00->dmax);
    a_00->d = puVar1;
    if ((int)puVar1 < 1) {
      a_00 = (BIGNUM *)0x0;
      ERR_put_error(10,0x76,0x41,"dsa_ameth.c",0x9a);
      goto LAB_0010913e;
    }
    iVar2 = 0x10;
  }
  a->write_params = 0;
  penclen = i2d_DSAPublicKey(a,&local_1c);
  if (penclen < 1) {
    ERR_put_error(10,0x76,0x41,"dsa_ameth.c",0xa9);
  }
  else {
    aobj = OBJ_nid2obj(0x74);
    iVar2 = X509_PUBKEY_set0_param(param_1,aobj,iVar2,a_00,local_1c,penclen);
    if (iVar2 != 0) {
      return (BIGNUM *)0x1;
    }
  }
LAB_0010913e:
  if (local_1c != (uchar *)0x0) {
    CRYPTO_free(local_1c);
  }
  if (a_00 != (BIGNUM *)0x0) {
    ASN1_STRING_free((ASN1_STRING *)a_00);
    a_00 = (BIGNUM *)0x0;
  }
  return a_00;
}

