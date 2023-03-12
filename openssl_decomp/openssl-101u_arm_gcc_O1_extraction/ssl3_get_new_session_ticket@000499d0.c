
int ssl3_get_new_session_ticket(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  void *pvVar6;
  EVP_MD *type;
  SSL_CTX *ctx;
  undefined4 uVar7;
  byte *pbVar8;
  uint __n;
  SSL_SESSION *c;
  int local_2c [2];
  
  iVar5 = (**(code **)(*(int *)(param_1 + 8) + 0x30))(param_1,0x11e0,0x11e1,4,0x4000,local_2c);
  if (local_2c[0] == 0) {
    return iVar5;
  }
  if (iVar5 < 6) {
    iVar5 = 0x87d;
LAB_00049af6:
    ERR_put_error(0x14,0x11b,0x9f,"s3_clnt.c",iVar5);
    uVar7 = 0x32;
  }
  else {
    pbVar8 = *(byte **)(param_1 + 0x40);
    bVar2 = *pbVar8;
    __n = (uint)CONCAT11(pbVar8[4],pbVar8[5]);
    bVar3 = pbVar8[1];
    bVar1 = pbVar8[2];
    bVar4 = pbVar8[3];
    if (__n + 6 != iVar5) {
      iVar5 = 0x888;
      goto LAB_00049af6;
    }
    if (__n == 0) {
      return 1;
    }
    c = *(SSL_SESSION **)(param_1 + 0xc0);
    if (c->session_id_length == 0) {
LAB_00049a36:
      if (*(void **)(c->krb5_client_princ + 0x54) != (void *)0x0) {
        CRYPTO_free(*(void **)(c->krb5_client_princ + 0x54));
        c = *(SSL_SESSION **)(param_1 + 0xc0);
        *(undefined4 *)(c->krb5_client_princ + 0x58) = 0;
      }
      pvVar6 = CRYPTO_malloc(__n,"s3_clnt.c",0x8b3);
      iVar5 = *(int *)(param_1 + 0xc0);
      *(void **)(c->krb5_client_princ + 0x54) = pvVar6;
      pvVar6 = *(void **)(iVar5 + 0xe4);
      if (pvVar6 != (void *)0x0) {
        memcpy(pvVar6,pbVar8 + 6,__n);
        iVar5 = *(int *)(param_1 + 0xc0);
        *(uint *)(iVar5 + 0xe8) = __n;
        *(uint *)(iVar5 + 0xec) =
             (uint)bVar3 << 0x10 | (uint)bVar2 << 0x18 | (uint)bVar4 | (uint)bVar1 << 8;
        type = EVP_sha256();
        EVP_Digest(pbVar8 + 6,__n,(uchar *)(iVar5 + 0x48),(uint *)(iVar5 + 0x44),type,(ENGINE *)0x0)
        ;
        return 1;
      }
      ERR_put_error(0x14,0x11b,0x41,"s3_clnt.c",0x8b5);
      goto LAB_00049b12;
    }
    ctx = *(SSL_CTX **)(param_1 + 0x170);
    if (ctx->session_cache_mode << 0x1f < 0) {
      if (ctx->session_cache_mode << 0x16 < 0) {
        if (ctx->remove_session_cb != (_func_3088 *)0x0) {
          (*ctx->remove_session_cb)(ctx,c);
          c = *(SSL_SESSION **)(param_1 + 0xc0);
        }
      }
      else {
        SSL_CTX_remove_session(ctx,c);
        c = *(SSL_SESSION **)(param_1 + 0xc0);
      }
    }
    c = (SSL_SESSION *)ssl_session_dup(c,0);
    if (c != (SSL_SESSION *)0x0) {
      SSL_SESSION_free(*(SSL_SESSION **)(param_1 + 0xc0));
      *(SSL_SESSION **)(param_1 + 0xc0) = c;
      goto LAB_00049a36;
    }
    ERR_put_error(0x14,0x11b,0x41,"s3_clnt.c",0x8a7);
    uVar7 = 0x50;
  }
  ssl3_send_alert(param_1,2,uVar7);
LAB_00049b12:
  *(undefined4 *)(param_1 + 0x34) = 5;
  return -1;
}

