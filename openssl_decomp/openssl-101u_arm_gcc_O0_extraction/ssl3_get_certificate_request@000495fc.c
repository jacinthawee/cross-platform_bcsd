
byte * ssl3_get_certificate_request(int *param_1)

{
  byte *pbVar1;
  _STACK *st;
  uint len;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  X509_NAME *a;
  int local_30;
  byte *local_2c [2];
  
  pbVar1 = (byte *)(**(code **)(param_1[2] + 0x30))
                             (param_1,0x1150,0x1151,0xffffffff,param_1[0x42],&local_30);
  if (local_30 == 0) {
    return pbVar1;
  }
  iVar2 = param_1[0x16];
  *(undefined4 *)(iVar2 + 0x358) = 0;
  if (*(int *)(iVar2 + 0x340) == 0xe) {
    *(undefined4 *)(iVar2 + 0x354) = 1;
    if (*(int *)(iVar2 + 0x178) == 0) {
      return (byte *)0x1;
    }
    iVar2 = ssl3_digest_cached_records(param_1);
    if (iVar2 != 0) {
      return (byte *)0x1;
    }
LAB_00049660:
    param_1[0xd] = 5;
    X509_NAME_free((X509_NAME *)0x0);
    return (byte *)0x0;
  }
  if (*(int *)(iVar2 + 0x340) != 0xd) {
    ssl3_send_alert(param_1,2,10);
    ERR_put_error(0x14,0x87,0x106,"s3_clnt.c",0x7de);
    goto LAB_00049660;
  }
  if ((0x300 < *param_1) && (*(int *)(*(int *)(iVar2 + 0x344) + 0x10) << 0x1d < 0)) {
    ssl3_send_alert(param_1,2,10);
    ERR_put_error(0x14,0x87,0xe8,"s3_clnt.c",0x7e7);
    goto LAB_00049660;
  }
  pbVar4 = (byte *)param_1[0x10];
  st = sk_new(ca_dn_cmp + 1);
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x14,0x87,0x41,"s3_clnt.c",0x7ef);
    goto LAB_00049660;
  }
  uVar7 = (uint)*pbVar4;
  if (8 < uVar7) {
    uVar7 = 9;
  }
  if ((((((uVar7 != 0) && (*(byte *)(param_1[0x16] + 0x360) = pbVar4[1], 1 < uVar7)) &&
        (*(byte *)(param_1[0x16] + 0x361) = pbVar4[2], 2 < uVar7)) &&
       ((*(byte *)(param_1[0x16] + 0x362) = pbVar4[3], 3 < uVar7 &&
        (*(byte *)(param_1[0x16] + 0x363) = pbVar4[4], 4 < uVar7)))) &&
      ((*(byte *)(param_1[0x16] + 0x364) = pbVar4[5], 5 < uVar7 &&
       ((*(byte *)(param_1[0x16] + 0x365) = pbVar4[6], 6 < uVar7 &&
        (*(byte *)(param_1[0x16] + 0x366) = pbVar4[7], 7 < uVar7)))))) &&
     (*(byte *)(param_1[0x16] + 0x367) = pbVar4[8], 8 < uVar7)) {
    *(byte *)(param_1[0x16] + 0x368) = pbVar4[9];
  }
  pbVar3 = pbVar4 + uVar7 + 1;
  if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
    pbVar8 = pbVar3 + 2;
    uVar6 = (uint)CONCAT11(pbVar4[uVar7 + 1],pbVar3[1]);
    if (pbVar1 < pbVar8 + (uVar6 - (int)pbVar4) + 2) {
      a = (X509_NAME *)0x0;
      ssl3_send_alert(param_1,2,0x32);
      ERR_put_error(0x14,0x87,0x92,"s3_clnt.c",0x803);
      goto LAB_00049770;
    }
    if (((int)(uVar6 << 0x1f) < 0) ||
       (iVar2 = tls1_process_sigalgs(param_1,pbVar8,uVar6), iVar2 == 0)) {
      a = (X509_NAME *)0x0;
      ssl3_send_alert(param_1,2,0x32);
      ERR_put_error(0x14,0x87,0x168,"s3_clnt.c",0x809);
      goto LAB_00049770;
    }
    pbVar3 = pbVar8 + uVar6;
  }
  uVar6 = (uint)CONCAT11(*pbVar3,pbVar3[1]);
  if (pbVar3 + uVar6 + (2 - (int)pbVar4) == pbVar1) {
    if (uVar6 == 0) {
LAB_0004982a:
      iVar2 = param_1[0x16];
      *(uint *)(iVar2 + 0x35c) = uVar7;
      *(undefined4 *)(iVar2 + 0x358) = 1;
      if (*(_STACK **)(iVar2 + 0x36c) != (_STACK *)0x0) {
        sk_pop_free(*(_STACK **)(iVar2 + 0x36c),X509_NAME_free);
        iVar2 = param_1[0x16];
      }
      *(_STACK **)(iVar2 + 0x36c) = st;
      X509_NAME_free((X509_NAME *)0x0);
      return (byte *)0x1;
    }
    if (uVar6 == 1) {
LAB_000498e0:
      a = (X509_NAME *)0x0;
      ssl3_send_alert(param_1,2,0x32);
      iVar2 = 0x823;
    }
    else {
      len = (uint)CONCAT11(pbVar3[2],pbVar3[3]);
      pbVar4 = pbVar3 + 4;
      pbVar1 = local_2c[0];
      for (uVar5 = len + 2; local_2c[0] = pbVar4, uVar5 <= uVar6; uVar5 = uVar5 + len + 2) {
        pbVar1 = local_2c[0] + len;
        a = d2i_X509_NAME((X509_NAME **)0x0,local_2c,len);
        if (a == (X509_NAME *)0x0) {
          if (param_1[0x40] << 2 < 0) goto LAB_00049826;
          ssl3_send_alert(param_1,2,0x32);
          ERR_put_error(0x14,0x87,0xd,"s3_clnt.c",0x837);
          goto LAB_00049770;
        }
        if (pbVar1 != local_2c[0]) {
          ssl3_send_alert(param_1,2,0x32);
          ERR_put_error(0x14,0x87,0x83,"s3_clnt.c",0x83f);
          goto LAB_00049770;
        }
        iVar2 = sk_push(st,a);
        if (iVar2 == 0) {
          ERR_put_error(0x14,0x87,0x41,"s3_clnt.c",0x843);
          goto LAB_00049770;
        }
        if (uVar6 <= uVar5) goto LAB_0004982a;
        if (uVar6 < uVar5 + 2) goto LAB_000498e0;
        len = (uint)CONCAT11(*pbVar1,pbVar1[1]);
        pbVar4 = pbVar1 + 2;
        pbVar1 = local_2c[0];
      }
      a = (X509_NAME *)(param_1[0x40] & 0x20000000);
      local_2c[0] = pbVar1;
      if (a != (X509_NAME *)0x0) {
LAB_00049826:
        ERR_clear_error();
        goto LAB_0004982a;
      }
      ssl3_send_alert(param_1,2,0x32);
      iVar2 = 0x82b;
    }
    ERR_put_error(0x14,0x87,0x84,"s3_clnt.c",iVar2);
  }
  else {
    a = (X509_NAME *)0x0;
    ssl3_send_alert(param_1,2,0x32);
    ERR_put_error(0x14,0x87,0x9f,"s3_clnt.c",0x81c);
  }
LAB_00049770:
  param_1[0xd] = 5;
  X509_NAME_free(a);
  sk_pop_free(st,X509_NAME_free);
  return (byte *)0x0;
}

