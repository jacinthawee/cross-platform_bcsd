
byte * ssl3_get_certificate_request(int *param_1)

{
  uint uVar1;
  byte *pbVar2;
  byte *pbVar3;
  _STACK *st;
  int iVar4;
  uint uVar5;
  X509_NAME *a;
  ushort uVar6;
  uint uVar7;
  uint len;
  ushort *puVar8;
  ushort *puVar9;
  int in_GS_OFFSET;
  int iVar10;
  int local_28;
  ushort *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pbVar3 = (byte *)(**(code **)(param_1[2] + 0x30))
                             (param_1,0x1150,0x1151,0xffffffff,param_1[0x42],&local_28);
  if (local_28 == 0) goto LAB_0809c6c6;
  iVar4 = param_1[0x16];
  *(undefined4 *)(iVar4 + 0x358) = 0;
  if (*(int *)(iVar4 + 0x340) == 0xe) {
    *(undefined4 *)(iVar4 + 0x354) = 1;
    if ((*(int *)(iVar4 + 0x178) == 0) || (iVar4 = ssl3_digest_cached_records(param_1), iVar4 != 0))
    {
LAB_0809c8e8:
      pbVar3 = (byte *)0x1;
      goto LAB_0809c6c6;
    }
  }
  else if (*(int *)(iVar4 + 0x340) == 0xd) {
    if ((*param_1 < 0x301) || ((*(byte *)(*(int *)(iVar4 + 0x344) + 0x10) & 4) == 0)) {
      pbVar2 = (byte *)param_1[0x10];
      st = sk_new(ca_dn_cmp);
      if (st != (_STACK *)0x0) {
        uVar7 = 9;
        if (*pbVar2 < 10) {
          uVar7 = (uint)*pbVar2;
        }
        if ((((((uVar7 != 0) && (*(byte *)(param_1[0x16] + 0x360) = pbVar2[1], uVar7 != 1)) &&
              (*(byte *)(param_1[0x16] + 0x361) = pbVar2[2], uVar7 != 2)) &&
             ((*(byte *)(param_1[0x16] + 0x362) = pbVar2[3], uVar7 != 3 &&
              (*(byte *)(param_1[0x16] + 0x363) = pbVar2[4], uVar7 != 4)))) &&
            ((*(byte *)(param_1[0x16] + 0x364) = pbVar2[5], uVar7 != 5 &&
             ((*(byte *)(param_1[0x16] + 0x365) = pbVar2[6], uVar7 != 6 &&
              (*(byte *)(param_1[0x16] + 0x366) = pbVar2[7], uVar7 != 7)))))) &&
           (*(byte *)(param_1[0x16] + 0x367) = pbVar2[8], uVar7 == 9)) {
          *(byte *)(param_1[0x16] + 0x368) = pbVar2[9];
        }
        puVar8 = (ushort *)(pbVar2 + uVar7 + 1);
        if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
          puVar9 = puVar8 + 1;
          uVar6 = *puVar8 >> 8;
          uVar5 = (uint)(ushort)(*puVar8 << 8 | uVar6);
          if (pbVar3 < (byte *)((int)puVar9 + ((uVar5 + 2) - (int)pbVar2))) {
            ssl3_send_alert(param_1,2,0x32);
            iVar10 = 0x803;
            iVar4 = 0x92;
          }
          else {
            if (((uVar6 & 1) == 0) &&
               (iVar4 = tls1_process_sigalgs(param_1,puVar9,uVar5), iVar4 != 0)) {
              puVar8 = (ushort *)((int)puVar9 + uVar5);
              goto LAB_0809c840;
            }
            ssl3_send_alert(param_1,2,0x32);
            iVar10 = 0x809;
            iVar4 = 0x168;
          }
        }
        else {
LAB_0809c840:
          uVar6 = *puVar8 << 8 | *puVar8 >> 8;
          uVar5 = (uint)uVar6;
          if (pbVar3 == (byte *)((int)puVar8 + uVar5 + (2 - (int)pbVar2))) {
            if (uVar6 == 0) {
LAB_0809c9b5:
              iVar4 = param_1[0x16];
              *(undefined4 *)(iVar4 + 0x358) = 1;
              *(uint *)(iVar4 + 0x35c) = uVar7;
              if (*(_STACK **)(iVar4 + 0x36c) != (_STACK *)0x0) {
                sk_pop_free(*(_STACK **)(iVar4 + 0x36c),X509_NAME_free);
                iVar4 = param_1[0x16];
              }
              *(_STACK **)(iVar4 + 0x36c) = st;
              X509_NAME_free((X509_NAME *)0x0);
              goto LAB_0809c8e8;
            }
            if (uVar5 == 1) {
LAB_0809ca94:
              ssl3_send_alert(param_1,2,0x32);
              iVar10 = 0x823;
            }
            else {
              puVar9 = puVar8 + 2;
              len = (uint)(ushort)(puVar8[1] << 8 | puVar8[1] >> 8);
              for (uVar1 = len + 2; uVar1 <= uVar5; uVar1 = len + 2 + uVar1) {
                local_24 = puVar9;
                a = d2i_X509_NAME((X509_NAME **)0x0,(uchar **)&local_24,len);
                if (a == (X509_NAME *)0x0) {
                  if ((*(byte *)((int)param_1 + 0x103) & 0x20) != 0) goto LAB_0809c9b0;
                  ssl3_send_alert(param_1,2,0x32);
                  iVar10 = 0x837;
                  iVar4 = 0xd;
LAB_0809cb3e:
                  ERR_put_error(0x14,0x87,iVar4,"s3_clnt.c",iVar10);
                  goto LAB_0809c88f;
                }
                puVar8 = (ushort *)((int)puVar9 + len);
                if (puVar8 != local_24) {
                  ssl3_send_alert(param_1,2,0x32);
                  iVar10 = 0x83f;
                  iVar4 = 0x83;
                  goto LAB_0809cb3e;
                }
                iVar4 = sk_push(st,a);
                if (iVar4 == 0) {
                  iVar10 = 0x843;
                  iVar4 = 0x41;
                  goto LAB_0809cb3e;
                }
                if (uVar5 <= uVar1) goto LAB_0809c9b5;
                if (uVar5 < uVar1 + 2) goto LAB_0809ca94;
                puVar9 = puVar8 + 1;
                len = (uint)(ushort)(*puVar8 << 8 | *puVar8 >> 8);
              }
              if ((*(byte *)((int)param_1 + 0x103) & 0x20) != 0) {
LAB_0809c9b0:
                ERR_clear_error();
                goto LAB_0809c9b5;
              }
              ssl3_send_alert(param_1,2,0x32);
              iVar10 = 0x82b;
            }
            iVar4 = 0x84;
          }
          else {
            ssl3_send_alert(param_1,2,0x32);
            iVar10 = 0x81c;
            iVar4 = 0x9f;
          }
        }
        ERR_put_error(0x14,0x87,iVar4,"s3_clnt.c",iVar10);
        a = (X509_NAME *)0x0;
LAB_0809c88f:
        param_1[0xd] = 5;
        X509_NAME_free(a);
        sk_pop_free(st,X509_NAME_free);
        pbVar3 = (byte *)0x0;
        goto LAB_0809c6c6;
      }
      ERR_put_error(0x14,0x87,0x41,"s3_clnt.c",0x7ef);
    }
    else {
      ssl3_send_alert(param_1,2,10);
      ERR_put_error(0x14,0x87,0xe8,"s3_clnt.c",0x7e7);
    }
  }
  else {
    ssl3_send_alert(param_1,2,10);
    ERR_put_error(0x14,0x87,0x106,"s3_clnt.c",0x7de);
  }
  param_1[0xd] = 5;
  X509_NAME_free((X509_NAME *)0x0);
  pbVar3 = (byte *)0x0;
LAB_0809c6c6:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pbVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

