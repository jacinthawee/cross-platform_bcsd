
int rsa_priv_encode(PKCS8_PRIV_KEY_INFO *param_1,int param_2)

{
  uchar *penc;
  int iVar1;
  ASN1_OBJECT *aobj;
  int in_GS_OFFSET;
  uchar *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = (uchar *)0x0;
  iVar1 = i2d_RSAPrivateKey(*(RSA **)(param_2 + 0x14),&local_14);
  penc = local_14;
  if (iVar1 < 1) {
    ERR_put_error(4,0x8a,0x41,"rsa_ameth.c",0x87);
    iVar1 = 0;
  }
  else {
    aobj = OBJ_nid2obj(6);
    iVar1 = PKCS8_pkey_set0(param_1,aobj,0,5,(void *)0x0,penc,iVar1);
    if (iVar1 == 0) {
      ERR_put_error(4,0x8a,0x41,"rsa_ameth.c",0x8e);
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

