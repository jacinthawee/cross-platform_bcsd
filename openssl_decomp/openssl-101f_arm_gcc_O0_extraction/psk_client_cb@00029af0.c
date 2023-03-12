
int psk_client_cb(undefined4 param_1,int param_2,char *param_3,uint param_4,uchar *param_5,
                 uint param_6)

{
  BIO *bio;
  uint uVar1;
  int iVar2;
  int iVar3;
  BIGNUM *local_1c [2];
  
  local_1c[0] = (BIGNUM *)0x0;
  if (c_debug != 0) {
    BIO_printf(bio_c_out,"psk_client_cb\n");
    if (param_2 == 0) {
      if (c_debug != 0) {
        BIO_printf(bio_c_out,"NULL received PSK identity hint, continuing anyway\n");
      }
    }
    else if (c_debug != 0) {
      BIO_printf(bio_c_out,"Received PSK identity hint \'%s\'\n",param_2);
    }
  }
  uVar1 = BIO_snprintf(param_3,param_4,"%s",psk_identity);
  if (((uint)(param_4 < uVar1) | uVar1 >> 0x1f) == 0) {
    if (c_debug != 0) {
      BIO_printf(bio_c_out,"created identity \'%s\' len=%d\n",param_3,uVar1);
    }
    iVar2 = BN_hex2bn(local_1c,psk_key);
    if (iVar2 == 0) {
      BIO_printf(bio_err,"Could not convert PSK key \'%s\' to BIGNUM\n",psk_key);
      if (local_1c[0] == (BIGNUM *)0x0) {
        return 0;
      }
      BN_free(local_1c[0]);
      return 0;
    }
    iVar3 = BN_num_bits(local_1c[0]);
    bio = bio_err;
    iVar2 = iVar3 + 7;
    if (iVar3 + 7 < 0) {
      iVar2 = iVar3 + 0xe;
    }
    if (param_6 < (uint)(iVar2 >> 3)) {
      iVar3 = BN_num_bits(local_1c[0]);
      iVar2 = iVar3 + 7;
      if (iVar3 + 7 < 0) {
        iVar2 = iVar3 + 0xe;
      }
      BIO_printf(bio,"psk buffer of callback is too small (%d) for key (%d)\n",param_6,iVar2 >> 3);
      BN_free(local_1c[0]);
      return 0;
    }
    iVar2 = BN_bn2bin(local_1c[0],param_5);
    BN_free(local_1c[0]);
    if (iVar2 != 0) {
      if (c_debug != 0) {
        BIO_printf(bio_c_out,"created PSK len=%d\n",iVar2);
        return iVar2;
      }
      return iVar2;
    }
  }
  if (c_debug == 0) {
    return 0;
  }
  BIO_printf(bio_err,"Error in PSK client callback\n");
  return 0;
}

