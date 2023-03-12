
int ssl3_get_client_certificate(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  X509 *a;
  void *pvVar4;
  _STACK **pp_Var5;
  byte *pbVar6;
  undefined4 uVar7;
  uint len;
  _STACK *st;
  int in_GS_OFFSET;
  int iVar8;
  int local_28;
  byte *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = (**(code **)(param_1[2] + 0x30))(param_1,0x2180,0x2181,0xffffffff,param_1[0x42],&local_28)
  ;
  if (local_28 == 0) goto LAB_0809c19d;
  iVar8 = param_1[0x16];
  if (*(int *)(iVar8 + 0x340) == 0x10) {
    if ((param_1[0x32] & 3U) == 3) {
      st = (_STACK *)0x0;
      uVar7 = 0x28;
      ERR_put_error(0x14,0x89,199,"s3_srvr.c",0xc71);
      goto LAB_0809c185;
    }
    if ((*param_1 < 0x301) || (*(int *)(iVar8 + 0x390) == 0)) {
      *(undefined4 *)(iVar8 + 0x354) = 1;
      iVar2 = 1;
      goto LAB_0809c19d;
    }
    iVar8 = 0xc78;
    iVar2 = 0xe9;
LAB_0809c16f:
    st = (_STACK *)0x0;
    uVar7 = 10;
    ERR_put_error(0x14,0x89,iVar2,"s3_srvr.c",iVar8);
LAB_0809c185:
    ssl3_send_alert(param_1,2,uVar7);
    if (st != (_STACK *)0x0) goto LAB_0809c1f8;
  }
  else {
    if (*(int *)(iVar8 + 0x340) != 0xb) {
      iVar8 = 0xc83;
      iVar2 = 0x106;
      goto LAB_0809c16f;
    }
    local_24 = (byte *)param_1[0x10];
    st = sk_new_null();
    if (st == (_STACK *)0x0) {
      ERR_put_error(0x14,0x89,0x41,"s3_srvr.c",0xc8a);
      iVar2 = -1;
      goto LAB_0809c19d;
    }
    uVar3 = (uint)local_24[1] << 8 | (uint)*local_24 << 0x10 | (uint)local_24[2];
    if (iVar2 != uVar3 + 3) {
      iVar8 = 0xc92;
      iVar2 = 0x9f;
      local_24 = local_24 + 3;
LAB_0809c2a9:
      uVar7 = 0x32;
      ERR_put_error(0x14,0x89,iVar2,"s3_srvr.c",iVar8);
      goto LAB_0809c185;
    }
    pbVar6 = local_24 + 3;
    if (uVar3 != 0) {
      pbVar6 = local_24 + 6;
      len = (uint)local_24[4] << 8 | (uint)local_24[3] << 0x10 | (uint)local_24[5];
      for (uVar1 = len + 3; local_24 = pbVar6, uVar1 <= uVar3; uVar1 = len + 3 + uVar1) {
        a = d2i_X509((X509 **)0x0,&local_24,len);
        if (a == (X509 *)0x0) {
          ERR_put_error(0x14,0x89,0xd,"s3_srvr.c",0xca3);
          goto LAB_0809c1f8;
        }
        if (local_24 != pbVar6 + len) {
          ERR_put_error(0x14,0x89,0x87,"s3_srvr.c",0xca9);
          ssl3_send_alert(param_1,2,0x32);
LAB_0809c51e:
          X509_free(a);
          goto LAB_0809c1f8;
        }
        iVar2 = sk_push(st,a);
        if (iVar2 == 0) {
          ERR_put_error(0x14,0x89,0x41,"s3_srvr.c",0xcae);
          goto LAB_0809c51e;
        }
        pbVar6 = local_24;
        if (uVar3 <= uVar1) goto LAB_0809c408;
        pbVar6 = local_24 + 3;
        len = (uint)*local_24 << 0x10 | (uint)local_24[1] << 8 | (uint)local_24[2];
      }
      iVar8 = 0xc9b;
      iVar2 = 0x87;
      goto LAB_0809c2a9;
    }
LAB_0809c408:
    local_24 = pbVar6;
    iVar2 = sk_num(st);
    if (iVar2 < 1) {
      if (*param_1 == 0x300) {
        iVar8 = 0xcbb;
        iVar2 = 0xb0;
      }
      else {
        if ((param_1[0x32] & 3U) != 3) {
          if ((*(int *)(param_1[0x16] + 0x178) != 0) &&
             (iVar2 = ssl3_digest_cached_records(param_1), iVar2 == 0)) {
            uVar7 = 0x50;
            goto LAB_0809c185;
          }
          goto LAB_0809c431;
        }
        iVar8 = 0xcc2;
        iVar2 = 199;
      }
      uVar7 = 0x28;
      ERR_put_error(0x14,0x89,iVar2,"s3_srvr.c",iVar8);
      goto LAB_0809c185;
    }
    iVar2 = ssl_verify_cert_chain(param_1,st);
    if (iVar2 < 1) {
      uVar7 = ssl_verify_alarm_type(param_1[0x3b]);
      ERR_put_error(0x14,0x89,0xb2,"s3_srvr.c",0xcd3);
      goto LAB_0809c185;
    }
LAB_0809c431:
    iVar2 = param_1[0x30];
    if (*(X509 **)(iVar2 + 0x9c) != (X509 *)0x0) {
      X509_free(*(X509 **)(iVar2 + 0x9c));
      iVar2 = param_1[0x30];
    }
    pvVar4 = sk_shift(st);
    *(void **)(iVar2 + 0x9c) = pvVar4;
    iVar2 = param_1[0x30];
    *(int *)(iVar2 + 0xa0) = param_1[0x3b];
    if (*(int *)(iVar2 + 0x98) != 0) {
LAB_0809c485:
      pp_Var5 = *(_STACK ***)(iVar2 + 0x98);
      if (*pp_Var5 != (_STACK *)0x0) {
        sk_pop_free(*pp_Var5,X509_free);
        pp_Var5 = *(_STACK ***)(param_1[0x30] + 0x98);
      }
      *pp_Var5 = st;
      iVar2 = 1;
      goto LAB_0809c19d;
    }
    uVar7 = ssl_sess_cert_new();
    *(undefined4 *)(iVar2 + 0x98) = uVar7;
    iVar2 = param_1[0x30];
    if (*(int *)(iVar2 + 0x98) != 0) goto LAB_0809c485;
    ERR_put_error(0x14,0x89,0x41,"s3_srvr.c",0xce4);
LAB_0809c1f8:
    sk_pop_free(st,X509_free);
  }
  iVar2 = -1;
LAB_0809c19d:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

