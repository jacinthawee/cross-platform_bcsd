
int psk_server_cb(undefined4 param_1,char *param_2,uchar *param_3,int param_4)

{
  BIO *bio;
  int iVar1;
  int iVar2;
  size_t sVar3;
  BIGNUM *local_1c;
  
  local_1c = (BIGNUM *)0x0;
  if (s_debug != 0) {
    BIO_printf(bio_s_out,"psk_server_cb\n");
  }
  if (param_2 == (char *)0x0) {
    BIO_printf(bio_err,"Error: client did not send PSK identity\n");
  }
  else {
    if (s_debug != 0) {
      sVar3 = strlen(param_2);
      BIO_printf(bio_s_out,"identity_len=%d identity=%s\n",sVar3,param_2);
    }
    iVar1 = strcmp(param_2,"Client_identity");
    if (iVar1 == 0) {
      if (s_debug != 0) {
        BIO_printf(bio_s_out,"PSK client identity found\n");
      }
      iVar1 = BN_hex2bn(&local_1c,psk_key);
      if (iVar1 == 0) {
        BIO_printf(bio_err,"Could not convert PSK key \'%s\' to BIGNUM\n",psk_key);
        if (local_1c == (BIGNUM *)0x0) {
          return 0;
        }
        BN_free(local_1c);
        return 0;
      }
      iVar2 = BN_num_bits(local_1c);
      bio = bio_err;
      iVar1 = iVar2 + 7;
      if (iVar2 + 7 < 0) {
        iVar1 = iVar2 + 0xe;
      }
      if (param_4 < iVar1 >> 3) {
        iVar2 = BN_num_bits(local_1c);
        iVar1 = iVar2 + 0xe;
        if (-1 < iVar2 + 7) {
          iVar1 = iVar2 + 7;
        }
        BIO_printf(bio,"psk buffer of callback is too small (%d) for key (%d)\n",param_4,iVar1 >> 3)
        ;
        BN_free(local_1c);
        return 0;
      }
      iVar1 = BN_bn2bin(local_1c,param_3);
      BN_free(local_1c);
      if (-1 < iVar1) {
        if (s_debug == 0) {
          return iVar1;
        }
        BIO_printf(bio_s_out,"fetched PSK len=%d\n",iVar1);
        return iVar1;
      }
    }
    else {
      BIO_printf(bio_s_out,"PSK error: client identity not found (got \'%s\' expected \'%s\')\n",
                 param_2,"Client_identity");
    }
  }
  if (s_debug == 0) {
    return 0;
  }
  BIO_printf(bio_err,"Error in PSK server callback\n");
  return 0;
}

