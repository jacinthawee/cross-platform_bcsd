
int psk_server_cb(undefined4 param_1,byte *param_2,uchar *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  int in_GS_OFFSET;
  undefined uVar4;
  bool bVar5;
  undefined uVar6;
  byte bVar7;
  BIGNUM *local_24;
  int local_20;
  
  bVar7 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = (BIGNUM *)0x0;
  if (s_debug == 0) {
    bVar5 = param_2 == (byte *)0x0;
    if (bVar5) {
LAB_08069890:
      BIO_printf(bio_err,"Error: client did not send PSK identity\n");
      goto joined_r0x080698ad;
    }
LAB_08069809:
    iVar1 = 0x10;
    pbVar3 = (byte *)"Client_identity";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar5 = *param_2 == *pbVar3;
      param_2 = param_2 + (uint)bVar7 * -2 + 1;
      pbVar3 = pbVar3 + (uint)bVar7 * -2 + 1;
    } while (bVar5);
    if (!bVar5) goto LAB_080699d0;
LAB_0806981d:
    iVar1 = BN_hex2bn(&local_24,psk_key);
    if (iVar1 != 0) {
      iVar2 = BN_num_bits(local_24);
      iVar1 = iVar2 + 7;
      if (iVar2 + 7 < 0) {
        iVar1 = iVar2 + 0xe;
      }
      if (param_4 < iVar1 >> 3) {
        iVar2 = BN_num_bits(local_24);
        iVar1 = iVar2 + 7;
        if (iVar2 + 7 < 0) {
          iVar1 = iVar2 + 0xe;
        }
        iVar2 = 0;
        BIO_printf(bio_err,"psk buffer of callback is too small (%d) for key (%d)\n",param_4,
                   iVar1 >> 3);
        BN_free(local_24);
        goto LAB_0806986d;
      }
      iVar2 = BN_bn2bin(local_24,param_3);
      BN_free(local_24);
      if (-1 < iVar2) {
        if (s_debug != 0) {
          BIO_printf(bio_s_out,"fetched PSK len=%d\n");
        }
        goto LAB_0806986d;
      }
      goto joined_r0x080698ad;
    }
    BIO_printf(bio_err,"Could not convert PSK key \'%s\' to BIGNUM\n");
    if (local_24 != (BIGNUM *)0x0) {
      iVar2 = 0;
      BN_free(local_24);
      goto LAB_0806986d;
    }
  }
  else {
    BIO_printf(bio_s_out,"psk_server_cb\n");
    if (param_2 == (byte *)0x0) goto LAB_08069890;
    bVar5 = s_debug == 0;
    if (bVar5) goto LAB_08069809;
    strlen((char *)param_2);
    uVar4 = (undefined *)0xffffffef < &stack0xffffffc4;
    uVar6 = &stack0x00000000 == &DAT_0000002c;
    BIO_printf(bio_s_out,"identity_len=%d identity=%s\n");
    iVar1 = 0x10;
    pbVar3 = (byte *)"Client_identity";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      uVar4 = *param_2 < *pbVar3;
      uVar6 = *param_2 == *pbVar3;
      param_2 = param_2 + (uint)bVar7 * -2 + 1;
      pbVar3 = pbVar3 + (uint)bVar7 * -2 + 1;
    } while ((bool)uVar6);
    if ((!(bool)uVar4 && !(bool)uVar6) == (bool)uVar4) {
      if (s_debug != 0) {
        BIO_printf(bio_s_out,"PSK client identity found\n");
      }
      goto LAB_0806981d;
    }
LAB_080699d0:
    BIO_printf(bio_s_out,"PSK error: client identity not found (got \'%s\' expected \'%s\')\n");
joined_r0x080698ad:
    if (s_debug != 0) {
      BIO_printf(bio_err,"Error in PSK server callback\n");
    }
  }
  iVar2 = 0;
LAB_0806986d:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

