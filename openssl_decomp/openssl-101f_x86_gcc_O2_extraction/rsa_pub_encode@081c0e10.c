
int rsa_pub_encode(X509_PUBKEY *param_1,int param_2)

{
  uchar *penc;
  int penclen;
  int iVar1;
  ASN1_OBJECT *aobj;
  int in_GS_OFFSET;
  uchar *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = (uchar *)0x0;
  penclen = i2d_RSAPublicKey(*(RSA **)(param_2 + 0x14),&local_14);
  penc = local_14;
  iVar1 = 0;
  if (0 < penclen) {
    aobj = OBJ_nid2obj(6);
    iVar1 = X509_PUBKEY_set0_param(param_1,aobj,5,(void *)0x0,penc,penclen);
    if (iVar1 == 0) {
      CRYPTO_free(local_14);
    }
    else {
      iVar1 = 1;
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

