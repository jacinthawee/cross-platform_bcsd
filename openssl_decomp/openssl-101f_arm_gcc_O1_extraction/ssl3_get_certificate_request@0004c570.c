
byte * ssl3_get_certificate_request(int *param_1)

{
  byte *pbVar1;
  _STACK *st;
  X509_NAME *data;
  uint len;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  int local_28;
  byte *local_24;
  
  pbVar1 = (byte *)(**(code **)(param_1[2] + 0x30))
                             (param_1,0x1150,0x1151,0xffffffff,param_1[0x42],&local_28);
  if (local_28 == 0) {
    return pbVar1;
  }
  iVar2 = param_1[0x16];
  *(undefined4 *)(iVar2 + 0x358) = 0;
  if (*(int *)(iVar2 + 0x340) == 0xe) {
    *(undefined4 *)(iVar2 + 0x354) = 1;
    if ((*(int *)(iVar2 + 0x178) != 0) && (iVar2 = ssl3_digest_cached_records(param_1), iVar2 == 0))
    {
      return (byte *)0x0;
    }
  }
  else {
    if (*(int *)(iVar2 + 0x340) != 0xd) {
      ssl3_send_alert(param_1,2,10);
      ERR_put_error(0x14,0x87,0x106,"s3_clnt.c",0x768);
      return (byte *)0x0;
    }
    if ((0x300 < *param_1) && (*(int *)(*(int *)(iVar2 + 0x344) + 0x10) << 0x1d < 0)) {
      ssl3_send_alert(param_1,2,10);
      ERR_put_error(0x14,0x87,0xe8,"s3_clnt.c",0x772);
      return (byte *)0x0;
    }
    pbVar4 = (byte *)param_1[0x10];
    st = sk_new(ca_dn_cmp + 1);
    if (st == (_STACK *)0x0) {
      ERR_put_error(0x14,0x87,0x41,"s3_clnt.c",0x77b);
      return (byte *)0x0;
    }
    uVar6 = (uint)*pbVar4;
    if (8 < uVar6) {
      uVar6 = 9;
    }
    if ((((((uVar6 != 0) && (*(byte *)(param_1[0x16] + 0x360) = pbVar4[1], 1 < uVar6)) &&
          (*(byte *)(param_1[0x16] + 0x361) = pbVar4[2], 2 < uVar6)) &&
         ((*(byte *)(param_1[0x16] + 0x362) = pbVar4[3], 3 < uVar6 &&
          (*(byte *)(param_1[0x16] + 0x363) = pbVar4[4], 4 < uVar6)))) &&
        ((*(byte *)(param_1[0x16] + 0x364) = pbVar4[5], 5 < uVar6 &&
         ((*(byte *)(param_1[0x16] + 0x365) = pbVar4[6], 6 < uVar6 &&
          (*(byte *)(param_1[0x16] + 0x366) = pbVar4[7], 7 < uVar6)))))) &&
       (*(byte *)(param_1[0x16] + 0x367) = pbVar4[8], 8 < uVar6)) {
      *(byte *)(param_1[0x16] + 0x368) = pbVar4[9];
    }
    pbVar3 = pbVar4 + uVar6 + 1;
    if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
      pbVar8 = pbVar3 + 2;
      uVar7 = (uint)CONCAT11(pbVar4[uVar6 + 1],pbVar3[1]);
      if (pbVar1 < pbVar8 + (uVar7 - (int)pbVar4) + 2) {
        ssl3_send_alert(param_1,2,0x32);
        ERR_put_error(0x14,0x87,0x92,"s3_clnt.c",0x78f);
        goto LAB_0004c6d6;
      }
      if (((int)(uVar7 << 0x1f) < 0) ||
         (iVar2 = tls1_process_sigalgs(param_1,pbVar8,uVar7), iVar2 == 0)) {
        ssl3_send_alert(param_1,2,0x32);
        ERR_put_error(0x14,0x87,0x168,"s3_clnt.c",0x795);
        goto LAB_0004c6d6;
      }
      pbVar3 = pbVar8 + uVar7;
    }
    uVar7 = (uint)CONCAT11(*pbVar3,pbVar3[1]);
    if (pbVar3 + uVar7 + (2 - (int)pbVar4) != pbVar1) {
      ssl3_send_alert(param_1,2,0x32);
      ERR_put_error(0x14,0x87,0x9f,"s3_clnt.c",0x7a9);
LAB_0004c6d6:
      sk_pop_free(st,X509_NAME_free + 1);
      return (byte *)0x0;
    }
    if (uVar7 != 0) {
      len = (uint)CONCAT11(pbVar3[2],pbVar3[3]);
      pbVar4 = pbVar3 + 4;
      pbVar1 = local_24;
      for (uVar5 = len + 2; local_24 = pbVar4, uVar5 <= uVar7; uVar5 = uVar5 + len + 2) {
        pbVar1 = local_24 + len;
        data = d2i_X509_NAME((X509_NAME **)0x0,&local_24,len);
        if (data == (X509_NAME *)0x0) {
          if (param_1[0x40] << 2 < 0) goto LAB_0004c76a;
          ssl3_send_alert(param_1,2,0x32);
          ERR_put_error(0x14,0x87,0xd,"s3_clnt.c",0x7c3);
          goto LAB_0004c6d6;
        }
        if (pbVar1 != local_24) {
          ssl3_send_alert(param_1,2,0x32);
          ERR_put_error(0x14,0x87,0x83,"s3_clnt.c",0x7cb);
          goto LAB_0004c6d6;
        }
        iVar2 = sk_push(st,data);
        if (iVar2 == 0) {
          ERR_put_error(0x14,0x87,0x41,"s3_clnt.c",2000);
          goto LAB_0004c6d6;
        }
        if (uVar7 <= uVar5) goto LAB_0004c76e;
        len = (uint)CONCAT11(*pbVar1,pbVar1[1]);
        pbVar4 = pbVar1 + 2;
        pbVar1 = local_24;
      }
      local_24 = pbVar1;
      if (-1 < param_1[0x40] << 2) {
        ssl3_send_alert(param_1,2,0x32);
        ERR_put_error(0x14,0x87,0x84,"s3_clnt.c",0x7b5);
        goto LAB_0004c6d6;
      }
LAB_0004c76a:
      ERR_clear_error();
    }
LAB_0004c76e:
    iVar2 = param_1[0x16];
    *(uint *)(iVar2 + 0x35c) = uVar6;
    *(undefined4 *)(iVar2 + 0x358) = 1;
    if (*(_STACK **)(iVar2 + 0x36c) != (_STACK *)0x0) {
      sk_pop_free(*(_STACK **)(iVar2 + 0x36c),X509_NAME_free + 1);
      iVar2 = param_1[0x16];
    }
    *(_STACK **)(iVar2 + 0x36c) = st;
  }
  return (byte *)0x1;
}

