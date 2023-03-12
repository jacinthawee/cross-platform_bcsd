
int ssl3_get_client_certificate(int *param_1)

{
  int iVar1;
  byte *pbVar2;
  X509 *a;
  void *pvVar3;
  int iVar4;
  int iVar5;
  _STACK **pp_Var6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  uint len;
  uint uVar10;
  _STACK *st;
  byte *local_28;
  int local_24;
  
  iVar1 = (**(code **)(param_1[2] + 0x30))(param_1,0x2180,0x2181,0xffffffff,param_1[0x42],&local_24)
  ;
  if (local_24 == 0) {
    return iVar1;
  }
  iVar4 = param_1[0x16];
  if (*(int *)(iVar4 + 0x340) == 0x10) {
    if ((param_1[0x32] & 3U) == 3) {
      st = (_STACK *)0x0;
      ERR_put_error(0x14,0x89,199,"s3_srvr.c",0xc81);
      uVar7 = 0x28;
    }
    else {
      if ((*param_1 < 0x301) || (*(int *)(iVar4 + 0x390) == 0)) {
        *(undefined4 *)(iVar4 + 0x354) = 1;
        return 1;
      }
      st = (_STACK *)0x0;
      ERR_put_error(0x14,0x89,0xe9,"s3_srvr.c",0xc8a);
      uVar7 = 10;
    }
  }
  else if (*(int *)(iVar4 + 0x340) == 0xb) {
    local_28 = (byte *)param_1[0x10];
    st = sk_new_null();
    iVar4 = 0xc9a;
    if (st == (_STACK *)0x0) {
LAB_00046bb4:
      ERR_put_error(0x14,0x89,0x41,"s3_srvr.c",iVar4);
      goto LAB_0004693e;
    }
    pbVar2 = local_28 + 3;
    uVar10 = (uint)local_28[1] << 8 | (uint)*local_28 << 0x10 | (uint)local_28[2];
    if (uVar10 + 3 == iVar1) {
      if (uVar10 == 0) {
LAB_00046aec:
        local_28 = pbVar2;
        iVar1 = sk_num(st);
        if (iVar1 < 1) {
          if (*param_1 == 0x300) {
            uVar7 = 0x28;
            ERR_put_error(0x14,0x89,0xb0,"s3_srvr.c",0xccc);
          }
          else if ((param_1[0x32] & 3U) == 3) {
            uVar7 = 0x28;
            ERR_put_error(0x14,0x89,199,"s3_srvr.c",0xcd3);
          }
          else {
            if ((*(int *)(param_1[0x16] + 0x178) == 0) ||
               (iVar1 = ssl3_digest_cached_records(param_1), iVar1 != 0)) goto LAB_00046b02;
            uVar7 = 0x50;
          }
        }
        else {
          iVar1 = ssl_verify_cert_chain(param_1,st);
          if (0 < iVar1) {
LAB_00046b02:
            iVar1 = param_1[0x30];
            if (*(X509 **)(iVar1 + 0x9c) != (X509 *)0x0) {
              X509_free(*(X509 **)(iVar1 + 0x9c));
              iVar1 = param_1[0x30];
            }
            pvVar3 = sk_shift(st);
            iVar9 = param_1[0x30];
            iVar4 = param_1[0x3b];
            iVar5 = *(int *)(iVar9 + 0x98);
            *(void **)(iVar1 + 0x9c) = pvVar3;
            *(int *)(iVar9 + 0xa0) = iVar4;
            if (iVar5 != 0) {
LAB_00046b30:
              pp_Var6 = *(_STACK ***)(iVar9 + 0x98);
              if (*pp_Var6 != (_STACK *)0x0) {
                sk_pop_free(*pp_Var6,X509_free);
                pp_Var6 = *(_STACK ***)(param_1[0x30] + 0x98);
              }
              *pp_Var6 = st;
              return 1;
            }
            uVar7 = ssl_sess_cert_new();
            *(undefined4 *)(iVar9 + 0x98) = uVar7;
            iVar9 = param_1[0x30];
            if (*(int *)(iVar9 + 0x98) != 0) goto LAB_00046b30;
            iVar4 = 0xcf2;
            goto LAB_00046bb4;
          }
          uVar7 = ssl_verify_alarm_type(param_1[0x3b]);
          ERR_put_error(0x14,0x89,0xb2,"s3_srvr.c",0xce1);
        }
      }
      else {
        if (uVar10 < 3) {
LAB_00046b54:
          local_28 = pbVar2;
          iVar1 = 0xca8;
        }
        else {
          len = (uint)local_28[4] << 8 | (uint)local_28[3] << 0x10 | (uint)local_28[5];
          local_28 = local_28 + 6;
          for (uVar8 = len + 3; uVar8 <= uVar10; uVar8 = uVar8 + len + 3) {
            pbVar2 = local_28 + len;
            a = d2i_X509((X509 **)0x0,&local_28,len);
            if (a == (X509 *)0x0) {
              ERR_put_error(0x14,0x89,0xd,"s3_srvr.c",0xcb6);
              goto LAB_0004693e;
            }
            if (local_28 != pbVar2) {
              ERR_put_error(0x14,0x89,0x87,"s3_srvr.c",0xcbc);
              ssl3_send_alert(param_1,2,0x32);
              param_1[0xd] = 5;
LAB_00046978:
              X509_free(a);
              goto LAB_0004697e;
            }
            iVar1 = sk_push(st,a);
            if (iVar1 == 0) {
              ERR_put_error(0x14,0x89,0x41,"s3_srvr.c",0xcc0);
              param_1[0xd] = 5;
              goto LAB_00046978;
            }
            pbVar2 = local_28;
            if (uVar10 <= uVar8) goto LAB_00046aec;
            if (uVar10 < uVar8 + 3) goto LAB_00046b54;
            len = (uint)local_28[1] << 8 | (uint)*local_28 << 0x10 | (uint)local_28[2];
            local_28 = local_28 + 3;
          }
          iVar1 = 0xcaf;
        }
        uVar7 = 0x32;
        ERR_put_error(0x14,0x89,0x87,"s3_srvr.c",iVar1);
      }
    }
    else {
      uVar7 = 0x32;
      local_28 = pbVar2;
      ERR_put_error(0x14,0x89,0x9f,"s3_srvr.c",0xca1);
    }
  }
  else {
    st = (_STACK *)0x0;
    ERR_put_error(0x14,0x89,0x106,"s3_srvr.c",0xc94);
    uVar7 = 10;
  }
  ssl3_send_alert(param_1,2,uVar7);
LAB_0004693e:
  param_1[0xd] = 5;
  if (st == (_STACK *)0x0) {
    return -1;
  }
LAB_0004697e:
  sk_pop_free(st,X509_free);
  return -1;
}

