
int psk_client_cb(undefined4 param_1,int param_2,char *param_3,undefined *param_4,uchar *param_5,
                 uint param_6)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int in_GS_OFFSET;
  undefined *puVar4;
  BIGNUM *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = (BIGNUM *)0x0;
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
  puVar4 = psk_identity;
  puVar1 = (undefined *)BIO_snprintf(param_3,(size_t)param_4,"%s",psk_identity);
  if (((int)puVar1 < 0) || (param_4 < puVar1)) {
LAB_0806ce70:
    if (c_debug != 0) {
      BIO_printf(bio_err,"Error in PSK client callback\n");
    }
  }
  else {
    if (c_debug != 0) {
      BIO_printf(bio_c_out,"created identity \'%s\' len=%d\n",param_3,puVar1);
      puVar4 = puVar1;
    }
    iVar2 = BN_hex2bn(&local_24,psk_key);
    if (iVar2 != 0) {
      iVar3 = BN_num_bits(local_24);
      iVar2 = iVar3 + 7;
      if (iVar3 + 7 < 0) {
        iVar2 = iVar3 + 0xe;
      }
      if (param_6 < (uint)(iVar2 >> 3)) {
        iVar3 = BN_num_bits(local_24);
        iVar2 = iVar3 + 7;
        if (iVar3 + 7 < 0) {
          iVar2 = iVar3 + 0xe;
        }
        iVar3 = 0;
        BIO_printf(bio_err,"psk buffer of callback is too small (%d) for key (%d)\n",param_6,
                   iVar2 >> 3);
        BN_free(local_24);
        goto LAB_0806ce7f;
      }
      iVar3 = BN_bn2bin(local_24,param_5);
      BN_free(local_24);
      if (iVar3 != 0) {
        if (c_debug != 0) {
          BIO_printf(bio_c_out,"created PSK len=%d\n",iVar3);
        }
        goto LAB_0806ce7f;
      }
      goto LAB_0806ce70;
    }
    BIO_printf(bio_err,"Could not convert PSK key \'%s\' to BIGNUM\n",psk_key,puVar4);
    if (local_24 != (BIGNUM *)0x0) {
      iVar3 = 0;
      BN_free(local_24);
      goto LAB_0806ce7f;
    }
  }
  iVar3 = 0;
LAB_0806ce7f:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

