
byte * ssl3_get_certificate_request(int *param_1)

{
  byte *pbVar1;
  ushort uVar2;
  byte *pbVar3;
  _STACK *st;
  X509_NAME *data;
  uint uVar4;
  ushort *puVar5;
  ushort *puVar6;
  uint uVar7;
  uint len;
  int in_GS_OFFSET;
  int iVar8;
  int line;
  int local_28;
  ushort *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pbVar3 = (byte *)(**(code **)(param_1[2] + 0x30))
                             (param_1,0x1150,0x1151,0xffffffff,param_1[0x42],&local_28);
  if (local_28 == 0) goto LAB_080a0212;
  iVar8 = param_1[0x16];
  *(undefined4 *)(iVar8 + 0x358) = 0;
  if (*(int *)(iVar8 + 0x340) == 0xe) {
    *(undefined4 *)(iVar8 + 0x354) = 1;
    if (*(int *)(iVar8 + 0x178) != 0) {
      iVar8 = ssl3_digest_cached_records(param_1);
      pbVar3 = (byte *)0x0;
      if (iVar8 == 0) goto LAB_080a0212;
    }
LAB_080a042c:
    pbVar3 = (byte *)0x1;
  }
  else {
    if (*(int *)(iVar8 + 0x340) == 0xd) {
      if ((*param_1 < 0x301) || ((*(byte *)(*(int *)(iVar8 + 0x344) + 0x10) & 4) == 0)) {
        pbVar1 = (byte *)param_1[0x10];
        st = sk_new(ca_dn_cmp);
        if (st != (_STACK *)0x0) {
          uVar4 = 9;
          if (*pbVar1 < 10) {
            uVar4 = (uint)*pbVar1;
          }
          if ((((((uVar4 != 0) && (*(byte *)(param_1[0x16] + 0x360) = pbVar1[1], uVar4 != 1)) &&
                (*(byte *)(param_1[0x16] + 0x361) = pbVar1[2], uVar4 != 2)) &&
               ((*(byte *)(param_1[0x16] + 0x362) = pbVar1[3], uVar4 != 3 &&
                (*(byte *)(param_1[0x16] + 0x363) = pbVar1[4], uVar4 != 4)))) &&
              ((*(byte *)(param_1[0x16] + 0x364) = pbVar1[5], uVar4 != 5 &&
               ((*(byte *)(param_1[0x16] + 0x365) = pbVar1[6], uVar4 != 6 &&
                (*(byte *)(param_1[0x16] + 0x366) = pbVar1[7], uVar4 != 7)))))) &&
             (*(byte *)(param_1[0x16] + 0x367) = pbVar1[8], uVar4 == 9)) {
            *(byte *)(param_1[0x16] + 0x368) = pbVar1[9];
          }
          puVar6 = (ushort *)(pbVar1 + uVar4 + 1);
          if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
            puVar5 = puVar6 + 1;
            uVar2 = *puVar6 >> 8;
            uVar7 = (uint)(ushort)(*puVar6 << 8 | uVar2);
            if (pbVar3 < (byte *)((int)puVar5 + ((uVar7 + 2) - (int)pbVar1))) {
              ssl3_send_alert(param_1,2,0x32);
              ERR_put_error(0x14,0x87,0x92,"s3_clnt.c",0x78f);
            }
            else {
              if (((uVar2 & 1) == 0) &&
                 (iVar8 = tls1_process_sigalgs(param_1,puVar5,uVar7), iVar8 != 0)) {
                puVar6 = (ushort *)((int)puVar5 + uVar7);
                goto LAB_080a0390;
              }
              ssl3_send_alert(param_1,2,0x32);
              ERR_put_error(0x14,0x87,0x168,"s3_clnt.c",0x795);
            }
          }
          else {
LAB_080a0390:
            uVar2 = *puVar6 << 8 | *puVar6 >> 8;
            if (pbVar3 == (byte *)((int)puVar6 + (uint)uVar2 + (2 - (int)pbVar1))) {
              if (uVar2 != 0) {
                puVar5 = puVar6 + 2;
                len = (uint)(ushort)(puVar6[1] << 8 | puVar6[1] >> 8);
                for (uVar7 = len + 2; uVar7 <= uVar2; uVar7 = len + 2 + uVar7) {
                  local_24 = puVar5;
                  data = d2i_X509_NAME((X509_NAME **)0x0,(uchar **)&local_24,len);
                  if (data == (X509_NAME *)0x0) {
                    if ((*(byte *)((int)param_1 + 0x103) & 0x20) != 0) goto LAB_080a04ed;
                    ssl3_send_alert(param_1,2,0x32);
                    ERR_put_error(0x14,0x87,0xd,"s3_clnt.c",0x7c3);
                    goto LAB_080a03de;
                  }
                  puVar6 = (ushort *)((int)puVar5 + len);
                  if (puVar6 != local_24) {
                    ssl3_send_alert(param_1,2,0x32);
                    ERR_put_error(0x14,0x87,0x83,"s3_clnt.c",0x7cb);
                    goto LAB_080a03de;
                  }
                  iVar8 = sk_push(st,data);
                  if (iVar8 == 0) {
                    ERR_put_error(0x14,0x87,0x41,"s3_clnt.c",2000);
                    goto LAB_080a03de;
                  }
                  if (uVar2 <= uVar7) goto LAB_080a04f2;
                  puVar5 = puVar6 + 1;
                  len = (uint)(ushort)(*puVar6 << 8 | *puVar6 >> 8);
                }
                if ((*(byte *)((int)param_1 + 0x103) & 0x20) == 0) {
                  ssl3_send_alert(param_1,2,0x32);
                  ERR_put_error(0x14,0x87,0x84,"s3_clnt.c",0x7b5);
                  goto LAB_080a03de;
                }
LAB_080a04ed:
                ERR_clear_error();
              }
LAB_080a04f2:
              iVar8 = param_1[0x16];
              *(undefined4 *)(iVar8 + 0x358) = 1;
              *(uint *)(iVar8 + 0x35c) = uVar4;
              if (*(_STACK **)(iVar8 + 0x36c) != (_STACK *)0x0) {
                sk_pop_free(*(_STACK **)(iVar8 + 0x36c),X509_NAME_free);
                iVar8 = param_1[0x16];
              }
              *(_STACK **)(iVar8 + 0x36c) = st;
              goto LAB_080a042c;
            }
            ssl3_send_alert(param_1,2,0x32);
            ERR_put_error(0x14,0x87,0x9f,"s3_clnt.c",0x7a9);
          }
LAB_080a03de:
          sk_pop_free(st,X509_NAME_free);
          pbVar3 = (byte *)0x0;
          goto LAB_080a0212;
        }
        line = 0x77b;
        iVar8 = 0x41;
      }
      else {
        ssl3_send_alert(param_1,2,10);
        line = 0x772;
        iVar8 = 0xe8;
      }
    }
    else {
      ssl3_send_alert(param_1,2,10);
      line = 0x768;
      iVar8 = 0x106;
    }
    ERR_put_error(0x14,0x87,iVar8,"s3_clnt.c",line);
    pbVar3 = (byte *)0x0;
  }
LAB_080a0212:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pbVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

