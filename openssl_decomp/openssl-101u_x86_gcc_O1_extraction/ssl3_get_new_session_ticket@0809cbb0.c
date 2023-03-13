
int ssl3_get_new_session_ticket(int param_1)

{
  uint *puVar1;
  uint uVar2;
  SSL_CTX *c;
  int iVar3;
  void *pvVar4;
  EVP_MD *type;
  SSL_SESSION *sess;
  undefined4 uVar5;
  ushort uVar6;
  uint __n;
  int in_GS_OFFSET;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = (**(code **)(*(int *)(param_1 + 8) + 0x30))(param_1,0x11e0,0x11e1,4,0x4000,&local_24);
  if (local_24 == 0) goto LAB_0809cce0;
  if (iVar3 < 6) {
    iVar3 = 0x87d;
LAB_0809cd90:
    ERR_put_error(0x14,0x11b,0x9f,"s3_clnt.c",iVar3);
    uVar5 = 0x32;
LAB_0809cdae:
    ssl3_send_alert(param_1,2,uVar5);
  }
  else {
    puVar1 = *(uint **)(param_1 + 0x40);
    uVar2 = *puVar1;
    uVar6 = *(ushort *)(puVar1 + 1) << 8 | *(ushort *)(puVar1 + 1) >> 8;
    __n = (uint)uVar6;
    if (iVar3 != __n + 6) {
      iVar3 = 0x888;
      goto LAB_0809cd90;
    }
    iVar3 = 1;
    if (uVar6 == 0) goto LAB_0809cce0;
    sess = *(SSL_SESSION **)(param_1 + 0xc0);
    if (sess->session_id_length != 0) {
      c = *(SSL_CTX **)(param_1 + 0x170);
      if ((c->session_cache_mode & 1U) != 0) {
        if ((c->session_cache_mode & 0x200U) == 0) {
          SSL_CTX_remove_session(c,(SSL_SESSION *)c);
          sess = *(SSL_SESSION **)(param_1 + 0xc0);
        }
        else if (c->remove_session_cb != (_func_3088 *)0x0) {
          (*c->remove_session_cb)(c,sess);
          sess = *(SSL_SESSION **)(param_1 + 0xc0);
        }
      }
      sess = (SSL_SESSION *)ssl_session_dup(sess,0);
      if (sess != (SSL_SESSION *)0x0) {
        SSL_SESSION_free(*(SSL_SESSION **)(param_1 + 0xc0));
        *(SSL_SESSION **)(param_1 + 0xc0) = sess;
        goto LAB_0809cc3b;
      }
      ERR_put_error(0x14,0x11b,0x41,"s3_clnt.c",0x8a7);
      uVar5 = 0x50;
      goto LAB_0809cdae;
    }
LAB_0809cc3b:
    if (*(void **)(sess->krb5_client_princ + 0x54) != (void *)0x0) {
      CRYPTO_free(*(void **)(sess->krb5_client_princ + 0x54));
      sess = *(SSL_SESSION **)(param_1 + 0xc0);
      *(undefined4 *)(sess->krb5_client_princ + 0x58) = 0;
    }
    pvVar4 = CRYPTO_malloc(__n,"s3_clnt.c",0x8b3);
    *(void **)(sess->krb5_client_princ + 0x54) = pvVar4;
    pvVar4 = *(void **)(*(int *)(param_1 + 0xc0) + 0xe4);
    if (pvVar4 != (void *)0x0) {
      memcpy(pvVar4,(void *)((int)puVar1 + 6),__n);
      iVar3 = *(int *)(param_1 + 0xc0);
      *(uint *)(iVar3 + 0xec) =
           uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      *(uint *)(iVar3 + 0xe8) = __n;
      type = EVP_sha256();
      EVP_Digest((void *)((int)puVar1 + 6),__n,(uchar *)(*(int *)(param_1 + 0xc0) + 0x48),
                 (uint *)(*(int *)(param_1 + 0xc0) + 0x44),type,(ENGINE *)0x0);
      iVar3 = 1;
      goto LAB_0809cce0;
    }
    ERR_put_error(0x14,0x11b,0x41,"s3_clnt.c",0x8b5);
  }
  *(undefined4 *)(param_1 + 0x34) = 5;
  iVar3 = -1;
LAB_0809cce0:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

