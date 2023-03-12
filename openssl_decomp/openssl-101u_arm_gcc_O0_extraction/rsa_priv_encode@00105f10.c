
int rsa_priv_encode(PKCS8_PRIV_KEY_INFO *param_1,int param_2)

{
  int iVar1;
  ASN1_OBJECT *aobj;
  int iVar2;
  uchar *local_14;
  
  iVar2 = 0;
  local_14 = (uchar *)0x0;
  iVar1 = i2d_RSAPrivateKey(*(RSA **)(param_2 + 0x14),&local_14);
  if (iVar1 < 1) {
    iVar1 = 0x85;
  }
  else {
    aobj = OBJ_nid2obj(6);
    iVar2 = PKCS8_pkey_set0(param_1,aobj,0,5,(void *)0x0,local_14,iVar1);
    if (iVar2 != 0) {
      return 1;
    }
    iVar1 = 0x8b;
  }
  ERR_put_error(4,0x8a,0x41,"rsa_ameth.c",iVar1);
  return iVar2;
}

