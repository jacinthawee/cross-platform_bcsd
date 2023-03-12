
int ssl3_get_client_certificate(int *param_1)

{
  int iVar1;
  X509 *a;
  void *pvVar2;
  int iVar3;
  int iVar4;
  _STACK **pp_Var5;
  undefined4 uVar6;
  uint len;
  byte *pbVar7;
  int iVar8;
  uint uVar9;
  _STACK *st;
  uint uVar10;
  byte *local_28;
  int local_24;
  
  iVar1 = (**(code **)(param_1[2] + 0x30))(param_1,0x2180,0x2181,0xffffffff,param_1[0x42],&local_24)
  ;
  if (local_24 == 0) {
    return iVar1;
  }
  iVar3 = param_1[0x16];
  if (*(int *)(iVar3 + 0x340) == 0x10) {
    if ((param_1[0x32] & 3U) == 3) {
      st = (_STACK *)0x0;
      ERR_put_error(0x14,0x89,199,"s3_srvr.c",0xc71);
      uVar6 = 0x28;
    }
    else {
      if ((*param_1 < 0x301) || (*(int *)(iVar3 + 0x390) == 0)) {
        *(undefined4 *)(iVar3 + 0x354) = 1;
        return 1;
      }
      st = (_STACK *)0x0;
      ERR_put_error(0x14,0x89,0xe9,"s3_srvr.c",0xc78);
      uVar6 = 10;
    }
  }
  else if (*(int *)(iVar3 + 0x340) == 0xb) {
    local_28 = (byte *)param_1[0x10];
    st = sk_new_null();
    if (st == (_STACK *)0x0) {
      ERR_put_error(0x14,0x89,0x41,"s3_srvr.c",0xc8a);
      return -1;
    }
    uVar10 = (uint)local_28[1] << 8 | (uint)*local_28 << 0x10 | (uint)local_28[2];
    if (uVar10 + 3 == iVar1) {
      pbVar7 = local_28 + 3;
      if (uVar10 == 0) {
LAB_00049ea8:
        local_28 = pbVar7;
        iVar1 = sk_num(st);
        if (iVar1 < 1) {
          if (*param_1 == 0x300) {
            uVar6 = 0x28;
            ERR_put_error(0x14,0x89,0xb0,"s3_srvr.c",0xcbb);
          }
          else if ((param_1[0x32] & 3U) == 3) {
            uVar6 = 0x28;
            ERR_put_error(0x14,0x89,199,"s3_srvr.c",0xcc2);
          }
          else {
            if ((*(int *)(param_1[0x16] + 0x178) == 0) ||
               (iVar1 = ssl3_digest_cached_records(param_1), iVar1 != 0)) goto LAB_00049ebe;
            uVar6 = 0x50;
          }
        }
        else {
          iVar1 = ssl_verify_cert_chain(param_1,st);
          if (0 < iVar1) {
LAB_00049ebe:
            iVar1 = param_1[0x30];
            if (*(X509 **)(iVar1 + 0x9c) != (X509 *)0x0) {
              X509_free(*(X509 **)(iVar1 + 0x9c));
              iVar1 = param_1[0x30];
            }
            pvVar2 = sk_shift(st);
            iVar8 = param_1[0x30];
            iVar3 = param_1[0x3b];
            iVar4 = *(int *)(iVar8 + 0x98);
            *(void **)(iVar1 + 0x9c) = pvVar2;
            *(int *)(iVar8 + 0xa0) = iVar3;
            if (iVar4 != 0) {
LAB_00049eee:
              pp_Var5 = *(_STACK ***)(iVar8 + 0x98);
              if (*pp_Var5 != (_STACK *)0x0) {
                sk_pop_free(*pp_Var5,X509_free);
                pp_Var5 = *(_STACK ***)(param_1[0x30] + 0x98);
              }
              *pp_Var5 = st;
              return 1;
            }
            uVar6 = ssl_sess_cert_new();
            *(undefined4 *)(iVar8 + 0x98) = uVar6;
            iVar8 = param_1[0x30];
            if (*(int *)(iVar8 + 0x98) != 0) goto LAB_00049eee;
            ERR_put_error(0x14,0x89,0x41,"s3_srvr.c",0xce4);
            goto joined_r0x0004a024;
          }
          uVar6 = ssl_verify_alarm_type(param_1[0x3b]);
          ERR_put_error(0x14,0x89,0xb2,"s3_srvr.c",0xcd3);
        }
      }
      else {
        len = (uint)local_28[3] << 0x10 | (uint)local_28[4] << 8 | (uint)local_28[5];
        local_28 = local_28 + 6;
        for (uVar9 = len + 3; uVar9 <= uVar10; uVar9 = uVar9 + len + 3) {
          pbVar7 = local_28 + len;
          a = d2i_X509((X509 **)0x0,&local_28,len);
          if (a == (X509 *)0x0) {
            ERR_put_error(0x14,0x89,0xd,"s3_srvr.c",0xca3);
            if (st == (_STACK *)0x0) {
              return -1;
            }
            goto LAB_00049d6e;
          }
          if (local_28 != pbVar7) {
            ERR_put_error(0x14,0x89,0x87,"s3_srvr.c",0xca9);
            ssl3_send_alert(param_1,2,0x32);
LAB_00049d68:
            X509_free(a);
            goto LAB_00049d6e;
          }
          iVar1 = sk_push(st,a);
          if (iVar1 == 0) {
            ERR_put_error(0x14,0x89,0x41,"s3_srvr.c",0xcae);
            goto LAB_00049d68;
          }
          pbVar7 = local_28;
          if (uVar10 <= uVar9) goto LAB_00049ea8;
          len = (uint)local_28[1] << 8 | (uint)*local_28 << 0x10 | (uint)local_28[2];
          local_28 = local_28 + 3;
        }
        uVar6 = 0x32;
        ERR_put_error(0x14,0x89,0x87,"s3_srvr.c",0xc9b);
      }
    }
    else {
      uVar6 = 0x32;
      local_28 = local_28 + 3;
      ERR_put_error(0x14,0x89,0x9f,"s3_srvr.c",0xc92);
    }
  }
  else {
    st = (_STACK *)0x0;
    ERR_put_error(0x14,0x89,0x106,"s3_srvr.c",0xc83);
    uVar6 = 10;
  }
  ssl3_send_alert(param_1,2,uVar6);
joined_r0x0004a024:
  if (st == (_STACK *)0x0) {
    return -1;
  }
LAB_00049d6e:
  sk_pop_free(st,X509_free);
  return -1;
}

