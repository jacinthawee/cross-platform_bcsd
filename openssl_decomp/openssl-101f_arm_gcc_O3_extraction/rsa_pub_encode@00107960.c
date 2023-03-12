
undefined4 rsa_pub_encode(X509_PUBKEY *param_1,int param_2)

{
  int iVar1;
  ASN1_OBJECT *aobj;
  undefined4 uVar2;
  uchar *local_1c [2];
  
  uVar2 = 0;
  local_1c[0] = (uchar *)0x0;
  iVar1 = i2d_RSAPublicKey(*(RSA **)(param_2 + 0x14),local_1c);
  if (0 < iVar1) {
    aobj = OBJ_nid2obj(6);
    iVar1 = X509_PUBKEY_set0_param(param_1,aobj,5,(void *)0x0,local_1c[0],iVar1);
    if (iVar1 == 0) {
      CRYPTO_free(local_1c[0]);
      return 0;
    }
    uVar2 = 1;
  }
  return uVar2;
}

