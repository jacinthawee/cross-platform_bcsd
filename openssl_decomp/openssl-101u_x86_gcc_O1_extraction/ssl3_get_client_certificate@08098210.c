
int ssl3_get_client_certificate(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  X509 *a;
  void *pvVar4;
  _STACK **pp_Var5;
  undefined4 uVar6;
  uint len;
  byte *pbVar7;
  int in_GS_OFFSET;
  int iVar8;
  _STACK *local_38;
  int local_28;
  byte *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = (**(code **)(param_1[2] + 0x30))(param_1,0x2180,0x2181,0xffffffff,param_1[0x42],&local_28)
  ;
  if (local_28 == 0) goto LAB_080982c0;
  iVar8 = param_1[0x16];
  if (*(int *)(iVar8 + 0x340) == 0x10) {
    if ((param_1[0x32] & 3U) == 3) {
      uVar6 = 0x28;
      ERR_put_error(0x14,0x89,199,"s3_srvr.c",0xc81);
      local_38 = (_STACK *)0x0;
      goto LAB_0809829b;
    }
    if ((*param_1 < 0x301) || (*(int *)(iVar8 + 0x390) == 0)) {
      *(undefined4 *)(iVar8 + 0x354) = 1;
      iVar2 = 1;
      goto LAB_080982c0;
    }
    iVar8 = 0xc8a;
    iVar2 = 0xe9;
LAB_0809827f:
    uVar6 = 10;
    ERR_put_error(0x14,0x89,iVar2,"s3_srvr.c",iVar8);
    local_38 = (_STACK *)0x0;
LAB_0809829b:
    ssl3_send_alert(param_1,2,uVar6);
    param_1[0xd] = 5;
  }
  else {
    if (*(int *)(iVar8 + 0x340) != 0xb) {
      iVar8 = 0xc94;
      iVar2 = 0x106;
      goto LAB_0809827f;
    }
    local_24 = (byte *)param_1[0x10];
    local_38 = sk_new_null();
    if (local_38 != (_STACK *)0x0) {
      uVar3 = (uint)local_24[1] << 8 | (uint)*local_24 << 0x10 | (uint)local_24[2];
      pbVar7 = local_24 + 3;
      if (iVar2 == uVar3 + 3) {
        if (uVar3 != 0) {
          if (uVar3 < 3) {
LAB_0809860a:
            local_24 = pbVar7;
            iVar2 = 0xca8;
          }
          else {
            pbVar7 = local_24 + 6;
            len = (uint)local_24[4] << 8 | (uint)local_24[3] << 0x10 | (uint)local_24[5];
            for (uVar1 = len + 3; local_24 = pbVar7, uVar1 <= uVar3; uVar1 = len + 3 + uVar1) {
              a = d2i_X509((X509 **)0x0,&local_24,len);
              if (a == (X509 *)0x0) {
                ERR_put_error(0x14,0x89,0xd,"s3_srvr.c",0xcb6);
                goto LAB_080984e8;
              }
              if (local_24 != pbVar7 + len) {
                ERR_put_error(0x14,0x89,0x87,"s3_srvr.c",0xcbc);
                ssl3_send_alert(param_1,2,0x32);
                param_1[0xd] = 5;
LAB_0809831a:
                X509_free(a);
                goto LAB_08098326;
              }
              iVar2 = sk_push(local_38,a);
              if (iVar2 == 0) {
                ERR_put_error(0x14,0x89,0x41,"s3_srvr.c",0xcc0);
                param_1[0xd] = 5;
                goto LAB_0809831a;
              }
              pbVar7 = local_24;
              if (uVar3 <= uVar1) goto LAB_08098547;
              if (uVar3 < uVar1 + 3) goto LAB_0809860a;
              len = (uint)*local_24 << 0x10 | (uint)local_24[1] << 8 | (uint)local_24[2];
              pbVar7 = local_24 + 3;
            }
            iVar2 = 0xcaf;
          }
          iVar8 = 0x87;
          goto LAB_080983df;
        }
LAB_08098547:
        local_24 = pbVar7;
        iVar2 = sk_num(local_38);
        if (iVar2 < 1) {
          if (*param_1 == 0x300) {
            iVar8 = 0xccc;
            iVar2 = 0xb0;
          }
          else {
            if ((param_1[0x32] & 3U) != 3) {
              if ((*(int *)(param_1[0x16] + 0x178) == 0) ||
                 (iVar2 = ssl3_digest_cached_records(param_1), iVar2 != 0)) goto LAB_08098576;
              uVar6 = 0x50;
              goto LAB_0809829b;
            }
            iVar8 = 0xcd3;
            iVar2 = 199;
          }
          uVar6 = 0x28;
          ERR_put_error(0x14,0x89,iVar2,"s3_srvr.c",iVar8);
        }
        else {
          iVar2 = ssl_verify_cert_chain(param_1,local_38);
          if (0 < iVar2) {
LAB_08098576:
            iVar2 = param_1[0x30];
            if (*(X509 **)(iVar2 + 0x9c) != (X509 *)0x0) {
              X509_free(*(X509 **)(iVar2 + 0x9c));
              iVar2 = param_1[0x30];
            }
            pvVar4 = sk_shift(local_38);
            *(void **)(iVar2 + 0x9c) = pvVar4;
            iVar2 = param_1[0x30];
            *(int *)(iVar2 + 0xa0) = param_1[0x3b];
            if (*(int *)(iVar2 + 0x98) == 0) {
              uVar6 = ssl_sess_cert_new();
              *(undefined4 *)(iVar2 + 0x98) = uVar6;
              iVar2 = param_1[0x30];
              if (*(int *)(iVar2 + 0x98) == 0) {
                iVar2 = 0xcf2;
                goto LAB_08098669;
              }
            }
            pp_Var5 = *(_STACK ***)(iVar2 + 0x98);
            if (*pp_Var5 != (_STACK *)0x0) {
              sk_pop_free(*pp_Var5,X509_free);
              pp_Var5 = *(_STACK ***)(param_1[0x30] + 0x98);
            }
            *pp_Var5 = local_38;
            iVar2 = 1;
            goto LAB_080982c0;
          }
          uVar6 = ssl_verify_alarm_type(param_1[0x3b]);
          ERR_put_error(0x14,0x89,0xb2,"s3_srvr.c",0xce1);
        }
      }
      else {
        iVar2 = 0xca1;
        iVar8 = 0x9f;
        local_24 = pbVar7;
LAB_080983df:
        uVar6 = 0x32;
        ERR_put_error(0x14,0x89,iVar8,"s3_srvr.c",iVar2);
      }
      goto LAB_0809829b;
    }
    iVar2 = 0xc9a;
LAB_08098669:
    ERR_put_error(0x14,0x89,0x41,"s3_srvr.c",iVar2);
LAB_080984e8:
    param_1[0xd] = 5;
  }
  iVar2 = -1;
  if (local_38 != (_STACK *)0x0) {
LAB_08098326:
    sk_pop_free(local_38,X509_free);
    iVar2 = -1;
  }
LAB_080982c0:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

